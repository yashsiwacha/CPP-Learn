//Making a program to calculate shipping cost based on weight and region.
#include <iostream>
#include <iomanip>
using namespace std;


//Function for calculating cost for region C.
double costforA(double w){
    if(w<=2) return 100;
    if(w>2&&w<=10) return 200;
    else if(w>10) return 200 + (w-10)*50;
}

//Function for calculating cost for region C.
double costforB(double w){
    if(w<=5) return 300;
    else return 300 + (w-5)*50;
}

//Function for calculating cost for region C.
double costforC(double w){
    if(w<=5) return 500;
    else if(w>5) return 500 + (w-5)*100;
}

//Function for calculator interface.
void calculator(){
    double w;
    cout << "Enter the weight of parcel to be shipped: ";
    cin >> w;
    //Using if to check if the input is valid or not.
    if(w>0&&w<=100){
        char r;
        cout << "Enter the region: ";
        cin >> r;
        //Using if to check if the input is valid or not.
        if(r=='A'||r=='B'||r=='C'){
            
            //Using if to calculate cost for differnt regions.
            if(r=='A'){
                cout << "Total shipping cost: $" << setprecision(2) << costforA(w);
            }
            if(r=='B'){
                cout << "Total shipping cost: $" << setprecision(2) <<  costforB(w);
            }
            if(r=='C'){
                cout << "Total shipping cost: $ "<< setprecision(2) << costforC(w);
            }
        }
        else cout << "Error: Invalid shipping zone. Please enter A, B, or C.";
        
    }
    else if(w>100) cout << "Error: Order weight must be less than 100.";
    else cout << "Error: Order weight must be positive.";
}

//Main Function
int main(){
    calculator();
    return 0;
}