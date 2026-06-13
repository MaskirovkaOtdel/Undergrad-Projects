#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    // Επανάληψη για περιορισμένες επιλογές
    do {
        // Εκτύπωση μενού
        printf("\nArithmomhxanh - Peperasmenh Epilogh\n");
        printf("Epilekste Praksh:\n");
        printf("1. Prosthesi\n");
        printf("2. Afairesh\n");
        printf("3. Pollaplasiasmos\n");
        printf("4. Diairesh\n");
        printf("5. Eksodos\n");

        // Εισαγωγή επιλογής
        printf("\nEisagete thn epilogh sas (1-5): ");
        scanf("%d", &choice);

        // Εκτέλεση της επιλεγμένης πράξης
        if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
            printf("Eisagete dyo arithmoys: ");
            scanf("%f %f", &num1, &num2);

            if (choice == 1) {
                result = num1 + num2;
                printf("Apotelesma: %.2f\n", result);
            } else if (choice == 2) {
                result = num1 - num2;
                printf("Apotelesma: %.2f\n", result);
            } else if (choice == 3) {
                result = num1 * num2;
                printf("Apotelesma: %.2f\n", result);
            } else if (choice == 4) {
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Apotelesma: %.2f\n", result);
                } else {
                    printf("Diairesh me to 0 den epitrepetai!\n");
                }
            }
        } else if (choice != 5) {
            printf("Mh egkyrh epilogh!\n");
        }

    } while (choice != 5);  // Επανάληψη έως να επιλεγεί η έξοδος

    printf("Eksodos apo thn arithmomhxanh\n");
    return 0;
}
