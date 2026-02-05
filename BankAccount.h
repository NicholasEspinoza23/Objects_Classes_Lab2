#ifndef BANKACCOUNT_H   // Include guard to prevent multiple inclusions
#define BANKACCOUNT_H

#include <string>      // For std::string

// BankAccount class definition
class BankAccount {
private:
    std::string accountNumber;      // Unique account number
    std::string accountHolderName;  // Name of the account holder
    double balance;                 // Current balance

public:
    // Constructors
    BankAccount();  // Default constructor
    BankAccount(std::string accNum, std::string accHolder, double initialBalance); // Parameterized constructor

    // Getter methods
    std::string getAccountNumber() const;
    std::string getAccountHolderName() const;
    double getBalance() const;

    // Setter method
    void setAccountHolderName(const std::string& newName);

    // Member functions for banking operations
    void deposit(double amount);
    void withdraw(double amount);
};

#endif
