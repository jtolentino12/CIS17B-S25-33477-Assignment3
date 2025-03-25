#include <iostream>
#include <memory>
#include <stdexcept>

// TODO: Define custom exception classes here
// - NegativeDepositException (for negative deposit attempts)
// - OverdrawException (for withdrawing more than the balance)
// - InvalidAccountOperationException (for transactions on a closed account)

class BankAccount {
private:
    std::string accountNumber;
    double balance;
    bool isActive;

public:
    // Constructor to initialize account number, balance, and active status
    BankAccount(std::string accNum, double initialBalance) : accountNumber(accNum), balance(initialBalance), isActive(true) {}

    // Deposit method
    void deposit(double amount) {
        // TODO: Implement exception handling for negative deposits
        balance += amount;
    }

    // Withdraw method
    void withdraw(double amount) {
        // TODO: Implement exception handling for overdrawing and closed accounts
        balance -= amount;
    }

    // Method to get current balance
    double getBalance() const {
        return balance;
    }

    // Method to close the account
    void closeAccount() {
        // TODO: Prevent further transactions when the account is closed
        isActive = false;
    }
};

int main() {
    try {
        // TODO: Ask the user to enter an initial balance and create a BankAccount object using smart pointers
        // Example: std::cout << "Enter initial balance: ";
        //          std::cin >> initialBalance;
        //          auto account = std::make_unique<BankAccount>("123456", initialBalance);

        auto account = std::make_unique<BankAccount>("123456", 1000.0); // Example initialization

        std::cout << "Bank Account Created: #" << "123456" << std::endl;

        // TODO: Allow the user to enter deposit amounts and call deposit() method
        std::cout << "Depositing $1000..." << std::endl;
        account->deposit(1000);

        // TODO: Allow the user to enter withdrawal amounts and call withdraw() method
        std::cout << "Withdrawing $500..." << std::endl;
        account->withdraw(500);

        std::cout << "Current Balance: $" << account->getBalance() << std::endl;

        // TODO: Test edge cases - try withdrawing more than available balance
        std::cout << "Attempting to withdraw $600..." << std::endl;
        account->withdraw(600); // This should trigger an exception once implemented

    } 
    catch (const std::exception& e) {
        // TODO: Catch and handle exceptions properly
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}