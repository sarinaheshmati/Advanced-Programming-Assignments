# Bank Management System

## Overview

This C++ project implements a simple Bank Management System, allowing for the management of bank accounts, including creating accounts, performing transactions, and tracking overall bank funds.

## Classes

### `Bank`
Manages multiple bank accounts.

- **Private Members**:
  - `name`: Bank name.
  - `BankAccount *accounts`: Array of up to 1000 accounts.
  - `account_count`: Number of active accounts.

- **Public Methods**:
  - `Bank(std::string)`: Initializes the bank with a name.
  - `void addAccount(std::string, std::string, std::string, unsigned int, double)`: Adds a new account.
  - `void deactivate(std::string)`: Deactivates an account by SSN.
  - `unsigned int activeAccounts()`: Returns the count of active accounts.
  - `double bankMoney()`: Calculates the total balance of all accounts.
  - `BankAccount &findBySSN(std::string)`: Finds an account by SSN.
  - `void print()`: Displays details of all accounts.
  - `~Bank()`: Cleans up resources.

### `BankAccount`
Represents a customer's bank account.

- **Private Members**:
  - `name`, `last_name`, `ssn`, `age`: Account holder details.
  - `balance`: Current balance.
  - `is_active`: Account status.

- **Public Methods**:
  - `BankAccount(std::string, std::string, std::string, unsigned int, double)`: Initializes an account.
  - `void deposit(double)`: Adds funds to the account.
  - `void withdraw(double)`: Removes funds from the account.
  - `double getBalance() const`: Returns the current balance.
  - `void activate()`: Activates the account.
  - `void deactivate()`: Deactivates the account.
  - `void print() const`: Displays account details.
  - `~BankAccount()`: Destructor.

## Usage

The system allows for creating and managing bank accounts, depositing and withdrawing funds, and tracking the bank's total funds and active accounts.

---

This `README.md` provides a streamlined overview of the Bank Management System's key features and usage.
