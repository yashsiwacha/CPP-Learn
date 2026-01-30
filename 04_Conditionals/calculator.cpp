// Developing a simple calculator that performs addition, subtraction, multiplication, and division.
#include <iostream>
#include <limits>
using namespace std;

/**
 * Function for addition operation.
 * @param a First operand
 * @param b Second operand
 * @return Sum of a and b
 */
float addition(float a, float b){
    return a + b;
}

/**
 * Function for subtraction operation.
 * @param a First operand
 * @param b Second operand
 * @return Difference of a and b
 */
float subtraction(float a, float b){
    return a - b;
}

/**
 * Function for multiplication operation.
 * @param a First operand
 * @param b Second operand
 * @return Product of a and b
 */
float multiplication(float a, float b){
    return a * b;
}

/**
 * Function for division operation.
 * @param a Dividend
 * @param b Divisor
 * @param success Reference to boolean flag indicating if division was successful
 * @return Quotient of a and b, or 0 if division by zero
 */
float division(float a, float b, bool &success){
    if(b == 0){
        success = false;
        return 0;
    }
    success = true;
    return a / b;
}

/**
 * Function for calculator interface with input validation and clear output.
 * Handles user menu selection and arithmetic operations with proper error handling.
 */
void calculator(){
    cout << "\n========== SIMPLE CALCULATOR ==========\n";
    cout << "Enter your choice 1-4:\n";
    cout << "1. Addition\n";
    cout << "2. Subtraction\n";
    cout << "3. Multiplication\n";
    cout << "4. Division\n";
    cout << "=======================================\n";
    cout << "Your choice: ";
    
    int c;
    cin >> c;
    
    // Validate menu input
    if(cin.fail() || c < 1 || c > 4){
        cin.clear(); // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
        cout << "\n[ERROR] Invalid choice! Please enter a number between 1 and 4.\n";
        calculator();
        return;
    }
    
    // Declare operands once for all cases
    float a, b;
    cout << "\nEnter first number: ";
    cin >> a;
    
    // Validate first number input
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[ERROR] Invalid input! Please enter a valid number.\n";
        calculator();
        return;
    }
    
    cout << "Enter second number: ";
    cin >> b;
    
    // Validate second number input
    if(cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[ERROR] Invalid input! Please enter a valid number.\n";
        calculator();
        return;
    }
    
    float result;
    bool success = true;
    
    // Using Switch for handling choices with clear output labels
    switch (c)
    {
    case 1:
        result = addition(a, b);
        cout << "\n[RESULT] " << a << " + " << b << " = " << result << endl;
        break;
    
    case 2:
        result = subtraction(a, b);
        cout << "\n[RESULT] " << a << " - " << b << " = " << result << endl;
        break;

    case 3:
        result = multiplication(a, b);
        cout << "\n[RESULT] " << a << " * " << b << " = " << result << endl;
        break;

    case 4:
        result = division(a, b, success);
        if(!success){
            cout << "\n[ERROR] Division by zero is not allowed!\n";
        } else {
            cout << "\n[RESULT] " << a << " / " << b << " = " << result << endl;
        }
        break;
    }
}

/**
 * Main function - entry point of the calculator program.
 * Provides option to perform multiple calculations.
 */
int main(){
    char choice;
    
    do {
        calculator();
        
        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;
        
        // Validate yes/no input
        while(choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N'){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERROR] Invalid input! Please enter 'y' for yes or 'n' for no: ";
            cin >> choice;
        }
        
    } while(choice == 'y' || choice == 'Y');
    
    cout << "\nThank you for using the calculator. Goodbye!\n";
    return 0;
}