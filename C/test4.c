#include <stdio.h>

// Δημιουργία της διαδικασίας για την αντιμεταθετική (swap)
void antimetathesi(int *a, int *b) {
    int tmp;
    tmp = *a;   // Αποθήκευση της τιμής του a σε temp
    *a = *b;     // Αντιστοίχιση της τιμής του b στο a
    *b = tmp;   // Αντιστοίχιση της τιμής του temp στο b
}

int main() {
    int m1, m2;

    // Εισαγωγή τιμών για m1 και m2
    printf("Dwse timh gia M1: ");
    scanf("%d", &m1);  // Εισαγωγή της τιμής του m1

    printf("Dwse timh gia M2: ");
    scanf("%d", &m2);  // Εισαγωγή της τιμής του m2

    printf("Proth timh twn metavlhtwn: m1=%d, m2=%d.\n", m1, m2);

    // Κλήση της διαδικασίας για την αντιμεταθετική
    antimetathesi(&m1, &m2);

    printf("Meta tin antimetathesi: m1=%d, m2=%d.\n", m1, m2);

    return 0;
}
