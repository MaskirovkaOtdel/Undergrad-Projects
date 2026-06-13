//AV,min,max thermokrasias 10 hmerwn, float temp, for 10 fores me elegxo timwn apo thermokrasia -12 ews 50

#include <stdio.h>
#include <stdlib.h>

int main() {
	float temp,table[10][2];
	int i;
	char input[50];
	
	    // Εισαγωγή και έλεγχος εισόδου
    for (i = 0; i < 10; i++) {
    	
    do {
        printf("Dwse thermokrasia apo -12 ews 50: ");
        fgets(input, sizeof(input), stdin); // Διαβάζουμε ολόκληρη τη γραμμή
        if (sscanf(input, "%f", &temp) < -12) {
            printf("Mh egkyrh eisodos! Prepei na eisageis enan arithmo.\n");
            continue;
        }
        if (temp < -12 || temp > 50) {
            printf("H thermokrasia prepei na einai apo -12 ews 50. Prospathise ksana.\n");
        }
    } while (temp >= -12 || temp <= 50);
    
        table[i][0] = i; 
        table[i][1] = temp;
        printf("%d\t\t%d\n", table[i][0], table[i][1]);
	}
    
    
}