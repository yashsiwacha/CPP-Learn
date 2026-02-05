/**
 * Program to demonstrate Multilevel Inheritance in C++
 *
 * Hierarchy: Vehicle (Base) -> Car (Intermediate) -> ElectricCar (Derived)
 *
 * Key Concepts Demonstrated:
 * 1. Constructor chaining across multiple inheritance levels
 * 2. Protected member access in derived classes
 * 3. Proper initialization using constructor initialization lists (RECOMMENDED)
 */
#include <iostream>
using namespace std;

/**
 * BASE CLASS: Vehicle
 * Contains common attributes for all vehicles (make, model)
 * Uses 'protected' members to allow derived class access while maintaining encapsulation
 */
class Vehicle
{
protected:
    string make;
    string model;

public:
    // Default constructor
    Vehicle()
    {
        cout << "[Level 1] Vehicle Default Constructor called." << endl;
    }

    // Parameterized constructor
    Vehicle(string m, string mod)
    {
        make = m;
        model = mod;
        cout << "[Level 1] Vehicle Parameterized Constructor called." << endl;
    }

    // Setter and getter methods for encapsulated access
    void setMake(string m) { make = m; }
    void setModel(string mod) { model = mod; }
    string getMake() { return make; }
    string getModel() { return model; }

    void displayVehicle()
    {
        cout << "Make: " << make << ", Model: " << model << endl;
    }
};

/**
 * INTERMEDIATE CLASS: Car (inherits from Vehicle)
 * Adds car-specific attribute (doors)
 * Demonstrates constructor chaining using initialization list
 */
class Car : public Vehicle
{
protected:
    int doors;

public:
    // Default constructor
    Car()
    {
        cout << "[Level 2] Car Default Constructor called." << endl;
    }

    // Parameterized constructor - uses initialization list to call parent constructor
    Car(string m, string mod, int d) : Vehicle(m, mod)
    {
        doors = d;
        cout << "[Level 2] Car Parameterized Constructor called." << endl;
    }

    // Setter and getter for Car-specific members
    void setDoors(int d) { doors = d; }
    int getDoors() { return doors; }

    void displayCar()
    {
        cout << "Make: " << make << ", Model: " << model << ", Doors: " << doors << endl;
    }
};

/**
 * DERIVED CLASS: ElectricCar (inherits from Car)
 * Demonstrates MULTILEVEL INHERITANCE: ElectricCar -> Car -> Vehicle (3 levels)
 * Constructor initialization list creates a chain: calls Car(), which calls Vehicle()
 */
class ElectricCar : public Car
{
protected:
    double batteryCapacity;

public:
    // Constructor with full parameters - demonstrates constructor chaining
    // Calls Car constructor, which automatically calls Vehicle constructor
    ElectricCar(string m, string mod, int d, double battery) : Car(m, mod, d)
    {
        batteryCapacity = battery;
        cout << "[Level 3] ElectricCar Parameterized Constructor called." << endl;
    }

    // Constructor with default make/model - still demonstrates full chaining
    ElectricCar(int d, double battery) : Car("Tesla", "Model S", d)
    {
        batteryCapacity = battery;
        cout << "[Level 3] ElectricCar Alternative Constructor called." << endl;
    }

    // Direct access to protected members across all inheritance levels
    void setAllDetails(string m, string mod, int d, double battery)
    {
        make = m;                  // From Vehicle (grandparent)
        model = mod;               // From Vehicle (grandparent)
        doors = d;                 // From Car (parent)
        batteryCapacity = battery; // Own member
    }

    void displayElectricCar()
    {
        cout << "Make: " << make
             << ", Model: " << model
             << ", Doors: " << doors
             << ", Battery: " << batteryCapacity << " kWh" << endl;
    }
};

int main()
{
    cout << "=================================================================" << endl;
    cout << "MULTILEVEL INHERITANCE - Constructor Chaining Demonstration" << endl;
    cout << "=================================================================" << endl;

    cout << "\n--- Creating ElectricCar Object 1 (Full Parameters) ---" << endl;
    ElectricCar ec1("Tesla", "Model 3", 4, 75.0);
    cout << "Result: ";
    ec1.displayElectricCar();

    cout << "\n--- Creating ElectricCar Object 2 (Default Make/Model) ---" << endl;
    ElectricCar ec2(2, 100.0);
    cout << "Result: ";
    ec2.displayElectricCar();

    cout << "\n--- Modifying Object Using Protected Member Access ---" << endl;
    ElectricCar ec3("Nissan", "Leaf", 4, 40.0);
    cout << "Before modification: ";
    ec3.displayElectricCar();
    ec3.setAllDetails("BMW", "i4", 4, 80.0);
    cout << "After modification:  ";
    ec3.displayElectricCar();

    cout << "\n=================================================================" << endl;
    cout << "Key Observation: Constructor calls follow the hierarchy" << endl;
    cout << "Vehicle (Level 1) -> Car (Level 2) -> ElectricCar (Level 3)" << endl;
    cout << "=================================================================" << endl;

    return 0;
}