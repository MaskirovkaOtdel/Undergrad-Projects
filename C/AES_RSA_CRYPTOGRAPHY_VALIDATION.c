#include <openssl/aes.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/sha.h>
#include <openssl/err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define AES_KEY_LENGTH 128  // Μήκος κλειδιού AES (128 bits)

void aes_encrypt(const unsigned char *input, unsigned char *output, unsigned char *key) {
    AES_KEY encrypt_key;
    AES_set_encrypt_key(key, AES_KEY_LENGTH, &encrypt_key);
    AES_encrypt(input, output, &encrypt_key);
}

void aes_decrypt(const unsigned char *input, unsigned char *output, unsigned char *key) {
    AES_KEY decrypt_key;
    AES_set_decrypt_key(key, AES_KEY_LENGTH, &decrypt_key);
    AES_decrypt(input, output, &decrypt_key);
}

void encrypt_file(const char *file_path, unsigned char *key, const char *output_file) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *file_data = (unsigned char *)malloc(file_len);
    fread(file_data, 1, file_len, file);
    fclose(file);

    unsigned char encrypted_data[file_len];
    for (long i = 0; i < file_len; i += AES_BLOCK_SIZE) {
        aes_encrypt(file_data + i, encrypted_data + i, key);
    }

    FILE *enc_file = fopen(output_file, "wb");
    fwrite(encrypted_data, 1, file_len, enc_file);
    fclose(enc_file);

    free(file_data);
    printf("File encrypted successfully!\n");
}

void decrypt_file(const char *file_path, unsigned char *key, const char *output_file) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *file_data = (unsigned char *)malloc(file_len);
    fread(file_data, 1, file_len, file);
    fclose(file);

    unsigned char decrypted_data[file_len];
    for (long i = 0; i < file_len; i += AES_BLOCK_SIZE) {
        aes_decrypt(file_data + i, decrypted_data + i, key);
    }

    FILE *dec_file = fopen(output_file, "wb");
    fwrite(decrypted_data, 1, file_len, dec_file);
    fclose(dec_file);

    free(file_data);
    printf("File decrypted successfully!\n");
}

void sign_file(const char *file_path, const char *private_key_path, const char *signature_file) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *file_data = (unsigned char *)malloc(file_len);
    fread(file_data, 1, file_len, file);
    fclose(file);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(file_data, file_len, hash);
    free(file_data);

    FILE *private_key_file = fopen(private_key_path, "rb");
    if (!private_key_file) {
        perror("Unable to open private key file");
        return;
    }

    RSA *private_key = PEM_read_RSAPrivateKey(private_key_file, NULL, NULL, NULL);
    fclose(private_key_file);
    if (!private_key) {
        ERR_print_errors_fp(stderr);
        return;
    }

    unsigned char signature[RSA_size(private_key)];
    unsigned int signature_len;

    if (RSA_sign(NID_sha256, hash, SHA256_DIGEST_LENGTH, signature, &signature_len, private_key) != 1) {
        ERR_print_errors_fp(stderr);
        return;
    }

    FILE *sig_file = fopen(signature_file, "wb");
    fwrite(signature, 1, signature_len, sig_file);
    fclose(sig_file);

    RSA_free(private_key);
    printf("File signed successfully!\n");
}

int verify_signature(const char *file_path, const char *signature_file, const char *public_key_path) {
    FILE *file = fopen(file_path, "rb");
    if (!file) {
        perror("Unable to open file");
        return 0;
    }

    fseek(file, 0, SEEK_END);
    long file_len = ftell(file);
    fseek(file, 0, SEEK_SET);

    unsigned char *file_data = (unsigned char *)malloc(file_len);
    fread(file_data, 1, file_len, file);
    fclose(file);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(file_data, file_len, hash);
    free(file_data);

    FILE *sig_file = fopen(signature_file, "rb");
    fseek(sig_file, 0, SEEK_END);
    long sig_len = ftell(sig_file);
    fseek(sig_file, 0, SEEK_SET);

    unsigned char *signature = (unsigned char *)malloc(sig_len);
    fread(signature, 1, sig_len, sig_file);
    fclose(sig_file);

    FILE *public_key_file = fopen(public_key_path, "rb");
    if (!public_key_file) {
        perror("Unable to open public key file");
        return 0;
    }

    RSA *public_key = PEM_read_RSA_PUBKEY(public_key_file, NULL, NULL, NULL);
    fclose(public_key_file);
    if (!public_key) {
        ERR_print_errors_fp(stderr);
        return 0;
    }

    int result = RSA_verify(NID_sha256, hash, SHA256_DIGEST_LENGTH, signature, sig_len, public_key);

    free(signature);
    RSA_free(public_key);

    if (result == 1) {
        printf("Signature is valid!\n");
        return 1;
    } else {
        printf("Signature is invalid!\n");
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <operation> <file> <key_file> [signature_file]\n", argv[0]);
        return 1;
    }

    unsigned char aes_key[AES_BLOCK_SIZE] = "1234567890123456"; // 16 byte AES key (128 bit)

    if (strcmp(argv[1], "encrypt") == 0) {
        if (argc != 4) {
            printf("Usage: %s encrypt <file> <output_file>\n", argv[0]);
            return 1;
        }
        encrypt_file(argv[2], aes_key, argv[3]);
    } else if (strcmp(argv[1], "decrypt") == 0) {
        if (argc != 4) {
            printf("Usage: %s decrypt <file> <output_file>\n", argv[0]);
            return 1;
        }
        decrypt_file(argv[2], aes_key, argv[3]);
    } else if (strcmp(argv[1], "sign") == 0) {
        if (argc != 5) {
            printf("Usage: %s sign <file> <private_key_file> <signature_file>\n", argv[0]);
            return 1;
        }
        sign_file(argv[2], argv[3], argv[4]);
    } else if (strcmp(argv[1], "verify") == 0) {
        if (argc != 5) {
            printf("Usage: %s verify <file> <public_key_file> <signature_file>\n", argv[0]);
            return 1;
        }
        verify_signature(argv[2], argv[4], argv[3]);
    } else {
        printf("Invalid operation. Use 'encrypt', 'decrypt', 'sign' or 'verify'.\n");
        return 1;
    }

    return 0;
}


//Κρυπτογράφηση:
//./program encrypt input.txt encrypted.dat
//Αποκρυπτογράφηση:
//./program decrypt encrypted.dat decrypted.txt
//Υπογραφή:
//./program sign encrypted.dat private_key.pem signature.sig
//Επαλήθευση Υπογραφής:
//./program verify encrypted.dat public_key.pem signature.sig