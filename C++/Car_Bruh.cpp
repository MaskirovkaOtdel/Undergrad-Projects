#include <iostream>
#include <string>
using namespace std;

class Car {
private:
    int year;
    string company;
    string model;

public:
    
    Car(int y, string c, string m) {
        year = y;
        company = c;
        model = m;
    }

    

    
    void setYear(int y) {
        year = y;
    }

    int getYear() {
        return year;
    }

    
    void setCompany(string c) {
        company = c;
    }

    string getCompany() {
        return company;
    }

    
    void setModel(string m) {
        model = m;
    }

    string getModel() {
        return model;
    }

    
    void displayCarDetails() {
        cout << "Car Details:" << endl;
        cout << "Year: " << getYear() << endl;
        cout << "Company: " << getCompany() << endl;
        cout << "Model: " << getModel() << endl;
        cout << endl;
    }
};

int main() {
    
    Car bmwCar(2021, "BMW", "X5");
    Car audiCar(2022, "Audi", "A6");

    
    bmwCar.displayCarDetails();
    audiCar.displayCarDetails();

    
    bmwCar.setYear(2023);
    bmwCar.setModel("X6");

    audiCar.setYear(2023);
    audiCar.setModel("Q7");

    
    cout << "Updated Car Details:" << endl;
    bmwCar.displayCarDetails();
    audiCar.displayCarDetails();

    return 0;
}
