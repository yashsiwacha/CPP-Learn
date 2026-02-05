// Program to demonstrate Diamond Inheritance and Virtual Inheritance in C++
#include <iostream>
#include <string>
using namespace std;

/**
 * THE DIAMOND PROBLEM:
 * When a class inherits from two classes that both inherit from the same base class,
 * it creates a diamond-shaped inheritance hierarchy:
 *
 *        Device
 *       /      \
 *    Phone    Camera
 *       \      /
 *      Smartphone
 *
 * WITHOUT virtual inheritance: Smartphone would have TWO copies of Device
 * WITH virtual inheritance: Smartphone has only ONE shared copy of Device
 *
 * This solves ambiguity and data duplication issues.
 */

/**
 * BASE CLASS: Device
 * Contains common properties shared by all electronic devices
 */
class Device
{
protected:
    string deviceName;
    int deviceId;

public:
    // Constructor
    Device(string name = "Unknown", int id = 0)
    {
        deviceName = name;
        deviceId = id;
        cout << "[Device Constructor] Creating Device: " << deviceName
             << " (ID: " << deviceId << ")" << endl;
    }

    // Getters
    string getDeviceName() const { return deviceName; }
    int getDeviceId() const { return deviceId; }

    // Display device info
    void displayDevice() const
    {
        cout << "Device Name: " << deviceName << ", ID: " << deviceId << endl;
    }

    // Destructor
    ~Device()
    {
        cout << "[Device Destructor] Destroying Device: " << deviceName << endl;
    }
};

/**
 * INTERMEDIATE CLASS 1: Phone
 * Inherits from Device using VIRTUAL INHERITANCE
 * The 'virtual' keyword ensures only ONE instance of Device in the final hierarchy
 */
class Phone : virtual public Device
{
protected:
    string phoneNumber;

public:
    // Constructor - must call Device constructor explicitly in initialization list
    Phone(string name = "Unknown", int id = 0, string number = "000-000-0000")
        : Device(name, id) // Calls Device constructor
    {
        phoneNumber = number;
        cout << "[Phone Constructor] Adding Phone capability: " << phoneNumber << endl;
    }

    // Phone-specific method
    void makeCall(string number) const
    {
        cout << "Calling " << number << " from " << phoneNumber << endl;
    }

    // Getter
    string getPhoneNumber() const { return phoneNumber; }

    // Destructor
    ~Phone()
    {
        cout << "[Phone Destructor] Removing Phone capability" << endl;
    }
};

/**
 * INTERMEDIATE CLASS 2: Camera
 * Inherits from Device using VIRTUAL INHERITANCE
 * The 'virtual' keyword ensures only ONE instance of Device in the final hierarchy
 */
class Camera : virtual public Device
{
protected:
    int megapixels;

public:
    // Constructor - must call Device constructor explicitly in initialization list
    Camera(string name = "Unknown", int id = 0, int mp = 0)
        : Device(name, id) // Calls Device constructor
    {
        megapixels = mp;
        cout << "[Camera Constructor] Adding Camera capability: " << megapixels << "MP" << endl;
    }

    // Camera-specific method
    void takePhoto() const
    {
        cout << "Taking photo with " << megapixels << "MP camera" << endl;
    }

    // Getter
    int getMegapixels() const { return megapixels; }

    // Destructor
    ~Camera()
    {
        cout << "[Camera Destructor] Removing Camera capability" << endl;
    }
};

/**
 * MOST-DERIVED CLASS: Smartphone
 * Inherits from BOTH Phone and Camera (Multiple Inheritance)
 *
 * KEY POINTS:
 * 1. Because Phone and Camera use virtual inheritance, there's only ONE Device
 * 2. The Smartphone constructor MUST explicitly initialize Device
 * 3. No ambiguity when accessing Device members
 * 4. No data duplication
 */
class Smartphone : public Phone, public Camera
{
private:
    string operatingSystem;

public:
    /**
     * Smartphone Constructor
     *
     * IMPORTANT: With virtual inheritance, the MOST-DERIVED class (Smartphone)
     * is responsible for initializing the virtual base class (Device).
     * Even though Phone and Camera constructors also call Device(),
     * those calls are IGNORED when creating a Smartphone.
     */
    Smartphone(string name, int id, string number, int mp, string os)
        : Device(name, id),        // This is the ONLY Device constructor call that executes
          Phone(name, id, number), // Device() call in Phone is ignored
          Camera(name, id, mp)     // Device() call in Camera is ignored
    {
        operatingSystem = os;
        cout << "[Smartphone Constructor] Adding OS: " << operatingSystem << endl;
    }

    // Smartphone-specific method combining capabilities
    void useSmartFeatures() const
    {
        cout << "\n--- Using Smartphone Features ---" << endl;
        displayDevice();
        cout << "Phone: " << phoneNumber << endl;
        cout << "Camera: " << megapixels << "MP" << endl;
        cout << "OS: " << operatingSystem << endl;
    }

    // Getter
    string getOS() const { return operatingSystem; }

    // Destructor
    ~Smartphone()
    {
        cout << "[Smartphone Destructor] Destroying Smartphone" << endl;
    }
};

/**
 * MAIN FUNCTION - Demonstrating Virtual Inheritance
 */
int main()
{
    cout << "============================================================" << endl;
    cout << "    DIAMOND INHERITANCE - Virtual Inheritance Solution" << endl;
    cout << "============================================================" << endl;

    cout << "\n--- Constructor Call Order (Creating Smartphone) ---" << endl;
    Smartphone myPhone("Samsung Galaxy", 12345, "555-1234", 108, "Android 14");

    cout << "\n--- Accessing Members (No Ambiguity!) ---" << endl;
    myPhone.useSmartFeatures();

    cout << "\n--- Using Inherited Methods ---" << endl;
    myPhone.makeCall("555-9999");
    myPhone.takePhoto();

    cout << "\n--- Direct Access to Device Members ---" << endl;
    // No ambiguity! Only ONE Device exists
    cout << "Device Name: " << myPhone.getDeviceName() << endl;
    cout << "Device ID: " << myPhone.getDeviceId() << endl;

    cout << "\n--- Memory Layout Demonstration ---" << endl;
    cout << "Address of Smartphone object: " << &myPhone << endl;
    // With virtual inheritance, there's only ONE Device sub-object

    cout << "\n--- Creating Another Smartphone ---" << endl;
    Smartphone iphone("iPhone 15 Pro", 67890, "555-5678", 48, "iOS 17");
    iphone.useSmartFeatures();

    cout << "\n--- Destructor Call Order (Reverse of Construction) ---" << endl;
    // Destructors will be called automatically when objects go out of scope

    return 0;
}

/**
 * KEY LEARNING POINTS:
 *
 * 1. DIAMOND PROBLEM: Without virtual inheritance, Smartphone would have:
 *    - Two Device::deviceName members (one from Phone path, one from Camera path)
 *    - Two Device::deviceId members
 *    - Ambiguous access: myPhone.deviceName would be an error
 *
 * 2. VIRTUAL INHERITANCE SOLUTION:
 *    - 'virtual' keyword in "class Phone : virtual public Device"
 *    - 'virtual' keyword in "class Camera : virtual public Device"
 *    - Ensures only ONE shared Device sub-object in Smartphone
 *
 * 3. CONSTRUCTOR RESPONSIBILITY:
 *    - Most-derived class (Smartphone) MUST explicitly call virtual base constructor
 *    - Device() calls in Phone and Camera constructors are ignored for Smartphone
 *
 * 4. BENEFITS:
 *    - No data duplication
 *    - No ambiguity in member access
 *    - Consistent, predictable behavior
 *    - Memory efficiency
 *
 * 5. CONSTRUCTOR ORDER:
 *    - Virtual base (Device) constructed FIRST
 *    - Then intermediate classes (Phone, Camera)
 *    - Finally most-derived class (Smartphone)
 *
 * 6. DESTRUCTOR ORDER:
 *    - Reverse of construction order
 *    - Smartphone -> Camera -> Phone -> Device
 */