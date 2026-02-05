#include <iostream>
#include "BankAccount.h"

// Default constructor
BankAccount::BankAccount() {
    accountNumber = "0000";
    accountHolderName = "Unknown";
    balance = 0.0;
}

// Parameterized constructor
BankAccount::BankAccount(std::string accNum, std::string accHolder, double initialBalance) {
    accountNumber = accNum;
    accountHolderName = accHolder;
    balance = initialBalance >= 0 ? initialBalance : 0.0; // Prevent negative balance
}

// Getter methods
std::string BankAccount::getAccountNumber() const { return accountNumber; }
std::string BankAccount::getAccountHolderName() const { return accountHolderName; }
double BankAccount::getBalance() const { return balance; }

// Setter method
void BankAccount::setAccountHolderName(const std::string& newName) {
    accountHolderName = newName;
}

// Deposit method
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
        std::cout << "Deposit successful. New balance: $" << balance << "\n";
    } else {
        std::cout << "Invalid deposit amount.\n";
    }
}

// Withdraw method
void BankAccount::withdraw(double amount) {
    if (amount <= 0) {
        std::cout << "Invalid withdrawal amount.\n";
    } else if (amount > balance) {
        std::cout << "Insufficient funds. Current balance: $" << balance << "\n";
    } else {
        balance -= amount;
        std::cout << "Withdrawal successful. New balance: $" << balance << "\n";
    }
}
