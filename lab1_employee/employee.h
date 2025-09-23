#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

using namespace std;

class Employee {
private:
    string name = "";
    int id = 0;
    double salary = 0.0;
public:
    Employee() {}
    Employee(const string& name, int id, double salary) : name(name), id(id), salary(salary) {}

    ~Employee() { cout << "employee \"" << name << "\" was deleted\n";}

    void setName(const string& name) { this->name = name; }
    void setId(int id) { this->id = id; }
    void setSalary(double salary) { this->salary = salary; }

    const string& getName() { return name; }
    int getId() { return id; }
    double getSalary() { return salary; }
};

struct S_Employee {
    string name = "";
    int id = 0;
    double salary = 0.0;
};

#endif // EMPLOYEE_H
