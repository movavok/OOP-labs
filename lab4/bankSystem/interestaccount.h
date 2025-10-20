#ifndef INTERESTACCOUNT_H
#define INTERESTACCOUNT_H

#include "bankaccount.h"

class InterestAccount : public BankAccount
{
    double interestRate;

public:
    InterestAccount(const QString&, const QString&, double, double);

    double getInterestRate() const;

    QString getType() const override;
};

#endif // INTERESTACCOUNT_H
