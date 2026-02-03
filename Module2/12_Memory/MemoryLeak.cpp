// Program demonstrating memory leak detection
#include <iostream>
#include <map>
using namespace std;

class Tracker
{
private:
    static int allocation_count;
    static int deallocation_count;
    static int active_allocations;
    static map<void *, int> allocation_map;
    int object_id;
    static int object_id_counter;

public:
    Tracker() : object_id(++object_id_counter)
    {
        cout << "Created Tracker #" << object_id << "\n";
    }

    ~Tracker()
    {
        cout << "Destroyed Tracker #" << object_id << "\n";
    }

    void *operator new(size_t size)
    {
        void *ptr = ::operator new(size);
        ++allocation_count;
        ++active_allocations;
        allocation_map[ptr] = allocation_count;
        cout << "Allocated " << size << " bytes at " << ptr << " (active: " << active_allocations << ")\n";
        return ptr;
    }

    void operator delete(void *ptr)
    {
        if (ptr == nullptr)
            return;

        ++deallocation_count;
        --active_allocations;
        allocation_map.erase(ptr);
        cout << "Freed memory at " << ptr << " (active: " << active_allocations << ")\n";
        ::operator delete(ptr);
    }

    static void display_leak_report()
    {
        cout << "\n--- Memory Leak Report ---\n";
        cout << "Allocations: " << allocation_count << "\n";
        cout << "Deallocations: " << deallocation_count << "\n";
        cout << "Active: " << active_allocations << "\n";

        if (active_allocations > 0)
        {
            cout << "\nWARNING: " << active_allocations << " memory leak(s) detected!\n";
            for (const auto &pair : allocation_map)
                cout << "  Allocation #" << pair.second << " at " << pair.first << " not freed\n";
        }
        else
        {
            cout << "\nNo memory leaks detected\n";
        }
    }

    int get_id() const { return object_id; }
};

// Initialize static members
int Tracker::allocation_count = 0;
int Tracker::deallocation_count = 0;
int Tracker::active_allocations = 0;
int Tracker::object_id_counter = 0;
map<void *, int> Tracker::allocation_map;

int main()
{
    cout << "Memory Leak Detection Demo\n\n";

    // Allocate objects
    Tracker *t1 = new Tracker();
    Tracker *t2 = new Tracker();
    Tracker *t3 = new Tracker();
    Tracker *t4 = new Tracker();
    Tracker *t5 = new Tracker();

    cout << "\nDeleting t1, t2, t4...\n";
    delete t1;
    delete t2;
    delete t4;

    cout << "\nIntentionally NOT deleting t3 and t5 (memory leak simulation)\n";

    // Display leak report
    Tracker::display_leak_report();

    return 0;
}