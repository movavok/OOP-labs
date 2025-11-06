#include "product.h"
#include "inventory.h"

int main()
{
    double price = 0;
    string name;
    Inventory<Product> store = {
        Product("Apple", 17.5, 120),
        Product("Laptop", 25000.0, 5),
        Product("Book", 299.0, 45),
        Product("Backpack", 899.0, 20)
    };

    cout << "* All items *" << endl;
    store.showAllItems();

    cout << "\nEnter price to find an item>> ";
    cin >> price;
    store.findByPrice(price);

    cout << "\nEnter name to remove an item>> ";
    cin >> name;
    store.removeByName(QString::fromStdString(name));

    cout << "\n* Updated items *" << endl;
    store.showAllItems();

    return 0;
}
