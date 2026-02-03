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
        cout << "Allocated at " << ptr << ", active: " << active_allocations << "\n";
        allocation_map[ptr] = active_allocations; // Track this allocation
        return ptr;
    }

    // Overloaded delete operator - called when deleting Tracker objects
    void operator delete(void *ptr)
    {
        if (ptr == nullptr)
            return;
        --active_allocations; // Decrement counter
        cout << "Freed at " << ptr << ", active: " << active_allocations << "\n";
        allocation_map.erase(ptr); // Remove from tracking
        ::operator delete(ptr);    // Free memory
    }
};

// Initialize static members
int Tracker::active_allocations = 0;
map<void *, int> Tracker::allocation_map;

int main()
{
    cout << "Creating objects...\n";
    Tracker *t1 = new Tracker();
    Tracker *t2 = new Tracker();

    cout << "Deleting t1...\n";
    delete t1;

    cout << "Program end. Active: " << Tracker::active_allocations << " (leaked t2)\n";
    return 0;
}
