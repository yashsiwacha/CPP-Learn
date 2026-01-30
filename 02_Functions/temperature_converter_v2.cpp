//Program for converting Temperature from fahrenheit to celsius.
#include <iostream>
using namespace std;

//Function for coverting temperature from fahrenheit to celsius.
float conversion(float f){
    return ((f-32)*5)/9; //Return the value after calculating the converted value.
}

//Main function.
int main(){

    float f, c; //Declaring the variable for storing temperatures in fahrenheit and celsius.
    cout << "Enter the temperature in fahrenheit: ";
    cin >> f; //Taking input from user for the temperature in fahrenheit which is to be converted.
    c = conversion(f); //Assigning the value returned by the conversion function to the variable which was declared for celsius.
    cout << "Temperature in Fahrenheit: " << f << "F" << endl; //Printing the temperature in fahremheit.
    cout << "Temperature in Celsius: " << c << "C" << endl; //Printing the temperature in celsius.

}