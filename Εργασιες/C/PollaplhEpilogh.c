#include <stdio.h>
#include <math.h>

int main() {
    double a, b, result;
    
    // Ζητάμε από τον χρήστη να εισάγει δύο αριθμούς
    printf("Eisagete ton prwto arithmo: ");
    scanf("%lf", &a);
    printf("Eisagete ton deytero arithmo: ");
    scanf("%lf", &b);
    
    // Πολλαπλή επιλογή για πράξεις
    if (a > b) {
        result = a + b;  // Άθροισμα
        printf("Athroisma: %.2f\n", result);
    } else if (a < b) {
        result = a - b;  // Αφαίρεση
        printf("Afairesh: %.2f\n", result);
    } else {
        result = a * b;  // Πολλαπλασιασμός
        printf("Pollaplasiasmos: %.2f\n", result);
    }
    
    if (b != 0) {
        result = a / b;  // Διαίρεση
        printf("Diairesh: %.2f\n", result);
    } else {
        printf("H diairesh me to 0 den epitrepetai!\n");
    }

    result = (int)a % (int)b;  // Υπόλοιπο (ακέραιοι αριθμοί)
    printf("Ypoloipo: %.0f\n", result);
    
    result = pow(a, b);  // Εκθέτης
    printf("Ekthetis: %.2f\n", result);
    
    return 0;
}
