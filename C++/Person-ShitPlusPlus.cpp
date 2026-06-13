#include <iostream>
#include <string>
using namespace std;

class Person {
private:
    int age;
    string name;

public:
    
    void setAge(int a) {
        age = a;
    }

    
    void setName(const string& n) {
        name = n;
    }

    
    void getDetails() const {
        cout << "My name is: " << name << " and I'm: " << age << " years old" << endl;
    }
	};


	class Panos : public Person {
    
	};


	class Mary : public Person {
   
	};

	int main() {
    Panos panos;
    Mary mary;

    panos.setName("Panos");
    panos.setAge(30);

    mary.setName("Mary");
    mary.setAge(25);

    panos.getDetails();
    mary.getDetails();

    return 0;
}
