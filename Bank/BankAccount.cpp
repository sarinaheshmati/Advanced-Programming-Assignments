#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include "Bank.h"
#include "BankAccount.h"
using namespace std;

BankAccount::BankAccount(){
    
}

BankAccount::BankAccount(string name, string lastname, string ssn, unsigned int age, double b){
    setName(name);
    setLastName(lastname);
    setSSN(ssn);
    setAge(age);
    balance = b;
}

BankAccount::~BankAccount(){
    this->is_active = false;
}

string BankAccount::getName() const{
    return name;
}
void BankAccount::setName(string& n){
    name = n;
}

string BankAccount::getLastName() const{
    return last_name;
}
void BankAccount::setLastName(string& ln){
    last_name = ln;
}

string BankAccount::getSSN() const{
    return ssn;
}
void BankAccount::setSSN(string& s){
    ssn = s;
}

unsigned int BankAccount::getAge() const{
    return age;
}
void BankAccount::setAge(unsigned int &n){
    if (n > 15)
        age = n;
    else
        cout << "invalid age" << endl;
}

bool BankAccount::isActive() const{
    if (is_active)
        return true;
    else
        return false;
}

BankAccount &BankAccount::deposit(double d){
    balance += d;
    return *this;
}
BankAccount &BankAccount::withdraw(double d){
    balance -= d;
    return *this;
}

double BankAccount::getBalance() const{
    return balance;
}

void BankAccount::print() const{
    string t = "Account is not active";
    if (isActive())
        t = "Account is active";
    cout << "Name: " << name << endl << "Last name: " << last_name << endl << "Age: " << age << endl << "Balance: " << balance << endl << t << endl;
    
}

void BankAccount::activate(){
    if (is_active)
        cout << "Account is already active!" << endl;
    else
        is_active = true;
}
void BankAccount::deactivate(){
    if (is_active && balance == 0)
        is_active = false;
    else
        cout << "Account is already deactive!" << endl;
}
