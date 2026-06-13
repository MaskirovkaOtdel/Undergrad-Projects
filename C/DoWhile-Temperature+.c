//Avrg,Min,Max theloyme apo 10 thermokrasies hmerwn poy dinei o xrhsths kai afoy ginetai elegxos egkyrothtas timwn proxwraei
//sthn dhmhoyrgia pinaka timwn me tis thermokrasies emfanizontas kai ta katallhla mynhmata!

#include <stdio.h>
#include <stdlib.h>

int main() {
	system("color 0A");
    float temp, table[10][2],sum = 0, minTemp = 51, maxTemp = -13;
    int i;
    char input[50];
    
    
    for (i = 0; i < 10; i++) {
        do {
            printf("Dwse thn %dh thermokrasia: ", i+1);
            fgets(input, sizeof(input), stdin); 
            
            
            if (sscanf(input, "%f", &temp) != 1) {
                printf("Mh egkyrh eisodos! Prepei na eisageis enan arithmo.\n");
                continue;
            }
            
            
            if (temp < -12 || temp > 50) {
                printf("H thermokrasia prepei na einai apo -12 ews 50. Prospathise ksana.\n");
            }
        } while (temp < -12 || temp > 50);  
        
        
        table[i][0] = i + 1;  
        table[i][1] = temp;    
        
        
        sum += temp;
        
        
        if (temp < minTemp) {
            minTemp = temp;
        }
        
        
        if (temp > maxTemp) {
            maxTemp = temp;
        }
    }

    
    printf("\nPinakas thermokrasiwn:\n");
    for (i = 0; i < 10; i++) {
        printf("H timi tis %dhs thermokrasias einai: %.2fC\n", (int)table[i][0], table[i][1]);
    }

    
    float average = sum / 10;
    printf("\nMesos oros thermokrasiwn: %.2f\n", average);
    
    
    printf("H elaxisth thermokrasia einai: %.2f\n", minTemp);
    printf("H megisth thermokrasia einai: %.2f\n", maxTemp);
    
    return 0;
}
