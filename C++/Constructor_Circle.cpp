#include <iostream>
#include <cmath>
#define PI 3.14159

using namespace std;

class Circle {
private:
    double rad;

public:
	Circle(double rad) {
		rad = r;
	}

    
    Circle() {
        rad = 1; 
    }

    
    //Circle(double r) {
        //rad = r;
    //}

    
    double calculateArea() {
        return PI * pow(rad,2);
    }

    
    double calculatePerimeter() {
        return 2 * PI * rad;
    }
};

int main() {
    Circle c1; 
    Circle c2(5); 

    cout << "Circle 1 (default radius):" << endl;
    cout << "Radius: " << c1.rad << endl;
    cout << "Area: " << c1.calculateArea() << endl;
    cout << "Perimeter: " << c1.calculatePerimeter() << endl;
    
    cout << "\nCircle 2 (radius = 5):" << endl;
    cout << "Radius: " << c2.rad << endl;
    cout << "Area: " << c2.calculateArea() << endl;
    cout << "Perimeter: " << c2.calculatePerimeter() << endl;

    return 0;
}
