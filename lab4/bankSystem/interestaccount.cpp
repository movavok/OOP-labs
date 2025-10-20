#include "interestaccount.h"

InterestAccount::InterestAccount(const QString& accNumber, const QString& ownerName, double balance, double rate)
    : BankAccount(accNumber, ownerName, balance), interestRate(rate) {}

double InterestAccount::getInterestRate() const { return interestRate; }

QString InterestAccount::getType() const { return "Рахунок з відсотками"; }
