#include <iostream>
using namespace std;

class Shape {
public:
    
    Shape(int w = 0, int h = 0) : width(w), height(h) {}

    
    int getWidth() const { return width; }
    int getHeight() const { return height; }

protected:
    int width;
    int height;
};

class Rectangle : public Shape {
public:
    
    Rectangle(int w, int h) : Shape(w, h) {}

    
    int getArea() const {
        return width * height;
    }
};

int main() {
    Rectangle Rect(5, 7); 
    cout << "Total area: " << Rect.getArea() << endl;
    return 0;
}
