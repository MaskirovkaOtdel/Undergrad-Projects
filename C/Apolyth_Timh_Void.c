#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void apolyth_timh() {
	
	float number;

    // Ζητάμε από τον χρήστη να εισάγει έναν αριθμό
    printf("Eisagete enan arithmo (float): ");
    scanf("%f", &number);

    // Υπολογίζουμε και εμφανίζουμε την απόλυτη τιμή του αριθμού
    printf("H apolyth timh toy %.2f einai %.2f\n", number, fabs(number));

    // Δήλωση δεύτερης μεταβλητής για ακέραιο αριθμό
    int number2;

    // Ζητάμε από τον χρήστη να εισάγει έναν ακέραιο αριθμό
    printf("Eisagete enan akeraio arithmo (int): ");
    scanf("%d", &number2);

    // Υπολογίζουμε και εμφανίζουμε την απόλυτη τιμή του ακέραιου αριθμού
    printf("H apolyth timh toy %d einai %d\n", number2, abs(number2));

    return 0;
}

int main() {
	int i;
	for(i=0; i<5; i++)
	{	
	printf("h timh einai %d\n",i+1);
	printf("EINAI H %dh FORA\n",i+1);	
	apolyth_timh();
	}

	return 0;
}