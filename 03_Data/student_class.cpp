//Developing a program for calculating simple interst.
#include <iostream>
using namespace std;

//Function for calculating simple interest.
float calculateSimpleInterest(float principal_amount, float rate_of_interest, float time_period){
        return (principal_amount*rate_of_interest*time_period)/100;
}

int main(){
    //Declaring the variable for components of interest.
    float principal_amount , time_period, rate_of_interest;
    //Taking input from the user.
    cout << "Enter the principal amount: ";
    cin >> principal_amount;
    cout << "Enter the Rate Of Interest: ";
    cin >> rate_of_interest;
    cout << "Enter the time period: ";
    cin >> time_period;
    
    float result = calculateSimpleInterest(principal_amount,rate_of_interest,time_period);
    cout << "Principal Amount : " << principal_amount << endl;
    cout << "Rate Of Interest : " << rate_of_interest << "%" << endl;
    cout << "Time period : " << time_period << endl;
    cout << "Simple interest calculated on " << principal_amount << " at the rate of interest of " << rate_of_interest << "% over " << time_period << " years is " << result << endl;
}
