#include "privatederived.h"

PrivateDerived::PrivateDerived() {}

void PrivateDerived::changeVars()
{
    publicVar    = 1;
    protectedVar = 1;
    //privateVar   = 1;
}
