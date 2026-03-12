#include <iostream>
#include <string>
#include <utility>

// ─── process() overloads ──────────────────────────────────────────────────────
// These overloads let us observe which value category each argument carries
// after perfect forwarding. Without std::forward the rvalue overload would
// never be reached (everything would decay to an lvalue inside the template).

// Overload 1: lvalue int  (named variable / lvalue reference)
void process(int &v)
{
    std::cout << "[int&  lvalue] " << v << '\n';
}

// Overload 2: rvalue int  (temporary / unnamed value)
void process(int &&v)
{
    std::cout << "[int&& rvalue] " << v << '\n';
}

// Overload 3: const lvalue std::string  (read-only string passed by reference)
void process(const std::string &s)
{
    std::cout << "[const string& lvalue] " << s << '\n';
}

// Overload 4: rvalue std::string  (temporary string that can be moved)
void process(std::string &&s)
{
    std::cout << "[string&& rvalue] " << s << '\n';
}

// ─── forwardAll() ─────────────────────────────────────────────────────────────
// Universal references:  Args&&... binds to BOTH lvalues and rvalues.
// std::forward<Args>(args)... preserves the original value category of every
// argument, forwarding lvalues as lvalues and rvalues as rvalues. Without
// std::forward, every argument would be treated as an lvalue inside this
// function, defeating the purpose of perfect forwarding.
template <typename... Args>
void forwardAll(Args &&...args)
{
    // Fold expression over the comma operator: calls process() once per arg
    // in order, each time with the correctly preserved value category.
    (process(std::forward<Args>(args)), ...);
}

// ─── main() ──────────────────────────────────────────────────────────────────
int main()
{
    int x = 5;

    std::cout << "--- Call 1: mix of lvalues and rvalues ---\n";
    // x        → lvalue  → forwarded as int&
    // 1, 0     → rvalue  → forwarded as int&&
    // std::string("HELLO") → rvalue → forwarded as string&&
    forwardAll(x, 1, std::string("HELLO"), 0);

    std::cout << "\n--- Call 2: rvalue string and rvalue int expression ---\n";
    // std::string("Temp") → rvalue → forwarded as string&&
    // x + 1               → rvalue → forwarded as int&&
    forwardAll(std::string("Temp"), x + 1);

    std::cout << "\n--- Call 3: const string lvalue ---\n";
    const std::string greeting = "World";
    // greeting → const lvalue → forwarded as const string&
    forwardAll(greeting);
}