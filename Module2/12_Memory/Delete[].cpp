// Program to demonstrate difference between deletion of dynamically allocated integers and arrays in C++
#include <iostream>
using namespace std;

class Item
{
    string name;

public:
    // Constructor - called when object is created
    Item(string n = "Default")
    {
        this->name = n;
        cout << "Object " << this->name << " constructed\n";
    }

    ~Item()
    {
        cout << "Object " << this->name << " destructed\n";
    }
}; // Missing semicolon fixed

int main()
{
    // Single object allocation
    Item *ptr = new Item("Item1");

    // Array allocation - cannot use initializer list with array of objects
    // Objects will be default-constructed
    Item *arr = new Item[5];

    // Delete single object
    delete ptr;

    // Delete array of objects - calls destructor for each element
    delete[] arr;

    return 0;
}