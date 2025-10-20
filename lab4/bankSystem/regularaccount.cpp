#include "regularaccount.h"

RegularAccount::RegularAccount(const QString& accNumber, const QString& ownerName, double balance, double minBalance)
    : BankAccount(accNumber, ownerName, balance), minBalance(minBalance) {}

double RegularAccount::getMinBalance() const { return minBalance; }

bool RegularAccount::withdraw(double amount) {
    if (getBalance() - amount < minBalance) return false;

    setBalance(getBalance() - amount);
    return true;
}

QString RegularAccount::getType() const { return "Звичайний рахунок"; }
