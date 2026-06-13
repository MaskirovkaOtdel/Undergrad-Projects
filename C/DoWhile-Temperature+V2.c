#include <stdio.h>
#include <stdlib.h>

int main() {
    system("color 0A");
    float temp, table[10][2], sum = 0, minTemp = 51, maxTemp = -13;
    int i, index;
    char input[50];
    
    // Εισαγωγή θερμοκρασιών
    for (i = 0; i < 10; i++) {
        do {
            printf("Dwse thn %dh thermokrasia: ", i + 1);
            fgets(input, sizeof(input), stdin); 
            
            if (sscanf(input, "%f", &temp) != 1) {
                printf("Mh egkyrh eisodos! Prepei na eisageis enan arithmo.\n");
                continue;
            }
            
            if (temp < -12 || temp > 50) {
                printf("H thermokrasia prepei na einai apo -12 ews 50. Prospathise ksana.\n");
            }
        } while (temp < -12 || temp > 50);  
        
        table[i][0] = i + 1;  // Αριθμός της θερμοκρασίας
        table[i][1] = temp;    // Τιμή θερμοκρασίας
        
        sum += temp;
        
        if (temp < minTemp) {
            minTemp = temp;
        }
        
        if (temp > maxTemp) {
            maxTemp = temp;
        }
    }

    // Εμφάνιση πίνακα θερμοκρασιών
    printf("\nPinakas thermokrasiwn:\n");
    for (i = 0; i < 10; i++) {
        printf("H timi tis %dhs thermokrasias einai: %.2fC\n", (int)table[i][0], table[i][1]);
    }

    // Υπολογισμός και εμφάνιση μέσου όρου, ελάχιστης και μέγιστης θερμοκρασίας
    float average = sum / 10;
    printf("\nMesos oros thermokrasiwn: %.2fC\n", average);
    printf("H elaxisth thermokrasia einai: %.2fC\n", minTemp);
    printf("H megisth thermokrasia einai: %.2fC\n", maxTemp);
    
    // Ζήτηση από τον χρήστη να εμφανίσει μια συγκεκριμένη τιμή
    printf("\nAn thes na deis mia sigkekrimeni timi, dwse ton arithmo tis thesews (1-10): ");
    fgets(input, sizeof(input), stdin); 
    
    if (sscanf(input, "%d", &index) == 1 && index >= 1 && index <= 10) {
        printf("H timi tis %dhs thermokrasias einai: %.2fC\n", index, table[index - 1][1]);
    } else {
        printf("Lathos eisodos. Parakalo dwse arithmo metaxy 1 kai 10.\n");
    }

    return 0;
}
