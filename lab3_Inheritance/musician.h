#ifndef MUSICIAN_H
#define MUSICIAN_H

#include "instrument.h"
#include "manager.h"

class Musician : public Manager
{
public:
    Musician();
    Musician(const QString& n,
             const Instrument& i,
             const QString& m)
        : name(n), instrument(i), Manager(m) {}

    QString getName();

private:
    QString name;
    Instrument instrument;
    //Manager* manager; //асоціація
};

#endif // MUSICIAN_H
