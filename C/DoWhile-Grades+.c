//Βελτιωμενη εκδοση

#include <stdio.h>
#include <stdlib.h>

int main() {
    float vathmos;

    // Εισαγωγή και έλεγχος εισόδου
    do {
        printf("Dwse ena vathmo 1 ews 10: ");
        if (scanf("%f", &vathmos) != 1) {
            printf("Mh egkyrh eisodos! Prepei na eisageis enan arithmo.\n");
            while (getchar() != '\n');  // Καθαρισμός του buffer εισόδου
            continue;
        }
        if (vathmos < 1 || vathmos > 10) {
            printf("O vathmos prepei na einai metaksy 1 kai 10. Prospathise ksana.\n");
        }
    } while (vathmos < 1 || vathmos > 10);

    // Αξιολόγηση βαθμού
    if (vathmos >= 5) {
        printf("Perases me vathmo %.2f\n", vathmos);
        if (vathmos == 10) {
            printf("Arista! Sygxarithria!\n");
        }
    } else {
        printf("Emeines me vathmo %.2f\n", vathmos);
    }

    printf("Eyxaristoyme gia th symmetoxh!\n");
    return 0;
}
