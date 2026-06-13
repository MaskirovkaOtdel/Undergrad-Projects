/* if_03.c: Deixnei tin xrhsh ths f */
#include <stdio.h>
void swap() {
    int tmp,a,b;
    // Εισαγωγή τιμών για a και b
    printf("dwse timh gia a: ");
    scanf("%d", &a);  // Εισαγωγή της τιμής του a

    printf("dwse timh gia b: ");
    scanf("%d", &b);  // Εισαγωγή της τιμής του b

    printf("prwth timh metavlhtwn: a=%d, b=%d.\n", a, b);
    
    tmp = a;
    a = b;
    b = tmp;
    printf("meta thn antimetathesh: a=%d, b=%d.\n", a, b);
    
}
int Polyonymo(int k, int y, int z) {
    int x, apo;
    printf("dwse arithmo gia x: ");
    scanf("%d", &x); 
    apo = k * x * x + y * x + z;
    return apo;
}
main()
{
		int x;
		int y;
		
		printf("Dwste ton akeraio x: ");
		scanf("%d",&x);
		printf("Dwste ton akeraio y: ");
		scanf("%d",&y);
		
		if(x<y) {
				printf("Isxyei x<y");
		}
		else {
			if(x==y)
				printf("Isxyei x=y");
			else
				printf("Isxyei x>y");
			
		}				
}