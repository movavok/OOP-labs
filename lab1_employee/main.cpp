#include "employee.h"

int main()
{
    cout << "-Creating object with default constructor-\n";

    Employee emp1;

    cout << "Employee's name - \"" << emp1.getName()
         << "\"\nEmployee's id - " << emp1.getId()
         << "\nEmployee's salary - " << emp1.getSalary() << "\n\n";

    cout << "-Creating object and setting arguments-\n";

    Employee emp2;

    string name;
    int id;
    double salary;

    cout << "Enter employee's name: ";
    cin >> name;
    cout << "                   id: ";
    cin >> id;
    cout << "               salary: ";
    cin >> salary;
    cout << endl;

    emp2.setName(name);
    emp2.setId(id);
    emp2.setSalary(salary);

    cout << "Employee's name - \"" << emp2.getName()
         << "\"\nEmployee's id - " << emp2.getId()
         << "\nEmployee's salary - " << emp2.getSalary() << "\n\n";

    cout << "-Creating object and setting arguments by second constructor-\n";

    cout << "Enter employee's name: ";
    cin >> name;
    cout << "                   id: ";
    cin >> id;
    cout << "               salary: ";
    cin >> salary;
    cout << endl;

    Employee emp3(name, id, salary);
    cout << "Employee's name - \"" << emp3.getName()
         << "\"\nEmployee's id - " << emp3.getId()
         << "\nEmployee's salary - " << emp3.getSalary() << "\n\n";

    cout << "-Creating structure object-\n";

    cout << "Enter employee's name: ";
    cin >> name;
    cout << "                   id: ";
    cin >> id;
    cout << "               salary: ";
    cin >> salary;
    cout << endl;

    S_Employee emp = {name, id, salary};
    cout << "Employee's name - \"" << emp.name
         << "\"\nEmployee's id - " << emp.id
         << "\nEmployee's salary - " << emp.salary << "\n\n";

    return 0;
}
