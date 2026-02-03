// Exponential function calculator using Taylor series
#include <iostream>
#include <cmath>
using namespace std;

// Calculate e^x using Taylor series: e^x = 1 + x + x^2/2! + x^3/3! + ...
float expo(float x, int n)
{
    float sum = 1.0;
    float term = 1.0;

    for (int i = 1; i <= n; i++)
    {
        term = term * x / i;
        sum += term;
    }

    return sum;
}

int main()
{
    float x;
    int n;

    cout << "Exponential Calculator (Taylor Series)\n";
    cout << "Formula: e^x = 1 + x + x^2/2! + x^3/3! + ...\n\n";

    cout << "Enter x: ";
    cin >> x;

    if (cin.fail())
    {
        cout << "Invalid input\n";
        return 1;
    }

    cout << "Enter number of terms (>= 0): ";
    cin >> n;

    if (cin.fail() || n < 0)
    {
        cout << "Invalid input\n";
        return 1;
    }

    float result = expo(x, n);
    float actual = exp(x);
    float error = abs(result - actual);
    float percentError = (actual != 0) ? (error / actual) * 100 : 0;

    cout << "\nInput: x = " << x << ", terms = " << (n + 1) << "\n";
    cout << "Calculated e^" << x << ": " << result << "\n";
    cout << "Actual e^" << x << ": " << actual << "\n";
    cout << "Error: " << error << " (" << percentError << "%)\n";

    return 0;
}
