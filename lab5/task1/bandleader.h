#ifndef BANDLEADER_H
#define BANDLEADER_H

#include <QString>
#include <iostream>

using namespace std;

class BandLeader
{
public:
    BandLeader();
    BandLeader(const QString& n)
        : name(n) {}

    QString getName() const;

    friend istream& operator>>(istream& in, BandLeader& leader);
    friend ostream& operator<<(ostream& out, const BandLeader& leader);

private:
    QString name;
};

#endif // BANDLEADER_H
