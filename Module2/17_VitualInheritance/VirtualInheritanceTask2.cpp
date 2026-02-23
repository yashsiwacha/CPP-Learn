//
// Created by YashSiwach on 17-02-2026.
//
/**
 * Virtual Inheritance - Solution to Diamond Problem
 *
 * This program demonstrates how VIRTUAL INHERITANCE solves the diamond problem:
 * - A class (Smartphone) inherits from two classes (Phone, Camera)
 * - Both intermediate classes inherit from the same base class (Device)
 * - WITH virtual inheritance keyword
 *
 * Result: Smartphone contains ONLY ONE shared copy of Device
 * No ambiguity when accessing Device members
 *
 * Inheritance Hierarchy WITH Virtual Inheritance:
 *           Device (id, showId())
 *          /      \
 *         /        \
 *    Phone          Camera
 *    (virtual)      (virtual)
 *         \        /
 *          \      /
 *        Smartphone  <-- Contains ONLY 1 Device subobject!
 *
 * Topics Covered:
 * - Virtual inheritance syntax
 * - Resolving base class ambiguity in multiple inheritance
 * - Single shared base subobject in derived class
 * - Practical demonstration of virtual inheritance benefits
 */

#include <iostream>
#include <iomanip>
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
        cout << "Device default constructor called" << endl;
    }

    Device(int deviceId) : id(deviceId) {
        cout << "Device parameterized constructor called with id: " << id << endl;
    }

    void showId() {
        cout << "Device ID: " << id << endl;
    }

    void setId(int deviceId) {
        id = deviceId;
        cout << "Device ID set to: " << id << endl;
    }

    int getId() const {
        return id;
    }
};

// ==================== INTERMEDIATE CLASSES WITH VIRTUAL INHERITANCE ====================
/**
 * Phone - Inherits from Device using VIRTUAL inheritance
 * Key: "virtual public Device" ensures only one Device subobject
 */
class Phone : virtual public Device {
private:
    string phoneNumber;

public:
    Phone() : phoneNumber("") {
        cout << "Phone constructor called" << endl;
    }

    Phone(string number) : phoneNumber(number) {
        cout << "Phone constructor called with number: " << phoneNumber << endl;
    }

    void makeCall() {
        cout << "Making a phone call from device " << id << endl;
    }

    void setPhoneNumber(string number) {
        phoneNumber = number;
    }

    string getPhoneNumber() const {
        return phoneNumber;
    }
};

/**
 * Camera - Inherits from Device using VIRTUAL inheritance
 * Key: "virtual public Device" ensures only one Device subobject
 */
class Camera : virtual public Device {
private:
    int megapixels;

public:
    Camera() : megapixels(0) {
        cout << "Camera constructor called" << endl;
    }

    Camera(int mp) : megapixels(mp) {
        cout << "Camera constructor called with " << megapixels << " MP" << endl;
    }

    void takePhoto() {
        cout << "Taking a photo with device " << id << " (" << megapixels << " MP)" << endl;
    }

    void setMegapixels(int mp) {
        megapixels = mp;
    }

    int getMegapixels() const {
        return megapixels;
    }
};

// ==================== DERIVED CLASS (DIAMOND WITH VIRTUAL INHERITANCE) ====================
/**
 * Smartphone - Inherits from BOTH Phone and Camera
 * WITH virtual inheritance in Phone and Camera, this creates ONLY ONE Device subobject!
 *
 * Important: When using virtual inheritance, the most derived class (Smartphone)
 * is responsible for initializing the virtual base class (Device)
 */
class Smartphone : public Phone, public Camera {
private:
    string model;
    string os;

public:
    // Constructor must explicitly initialize the virtual base class (Device)
    Smartphone() : Device(), Phone(), Camera(), model("Unknown"), os("Unknown") {
        cout << "Smartphone default constructor called" << endl;
        cout << "\n=== IMPORTANT: Smartphone has only ONE Device object! ===" << endl;
        cout << "    - Phone and Camera share the same Device subobject" << endl;
        cout << "    - No ambiguity when accessing Device members" << endl;
    }

    Smartphone(int deviceId, string m, string operatingSystem, string number, int mp)
        : Device(deviceId),  // Most derived class initializes virtual base
          Phone(number),
          Camera(mp),
          model(m),
          os(operatingSystem) {
        cout << "Smartphone parameterized constructor called: " << model << endl;
        cout << "\n=== Virtual Inheritance Success! ===" << endl;
        cout << "    - Only ONE Device object created" << endl;
        cout << "    - Device ID " << deviceId << " is shared by Phone and Camera" << endl;
    }

    void displayInfo() {
        cout << "\n========================================" << endl;
        cout << "  SMARTPHONE INFORMATION" << endl;
        cout << "========================================" << endl;
        cout << "Model:        " << model << endl;
        cout << "OS:           " << os << endl;
        cout << "Device ID:    " << id << endl;  // Direct access - NO AMBIGUITY!
        cout << "Phone Number: " << getPhoneNumber() << endl;
        cout << "Camera:       " << getMegapixels() << " MP" << endl;
        cout << "========================================" << endl;
    }

    void useAllFeatures() {
        cout << "\nDemonstrating all features:" << endl;
        showId();      // Direct call - NO AMBIGUITY!
        makeCall();
        takePhoto();
    }
};

// ==================== MAIN DEMONSTRATION ====================
int main() {
    cout << "========================================" << endl;
    cout << "  VIRTUAL INHERITANCE DEMONSTRATION" << endl;
    cout << "  (Diamond Problem SOLVED)" << endl;
    cout << "========================================\n" << endl;

    // ==================== CREATING SMARTPHONE WITH VIRTUAL INHERITANCE ====================
    cout << "Creating Smartphone object with virtual inheritance...\n" << endl;
    Smartphone myPhone(12345, "iPhone 15 Pro", "iOS 17", "+1-555-0100", 48);

    cout << "\n========================================" << endl;
    cout << "  NO AMBIGUITY WITH VIRTUAL INHERITANCE" << endl;
    cout << "========================================\n" << endl;

    // ==================== DIRECT ACCESS WITHOUT AMBIGUITY ====================
    cout << "1. Direct member access (NO ambiguity):" << endl;
    cout << "   Accessing id directly: myPhone.id = " << myPhone.getId() << endl;

    cout << "\n2. Modifying id directly:" << endl;
    myPhone.setId(99999);  // NO AMBIGUITY! No scope resolution needed!

    cout << "\n3. Calling showId() directly:" << endl;
    myPhone.showId();  // NO AMBIGUITY! No scope resolution needed!

    // ==================== DEMONSTRATING SHARED DEVICE OBJECT ====================
    cout << "\n========================================" << endl;
    cout << "  PROOF: ONLY ONE Device SUBOBJECT" << endl;
    cout << "========================================\n" << endl;

    cout << "Memory addresses of Device subobject:" << endl;

    // Get address of Device via Phone path
    Device* deviceViaPhone = static_cast<Device*>(static_cast<Phone*>(&myPhone));
    cout << "Via Phone:  " << deviceViaPhone << endl;

    // Get address of Device via Camera path
    Device* deviceViaCamera = static_cast<Device*>(static_cast<Camera*>(&myPhone));
    cout << "Via Camera: " << deviceViaCamera << endl;

    cout << "\n✓ BOTH ADDRESSES ARE IDENTICAL!" << endl;
    cout << "  This proves there is only ONE Device subobject." << endl;

    // Verify addresses are the same
    if (deviceViaPhone == deviceViaCamera) {
        cout << "\n✓ Verification: Phone and Camera share the same Device!" << endl;
    }

    // ==================== DEMONSTRATING CONSISTENCY ====================
    cout << "\n========================================" << endl;
    cout << "  DEMONSTRATING DATA CONSISTENCY" << endl;
    cout << "========================================\n" << endl;

    cout << "Setting Device ID via Phone:" << endl;
    myPhone.Phone::setId(777);

    cout << "\nReading Device ID via Camera:" << endl;
    myPhone.Camera::showId();

    cout << "\nReading Device ID directly:" << endl;
    myPhone.showId();

    cout << "\n✓ ALL THREE show the same ID (777)!" << endl;
    cout << "  This is because there's only ONE Device object." << endl;

    // ==================== USING ALL FEATURES ====================
    cout << "\n========================================" << endl;
    cout << "  USING ALL SMARTPHONE FEATURES" << endl;
    cout << "========================================\n" << endl;

    myPhone.setId(12345);
    myPhone.setPhoneNumber("+1-555-0123");
    myPhone.setMegapixels(108);

    myPhone.displayInfo();
    myPhone.useAllFeatures();

    // ==================== COMPARING WITH AND WITHOUT VIRTUAL INHERITANCE ====================
    cout << "\n========================================" << endl;
    cout << "  COMPARISON: WITH vs WITHOUT Virtual Inheritance" << endl;
    cout << "========================================\n" << endl;

    cout << "WITHOUT virtual inheritance:" << endl;
    cout << "  ✗ myPhone.id           -> AMBIGUOUS (compiler error)" << endl;
    cout << "  ✗ myPhone.showId()     -> AMBIGUOUS (compiler error)" << endl;
    cout << "  ✗ Two Device objects   -> Memory waste" << endl;
    cout << "  ✗ Phone::id != Camera::id -> Data inconsistency" << endl;
    cout << "  ✗ Must use scope resolution -> Phone::showId() or Camera::showId()" << endl;

    cout << "\nWITH virtual inheritance (current program):" << endl;
    cout << "  ✓ myPhone.id           -> WORKS perfectly" << endl;
    cout << "  ✓ myPhone.showId()     -> WORKS perfectly" << endl;
    cout << "  ✓ One Device object    -> Memory efficient" << endl;
    cout << "  ✓ Single shared id     -> Data consistency" << endl;
    cout << "  ✓ Natural syntax       -> No scope resolution needed" << endl;

    // ==================== MEMORY LAYOUT ====================
    cout << "\n========================================" << endl;
    cout << "  MEMORY LAYOUT VISUALIZATION" << endl;
    cout << "========================================\n" << endl;

    cout << "Object sizes (in bytes):" << endl;
    cout << "sizeof(Device):     " << sizeof(Device) << " bytes" << endl;
    cout << "sizeof(Phone):      " << sizeof(Phone) << " bytes" << endl;
    cout << "sizeof(Camera):     " << sizeof(Camera) << " bytes" << endl;
    cout << "sizeof(Smartphone): " << sizeof(Smartphone) << " bytes" << endl;

    cout << "\nNote: With virtual inheritance, there's extra overhead" << endl;
    cout << "for virtual table pointers (vptr), but we avoid duplication!" << endl;

    // ==================== CONSTRUCTOR CALL ORDER ====================
    cout << "\n========================================" << endl;
    cout << "  CONSTRUCTOR CALL ORDER" << endl;
    cout << "========================================\n" << endl;

    cout << "With virtual inheritance, constructor order is special:" << endl;
    cout << "1. Virtual base class (Device) is constructed FIRST" << endl;
    cout << "2. Intermediate classes (Phone, Camera) are constructed" << endl;
    cout << "3. Most derived class (Smartphone) is constructed LAST" << endl;
    cout << "\nImportant: The most derived class (Smartphone) is responsible" << endl;
    cout << "for initializing the virtual base class (Device)." << endl;

    cout << "\nCreating another Smartphone to see constructor order:\n" << endl;
    Smartphone anotherPhone(54321, "Galaxy S24", "Android 14", "+1-555-0200", 200);

    // ==================== PRACTICAL USE CASES ====================
    cout << "\n========================================" << endl;
    cout << "  PRACTICAL USE CASES" << endl;
    cout << "========================================\n" << endl;

    cout << "When to use virtual inheritance:" << endl;
    cout << "1. Multiple inheritance with common base class" << endl;
    cout << "2. Need single shared instance of base class data" << endl;
    cout << "3. Want to avoid ambiguity in member access" << endl;
    cout << "4. Logical model requires shared state" << endl;

    cout << "\nCommon scenarios:" << endl;
    cout << "- GUI frameworks (Widget -> Button/TextBox -> RichTextButton)" << endl;
    cout << "- Device hierarchies (as shown here)" << endl;
    cout << "- Stream I/O (iostream inherits from istream and ostream)" << endl;
    cout << "- Multiple interface implementation with shared base" << endl;

    // ==================== KEY SYNTAX REMINDER ====================
    cout << "\n========================================" << endl;
    cout << "  KEY SYNTAX REMINDER" << endl;
    cout << "========================================\n" << endl;

    cout << "Virtual inheritance syntax:" << endl;
    cout << "\n  class Phone : virtual public Device { };" << endl;
    cout << "  class Camera : virtual public Device { };" << endl;
    cout << "  class Smartphone : public Phone, public Camera { };" << endl;

    cout << "\nKey points:" << endl;
    cout << "- Use 'virtual' keyword before access specifier (public/protected/private)" << endl;
    cout << "- Both intermediate classes must use virtual inheritance" << endl;
    cout << "- Most derived class initializes the virtual base in its constructor" << endl;
    cout << "- Results in single shared base class subobject" << endl;

    // ==================== SUMMARY ====================
    cout << "\n========================================" << endl;
    cout << "  KEY TAKEAWAYS" << endl;
    cout << "========================================\n" << endl;

    cout << "1. Virtual Inheritance Purpose:" << endl;
    cout << "   ✓ Solves the diamond problem" << endl;
    cout << "   ✓ Ensures single shared base class instance" << endl;
    cout << "   ✓ Eliminates ambiguity in member access" << endl;

    cout << "\n2. Syntax:" << endl;
    cout << "   class Derived : virtual public Base { };" << endl;

    cout << "\n3. Benefits:" << endl;
    cout << "   ✓ No ambiguous member access" << endl;
    cout << "   ✓ Memory efficient (no duplication)" << endl;
    cout << "   ✓ Data consistency (one id, not two)" << endl;
    cout << "   ✓ Natural, intuitive syntax" << endl;

    cout << "\n4. Constructor Rule:" << endl;
    cout << "   ✓ Most derived class initializes virtual base" << endl;
    cout << "   ✓ Virtual base constructed before all others" << endl;

    cout << "\n5. Address Proof:" << endl;
    cout << "   ✓ Device address via Phone = Device address via Camera" << endl;
    cout << "   ✓ Confirms single shared Device subobject" << endl;

    cout << "\n========================================" << endl;
    cout << "  PROGRAM COMPLETE" << endl;
    cout << "========================================" << endl;

    return 0;
}

/**
 * KEY DIFFERENCES FROM NON-VIRTUAL INHERITANCE:
 *
 * WITHOUT virtual inheritance (DiamondProblem.cpp):
 * - myPhone.id           -> COMPILER ERROR (ambiguous)
 * - myPhone.showId()     -> COMPILER ERROR (ambiguous)
 * - Phone::Device and Camera::Device are DIFFERENT objects
 * - Different memory addresses for Device via Phone and Camera
 * - Must use scope resolution: Phone::showId() or Camera::showId()
 *
 * WITH virtual inheritance (this program):
 * - myPhone.id           -> WORKS! (no ambiguity)
 * - myPhone.showId()     -> WORKS! (no ambiguity)
 * - Phone and Camera share the SAME Device object
 * - Same memory address for Device via Phone and Camera
 * - Natural syntax, no scope resolution needed
 *
 * CONCLUSION:
 * Virtual inheritance is essential when you have multiple inheritance
 * with a common base class and want:
 * 1. Single shared instance of base class
 * 2. No ambiguity
 * 3. Data consistency
 * 4. Memory efficiency
 */
