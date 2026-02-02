// Program for converting Temperature from fahrenheit to celsius.
#include <iostream>
using namespace std;

float conversion(float f)
{
    return ((f - 32) * 5) / 9;
}

int main()
{

    float f, c;
    cout << "Enter the temperature in fahrenheit: ";
    cin >> f;
    c = conversion(f);
    cout << "Temperature in Fahrenheit: " << f << "F" << endl;
    cout << "Temperature in Celsius: " << c << "C" << endl;
}