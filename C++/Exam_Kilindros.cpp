#include <iostream>
#include <cmath>
using namespace std;


const float Pi = 3.14159265358979323846;


class Circle {
protected:
    float aktina; 

public:
    
    float emvado() {
        return pow(aktina, 2) * Pi;
    }

    
    void set_r(float r) {
        aktina = r;
    }

    
    float get_r() {
        return aktina;
    }
};


class Kilindros : public Circle {
private:
    float height;  

public:
    
    float volume() {
        return emvado() * height; 
    }

    
    void set(float r, float h) {
        set_r(r);  
        height = h;  
    }
};

int main() {
    
    Kilindros k;

    
    k.set(5.0, 10.0);  

    
    cout << "O ogkos toy kilindroy einai: " << k.volume() << " kyvikes monades." << endl;

    return 0;
}
