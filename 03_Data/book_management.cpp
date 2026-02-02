// Program for converting days to years, weeks and days.
#include <iostream>
using namespace std;

void convertDays(int total_days)
{
    int years, weeks, days, remaining;

    years = total_days / 365;
    remaining = total_days % 365;
    weeks = remaining / 7;
    days = remaining % 7;

    cout << total_days << " days are " << years << " years, " << weeks << " weeks and " << days << " days." << endl;
}

int main()
{
    int totaldays;
    cin >> totaldays;
    convertDays(totaldays);
    return 0;
}