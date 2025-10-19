#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QString>

class BankAccount
{
public:
    BankAccount();
    BankAccount(const QString &accNumber, const QString &ownerName, double balance);

    QString getAccNumber() const;
    QString getOwnerName() const;
    double getBalance() const;

    void deposit(double amount);
    virtual bool withdraw(double amount);

private:
    QString accNumber;
    QString ownerName;
    double balance;
};

#endif // BANKACCOUNT_H
