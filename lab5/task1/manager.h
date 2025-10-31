#ifndef MANAGER_H
#define MANAGER_H

#include <QString>
#include <iostream>

using namespace std;

class Manager
{
public:
    Manager();
    Manager(const QString& n)
        : name(n) {}

    QString getName();

    friend istream& operator>>(istream& in, Manager& manager);
    friend ostream& operator<<(ostream& out, const Manager& manager);

private:
    QString name;
};

#endif // MANAGER_H
