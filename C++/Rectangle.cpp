#include <iostream>
#include <sstream>
#include <string>

class Rectangle {
private:
    double length;  
    double width;   
    std::string lengthUnit;
    std::string widthUnit;

    
    double toCentimeters(double value, const std::string& unit) {
        if (unit == "mm") {
            return value / 10;  
        } else if (unit == "m") {
            return value * 100; 
        }
        return value;  
    }

    
    double convertToUnit(double value, const std::string& unit, const std::string& type) {
        if (unit == "mm") {
            if (type == "area") {
                return value * 100;  
            } else {
                return value * 10;   
            }
        } else if (unit == "m") {
            if (type == "area") {
                return value / 100; 
            } else {
                return value / 100;  
            }
        }
        return value;  
    }

public:
    Rectangle() {
        length = 0;
        width = 0;
        lengthUnit = "cm";  
        widthUnit = "cm";   
    }

    
    void setLength(double l, const std::string& unit) {
        if (l > 0) {
            length = toCentimeters(l, unit);  
            lengthUnit = unit;
        } else {
            std::cout << "Length must be positive \n";
        }
    }

    
    void setWidth(double w, const std::string& unit) {
        if (w > 0) {
            width = toCentimeters(w, unit);  
            widthUnit = unit;
        } else {
            std::cout << "Width must be positive \n";
        }
    }

    
    double getArea() {
        return length * width;
    }

    
    double getPerimeter() {
        return 2 * (length + width);
    }

    
    void printDimensions() {
        std::cout << "Length is: " << length << " " << lengthUnit << "\n";
        std::cout << "Width is: " << width << " " << widthUnit << "\n";
    }

    
    void printAreaAndPerimeter() {
        double area = getArea();
        double perimeter = getPerimeter();

        
        area = convertToUnit(area, lengthUnit, "area");
        perimeter = convertToUnit(perimeter, lengthUnit, "perimeter");

        if (lengthUnit == "mm") {
            std::cout << "The Area of the rectangle is: " << area << " mm\n";
            std::cout << "The Perimeter of the rectangle is: " << perimeter << " mm\n";
        } else if (lengthUnit == "m") {
            std::cout << "The Area of the rectangle is: " << area << " m\n";
            std::cout << "The Perimeter of the rectangle is: " << perimeter << " m\n";
        } else {
            std::cout << "The Area of the rectangle is: " << area << " cm\n";
            std::cout << "The Perimeter of the rectangle is: " << perimeter << " cm\n";
        }
    }
};

double parseInput(const std::string& input, std::string& unit) {
    double value;
    std::stringstream ss(input);
    ss >> value >> unit;
    return value;
}

int main() {
    Rectangle rect;
    std::string lengthInput, widthInput, lengthUnit, widthUnit;

    std::cout << "Enter the unit for Length and Width (mm, cm, m): ";
    std::string unit;
    std::getline(std::cin, unit);

    std::cout << "Enter Length (" << unit << "): ";
    std::getline(std::cin, lengthInput);
    double length = parseInput(lengthInput, lengthUnit);
    rect.setLength(length, lengthUnit);

    std::cout << "Enter Width (" << unit << "): ";
    std::getline(std::cin, widthInput);
    double width = parseInput(widthInput, widthUnit);
    rect.setWidth(width, widthUnit);

    rect.printDimensions();

    rect.printAreaAndPerimeter();

    return 0;
}
