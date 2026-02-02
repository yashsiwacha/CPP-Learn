// Program demonstrating deep copy vs shallow copy
#include <iostream>
#include <cstring>
using namespace std;

class DynamicArray
{
private:
    int *data;
    int size;

public:
    DynamicArray(int s = 5) : size(s)
    {
        cout << "\n[Constructor] Allocating memory for " << size << " integers..." << endl;
        data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = (i + 1) * 10;
        }

        cout << "[Constructor] Memory allocated at address: " << data << endl;
        cout << "[Constructor] Array initialized with values: ";
        display();
    }

    // Copy Constructor - Deep Copy
    DynamicArray(const DynamicArray &source)
    {
        cout << "\n[Copy Constructor] Creating deep copy..." << endl;

        size = source.size;
        data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = source.data[i];
        }

        cout << "[Copy Constructor] New memory allocated at: " << data << endl;
        cout << "[Copy Constructor] Source memory was at: " << source.data << endl;
        cout << "[Copy Constructor] Deep copy completed successfully!" << endl;
    }

    ~DynamicArray()
    {
        cout << "\n[Destructor] Releasing memory at address: " << data << endl;
        delete[] data;
        cout << "[Destructor] Memory freed successfully!" << endl;
    }

    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void modify(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            data[index] = value;
        }
    }

    int *getAddress() const
    {
        return data;
    }
};

class ShallowArray
{
private:
    int *data;
    int size;

public:
    // Default Constructor
    ShallowArray(int s = 5) : size(s)
    {
        cout << "\n[Shallow Constructor] Allocating memory for " << size << " integers..." << endl;
        data = new int[size];

        for (int i = 0; i < size; i++)
        {
            data[i] = (i + 1) * 100; // 100, 200, 300, 400, 500
        }

        cout << "[Shallow Constructor] Memory at: " << data << endl;
    }

    // NO COPY CONSTRUCTOR DEFINED!
    // Compiler generates default copy constructor which does SHALLOW COPY
    // This means it copies the pointer value, not the data!

    // Destructor
    ~ShallowArray()
    {
        cout << "\n[Shallow Destructor] Attempting to free memory at: " << data << endl;
        delete[] data; // DANGER! May cause double-free error!
        cout << "[Shallow Destructor] Memory freed!" << endl;
    }

    void display() const
    {
        for (int i = 0; i < size; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }

    void modify(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            data[index] = value;
        }
    }

    int *getAddress() const
    {
        return data;
    }
};

// ============================================================================
// DEMONSTRATION FUNCTIONS
// ============================================================================

void demonstrateDeepCopy()
{
    cout << "\n========================================" << endl;
    cout << "DEMONSTRATION 1: DEEP COPY (SAFE)" << endl;
    cout << "========================================" << endl;

    cout << "\n--- Creating original object (obj1) ---" << endl;
    DynamicArray obj1(5);

    cout << "\n--- Creating copy using copy constructor (obj2) ---" << endl;
    DynamicArray obj2 = obj1; // Copy constructor is called

    cout << "\n--- Verifying memory addresses ---" << endl;
    cout << "obj1 data address: " << obj1.getAddress() << endl;
    cout << "obj2 data address: " << obj2.getAddress() << endl;
    cout << "Are they different? " << (obj1.getAddress() != obj2.getAddress() ? "YES (Good!)" : "NO (Bad!)") << endl;

    cout << "\n--- Initial values ---" << endl;
    cout << "obj1: ";
    obj1.display();
    cout << "obj2: ";
    obj2.display();

    cout << "\n--- Modifying obj1 (changing index 2 to 999) ---" << endl;
    obj1.modify(2, 999);

    cout << "\n--- After modification ---" << endl;
    cout << "obj1: ";
    obj1.display();
    cout << "obj2: ";
    obj2.display();
    cout << "\nNotice: obj2 is NOT affected! This is DEEP COPY." << endl;

    cout << "\n--- Objects will be destroyed when going out of scope ---" << endl;
    // Destructors will be called automatically
}

void demonstrateShallowCopy()
{
    cout << "\n\n========================================" << endl;
    cout << "DEMONSTRATION 2: SHALLOW COPY (DANGEROUS!)" << endl;
    cout << "========================================" << endl;

    cout << "\n--- Creating original object (sObj1) ---" << endl;
    ShallowArray sObj1(5);

    cout << "\n--- Creating copy using DEFAULT copy constructor (sObj2) ---" << endl;
    ShallowArray sObj2 = sObj1; // Default copy constructor (shallow copy!)

    cout << "\n--- Verifying memory addresses ---" << endl;
    cout << "sObj1 data address: " << sObj1.getAddress() << endl;
    cout << "sObj2 data address: " << sObj2.getAddress() << endl;
    cout << "Are they the SAME? " << (sObj1.getAddress() == sObj2.getAddress() ? "YES (PROBLEM!)" : "NO") << endl;

    cout << "\n⚠️  WARNING: Both objects point to the SAME memory!" << endl;

    cout << "\n--- Initial values ---" << endl;
    cout << "sObj1: ";
    sObj1.display();
    cout << "sObj2: ";
    sObj2.display();

    cout << "\n--- Modifying sObj1 (changing index 2 to 777) ---" << endl;
    sObj1.modify(2, 777);

    cout << "\n--- After modification ---" << endl;
    cout << "sObj1: ";
    sObj1.display();
    cout << "sObj2: ";
    sObj2.display();
    cout << "\n⚠️  DANGER: sObj2 is also affected! They share the same memory!" << endl;

    cout << "\n--- Objects will be destroyed when going out of scope ---" << endl;
    cout << "⚠️  CRITICAL PROBLEM: Both destructors will try to delete the SAME memory!" << endl;
    cout << "⚠️  This causes DOUBLE-FREE error (Undefined Behavior)!" << endl;
    // When this function ends, BOTH destructors will try to free the same memory!
    // This is a DOUBLE-FREE bug - very dangerous!
}

void demonstrateCopyInFunction()
{
    cout << "\n\n========================================" << endl;
    cout << "DEMONSTRATION 3: COPY IN FUNCTION CALLS" << endl;
    cout << "========================================" << endl;

    // Lambda function that takes object by value (makes a copy)
    auto processArray = [](DynamicArray arr)
    {
        cout << "\n[Inside Function] Object copied into function parameter" << endl;
        cout << "[Inside Function] Array address: " << arr.getAddress() << endl;
        cout << "[Inside Function] Modifying the copy..." << endl;
        arr.modify(0, 555);
        cout << "[Inside Function] Modified array: ";
        arr.display();
        cout << "[Inside Function] Function ending, copy will be destroyed..." << endl;
    };

    cout << "\n--- Creating original object ---" << endl;
    DynamicArray original(3);
    cout << "Original address: " << original.getAddress() << endl;
    cout << "Original array: ";
    original.display();

    cout << "\n--- Passing to function by value (triggers copy constructor) ---" << endl;
    processArray(original);

    cout << "\n--- Back in main, checking original object ---" << endl;
    cout << "Original address: " << original.getAddress() << endl;
    cout << "Original array: ";
    original.display();
    cout << "\nNotice: Original is unchanged! Copy constructor protected it." << endl;
}

// ============================================================================
// MAIN FUNCTION
// ============================================================================

int main()
{
    cout << "╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║     COPY CONSTRUCTOR & DEEP COPY DEMONSTRATION        ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;

    // Demonstration 1: Proper deep copy with user-defined copy constructor
    demonstrateDeepCopy();

    cout << "\n\n"
         << string(60, '=') << endl;
    cout << "Press Enter to continue to Shallow Copy demonstration..." << endl;
    cin.get();

    // Demonstration 2: Shallow copy problem (compiler-generated copy constructor)
    demonstrateShallowCopy();

    cout << "\n\n"
         << string(60, '=') << endl;
    cout << "Press Enter to continue to Function Call demonstration..." << endl;
    cin.get();

    // Demonstration 3: Copy constructor in function calls
    demonstrateCopyInFunction();

    // Summary
    cout << "\n\n╔════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    KEY TAKEAWAYS                       ║" << endl;
    cout << "╚════════════════════════════════════════════════════════╝" << endl;
    cout << "\n1. SHALLOW COPY (Default):" << endl;
    cout << "   - Copies pointer values, not the data" << endl;
    cout << "   - Multiple objects point to SAME memory" << endl;
    cout << "   - Causes: double-free, data corruption, crashes" << endl;

    cout << "\n2. DEEP COPY (User-Defined Copy Constructor):" << endl;
    cout << "   - Allocates NEW memory for each object" << endl;
    cout << "   - Copies data values, not pointer addresses" << endl;
    cout << "   - Each object has its OWN independent memory" << endl;
    cout << "   - Safe and prevents memory errors" << endl;

    cout << "\n3. RULE OF THREE:" << endl;
    cout << "   If your class needs ONE of these, it needs ALL THREE:" << endl;
    cout << "   - Destructor" << endl;
    cout << "   - Copy Constructor" << endl;
    cout << "   - Copy Assignment Operator" << endl;

    cout << "\n4. WHEN TO DEFINE COPY CONSTRUCTOR:" << endl;
    cout << "   - Class manages dynamic memory (new/delete)" << endl;
    cout << "   - Class owns resources (file handles, network connections)" << endl;
    cout << "   - Default shallow copy would be dangerous" << endl;

    cout << "\n5. SYNTAX:" << endl;
    cout << "   ClassName(const ClassName& source) {" << endl;
    cout << "       // Allocate new memory" << endl;
    cout << "       // Copy data from source" << endl;
    cout << "   }" << endl;

    cout << "\n\n"
         << string(60, '=') << endl;
    cout << "Program completed successfully!" << endl;
    cout << string(60, '=') << endl;

    return 0;
}

/*
 * EXPECTED OUTPUT EXPLANATION:
 * ============================
 *
 * Deep Copy (Safe):
 * - Two different memory addresses for obj1 and obj2
 * - Modifying one doesn't affect the other
 * - Clean destruction without double-free
 *
 * Shallow Copy (Dangerous):
 * - Same memory address for both objects
 * - Modifying one affects the other
 * - Double-free error when both destructors run
 *
 * Function Call:
 * - Copy constructor called when passing by value
 * - Function gets its own copy with separate memory
 * - Original remains unaffected
 *
 * COMMON INTERVIEW QUESTIONS:
 * ==========================
 * 1. What is the difference between shallow and deep copy?
 * 2. When do you need to define a copy constructor?
 * 3. What is the Rule of Three?
 * 4. What happens if you don't define a copy constructor for a class with dynamic memory?
 * 5. How does pass-by-value trigger the copy constructor?
 *
 * PRACTICE EXERCISES:
 * ==================
 * 1. Add a copy assignment operator to DynamicArray class
 * 2. Implement a String class with dynamic char array
 * 3. Create a LinkedList class with proper deep copy
 * 4. Add move constructor for better performance
 * 5. Implement Rule of Five (with move semantics)
 */
