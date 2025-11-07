#include "inventory.h"

int main()
{
    string input;
    double price = 0.0;
    unsigned short amount = 0;
    Inventory store = {
        {"Brake Pads", "Brembo", 1250.0, 40},
        {"Oil Filter", "Bosch", 350.0, 100},
        {"Spark Plug", "NGK", 270.0, 80},
        {"Battery", "Varta", 4200.0, 15},
        {"Winter Tires", "Michelin", 6900.0, 25},
        {"Summer Tires", "Continental", 6400.0, 30}
    };

    store.showAllParts();

    cout << "Enter part name to remove: ";
    getline(cin, input);
    store.removeByName(input);

    cout << "Enter part name to update: ";
    getline(cin, input);
    cout << "Enter new part price: ";
    cin >> price;
    cout << "Enter new part amount: ";
    cin >> amount;
    cin.ignore();
    store.updateByName(input, price, amount);

    cout << "Sort by name/price?: ";
    cin >> input;
    store.sortBy(input);

    cout << "\nUpdated: " << endl;
    store.showAllParts();

    return 0;
}
