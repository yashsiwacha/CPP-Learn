// Temperature converter from Fahrenheit to Celsius
#include <iostream>
using namespace std;

float toCelsius(float f)
{
    return ((f - 32) * 5) / 9;
}

int main()
{
    float f;
    cout << "Enter temperature in Fahrenheit: ";
    cin >> f;

    float c = toCelsius(f);
    cout << "Fahrenheit: " << f << "F\n";
    cout << "Celsius: " << c << "C\n";

    return 0;
}