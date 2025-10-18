#include <musicalband.h>

int main()
{
    string input;
    cout << "Enter band name: ";
    getline(cin, input);
    QString bandName = QString::fromStdString(input);

    cout << "Enter band style: ";
    getline(cin, input);
    QString bandStyle = QString::fromStdString(input);

    cout << "Enter band leader name: ";
    getline(cin, input);
    BandLeader leader(QString::fromStdString(input));

    cout << "Enter number of musicians: ";
    int numMusicians;
    cin >> numMusicians;
    cin.ignore();

    MusicalBand band(bandName, bandStyle, leader);

    for (int i = 0; i < numMusicians; ++i) {
        cout << "\n--- Musician " << (i+1) << " ---\n";

        cout << "Enter musician name: ";
        getline(cin, input);
        QString musicianName = QString::fromStdString(input);

        cout << "Enter instrument name: ";
        getline(cin, input);
        QString instrumentName = QString::fromStdString(input);

        cout << "Enter instrument production year: ";
        unsigned short year;
        cin >> year;
        cin.ignore();
        Instrument instrument(instrumentName, year);

        cout << "Enter manager name: ";
        getline(cin, input);
        Manager* manager = new Manager(QString::fromStdString(input));

        Musician* musician = new Musician(musicianName, instrument, manager);
        band.addMusician(musician);
    }

    cout << "\n--- Band Info ---\n";
    cout << "Band: " << band.getName().toStdString()
         << " (" << band.getStyle().toStdString() << ")" << endl;
    cout << "Leader: " << leader.getName().toStdString() << endl;

    for (int i = 0; i < band.getLen(); ++i) {
        Musician* m = band.getList().at(i);
        cout << "Musician " << (i+1) << ": " << m->getName().toStdString() << endl;
    }

    for (Musician* m : band.getList()) {
        band.delMusician(m);
    }

    return 0;
}
