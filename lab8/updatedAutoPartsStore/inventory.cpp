#include "inventory.h"

Inventory::Inventory() {}

Inventory::Inventory(const initializer_list<pair<string, Part>>& list) {
    for (const auto& part : list) {
        parts.emplace(part.first, part.second);
        uniqueNames.insert(part.first);

        history.push({"added", part.first, part.second});
    }
}

void Inventory::addPart(const Supply& part) { supply.push(part); }

void Inventory::handleSupply() {
    while (!supply.empty()) {
        Supply sup = supply.front();
        supply.pop();

        auto iterator = parts.find(sup.name);
        if (iterator != parts.end()) {
            if (iterator->second.manufacturer == sup.part.manufacturer)
                iterator->second.amount += sup.part.amount;
            else duplicates.insert({sup.name, sup.part});
        }
        else parts[sup.name] = sup.part;

        history.push({"added" ,sup.name, sup.part});
        uniqueNames.insert(sup.name);
    }
}

void Inventory::showAllParts() const{
    if (parts.empty() && duplicates.empty()) {
        cout << "Inventory is empty(" << endl;
        return;
    }

    cout << "* All parts *" << endl;
    this->showPartsFrom(parts);
    this->showPartsFrom(duplicates);
    cout << endl;
}

void Inventory::ifFound(bool found, const string& name, const string& manufacturer) {
    if (!found) cout << "Part \"" << name << "\" with manufacturer \"" << manufacturer << "\" not found!" << endl;
}

void Inventory::removePart(const string& name, const string& manufacturer) {
    bool found = false;

    auto partIterator = parts.find(name);
    if (partIterator != parts.end() && partIterator->second.manufacturer == manufacturer) {
        history.push({"removed", name, partIterator->second});
        parts.erase(partIterator);
        found = true;
    }

    auto range = duplicates.equal_range(name);
    for (auto dupIterator = range.first; dupIterator != range.second; ) {
        if (dupIterator->second.manufacturer == manufacturer) {
            history.push({"removed", name, dupIterator->second});
            dupIterator = duplicates.erase(dupIterator);
            found = true;
        }
        else ++dupIterator;
    }

    if (parts.find(name) == parts.end() && duplicates.count(name) == 0)
        uniqueNames.erase(name);

    ifFound(found, name, manufacturer);
}

void Inventory::updatePart(const string& name, const string& manufacturer, double newPrice, unsigned short newAmount) {
    bool found = false;

    auto partIterator = parts.find(name);
    if (partIterator != parts.end() && partIterator->second.manufacturer == manufacturer) {
        partIterator->second.price = newPrice;
        partIterator->second.amount = newAmount;
        history.push({"updated", name, partIterator->second});
        found = true;
    }

    auto range = duplicates.equal_range(name);
    auto dupIterator = range.first;
    while (dupIterator != range.second) {
        if (dupIterator->second.manufacturer == manufacturer) {
            dupIterator->second.price = newPrice;
            dupIterator->second.amount = newAmount;
            history.push({"updated", name, dupIterator->second});
            found = true;
        }
        ++dupIterator;
    }

    ifFound(found, name, manufacturer);
}

void Inventory::searchByManufacturer(const string& manufacturer) const{
    map<string, Part> searchedParts;
    multimap<string, Part> searchedDuplicates;

    for (const auto& part : parts)
        if (part.second.manufacturer == manufacturer)
            searchedParts.insert(part);

    for (const auto& part : duplicates)
        if (part.second.manufacturer == manufacturer)
            searchedDuplicates.insert(part);

    if (searchedParts.empty() && searchedDuplicates.empty()) {
        cout << "No parts found from manufacturer \"" << manufacturer << "\"." << endl;
        return;
    }

    cout << "* Parts from manufacturer \"" << manufacturer << "\" *" << endl;
    showPartsFrom(searchedParts);
    showPartsFrom(searchedDuplicates);
    cout << endl;
}

void Inventory::filterByPrice(double minPrice, double maxPrice) const{
    map<string, Part> filteredParts;
    multimap<string, Part> filteredDuplicates;

    for (const auto& part : parts)
        if (part.second.price >= minPrice && part.second.price <= maxPrice) filteredParts.insert(part);

    for (const auto& part : duplicates)
        if (part.second.price >= minPrice && part.second.price <= maxPrice) filteredDuplicates.insert(part);

    if (filteredParts.empty() && filteredDuplicates.empty()) {
        cout << "No parts found in this price(" << endl;
        return;
    }

    cout << "* Parts with price from " << minPrice << " to " << maxPrice << " *" << endl;
    showPartsFrom(filteredParts);
    showPartsFrom(filteredDuplicates);
    cout << endl;
}

void Inventory::showPartsHistory() const {
    if (history.empty()) {
        cout << "History is empty" << endl;
        return;
    }

    cout << "* Parts History *" << endl;
    stack<History> temp = history;

    while (!temp.empty()) {
        const History& note = temp.top();
        cout << "Action: " << note.action
             << ", name: " << note.name
             << ", manufacturer: " << note.part.manufacturer
             << ", price: " << note.part.price
             << ", amount: " << note.part.amount << endl;
        temp.pop();
    }

    cout << endl;
}
