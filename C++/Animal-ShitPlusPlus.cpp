#include <iostream>
using namespace std;

class Animal {
public:
    void Eat() {  
        cout << "I can eat" << endl;
    }

    void Sleep() {  
        cout << "I can sleep" << endl;
    }
};

class Dog : public Animal {
public:
    Dog() {
        cout << "Woof Woof" << endl;
    }
};

int main() {
    Dog obj;

    
    obj.Eat();
    obj.Sleep();

    return 0;
}
