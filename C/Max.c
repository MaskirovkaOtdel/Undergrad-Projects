#include <stdio.h>
#include <math.h>

int main()    
{
    float num1, num2, num3, max;

    printf("Eisagete 3 arithmoys: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    // Υπολογισμός του μέγιστου αριθμού
    if (num1 >= num2 && num1 >= num3) { 
        max = num1;
    }
    else if (num2 >= num1 && num2 >= num3) {
        max = num2;
    }
    else {
        max = num3;
    }

    printf("Megistos einai o %.3f \n", max);

    return 0;
}


