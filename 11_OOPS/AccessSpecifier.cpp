/*
 * Program: Access Specifiers in C++ Object-Oriented Programming
 * 
 * This program demonstrates the three access specifiers in C++:
 * 1. PRIVATE   - Accessible only within the class itself
 * 2. PROTECTED - Accessible within the class AND its derived classes
 * 3. PUBLIC    - Accessible from anywhere in the program
 * 
 * Key Concepts:
 * - Encapsulation: Hiding internal data and exposing only necessary interfaces
 * - Inheritance: Derived classes can access protected members of base class
 * - Data Protection: Private members ensure data integrity and controlled access
 */

#include <iostream>
using namespace std;

// Base Class: BankAccount
// Demonstrates all three access specifiers
class BankAccount{
    // PRIVATE SECTION (default for class)
    // These members are ONLY accessible within BankAccount class methods
    // NOT accessible in derived classes or from outside
    int accountNumber;      // Private: Account identifier
    double balance;         // Private: Account balance (protected from direct manipulation)

    // PUBLIC SECTION
    // These members can be accessed from anywhere:
    // - Inside the class
    // - In derived classes
    // - From outside the class (main function, other classes, etc.)
    public:
    
    // Method to add money to the account
    // Parameters: amount - the amount to deposit
    // This provides controlled access to the private 'balance' variable
    void deposit(double amount){
        // Validate the amount before modifying balance
        if(amount>0) this->balance += amount;  // 'this->' refers to current object
        else cout << "The amount should be more than 0.\n";
    }
    
    // Method to withdraw money from the account
    // Parameters: amount - the amount to withdraw
    // Ensures balance doesn't go negative
    void withdraw(double amount){
        // Check if sufficient balance is available
        if((this->balance-amount)>=0){
            this->balance -= amount;  // Deduct the amount
        }
        else cout << "Balance is not enough to withdraw this amount.\n";
    }
    
    // Getter method to safely retrieve balance
    // Returns: current balance
    // This is the ONLY way to read balance from outside the class
    double getBalance(){
        return this->balance;
    }

    // PROTECTED SECTION
    // These members are accessible:
    // - Inside BankAccount class methods ✓
    // - Inside derived class methods (like VIPAccount) ✓
    // - From outside the class hierarchy ✗
    protected:
        string ownerName;   // Protected: Can be accessed by VIPAccount class

};

// Derived Class: VIPAccount
// Inherits from BankAccount using PUBLIC inheritance
// - Public members of BankAccount remain public in VIPAccount
// - Protected members of BankAccount remain protected in VIPAccount
// - Private members of BankAccount are NOT accessible in VIPAccount
class VIPAccount : public BankAccount{

    public:
        // Method to set the owner name of the VIP account
        // Parameters: name - the name of the account owner
        // ✓ This works because ownerName is PROTECTED in the base class
        void setOwnerName(string name){
          this->ownerName = name;  // Can access protected member from base class
        }
        
        // Method to display the owner's name
        // Demonstrates reading a protected member from base class
        void printOwnerName(){
            cout << "The owner of this Account is: " << this->ownerName << endl;
        }
        
        // Demonstration method showing what can and cannot be accessed
        // within a derived class method
        void testDirectAccess(){
            // ✓ SUCCESS: Can access PROTECTED members in derived class
            ownerName = "Test";
            
            // ✗ ERROR: Cannot access PRIVATE members even in derived class
            // Private members are completely hidden from derived classes
            // accountNumber = 12345;  // Uncommenting this will cause compilation error
            // balance = 1000.0;       // Uncommenting this will cause compilation error
            
            // ✓ SUCCESS: Can use PUBLIC methods to interact with private data
            // This is the proper way to work with private members
            deposit(1000.0);        // Inherited public method
            cout << "Balance: " << getBalance() << endl;  // Inherited public method
        }
};

// Main function - Entry point of the program
// Demonstrates access specifier rules with practical examples
int main(){
    cout << "=== ACCESS SPECIFIER DEMONSTRATION ===" << endl << endl;
    
    // Creating instances of both base and derived classes
    BankAccount basicAccount;   // Instance of base class
    VIPAccount vipAccount;      // Instance of derived class
    
    // ==========================================
    // SECTION 1: Testing access on BankAccount
    // ==========================================
    cout << "1. Attempting to access BankAccount members directly:" << endl;
    
    // ✗ ERROR: Cannot access PRIVATE members from outside the class
    // Private members (accountNumber, balance) are completely hidden from external code
    // basicAccount.accountNumber = 12345;  // Compilation Error: 'accountNumber' is private
    // basicAccount.balance = 5000.0;       // Compilation Error: 'balance' is private
    
    // ✗ ERROR: Cannot access PROTECTED members from outside the class hierarchy
    // Protected members are only accessible within the class and its derived classes
    // basicAccount.ownerName = "John Doe";  // Compilation Error: 'ownerName' is protected
    
    // ✓ CORRECT WAY: Use PUBLIC methods to interact with private/protected data
    // This is encapsulation in action - controlled access through public interface
    basicAccount.deposit(5000.0);       // Add money using public method
    basicAccount.withdraw(1000.0);      // Withdraw money using public method
    cout << "   Balance (via public method): $" << basicAccount.getBalance() << endl;
    
    // ==========================================
    // SECTION 2: Testing access on VIPAccount
    // ==========================================
    cout << "\n2. Attempting to access VIPAccount members directly:" << endl;
    
    // ✗ ERROR: Even on derived class instance, cannot access private/protected from outside
    // The access specifiers still apply when accessing through an object reference
    // vipAccount.accountNumber = 67890;   // Compilation Error: 'accountNumber' is private
    // vipAccount.balance = 10000.0;       // Compilation Error: 'balance' is private
    // vipAccount.ownerName = "Jane Smith"; // Compilation Error: 'ownerName' is protected
    
    // ✓ CORRECT WAY: Use PUBLIC methods (both inherited and new)
    vipAccount.setOwnerName("Jane Smith");  // New public method in VIPAccount
    vipAccount.deposit(10000.0);            // Inherited public method from BankAccount
    vipAccount.printOwnerName();            // New public method in VIPAccount
    cout << "   Balance (via public method): $" << vipAccount.getBalance() << endl;
    
    // ==========================================
    // SECTION 3: Access from within methods
    // ==========================================
    cout << "\n3. Testing access from within derived class methods:" << endl;
    vipAccount.testDirectAccess();  // This method demonstrates internal access rules
    
    // ==========================================
    // SUMMARY: Access Specifier Rules
    // ==========================================
    cout << "\n=== ACCESS SPECIFIER SUMMARY ===" << endl;
    cout << "PRIVATE members:   Accessible only within the class itself" << endl;
    cout << "PROTECTED members: Accessible within the class AND derived classes" << endl;
    cout << "PUBLIC members:    Accessible from anywhere" << endl;
    cout << "\nFrom outside any class: Only PUBLIC members are accessible" << endl;
    
    return 0;  // Program executed successfully
}
