// Program to demonstrate memory leak in a loop in C++
#include <iostream>
using namespace std;

class LeakDemo
{
private:
    int objectId; // Instance-specific ID to track each object

public:
    // Constructor with object ID parameter
    LeakDemo(int id) : objectId(id)
    {
        cout << "The Object " << objectId << " is constructed." << endl;
    }

    ~LeakDemo()
    {
        cout << "The Object " << objectId << " is destructed." << endl;
    }
};

int main()
{
    cout << "\n========================================" << endl;
    cout << "   MEMORY LEAK DEMONSTRATION" << endl;
    cout << "========================================\n"
         << endl;

    // ===== SCENARIO 1: WITH MEMORY LEAK =====
    cout << "--- SCENARIO 1: Creating Objects WITHOUT delete (MEMORY LEAK) ---" << endl;
    cout << "Explanation: When we use 'new' without 'delete', memory is allocated" << endl;
    cout << "but never freed. This causes memory leak.\n"
         << endl;

    int leakCount = 0;
    while (leakCount < 1000)
    {
        new LeakDemo(leakCount + 1); // Memory allocated but never freed!
                                     // Pointer is lost immediately after creation
                                     // No way to delete this object later
        leakCount++;
    }

    cout << "\n--- RESULT OF SCENARIO 1 ---" << endl;
    cout << "Notice: You see 1000 'constructed' messages but 0 'destructed' messages!" << endl;
    cout << "This means 1000 objects are created in memory but never destroyed." << endl;
    cout << "Memory used: ~" << (1000 * sizeof(LeakDemo)) << " bytes leaked!\n"
         << endl;

    // ===== SCENARIO 2: WITHOUT MEMORY LEAK =====
    cout << "\n--- SCENARIO 2: Creating Objects WITH delete (NO MEMORY LEAK) ---" << endl;
    cout << "Explanation: We store the pointer returned by 'new' and call 'delete'" << endl;
    cout << "This properly frees the memory after use.\n"
         << endl;

    int fixedCount = 0;

    while (fixedCount < 1000)
    {
        LeakDemo *objectPtr = new LeakDemo(fixedCount + 1); // Store the pointer with unique ID
        delete objectPtr;                                   // Free the memory
                                                            // Destructor is called, memory is released
        fixedCount++;
    }

    cout << "\n--- RESULT OF SCENARIO 2 ---" << endl;
    cout << "Notice: You see 1000 'constructed' AND 1000 'destructed' messages!" << endl;
    cout << "Each object is properly cleaned up. No memory leak!" << endl;
    cout << "Memory used: 0 bytes leaked (all memory properly freed)\n"
         << endl;

    return 0;
}