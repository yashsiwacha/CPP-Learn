// Program demonstrating access specifiers in C++
#include <iostream>
using namespace std;

class BankAccount
{
    int accountNumber; // Private
    double balance;    // Private

public:
    void deposit(double amount)
    {
        if (amount > 0)
            balance += amount;
        else
            cout << "Amount must be positive\n";
    }

    void withdraw(double amount)
    {
        if (balance >= amount)
            balance -= amount;
        else
            cout << "Insufficient balance\n";
    }

    double getBalance() { return balance; }

protected:
    string ownerName; // Protected - accessible in derived classes
};

class VIPAccount : public BankAccount
{
public:
    void setOwnerName(string name)
    {
        ownerName = name; // Can access protected member
    }

    void printOwnerName()
    {
        cout << "Owner: " << ownerName << "\n";
    }

    void testAccess()
    {
        // Can access protected members
        ownerName = "Test";

        // Cannot access private members (will cause compilation error if uncommented)
        // accountNumber = 12345;
        // balance = 1000.0;

        // Can use public methods
        deposit(1000.0);
        cout << "Balance: $" << getBalance() << "\n";
    }
};

int main()
{
    BankAccount basicAccount;
    VIPAccount vipAccount;

    // Cannot access private/protected members directly (compilation errors if uncommented)
    // basicAccount.accountNumber = 12345;
    // basicAccount.balance = 5000.0;
    // basicAccount.ownerName = "John";

    // Use public methods to interact with account
    basicAccount.deposit(5000.0);
    basicAccount.withdraw(1000.0);
    cout << "Basic account balance: $" << basicAccount.getBalance() << "\n\n";

    // VIP account with protected member access through public method
    vipAccount.setOwnerName("Jane Smith");
    vipAccount.deposit(10000.0);
    vipAccount.printOwnerName();
    cout << "VIP account balance: $" << vipAccount.getBalance() << "\n\n";

    // Test access within derived class
    vipAccount.testAccess();

    return 0;
}
