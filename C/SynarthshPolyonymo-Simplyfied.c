#include <stdio.h>
void swap() {
    int tmp,a,b;
    // Εισαγωγή τιμών για a και b
    printf("dwse timh gia a: ");
    scanf("%d", &a);  // Εισαγωγή της τιμής του a

    printf("dwse timh gia b: ");
    scanf("%d", &b);  // Εισαγωγή της τιμής του b

    printf("prwth timh metavlhtwn: a=%d, b=%d.\n", a, b);
    
    tmp = a;
    a = b;
    b = tmp;
    printf("meta thn antimetathesh: a=%d, b=%d.\n", a, b);
    
}
int Polyonymo(int k, int y, int z) {
    int x, apo;
    printf("dwse arithmo gia x: ");
    scanf("%d", &x); 
    apo = k * x * x + y * x + z;
    return apo;
}
int main() {
    
    swap();  // Κλήση με διευθύνσεις των μεταβλητών a, b, c
   
    int result = Polyonymo(2, 7, 4);  // Κλήση της συνάρτησης Polyonymo
    printf("Apotelesma polywnymoy: %d\n", result);  // Εκτύπωση του αποτελέσματος
    return 0;
}
