#include <stdio.h>

// Συνάρτηση για την εύρεση του μέγιστου και του ελάχιστου αριθμού
void find_max_min() {
    float num1, num2, num3, max, min;

    // Διαβάζει 3 αριθμούς από τον χρήστη
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

    // Υπολογισμός του ελάχιστου αριθμού
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
}

// Συνάρτηση για να επιστρέψει το μέγιστο και το ελάχιστο
float funct_max(float num1, float num2, float num3) {
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

    // Υπολογισμός του ελάχιστου αριθμού
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

    // Επιστροφή του μέγιστου αριθμού
    return max;
    // Επιστροφη του ελάγχιστου αριθμού
    return min;
}

int main() {
    
    find_max_min();

    
    float max, min;
    max=funct_max(5, 8, 9,);
	min=funct_min(5, 8, 9,);
    
    printf("To megisto einai: %.3f\n", max);
    printf("To elaxisto einai: %.3f\n", min);

    return 0;
}
