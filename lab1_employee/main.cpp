#include "employee.h"

int main()
{
    Employee emp1;
    cout << "Employee's name - \"" << getName(emp1)
         << "\"\nEmployee's id - " << getId(emp1)
         << "\nEmployee's salary - " << getSalary(emp1) << "\n\n";

    Employee emp2;
    setName(emp2, "Yarik");
    setId(emp2, 3);
    setSalary(emp2, 19999.9);
    cout << "Employee's name - \"" << getName(emp2)
         << "\"\nEmployee's id - " << getId(emp2)
         << "\nEmployee's salary - " << getSalary(emp2) << "\n\n";

    Employee emp3 = {"Vova", 4, 60000};
    cout << "Employee's name - \"" << getName(emp3)
         << "\"\nEmployee's id - " << getId(emp3)
         << "\nEmployee's salary - " << getSalary(emp3) << "\n\n";

    return 0;
}
