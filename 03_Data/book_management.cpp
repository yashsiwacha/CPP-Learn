//Program for converting days to years, weeks and days.
#include <iostream>
using namespace std;

//Function for converting and printing days into years, weeks and days.
void convertDays(int total_days){
    //Declaring the variable needed for calculating
    int years , weeks , days , remaining;
    
    //Calculating the years, weeks and days.
    years = total_days/365;
    remaining = total_days%365;
    weeks = remaining/7;
    days = remaining%7;

    //Printing the result.
    cout << total_days << " days are " << years << " years, " << weeks << " weeks and " << days << " days." <<endl;

}

//Main function
int main(){
    int totaldays;
    cin >> totaldays;
    convertDays(totaldays);
    return 0;
}