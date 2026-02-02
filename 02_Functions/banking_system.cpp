// Program for banking operations like deposit, withdraw and check balance.
#include <iostream>
#include <string>
using namespace std;

// Global static variable - persists across function calls to maintain balance
static float balance = 0;

// Function to add money to the account
void deposit(float amount)
{
    // Validate input - reject negative amounts
    if (amount < 0)
    {
        cout << "Deposit amount cannot be negative." << endl;
    }
    // Reject zero deposits
    else if (amount == 0)
    {
        cout << "Deposit amount should be positive." << endl;
    }
    else
    {
        balance += amount; // Add to balance
        cout << "Amount successfully deposited." << endl;
    }
}

// Function to withdraw money from the account
void withdraw(float withdrawalAmount)
{
    // Check for zero withdrawal
    if (withdrawalAmount == 0)
    {
        cout << "Withdrawal amount cannot be zero." << endl;
    }
    // Validate for negative amount
    else if (withdrawalAmount < 0)
    {
        cout << "Withdrawal amount should be positive." << endl;
    }
    // Check if account has any balance
    else if (balance == 0)
    {
        cout << "Balance is zero. Cannot process withdrawal." << endl;
    }
    // Check for sufficient funds
    else if (balance - withdrawalAmount < 0)
    {
        cout << "Insufficient funds. Available balance: " << balance << endl;
    }
    else
    {
        balance -= withdrawalAmount; // Deduct from balance
        cout << "Amount successfully withdrawn. New balance: " << balance << endl;
    }
}

// Function to return current balance
float checkBalance()
{
    return balance;
}

// Function to validate numeric input from user
bool getValidatedAmount(float &transactionAmount)
{
    cin >> transactionAmount;

    // Check if input failed (non-numeric input)
    if (cin.fail())
    {
        cin.clear();             // Clear error flags
        cin.ignore(10000, '\n'); // Discard invalid input
        cout << "Invalid input. Please enter a numeric value." << endl;
        return false;
    }
    return true;
}

void handleDepositTransaction()
{
    float depositAmount;
    cout << "Enter the amount to deposit: ";

    if (getValidatedAmount(depositAmount))
    {
        deposit(depositAmount);
    }
}

void handleWithdrawalTransaction()
{
    float requestedAmount;
    cout << "Enter the amount to withdraw: ";

    if (getValidatedAmount(requestedAmount))
    {
        withdraw(requestedAmount);
    }
}

void displayAccountBalance()
{
    cout << "Current Balance: " << checkBalance() << endl;
}

void banking()
{
    cout << "========================================" << endl;
    cout << "  Welcome to the Banking System!" << endl;
    cout << "========================================" << endl;
    cout << "Available Commands:" << endl;
    cout << "  - Deposit: Add funds to your account" << endl;
    cout << "  - Withdraw: Remove funds from your account" << endl;
    cout << "  - CheckBalance: View current balance" << endl;
    cout << "  - Exit: Close the banking session" << endl;
    cout << "========================================" << endl;

    while (true)
    {
        string userCommand;
        cout << "\n>> Enter command: ";
        cin >> userCommand;

        if (userCommand == "Deposit")
        {
            handleDepositTransaction();
        }
        else if (userCommand == "Withdraw")
        {
            handleWithdrawalTransaction();
        }
        else if (userCommand == "CheckBalance")
        {
            displayAccountBalance();
        }
        else if (userCommand == "Exit")
        {
            cout << "\nThank you for using the Banking System!" << endl;
            cout << "Final Balance: " << checkBalance() << endl;
            break;
        }
        else
        {
            cout << "Error: Invalid command. Please try again." << endl;
        }
    }
}

int main()
{
    banking();
    return 0;
}