#include "manager.h"

Manager::Manager() {}

QString Manager::getName(){ return name; }

istream& operator>>(istream& in, Manager& manager) {
    string input;
    cout << "Enter manager name: ";
    getline(in, input);
    manager.name = QString::fromStdString(input);
    return in;
}

ostream& operator<<(ostream& out, const Manager& manager) {
    out << "Manager: " << manager.name.toStdString();
    return out;
}
