#include "bandleader.h"

BandLeader::BandLeader() {}

QString BandLeader::getName() const{ return name; }

istream& operator>>(istream& in, BandLeader& leader) {
    string input;
    cout << "Enter band leader name: ";
    getline(in, input);
    leader.name = QString::fromStdString(input);
    return in;
}

ostream& operator<<(ostream& out, const BandLeader& leader) {
    out << "Leader: " << leader.name.toStdString();
    return out;
}
