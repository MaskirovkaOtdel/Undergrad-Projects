#include <iostream>
using namespace std;

class Kouti {
public:
    double length;    // Μήκος
    double breadth;   // Πλάτος
    double height;    // Ύψος
};

int main() {
    // Δημιουργία αντικειμένων τύπου Kouti
    Kouti KoutiA, KoutiB;
    
    // Αρχικοποίηση μεταβλητών KoutiA
    KoutiA.length = 2.0;
    KoutiA.breadth = 3.2;
    KoutiA.height = 6.0;
    
    // Αρχικοποίηση μεταβλητών KoutiB
    KoutiB.length = 2.5;
    KoutiB.breadth = 4.0;
    KoutiB.height = 5.0;

    // Υπολογισμός του όγκου για το KoutiA
    double ogkos = KoutiA.length * KoutiA.breadth * KoutiA.height;
    cout << "O Ogkos tou Kouti A einai: " << ogkos << " kyvikes monades." << endl;

    // Υπολογισμός του όγκου για το KoutiB
    ogkos = KoutiB.length * KoutiB.breadth * KoutiB.height;
    cout << "O Ogkos tou Kouti B einai: " << ogkos << " Kyvikes monades." << endl;

    return 0;
}
