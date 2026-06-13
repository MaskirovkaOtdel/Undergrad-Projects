#include <stdio.h>
#include <stdlib.h>

double add(double a,double b) {
	return a+b;
}

double sub(double a, double b) {
	return a-b;
}

double mul(double a, double b) {
	return a*b;
}

double div(double a, double b) {
	if (b!=0)
	 return a/b;
	else {
		printf("Error Division by zero isn't possible!\n"); 
	 return 0;
	 
	} 
}

int main() {
	double num1,num2;
	char operation;
	
	printf("Enter the first number: ");
	scanf("%lf", &num1);
	
    while ((getchar())  != '\n');
    
    printf("Enter the operator (+, -, *, /,): ");
    scanf("%c", &operation);
    
    printf("Enter the second number: ");
    scanf("%lf", &num2);

	

	

	
if (operation =='+'){
	printf("Result: %lf\n", add(num1,num2));
   } else if(operation=='-') {
	printf("Result: %lf\n", sub(num1,num2));
   }	else if(operation=='*') {
	printf("Result: %lf\n", mul(num1,num2));
   }	else if(operation=='/'){
	printf("Result: %lf\n", div(num1,num2));
   }    else {
   	printf("Error:Invalid operator\n");
   }
   return 0;
}