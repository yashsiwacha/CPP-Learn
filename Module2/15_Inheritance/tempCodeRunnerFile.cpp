/*
 * Library Management System - Demonstrating Core OOP Principles
 *
 * This program demonstrates three fundamental Object-Oriented Programming principles:
 *
 * 1. ABSTRACTION: The abstract base class 'Item' provides a common interface for all library items.
 *    - It defines what operations are available (display, getters, setters) without exposing implementation details.
 *    - The pure virtual function display() enforces that all derived classes must provide their own implementation.
 *
 * 2. ENCAPSULATION: Data members are kept private and accessed through public methods.
 *    - Private data members (title, id, pages, issue, duration) are hidden from outside access.
 *    - Public getter and setter methods provide controlled access with validation.
 *    - This protects data integrity by preventing invalid states.
 *
 * 3. INHERITANCE: Book, Magazine, and DVD inherit common properties from Item.
 *    - Derived classes reuse code from the base class (avoiding duplication).
 *    - Each derived class extends the base class with specific attributes.
 *    - Polymorphism allows treating different types uniformly through base class pointers.
 */

#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/*
 * ABSTRACTION: Abstract Base Class 'Item'
 *
 * This class serves as an interface for all library items, defining:
 * - Common attributes (title, id)
 * - Common behavior (setters, getters, display)
 * - Abstract contract (pure virtual display() function)
 *
 * The pure virtual display() function makes this class abstract, meaning:
 * - No objects of type Item can be created directly
 * - All derived classes MUST implement display()
 * - This enforces a consistent interface across all library items
 */
class Item
{
    // ENCAPSULATION: Private data members protect internal state
    // These can only be accessed through public methods below
    string title;
    int id;

public:
    // Default constructor initializes members to safe default values
    Item() : title(""), id(0) {}

    // Setter with validation to ensure data integrity
    bool setTitle(string title)
    {
        if (title.empty())
        {
            cout << "[Validation Error] Title cannot be empty." << endl;
            return false;
        }
        this->title = title;
        return true;
    }

    // Const getter ensures this method doesn't modify the object
    string getTitle() const
    {
        return this->title;
    }

    // Setter with validation for ID
    bool setID(int id)
    {
        if (id <= 0)
        {
            cout << "[Validation Error] ID must be a positive integer." << endl;
            return false;
        }
        this->id = id;
        return true;
    }

    // Const getter for ID
    int getID() const
    {
        return this->id;
    }

    // ABSTRACTION: Pure virtual function (= 0) creates an abstract interface
    // This forces all derived classes to implement their own display() method
    // This is the cornerstone of polymorphism in this design
    virtual void display() const = 0;

    // Virtual destructor ensures proper cleanup of derived class objects
    // When deleting through a base class pointer, this ensures the derived destructor is called
    virtual ~Item() = default;
};

/*
 * INHERITANCE: Book class inherits from Item
 *
 * This demonstrates:
 * - Code reuse: Book inherits title and id from Item
 * - Extension: Book adds its own specific attribute (pages)
 * - Polymorphism: Book can be treated as an Item through base class pointers
 * - Contract fulfillment: Book implements the required display() method
 */
class Book : public Item
{
    // ENCAPSULATION: Private member specific to Book
    int pages;

public:
    // Constructor initializes pages to a safe default value
    Book() : pages(0) {}

    // ENCAPSULATION: Setter with enhanced validation
    // Returns bool to indicate success/failure for better error handling
    bool setPages(int pages)
    {
        // Validation: Pages must be positive (zero is not valid for a book)
        if (pages <= 0)
        {
            cout << "[Validation Error] Pages must be a positive integer (current attempt: "
                 << pages << ")." << endl;
            return false;
        }
        this->pages = pages;
        return true;
    }

    // Const getter protects data from modification
    int getPages() const
    {
        return this->pages;
    }

    // POLYMORPHISM: Override the pure virtual function from base class
    // This provides Book-specific implementation while maintaining the common interface
    void display() const override
    {
        cout << "=== BOOK ===" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Pages: " << getPages() << endl;
    }
};

/*
 * INHERITANCE: Magazine class inherits from Item
 *
 * Similar to Book, but with magazine-specific attributes (issue number)
 * This shows how inheritance allows us to create related but distinct types
 * while maintaining a common interface through the base class.
 */
class Magazine : public Item
{
    // ENCAPSULATION: Private member specific to Magazine
    int issue;

public:
    // Constructor initializes issue to a safe default value
    Magazine() : issue(0) {}

    // ENCAPSULATION: Setter with validation
    bool setIssue(int issue)
    {
        // Validation: Issue number must be positive
        if (issue <= 0)
        {
            cout << "[Validation Error] Issue number must be a positive integer (current attempt: "
                 << issue << ")." << endl;
            return false;
        }
        this->issue = issue;
        return true;
    }

    // Const getter for issue number
    int getIssue() const
    {
        return this->issue;
    }

    // POLYMORPHISM: Magazine-specific implementation of display()
    void display() const override
    {
        cout << "=== MAGAZINE ===" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Issue Number: " << getIssue() << endl;
    }
};

/*
 * INHERITANCE: DVD class inherits from Item
 *
 * Demonstrates the extensibility of the design:
 * - New item types can be easily added by inheriting from Item
 * - DVD has its own specific attribute (duration in minutes)
 * - Works seamlessly with the polymorphic container in main()
 */
class DVD : public Item
{
    // ENCAPSULATION: Private member specific to DVD
    double duration; // Duration in minutes

public:
    // Constructor initializes duration to a safe default value
    DVD() : duration(0.0) {}

    // ENCAPSULATION: Setter with validation
    bool setDuration(double duration)
    {
        // Validation: Duration must be positive (zero duration is invalid)
        if (duration <= 0.0)
        {
            cout << "[Validation Error] Duration must be a positive number (current attempt: "
                 << duration << ")." << endl;
            return false;
        }
        this->duration = duration;
        return true;
    }

    // Const getter for duration
    double getDuration() const
    {
        return this->duration;
    }

    // POLYMORPHISM: DVD-specific implementation of display()
    void display() const override
    {
        cout << "=== DVD ===" << endl;
        cout << "Title: " << getTitle() << endl;
        cout << "ID: " << getID() << endl;
        cout << "Duration: " << getDuration() << " minutes" << endl;
    }
};

/*
 * Main Function - Demonstrating Polymorphism
 *
 * This function showcases the power of polymorphism:
 * 1. A vector of base class pointers (unique_ptr<Item>) stores different derived types
 * 2. All derived objects can be treated uniformly through the common Item interface
 * 3. Runtime polymorphism ensures the correct display() method is called for each object
 *
 * Benefits of this design:
 * - New item types can be added without changing existing code
 * - Items can be managed collectively in a single container
 * - The interface is consistent across all item types
 */
int main()
{
    cout << "=====================================" << endl;
    cout << "  LIBRARY MANAGEMENT SYSTEM" << endl;
    cout << "  Demonstrating OOP Principles" << endl;
    cout << "=====================================" << endl
         << endl;

    // POLYMORPHISM: Vector of base class pointers holds different derived types
    // unique_ptr provides automatic memory management (RAII principle)
    vector<unique_ptr<Item>> items;

    // Better approach: Create and configure objects before adding to vector
    // This avoids the need for casting by working with the derived type directly

    cout << "--- Setting up Book ---" << endl;
    auto book = make_unique<Book>();
    book->setTitle("C++ Programming");
    book->setID(1);
    book->setPages(255);
    items.push_back(std::move(book)); // Transfer ownership to vector
    cout << "Book setup complete.\n"
         << endl;

    cout << "--- Setting up Magazine ---" << endl;
    auto magazine = make_unique<Magazine>();
    magazine->setTitle("Tech Magazine");
    magazine->setID(2);
    magazine->setIssue(2055);
    items.push_back(std::move(magazine)); // Transfer ownership to vector
    cout << "Magazine setup complete.\n"
         << endl;

    cout << "--- Setting up DVD ---" << endl;
    auto dvd = make_unique<DVD>();
    dvd->setTitle("Tutorial DVD");
    dvd->setID(3);
    dvd->setDuration(25.45);
    items.push_back(std::move(dvd)); // Transfer ownership to vector
    cout << "DVD setup complete.\n"
         << endl;

    cout << "=====================================" << endl;
    cout << "  LIBRARY ITEMS DISPLAY" << endl;
    cout << "=====================================" << endl
         << endl;

    // POLYMORPHISM IN ACTION: Call display() through base class pointers
    // The correct derived class version is called at runtime (dynamic dispatch)
    for (const auto &ptr : items)
    {
        ptr->display(); // Polymorphic call - executes the correct derived class method
        cout << "-------------------------------------" << endl
             << endl;
    }

    // Demonstrate validation by attempting to set invalid values
    cout << "=====================================" << endl;
    cout << "  VALIDATION DEMONSTRATION" << endl;
    cout << "=====================================" << endl
         << endl;

    cout << "Attempting to set invalid values to test validation:\n"
         << endl;

    cout << "1. Trying to set negative pages for a book:" << endl;
    Book testBook;
    testBook.setPages(-50);
    cout << endl;

    cout << "2. Trying to set zero issue number for a magazine:" << endl;
    Magazine testMagazine;
    testMagazine.setIssue(0);
    cout << endl;

    cout << "3. Trying to set negative duration for a DVD:" << endl;
    DVD testDVD;
    testDVD.setDuration(-10.5);
    cout << endl;

    cout << "4. Trying to set zero ID:" << endl;
    testBook.setID(0);
    cout << endl;

    cout << "5. Trying to set empty title:" << endl;
    testBook.setTitle("");
    cout << endl;

    cout << "=====================================" << endl;
    cout << "All validations work correctly!" << endl;
    cout << "=====================================" << endl;

    return 0;
}