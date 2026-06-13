#include <stdio.h>
#include <stdlib.h>
#define N 10
#define M 5

int main() {
    int pinakas[N][M];
    int i, j;

    // Εισαγωγή των στοιχείων του πίνακα
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("Dwse to %do stoixeio (%d, %d): ", (i * M + j + 1), i + 1, j + 1);
            scanf("%d", &pinakas[i][j]);
        }
    }

    // Εκτύπωση των στοιχείων του πίνακα
    printf("\nTa stoixeia tou pinaka einai:\n");
    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            printf("Stoixeio %do: %d\n", (i * M + j + 1), pinakas[i][j]);
        }
    }

    return 0;
}
