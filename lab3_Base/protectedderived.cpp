#include "protectedderived.h"

ProtectedDerived::ProtectedDerived() {}

void ProtectedDerived::changeVars()
{
    publicVar    = 1;
    protectedVar = 1;
    //privateVar   = 1;
}
