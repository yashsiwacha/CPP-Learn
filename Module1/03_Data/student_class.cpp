// Program for calculating simple interest
#include <iostream>
using namespace std;

// Calculate simple interest: SI = (P × R × T) / 100
float calculateSimpleInterest(float principal, float rate, float time)
{
    return (principal * rate * time) / 100;
}

int main()
{
    float principal, rate, time;

    cout << "Enter principal amount: ";
    cin >> principal;
    cout << "Enter rate of interest: ";
    cin >> rate;
    cout << "Enter time period (years): ";
    cin >> time;

    float interest = calculateSimpleInterest(principal, rate, time);

    cout << "\nPrincipal: " << principal << "\n";
    cout << "Rate: " << rate << "%\n";
    cout << "Time: " << time << " years\n";
    cout << "Simple Interest: " << interest << "\n";

    return 0;
}
