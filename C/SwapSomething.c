#include <stdio.h>

// Δημιουργία της διαδικασίας για την αντιμεταθετική (swap)
void swap(int *a, int *b) {
    int temp;
    
    printf("Prwth timh metavlhtwn: a=%d, b=%d.\n", *a, *b);
    
    // Αντιμετάθεση των τιμών
    temp = *a;
    *a = *b;
    *b = temp;
    
    printf("Meta thn antimetathesh: a=%d, b=%d.\n", *a, *b);
}

int main() {
    int m1, m2;
    char choice;
    
    // Επαναλαμβανόμενος βρόχος για επανειλημμένη αντιμετάθεση
    do {
        // Εισαγωγή τιμών για m1 και m2 με έλεγχο για την εγκυρότητα της εισόδου
        printf("Dwse timh gia m1: ");
        while (scanf("%d", &m1) != 1) {
            while(getchar() != '\n');  // Καθαρισμός του buffer
            printf("Lathos eisodos! dwse enan akeraio arithmo gia m1: ");
        }

        printf("Dwse timh gia m2: ");
        while (scanf("%d", &m2) != 1) {
            while(getchar() != '\n');  // Καθαρισμός του buffer
            printf("Lathos eisodos! dwse enan akeraio arithmo gia m2: ");
        }

        // Εκτέλεση της διαδικασίας για την αντιμεταθετική
        swap(&m1, &m2);

        // Ζητάμε από τον χρήστη αν θέλει να επαναλάβει
        printf("theleis na kaneis allh antimetathesh me arithmoys? (y/n): ");
        while (scanf(" %c", &choice) != 1 || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            while(getchar() != '\n');  // Καθαρισμός του buffer
            printf("Lathos eisodos! Grapse 'y' gia nai h 'n' gia oxi: ");
        }
        
    } while (choice == 'y' || choice == 'Y');  // Επαναλαμβάνει αν ο χρήστης επιλέξει 'y' ή 'Y'

    printf("Eyxaristoyme poy xrhsimopoihses to programma!\n");

    return 0;
}
