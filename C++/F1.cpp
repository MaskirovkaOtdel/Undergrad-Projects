#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <bitset>
using namespace std;

// Function to prompt the user to continue or exit
bool PromptToContinue() {
    char choice;
    cout << "Do you want to continue? (y/n): ";
    cin >> choice;
    return (choice == 'y' || choice == 'Y');
}
//Min - Max Function
void MinMax() {
	int num1,num2;
	
	cout << "Give number 1: ";
    cin >> num1;
    
    cout << "Give number 2: ";
    cin >> num2;
    
    if (num1 > num2) {
    	cout << "Max is " << num1 << " and min is " << num2 << endl;
	}
	else
    	cout << "Max is " << num2 << " and min is " << num1 << endl;
	}
    	
// Basic Arithmetic Functions
void Add() {
    int num1, num2, sum;
    cout << "Give number 1: ";
    cin >> num1;
    cout << "Give number 2: ";
    cin >> num2;
    sum = num1 + num2;
    cout << "The sum of " << num1 << " and " << num2 << " is: " << sum << endl;
}

void Subt() {
    int num1, num2, subt;
    cout << "Give number 1: ";
    cin >> num1;
    cout << "Give number 2: ";
    cin >> num2;

    if (num1 > 0 && num2 > 0) {
        if (num1 > num2)
            subt = num1 - num2;
        else
            subt = num2 - num1;
    }
    else if (num1 > 0 && num2 < 0) {
        subt = num1 - num2; // subtracting a negative = addition
    }
    else if (num1 < 0 && num2 > 0) {
        subt = num2 - num1; // subtracting a negative = addition
    }
    else if (num1 < 0 && num2 < 0) {
        if (num1 > num2)
            subt = num1 - num2;
        else
            subt = num2 - num1;
    }
    else if (num1 == 0 && num2 > 0) {
        subt = num2;
    }
    else if (num1 == 0 && num2 < 0) {
        subt = -num2;
    }
    else if (num1 == 0 && num2 == 0) {
        subt = 0;
    }

    cout << "The result of subtraction is: " << subt << endl;
}

void Multiply() {
    int num1, num2, product;
    cout << "Give number 1: ";
    cin >> num1;
    cout << "Give number 2: ";
    cin >> num2;
    product = num1 * num2;
    cout << "The product of " << num1 << " and " << num2 << " is: " << product << endl;
}

void Divide() {
    int num1, num2;
    double quotient;
    cout << "Give number 1: ";
    cin >> num1;
    cout << "Give number 2: ";
    cin >> num2;
    if (num2 != 0) {
        quotient = (double)num1 / num2;
        cout << "The quotient of " << num1 << " divided by " << num2 << " is: " << quotient << endl;
    } else {
        cout << "Error: Division by zero is not allowed!" << endl;
    }
}

void Modulo() {
    int num1, num2, remainder;
    cout << "Give number 1: ";
    cin >> num1;
    cout << "Give number 2: ";
    cin >> num2;
    if (num2 != 0) {
        remainder = num1 % num2;
        cout << "The remainder when " << num1 << " is divided by " << num2 << " is: " << remainder << endl;
    } else {
        cout << "Error: Division by zero is not allowed!" << endl;
    }
}

// Advanced Mathematical Functions
void Exponentiation() {
    double base, exponent, result;
    cout << "Give the base: ";
    cin >> base;
    cout << "Give the exponent: ";
    cin >> exponent;
    result = pow(base, exponent);
    cout << "The result of " << base << " raised to the power " << exponent << " is: " << result << endl;
}

void SquareRoot() {
    double num, result;
    cout << "Give a number: ";
    cin >> num;
    if (num >= 0) {
        result = sqrt(num);
        cout << "The square root of " << num << " is: " << result << endl;
    } else {
        cout << "Error: Cannot compute square root of a negative number!" << endl;
    }
}

void AbsoluteValue() {
    int num;
    cout << "Give a number: ";
    cin >> num;
    cout << "The absolute value of " << num << " is: " << abs(num) << endl;
}

void Factorial() {
    int num;
    long long fact = 1;
    cout << "Give a number: ";
    cin >> num;
    if (num < 0) {
        cout << "Error: Factorial is not defined for negative numbers!" << endl;
    } else {
        for (int i = 1; i <= num; ++i) {
            fact *= i;
        }
        cout << "The factorial of " << num << " is: " << fact << endl;
    }
}

void Logarithm() {
    double num;
    cout << "Give a number: ";
    cin >> num;
    if (num > 0) {
        cout << "The natural logarithm of " << num << " is: " << log(num) << endl;
        cout << "The base-10 logarithm of " << num << " is: " << log10(num) << endl;
    } else {
        cout << "Error: Logarithm is only defined for positive numbers!" << endl;
    }
}

// Trigonometric Functions
void SinFunction() {
    double angle;
    cout << "Give the angle (in radians): ";
    cin >> angle;
    cout << "The sine of the angle is: " << sin(angle) << endl;
}

void CosFunction() {
    double angle;
    cout << "Give the angle (in radians): ";
    cin >> angle;
    cout << "The cosine of the angle is: " << cos(angle) << endl;
}

void TanFunction() {
    double angle;
    cout << "Give the angle (in radians): ";
    cin >> angle;
    cout << "The tangent of the angle is: " << tan(angle) << endl;
}

// Inverse Trigonometric Functions
void InverseSin() {
    double value;
    cout << "Give the value between -1 and 1: ";
    cin >> value;
    if (value >= -1 && value <= 1) {
        cout << "The arcsine of " << value << " is: " << asin(value) << " radians" << endl;
    } else {
        cout << "Error: Value must be between -1 and 1 for arcsine!" << endl;
    }
}

void InverseCos() {
    double value;
    cout << "Give the value between -1 and 1: ";
    cin >> value;
    if (value >= -1 && value <= 1) {
        cout << "The arccosine of " << value << " is: " << acos(value) << " radians" << endl;
    } else {
        cout << "Error: Value must be between -1 and 1 for arccosine!" << endl;
    }
}

void InverseTan() {
    double value;
    cout << "Give a value: ";
    cin >> value;
    cout << "The arctangent of " << value << " is: " << atan(value) << " radians" << endl;
}

// Hyperbolic Functions
void HyperbolicSin() {
    double angle;
    cout << "Give the angle (in radians): ";
    cin >> angle;
    cout << "The hyperbolic sine of the angle is: " << sinh(angle) << endl;
}

void HyperbolicCos() {
    double angle;
    cout << "Give the angle (in radians): ";
    cin >> angle;
    cout << "The hyperbolic cosine of the angle is: " << cosh(angle) << endl;
}

void HyperbolicTan() {
    double angle;
    cout << "Give the angle (in radians): ";
    cin >> angle;
    cout << "The hyperbolic tangent of the angle is: " << tanh(angle) << endl;
}

// Prime Number Checker
void IsPrime() {
    int num;
    cout << "Enter a number to check if it's prime: ";
    cin >> num;

    if (num <= 1) {
        cout << num << " is not a prime number." << endl;
        return;
    }

    for (int i = 2; i <= sqrt(num); ++i) {
        if (num % i == 0) {
            cout << num << " is not a prime number." << endl;
            return;
        }
    }

    cout << num << " is a prime number." << endl;
}

// Fibonacci Sequence
void Fibonacci() {
    int n;
    cout << "Enter the number of Fibonacci numbers to generate: ";
    cin >> n;

    int a = 0, b = 1;
    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; ++i) {
        cout << a << " ";
        int temp = a;
        a = b;
        b = temp + b;
    }
    cout << endl;
}

// Solve Quadratic Equation: ax^2 + bx + c = 0
void SolveQuadratic() {
    double a, b, c, discriminant, root1, root2;

    cout << "Enter coefficients a, b, and c for the equation ax^2 + bx + c = 0:" << endl;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;
    cout << "c = ";
    cin >> c;

    discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and distinct: " << root1 << " and " << root2 << endl;
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        cout << "Root is real and equal: " << root1 << endl;
    } else {
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Roots are complex: " << realPart << " + " << imaginaryPart << "i and "
             << realPart << " - " << imaginaryPart << "i" << endl;
    }
}

// Number Base Conversion
void ConvertNumberBase() {
    int number, choice;
    cout << "Enter the number you want to convert: ";
    cin >> number;
    cout << "Choose the base to convert to:\n1. Binary\n2. Octal\n3. Hexadecimal\n";
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Binary: " << bitset<32>(number) << endl; // Converts to binary and displays as a string
            break;
        case 2:
            cout << "Octal: " << oct << number << endl;
            break;
        case 3:
            cout << "Hexadecimal: " << hex << number << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
    }
}

// Random Number Generation
void GenerateRandomNumber() {
    int lower, upper;
    cout << "Enter the lower bound: ";
    cin >> lower;
    cout << "Enter the upper bound: ";
    cin >> upper;

    srand(time(0)); // seed the random number generator
    int random_num = rand() % (upper - lower + 1) + lower;
    cout << "Random number between " << lower << " and " << upper << " is: " << random_num << endl;
}

int main() {
    // Example of calling functions with prompt to continue
    MinMax();
    if (!PromptToContinue()) return 0;
    
    Add();
    if (!PromptToContinue()) return 0;

    Subt();
    if (!PromptToContinue()) return 0;

    Multiply();
    if (!PromptToContinue()) return 0;

    Divide();
    if (!PromptToContinue()) return 0;

    Modulo();
    if (!PromptToContinue()) return 0;

    Exponentiation();
    if (!PromptToContinue()) return 0;

    SquareRoot();
    if (!PromptToContinue()) return 0;

    AbsoluteValue();
    if (!PromptToContinue()) return 0;

    Factorial();
    if (!PromptToContinue()) return 0;

    Logarithm();
    if (!PromptToContinue()) return 0;

    SinFunction();
    if (!PromptToContinue()) return 0;

    CosFunction();
    if (!PromptToContinue()) return 0;

    TanFunction();
    if (!PromptToContinue()) return 0;

    InverseSin();
    if (!PromptToContinue()) return 0;

    InverseCos();
    if (!PromptToContinue()) return 0;

    InverseTan();
    if (!PromptToContinue()) return 0;

    HyperbolicSin();
    if (!PromptToContinue()) return 0;

    HyperbolicCos();
    if (!PromptToContinue()) return 0;

    HyperbolicTan();
    if (!PromptToContinue()) return 0;

    IsPrime();
    if (!PromptToContinue()) return 0;

    Fibonacci();
    if (!PromptToContinue()) return 0;

    SolveQuadratic();
    if (!PromptToContinue()) return 0;

    ConvertNumberBase();
    if (!PromptToContinue()) return 0;

    GenerateRandomNumber();
    if (!PromptToContinue()) return 0;

    return 0;
}
