#ifndef BANK_H
#define BANK_H

#include <string>
#include "BankAccount.h"

class Bank
{
public:
    Bank(std::string);

    void setName(std::string &);
    std::string getName() const;

    void addAccount(std::string, std::string, std::string, unsigned int, double);
    void deactivate(std::string);

    void print();

    unsigned int activeAccounts();
    double bankMoney();

    BankAccount &findBySSN(std::string);

    ~Bank();

private:
    std::string name;
    BankAccount *accounts = new BankAccount[1000];

    unsigned int account_count{0};
};

#endif
