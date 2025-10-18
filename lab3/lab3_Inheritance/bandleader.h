#ifndef BANDLEADER_H
#define BANDLEADER_H

#include <QString>

class BandLeader
{
public:
    BandLeader();
    BandLeader(const QString& n)
        : name(n) {}

    QString getName();

private:
    QString name;
};

#endif // BANDLEADER_H
