#include <stdio.h>
int main(){
	
	int mx,m1,m2;
	m1=12;
	m2=17;
	printf("m1=%d,m2=%d.\n",m1,m2);
	
	mx=m1;
	m1=m2;
	m2=mx;
	
	printf("m1=%d,m2=%d.\n",m1,m2);
	return 0;
}