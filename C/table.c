#include <stdio.h>

int main() {
    int table[10]; 
    int a; 

    printf("o Pinakas einai:\n");

    
    for (int i = 0; i <= 9; i++) {
        printf("Dwse stoixeio %d: ", i + 1); 
        scanf("%d", &table[i]); 
    }

   
    printf("o pinakas einai: \n");
    for (int i = 0; i <= 9; i++) {
        printf("H Thesi %d einai: %d\n", i + 1, table[i]);
    }

    return 0;
}


//ftiakse ena dekathesio pinaka opoy oi times tha mpainoyn se zeygaria. Sthn prwth thesi apothikeyetai h timh toy tetragwnoy kai sth deyterh h timh ths perimetroy toy!