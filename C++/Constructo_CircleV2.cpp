#include <iostream>
#include <cmath> 

using namespace std;

class Circle {
private:
    double rad;

public:
    
    Circle(double r) {
        rad = r;
    }

    
    double getRadius() const {
        return rad;
    }

    
    double area() const {
        return M_PI * rad * rad;
    }

    
    double circumference() const {
        return 2 * M_PI * rad;
    }
};

int main() {
    double inputRadius;
	Circle c1; 
    Circle c2(5);
    
    cout << "Enter the radius of the circle: ";
    cin >> inputRadius;

    
    Circle c(inputRadius);

    
    cout << "Radius: " << c.getRadius() << endl;
    cout << "Area: " << c.area() << endl;
    cout << "Circumference: " << c.circumference() << endl;
	
    return 0;
}
