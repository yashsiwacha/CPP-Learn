/*
 * Program: Temperature Converter with Encapsulation
 * Description: Demonstrates encapsulation principles in OOP
 *
 * Key Concepts Demonstrated:
 * - ENCAPSULATION: Private data member cannot be accessed directly from outside the class
 * - DATA HIDING: The celsius variable is hidden to prevent unauthorized or invalid modifications
 * - CONTROLLED ACCESS: Public setter/getter methods provide controlled access to private data
 * - VALIDATION: Setter method validates data before storing to maintain data integrity
 *
 * Why Encapsulation Matters:
 * - Prevents invalid data (e.g., temperature below absolute zero -273.15°C)
 * - Maintains object state consistency
 * - Allows changing internal implementation without affecting external code
 * - Provides a clean interface to interact with the object
 */

#include <iostream>
#include <iomanip>
using namespace std;

class Temperature
{
private:
    /*
     * Private data member - ENCAPSULATED to prevent direct access
     *
     * WHY PRIVATE?
     * - If this was public, anyone could set: temp1.celsius = -500; (invalid!)
     * - Direct modification bypasses validation and can break object state
     * - In C++, making members private enforces data protection at compile-time
     */
    double celsius;

public:
    /*
     * Setter method with VALIDATION - the gatekeeper for data integrity
     *
     * Why validation is critical:
     * - Temperature cannot go below absolute zero (-273.15°C)
     * - Without validation, invalid data could corrupt calculations
     * - This demonstrates the power of encapsulation: control HOW data is modified
     */
    void setCelsius(double value)
    {
        // Validate: Check if temperature is physically possible
        if (value < -273.15)
        {
            // Reject invalid data and inform user
            cout << "ERROR: Temperature cannot be below absolute zero (-273.15°C)!" << endl;
            cout << "       Invalid value " << value << "°C was rejected." << endl;
            return; // Don't modify the private member
        }

        // Valid data - safe to store
        this->celsius = value;
    }

    /*
     * Getter method - provides READ-ONLY access to private data
     *
     * Why use a getter instead of making celsius public?
     * - Maintains encapsulation even for reading
     * - Allows adding logic (e.g., logging, caching) without changing interface
     * - Can return computed or formatted values if needed
     */
    double getCelsius()
    {
        return this->celsius;
    }

    /*
     * Conversion method - converts celsius to fahrenheit
     * Formula: F = (C × 9/5) + 32
     */
    double getFahrenheit()
    {
        return ((celsius * 9.0 / 5.0) + 32);
    }

    /*
     * Conversion method - converts celsius to kelvin
     * Formula: K = C + 273.15
     */
    double getKelvin()
    {
        return (celsius + 273.15);
    }
};

int main()
{
    cout << "╔════════════════════════════════════════════╗" << endl;
    cout << "║     Temperature Converter Program         ║" << endl;
    cout << "║        Demonstrating Encapsulation        ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;
    cout << endl;

    // Create Temperature object
    Temperature temp1;

    // Test 1: Valid temperature
    cout << "Test 1: Setting valid temperature (36°C)" << endl;
    temp1.setCelsius(36);

    // Display results with formatting
    cout << fixed << setprecision(2);
    cout << "\nTemperature Reading:" << endl;
    cout << "─────────────────────────────────" << endl;
    cout << "Celsius:    " << setw(8) << temp1.getCelsius() << " °C" << endl;
    cout << "Fahrenheit: " << setw(8) << temp1.getFahrenheit() << " °F" << endl;
    cout << "Kelvin:     " << setw(8) << temp1.getKelvin() << " K" << endl;
    cout << "─────────────────────────────────" << endl;

    // Test 2: Invalid temperature (below absolute zero)
    cout << "\n\nTest 2: Attempting to set invalid temperature (-300°C)" << endl;
    temp1.setCelsius(-300); // This will be rejected with error message

    // Verify the value wasn't changed
    cout << "\nCurrent temperature after invalid attempt: "
         << temp1.getCelsius() << "°C" << endl;
    cout << "(Notice: Value remains unchanged, demonstrating data protection)" << endl;

    // Test 3: Edge case - exactly at absolute zero
    cout << "\n\nTest 3: Setting temperature at absolute zero (-273.15°C)" << endl;
    Temperature temp2;
    temp2.setCelsius(-273.15);

    cout << "\nTemperature Reading:" << endl;
    cout << "─────────────────────────────────" << endl;
    cout << "Celsius:    " << setw(8) << temp2.getCelsius() << " °C" << endl;
    cout << "Fahrenheit: " << setw(8) << temp2.getFahrenheit() << " °F" << endl;
    cout << "Kelvin:     " << setw(8) << temp2.getKelvin() << " K" << endl;
    cout << "─────────────────────────────────" << endl;

    cout << "\n╔════════════════════════════════════════════╗" << endl;
    cout << "║    Encapsulation Successfully Verified!    ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;

    return 0;
}