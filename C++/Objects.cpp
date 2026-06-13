#include <iostream>
#include <string>

using namespace std;


class Person {
private:
    
    string name;
    int age;

public:
    
    Person(const string& n, int a) : name(n), age(a) {}

    
    void introduce() const {
        cout << "Hi, my name is " << name << " and I am "
             << age << " years old." << "\n"; 
    }

    
    void display() const {
        cout << "Name: " << name << ", Age: " << age << "\n"; 
    }
};

int main() {
    
    Person person1("Bruh", 69);

    
    person1.introduce();

    
    cout << "\n"; 

    
    person1.display();

    return 0;
}
