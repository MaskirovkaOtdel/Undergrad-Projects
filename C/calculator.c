#include <stdio.h>
#include <stdlib.h>

float add(float a,float b) {
	return a+b;
}

float sub(float a, float b) {
	return a-b;
}

float mul(float a, float b) {
	return a*b;
}

float div1(float a, float b) {
	if (b!=0)
	 return a/b;
	else {
		printf("Error Division by zero isn't possible!\n"); 
	 return 0;
	 
	} 
}

int main() {
	float num1,num2;
	char operation;
	
	printf("Enter the first number: ");
	scanf("%f",&num1);

    printf("Enter operator1 (+, -, *, /): ");
	scanf("%c",&operation);
	
	printf("Enter second number:");
	scanf("%f",&num2);
	

	
	switch(operation){
		case '+':
			printf("Result: %lf\n", add(num1,num2));
			break;
		case '-':
			printf("Result: %lf\n", sub(num1,num2));
			break;
		case '*':
			printf("Result: %lf\n", mul(num1,num2));
			break;
		case '/':;
		    printf("Result: %lf\n", div1(num1,num2));
			break;
		default:
		    printf("Error: Invalid operator! \n");
				
	}
	
	return 0;
}
