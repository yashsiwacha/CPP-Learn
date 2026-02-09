/*
 * Game Characters - Encapsulation, Abstraction, and Inheritance
 * Demonstrates: private data, validated setters/getters, pure virtual functions,
 * inheritance, and polymorphism through base pointers
 */

#include <iostream>
#include <vector>
using namespace std;

// Abstract Base Class - Character
class Character
{
private:
    int health;
    int mana;
    static const int MAX_HEALTH = 100;
    static const int MAX_MANA = 100;

public:
    // Constructor
    Character(int h, int m)
    {
        setHealth(h);
        setMana(m);
    }

    // Virtual destructor
    virtual ~Character() {}

    // Validated Setters
    void setHealth(int h)
    {
        if (h < 0)
        {
            cout << "Warning: Health cannot be negative. Setting to 0." << endl;
            health = 0;
        }
        else if (h > MAX_HEALTH)
        {
            cout << "Warning: Health exceeds maximum. Setting to " << MAX_HEALTH << "." << endl;
            health = MAX_HEALTH;
        }
        else
        {
            health = h;
        }
    }

    void setMana(int m)
    {
        if (m < 0)
        {
            cout << "Warning: Mana cannot be negative. Setting to 0." << endl;
            mana = 0;
        }
        else if (m > MAX_MANA)
        {
            cout << "Warning: Mana exceeds maximum. Setting to " << MAX_MANA << "." << endl;
            mana = MAX_MANA;
        }
        else
        {
            mana = m;
        }
    }

    // Getters
    int getHealth() const { return health; }
    int getMana() const { return mana; }

    // Pure virtual function - must be implemented by derived classes
    virtual void attack() = 0;
};

// Derived Class: Warrior
class Warrior : public Character
{
public:
    Warrior(int health, int mana) : Character(health, mana) {}

    // Override attack() with melee mechanics
    void attack() override
    {
        cout << "Warrior attacks with a powerful sword strike!" << endl;
    }
};

// Derived Class: Mage
class Mage : public Character
{
public:
    Mage(int health, int mana) : Character(health, mana) {}

    // Override attack() with magic mechanics
    void attack() override
    {
        if (getMana() > 0)
        {
            cout << "Mage casts a fireball spell!" << endl;
        }
        else
        {
            cout << "Mage is out of mana!" << endl;
        }
    }
};

int main()
{
    cout << "=== Game Characters - OOP Demonstration ===\n"
         << endl;

    // Create characters
    Warrior warrior(80, 20);
    Mage mage(50, 90);

    cout << "Initial Stats:" << endl;
    cout << "Warrior - Health: " << warrior.getHealth() << ", Mana: " << warrior.getMana() << endl;
    cout << "Mage - Health: " << mage.getHealth() << ", Mana: " << mage.getMana() << endl;

    // Test validation
    cout << "\n--- Testing Validation ---" << endl;
    warrior.setHealth(-10); // Invalid negative
    warrior.setHealth(150); // Invalid exceeds max
    mage.setMana(-5);       // Invalid negative
    mage.setMana(120);      // Invalid exceeds max

    // Reset to valid values
    warrior.setHealth(80);
    mage.setMana(90);

    // Polymorphic behavior using base class pointers
    cout << "\n--- Polymorphic Attacks ---" << endl;
    vector<Character *> characters;
    characters.push_back(&warrior);
    characters.push_back(&mage);
    characters.push_back(new Warrior(90, 30));
    characters.push_back(new Mage(60, 100));

    for (size_t i = 0; i < characters.size(); i++)
    {
        cout << "Character " << (i + 1) << ": ";
        characters[i]->attack();
    }

    // Cleanup dynamically allocated objects
    delete characters[2];
    delete characters[3];

    cout << "\n=== Program Complete ===" << endl;
    return 0;
}