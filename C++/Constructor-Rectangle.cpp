#include <iostream>
using namespace std;

class Rectangle {
public:
    Rectangle(double w, double h); 
    void setWidth(double w);
    double getWidth(void);
    void setHeight(double h);
    double getHeight(void);

private:
    double width;
    double height;
};


Rectangle::Rectangle(double w, double h) {
    width = w;
    height = h;
    cout << "Object has been created" << endl;
}

void Rectangle::setWidth(double w) {
    width = w;
}

double Rectangle::getWidth(void) {
    return width; 
}

void Rectangle::setHeight(double h) {
    height = h; 
}

double Rectangle::getHeight(void) {
    return height; 
}

int main() {
    
    Rectangle rect1(6.0, 7.0); 
    Rectangle rect2(7.0, 8.0);

    cout << "Width of rect1: " << rect1.getWidth() << endl;
    cout << "Height of rect1: " << rect1.getHeight() << endl;

    cout << "Width of rect2: " << rect2.getWidth() << endl;
    cout << "Height of rect2: " << rect2.getHeight() << endl;

    return 0;
}
