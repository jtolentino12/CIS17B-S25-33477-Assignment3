#include <iostream>
#include <memory>
#include <stdexcept>

// TODO: Define custom exception classes here
// - NegativeDepositException (for negative deposit attempts)
class NegativeDepositException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot deposit a negative amount!";
    }
};

// - OverdrawException (for withdrawing more than the balance)
class OverdrawException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Insufficient funds!";
    }
};

// - InvalidAccountOperationException (for transactions on a closed account)
class InvalidAccountOperationException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Account is closed for transactions!";
    }
};

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
        if (!isActive) {
            throw InvalidAccountOperationException();
        }
        if (amount < 0) {
            throw NegativeDepositException();
        }
        balance += amount;
    }

    // Withdraw method
    void withdraw(double amount) {
        // TODO: Implement exception handling for overdrawing and closed accounts
        if (!isActive) {
            throw InvalidAccountOperationException();
        }
        if (amount > balance) {
            throw OverdrawException();
        }
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
        double initialBalance;
        std::cout << "Enter initial balance: ";
        std::cin >> initialBalance;

        auto account = std::make_unique<BankAccount>("123456", initialBalance); // Example initialization

        std::cout << "Bank Account Created: #" << "123456" << std::endl;

        // TODO: Allow the user to enter deposit amounts and call deposit() method
        double depositAmount;
        std::cout <<"Enter the amount to deposit: ";
        std::cin >> depositAmount;
        account->deposit(depositAmount);
        std::cout << "Sucessfully deposited $" << depositAmount << ". New Balance: $" << account->getBalance() << std::endl;

        // TODO: Allow the user to enter withdrawal amounts and call withdraw() method
        double withdrawAmount;
        std::cout << "Enter the amount to withdraw: ";
        std::cin >> withdrawAmount;
        account->withdraw(withdrawAmount);
        std::cout << "Sucessfully withdrawed $" << withdrawAmount << ". New Balance: $" << account->getBalance() << std::endl;

        // TODO: Test edge cases - try withdrawing more than available balance
        std::cout << "Attempting to withdraw $999999..." << std::endl;
        account->withdraw(999999); // This should trigger an exception once implemented

        // more test cases (remove comments to test)

        /*
        std::cout << "Attempting to withdraw $1 from a closed account" << std::endl;
        account->closeAccount();
        account->withdraw(1);
        */

    } 
    catch (const std::exception& e) {
        // TODO: Catch and handle exceptions properly
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}