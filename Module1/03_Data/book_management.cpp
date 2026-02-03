// Program to convert days to years, weeks and days
#include <iostream>
using namespace std;

void convertDays(int total_days)
{
    int years = total_days / 365;
    int remaining = total_days % 365;
    int weeks = remaining / 7;
    int days = remaining % 7;

    cout << total_days << " days = " << years << " years, " << weeks << " weeks, " << days << " days\n";
}

int main()
{
    int totaldays;
    cout << "Enter days: ";
    cin >> totaldays;
    convertDays(totaldays);
    return 0;
}