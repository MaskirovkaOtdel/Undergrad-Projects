#include <iostream>
using namespace std;

class Line {
public:
    void setLength(double length);
    double getLength(void);
    Line();
private:
    double length;    
};

Line::Line(void) {
    cout << "object has been created" << endl;
}

void Line::setLength(double len) {
    length = len;
}

double Line::getLength(void) {
    return length;
}

int main() {
    Line line1;  
    Line line2; 
    line1.setLength(6.0);  
    line2.setLength(7.0);  
    cout << "Length of line1 : " << line1.getLength() << endl;  
    cout << "Length of line2 : " << line2.getLength() << endl;  
    return 0; 
}
