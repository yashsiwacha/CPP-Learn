#include <iostream>

#ifndef DEBUG_H
#define DEBUG_H
#endif

#ifdef DEBUG
#define DEBUG_PRINT(x) cout << x << endl;
#else
#define DEBUG_PRINT(x)
#endif
