#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Bank.h"
#include "BankAccount.h"
using namespace std;

Bank::Bank(string n){
    setName(n);
}

void Bank::setName(string &n){
    name = n;
}
string Bank::getName() const{
    return name;
}

void Bank::addAccount(string n, string l, string s, unsigned int a, double b){
    accounts[account_count] = BankAccount(n, l, s, a, b);
    account_count++;
}
void Bank::deactivate(string s){
    for (int i = 0; i < account_count; i++)
    {
      if (Bank::accounts[i].getSSN() == s && accounts[i].isActive() == true)
      {
        accounts[i].deactivate();
      }
    }
}

void Bank::print(){
    cout << "Bank’s Name: " << name << endl << "Active Accounts: " << activeAccounts() << endl << "Bank’s Money: " << bankMoney();
}

unsigned int Bank::activeAccounts()
{
    unsigned int active = 0;
    for(int i = 0; i < account_count; i++)
    {
        if(accounts[i].isActive())
            active++;
    }
    return active;
}

double Bank::bankMoney()
{
    double b = 0;
    for (int i = 0; i < account_count; i++)
    {
      b += accounts[i].getBalance();
    }
    return b;
}

BankAccount &Bank::findBySSN(string ssn)
{
    for(int i = 0; i < account_count; i++)
    {
        if(accounts[i].getSSN() == ssn)
            return accounts[i];
    }
    throw invalid_argument ("invalid SSN.");
}

Bank::~Bank(){
    delete [] accounts;
    account_count = 0;
    name = "";
}
