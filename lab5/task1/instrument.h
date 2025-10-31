#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QString>
#include <iostream>

using namespace std;

class Instrument
{
public:
    Instrument();
    Instrument(const QString& n, unsigned short y)
        : name(n), prodYear(y) {}

    QString getName() const;
    unsigned short getprodYear() const;

    friend istream& operator>>(istream& in, Instrument& instrument);
    friend ostream& operator<<(ostream& out, const Instrument& instrument);

private:
    QString name;
    unsigned short prodYear;
};

#endif // INSTRUMENT_H
