#include <iostream>
using namespace std;

#include "config.h"

int main()
{
    cout << "Starting program..." << endl;
    VERSION_INFO();

#undef VERSION
#define VERSION 4
    VERSION_INFO();

    return 0;
}
