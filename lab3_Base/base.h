#ifndef BASE_H
#define BASE_H

#include <iostream>

using namespace std;

class Base
{
public:
    Base();
    int publicVar;

protected:
    int protectedVar;

private:
    int privateVar;
};

#endif // BASE_H
