#include <stdio.h>
#include <stdlib.h>

int main() {
    int pinakas[4][4];
    int i, j;

  
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Dwse to %do stoixeio (%d, %d): ", (i * 4 + j + 1), i + 1, j + 1);
            scanf("%d", &pinakas[i][j]);
        }
    }


    printf("\nTa stoixeia tou pinaka einai:\n");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Stoixeio %do: %d\n", (i * 4 + j + 1), pinakas[i][j]);
        }
    }

    return 0;
}
