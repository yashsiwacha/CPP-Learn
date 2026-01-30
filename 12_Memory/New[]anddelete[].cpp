// Program to Compare C++ Memory Management (new[]/delete[]) vs C Memory Management (malloc/free)
// This program demonstrates the key differences between the two approaches

#include <iostream>
#include <cstdlib> // For malloc and free
#include <cstring> // For memset

using namespace std;

// ============================================================================
// DEMO CLASS: To demonstrate constructor/destructor behavior differences
// ============================================================================
class Element
{
private:
    int value;

public:
    // Constructor - ONLY called with new[], NOT with malloc
    Element() : value(0)
    {
        cout << "    [Constructor called for Element at " << this << "]" << endl;
    }

    // Parameterized constructor
    Element(int val) : value(val)
    {
        cout << "    [Constructor called for Element with value " << val << "]" << endl;
    }

    // Destructor - ONLY called with delete[], NOT with free
    ~Element()
    {
        cout << "    [Destructor called for Element at " << this << " with value " << value << "]" << endl;
    }

    // Setter method
    void setValue(int val) { value = val; }

    // Getter method
    int getValue() const { return value; }

    // Display method
    void display() const
    {
        cout << value << " ";
    }
};

// ============================================================================
// FUNCTION PROTOTYPES
// ============================================================================
void demonstrate_cpp_memory_management();
void demonstrate_c_memory_management();
void demonstrate_constructor_destructor_difference();

// ============================================================================
// MAIN FUNCTION
// ============================================================================
int main()
{
    cout << "\n";
    cout << "========================================================================" << endl;
    cout << "   COMPARISON: C++ (new[]/delete[]) vs C (malloc/free)" << endl;
    cout << "========================================================================" << endl;
    cout << "\n";

    // Part 1: Demonstrate C++ memory management (new[] and delete[])
    demonstrate_cpp_memory_management();

    cout << "\n"
         << string(70, '-') << "\n"
         << endl;

    // Part 2: Demonstrate C memory management (malloc and free)
    demonstrate_c_memory_management();

    cout << "\n"
         << string(70, '-') << "\n"
         << endl;

    // Part 3: Demonstrate constructor/destructor behavior difference
    demonstrate_constructor_destructor_difference();

    cout << "\n";
    cout << "========================================================================" << endl;
    cout << "                        SUMMARY OF KEY DIFFERENCES" << endl;
    cout << "========================================================================" << endl;
    cout << "\n";
    cout << "1. TYPE SAFETY:" << endl;
    cout << "   - new[]: Type-safe, no casting needed" << endl;
    cout << "   - malloc: Returns void*, requires explicit type casting" << endl;
    cout << "\n";
    cout << "2. CONSTRUCTOR/DESTRUCTOR:" << endl;
    cout << "   - new[]: Automatically calls constructors for each element" << endl;
    cout << "   - malloc: Only allocates raw memory, no constructors called" << endl;
    cout << "   - delete[]: Automatically calls destructors for each element" << endl;
    cout << "   - free: Only deallocates memory, no destructors called" << endl;
    cout << "\n";
    cout << "3. INITIALIZATION:" << endl;
    cout << "   - new[]: Can initialize array with values directly" << endl;
    cout << "   - malloc: Memory is uninitialized, requires manual initialization" << endl;
    cout << "\n";
    cout << "4. SIZE CALCULATION:" << endl;
    cout << "   - new[]: Automatically calculates size based on type" << endl;
    cout << "   - malloc: Requires explicit size calculation using sizeof()" << endl;
    cout << "\n";
    cout << "5. FAILURE HANDLING:" << endl;
    cout << "   - new[]: Throws std::bad_alloc exception on failure" << endl;
    cout << "   - malloc: Returns NULL on failure" << endl;
    cout << "\n";
    cout << "6. OPERATOR OVERLOADING:" << endl;
    cout << "   - new[]/delete[]: Can be overloaded for custom behavior" << endl;
    cout << "   - malloc/free: Cannot be overloaded" << endl;
    cout << "\n";
    cout << "========================================================================" << endl;
    cout << "\n";

    return 0;
}

// ============================================================================
// FUNCTION: Demonstrate C++ Memory Management (new[] and delete[])
// ============================================================================
void demonstrate_cpp_memory_management()
{
    cout << ">>> C++ MEMORY MANAGEMENT USING new[] AND delete[] <<<" << endl;
    cout << "\n";

    // Define array size (easy to change for testing)
    const int SIZE = 5;

    cout << "Step 1: Allocating array using new[]" << endl;
    cout << "  Syntax: int *arr = new int[SIZE]{values};" << endl;
    cout << "  - Type-safe: Returns int*, no casting required" << endl;
    cout << "  - Initialization: Can initialize with values directly" << endl;
    cout << "  - Size calculation: Automatic based on type" << endl;
    cout << "\n";

    // Allocate memory using new[] with initialization
    int *arr_cpp = new int[SIZE]{10, 20, 30, 40, 50};

    cout << "  Memory allocated successfully!" << endl;
    cout << "  Array address: " << arr_cpp << endl;
    cout << "  Size allocated: " << SIZE << " integers (" << (SIZE * sizeof(int)) << " bytes)" << endl;
    cout << "\n";

    cout << "Step 2: Displaying array elements" << endl;
    cout << "  [C++ METHOD] Elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr_cpp[i];
        if (i < SIZE - 1)
            cout << ", ";
    }
    cout << endl;
    cout << "\n";

    cout << "Step 3: Modifying array elements" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        arr_cpp[i] = arr_cpp[i] * 2;
    }
    cout << "  Modified elements (doubled): ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr_cpp[i];
        if (i < SIZE - 1)
            cout << ", ";
    }
    cout << endl;
    cout << "\n";

    cout << "Step 4: Deallocating memory using delete[]" << endl;
    cout << "  Syntax: delete[] arr;" << endl;
    cout << "  - Properly deallocates array memory" << endl;
    cout << "  - Must use delete[] for arrays (not delete)" << endl;
    cout << "\n";

    delete[] arr_cpp;
    arr_cpp = nullptr; // Good practice: set pointer to nullptr after deletion

    cout << "  Memory deallocated successfully!" << endl;
    cout << "  Pointer set to nullptr for safety" << endl;
}

// ============================================================================
// FUNCTION: Demonstrate C Memory Management (malloc and free)
// ============================================================================
void demonstrate_c_memory_management()
{
    cout << ">>> C MEMORY MANAGEMENT USING malloc AND free <<<" << endl;
    cout << "\n";

    // Define array size (easy to change for testing)
    const int SIZE = 5;

    cout << "Step 1: Allocating array using malloc" << endl;
    cout << "  Syntax: int *arr = (int*)malloc(SIZE * sizeof(int));" << endl;
    cout << "  - Type casting REQUIRED: malloc returns void*" << endl;
    cout << "  - Manual size calculation: Must use sizeof()" << endl;
    cout << "  - No initialization: Memory contains garbage values" << endl;
    cout << "\n";

    // Allocate memory using malloc
    // IMPORTANT: Explicit type casting (int*) is REQUIRED
    int *arr_c = (int *)malloc(SIZE * sizeof(int));

    // Check if allocation was successful (malloc returns NULL on failure)
    if (arr_c == NULL)
    {
        cout << "  ERROR: Memory allocation failed!" << endl;
        return;
    }

    cout << "  Memory allocated successfully!" << endl;
    cout << "  Array address: " << arr_c << endl;
    cout << "  Size allocated: " << SIZE << " integers (" << (SIZE * sizeof(int)) << " bytes)" << endl;
    cout << "\n";

    cout << "Step 2: Initializing array elements manually" << endl;
    cout << "  NOTE: malloc does NOT initialize memory" << endl;
    cout << "  We must manually assign values to each element" << endl;

    // Manual initialization (required with malloc)
    int values[] = {10, 20, 30, 40, 50};
    for (int i = 0; i < SIZE; i++)
    {
        arr_c[i] = values[i];
    }

    cout << "\n";
    cout << "Step 3: Displaying array elements" << endl;
    cout << "  [C METHOD] Elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr_c[i];
        if (i < SIZE - 1)
            cout << ", ";
    }
    cout << endl;
    cout << "\n";

    cout << "Step 4: Modifying array elements" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        arr_c[i] = arr_c[i] * 2;
    }
    cout << "  Modified elements (doubled): ";
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr_c[i];
        if (i < SIZE - 1)
            cout << ", ";
    }
    cout << endl;
    cout << "\n";

    cout << "Step 5: Deallocating memory using free" << endl;
    cout << "  Syntax: free(arr);" << endl;
    cout << "  - Deallocates memory allocated by malloc" << endl;
    cout << "  - No need for free[] (unlike delete[])" << endl;
    cout << "\n";

    free(arr_c);
    arr_c = nullptr; // Good practice: set pointer to nullptr after freeing

    cout << "  Memory deallocated successfully!" << endl;
    cout << "  Pointer set to nullptr for safety" << endl;
}

// ============================================================================
// FUNCTION: Demonstrate Constructor/Destructor Behavior Difference
// ============================================================================
void demonstrate_constructor_destructor_difference()
{
    cout << ">>> CONSTRUCTOR/DESTRUCTOR BEHAVIOR DIFFERENCE <<<" << endl;
    cout << "\n";

    const int SIZE = 3;

    // ========================================================================
    // Part A: Using new[] - Constructors and Destructors ARE called
    // ========================================================================
    cout << "PART A: Using new[] with custom class (Element)" << endl;
    cout << "  - Constructors WILL be called for each element" << endl;
    cout << "  - Destructors WILL be called when delete[] is used" << endl;
    cout << "\n";

    cout << "  Allocating array of " << SIZE << " Element objects using new[]..." << endl;
    Element *obj_array_cpp = new Element[SIZE];

    cout << "\n  Setting values..." << endl;
    for (int i = 0; i < SIZE; i++)
    {
        obj_array_cpp[i].setValue((i + 1) * 100);
    }

    cout << "\n  Displaying elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        obj_array_cpp[i].display();
    }
    cout << "\n\n  Deallocating with delete[]..." << endl;
    delete[] obj_array_cpp;

    cout << "\n  OBSERVE: Destructors were automatically called!" << endl;

    // ========================================================================
    // Part B: Using malloc - Constructors and Destructors are NOT called
    // ========================================================================
    cout << "\n"
         << string(70, '.') << "\n"
         << endl;
    cout << "PART B: Using malloc with custom class (Element)" << endl;
    cout << "  - Constructors will NOT be called" << endl;
    cout << "  - Destructors will NOT be called when free is used" << endl;
    cout << "  WARNING: This is UNSAFE for classes with constructors/destructors!" << endl;
    cout << "\n";

    cout << "  Allocating memory for " << SIZE << " Element objects using malloc..." << endl;
    // IMPORTANT: This is generally a BAD PRACTICE for classes!
    // malloc only allocates raw memory without calling constructors
    Element *obj_array_c = (Element *)malloc(SIZE * sizeof(Element));

    if (obj_array_c == NULL)
    {
        cout << "  ERROR: Memory allocation failed!" << endl;
        return;
    }

    cout << "  Memory allocated (but NO constructors called!)" << endl;
    cout << "\n  NOTE: Objects are in uninitialized state" << endl;
    cout << "  We must manually call setValue() to initialize" << endl;

    for (int i = 0; i < SIZE; i++)
    {
        // Must use placement new or direct member access to initialize
        obj_array_c[i].setValue((i + 1) * 200);
    }

    cout << "\n  Displaying elements: ";
    for (int i = 0; i < SIZE; i++)
    {
        obj_array_c[i].display();
    }

    cout << "\n\n  Deallocating with free()..." << endl;
    free(obj_array_c);
    cout << "  Memory freed (but NO destructors called!)" << endl;

    cout << "\n  OBSERVE: No destructor messages appeared!" << endl;
    cout << "  This is why malloc/free should NOT be used with C++ classes!" << endl;
}