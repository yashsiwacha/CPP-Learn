// Program to demonstrate the use of mutable keyword in C++
// 
// The 'mutable' keyword allows specific member variables to be modified
// even inside const member functions. This is useful for:
// 1. Caching/memoization (storing computed results)
// 2. Logging and debugging counters
// 3. Thread synchronization (mutexes in const functions)
// 4. Lazy initialization of data

#include <iostream>
#include <string>
using namespace std;

// Logger class demonstrating mutable keyword usage
class Logger{
    // mutable member: CAN be modified inside const member functions
    // Used here to track how many times the log is accessed
    mutable int accessCount;
    
    // Regular member: CANNOT be modified inside const member functions
    // Stores the actual log message - should remain unchanged
    string message;
    
    public:
        // Constructor initializes both members
        Logger(string msg): message(msg), accessCount(0) {}
        
        // const member function: promises not to modify the object's state
        // However, mutable members (accessCount) can still be changed
        // Non-mutable members (message) cannot be modified here
        void print() const{
            ++accessCount;  // This is allowed because accessCount is mutable
            // message = "new"; // This would cause a compiler error!
            
            cout << "Message: " << message << endl;
            cout << "Access Count: " << accessCount << endl;
            cout << "---" << endl;
        }
};

int main(){
    Logger log("Hello, World!");
    
    cout << "=== Demonstrating Mutable Keyword ===" << endl;
    cout << "\nFirst call to print():" << endl;
    log.print();
    
    cout << "\nSecond call to print():" << endl;
    log.print();
    
    cout << "\nThird call to print():" << endl;
    log.print();
    
    cout << "\nNotice how accessCount increases each time," << endl;
    cout << "even though print() is a const function!" << endl;
    
    return 0;
}