#include <iostream>
#include <vector>
#include <string>

// BankAccount class define
class BankAccount {
private:
    std::string accountNumber;      // Stores the account number
    std::string accountHolderName;  // Stores the name of the account holder
    double balance;                 // Stores the current balance

public:
    // The constructor
    BankAccount() {
        accountNumber = "0000";        // Default account number
        accountHolderName = "Unknown"; // Default name
        balance = 0.0;                 // Default balance
    }

    // Parameterized constructor (initialize with custom values)
    BankAccount(std::string accNum, std::string accHolder, double initialBalance) {
        accountNumber = accNum;                          // Setting account number
        accountHolderName = accHolder;                  // Setting account holder name
        balance = initialBalance >= 0 ? initialBalance : 0.0; // Help to prevent negative initial balance
    }

    // methods to access private variables
    std::string getAccountNumber() const { return accountNumber; }
    std::string getAccountHolderName() const { return accountHolderName; }
    double getBalance() const { return balance; }

    // Setter method to change the account holder's name
    void setAccountHolderName(const std::string& newName) {
        accountHolderName = newName;
    }

    // Deposit money into the account
    void deposit(double amount) {
        if (amount > 0) {                    // Only allow positive deposits
            balance += amount;               // Add amount to balance
            std::cout << "Deposit successful. New balance: $" << balance << "\n";
        } else {
            std::cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw money from the account
    void withdraw(double amount) {
        if (amount <= 0) {                   // Reject negative or zero withdrawals
            std::cout << "Invalid withdrawal amount.\n";
        } else if (amount > balance) {       // Reject if not enough funds
            std::cout << "Insufficient funds. Current balance: $" << balance << "\n";
        } else {
            balance -= amount;               // Subtract amount from balance
            std::cout << "Withdrawal successful. New balance: $" << balance << "\n";
        }
    }
};

// Functions to display the main menu
void displayMenu() {
    std::cout << "\n--- Bank Account Management ---\n";
    std::cout << "1. Create Account\n";
    std::cout << "2. Deposit\n";
    std::cout << "3. Withdraw\n";
    std::cout << "4. Display Account Info\n";
    std::cout << "5. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    std::vector<BankAccount> accounts; // Vector to store multiple BankAccount objects
    int choice;

    do {
        displayMenu();                    // Show the menu to the user
        std::cin >> choice;

        switch (choice) {
            case 1: { // Create a new bank account
                std::string accNum, accHolder;
                double initialBalance;

                std::cout << "Enter account number: ";
                std::cin >> accNum;
                std::cin.ignore(); // Clear newline from input buffer
                std::cout << "Enter account holder name: ";
                std::getline(std::cin, accHolder);
                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;

                // Add the new account to the vector
                accounts.push_back(BankAccount(accNum, accHolder, initialBalance));
                std::cout << "Account created successfully.\n";
                break;
            }

            case 2: { // Deposit money into an account
                std::string accNum;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                bool found = false;
                for (auto &acc : accounts) { // Search for the account
                    if (acc.getAccountNumber() == accNum) {
                        std::cout << "Enter deposit amount: ";
                        std::cin >> amount;
                        acc.deposit(amount); // Call deposit method
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Account not found.\n";
                break;
            }

            case 3: { // Withdraw money from an account
                std::string accNum;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                bool found = false;
                for (auto &acc : accounts) { // Search for the account
                    if (acc.getAccountNumber() == accNum) {
                        std::cout << "Enter withdrawal amount: ";
                        std::cin >> amount;
                        acc.withdraw(amount); // Call withdraw method
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Account not found.\n";
                break;
            }

            case 4: { // Display account information
                std::string accNum;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                bool found = false;
                for (auto &acc : accounts) { // Search for the account
                    if (acc.getAccountNumber() == accNum) {
                        // Show account details
                        std::cout << "\nAccount Number: " << acc.getAccountNumber()
                                  << "\nHolder Name: " << acc.getAccountHolderName()
                                  << "\nBalance: $" << acc.getBalance() << "\n";
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Account not found.\n";
                break;
            }

            case 5: // Exit the program
                std::cout << "Exiting program.\n";
                break;

            default: // Handle invalid input
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5); // Keep looping until user chooses to exit

    return 0;
}
