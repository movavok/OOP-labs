#include "musicalband.h"

MusicalBand::MusicalBand() {}

QString MusicalBand::getName(){ return name; }

QString MusicalBand::getStyle(){ return style; }

void MusicalBand::addMusician(Musician* m) { musicians.append(m); }

void MusicalBand::delMusician(Musician* m) {
    musicians.removeOne(m);
    delete m;
}

QList<Musician*> MusicalBand::getList() { return musicians; }

int MusicalBand::getLen() { return musicians.length(); }
