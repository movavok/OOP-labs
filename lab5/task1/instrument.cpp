#include "instrument.h"

Instrument::Instrument() {}

QString Instrument::getName() const{ return name; }

unsigned short Instrument::getprodYear() const{ return prodYear; }

istream& operator>>(istream& in, Instrument& instrument) {
    string input;

    cout << "Enter instrument name: ";
    getline(in, input);
    instrument.name = QString::fromStdString(input);

    cout << "Enter production year: ";
    unsigned short year;
    in >> year;
    in.ignore();
    instrument.prodYear = year;

    return in;
}

ostream& operator<<(ostream& out, const Instrument& instrument) {
    out << instrument.name.toStdString() << " (" << instrument.prodYear << ")";
    return out;
}
