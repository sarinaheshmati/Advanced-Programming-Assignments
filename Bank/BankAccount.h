#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string>

class BankAccount
{
public:
    BankAccount() { }

    BankAccount(std::string, std::string, std::string, unsigned int, double);
    ~BankAccount();

    std::string getName() const;
    void setName(std::string&);

    std::string getLastName() const;
    void setLastName(std::string&);

    std::string getSSN() const;
    void setSSN(std::string&);

    unsigned int getAge() const;
    void setAge(unsigned int &n);

    bool isActive() const;

    BankAccount &deposit(double);
    BankAccount &withdraw(double);

    double getBalance() const;

    void print() const;

    void activate();
    void deactivate();

private:
    std::string name;
    std::string last_name;
    std::string ssn;
    unsigned int age;
    double balance;
    bool is_active{false};
};

#endif
