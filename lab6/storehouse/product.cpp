#include "product.h"

Product::Product(const QString& n, double p, unsigned short a)
    : name(n), price(p), amount(a) {}

QString Product::getName() const{ return name; }

double Product::getPrice() const{ return price; }

void Product::printItem() const{
    cout << "Name: " << name.toStdString()
       << ", price: " << price << "uah"
       << ", amount: " << amount << endl;
}
