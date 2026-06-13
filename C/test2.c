#include <stdio.h>
int main(){
	int x,y,z;
	x=4;
	y=7;
	z=++y;
	printf("x=%d,y=%d,z=%d.\n",x,y,z);
	y=x++;
	printf("x=%d,y=%d,z=%d.\n",x,y,z);
	z=--y;
	printf("x=%d,y=%d,z=%d.\n",x,y,z);
	return 0;
}