#include <iostream>

#include "Bank.h"
#include "BankAccount.h"

using namespace std;

int main()
{
    Bank bank("AUT Bank");

    bank.addAccount("James", "Hetfield", "123456789", 58, 1000);
    bank.addAccount("Roger", "Waters", "112233445", 78, 800);
    bank.addAccount("David", "Gilmour", "987654321", 76, 1500);

    bank.print();

    cout << "##########################################" << endl;

    bank.findBySSN("987654321").print();
    bank.findBySSN("987654321").withdraw(500).deposit(300).print();

    cout << "##########################################" << endl;

    bank.findBySSN("112233445").withdraw(800).print();

    cout << "##########################################" << endl;

    bank.findBySSN("112233445").deactivate();

    bank.print();

    cout << "##########################################" << endl;

    bank.findBySSN("123456789").deactivate();

    bank.print();

    cout << "##########################################" << endl;

    bank.addAccount("Ozzy", "Osbourne", "123789456", 73, 1250);

    bank.findBySSN("123789456").print();
    bank.findBySSN("123789456").deposit(2500).print();

    bank.print();

    cout << "##########################################" << endl;

    bank.findBySSN("112233445").activate();
    bank.findBySSN("112233445").deposit(2000).print();
    bank.print();

    cout << "##########################################" << endl;

        bank.findBySSN("123456789").activate();
        bank.deactivate("123456789");

    return 0;
}
