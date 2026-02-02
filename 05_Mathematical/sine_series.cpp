// Sin(X) Calculator Using Taylor Series
#include <iostream>
#include <cmath>
using namespace std;

// Calculate factorial of a number (n!)
long long factorial(int n)
{
    if (n < 0)
        return 0;
    if (n == 0 || n == 1)
        return 1;

    long long result = 1;
    for (int i = 2; i <= n; i++)
    {
        result *= i;
    }
    return result;
}

// Calculate nth term of Taylor series for sin(x)
// Formula: (-1)^(n+1) * (x^(2n-1)) / (2n-1)!
float term(float x, int n)
{
    if (n <= 0)
        return 0;

    // Calculate power: x^(2n-1)
    int power = 2 * n - 1;
    float xPower = 1.0;
    for (int i = 0; i < power; i++)
    {
        xPower *= x;
    }

    // Calculate factorial of power
    long long fact = factorial(power);

    // Determine sign: alternates between + and -
    int sign = (n % 2 == 0) ? -1 : 1;

    return sign * xPower / fact;
}

// Calculate sin(x) using Taylor series expansion
float sinTaylor(float x, int terms)
{
    if (terms <= 0)
        return 0;

    float result = 0.0;
    // Sum up all terms in the series
    for (int n = 1; n <= terms; n++)
    {
        result += term(x, n);
    }
    return result;
}

int main()
{
    float X, x;
    int terms;

    cout << "=== Sin(X) Calculator Using Taylor Series ===" << endl;
    cout << "\nEnter the angle X in degrees: ";
    cin >> X;

    cout << "Enter the number of terms for Taylor series: ";
    cin >> terms;

    if (terms <= 0)
    {
        cout << "\nError: Number of terms must be greater than 0!" << endl;
        return 1;
    }

    x = X * M_PI / 180.0;

    float sinApprox = sinTaylor(x, terms);

    float sinBuiltIn = sin(x);

    float difference = fabs(sinApprox - sinBuiltIn);

    cout << "\n=== Results ===" << endl;
    cout << "Angle in degrees: " << X << "°" << endl;
    cout << "Angle in radians: " << x << " rad" << endl;
    cout << "Number of terms used: " << terms << endl;
    cout << "\nTaylor series approximation: " << sinApprox << endl;
    cout << "Built-in sin() function: " << sinBuiltIn << endl;
    cout << "Absolute difference: " << difference << endl;

    if (difference < 0.0001)
    {
        cout << "\nExcellent accuracy! The approximation is very close to the actual value." << endl;
    }
    else if (difference < 0.01)
    {
        cout << "\nGood accuracy! Consider using more terms for better precision." << endl;
    }
    else
    {
        cout << "\nLow accuracy. Use more terms to improve the approximation." << endl;
    }

    return 0;
}
