#ifndef INVENTORY_H
#define INVENTORY_H

#include <vector>
#include <string>
#include <iostream>
#include "Part.h"

using namespace std;

class Inventory
{
    vector<Part> parts;

public:
    Inventory();
    Inventory(const initializer_list<Part>&);

    void addPart(const Part&);
    void showAllParts() const;
    void removeByName(const string&);
    void updateByName(const string&, double, unsigned short);
    void sortBy(const string&);
};

#endif // INVENTORY_H
