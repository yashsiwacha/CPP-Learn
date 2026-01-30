#include <iostream>

// #define WINDOWS
// #define MACOS
// #define LINUX

#include "platform.h"
using namespace std;

int main()
{
#if defined(WINDOWS)
    cout << "Windows is defined.\n";
#elif defined(MACOS)
    cout << "MACOS is defined.\n";
#elif defined(LINUX)
    cout << "Linux is defined.\n";
#else
    cout << "No OS is defined.\n";
#endif
}
