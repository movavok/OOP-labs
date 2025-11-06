#ifndef INVENTORY_H
#define INVENTORY_H

#include <QList>
#include <iostream>

using namespace std;

template <typename T>
class Inventory
{
    QList<T> items;

public:
    Inventory() = default;

    Inventory(const initializer_list<T>& list) {
        for (const auto& item : list) items.append(item);
    }

    void addItem(const T& item) { items.append(item); }

    void removeByName(const QString& name) {
        for (int index = 0; index < items.size(); ++index)
            if (items[index].getName() == name ) {
                items.removeAt(index);
                return;
            }
        cout << "Item wasn't found(" << endl;
    }

    void showAllItems() const {
        if (items.isEmpty()) {
            cout << "List of items is empty" << endl;
            return;
        }
        for (const auto& item : items) item.printItem();
    }

    void findByPrice(double price) const {
        bool found = false;
        for (const auto& item : items)
            if (item.getPrice() == price) {
                item.printItem();
                found = true;
            }
        if (!found) cout << "Item wasn't found(" << endl;
    }
};

#endif // INVENTORY_H
