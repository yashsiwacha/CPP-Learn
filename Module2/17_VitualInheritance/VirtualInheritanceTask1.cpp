#include <iostream>

/*
========================================================
PART 1 — DIAMOND PROBLEM (AMBIGUITY DEMONSTRATION)
========================================================

Inheritance structure:

        Device
        /    \
     Phone  Camera
        \    /
      SmartPhone

Problem:
SmartPhone inherits TWO copies of Device —
one through Phone and one through Camera.

This causes ambiguity when accessing members of Device.
*/

class Device
{
public:
    int id;   // Unique identifier for a device

    // Constructor initializes id
    Device() : id(100) {}

    // Function to display id
    void showId()
    {
        std::cout << "Device ID: " << id << std::endl;
    }
};

// Phone inherits Device
class Phone : public Device
{
    // Phone gets its own copy of Device
};

// Camera also inherits Device
class Camera : public Device
{
    // Camera gets another copy of Device
};

// SmartPhone inherits both Phone and Camera
// → This creates TWO Device subobjects
class SmartPhone : public Phone, public Camera
{
};



/*
========================================================
PART 2 — FIXING THE DIAMOND PROBLEM
(VIRTUAL INHERITANCE)
========================================================

By using virtual inheritance:

        Device (shared)
        /            \
     VPhone        VCamera
        \            /
       VSmartPhone

Now SmartPhone contains ONLY ONE Device object.
No ambiguity occurs.
*/

class VDevice
{
public:
    int id;

    // Constructor initializes shared id
    VDevice() : id(200) {}

    void showId()
    {
        std::cout << "Shared Device ID: " << id << std::endl;
    }
};

// Virtual inheritance ensures only one base instance exists
class VPhone : virtual public VDevice {};
class VCamera : virtual public VDevice {};

// No duplication of VDevice here
class VSmartPhone : public VPhone, public VCamera {};



int main()
{
    std::cout << "=== Diamond Problem Demonstration ===\n\n";

    SmartPhone s;

    /*
    The following lines would cause a compiler error
    because the compiler cannot decide which Device to use:

        s.id;
        s.showId();

    Uncomment to see ambiguity error.
    */

    // std::cout << s.id << std::endl;
    // s.showId();

    // Manual disambiguation using inheritance path
    std::cout << "Resolving ambiguity manually:\n";

    std::cout << "Phone path ID: "
              << s.Phone::id << std::endl;

    std::cout << "Camera path ID: "
              << s.Camera::id << std::endl;

    // Explicitly specify which base class to use
    s.Phone::showId();
    s.Camera::showId();


    std::cout << "\n=== Diamond Problem Fixed ===\n\n";

    VSmartPhone vs;

    /*
    No ambiguity now —
    only ONE shared VDevice exists.
    */

    std::cout << vs.id << std::endl;
    vs.showId();

    return 0;
}
