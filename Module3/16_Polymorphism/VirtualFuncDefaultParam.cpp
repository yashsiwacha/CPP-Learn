#include <iostream>

// Base class Printer
class Printer
{
public:
    // Virtual function print() to print the input msg with default parameter "Base Printer".
    // Note: default arguments are bound at compile time (based on the static type).
    virtual void print(const std::string &msg = "Base Printer")
    {
        std::cout << msg << std::endl;
    }
};

// Declaring the derived class and inheriting the Printer class.
class ColorPrinter : public Printer
{
public:
    // Overriding the print() function and changing the default parameter to "Color Printer".
    // The default argument here applies only when the call is resolved with static type ColorPrinter.
    void print(const std::string &msg = "Color Printer") override
    {
        std::cout << msg << std::endl;
    }
};

// Main Function
int main()
{
    // ColorPrinter Object.
    ColorPrinter cp;
    // Calling the print function with ColorPrinter object.
    std::cout << "===============================================================" << std::endl;
    std::cout << "Call site: ColorPrinter object (static type ColorPrinter)" << std::endl;
    std::cout << "Expected default arg: Color Printer" << std::endl;
    cp.print();

    // Initializing the Printer pointer with address of ColorPrint Object.
    std::cout << "===============================================================" << std::endl;
    std::cout << "Call site: Printer pointer (static type Printer)" << std::endl;
    std::cout << "Expected default arg: Base Printer" << std::endl;
    Printer *pr = &cp;
    // Calling the print function with the Printer Pointer.
    // Note: virtual dispatch happens at runtime, so ColorPrinter::print is called,
    // but the default argument is still chosen at compile time from Printer.
    pr->print();
}
