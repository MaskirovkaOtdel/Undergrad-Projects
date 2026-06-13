#include <bits/stdc++.h>
using namespace std;

int main() {
	int var = 20;
	int *ptr = &var;
	
	
	cout << "value at ptr = " << ptr << "\n";
	cout << "value at var = " << var << "\n";
	cout << "Value at *ptr = " << *ptr << "\n";
	
	*ptr = 40;
	cout << "value at var = " << *ptr << "\n";
}