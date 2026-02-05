| Attribute           | Data Type     | Description                              |
| ------------------- | ------------- | ---------------------------------------- |
| `accountNumber`     | `std::string` | Unique identifier for the bank account.  |
| `accountHolderName` | `std::string` | Name of the person who owns the account. |
| `balance`           | `double`      | Current balance of the account.          |
| Method Signature                                         | Return Type   | Description                                                                   |
| -------------------------------------------------------- | ------------- | ----------------------------------------------------------------------------- |
| `BankAccount()`                                          | (Constructor) | Default constructor, sets default values.                                     |
| `BankAccount(accountNumber, accountHolderName, balance)` | (Constructor) | Parameterized constructor to initialize an account.                           |
| `getAccountNumber() const`                               | `std::string` | Returns the account number.                                                   |
| `getAccountHolderName() const`                           | `std::string` | Returns the account holder's name.                                            |
| `setAccountHolderName(const std::string& newName)`       | `void`        | Updates the account holder's name.                                            |
| `getBalance() const`                                     | `double`      | Returns the current account balance.                                          |
| `deposit(double amount)`                                 | `void`        | Adds funds to the account, validates positive amounts.                        |
| `withdraw(double amount)`                                | `void`        | Withdraws funds, validates positive amount and checks for sufficient balance. |
