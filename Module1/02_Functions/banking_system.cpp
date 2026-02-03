// Banking system with deposit, withdraw and balance operations
#include <iostream>
#include <string>
using namespace std;

static float balance = 0;

void deposit(float amount)
{
    if (amount <= 0)
        cout << "Amount must be positive\n";
    else
    {
        balance += amount;
        cout << "Deposited successfully\n";
    }
}

void withdraw(float amount)
{
    if (amount <= 0)
        cout << "Amount must be positive\n";
    else if (balance < amount)
        cout << "Insufficient funds. Balance: " << balance << "\n";
    else
    {
        balance -= amount;
        cout << "Withdrawn successfully. Balance: " << balance << "\n";
    }
}

float checkBalance()
{
    return balance;
}

int main()
{
    string command;

    cout << "Banking System\nCommands: Deposit, Withdraw, CheckBalance, Exit\n";

    while (true)
    {
        cout << "\nCommand: ";
        cin >> command;

        if (command == "Deposit")
        {
            float amount;
            cout << "Amount: ";
            cin >> amount;
            deposit(amount);
        }
        else if (command == "Withdraw")
        {
            float amount;
            cout << "Amount: ";
            cin >> amount;
            withdraw(amount);
        }
        else if (command == "CheckBalance")
            cout << "Balance: " << checkBalance() << "\n";
        else if (command == "Exit")
        {
            cout << "Final Balance: " << checkBalance() << "\n";
            break;
        }
        else
            cout << "Invalid command\n";
    }

    return 0;
}