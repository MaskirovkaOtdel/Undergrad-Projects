#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
using namespace std;

float add(float a,float b) {
	return a+b;
}
float sub(float a, float b) {
	return a-b;
}
float mul(float a, float b) {
	return a*b;
}
float div(float a, float b) {
	if (b!=0)
	 return a/b;
	else {
		cout <<"Error division by zero is not possible" << endl;
	 return 0;
	 
	} 
}

int main() {
	float num1,num2;
	char operation;
	
	cout <<"Enter first number:";
	cin >> num1;
	
	cout<<"Enter operator(+,-,*,/):";
	cin >> operation;
	
	cout <<"Enter second number:";
	cin >> num2;
	
	switch(operation){
		case '+':
			cout << "Result:" << add(num1,num2) << endl;
			break;
		case '-':
			cout << "Result:" << sub(num1,num2) << endl;
			break;
		case '*':
			cout << "Result:" << mul(num1,num2) << endl;
			break;
		case '/':;
		    cout << "Result:" << div(num1,num2) << endl;
			break;
		default:
		    cout << "Error: Invalid operator!" << endl;
				
	}
	
	return 0;
}
