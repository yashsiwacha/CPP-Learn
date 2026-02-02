// Program demonstrating destructors and object lifetime
#include <iostream>
#include <string>
using namespace std;

class DynamicArray
{
private:
    int *arr;
    int size;
    int id;
    static int objectCount;

public:
    DynamicArray()
    {
        objectCount++;
        id = objectCount;
        size = 5;
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }

        cout << "✓ Constructor called for DynamicArray[" << id << "] - Created array of size " << size << endl;
    }

    DynamicArray(int s)
    {
        objectCount++;
        id = objectCount;
        size = s;
        arr = new int[size];

        for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }

        cout << "✓ Parameterized Constructor called for DynamicArray[" << id << "] - Created array of size " << size << endl;
    }

    ~DynamicArray()
    {
        cout << "✗ Destructor called for DynamicArray[" << id << "] - Freeing memory for array of size " << size << endl;
        delete[] arr;
        arr = nullptr;
    }

    void setValue(int index, int value)
    {
        if (index >= 0 && index < size)
        {
            arr[index] = value;
        }
    }

    void display() const
    {
        cout << "  DynamicArray[" << id << "]: [";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i];
            if (i < size - 1)
                cout << ", ";
        }
        cout << "]" << endl;
    }

    int getID() const
    {
        return id;
    }
};

int DynamicArray::objectCount = 0;

void demoStackArrayDestruction()
{
    cout << "\n=== Demo 1: Stack-Allocated Array of Objects ===" << endl;
    cout << "Creating array of 3 DynamicArray objects...\n"
         << endl;

    DynamicArray arr[3];

    cout << "\n--- All objects created. Now populating with data ---\n"
         << endl;

    // Populate arrays with some data
    arr[0].setValue(0, 10);
    arr[0].setValue(1, 20);
    arr[1].setValue(0, 100);
    arr[1].setValue(1, 200);
    arr[2].setValue(0, 1000);
    arr[2].setValue(1, 2000);

    // Display array contents
    cout << "Array contents:" << endl;
    arr[0].display();
    arr[1].display();
    arr[2].display();

    cout << "\n--- Function scope ending. Watch destruction order! ---\n"
         << endl;
    // Destructors will be called in REVERSE order: arr[2], arr[1], arr[0]
    // This is Last-In-First-Out (LIFO) order
}

// ============================================================================
// Function 2: Demonstrate mixed object lifetimes
// ============================================================================
void demoMixedObjectLifetimes()
{
    cout << "\n=== Demo 2: Mixed Object Lifetimes ===" << endl;
    cout << "Creating objects with different scopes...\n"
         << endl;

    // Object 1: Created at function scope
    DynamicArray obj1(3);
    obj1.setValue(0, 1);

    cout << "\nEntering inner scope..." << endl;
    {
        // Object 2: Created in inner scope
        DynamicArray obj2(4);
        obj2.setValue(0, 2);

        cout << "\nInside inner scope - both objects exist:" << endl;
        obj1.display();
        obj2.display();

        cout << "\nExiting inner scope..." << endl;
        // obj2 will be destroyed here when inner scope ends
    }

    cout << "\nBack in outer scope - obj2 is destroyed, obj1 still exists:" << endl;
    obj1.display();

    cout << "\nExiting function scope..." << endl;
    // obj1 will be destroyed here when function scope ends
}

// ============================================================================
// Function 3: Demonstrate heap vs stack allocation
// ============================================================================
void demoHeapVsStack()
{
    cout << "\n=== Demo 3: Heap vs Stack Allocation ===" << endl;

    // Stack allocation - automatic cleanup
    cout << "\nCreating stack-allocated object:" << endl;
    DynamicArray stackObj(2);
    stackObj.setValue(0, 42);

    // Heap allocation - manual cleanup required
    cout << "\nCreating heap-allocated object:" << endl;
    DynamicArray *heapObj = new DynamicArray(2);
    heapObj->setValue(0, 99);

    cout << "\nBoth objects exist:" << endl;
    stackObj.display();
    heapObj->display();

    // Manual deletion of heap object
    cout << "\nManually deleting heap object:" << endl;
    delete heapObj; // Destructor called explicitly

    cout << "\nExiting function - stack object will be destroyed automatically:" << endl;
    // stackObj destructor will be called automatically
}

// ============================================================================
// Function 4: Demonstrate parameterized array creation
// ============================================================================
void demoParameterizedArrays()
{
    cout << "\n=== Demo 4: Array of Objects with Different Sizes ===" << endl;
    cout << "Creating array of DynamicArray objects with different sizes...\n"
         << endl;

    // Create multiple objects
    DynamicArray small(2);
    DynamicArray medium(5);
    DynamicArray large(10);

    small.setValue(0, 1);
    medium.setValue(0, 100);
    large.setValue(0, 1000);

    cout << "\nDisplaying all arrays:" << endl;
    small.display();
    medium.display();
    large.display();

    cout << "\nFunction ending - destruction order will be: large, medium, small" << endl;
    // Destructors called in reverse order of construction
}

// ============================================================================
// Main function - Orchestrates all demonstrations
// ============================================================================
int main()
{
    cout << "╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║   Destructors & Object Lifetime Demonstration in C++      ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;

    // Demo 1: Stack array destruction order
    demoStackArrayDestruction();
    cout << "\n"
         << string(60, '-') << endl;

    // Demo 2: Mixed object lifetimes with nested scopes
    demoMixedObjectLifetimes();
    cout << "\n"
         << string(60, '-') << endl;

    // Demo 3: Heap vs Stack allocation differences
    demoHeapVsStack();
    cout << "\n"
         << string(60, '-') << endl;

    // Demo 4: Array of objects with different sizes
    demoParameterizedArrays();
    cout << "\n"
         << string(60, '-') << endl;

    cout << "\n╔════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    Program Complete                        ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════╝" << endl;

    cout << "\n📚 Key Learnings:" << endl;
    cout << "1. Destructors are called automatically when objects go out of scope" << endl;
    cout << "2. Destruction order is REVERSE of construction order (LIFO)" << endl;
    cout << "3. Stack objects have automatic lifetime management" << endl;
    cout << "4. Heap objects require explicit deletion with 'delete' keyword" << endl;
    cout << "5. Destructors are essential for proper resource cleanup" << endl;
    cout << "6. Nested scopes demonstrate deterministic destruction patterns" << endl;

    return 0;
}

/*
 * EXPECTED OUTPUT PATTERN:
 *
 * For stack array of 3 objects:
 * - Construction: obj[0] → obj[1] → obj[2]
 * - Destruction:  obj[2] → obj[1] → obj[0]  (REVERSE order)
 *
 * IMPORTANT CONCEPTS:
 *
 * 1. DESTRUCTOR SYNTAX:
 *    ~ClassName() { // cleanup code }
 *    - Same name as class with ~ prefix
 *    - No parameters, no return type
 *    - Called automatically
 *
 * 2. WHEN DESTRUCTORS ARE CALLED:
 *    - Stack objects: When scope ends
 *    - Heap objects: When 'delete' is called
 *    - Array objects: In reverse order of creation
 *
 * 3. WHY REVERSE ORDER MATTERS:
 *    - Later objects may depend on earlier objects
 *    - Ensures proper cleanup of dependencies
 *    - Mirrors construction order inversely
 *
 * 4. RESOURCE MANAGEMENT:
 *    - Destructors free dynamically allocated memory
 *    - Prevents memory leaks
 *    - RAII (Resource Acquisition Is Initialization) principle
 *
 * 5. STACK vs HEAP:
 *    - Stack: Automatic, fast, limited size
 *    - Heap: Manual, flexible size, requires delete
 *    - Stack objects have deterministic lifetime
 */
