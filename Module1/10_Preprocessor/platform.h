#ifndef PLATFORM_H
#define PLATFORM_H

#include <iostream>

// Platform detection using preprocessor directives
// This demonstrates conditional compilation for cross-platform development

void detectPlatform()
{
#if defined(WINDOWS)
    std::cout << "This is a Windows operating system." << std::endl;
#elif defined(LINUX)
    std::cout << "This is a Linux operating system." << std::endl;
#elif defined(MAC)
    std::cout << "This is a macOS operating system." << std::endl;
#else
    std::cout << "Unknown OS" << std::endl;
#endif
}

#endif // PLATFORM_H
