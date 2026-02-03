// Program to demonstrate encapsulation with a BankAccount class
#include <iostream>
using namespace std;

#define MAX_WITHDRAW 10000
#define MAX_DEPOSIT 100000

// BankAccount class with private data members for encapsulation
class BankAccount
{
    // Private members - protected from direct external access
    int accountNumber;
    double balance;

public:
    // Constructor: initializes account with number and zero balance
    BankAccount(int accountNumber)
    {
        this->accountNumber = accountNumber;
        this->balance = 0.0; // Initialize balance to prevent undefined behavior
    }

    // Deposit method with validation
    void deposit(double amount)
    {
        // Validate: amount must be positive
        if (amount <= 0)
        {
            cout << "Deposit failed: Amount must be greater than zero." << endl;
            return;
        }

        // Validate: check deposit limit
        if (amount > MAX_DEPOSIT)
        {
            cout << "Deposit failed: Amount exceeds maximum deposit limit of " << MAX_DEPOSIT << endl;
            return;
        }

        // Process valid deposit
        balance += amount;
        cout << "Deposited: Rs." << amount << " | New Balance: Rs." << balance << endl;
    }

    // Withdraw method with validation
    void withdraw(double amount)
    {
        // Validate: amount must be positive
        if (amount <= 0)
        {
            cout << "Withdrawal failed: Amount must be greater than zero." << endl;
            return;
        }

        // Validate: check withdrawal limit
        if (amount > MAX_WITHDRAW)
        {
            cout << "Withdrawal failed: Amount exceeds maximum withdrawal limit of " << MAX_WITHDRAW << endl;
            return;
        }

        // Validate: sufficient balance
        if (balance < amount)
        {
            cout << "Withdrawal failed: Insufficient balance." << endl;
            return;
        }

        // Process valid withdrawal
        balance -= amount;
        cout << "Withdrawn: Rs." << amount << " | New Balance: Rs." << balance << endl;
    }

    // Getter method for balance (read-only access)
    double getBalance()
    {
        return balance;
    }
};

int main()
{
    // Create bank account with account number
    BankAccount b1(1);

    cout << "=== Bank Account Operations ===" << endl;
    cout << "Initial Balance: Rs." << b1.getBalance() << endl
         << endl;

    // Test deposit operations
    cout << "--- Deposit Operations ---" << endl;
    b1.deposit(1212);
    b1.deposit(-500);   // Invalid: negative amount
    b1.deposit(150000); // Invalid: exceeds limit
    cout << endl;

    // Test withdrawal operations
    cout << "--- Withdrawal Operations ---" << endl;
    b1.withdraw(200);
    b1.withdraw(-12); // Invalid: negative amount
    b1.withdraw(5000);
    b1.withdraw(10000); // Invalid: insufficient balance
    cout << endl;

    // Final balance
    cout << "--- Final Account Status ---" << endl;
    cout << "Final Balance: Rs." << b1.getBalance() << endl;

    return 0;
}