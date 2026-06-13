#include <stdio.h>
#include <stdlib.h>

int main() {
    int age;
    char input[50];

    // Εισαγωγή και έλεγχος εισόδου
    do {
        printf("Dwse hlhkia apo 1 ews 120: ");
        fgets(input, sizeof(input), stdin); // Διαβάζουμε ολόκληρη τη γραμμή
        if (sscanf(input, "%d", &age) != 1) {
            printf("Mh egkyrh eisodos! Prepei na eisageis enan arithmo.\n");
            continue;
        }
        if (age <= 0 || age > 120) {
            printf("H hlhkia prepei na enai apo 1 ews 120. Prospathise ksana.\n");
        }
    } while (age < 1 || age > 120);

    // Υπολογισμός Ηλικίας
    if (age <= 4) {
        printf("Nhpio\n");
    }
    else if (age <= 12) {
        printf("Paidi\n");
    }
    else if (age <= 18) {
        printf("Efhvos\n");
    }
    else if (age <= 35) {
        printf("Neos\n");
    }
    else if (age <= 65) {
        printf("Wrimos\n");
    }
    else if (age <= 80) {
        printf("Hlikiwmenos\n");
    }
    else {
        printf("Tafoplaka\n");
    }

    printf("Telos ypologismoy hlhkias!\n");
    return 0;
}
