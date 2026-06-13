#include <stdio.h>
#include <stdlib.h>

int main(){

int sum,i;

sum=0;
for(i=1; i<=50; i++) {
	sum=sum+i;
}
printf("Sum %d",sum);

return 0;	
}