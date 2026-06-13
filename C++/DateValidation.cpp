#include <iostream>
#include <string>
using namespace std;


class Month;
class Day;


class Date {
protected:
    int year;
    Month* month;
    Day* day;

public:
    Date(int y, int m, int d);
    ~Date();

    void setYear(int y) { year = y; }
    int getYear() { return year; }

    void displayDateDetails();

    static bool isValidDate(int y, int m, int d);
};


class Month {
private:
    int value;

public:
    Month(int m = 1) : value(m) {}

    void setMonth(int m) { value = m; }
    int getMonth() { return value; }

    bool isValidMonth() { return value >= 1 && value <= 12; }
};


class Day {
private:
    int value;

public:
    Day(int d = 1) : value(d) {}

    void setDay(int d) { value = d; }
    int getDay() { return value; }

    bool isValidDay(int m, int y);
};


Date::Date(int y, int m, int d) {
    year = y;
    month = new Month(m);
    day = new Day(d);
}

Date::~Date() {
    delete month;
    delete day;
}


bool Day::isValidDay(int m, int y) {
    if (value < 1) return false;
    int maxDays;
    switch (m) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            maxDays = 31; break;
        case 4: case 6: case 9: case 11:
            maxDays = 30; break;
        case 2:
            
            if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
                maxDays = 29;
            else
                maxDays = 28;
            break;
        default:
            return false;
    }
    return value <= maxDays;
}


bool Date::isValidDate(int y, int m, int d) {
    Month tempMonth(m);
    Day tempDay(d);
    return tempMonth.isValidMonth() && tempDay.isValidDay(m, y);
}


void Date::displayDateDetails() {
    cout << "Current Date: " 
         << day->getDay() << "/" 
         << month->getMonth() << "/" 
         << getYear() << endl;
}


int main() {
    int y, m, d;

    while (true) {
        cout << "Enter year: ";
        cin >> y;

        cout << "Enter month: ";
        cin >> m;

        cout << "Enter day: ";
        cin >> d;

        if (Date::isValidDate(y, m, d)) {
            Date myDate(y, m, d);
            myDate.displayDateDetails();
            break; 
        } else {
            cout << "Incorrect date format. Please try again.\n" << endl;
        }
    }

    return 0;
}
