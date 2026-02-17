// Program to demonstrate function overloading with default arguments
// This demonstrates COMPILE-TIME POLYMORPHISM (Static Binding)
#include <iostream>
#include <string>

class Messenger
{
public:
    // OVERLOAD 1: Two parameters with DEFAULT ARGUMENT (priority = 1)
    // This demonstrates BOTH overloading AND default arguments working together
    // When called with 1 argument: uses default priority = 1
    // When called with 2 arguments: uses explicit priority value
    // The compiler resolves this at COMPILE-TIME based on the arguments provided
    void send(const std::string &msg, int priority = 1)
    {
        std::cout << "\n[OVERLOAD 1 CALLED: send(string, int = 1)]" << std::endl;
        std::cout << "Priority level: " << priority;
        if (priority == 1)
        {
            std::cout << " (default)";
        }
        std::cout << std::endl;
        std::cout << "Message: " << msg << std::endl;
    }

    // OVERLOAD 2: Three parameters - ALL REQUIRED (no defaults to avoid ambiguity)
    // This demonstrates that more parameters creates a distinct overload
    // Notice: No default arguments here to prevent ambiguity with 2-param version
    void send(const std::string &msg, int priority, const std::string &destination)
    {
        std::cout << "\n[OVERLOAD 2 CALLED: send(string, int, string)]" << std::endl;
        std::cout << "Destination: " << destination << std::endl;
        std::cout << "Priority level: " << priority << std::endl;
        std::cout << "Message: " << msg << std::endl;
    }

    // OVERLOAD 3: Different parameter TYPE (bool instead of int) with DEFAULT
    // OVERLOAD 3: Different parameter TYPE (bool instead of int) - NO DEFAULT
    // Demonstrates overloading based on parameter TYPES, not just count
    // This coexists with send(string, int=1) without ambiguity
    // No default here to prevent ambiguity: send("msg") would be unclear
    void send(const std::string &msg, bool urgent)
    {
        std::cout << "\n[OVERLOAD 3 CALLED: send(string, bool)]" << std::endl;
        std::cout << "Urgent: " << (urgent ? "YES" : "NO") << std::endl;
        std::cout << "Message: " << msg << std::endl;
    }
};

int main()
{
    std::cout << "=== FUNCTION OVERLOADING & DEFAULT ARGUMENTS DEMONSTRATION ===" << std::endl;
    std::cout << "This demonstrates COMPILE-TIME POLYMORPHISM (Static Binding)" << std::endl;

    Messenger messenger;

    // ===== DEMONSTRATION 1: Using Default Argument (Implicit) =====
    std::cout << "\n--- Test 1: Calling with 1 argument (string only) ---";
    std::cout << "\nCompiler selects: send(string, int = 1)" << std::endl;
    std::cout << "The second parameter uses its DEFAULT value (priority = 1)" << std::endl;
    messenger.send("Hello, World!");

    // ===== DEMONSTRATION 2: Explicit Two Arguments (Overriding Default) =====
    std::cout << "\n\n--- Test 2: Calling with 2 arguments (string, int) ---";
    std::cout << "\nCompiler selects: send(string, int = 1)" << std::endl;
    std::cout << "The second parameter is EXPLICITLY provided, overriding the default" << std::endl;
    messenger.send("High priority alert!", 5);

    // ===== DEMONSTRATION 3: Three Arguments (All Explicit) =====
    std::cout << "\n\n--- Test 3: Calling with 3 arguments (string, int, string) ---";
    std::cout << "\nCompiler selects: send(string, int, string)" << std::endl;
    std::cout << "All three parameters REQUIRED (no defaults to avoid ambiguity)" << std::endl;
    messenger.send("Conference call", 4, "team@company.com");

    // ===== DEMONSTRATION 4: Type-Based Overload with bool =====
    std::cout << "\n\n--- Test 4: Calling with explicit bool parameter ---";
    std::cout << "\nCompiler selects: send(string, bool = false) - based on TYPE" << std::endl;
    std::cout << "The bool overload is distinct from int overload due to type difference" << std::endl;
    messenger.send("Emergency notification", true);

    // ===== DEMONSTRATION 5: Comparing int vs bool overloads =====
    std::cout << "\n\n--- Test 5: Type determines which overload is called ---";
    std::cout << "\nBoth send(string, int=1) and send(string, bool) have 2 params" << std::endl;
    std::cout << "Compiler selects based on the TYPE of the second argument:" << std::endl;
    std::cout << "\nCall with explicit int (priority 2):" << std::endl;
    messenger.send("Regular message", 2); // Calls send(string, int = 1)
    std::cout << "\nCall with explicit bool (urgent = false):" << std::endl;
    messenger.send("Routine notification", false); // Calls send(string, bool)

    // ===== EXPLANATION SECTION =====
    std::cout << "\n\n=== HOW THE COMPILER RESOLVES OVERLOADS ===" << std::endl;
    std::cout << "1. EXACT MATCH: Compiler first looks for exact parameter match" << std::endl;
    std::cout << "2. PROMOTION: If no exact match, tries type promotions (char->int)" << std::endl;
    std::cout << "3. STANDARD CONVERSION: Standard conversions (int->double, float->double)" << std::endl;
    std::cout << "4. USER-DEFINED: User-defined conversion operators" << std::endl;
    std::cout << "5. ELLIPSIS: Functions with ellipsis (...) are last resort" << std::endl;

    std::cout << "\n=== DEFAULT ARGUMENTS IN OVERLOADING ===" << std::endl;
    std::cout << "- Default arguments provide fallback values when arguments are omitted" << std::endl;
    std::cout << "- They are resolved at COMPILE-TIME (part of static polymorphism)" << std::endl;
    std::cout << "- Defaults must be specified from RIGHT to LEFT in parameter list" << std::endl;
    std::cout << "- Example: void func(int a, int b = 1, int c = 2) is VALID" << std::endl;
    std::cout << "- Example: void func(int a = 1, int b, int c) is INVALID" << std::endl;

    std::cout << "\n=== AMBIGUITY PREVENTION ===" << std::endl;
    std::cout << "- PROBLEM: If both send(string, int=1) AND send(string, bool=false) had defaults:" << std::endl;
    std::cout << "  Calling send(\"msg\") would be AMBIGUOUS - which default to use?" << std::endl;
    std::cout << "- SOLUTION: Only ONE overload (int version) has default argument" << std::endl;
    std::cout << "- Now send(\"msg\") unambiguously calls send(string, int=1)" << std::endl;
    std::cout << "- send(\"msg\", 5) explicitly uses int overload" << std::endl;
    std::cout << "- send(\"msg\", true) explicitly uses bool overload (requires bool arg)" << std::endl;
    std::cout << "- BEST PRACTICE: Be careful when multiple overloads have same param count with defaults" << std::endl;

    std::cout << "\n=== IMPLICIT vs EXPLICIT ARGUMENT PASSING ===" << std::endl;
    std::cout << "- IMPLICIT: Omit argument, compiler uses default value" << std::endl;
    std::cout << "  Example: send(\"msg\") -> uses priority = 1 (default)" << std::endl;
    std::cout << "- EXPLICIT: Provide argument, overrides default value" << std::endl;
    std::cout << "  Example: send(\"msg\", 5) -> uses priority = 5 (explicit)" << std::endl;

    std::cout << "\n=== COMPILE-TIME vs RUN-TIME POLYMORPHISM ===" << std::endl;
    std::cout << "- COMPILE-TIME (Static Polymorphism):" << std::endl;
    std::cout << "  * Function/Operator overloading" << std::endl;
    std::cout << "  * Template specialization" << std::endl;
    std::cout << "  * Resolved during compilation" << std::endl;
    std::cout << "  * No runtime overhead" << std::endl;
    std::cout << "- RUN-TIME (Dynamic Polymorphism):" << std::endl;
    std::cout << "  * Virtual functions" << std::endl;
    std::cout << "  * Resolved during execution via vtable" << std::endl;
    std::cout << "  * Slight runtime overhead" << std::endl;
    std::cout << "- THIS PROGRAM: Demonstrates COMPILE-TIME polymorphism" << std::endl;

    std::cout << "\n=== Program completed successfully ===" << std::endl;
    return 0;
}

std::cout << "\n=== Program completed successfully ===" << std::endl;
return 0;
}