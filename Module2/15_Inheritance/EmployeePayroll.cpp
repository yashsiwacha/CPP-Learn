/*
 * Employee Payroll System - Demonstrating OOP Principles
 * 
 * This program demonstrates three fundamental Object-Oriented Programming principles:
 * 
 * 1. INHERITANCE: SalariedEmployee and HourlyEmployee inherit from the Employee base class.
 *    - Code reuse: Common properties (name, id, type) are defined once in the base class.
 *    - Extensibility: New employee types can be added by creating new derived classes.
 *    - "IS-A" relationship: SalariedEmployee IS-A Employee, HourlyEmployee IS-A Employee.
 * 
 * 2. ENCAPSULATION: Data members are private and accessed through public methods.
 *    - Data hiding: Private members (name, id, salary, hourlyRate) cannot be accessed directly.
 *    - Controlled access: Public getters and setters provide validated access to data.
 *    - Data integrity: Validation in setters ensures data remains in a valid state.
 * 
 * 3. ABSTRACTION: The Employee class defines a common interface with calculatePay().
 *    - Pure virtual function: calculatePay() = 0 makes Employee abstract.
 *    - Implementation hiding: Each derived class implements its own pay calculation logic.
 *    - Polymorphism: Different employee types can be treated uniformly through base class pointers.
 */

// Program to make a Employee Payroll System.
#include <iostream>
#include <vector>
#include <memory>
#include <iomanip>  // For output formatting
using namespace std;

/*
 * ABSTRACTION & ENCAPSULATION: Employee Base Class
 * 
 * ABSTRACTION:
 * - This is an abstract base class (cannot be instantiated directly)
 * - Provides a common interface for all employee types through calculatePay()
 * - The pure virtual function enforces that all derived classes must implement their own pay logic
 * 
 * ENCAPSULATION:
 * - Private data members (name, id) hide internal state from outside access
 * - Protected member (type) allows derived classes to access it while hiding from external code
 * - Public methods provide controlled, validated access to the data
 * - This protects data integrity and prevents invalid states
 */
class Employee
{
    // ENCAPSULATION: Private Members - hidden from outside access
    // Can only be modified through public setter methods with validation
    string name;
    int id;

protected:
    // ENCAPSULATION: Protected member - accessible to derived classes but not external code
    string type; // Protected member to store employee type (salaried or hourly)
    
public:
    // Constructor that initializes the private members to safe default values
    Employee() : name(""), id(0), type("") {}

    // ENCAPSULATION: Getter and Setter methods provide controlled access to private data
    // Setters include validation to ensure data integrity
    
    // Setter for name with validation (ENCAPSULATION principle)
    void setName(string name)
    {
        if (name.empty())
        {
            cout << "[Validation Error] Name cannot be empty." << endl;
            return;
        }
        this->name = name;
    }
    
    // Const getter ensures read-only access to name
    string getName() const
    {
        return this->name;
    }
    
    // Setter for ID with validation (ENCAPSULATION principle)
    void setID(int id)
    {
        if (id <= 0)
        {
            cout << "[Validation Error] ID must be a positive integer." << endl;
            return;
        }
        this->id = id;
    }
    
    // Const getter ensures read-only access to ID
    int getID() const
    {
        return this->id;
    }
    
    // Getter for employee type
    string getType() const
    {
        return this->type;
    }
    
    // ABSTRACTION: Pure virtual function creates an abstract interface
    // This enforces that all derived classes must implement their own calculatePay() method
    // This is the cornerstone of polymorphism - allowing different behaviors through a common interface
    virtual double calculatePay() const = 0;

    // Virtual destructor to ensure proper cleanup of derived classes
    virtual ~Employee() = default;
};

/*
 * INHERITANCE: SalariedEmployee inherits from Employee
 * 
 * INHERITANCE benefits demonstrated:
 * - Code reuse: Inherits name, id, type, and their methods from Employee
 * - Specialization: Adds salary specific to salaried employees
 * - "IS-A" relationship: SalariedEmployee IS-A Employee
 * 
 * ENCAPSULATION: salary is private, accessed through public methods
 * 
 * POLYMORPHISM: Implements calculatePay() with salaried-specific logic
 */
class SalariedEmployee : public Employee
{
    // ENCAPSULATION: Private member specific to SalariedEmployee
    double salary;

public:
    // Constructor initializes salary and sets employee type
    SalariedEmployee() : salary(0)
    {
        type = "Salaried";  // Setting protected member from base class
    }
    
    // ENCAPSULATION: Setter with validation for salary
    void setSalary(double salary)
    {
        if (salary <= 0)
        {
            cout << "[Validation Error] Salary must be a positive value." << endl;
            return;
        }
        this->salary = salary;
    }
    
    // ENCAPSULATION: Getter for salary
    double getSalary() const
    {
        return this->salary;
    }

    // POLYMORPHISM: Override the pure virtual function from base class
    // Provides salaried-specific implementation of pay calculation
    double calculatePay() const override
    {
        return this->salary;  // Salaried employees receive fixed monthly salary
    }
};

/*
 * INHERITANCE: HourlyEmployee inherits from Employee
 * 
 * INHERITANCE benefits demonstrated:
 * - Code reuse: Inherits name, id, type, and their methods from Employee
 * - Specialization: Adds hourlyRate and hoursWorked specific to hourly employees
 * - "IS-A" relationship: HourlyEmployee IS-A Employee
 * 
 * ENCAPSULATION: hourlyRate and hoursWorked are private, accessed through public methods
 * 
 * POLYMORPHISM: Implements calculatePay() with hourly-specific logic (rate × hours)
 */
class HourlyEmployee : public Employee
{
    // ENCAPSULATION: Private members specific to HourlyEmployee
    double hourlyRate, hoursWorked;

public:
    // Constructor initializes hourly-specific members and sets employee type
    HourlyEmployee() : hourlyRate(0), hoursWorked(0)
    {
        type = "Hourly";  // Setting protected member from base class
    }
    
    // ENCAPSULATION: Setter with validation for hourly rate
    void setHourlyRate(double hr)
    {
        if (hr <= 0)
        {
            cout << "[Validation Error] Hourly rate must be a positive value." << endl;
            return;
        }
        this->hourlyRate = hr;
    }
    
    // ENCAPSULATION: Getter for hourly rate
    double getHourlyRate() const
    {
        return this->hourlyRate;
    }
    
    // ENCAPSULATION: Setter with validation for hours worked
    void setHoursWorked(double hw)
    {
        if (hw <= 0)
        {
            cout << "[Validation Error] Hours worked must be a positive value." << endl;
            return;
        }
        this->hoursWorked = hw;
    }
    
    // ENCAPSULATION: Getter for hours worked
    double getHourWorked() const
    {
        return this->hoursWorked;
    }
    
    // POLYMORPHISM: Override the pure virtual function from base class
    // Provides hourly-specific implementation of pay calculation
    double calculatePay() const override
    {
        return hourlyRate * hoursWorked;  // Hourly employees: pay = rate × hours
    }
};

/*
 * Main Function - Demonstrating Polymorphism in Action
 * 
 * POLYMORPHISM demonstrated:
 * 1. A vector of base class pointers (unique_ptr<Employee>) can store different derived types
 * 2. All employee types are managed uniformly through the common Employee interface
 * 3. Runtime polymorphism: calculatePay() calls the correct method based on actual object type
 * 4. This allows treating different employee types consistently while maintaining their specific behaviors
 */
int main()
{
    // POLYMORPHISM: Vector of base class pointers holds different derived types
    // This demonstrates the "IS-A" relationship and polymorphic behavior
    vector<unique_ptr<Employee>> employees;

    // Create and configure SalariedEmployee before adding to vector
    // This approach avoids casting by working with the specific type first
    auto salariedEmp = make_unique<SalariedEmployee>();
    salariedEmp->setName("Yash");
    salariedEmp->setID(1);
    salariedEmp->setSalary(27500);  // Monthly salary
    employees.push_back(std::move(salariedEmp));  // Transfer ownership to vector

    // Create and configure HourlyEmployee before adding to vector
    auto hourlyEmp = make_unique<HourlyEmployee>();
    hourlyEmp->setName("John");
    hourlyEmp->setID(2);
    hourlyEmp->setHourlyRate(50);   // $50 per hour
    hourlyEmp->setHoursWorked(160); // 160 hours per month
    employees.push_back(std::move(hourlyEmp));  // Transfer ownership to vector

    // Display payroll information with improved formatting and clarity
    cout << "========================================" << endl;
    cout << "     EMPLOYEE PAYROLL SYSTEM" << endl;
    cout << "     Monthly Compensation Report" << endl;
    cout << "========================================" << endl
         << endl;

    // POLYMORPHISM IN ACTION: Loop through base class pointers
    // calculatePay() calls the correct derived class method at runtime (dynamic dispatch)
    for (const auto &emp : employees)
    {
        cout << "Employee Type: " << emp->getType() << endl;
        cout << "Name:          " << emp->getName() << endl;
        cout << "ID:            " << emp->getID() << endl;
        
        // Set fixed precision for currency display
        cout << fixed << setprecision(2);
        cout << "Monthly Pay:   $" << emp->calculatePay() << endl;
        
        // Additional context based on employee type
        if (emp->getType() == "Salaried") {
            cout << "Payment Type:  Fixed Monthly Salary" << endl;
        } else if (emp->getType() == "Hourly") {
            cout << "Payment Type:  Calculated from Hours Worked" << endl;
        }
        
        cout << "----------------------------------------" << endl
             << endl;
    }

    cout << "========================================" << endl;
    cout << "Total Employees: " << employees.size() << endl;
    cout << "========================================" << endl;
    
    return 0;
}
