// Memory leak detection test - tracks allocations and deallocations
#include <iostream>
#include <map>

using namespace std;

class Tracker
{
private:
    static int active_allocations;          // Count of currently allocated objects
    static map<void *, int> allocation_map; // Maps memory address to allocation ID

public:
    // Overloaded new operator - called when creating Tracker objects
    void *operator new(size_t size)
    {
        void *ptr = ::operator new(size); // Allocate memory
        ++active_allocations;             // Increment counter
        cout << "Allocated at " << ptr << ", active: " << active_allocations << endl;
        allocation_map[ptr] = active_allocations; // Track this allocation
        return ptr;
    }

    // Overloaded delete operator - called when deleting Tracker objects
    void operator delete(void *ptr)
    {
        if (ptr == nullptr)
            return;
        --active_allocations; // Decrement counter
        cout << "Freed at " << ptr << ", active: " << active_allocations << endl;
        allocation_map.erase(ptr); // Remove from tracking
        ::operator delete(ptr);    // Free memory
    }
};

// Initialize static members
int Tracker::active_allocations = 0;
map<void *, int> Tracker::allocation_map;

int main()
{
    cout << "Creating objects..." << endl;
    Tracker *t1 = new Tracker(); // Allocation 1
    Tracker *t2 = new Tracker(); // Allocation 2

    cout << "Deleting t1..." << endl;
    delete t1; // Free t1, t2 remains allocated

    // Program ends - t2 is never deleted (memory leak!)
    cout << "Program end. Active: " << Tracker::active_allocations << endl;
    return 0;
}
