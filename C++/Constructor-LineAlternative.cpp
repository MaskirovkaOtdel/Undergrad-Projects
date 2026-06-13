#include <iostream>
using namespace std;

class Line {
public:
    
    Line(double a = 12.0, double b = 8.0, double c = 4.0);
    
    
    void setLength(double len);
    double getLength(void);
    
    
    void printParams() const;
    
private:
    double length;
    double X, Y, Z;  
};


Line::Line(double a, double b, double c) : X(a), Y(b), Z(c) {
    cout << "Object created with: " 
         << " X: " << X << "  Y: " << Y << "  Z: " << Z << endl;
}


void Line::setLength(double len) {
    length = len;
}


double Line::getLength(void) {
    return length;
}


void Line::printParams() const {
    cout << "Parameters X: " << X << "  Y: " << Y << "  Z: " << Z << endl;
}

int main() {
    
    Line line1(12.0, 8.0, 4.0);  
    Line line2;  
    
    line1.setLength(6.0);
    line2.setLength(7.0);
    
    cout << "Length of line1: " << line1.getLength() << endl;
    cout << "Length of line2: " << line2.getLength() << endl;
    
    
    line1.printParams();
    line2.printParams();

    return 0;
}
