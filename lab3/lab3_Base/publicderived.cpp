#include "publicderived.h"

PublicDerived::PublicDerived() {}

void PublicDerived::changeVars()
{
    publicVar    = 1;
    protectedVar = 1;
    //privateVar   = 1;
}
