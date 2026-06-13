#include <iostream>
#include <string>
using namespace std;


class Person {
private:
    string name;  
    int age;      

public:
    
    void setName(string n) {
        name = n;
    }

    
    void setAge(int a) {
        age = a;
    }

    
    void displayAge() {
        cout << "Η ηλικία του " << name << " είναι: " << age << " έτη." << endl;
    }
};

int main() {
   
    Person apostolis, vicky;

   
    apostolis.setName("Apostolis");
    apostolis.setAge(33);

    
    vicky.setName("Vicky");
    vicky.setAge(28);

    
    apostolis.displayAge();

    
    vicky.displayAge();

    return 0;
}
