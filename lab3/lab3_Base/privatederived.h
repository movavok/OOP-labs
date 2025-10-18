#ifndef PRIVATEDERIVED_H
#define PRIVATEDERIVED_H

#include "base.h"

class PrivateDerived : private Base
{
public:
    PrivateDerived();
    void changeVars();
};

#endif // PRIVATEDERIVED_H
