// Simple calculator for basic arithmetic operations
#include <iostream>
#include <limits>
using namespace std;

float addition(float a, float b) { return a + b; }
float subtraction(float a, float b) { return a - b; }
float multiplication(float a, float b) { return a * b; }

// Division with zero check
float division(float a, float b, bool &success)
{
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
    cout << "\n1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n";
    cout << "Choice: ";

    int c;
    cin >> c;

    if (cin.fail() || c < 1 || c > 4)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid choice\n";
        return;
    }

    float a, b;
    cout << "Enter first number: ";
    cin >> a;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input\n";
        return;
    }

    cout << "Enter second number: ";
    cin >> b;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Invalid input\n";
        return;
    }

    float result;
    bool success = true;

    switch (c)
    {
    case 1:
        result = addition(a, b);
        cout << "\n"
             << a << " + " << b << " = " << result << "\n";
        break;
    case 2:
        result = subtraction(a, b);
        cout << "\n"
             << a << " - " << b << " = " << result << "\n";
        break;
    case 3:
        result = multiplication(a, b);
        cout << "\n"
             << a << " * " << b << " = " << result << "\n";
        break;
    case 4:
        result = division(a, b, success);
        if (!success)
            cout << "\nError: Division by zero\n";
        else
            cout << "\n"
                 << a << " / " << b << " = " << result << "\n";
        break;
    }
}

int main()
{
    char choice;

    do
    {
        calculator();
        cout << "\nContinue? (y/n): ";
        cin >> choice;

        while (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Enter y or n: ";
            cin >> choice;
        }

    } while (choice == 'y' || choice == 'Y');

    return 0;
}