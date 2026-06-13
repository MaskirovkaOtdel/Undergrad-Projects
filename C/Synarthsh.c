#include <stdio.h>

// Συνάρτηση για υπολογισμό της τιμής της συνάρτησης αx^2 + βx + γ
double calculateFunction(double alpha, double beta, double gamma, double x) {
    return alpha * x * x + beta * x + gamma;
}

int main() {
    double alpha, beta, gamma, x = 1.0, result;  // Εδώ μπορείς να βάλεις οποιαδήποτε τιμή θες για το x

    // Ζητάμε τις τιμές των παραμέτρων α, β, γ
    printf("Dwse timh gia a: ");
    while (scanf("%lf", &alpha) != 1) {
        while(getchar() != '\n');
        printf("Lathos eisodos! dwse enan arithmo gia a: ");
    }

    printf("Dwse timh gia b: ");
    while (scanf("%lf", &beta) != 1) {
        while(getchar() != '\n');
        printf("Lathos eisodos! dwse enan arithmo gia b: ");
    }

    printf("Dwse timh gia c: ");
    while (scanf("%lf", &gamma) != 1) {
        while(getchar() != '\n');
        printf("Lathos eisodos! dwse enan arithmo gia c: ");
    }

    // Υπολογίζουμε την τιμή της συνάρτησης για x = 1.0 (ή όποια τιμή θες να βάλεις για x)
    result = calculateFunction(alpha, beta, gamma, x);

    // Εμφανίζουμε το αποτέλεσμα
    printf("H Timh synarthshs gia x = %.2f einai: %.2f\n", x, result);

    return 0;
}
