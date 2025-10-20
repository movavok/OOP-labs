#include "bankaccount.h"

BankAccount::BankAccount()
    : accNumber(""), ownerName(""), balance(0.0) {}

BankAccount::BankAccount(const QString &accNumber, const QString &ownerName, double balance)
    : accNumber(accNumber), ownerName(ownerName), balance(balance) {}

QString BankAccount::getAccNumber() const { return accNumber; }
QString BankAccount::getOwnerName() const { return ownerName; }
double BankAccount::getBalance() const { return balance; }

void BankAccount::setBalance(double newBalance) { balance = newBalance; }

void BankAccount::deposit(double amount) { if (amount > 0) balance += amount; }

bool BankAccount::withdraw(double amount) {
    if (amount > 0 && balance >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}
