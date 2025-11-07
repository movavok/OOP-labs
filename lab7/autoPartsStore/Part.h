#ifndef PART_H
#define PART_H

#include <string>

using namespace std;

struct Part {
    string name;
    string manufacturer;
    double price = 0.0;
    unsigned short amount = 0;
};

#endif // PART_H
