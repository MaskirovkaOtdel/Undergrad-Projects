//πινακας ακεραιων που τον γεμιζει ο user και εμφανιζει αθροισμα και πολλαπλασιαμο των τιμων του πινακα με ελεγχο τιμων

#include <stdio.h>
#include <stdlib.h>



int main() {
	system("color 8a"); //or 7c for usage for red and light gray background!
    int pinakas[4][4];
    int i, j, sum = 0, mult = 1;

    
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("Dwse tin timh gia tis theseis (%d, %d): ", i + 1, j + 1);
            scanf("%d", &pinakas[i][j]);

            
            if (pinakas[i][j] < 0 || pinakas[i][j] > 100) {
                printf("Parakalo dwste timh metaksy 0 kai 100.\n");
                j--;  
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            sum += pinakas[i][j];
            mult *= pinakas[i][j];
        }
    }

    
    printf("\nTo athroisma twn timwn tou pinaka einai: %d\n", sum);
    printf("O pollaplasiasmos twm timwn tou pinaka einai: %d\n", mult);

    return 0;
}
