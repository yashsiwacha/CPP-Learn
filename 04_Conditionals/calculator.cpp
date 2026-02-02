// Simple calculator that performs addition, subtraction, multiplication, and division.
#include <iostream>
#include <limits>
using namespace std;

float addition(float a, float b)
{
    return a + b;
}

float subtraction(float a, float b)
{
    return a - b;
}

float multiplication(float a, float b)
{
    return a * b;
}

float division(float a, float b, bool &success)
{
    // Prevent division by zero
    if (b == 0)
    {
        success = false;
        return 0;
    }
    success = true;
    return a / b;
}

void calculator()
{
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

    if (cin.fail() || c < 1 || c > 4)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "\n[ERROR] Invalid choice! Please enter a number between 1 and 4.\n";
        calculator();
        return;
    }

    float a, b;
    cout << "\nEnter first number: ";
    cin >> a;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[ERROR] Invalid input! Please enter a valid number.\n";
        calculator();
        return;
    }

    cout << "Enter second number: ";
    cin >> b;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "[ERROR] Invalid input! Please enter a valid number.\n";
        calculator();
        return;
    }

    float result;
    bool success = true;

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
        if (!success)
        {
            cout << "\n[ERROR] Division by zero is not allowed!\n";
        }
        else
        {
            cout << "\n[RESULT] " << a << " / " << b << " = " << result << endl;
        }
        break;
    }
}

int main()
{
    char choice;

    do
    {
        calculator();

        cout << "\nDo you want to perform another calculation? (y/n): ";
        cin >> choice;

        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "[ERROR] Invalid input! Please enter 'y' for yes or 'n' for no: ";
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using the calculator. Goodbye!\n";
    return 0;
}