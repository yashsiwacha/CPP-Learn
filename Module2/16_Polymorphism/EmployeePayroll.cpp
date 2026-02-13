// Program to demonstrate Polymorphism using the Employee Payroll System.
// This demonstrates Runtime Polymorphism using Virtual Functions and Inheritance.
#include <iostream>
#include <string>

// Base Class: Employee
// This class defines the interface for all employee types using a pure virtual function.
// Virtual functions enable runtime polymorphism - the actual function called depends on
// the object's type, not the pointer/reference type. This provides a unified interface
// for payroll computation across different employee categories.
class Employee
{
    // Data members common to all employee types
    std::string name;
    int id;

public:
    Employee() : name(""), id(0) {}

    void setName(std::string name)
    {
        this->name = name;
    }

    std::string getName()
    {
        return name;
    }

    void setID(int id)
    {
        this->id = id;
    }

    int getID()
    {
        return id;
    }

    // Pure Virtual Function: calculatePay()
    // The "= 0" makes this an abstract method and the class abstract.
    // This forces derived classes to implement their own version of calculatePay().
    // Ensures every employee type must define how to calculate their pay.
    virtual double calculatePay() const = 0;
};

// Derived Class 1: SalariedEmployee
// Implements the virtual calculatePay() function for fixed-salary employees.
// Demonstrates how derived classes override virtual functions with their specific logic.
class SalariedEmployee : public Employee
{
    double salary;

public:
    SalariedEmployee() : salary(0) {}

    void setSalary(double salary)
    {
        this->salary = salary;
    }

    // Override: Implements the pure virtual calculatePay() from base class.
    // For salaried employees, pay is simply the fixed salary.
    // The "override" keyword explicitly indicates this implements the base class virtual function.
    double calculatePay() const override
    {
        return salary;
    }
};

// Derived Class 2: HourlyEmployee
// Implements the virtual calculatePay() function for hourly-wage employees.
// Demonstrates how different derived classes can have different implementations
// of the same virtual function.
class HourlyEmployee : public Employee
{
    double hoursWorked;
    double hourlyRate;

public:
    HourlyEmployee() : hoursWorked(0), hourlyRate(0) {}

    void setHoursWorked(double hw)
    {
        this->hoursWorked = hw;
    }

    double getHoursWorked()
    {
        return hoursWorked;
    }

    void setHourlyRate(double hr)
    {
        this->hourlyRate = hr;
    }

    double getHourlyRate()
    {
        return hourlyRate;
    }

    // Override: Implements the pure virtual calculatePay() from base class.
    // For hourly employees, pay is calculated as hourlyRate * hoursWorked.
    // This demonstrates polymorphism: same function name, different behavior based on object type.
    double calculatePay() const override
    {
        return hourlyRate * hoursWorked;
    }
};

int main()
{
    // Create specific derived class objects
    SalariedEmployee *emp1 = new SalariedEmployee();
    HourlyEmployee *emp2 = new HourlyEmployee();

    // Set salaried employee details
    emp1->setName("Yash");
    emp1->setID(01);
    emp1->setSalary(25000);

    // Set hourly employee details
    emp2->setName("Aryan");
    emp2->setID(02);
    emp2->setHourlyRate(100);
    emp2->setHoursWorked(120);

    // Display and calculate payroll information
    std::cout << "===============================================" << std::endl;
    std::cout << "Details of Salaried Employee :" << std::endl;
    std::cout << "Name : " << emp1->getName() << std::endl;
    std::cout << "ID : " << emp1->getID() << std::endl;
    std::cout << "Salary : " << emp1->calculatePay() << std::endl; // Polymorphic call

    std::cout << "===============================================" << std::endl;
    std::cout << "Details of Hourly Employee :" << std::endl;
    std::cout << "Name : " << emp2->getName() << std::endl;
    std::cout << "ID : " << emp2->getID() << std::endl;
    std::cout << "Hourly Pay (Hours * Rate) : " << emp2->calculatePay() << std::endl; // Polymorphic call
    std::cout << "===============================================" << std::endl;

    // Clean up dynamically allocated memory to prevent memory leaks
    delete emp1;
    delete emp2;

    return 0;
}