#include <stdio.h>

int main() {
    float num1, num2, num3, max, min;
    
    // διαβαζει 3 αριθμους απο τον χρηστη
    printf("Dwse 3 arithmoys: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    // Υπολογισμός του μέγιστου αριθμού
    if (num1 >= num2) {
        if (num1 >= num3) {
            max = num1;
        } else {
            max = num3;
        }
    } else {
        if (num2 >= num3) {
            max = num2;
        } else {
            max = num3;
        }
    }
    printf("Megistos einai o %.3f \n", max);

    // Υπολογισμος του ελαγχιστου αριθμου
    if (num1 <= num2) {
        if (num1 <= num3) {
            min = num1;
        } else {
            min = num3;
        }
    } else {
        if (num2 <= num3) {
            min = num2;
        } else {
            min = num3;
        }
    }
    printf("Elagxistos einai o %.3f \n", min);

    return 0;
}
