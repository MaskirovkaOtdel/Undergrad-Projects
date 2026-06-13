#include <iostream>
#include <string>
#include <vector>

class Employee {
private:
    std::string name;
    int employeeID;
    double salary;
    std::string department;
    std::string position;

public:
    
    Employee(std::string n, int id, double sal, std::string dep, std::string pos) {
        name = n;
        employeeID = id;
        salary = sal;
        department = dep;
        position = pos;
    }

    
    std::string getName() const {
        return name;
    }
    void setName(const std::string &n) {
        name = n;
    }

    
    int getEmployeeID() const {
        return employeeID;
    }
    void setEmployeeID(int id) {
        employeeID = id;
    }

    
    double getSalary() const {
        return salary;
    }
    void setSalary(double sal) {
        salary = sal;
    }

    
    std::string getDepartment() const {
        return department;
    }
    void setDepartment(const std::string &dep) {
        department = dep;
    }

    
    std::string getPosition() const {
        return position;
    }
    void setPosition(const std::string &pos) {
        position = pos;
    }

    
    void calculateSalary(double performance) {
        if (performance >= 1.0 && performance <= 1.5) {
            salary *= performance;
        } else {
            std::cout << "Performance multiplier should be between 1.0 and 1.5." << std::endl;
        }
    }

    
    void displayDetails() const {
        std::cout << "Employee Details: \n";
        std::cout << "Name: " << name << std::endl;
        std::cout << "Employee ID: " << employeeID << std::endl;
        std::cout << "Salary: $" << salary << std::endl;
        std::cout << "Department: " << department << std::endl;
        std::cout << "Position: " << position << std::endl;
    }
};

int main() {
    
    std::vector<Employee> employees;

    
    employees.push_back(Employee("John Doe", 12345, 50000.00, "IT", "Software Engineer"));
    employees.push_back(Employee("Jane Smith", 12346, 60000.00, "HR", "HR Manager"));
    employees.push_back(Employee("Alice Brown", 12347, 70000.00, "Finance", "Financial Analyst"));
    employees.push_back(Employee("Bob Johnson", 12348, 75000.00, "Marketing", "Marketing Specialist"));

    
    std::cout << "Before Salary Adjustment:\n";
    for (const auto &emp : employees) {
        emp.displayDetails();
        std::cout << "------------------------------\n";
    }

    
    employees[0].calculateSalary(1.2);  
    employees[1].calculateSalary(1.1);  
    employees[2].calculateSalary(1.5);  
    employees[3].calculateSalary(1.0);  

    
    std::cout << "\nAfter Salary Adjustment:\n";
    for (const auto &emp : employees) {
        emp.displayDetails();
        std::cout << "------------------------------\n";
    }

    return 0;
}
