// Sin(x) calculator using Taylor series
#include <iostream>
#include <cmath>
using namespace std;

// Calculate factorial
long long factorial(int n)
{
    if (n <= 1)
        return 1;
    long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

// Calculate nth term of Taylor series for sin(x)
float term(float x, int n)
{
    if (n <= 0)
        return 0;

    int power = 2 * n - 1;
    float xPower = 1.0;
    for (int i = 0; i < power; i++)
        xPower *= x;

    int sign = (n % 2 == 0) ? -1 : 1;
    return sign * xPower / factorial(power);
}

// Calculate sin(x) using Taylor series
float sinTaylor(float x, int terms)
{
    float result = 0.0;
    for (int n = 1; n <= terms; n++)
        result += term(x, n);
    return result;
}

int main()
{
    float X, x;
    int terms;

    cout << "Sin(x) Calculator (Taylor Series)\n\n";
    cout << "Enter angle in degrees: ";
    cin >> X;

    cout << "Enter number of terms: ";
    cin >> terms;

    if (terms <= 0)
    {
        cout << "Error: Terms must be > 0\n";
        return 1;
    }

    x = X * M_PI / 180.0;

    float sinApprox = sinTaylor(x, terms);
    float sinBuiltIn = sin(x);
    float difference = fabs(sinApprox - sinBuiltIn);

    cout << "\nAngle: " << X << "° (" << x << " rad)\n";
    cout << "Terms: " << terms << "\n";
    cout << "Taylor series: " << sinApprox << "\n";
    cout << "Built-in sin(): " << sinBuiltIn << "\n";
    cout << "Difference: " << difference << "\n";

    return 0;
}
