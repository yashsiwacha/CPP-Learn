#include <iostream>
#include <string>
using namespace std;

/**
 * CLion Setup Test Program
 * This program verifies that your CLion C++ setup is working correctly.
 */

int main() {
    cout << "========================================" << endl;
    cout << "   CLion C++ Setup Test - SUCCESS!    " << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // Test 1: Basic output
    cout << "[Test 1] Console output: PASSED" << endl;
    
    // Test 2: Variables and calculations
    int a = 10, b = 20;
    int sum = a + b;
    cout << "[Test 2] Calculations: " << a << " + " << b << " = " << sum << " PASSED" << endl;
    
    // Test 3: String handling
    string name = "CLion";
    cout << "[Test 3] String handling: Hello from " << name << " PASSED" << endl;
    
    // Test 4: Conditionals
    bool isWorking = (sum == 30);
    if (isWorking) {
        cout << "[Test 4] Conditionals: PASSED" << endl;
    }
    
    // Test 5: Loops
    int count = 0;
    for (int i = 1; i <= 5; i++) {
        count += i;
    }
    cout << "[Test 5] Loops: Sum(1..5) = " << count << " PASSED" << endl;
    
    cout << endl;
    cout << "========================================" << endl;
    cout << "All tests PASSED! Your setup is ready." << endl;
    cout << "========================================" << endl;
    cout << endl;
    cout << "Next steps:" << endl;
    cout << "1. Select any program from the dropdown" << endl;
    cout << "2. Press Shift+F10 to run" << endl;
    cout << "3. Press Shift+F9 to debug" << endl;
    cout << endl;
    
    // Interactive test
    cout << "Enter your name: ";
    string userName;
    getline(cin, userName);
    
    if (!userName.empty()) {
        cout << endl;
        cout << "Welcome, " << userName << "! Happy coding!" << endl;
    }
    
    return 0;
}
