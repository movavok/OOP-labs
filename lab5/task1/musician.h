#ifndef MUSICIAN_H
#define MUSICIAN_H

#include "instrument.h"
#include "manager.h"

class MusicalBand;

class Musician
{
public:
    Musician();
    Musician(const QString& n,
             const Instrument& i,
             Manager* m)
        : name(n), instrument(i), manager(m) {}

    QString getName() const;
    const Instrument& getInstrument() const;
    Manager* getManager() const;

    friend istream& operator>>(istream& in, Musician& musician);
    friend ostream& operator<<(ostream& out, const Musician& musician);

private:
    QString name;
    Instrument instrument;
    Manager* manager; //асоціація
};

#endif // MUSICIAN_H
