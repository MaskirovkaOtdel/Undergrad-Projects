#include <stdio.h>
#include <math.h>

int main() {
    double a, b, result;
    
    // Ζητάμε από τον χρήστη να εισάγει δύο αριθμούς
    printf("Eisagete ton prwto arithmo: ");
    scanf("%lf", &a);
    printf("Eisagete ton deytero arithmo: ");
    scanf("%lf", &b);
    
    // Εμφωλευμένη επιλογή για αριθμητικές πράξεις
    if (a > b) {
        if (a > 0) {  // Αν το 'a' είναι θετικός
            result = a + b;  // Άθροισμα
            printf("Athroisma: %.2f\n", result);
        } else {
            result = a * b;  // Αν το 'a' δεν είναι θετικός, κάνουμε πολλαπλασιασμό
            printf("Pollaplasiasmos: %.2f\n", result);
        }
    } else {
        if (b != 0) {  // Αν το 'b' δεν είναι μηδέν
            result = a / b;  // Διαίρεση
            printf("Diairesh: %.2f\n", result);
        } else {
            printf("H Diairesh me to 0 den epitrepetai!\n");
        }
    }
    
    if ((int)b != 0) {
        result = (int)a % (int)b;  // Υπόλοιπο (ακέραιοι αριθμοί)
        printf("Ypoloipo: %.0f\n", result);
    } else {
        printf("H Diairesh me to 0 den epitrepetai!\n");
    }

    result = pow(a, b);  // Εκθέτης
    printf("Ekthetis: %.2f\n", result);
    
    return 0;
}
