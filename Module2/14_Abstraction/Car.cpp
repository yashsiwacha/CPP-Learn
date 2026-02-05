// Program to demonstrate abstraction in C++.
#include <iostream>
using namespace std;

/**
 * DATA ABSTRACTION DEMONSTRATION:
 * The Car class demonstrates data abstraction by hiding the complex internal
 * mechanisms (engine state, speed, RPM) and providing a simple public interface
 * for users to interact with the car.
 *
 * ENCAPSULATION CONCEPT:
 * Private members (engineON, speed, rpm) are hidden from direct external access.
 * This prevents unauthorized or accidental modification of the car's internal state,
 * ensuring data integrity and controlled behavior.
 *
 * WHY PREVENT DIRECT ACCESS?
 * - Maintains consistency: Speed and RPM must change together logically
 * - Enforces constraints: Speed limits, engine state requirements
 * - Protects data integrity: Invalid states (e.g., speed > max) are prevented
 * - Simplifies usage: Users don't need to know implementation details
 */
class Car
{
    // PRIVATE DATA MEMBERS (Hidden Implementation Details)
    // These represent the internal state that users should not directly manipulate
    bool engineON = false;
    int speed = 0;
    int rpm = 0;
    static const int MAX_SPEED = 120; // Maximum speed limit in km/h
    static const int MIN_SPEED = 0;
    static const int MAX_RPM = 7000;

public:
    // PUBLIC API (Abstraction Layer)
    // These methods provide controlled access to manipulate the car's state

    /**
     * start() - Turns on the car engine
     * Purpose: Initializes the car to a ready state with base speed and RPM
     * This demonstrates abstraction: user simply calls start(), internal
     * complexity of setting engineON, speed, and RPM is hidden
     */
    void start()
    {
        cout << "\n========== START ENGINE ==========" << endl;
        if (engineON)
        {
            cout << "Car is already ON." << endl;
            cout << "==================================" << endl;
            return;
        }
        engineON = true;
        speed = 40;
        rpm = 2000;
        cout << "Car is turned ON." << endl;
        cout << "Current Status: Speed = " << speed << " km/h | RPM = " << rpm << endl;
        cout << "==================================" << endl;
    }

    /**
     * accelerate() - Increases car speed and RPM
     * Purpose: Provides controlled acceleration with built-in safety constraints
     * Demonstrates encapsulation: speed and RPM are modified together to maintain
     * logical consistency, and maximum speed limit is enforced
     */
    void accelerate()
    {
        cout << "\n======== ACCELERATING ========" << endl;
        if (engineON == false)
        {
            cout << "Cannot accelerate: Turn on the car first." << endl;
            cout << "==============================" << endl;
            return;
        }

        // Check if already at maximum speed
        if (speed >= MAX_SPEED)
        {
            cout << "Already at maximum speed (" << MAX_SPEED << " km/h)." << endl;
            cout << "Current Status: Speed = " << speed << " km/h | RPM = " << rpm << endl;
            cout << "==============================" << endl;
            return;
        }

        // Increase speed and RPM, respecting maximum limits
        speed += 10;
        rpm += 500;

        // Enforce maximum speed constraint
        if (speed > MAX_SPEED)
        {
            speed = MAX_SPEED;
            rpm = MAX_RPM;
        }

        cout << "Accelerating..." << endl;
        cout << "Current Status: Speed = " << speed << " km/h | RPM = " << rpm << endl;
        cout << "==============================" << endl;
    }

    /**
     * brake() - Decreases car speed and RPM
     * Purpose: Provides controlled deceleration with safety checks
     * Demonstrates data hiding: users don't directly modify speed/RPM,
     * they use this method which ensures proper state transitions
     */
    void brake()
    {
        cout << "\n========== BRAKING ==========" << endl;
        if (engineON == false)
        {
            cout << "Cannot brake: Turn on the car first." << endl;
            cout << "=============================" << endl;
            return;
        }
        if (speed == 0)
        {
            cout << "Car is already stopped." << endl;
            cout << "=============================" << endl;
            return;
        }

        cout << "Applying brakes..." << endl;

        // Gradually decrease speed, or stop if speed is low
        if (speed <= 10)
        {
            speed = 0;
            rpm = 0;
            cout << "Car has stopped completely." << endl;
        }
        else
        {
            speed -= 10;
            rpm -= 500;
        }

        cout << "Current Status: Speed = " << speed << " km/h | RPM = " << rpm << endl;
        cout << "=============================" << endl;
    }
};

/**
 * MAIN FUNCTION - Testing the Car Abstraction
 * This demonstrates how abstraction simplifies usage:
 * Users interact with the car using simple methods (start, accelerate, brake)
 * without needing to know or manipulate internal variables directly
 */
int main()
{
    cout << "============================================" << endl;
    cout << "   CAR CONTROL SYSTEM - Testing Abstraction" << endl;
    cout << "============================================" << endl;

    Car maruti;

    // Test 1: Try operations when car is off
    maruti.brake();
    maruti.accelerate();

    // Test 2: Start the car
    maruti.start();
    maruti.start(); // Try starting again

    // Test 3: Accelerate multiple times (test max speed limit)
    maruti.accelerate();
    maruti.accelerate();

    // Test 4: Mix of operations
    maruti.brake();
    maruti.accelerate();

    // Test 5: Brake until stopped
    maruti.brake();
    maruti.brake();
    maruti.brake();
    maruti.brake();
    maruti.brake();
    maruti.brake();
    maruti.brake();
    maruti.brake();
    maruti.brake();

    cout << "\n============================================" << endl;
    cout << "   Test Complete - All Operations Executed" << endl;
    cout << "============================================" << endl;

    return 0;
}