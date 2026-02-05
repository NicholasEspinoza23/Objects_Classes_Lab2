// Nicholas Espinoza
// 2/3/2026
//
#include <iostream>
#include <vector>
#include "BankAccount.h" // Include the BankAccount class

// Function to display the main menu
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
        displayMenu();                    // Show menu
        std::cin >> choice;

        switch (choice) {
            case 1: { // Create a new account
                std::string accNum, accHolder;
                double initialBalance;

                std::cout << "Enter account number: ";
                std::cin >> accNum;
                std::cin.ignore(); // Clear input buffer
                std::cout << "Enter account holder name: ";
                std::getline(std::cin, accHolder);
                std::cout << "Enter initial balance: ";
                std::cin >> initialBalance;

                accounts.push_back(BankAccount(accNum, accHolder, initialBalance));
                std::cout << "Account created successfully.\n";
                break;
            }

            case 2: { // Deposit money
                std::string accNum;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        std::cout << "Enter deposit amount: ";
                        std::cin >> amount;
                        acc.deposit(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Account not found.\n";
                break;
            }

            case 3: { // Withdraw money
                std::string accNum;
                double amount;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        std::cout << "Enter withdrawal amount: ";
                        std::cin >> amount;
                        acc.withdraw(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) std::cout << "Account not found.\n";
                break;
            }

            case 4: { // Display account info
                std::string accNum;
                std::cout << "Enter account number: ";
                std::cin >> accNum;

                bool found = false;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
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

            case 5: // Exit
                std::cout << "Exiting program.\n";
                break;

            default: // Invalid input
                std::cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5); // Loop until user chooses to exit

    return 0;
}
