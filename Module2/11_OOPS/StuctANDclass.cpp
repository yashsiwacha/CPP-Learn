//Program to demonstrate the difference between structure and class in C++.
//
//KEY CONCEPT: Access Specifiers Control Data Visibility
//============================================================
//STRUCTS: Members are PUBLIC by default
//  - Can be accessed directly from anywhere in the program
//  - No encapsulation unless explicitly specified with 'private:'
//  - Used for simple data grouping without protection
//
//CLASSES: Members are PRIVATE by default  
//  - Cannot be accessed directly from outside the class
//  - Enforces encapsulation and data hiding
//  - Access provided through PUBLIC getter/setter methods
//  - Used for complex objects requiring controlled access and validation
//============================================================

#include <iostream>
#include <cmath>  //For sqrt function
using namespace std;

//==============================================================================
// STRUCT EXAMPLE: Point (Coordinates)
//==============================================================================
//In structs, all members are PUBLIC by default - no access specifier needed
//
//WHAT DOES PUBLIC MEAN?
//  - Any part of the program can read or modify these members directly
//  - Syntax: objectName.memberName (e.g., point.x = 10)
//  - No getter/setter methods required
//  - Fast and simple, but no data protection or validation
//
//WHEN TO USE STRUCTS:
//  - Simple data containers (coordinates, RGB colors, etc.)
//  - When you don't need to validate or protect the data
//  - When performance and simplicity are priorities
//==============================================================================
struct Point{
    int x, y;  //These are PUBLIC - accessible from anywhere without restrictions
    string label;  //Also PUBLIC - can be directly read or modified
    
    //Structs can have methods too! These are also PUBLIC by default
    void displayInfo(){
        cout << "Point '" << label << "': (" << x << ", " << y << ")" << endl;
    }
    
    //Calculate distance from origin (0,0)
    double distanceFromOrigin(){
        return sqrt(x * x + y * y);
    }
};

//==============================================================================
// CLASS EXAMPLE: Rectangle (Geometric Shape)
//==============================================================================
//In classes, all members are PRIVATE by default - must specify 'public:' explicitly
//
//WHAT DOES PRIVATE MEAN?
//  - Members can ONLY be accessed from within the class itself
//  - Cannot use objectName.memberName syntax from outside
//  - Attempting direct access causes a COMPILATION ERROR
//  - Must use PUBLIC getter/setter methods to access or modify
//
//WHY USE PRIVATE MEMBERS? (Encapsulation Benefits)
//  1. DATA PROTECTION: Prevents accidental or malicious modification
//  2. VALIDATION: Setter methods can check if values are valid before storing
//  3. FLEXIBILITY: Can change internal implementation without breaking code
//  4. DEBUGGING: Easier to track where data is modified (only through setters)
//
//WHEN TO USE CLASSES:
//  - Complex objects requiring data protection
//  - When input validation or business rules are needed
//  - When you want to control how data is accessed or modified
//==============================================================================
class Rectangle{
    //PRIVATE SECTION (default for classes - no keyword needed)
    //These members are HIDDEN from outside access - encapsulation in action!
    int length, width;  //Cannot be accessed as: rectangle.length (will cause ERROR)
    string color;       //Cannot be accessed as: rectangle.color (will cause ERROR)
    bool isValid;       //Internal state tracking - users don't need to see this
    
    public:  //PUBLIC SECTION - must be explicitly declared in classes
             //Everything below this keyword IS accessible from outside the class
        
        //Constructor: PUBLIC method that creates and initializes the object
        //Uses setter methods instead of direct assignment to ensure validation
        Rectangle(int len, int wid, string col = "White"){
            color = col;
            isValid = true;
            setLength(len);  //Using setters ensures validation even during construction
            setWidth(wid);   //Direct assignment (this->length = len) would bypass validation
        }
        
        //PUBLIC SETTER METHOD - The "Gateway" to modify PRIVATE data
        //This method provides CONTROLLED access with VALIDATION
        //Without this, there would be NO WAY to change 'length' from outside
        void setLength(int value){
            if(value > 0 && value <= 1000){  //VALIDATION: Ensures data integrity
                this->length = value;
            } else {
                //ERROR HANDLING: Provides safe defaults instead of storing invalid data
                cout << "[ERROR] Invalid length! Must be between 1-1000. Setting to default (10)." << endl;
                this->length = 10;
                isValid = false;
            }
        }
        
        //PUBLIC GETTER METHOD - Provides READ-ONLY access to PRIVATE data
        //Allows viewing the value without allowing direct modification
        //Users can call: rectangle.getLength() but NOT: rectangle.length
        int getLength(){
            return this->length;
        }
        
        //PUBLIC SETTER for width - same controlled access pattern
        void setWidth(int value){
            if(value > 0 && value <= 1000){  //VALIDATION ensures only valid data is stored
                this->width = value;
            } else {
                cout << "[ERROR] Invalid width! Must be between 1-1000. Setting to default (10)." << endl;
                this->width = 10;
                isValid = false;
            }
        }
        
        int getWidth(){
            return this->width;
        }
        
        void setColor(string col){
            this->color = col;
        }
        
        string getColor(){
            return this->color;
        }
        
        //Additional functionality - calculate area
        int calculateArea(){
            return length * width;
        }
        
        //Additional functionality - calculate perimeter
        int calculatePerimeter(){
            return 2 * (length + width);
        }
        
        //Check if rectangle is a square
        bool isSquare(){
            return length == width;
        }
        
        //Display complete information
        void displayInfo(){
            cout << "Rectangle Info: " << length << "x" << width 
                 << " (Color: " << color << ")" << endl;
            cout << "  Area: " << calculateArea() << " square units" << endl;
            cout << "  Perimeter: " << calculatePerimeter() << " units" << endl;
            cout << "  Is Square: " << (isSquare() ? "Yes" : "No") << endl;
        }

};
int main(){
    //==========================================================================
    // PART 1: Creating and Using a STRUCT (PUBLIC members by default)
    //==========================================================================
    struct Point cartesianPoint;
    
    //DIRECT ACCESS works because struct members are PUBLIC
    //Notice: We use dot notation directly without any getter/setter methods
    //Syntax: structName.memberName = value
    cartesianPoint.x = 25;                    //Direct write access - no method needed
    cartesianPoint.y = 45;                    //Direct write access - no method needed
    cartesianPoint.label = "Origin Point";    //Direct write access - no method needed
    
    //==========================================================================
    // PART 2: Creating and Using a CLASS (PRIVATE members by default)
    //==========================================================================
    //Creating a Rectangle object - constructor is PUBLIC so we can call it
    Rectangle floorRectangle(25, 35, "Blue");
    
    //==========================================================================
    // DEMONSTRATING: STRUCT with PUBLIC Access (No Restrictions)
    //==========================================================================
    cout << "\n=== STRUCT (Direct Access) ===" << endl;
    //Reading struct members directly - no getter methods needed
    //This is ONLY possible because x, y, and label are PUBLIC
    cout << "Point X coordinate: " << cartesianPoint.x << endl;        //Direct read
    cout << "Point Y coordinate: " << cartesianPoint.y << endl;        //Direct read
    cout << "Point Label: " << cartesianPoint.label << endl;           //Direct read
    cartesianPoint.displayInfo();  //Calling public method
    cout << "Distance from origin: " << cartesianPoint.distanceFromOrigin() << " units" << endl;
    
    //==========================================================================
    // DEMONSTRATING: CLASS with PRIVATE Members (Controlled Access Required)
    //==========================================================================
    cout << "\n=== CLASS (Getter/Setter Access) ===" << endl;
    //Cannot use: floorRectangle.length (COMPILATION ERROR - it's PRIVATE)
    //Must use: floorRectangle.getLength() (PUBLIC getter method)
    cout << "Rectangle Length: " << floorRectangle.getLength() << endl;           //Using PUBLIC getter
    cout << "Rectangle Width: " << floorRectangle.getWidth() << endl;             //Using PUBLIC getter
    cout << "Rectangle Color: " << floorRectangle.getColor() << endl;             //Using PUBLIC getter
    cout << "Rectangle Area: " << floorRectangle.calculateArea() << " square units" << endl;
    cout << "Rectangle Perimeter: " << floorRectangle.calculatePerimeter() << " units" << endl;
    
    //==========================================================================
    // DEMONSTRATING: SETTER METHODS for Modifying PRIVATE Members
    //==========================================================================
    cout << "\n=== Modifying Private Members Using Setters ===" << endl;
    //Cannot use: floorRectangle.length = 50 (COMPILATION ERROR - it's PRIVATE)
    //Must use: floorRectangle.setLength(50) (PUBLIC setter method)
    floorRectangle.setLength(50);      //Modifying through PUBLIC setter
    floorRectangle.setWidth(30);       //Modifying through PUBLIC setter
    floorRectangle.setColor("Red");    //Modifying through PUBLIC setter
    floorRectangle.displayInfo();      //Display complete info using PUBLIC method
    
    //==========================================================================
    // DEMONSTRATING: WHY PRIVATE + SETTERS = POWERFUL (Validation & Safety)
    //==========================================================================
    cout << "\n=== Testing Input Validation (Error Handling) ===" << endl;
    Rectangle testRectangle(10, 10, "Green");
    //The beauty of encapsulation: Invalid data is automatically rejected
    //If length/width were PUBLIC, we could accidentally store -5 or 2000!
    cout << "Attempting to set invalid length (-5)..." << endl;
    testRectangle.setLength(-5);      //Setter validates and rejects invalid value
    cout << "Attempting to set invalid width (2000)..." << endl;
    testRectangle.setWidth(2000);     //Setter validates and rejects invalid value
    cout << "\nAfter invalid inputs, rectangle has safe default values:" << endl;
    testRectangle.displayInfo();
    //This demonstrates DATA INTEGRITY - impossible with PUBLIC members!
    
    //Testing square functionality
    cout << "\n=== Testing Additional Functionality ===" << endl;
    Rectangle square(40, 40, "Yellow");
    square.displayInfo();
    
    //Demonstrating struct adaptability with another point
    cout << "\n=== Creating Another Struct Instance ===" << endl;
    Point destination;
    destination.x = 100;
    destination.y = 200;
    destination.label = "Destination";
    destination.displayInfo();
    
    //==========================================================================
    // CRITICAL DEMONSTRATION: Why Direct Access Fails for CLASS Members
    //==========================================================================
    //Uncommenting ANY of the lines below will cause a COMPILATION ERROR:
    //  "error: 'length' is a private member of 'Rectangle'"
    //  "error: 'width' is a private member of 'Rectangle'"
    //
    //This is the COMPILER enforcing encapsulation - it PREVENTS you from
    //bypassing the controlled access that getters/setters provide.
    //
    //REMEMBER: 
    //  ✓ STRUCT: cartesianPoint.x = 100;        // This WORKS (PUBLIC)
    //  ✗ CLASS:  floorRectangle.length = 100;   // This FAILS (PRIVATE)
    //  ✓ CLASS:  floorRectangle.setLength(100); // This WORKS (PUBLIC method)
    //==========================================================================
    
    // cout << "\nAttempting Direct Access (This Will Fail): " << endl;
    // cout << "Rectangle Length: " << floorRectangle.length << endl;     // COMPILE ERROR!
    // cout << "Rectangle Width: " << floorRectangle.width << endl;       // COMPILE ERROR!

}
