// Program to demonstrate multiple inheritance and polymorphic interface usage
#include <iostream>
using namespace std;

/**
 * INTERFACE: Printable
 * Defines a contract for objects that can be printed
 * Pure virtual function makes this an abstract base class
 */
class Printable
{
public:
    virtual void print() const = 0; // Pure virtual function
    virtual ~Printable() {}         // Virtual destructor for proper cleanup
};

/**
 * INTERFACE: Savable
 * Defines a contract for objects that can be saved
 * Pure virtual function makes this an abstract base class
 */
class Savable
{
public:
    virtual void save() const = 0; // Pure virtual function
    virtual ~Savable() {}          // Virtual destructor for proper cleanup
};

/**
 * CONCRETE CLASS: Document
 * Implements BOTH Printable and Savable interfaces (Multiple Inheritance)
 * Must provide implementations for all pure virtual functions
 */
class Document : public Printable, public Savable
{
private:
    string content;

public:
    Document(string c = "Empty Document") : content(c) {}

    // Implementation of Printable interface
    void print() const override
    {
        cout << "Printing the Document: " << content << endl;
    }

    // Implementation of Savable interface
    void save() const override
    {
        cout << "Saving the Document: " << content << endl;
    }
};

/**
 * MAIN FUNCTION - Demonstrating Polymorphic Interface Usage
 *
 * Key Concept: A single Document object can be accessed through different
 * interface pointers (Printable* or Savable*), demonstrating polymorphism
 * and the power of multiple inheritance.
 */
int main()
{
    cout << "========== POLYMORPHIC INTERFACE DEMONSTRATION ==========" << endl;
    cout << "\n--- Creating a Document object ---" << endl;
    Document doc("My Important Report");

    cout << "\n--- Direct method calls on Document object ---" << endl;
    doc.print();
    doc.save();

    cout << "\n--- Using Printable* pointer (Interface 1) ---" << endl;
    // Polymorphism: Document pointer converted to Printable pointer
    Printable *printPtr = &doc;
    printPtr->print(); // Calls Document's implementation of print()
    cout << "Note: Through Printable*, we can only access Printable interface methods." << endl;

    cout << "\n--- Using Savable* pointer (Interface 2) ---" << endl;
    // Polymorphism: Document pointer converted to Savable pointer
    Savable *savePtr = &doc;
    savePtr->save(); // Calls Document's implementation of save()
    cout << "Note: Through Savable*, we can only access Savable interface methods." << endl;

    cout << "\n--- Demonstrating the SAME object through BOTH interfaces ---" << endl;
    cout << "Address of Document object:  " << &doc << endl;
    cout << "Address via Printable*:      " << printPtr << endl;
    cout << "Address via Savable*:        " << savePtr << endl;
    cout << "\nKey Point: Same object, accessed via different interface pointers!" << endl;

    cout << "\n--- Creating a Document on the heap ---" << endl;
    Document *docPtr = new Document("Heap-allocated Document");

    // Using the same pointer as different interface types
    Printable *printInterface = docPtr;
    Savable *saveInterface = docPtr;

    cout << "Calling through Printable interface:" << endl;
    printInterface->print();

    cout << "Calling through Savable interface:" << endl;
    saveInterface->save();

    // Cleanup
    delete docPtr;

    cout << "\n========== SUMMARY ==========" << endl;
    cout << "Multiple Inheritance allows Document to implement multiple interfaces." << endl;
    cout << "Polymorphism allows the same object to be used via different interface pointers." << endl;
    cout << "This demonstrates the Interface Segregation Principle in C++." << endl;
    cout << "=========================================================" << endl;

    return 0;
}