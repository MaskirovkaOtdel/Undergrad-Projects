#include <stdio.h>
#include <stdlib.h>

int main() {
	int i,j;
	
	for(i=0;i<4;i++)
		for(j=0;j<4;j++)
			printf("\%d+%d=%d\n",i,j,i+j);
	return 0;
}

