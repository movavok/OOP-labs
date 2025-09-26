#ifndef MUSICALBAND_H
#define MUSICALBAND_H

#include "musician.h"
#include "bandleader.h"
#include <iostream>
#include <QList>

using namespace std;

class MusicalBand
{
public:
    MusicalBand();
    MusicalBand(const QString& n,
                const QString& s,
                const BandLeader& l)
        : name(n), style(s), leader(l) {}

    void addMusician(Musician*);
    void delMusician(Musician*);

    QString getName();
    QString getStyle();
    QList<Musician*> getList();
    int getLen();

private:
    QString name;
    QString style;
    QList<Musician*> musicians;
    BandLeader leader;
};

#endif // MUSICALBAND_H
