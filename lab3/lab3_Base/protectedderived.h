#ifndef PROTECTEDDERIVED_H
#define PROTECTEDDERIVED_H

#include "base.h"

class ProtectedDerived : protected Base
{
public:
    ProtectedDerived();
    void changeVars();
};

#endif // PROTECTEDDERIVED_H
