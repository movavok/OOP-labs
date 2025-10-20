#ifndef REGULARACCOUNT_H
#define REGULARACCOUNT_H

#include "bankaccount.h"

class RegularAccount : public BankAccount
{
    double minBalance;

public:
    RegularAccount(const QString&, const QString&, double, double);

    double getMinBalance() const;

    bool withdraw(double) override;

    QString getType() const override;
};

#endif // REGULARACCOUNT_H
