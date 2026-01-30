//Developing a program to make functions of banking operations like deposit, withdraw and check balance.
#include <iostream>
#include <string>
using namespace std;

//Global static variable to maintain account balance across function calls
static float balance = 0;

//Adds specified amount to account balance
void deposit(float amount){
    // Explicit check for negative deposit
    if(amount < 0) {
        cout << "Deposit amount cannot be negative." << endl;
    }
    // Check for zero deposit
    else if(amount == 0) {
        cout << "Deposit amount should be positive." << endl;
    }
    else {
        balance += amount;
        cout << "Amount successfully deposited." << endl;
    }
}

//Deducts specified amount from account balance
void withdraw(float withdrawalAmount){
    // Explicit zero withdrawal check
    if(withdrawalAmount == 0) {
        cout << "Withdrawal amount cannot be zero." << endl;
    }
    // Negative amount validation
    else if(withdrawalAmount < 0) {
        cout << "Withdrawal amount should be positive." << endl;
    }
    // Check for zero balance
    else if(balance == 0) {
        cout << "Balance is zero. Cannot process withdrawal." << endl;
    }
    // Verify sufficient funds
    else if(balance - withdrawalAmount < 0) {
        cout << "Insufficient funds. Available balance: " << balance << endl;
    }
    // Process withdrawal
    else {
        balance -= withdrawalAmount;
        cout << "Amount successfully withdrawn. New balance: " << balance << endl;
    }
}

//Returns current account balance
float checkBalance(){
    return balance;
}

//Validates and retrieves numeric input from user
bool getValidatedAmount(float &transactionAmount){
    cin >> transactionAmount;
    
    // Check if cin encountered an error (non-numeric input)
    if(cin.fail()){
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Please enter a numeric value." << endl;
        return false;
    }
    return true;
}

//Handles deposit transaction workflow
void handleDepositTransaction(){
    float depositAmount;
    cout << "Enter the amount to deposit: ";
    
    if(getValidatedAmount(depositAmount)){
        deposit(depositAmount);
    }
}

//Handles withdrawal transaction workflow
void handleWithdrawalTransaction(){
    float requestedAmount;
    cout << "Enter the amount to withdraw: ";
    
    if(getValidatedAmount(requestedAmount)){
        withdraw(requestedAmount);
    }
}

//Displays current account balance
void displayAccountBalance(){
    cout << "Current Balance: " << checkBalance() << endl;
}


//Main menu loop for user interaction
void banking(){
    // Welcome message and available commands
    cout << "========================================" << endl;
    cout << "  Welcome to the Banking System!" << endl;
    cout << "========================================" << endl;
    cout << "Available Commands:" << endl;
    cout << "  - Deposit: Add funds to your account" << endl;
    cout << "  - Withdraw: Remove funds from your account" << endl;
    cout << "  - CheckBalance: View current balance" << endl;
    cout << "  - Exit: Close the banking session" << endl;
    cout << "========================================" << endl;
    
    // Main interaction loop
    while(true){
        string userCommand;
        cout << "\n>> Enter command: ";
        cin >> userCommand;
        
        if(userCommand == "Deposit"){
            handleDepositTransaction();
        }
        else if(userCommand == "Withdraw"){
            handleWithdrawalTransaction();
        }
        else if(userCommand == "CheckBalance"){
            displayAccountBalance();
        }
        else if(userCommand == "Exit"){
            cout << "\nThank you for using the Banking System!" << endl;
            cout << "Final Balance: " << checkBalance() << endl;
            break;
        }
        else {
            cout << "Error: Invalid command. Please try again." << endl;
        }
    }
}

//Main Function
int main(){
    banking();
    return 0;
}