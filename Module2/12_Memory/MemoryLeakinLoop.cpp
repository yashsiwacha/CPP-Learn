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
        cout << "Object " << objectId << " constructed\n";
    }

    ~LeakDemo()
    {
        cout << "Object " << objectId << " destructed\n";
    }
};

int main()
{
    cout << "\nMemory Leak Demo\n\n";

    cout << "Scenario 1: WITHOUT delete (Memory Leak)\n";
    int leakCount = 0;
    while (leakCount < 1000)
    {
        new LeakDemo(leakCount + 1);
        leakCount++;
    }
    cout << "Result: 1000 constructed, 0 destructed - Memory leaked\n\n";

    cout << "Scenario 2: WITH delete (No Leak)\n";
    int fixedCount = 0;
    while (fixedCount < 1000)
    {
        LeakDemo *objectPtr = new LeakDemo(fixedCount + 1);
        delete objectPtr;
        fixedCount++;
    }
    cout << "Result: 1000 constructed, 1000 destructed - No leak\n";

    return 0;
}