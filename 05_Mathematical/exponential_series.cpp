//Program for solving exponential function.
#include <iostream>
#include <math.h>
using namespace std;

//Custom function for calculating power without using pow()
float power(float base, int exponent){
    if(exponent == 0) return 1;
    
    float result = 1;
    for(int i = 0; i < exponent; i++){
        result *= base;
    }
    return result;
}

//function for calculating factorial using iterative approach for better efficiency
long long factorial(int n){
    if(n == 0 || n == 1) return 1;  // 0! = 1 and 1! = 1
    
    long long result = 1;
    for(int i = 2; i <= n; i++){
        result *= i;
    }
    return result;
}

//function for calculating nth term of Taylor series: x^n / n!
float nthterm(float x, int n){
    return power(x, n) / factorial(n);
}

//function to sum up all terms from 0 to n: e^x ≈ Σ(x^i / i!) for i=0 to n
//Optimized to compute terms incrementally without recalculating factorials
float expo(float x, int n){
    float sum = 1.0;  // First term: x^0/0! = 1
    float term = 1.0; // Current term in the series
    
    // Incrementally compute each term: term(i) = term(i-1) * x / i
    for(int i = 1; i <= n; i++){
        term = term * x / i;  // Efficient: avoids recalculating power and factorial
        sum += term;
    }
    
    return sum;
}

//Main function to test the exponential calculation
int main(){
    float x;
    int n;
    
    cout << "=== Exponential Function Calculator (Taylor Series) ===\n";
    cout << "Formula: e^x = 1 + x + x^2/2! + x^3/3! + ... + x^n/n!\n\n";
    
    // Input for x value
    cout << "Enter the value of x: ";
    cin >> x;
    
    // Input validation for x
    if(cin.fail()){
        cout << "[ERROR] Invalid input for x. Please enter a valid number." << endl;
        return 1;
    }
    
    // Edge case: Warning for very large or small x values
    if(abs(x) > 10){
        cout << "[WARNING] Large |x| value detected. You may need many terms for accurate convergence." << endl;
        cout << "          Recommended terms: at least " << (int)(abs(x) * 2) << " for reasonable accuracy.\n" << endl;
    }
    
    // Input for number of terms
    cout << "Enter the number of terms (n must be >= 0): ";
    cin >> n;
    
    // Input validation for n
    if(cin.fail()){
        cout << "[ERROR] Invalid input for n. Please enter a valid integer." << endl;
        return 1;
    }
    
    // Check if n is non-negative
    if(n < 0){
        cout << "[ERROR] Number of terms must be a non-negative integer." << endl;
        return 1;
    }
    
    // Edge case: Check for potential overflow with large n
    if(n > 20){
        cout << "[WARNING] Large n value may cause precision issues with float type.\n" << endl;
    }
    
    // Edge case: x = 0
    if(x == 0){
        cout << "\n[INFO] For x = 0, e^0 = 1 (exact value)" << endl;
    }
    
    // Calculate using Taylor series
    float result = expo(x, n);
    float actual = exp(x);  // C++ built-in exponential function for comparison
    float error = abs(result - actual);
    float percentError = (actual != 0) ? (error / actual) * 100 : 0;
    
    // Display results with clear context
    cout << "\n======= RESULTS =======" << endl;
    cout << "Input value (x): " << x << endl;
    cout << "Number of terms used: " << (n + 1) << " (from term 0 to term " << n << ")" << endl;
    cout << "\nCalculated e^" << x << " (Taylor series): " << result << endl;
    cout << "Actual e^" << x << " (built-in exp()): " << actual << endl;
    cout << "\nAbsolute Error: " << error << endl;
    cout << "Percentage Error: " << percentError << "%" << endl;
    
    // Convergence suggestion
    if(percentError > 1){
        cout << "\n[TIP] For better accuracy, try increasing the number of terms." << endl;
    } else if(percentError < 0.01){
        cout << "\n[SUCCESS] Excellent convergence achieved!" << endl;
    } else {
        cout << "\n[SUCCESS] Good convergence achieved!" << endl;
    }
    
    return 0;
}
