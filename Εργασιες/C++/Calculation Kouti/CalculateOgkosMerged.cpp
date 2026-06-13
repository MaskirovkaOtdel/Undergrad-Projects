#include <iostream>
using namespace std;

class Kouti {
private:
    double length;    // Μήκος
    double breadth;   // Πλάτος
    double height;    // Ύψος

public:
    // Μέθοδοι setter για την αρχικοποίηση των ιδιοτήτων
    void setMikos(double l) {
        length = l;
    }

    void setPlatos(double b) {
        breadth = b;
    }

    void setYpsos(double h) {
        height = h;
    }

    // Μέθοδος για τον υπολογισμό του όγκου
    double calculateOgkos() {
        return length * breadth * height;
    }

    // Μέθοδοι getter για την εμφάνιση των ιδιοτήτων (αν χρειάζεται)
    double getMikos() {
        return length;
    }

    double getPlatos() {
        return breadth;
    }

    double getYpsos() {
        return height;
    }
};

int main() {
    // Δημιουργία αντικειμένων τύπου Kouti
    Kouti KoutiA, KoutiB, KoutiC;

    // Αρχικοποίηση του KoutiA με τις αντίστοιχες τιμές
    KoutiA.setMikos(2.0);
    KoutiA.setPlatos(3.2);
    KoutiA.setYpsos(6.0);
    
    // Αρχικοποίηση του KoutiB με τις αντίστοιχες τιμές
    KoutiB.setMikos(2.5);
    KoutiB.setPlatos(4.0);
    KoutiB.setYpsos(5.0);

    // Υπολογισμός του όγκου του KoutiA
    double ogkos = KoutiA.calculateOgkos();
    cout << "O Ogkos tou Kouti A einai : " << ogkos << " Kuvikes monades." << endl;

    // Υπολογισμός του όγκου του KoutiB
    ogkos = KoutiB.calculateOgkos();
    cout << "O Ogkos tou KoutiB einai : " << ogkos << " Kuvikes monades." << endl;

    // Δημιουργία και υπολογισμός του όγκου για το KoutiC
    KoutiC.setMikos(3.0);
    KoutiC.setPlatos(4.5);
    KoutiC.setYpsos(7.5);
    ogkos = KoutiC.calculateOgkos();
    cout << "O Ogkos tou Kouti C einai : " << ogkos << " Kuvikes monades." << endl;

    return 0;
}
