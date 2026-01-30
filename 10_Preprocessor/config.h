#ifndef CONFIG_H
#define CONFIG_H

#include <iostream>
using namespace std;

// Define version number
#define VERSION 2

// Version-specific logic using conditional compilation
#undef VERSION_INFO
#if VERSION >= 3
#define VERSION_INFO() cout << "Stable version" << endl;
#else
#define VERSION_INFO() cout << "Beta version" << endl;
#endif

#endif // CONFIG_H