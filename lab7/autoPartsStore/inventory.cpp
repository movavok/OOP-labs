#include "inventory.h"

Inventory::Inventory() {}

Inventory::Inventory(const initializer_list<Part>& list) {
    for (const auto& part : list) parts.push_back(part);
}

void Inventory::addPart(const Part& part) { parts.push_back(part); }

void Inventory::showAllParts() const{
    if (parts.empty()) {
        cout << "Inventory is empty(" << endl;
        return;
    }

    cout << "* All parts *" << endl;
    for (const auto& part : parts)
        cout << "Name: " << part.name
             << ", manufacturer: " << part.manufacturer
             << ", price: " << part.price
             << ", amount: " << part.amount << endl;
    cout << endl;
}

void Inventory::removeByName(const string& name) {
    for (auto iterator = parts.begin(); iterator != parts.end(); ) {
        if (iterator->name == name) iterator = parts.erase(iterator);
        else ++iterator;
    }
}

void Inventory::updateByName(const string& name, double newPrice, unsigned short newAmount) {
    bool found = false;

    for (auto& part : parts)
        if (part.name == name) {
            part.price = newPrice;
            part.amount = newAmount;
            found = true;
            break;
        }

    if (!found) cout << "Part \"" << name << "\" not found!" << endl;
}

bool compareByName(const Part& left, const Part& right) { return left.name < right.name; }

bool compareByPrice(const Part& left, const Part& right) { return left.price < right.price; }

void Inventory::sortBy(const string& input) {
    if (input == "name") sort(parts.begin(), parts.end(), compareByName);
    else if (input == "price") sort(parts.begin(), parts.end(), compareByPrice);
    else cout << "Should enter name/price" << endl;
}
