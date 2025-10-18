#ifndef MUSICIAN_H
#define MUSICIAN_H

#include "instrument.h"
#include "manager.h"

class Musician
{
public:
    Musician();
    Musician(const QString& n,
             const Instrument& i,
             Manager* m)
        : name(n), instrument(i), manager(m) {}

    QString getName();

private:
    QString name;
    Instrument instrument;
    Manager* manager; //асоціація
};

#endif // MUSICIAN_H
