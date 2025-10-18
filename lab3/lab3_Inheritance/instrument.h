#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <QString>

class Instrument
{
public:
    Instrument();
    Instrument(const QString& n, unsigned short y)
        : name(n), prodYear(y) {}

    QString getName();
    unsigned short getprodYear();

private:
    QString name;
    unsigned short prodYear;
};

#endif // INSTRUMENT_H
