#ifndef MANAGER_H
#define MANAGER_H

#include <QString>

class Manager
{
public:
    Manager();
    Manager(const QString& n)
        : name(n) {}

    QString getName();

private:
    QString name;
};

#endif // MANAGER_H
