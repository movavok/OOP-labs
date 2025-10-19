#ifndef REGULARACCOUNT_H
#define REGULARACCOUNT_H

#include "bankaccount.h"

class RegularAccount : public BankAccount
{
    double minBalance;

public:
    RegularAccount(const QString& accNumber, const QString& ownerName, double balance, double minBalance);

    double getMinBalance() const;

    bool withdraw(double amount) override;
};

#endif // REGULARACCOUNT_H
