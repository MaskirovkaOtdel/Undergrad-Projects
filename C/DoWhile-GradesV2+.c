#include <stdio.h>
#include <stdlib.h>

int main() {
    float vathmos;
    char input[50];

    // Εισαγωγή και έλεγχος εισόδου
    do {
        printf("Δώσε βαθμό από 1 έως 10: ");
        fgets(input, sizeof(input), stdin); // Διαβάζουμε ολόκληρη τη γραμμή
        if (sscanf(input, "%f", &vathmos) != 1) {
            printf("Μη έγκυρη είσοδος! Πρέπει να εισάγεις έναν αριθμό.\n");
            continue;
        }
        if (vathmos < 1 || vathmos > 10) {
            printf("Ο βαθμός πρέπει να είναι μεταξύ 1 και 10. Προσπάθησε ξανά.\n");
        }
    } while (vathmos < 1 || vathmos > 10);

    // Αξιολόγηση βαθμού
    if (vathmos >= 5) {
        printf("Πέρασες με βαθμό %.2f\n", vathmos);
        if (vathmos == 10) {
            printf("Άριστα! Συγχαρητήρια!\n");
        }
    } else {
        printf("Εμεινες με βαθμό %.2f\n", vathmos);
    }

    printf("Ευχαριστούμε για τη συμμετοχή!\n");
    return 0;
}




//Σπλιτ σε πολλαπλες συναρτησεις

//#include <stdio.h>
//#include <stdlib.h>

// Συνάρτηση για να ζητήσει και να επιστρέψει τον βαθμό
//float input_vathmos() {
//    float vathmos;
//    char input[50];
//    while (1) {
//        printf("Δώσε βαθμό από 1 έως 10: ");
//        fgets(input, sizeof(input), stdin);
//        if (sscanf(input, "%f", &vathmos) == 1 && vathmos >= 1 && vathmos <= 10) {
//            return vathmos;
//        } else {
//            printf("Μη έγκυρη είσοδος ή βαθμός εκτός εύρους! Προσπάθησε ξανά.\n");
//        }
//    }
//}

// Συνάρτηση για αξιολόγηση του βαθμού
//void evaluate_vathmos(float vathmos) {
//    if (vathmos >= 5) {
//        printf("Πέρασες με βαθμό %.2f\n", vathmos);
//        if (vathmos == 10) {
//            printf("Άριστα! Συγχαρητήρια!\n");
//        }
//    } else {
//        printf("Εμεινες με βαθμό %.2f\n", vathmos);
//    }
//}

//int main() {
//    float vathmos = input_vathmos(); // Εισάγουμε τον βαθμό
//    evaluate_vathmos(vathmos);       // Αξιολογούμε τον βαθμό
//    return 0;
//}
