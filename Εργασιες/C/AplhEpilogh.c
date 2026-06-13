#include <stdio.h>

int main() {
    int choice;
    float num1, num2, result;

    // Εκτύπωση μενού
    printf("\nArithmomhxanh - Aplh Epilogh\n");
    printf("Epilekste Praksh:\n");
    printf("1. Prosthesh\n");
    printf("2. Afairesh\n");
    printf("3. Pollaplasiasmos\n");
    printf("4. Diairesh\n");

    // Εισαγωγή επιλογής
    printf("\nEisagete thn epilogh sas (1-4): ");
    scanf("%d", &choice);

    // Εκτέλεση της επιλεγμένης πράξης
    if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
        printf("Eisagete 2 arithmoys: ");
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
                printf("Diairesh me 0 den epitrepetai!\n");
            }
        }
    } else {
        printf("Mh egkyrh epilogh!\n");
    }

    return 0;
}
