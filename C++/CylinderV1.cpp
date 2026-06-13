#include <iostream>
using namespace std;


class Circle {
private:
    double radius;
    double area;

public:
    
    void setRadius(double r) {
        radius = r;
        setArea();  
    }

    
    void setArea() {
        area = 3.14159 * radius * radius;
    }

    
    double getRadius() const {
        return radius;
    }

    
    double getArea() const {
        return area;
    }
};

class Cylinder : public Circle {
private:
    double depth;

public:
    
    void setDepth(double d) {
        depth = d;
    }

    
    double getDepth() const {
        return depth;
    }

    
    double getVolume() const {
        return getArea() * depth;
    }
};

int main() {
    Cylinder cyl;
    cyl.setRadius(5.0);
    cyl.setDepth(10.0);

    cout << "Radius: " << cyl.getRadius() << endl;
    cout << "Area: " << cyl.getArea() << endl;
    cout << "Depth: " << cyl.getDepth() << endl;
    cout << "Volume: " << cyl.getVolume() << endl;

    return 0;
}
