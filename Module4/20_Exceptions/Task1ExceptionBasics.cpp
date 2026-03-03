#include <iostream>
#include <stdexcept>
using namespace std;

int divide(int numerator, int denominator)
{
    if (denominator == 0)
    {
        throw runtime_error("Division by zero cannot be performed.");
    }

    return numerator / denominator;
}

int main()
{
    int numerator, denominator;

    cout << "Enter numerator: ";
    cin >> numerator;

    cout << "Enter denominator: ";
    cin >> denominator;

    try
    {
        int result = divide(numerator, denominator);
        cout << "Result of division: " << result << endl;
    }
    catch (const runtime_error &e)
    {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}