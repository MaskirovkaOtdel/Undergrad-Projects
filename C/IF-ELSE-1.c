#include <stdio.h>

void swap() {
    int tmp, a, b;
    
    printf("dwse timh gia a: ");
    scanf("%d", &a); 

    printf("dwse timh gia b: ");
    scanf("%d", &b);  

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
    int x;  

    printf("dwse timh gia x (1 gia swap, 2 gia polyonymo): ");
    scanf("%d", &x); 

    if (x == 1) {
        swap();
    } else if (x == 2) {
        int result = Polyonymo(2, 7, 4); 
        printf("Apotelesma polywnymoy: %d\n", result); 
    } else {
        printf("Lathos Epilgh!\n");
    }

    return 0;
}
