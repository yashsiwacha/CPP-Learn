//Program to demonstrate static members in C++
#include <iostream>
using namespace std;

//Declaring the Counter class to demonstrate the static member in C++.
// Static members belong to the class itself, not to individual objects.
// They are shared across ALL objects of the class.
class Counter{
    //Declaring the static int count which we are going to use as a indicator of the scope of the class.
    // Static member: shared by all Counter objects, tracks total active objects
    static int count;
    int objectID;  // Individual object identifier (non-static, unique per object)
public:
    //Declaring the constructor and deconstructor.
    Counter(){
        count++;//Incrementing the int count everytime the constructor is called to create a object.
        objectID = count;  // Assign unique ID based on creation order
        cout << "✓ Constructor called - Object #" << objectID << " created (Total active: " << count << ")" << endl;
        cout.flush();  // Force output to display immediately (useful for debugging)
    }
    ~Counter(){
        // Destructor is called AUTOMATICALLY when object goes out of scope
        // IMPORTANT: Decrement first, THEN show the count to display accurate remaining count
        count--;//Decrementing the int count everytime the object goes out of scope.
        cout << "✗ Destructor called - Object #" << objectID << " destroyed (Remaining active: " << count << ")" << endl;
        cout.flush();  // Force output to display immediately
    }
    void getCount();//Declaring a function to print the count int.
};

int Counter::count = 0;//Initializing the int count outside the class Counter with a value of 0.
// IMPORTANT: Static members MUST be initialized outside the class definition.
// This allocates actual memory for the static variable that all objects share.

void Counter::getCount(){
    cout << "📊 Current active objects: " << count << endl;//Declaring the body of function get count outside the class.
    // This static function can be called even without creating an object: Counter::getCount()
}

//Main Function
int main(){
    cout << "\n=== Starting Program ===" << endl;
    
    cout << "\n1. Creating first object 'counter':" << endl;
    Counter counter;//Calling the constructor to create a object of Counter class.
    counter.getCount();//Calling the getCount to print the current value of the int count
    
    cout << "\n2. Entering local scope { }:" << endl;
    {//Creating a local scope to see if the destructor decriments the int count or not after getting out of scope.
        cout << "   Creating second object 'c1' inside scope:" << endl;
        Counter c1;//Calling the constructor to create a object of Counter class.
        counter.getCount();//Calling the getCount to print the current value of the int count
        cout << "   Exiting scope - watch c1 destructor!" << endl;
    }// c1 destructor is AUTOMATICALLY called here when scope ends
    
    cout << "\n3. After exiting scope (c1 destroyed):" << endl;
    counter.getCount();//Calling the getCount to print the current value of the int count after the c1 goes out of scope
    
    cout << "\n4. Creating third object 'c2':" << endl;
    Counter c2;//Calling the constructor to create a object of Counter class.
    counter.getCount();//Calling the getCount to print the current value of the int count
    
    cout << "\n5. Exiting main() - watch remaining destructors!" << endl;
    cout << "   (Destructors called in REVERSE order of construction: c2, then counter)" << endl;
    return 0;
    // Both 'counter' and 'c2' destructors are AUTOMATICALLY called here (in reverse order: c2, then counter)
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
