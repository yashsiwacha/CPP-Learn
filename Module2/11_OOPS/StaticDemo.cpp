// Program to demonstrate static members in C++
#include <iostream>
using namespace std;

class Counter
{
    static int count;
    int objectID;

public:
    Counter()
    {
        count++;
        objectID = count;
        cout << "Constructor called - Object #" << objectID << " created (Total: " << count << ")\n";
        cout.flush();
    }
    ~Counter()
    {
        count--;
        cout << "Destructor called - Object #" << objectID << " destroyed (Remaining: " << count << ")\n";
        cout.flush();
    }
    void getCount();
};

int Counter::count = 0;

void Counter::getCount()
{
    cout << "Current active objects: " << count << "\n";
}

int main()
{
    cout << "\n=== Starting Program ===" << endl;

    cout << "\n1. Creating first object 'counter':" << endl;
    Counter counter;
    counter.getCount();

    cout << "\n2. Entering local scope { }:" << endl;
    {
        cout << "   Creating second object 'c1' inside scope:" << endl;
        Counter c1;
        counter.getCount();
        cout << "   Exiting scope - watch c1 destructor!" << endl;
    }

    cout << "\n3. After exiting scope (c1 destroyed):" << endl;
    counter.getCount();

    cout << "\n4. Creating third object 'c2':" << endl;
    Counter c2;
    counter.getCount();

    cout << "\n5. Exiting main() - watch remaining destructors!" << endl;
    cout << "   (Destructors called in REVERSE order of construction: c2, then counter)" << endl;
    return 0;
}

/*
 * KEY LEARNING POINTS:
 *
 * 1. STATIC MEMBERS are shared across ALL objects of a class
 *    - Only ONE copy exists in memory, not one per object
 *    - Useful for tracking class-wide information (like object count)
 *
 * 2. STATIC MEMBER INITIALIZATION must happen outside the class
 *    - Format: type ClassName::staticMember = value;
 *
 * 3. DESTRUCTOR TIMING:
 *    - Called AUTOMATICALLY when object goes out of scope
 *    - Stack objects: destroyed in REVERSE order of creation
 *    - Essential for proper resource cleanup and accurate counting
 *
 * 4. OBJECT LIFETIME & SCOPE:
 *    - Local scope { }: Objects destroyed at closing brace
 *    - Function scope: Objects destroyed when function exits
 *    - Demonstrates deterministic destruction (RAII principle)
 *
 * EXPECTED OUTPUT PATTERN:
 * - constructor → count increases
 * - Scope ends → destructor → count decreases
 * - Final count should be 0 when program exits
 */
