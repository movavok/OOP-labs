#ifndef INVENTORY_H
#define INVENTORY_H

#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <iostream>
#include "comparator.h"
#include "History.h"

using namespace std;

class Inventory
{
public:
    Inventory();
    Inventory(const initializer_list<pair<string, Part>>&);

    void addPart(const Supply&);
    void handleSupply();

    template<typename T>
    void showPartsFrom(const T& list) const{
        for (const auto& part : list)
            cout << "Name: " << part.first
                 << ", manufacturer: " << part.second.manufacturer
                 << ", price: " << part.second.price
                 << ", amount: " << part.second.amount << endl;
    }

    void showAllParts() const;

    static void ifFound(bool, const string&, const string&);

    void removePart(const string&, const string&);
    void updatePart(const string&, const string&, double, unsigned short);

    void searchByManufacturer(const string&) const;
    void filterByPrice(double, double) const;

    void showPartsHistory() const;

private:
    map<string, Part> parts;
    multimap<string, Part> duplicates;
    set<string> uniqueNames;
    queue<Supply> supply;

    priority_queue<pair<string, Part>,
                   vector<pair<string, Part>>,
                   CompareAmount> refillQueue;

    stack<History> history;
};

#endif // INVENTORY_H
