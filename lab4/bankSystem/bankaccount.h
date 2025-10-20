#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <QString>

class BankAccount
{
public:
    BankAccount();
    BankAccount(const QString&, const QString&, double);

    virtual ~BankAccount() = default;

    QString getAccNumber() const;
    QString getOwnerName() const;
    double getBalance() const;

    void setBalance(double);

    void deposit(double);
    virtual bool withdraw(double);

    virtual QString getType() const = 0;

private:
    QString accNumber;
    QString ownerName;
    double balance;
};

#endif // BANKACCOUNT_H
