// Program to calculate shipping cost based on weight and region
#include <iostream>
using namespace std;

// Calculate cost for Region A
double costforA(double w)
{
    if (w <= 2)
        return 100;
    if (w > 2 && w <= 10)
        return 200;
    else
        return 200 + (w - 10) * 50;
}

// Calculate cost for Region B
double costforB(double w)
{
    if (w <= 5)
        return 300;
    else
        return 300 + (w - 5) * 50;
}

// Calculate cost for Region C
double costforC(double w)
{
    if (w <= 5)
        return 500;
    else
        return 500 + (w - 5) * 100;
}

void calculator()
{
    double w;
    cout << "Enter parcel weight: ";
    cin >> w;

    if (w > 0 && w <= 100)
    {
        char r;
        cout << "Enter region (A/B/C): ";
        cin >> r;

        if (r == 'A' || r == 'B' || r == 'C')
        {
            if (r == 'A')
                cout << "Shipping cost: $" << costforA(w) << "\n";
            if (r == 'B')
                cout << "Shipping cost: $" << costforB(w) << "\n";
            if (r == 'C')
                cout << "Shipping cost: $" << costforC(w) << "\n";
        }
        else
            cout << "Error: Invalid shipping zone\n";
    }
    else if (w > 100)
        cout << "Error: Weight must be less than 100\n";
    else
        cout << "Error: Weight must be positive\n";
}

int main()
{
    calculator();
    return 0;
}