#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class BankAccount
{
private:
    string owner;
    int accountNumber;
    double balance;

public:
    BankAccount(const string &owner, int accountNumber, double initialBalance)
        : owner(owner), accountNumber(accountNumber), balance(initialBalance) {}

    void deposit(double amount)
    {
        if (amount < 0)
        {
            throw invalid_argument("Deposit amount cannot be negative.");
        }

        const double newBalance = balance + amount;
        balance = newBalance;
    }

    void withdraw(double amount)
    {
        if (amount < 0)
        {
            throw invalid_argument("Withdraw amount cannot be negative.");
        }

        if (amount > balance)
        {
            throw runtime_error("Insufficient funds for withdrawal.");
        }

        balance -= amount;
    }

    bool transferTo(BankAccount &targetAccount, double amount) noexcept
    {
        if (amount < 0)
        {
            return false;
        }

        if (amount > balance)
        {
            return false;
        }

        balance -= amount;
        targetAccount.balance += amount;
        return true;
    }

    double getBalance() const
    {
        return balance;
    }

    void print() const
    {
        cout << "Owner: " << owner
             << ", Account#: " << accountNumber
             << ", Balance: Rs. " << fixed << setprecision(2) << balance << '\n';
    }
};

int main()
{
    BankAccount alice("Alice", 1001, 500.0);
    BankAccount bob("Bob", 1002, 300.0);

    cout << "Initial account state:\n";
    alice.print();
    bob.print();

    cout << "\nTesting deposit:\n";
    try
    {
        alice.deposit(200.0);
        cout << "After valid deposit:\n";
        alice.print();

        alice.deposit(-50.0);
    }
    catch (const exception &error)
    {
        cout << "Deposit error: " << error.what() << '\n';
    }

    cout << "Alice after failed deposit attempt:\n";
    alice.print();

    cout << "\nTesting withdraw:\n";
    try
    {
        bob.withdraw(100.0);
        cout << "After valid withdraw:\n";
        bob.print();

        bob.withdraw(1000.0);
    }
    catch (const exception &error)
    {
        cout << "Withdraw error: " << error.what() << '\n';
    }

    cout << "Bob after failed withdraw attempt:\n";
    bob.print();

    cout << "\nTesting transferTo:\n";
    bool transferSuccess = alice.transferTo(bob, 250.0);
    cout << "Valid transfer success: " << boolalpha << transferSuccess << '\n';
    alice.print();
    bob.print();

    transferSuccess = alice.transferTo(bob, 10000.0);
    cout << "Invalid transfer (insufficient funds) success: " << boolalpha << transferSuccess << '\n';
    alice.print();
    bob.print();

    transferSuccess = alice.transferTo(bob, -10.0);
    cout << "Invalid transfer (negative amount) success: " << boolalpha << transferSuccess << '\n';
    alice.print();
    bob.print();

    return 0;
}
