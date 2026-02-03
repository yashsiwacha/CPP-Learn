#include "config.h"

int main()
{
    cout << "Testing version control with preprocessor directives:" << endl;
    cout << "Current VERSION: " << VERSION << endl;

    // Display version message based on VERSION macro
    VERSION_INFO();

    return 0;
}