#include <stdio.h>
int main() {
	int x,y;
	x=2;
	y=9;
	x++;
	--y;
	++x;
	x--;
	y--;
	++y;
	printf("x=%d, y=%d.\n",x,y);
	return 0;
}