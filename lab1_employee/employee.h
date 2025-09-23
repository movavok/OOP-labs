#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>

using namespace std;

// class Employee {
// private:
//     string name = "";
//     int id = 0;
//     double salary = 0.0;
// public:
//     Employee() {}
//     Employee(const string& name, int id, double salary) : name(name), id(id), salary(salary) {}

//     ~Employee() { cout << "employee \"" << name << "\" was deleted\n";}

//     void setName(const string& name) { this->name = name; }
//     void setId(int id) { this->id = id; }
//     void setSalary(double salary) { this->salary = salary; }

//     const string& getName() { return name; }
//     int getId() { return id; }
//     double getSalary() { return salary; }
// };

struct Employee {
    string name = "";
    int id = 0;
    double salary = 0.0;
};

void setName(Employee &emp, const string& name) { emp.name = name; }
void setId(Employee &emp, int id) { emp.id = id; }
void setSalary(Employee &emp, double salary) { emp.salary = salary; }

const string& getName(const Employee &emp) { return emp.name; }
int getId(const Employee &emp) { return emp.id; }
double getSalary(const Employee &emp) { return emp.salary; }

#endif // EMPLOYEE_H
