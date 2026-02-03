#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>

// Platform detection using preprocessor directives
// This demonstrates conditional compilation for cross-platform development

void detectPlatform()
{
#if defined(WINDOWS)
    cout << "This is a Windows operating system." << endl;
#elif defined(LINUX)
    cout << "This is a Linux operating system." << endl;
#elif defined(MAC)
    cout << "This is a macOS operating system." << endl;
#else
    cout << "Unknown OS" << endl;
#endif
}

#endif // PLATFORM_H
