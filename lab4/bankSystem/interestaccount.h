#ifndef INTERESTACCOUNT_H
#define INTERESTACCOUNT_H

#include "bankaccount.h"

class InterestAccount : public BankAccount
{
    double interestRate;

public:
    InterestAccount(const QString& accNumber, const QString& ownerName, double balance, double rate);

    double getInterestRate() const;
    void applyInterest();
};

#endif // INTERESTACCOUNT_H
