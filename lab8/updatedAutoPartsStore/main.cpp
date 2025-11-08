#include "inventory.h"

int main()
{
    Inventory store = {
        {"Brake Pads", {"Brembo", 1250.0, 40}},
        {"Oil Filter", {"Bosch", 350.0, 100}},
        {"Spark Plug", {"NGK", 270.0, 80}},
        {"Battery", {"Varta", 4200.0, 15}},
        {"Winter Tires", {"Michelin", 6900.0, 25}},
        {"Summer Tires", {"Continental", 6400.0, 30}}
    };

    cout << "Initial:" << endl;
    store.showAllParts();

    store.addPart({"Brake Pads", {"Brembo", 1250.0, 10}});
    store.addPart({"Spark Plug", {"Denso", 270.0, 20}});
    store.handleSupply();

    cout << "Hendled supply:" << endl;
    store.showAllParts();

    string name, manufacturer;
    cout << "Enter part name to remove: ";
    getline(cin, name);
    cout << "Enter manufacturer: ";
    getline(cin, manufacturer);
    store.removePart(name, manufacturer);

    double price = 0.0;
    unsigned short amount = 0;
    cout << "Enter part name to update: ";
    getline(cin, name);
    cout << "Enter manufacturer: ";
    getline(cin, manufacturer);
    cout << "Enter new price: ";
    cin >> price;
    cout << "Enter new amount: ";
    cin >> amount;
    cin.ignore();
    store.updatePart(name, manufacturer, price, amount);

    cout << "\nUpdated: " << endl;
    store.showAllParts();

    cout << "Enter manufacturer to search: ";
    getline(cin, manufacturer);
    store.searchByManufacturer(manufacturer);

    double minPrice, maxPrice;
    cout << "Enter min price: ";
    cin >> minPrice;
    cout << "Enter max price: ";
    cin >> maxPrice;
    store.filterByPrice(minPrice, maxPrice);

    store.showPartsHistory();

    return 0;
}
