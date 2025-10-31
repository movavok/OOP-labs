#include "musician.h"

Musician::Musician() {}

QString Musician::getName() const { return name; }

const Instrument& Musician::getInstrument() const { return instrument; }

Manager* Musician::getManager() const { return manager; }

istream& operator>>(istream& in, Musician& musician) {
    string input;

    cout << "Enter musician name: ";
    getline(in, input);
    musician.name = QString::fromStdString(input);

    in >> musician.instrument;

    musician.manager = new Manager();
    in >> *musician.manager;

    return in;
}

ostream& operator<<(ostream& out, const Musician& musician) {
    out << "Musician: " << musician.getName().toStdString()
    << " | ";
    out << musician.getInstrument();
    out << " | ";
    out << (musician.getManager() ? *musician.getManager() : Manager("None"));
    return out;
}
