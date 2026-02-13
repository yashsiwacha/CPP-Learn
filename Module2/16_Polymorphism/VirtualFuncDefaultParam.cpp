#include <iostream>

// Base class Printer
class Printer
{
public:
    // Virtual function print() to print the input msg with defaulat parameter "Base Printer".
    virtual void print(const std::string &msg = "Base Printer")
    {
        std::cout << msg << std::endl;
    }
};

// Declaring the derieved class and inheriting the Printer class.
class ColorPrinter : public Printer
{
public:
    // Overriding the print() function and changing the default parameter to "Color Printer"
    void print(const std::string &msg = "Color Printer") override // Overriding the print function which changes the default parameter of this function only for the derieved class.
    {
        std::cout << msg << std::endl;
    }
};

// Main Function
int main()
{
    // ColorPrinter Object.
    ColorPrinter cp;
// Calling the print function with ColorPrint object .
std:;
    std::cout << "===============================================================" << std::endl;
    std::cout << "Calling the Print function with the ColorPrint class Object : " << std::endl;
    cp.print();

    // Initializing the Printer pointer with address of ColorPrint Object.
    std::cout << "===============================================================" << std::endl;
    std::cout << "Calling the Print function with the Printer class Pointer : " << std::endl;
    Printer *pr = &cp;
    // Calling the print function with the Printer Pointer.
    pr->print();
}
