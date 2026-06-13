#include <stdio.h>

int main() {
    int table[20]; 
    int i, side;
    
    for (i = 0; i < 10; i++) {
        printf("Dwse thn pleyra tou tetragwnoy %d: ", i + 1);
        scanf("%d", &side);

        table[2 * i] = side * side;  
        table[2 * i + 1] = 4 * side; 
    }

    printf("-------------------------------------------------------------");
    printf("\n| Tetragwno |  Theseis   |    Emvado    |     Perimetros    |\n");
    printf("-------------------------------------------------------------\n");

    
    for (i = 0; i < 10; i++) {
        
        printf("|    %d\t    |\t(%d,%d)\t |  \t%d\t|    \t%d\t    |\n", i + 1, 2 * i, 2 * i + 1, table[2 * i], table[2 * i + 1]);
        //printf("-------------------------------------------------------------\n"); eswterikos pinakas
    }
		printf("-------------------------------------------------------------\n"); //ejwterikos pinakas
    return 0;
}


//ftiaxnw ton monodiastato shape[12] opoy ston idio me theseis apo 0-11 tha mpainei ana triades enas arithmos apo to 1-3 sto prwto keli opoy an 1 einai tetragwno, an 2 isoplevro trigwno, an 3 kyklos, sto deytero keli analoga me thn prwth epilogh tha vazei π an tetragwno h trigwno h ρ an kyklos, kai sto trito keli na vazei thn perimetro. Epishs tha zhtaei apo ton xrhsth na dinei pleyra h aktina afoy epilejei ti sxhma tha einai. Thewroyme oti π=3 