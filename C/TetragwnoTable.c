#include <stdio.h>

int main() {
    int table[10][2];
    int i, side;

    
    for (i = 0; i < 10; i++) {
        printf("Dwse thn pleyra toy tetragwnoy %d: ", i + 1);
        scanf("%d", &side); 

        
        table[i][0] = side * side; 
        table[i][1] = 2 * side; 
    }

    
    printf("\nTetragwno | Perimetros\n");
    for (i = 0; i < 10; i++) {
        printf("%d\t\t%d\n", table[i][0], table[i][1]);
    }

    return 0;
}
