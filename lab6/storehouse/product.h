#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>
#include <iostream>

using namespace std;

class Product
{
public:
    Product(const QString&, double, unsigned short);

    QString getName() const;
    double getPrice() const;

    void printItem() const;

private:
    QString name;
    double price;
    unsigned short amount;
};

#endif // PRODUCT_H
