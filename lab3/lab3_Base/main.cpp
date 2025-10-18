#include "base.h"
#include "publicderived.h"
#include "protectedderived.h"
#include "privatederived.h"

int main()
{
    PublicDerived pubObj;
    pubObj.changeVars();

    cout << "Public field    = " << pubObj.publicVar << endl;
    //cout << "Protected field = " << pubObj.protectedVar << endl;
    //cout << "Private field   = " << pubObj.privateVar << endl;

    ProtectedDerived protObj;
    protObj.changeVars();

    //cout << "Public field    = " << protObj.publicVar << endl;
    //cout << "Protected field = " << protObj.protectedVar << endl;
    //cout << "Private field   = " << protObj.privateVar << endl;

    PrivateDerived privObj;
    privObj.changeVars();

    //cout << "Public field    = " << privObj.publicVar;
    //cout << "Protected field = " << privObj.protectedVar;
    //cout << "Private field   = " << privObj.privateVar;

    return 0;
}
