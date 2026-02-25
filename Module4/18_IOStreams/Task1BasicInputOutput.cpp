// Program to demonstrate basic input and output operations in C++
#include <iostream>
#include <limits>
#include <string>

int main()
{
    // Variables to store user input values.
    std::string name;
    int age;
    std::string city;

    // std::cout prints a prompt to the console.
    // std::getline reads a full line (including spaces) for the name.
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);

    // std::cin reads numeric input for age.
    // Validation ensures the user enters a valid integer.
    std::cout << "Enter your age: ";
    while (!(std::cin >> age))
    {
        std::cout << "Invalid input. Please enter a valid integer for age: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // std::getline is used again so city names with spaces are read correctly.
    std::cout << "Enter your city: ";
    std::getline(std::cin, city);

    // Formatted output using std::cout.
    std::cout << "Hello " << name << ", you are " << age
              << " and live in " << city << "." << std::endl;

    return 0;
}