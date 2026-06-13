#include <stdio.h>
#include <stdlib.h>
//diavazei vathmo, kanei elegxo timwn, emfanizei perases h emeines analogws

int main() {
	int vathmos;
	
	do {
		printf("dwse vathmo apo 1 - 10 :");
		scanf("%d", &vathmos);
	}
	while (vathmos < 1 || vathmos > 10);
	
	if (vathmos>=5) {
		printf("perases");
	}
		else {
		printf("emeines");
	}
}