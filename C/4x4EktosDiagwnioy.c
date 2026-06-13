#include <stdio.h>
#include <stdlib.h>

int no_ij() {
    int pinakas[4][4];
    int i, j;

    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            if (i != j) {  
                printf("\nDwse to %do stoixeio (%d, %d): ", (i * 4 + j + 1), i + 1, j + 1);
                scanf("%d", &pinakas[i][j]);
            } else {
                pinakas[i][j] = 0; 
            }
        }
    }

   	printf("\n-------------------------------");
    printf("\n|Ta stoixeia tou pinaka einai:|\n");
    printf("-------------------------------\n");

 
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            if (i != j) {  
                printf("|  %d  |\t", pinakas[i][j]);
            } else {
                printf("|  X  |\t"); 
            }
        }
        printf("\n");
        printf("-------------------------------\n");
    }

    return 0;
    
}
int only_ij() {
    int pinakas[4][4];
    int i, j;

    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            if (i == j) {  
                printf("\nDwse to %do stoixeio (%d, %d): ", (i * 4 + j + 1), i + 1, j + 1);
                scanf("%d", &pinakas[i][j]);
            } else {
                pinakas[i][j] = 0; 
            }
        }
    }
	printf("\n-------------------------------");
    printf("\n|Ta stoixeia tou pinaka einai:|\n");
    printf("-------------------------------\n");

 
    for (i = 0; i < 4; i++) { 
        for (j = 0; j < 4; j++) { 
            if (i == j) {  
                printf("|  %d  |\t", pinakas[i][j]);
            } else {
                printf("|  X  |\t"); 
            }
        }
        printf("\n");
        printf("-------------------------------\n");
    }

    return 0;
    
}

//if (i != j)
//if (i == j)
int main(int argc, char* argv[]) {
    no_ij();
    only_ij();
    return 0;
}