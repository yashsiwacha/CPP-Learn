/**
 * Diamond Problem in Multiple Inheritance (WITHOUT Virtual Inheritance)
 * 
 * This program demonstrates the diamond problem that occurs when:
 * - A class (Smartphone) inherits from two classes (Phone, Camera)
 * - Both intermediate classes inherit from the same base class (Device)
 * - WITHOUT using virtual inheritance
 * 
 * Result: Smartphone contains TWO separate copies of Device
 * This causes AMBIGUITY when accessing Device members
 * 
 * Inheritance Hierarchy:
 *        Device (id, showId())
 *       /      \
 *   Phone      Camera
 *       \      /
 *      Smartphone  <-- Contains 2 Device subobjects!
 * 
 * Topics Covered:
 * - The diamond problem in multiple inheritance
 * - Multiple copies of base class without virtual inheritance
 * - Ambiguity and compiler errors
 * - Why virtual inheritance is needed
 */

#include <iostream>
using namespace std;

// ==================== BASE CLASS ====================
/**
 * Device - Base class representing any electronic device
 */
class Device {
protected:
    int id;

public:
    Device() : id(0) {
        cout << "Device constructor called" << endl;
    }

    Device(int deviceId) : id(deviceId) {
        cout << "Device constructor called with id: " << id << endl;
    }

    void showId() {
        cout << "Device ID: " << id << endl;
    }

    void setId(int deviceId) {
        id = deviceId;
        cout << "Device ID set to: " << id << endl;
    }
};

// ==================== INTERMEDIATE CLASSES ====================
/**
 * Phone - Inherits from Device (NOT virtual)
 */
class Phone : public Device {
public:
    Phone() {
        cout << "Phone constructor called" << endl;
    }

    void makeCall() {
        cout << "Making a phone call from device " << id << endl;
    }
};

/**
 * Camera - Inherits from Device (NOT virtual)
 */
class Camera : public Device {
public:
    Camera() {
        cout << "Camera constructor called" << endl;
    }

    void takePhoto() {
        cout << "Taking a photo with device " << id << endl;
    }
};

// ==================== DERIVED CLASS (DIAMOND) ====================
/**
 * Smartphone - Inherits from BOTH Phone and Camera
 * WITHOUT virtual inheritance, this creates TWO Device subobjects!
 */
class Smartphone : public Phone, public Camera {
private:
    string model;

public:
    Smartphone(string m) : model(m) {
        cout << "Smartphone constructor called: " << model << endl;
        cout << "\n=== IMPORTANT: Smartphone now has TWO Device objects! ===" << endl;
        cout << "    - One from Phone::Device" << endl;
        cout << "    - One from Camera::Device" << endl;
    }

    void displayInfo() {
        cout << "\nSmartphone Model: " << model << endl;
    }
};

// ==================== MAIN DEMONSTRATION ====================
int main() {
    cout << "========================================" << endl;
    cout << "  DIAMOND PROBLEM DEMONSTRATION" << endl;
    cout << "  (WITHOUT Virtual Inheritance)" << endl;
    cout << "========================================\n" << endl;

    // Creating a Smartphone object
    cout << "Creating Smartphone object...\n" << endl;
    Smartphone myPhone("iPhone 15");

    cout << "\n========================================" << endl;
    cout << "  DEMONSTRATING THE AMBIGUITY PROBLEM" << endl;
    cout << "========================================\n" << endl;

    // ==================== PROBLEM 1: Ambiguous Member Access ====================
    cout << "PROBLEM 1: Direct member access is AMBIGUOUS\n" << endl;
    cout << "// The following line would cause COMPILER ERROR:" << endl;
    cout << "// myPhone.id = 101;" << endl;
    cout << "// Error: 'id' is ambiguous - which Device::id? Phone's or Camera's?\n" << endl;

    // Uncommenting the next line will cause a COMPILER ERROR
    // myPhone.id = 101;  // ERROR: request for member 'id' is ambiguous

    // ==================== PROBLEM 2: Ambiguous Function Call ====================
    cout << "PROBLEM 2: Member function call is AMBIGUOUS\n" << endl;
    cout << "// The following line would cause COMPILER ERROR:" << endl;
    cout << "// myPhone.showId();" << endl;
    cout << "// Error: 'showId' is ambiguous - which Device::showId()?\n" << endl;

    // Uncommenting the next line will cause a COMPILER ERROR
    // myPhone.showId();  // ERROR: request for member 'showId' is ambiguous

    // ==================== PROBLEM 3: Ambiguous setId Call ====================
    cout << "PROBLEM 3: Setting ID is AMBIGUOUS\n" << endl;
    cout << "// The following line would cause COMPILER ERROR:" << endl;
    cout << "// myPhone.setId(202);" << endl;
    cout << "// Error: 'setId' is ambiguous\n" << endl;

    // Uncommenting the next line will cause a COMPILER ERROR
    // myPhone.setId(202);  // ERROR: request for member 'setId' is ambiguous

    // ==================== SOLUTION: Use Scope Resolution ====================
    cout << "\n========================================" << endl;
    cout << "  WORKAROUND: Using Scope Resolution" << endl;
    cout << "========================================\n" << endl;

    cout << "We must specify WHICH Device subobject to use:\n" << endl;

    // Access Phone's Device subobject
    cout << "1. Accessing Phone's Device:" << endl;
    myPhone.Phone::setId(101);
    myPhone.Phone::showId();

    cout << "\n2. Accessing Camera's Device:" << endl;
    myPhone.Camera::setId(202);
    myPhone.Camera::showId();

    cout << "\n3. Both IDs are DIFFERENT because they're separate objects:" << endl;
    cout << "   Phone's Device ID:  ";
    myPhone.Phone::showId();
    cout << "   Camera's Device ID: ";
    myPhone.Camera::showId();

    // ==================== DEMONSTRATING TWO SEPARATE OBJECTS ====================
    cout << "\n========================================" << endl;
    cout << "  PROOF: TWO SEPARATE Device OBJECTS" << endl;
    cout << "========================================\n" << endl;

    cout << "Memory addresses prove they are different objects:" << endl;
    cout << "Phone::Device address:  " << (void*)static_cast<Device*>(static_cast<Phone*>(&myPhone)) << endl;
    cout << "Camera::Device address: " << (void*)static_cast<Device*>(static_cast<Camera*>(&myPhone)) << endl;
    cout << "\nNotice: Different addresses = Different objects!\n" << endl;

    // ==================== EXPLAINING THE PROBLEM ====================
    cout << "========================================" << endl;
    cout << "  WHY IS THIS A PROBLEM?" << endl;
    cout << "========================================\n" << endl;

    cout << "Issues with Diamond Problem (without virtual inheritance):" << endl;
    cout << "1. MEMORY WASTE: Two copies of Device data (id stored twice)" << endl;
    cout << "2. AMBIGUITY: Compiler doesn't know which Device to use" << endl;
    cout << "3. INCONSISTENCY: Phone's id and Camera's id can be different!" << endl;
    cout << "4. AWKWARD SYNTAX: Must use scope resolution (Phone::, Camera::)" << endl;
    cout << "5. LOGICAL ERROR: A smartphone should have ONE device ID, not two!\n" << endl;

    // ==================== THE SOLUTION ====================
    cout << "========================================" << endl;
    cout << "  THE SOLUTION: Virtual Inheritance" << endl;
    cout << "========================================\n" << endl;

    cout << "To fix this, we need VIRTUAL INHERITANCE:" << endl;
    cout << "\nChange this:" << endl;
    cout << "    class Phone : public Device { ... };" << endl;
    cout << "    class Camera : public Device { ... };" << endl;
    cout << "\nTo this:" << endl;
    cout << "    class Phone : public virtual Device { ... };" << endl;
    cout << "    class Camera : public virtual Device { ... };" << endl;
    cout << "\nResult:" << endl;
    cout << "- Only ONE Device subobject in Smartphone" << endl;
    cout << "- No ambiguity" << endl;
    cout << "- No scope resolution needed" << endl;
    cout << "- Logical correctness: One device = One ID\n" << endl;

    // ==================== VISUAL REPRESENTATION ====================
    cout << "========================================" << endl;
    cout << "  VISUAL REPRESENTATION" << endl;
    cout << "========================================\n" << endl;

    cout << "WITHOUT virtual inheritance (current):" << endl;
    cout << "    Device(id)     Device(id)" << endl;
    cout << "        |              |" << endl;
    cout << "      Phone          Camera" << endl;
    cout << "        \\              /" << endl;
    cout << "         Smartphone" << endl;
    cout << "  (TWO Device objects!)\n" << endl;

    cout << "WITH virtual inheritance (solution):" << endl;
    cout << "         Device(id)" << endl;
    cout << "        /          \\" << endl;
    cout << "      Phone        Camera" << endl;
    cout << "        \\          /" << endl;
    cout << "         Smartphone" << endl;
    cout << "  (ONE shared Device object)\n" << endl;

    // ==================== PRACTICAL DEMONSTRATION ====================
    cout << "========================================" << endl;
    cout << "  PRACTICAL DEMONSTRATION" << endl;
    cout << "========================================\n" << endl;

    cout << "Let's see the inconsistency in action:\n" << endl;

    myPhone.Phone::setId(999);
    myPhone.Camera::setId(111);

    cout << "\nNow when we call methods:" << endl;
    cout << "makeCall() uses Phone's Device with id = ";
    myPhone.Phone::showId();
    
    cout << "takePhoto() uses Camera's Device with id = ";
    myPhone.Camera::showId();

    cout << "\nThis is ILLOGICAL! The same smartphone has two different IDs!" << endl;
    cout << "This is why virtual inheritance is essential.\n" << endl;

    // ==================== SUMMARY ====================
    cout << "========================================" << endl;
    cout << "  KEY TAKEAWAYS" << endl;
    cout << "========================================\n" << endl;

    cout << "1. Diamond Problem occurs when:" << endl;
    cout << "   - Multiple inheritance is used" << endl;
    cout << "   - Two parent classes share a common base" << endl;
    cout << "   - WITHOUT virtual inheritance" << endl;
    cout << "\n2. Without virtual inheritance:" << endl;
    cout << "   - Multiple copies of base class are created" << endl;
    cout << "   - Causes ambiguity in member access" << endl;
    cout << "   - Wastes memory" << endl;
    cout << "   - Creates logical inconsistencies" << endl;
    cout << "\n3. Solution:" << endl;
    cout << "   - Use 'virtual' keyword in inheritance" << endl;
    cout << "   - Ensures only ONE shared base class object" << endl;
    cout << "   - Eliminates ambiguity" << endl;
    cout << "   - Maintains logical correctness" << endl;
    cout << "\n4. Next Step:" << endl;
    cout << "   - See VirtualInheritanceTask2.cpp for the solution" << endl;

    cout << "\n========================================" << endl;
    cout << "  PROGRAM COMPLETE" << endl;
    cout << "========================================" << endl;

    return 0;
}

/**
 * COMPILER ERRORS YOU WOULD SEE:
 * 
 * If you uncomment the ambiguous lines, you'll see errors like:
 * 
 * error: request for member 'id' is ambiguous
 * note: candidates are:
 *   - int Device::id [inherited via Phone]
 *   - int Device::id [inherited via Camera]
 * 
 * error: request for member 'showId' is ambiguous
 * note: candidates are:
 *   - void Device::showId() [inherited via Phone]
 *   - void Device::showId() [inherited via Camera]
 * 
 * These errors clearly show the diamond problem in action!
 */
