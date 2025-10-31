#include "musicalband.h"

MusicalBand::MusicalBand() {}

QString MusicalBand::getName() const{ return name; }

QString MusicalBand::getStyle(){ return style; }

void MusicalBand::addMusician(Musician* m) { musicians.append(m); }

void MusicalBand::delMusician(Musician* m) {
    musicians.removeOne(m);
    delete m;
}

QList<Musician*> MusicalBand::getList() { return musicians; }

int MusicalBand::getLen() { return musicians.length(); }

istream& operator>>(istream& in, MusicalBand& band) {
    string input;
    cout << "Enter band name: ";
    getline(in, input);
    band.name = QString::fromStdString(input);

    cout << "Enter band style: ";
    getline(in, input);
    band.style = QString::fromStdString(input);

    in >> band.leader;

    cout << "Enter number of musicians: ";
    int numMusicians;
    in >> numMusicians;
    in.ignore();

    for (int i = 0; i < numMusicians; ++i) {
        cout << "\n--- Musician " << (i + 1) << " ---\n";
        Musician* m = new Musician();
        in >> *m;
        band.addMusician(m);
    }

    return in;
}

ostream& operator<<(ostream& out, const MusicalBand& band) {
    out << "Band: " << band.name.toStdString()
    << " (" << band.style.toStdString() << ")\n"
    << band.leader << "\n";

    int i = 1;
    for (auto* m : band.musicians)
        out << "  Musician " << i++ << ": " << *m << "\n";

    return out;
}
