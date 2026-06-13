
#include <stdio.h>

#define PI 3 

int main() {
    int shape[12][3]; 
    int i, side_or_radius, type;

    
    for (i = 0; i < 12; i++) {
        printf("Epilexe to sxhma (1: Tetragwno, 2: Isosplevro Trigwno, 3: Kyklos) gia to sxhma %d: ", i + 1);
        scanf("%d", &type);
        shape[i][0] = type; 

        if (type == 1) { 
            printf("Dwse pleyra tou tetragwnou: ");
            scanf("%d", &side_or_radius);
            shape[i][1] = PI;  
            shape[i][2] = 4 * side_or_radius; 
        } else if (type == 2) { 
            printf("Dwse pleyra tou isoplevrou trigwnou: ");
            scanf("%d", &side_or_radius);
            shape[i][1] = PI;
            shape[i][2] = 3 * side_or_radius;  
        } else if (type == 3) { 
            printf("Dwse akrina tou kukloy: ");
            scanf("%d", &side_or_radius);
            shape[i][1] = 3;  
            shape[i][2] = 2 * 3 * side_or_radius; 
        } else {
            printf("Lathos epilogi sxhmatos. Epilekse 1, 2, h 3.\n");
            i--; 
        }
    }


    printf("---------------------------------------------------------------------------------------------");
    printf("\n|     Theseis      |            Sxhma           |      Timi (Pi/R)    |      Perimetros     |\n");
    printf("---------------------------------------------------------------------------------------------\n");

    for (i = 0; i < 12; i++) {
        if (shape[i][0] == 1) {
            printf("|       %d\t |\t(Tetragwno)\t\t %d\t\t\t%d\n", i + 1, shape[i][1], shape[i][2]);
        } else if (shape[i][0] == 2) {
            printf("|        %d\t   |\t(Isoplevro Trigwno)\t|       %d\t      | \t%d\n", i + 1, shape[i][1], shape[i][2]);
        } else if (shape[i][0] == 3) {
            printf("|       %d\t |\t\t(Kyklos)\t\t \t%d\t\t\t%d\n", i + 1, shape[i][1], shape[i][2]);
        }
    }

    return 0;
}
