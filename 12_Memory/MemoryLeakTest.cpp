// Simple test version
#include <iostream>
#include <map>

using namespace std;

class Tracker
{
private:
    static int active_allocations;
    static map<void *, int> allocation_map;

public:
    void *operator new(size_t size)
    {
        void *ptr = ::operator new(size);
        ++active_allocations;
        cout << "Allocated at " << ptr << ", active: " << active_allocations << endl;
        allocation_map[ptr] = active_allocations;
        return ptr;
    }

    void operator delete(void *ptr)
    {
        if (ptr == nullptr)
            return;
        --active_allocations;
        cout << "Freed at " << ptr << ", active: " << active_allocations << endl;
        allocation_map.erase(ptr);
        ::operator delete(ptr);
    }
};

int Tracker::active_allocations = 0;
map<void *, int> Tracker::allocation_map;

int main()
{
    cout << "Creating objects..." << endl;
    Tracker *t1 = new Tracker();
    Tracker *t2 = new Tracker();

    cout << "Deleting t1..." << endl;
    delete t1;

    cout << "Program end. Active: " << Tracker::active_allocations << endl;
    return 0;
}
