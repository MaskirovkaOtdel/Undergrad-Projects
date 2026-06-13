#include <stdio.h>
// Δημιουργία της διαδικασίας για την αντιμεταθετική (swap)
void antimetathesi() {
    int m1, m2, mx;

    // Εισαγωγή τιμών για m1 και m2
    printf("Dwse timh gia M1: ");
    scanf("%d", &m1);  // Εισαγωγή της τιμής του m1

    printf("Dwse timh gia M2: ");
    scanf("%d", &m2);  // Εισαγωγή της τιμής του m2

    printf("Proth timh twn metavlhtwn: m1=%d, m2=%d.\n", m1, m2);
	
	mx=m1;
	m1=m2;
	m2=mx;
 	
    printf("Meta tin antimetathesi: m1=%d, m2=%d.\n", m1, m2);
}

int main() {
    antimetathesi();
    antimetathesi();
    antimetathesi();
    antimetathesi();
    antimetathesi();
    return 0;
}
