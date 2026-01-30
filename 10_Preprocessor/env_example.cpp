#include <iostream>
#include "env.h"

using namespace std;

int main()
{
    cout << "========================================" << endl;
    cout << "Environment-Specific Configuration Demo" << endl;
    cout << "========================================" << endl;
    cout << endl;

    cout << "Current Environment: " << ENVIRONMENT << endl;
    cout << "The API URL for this environment is: " << API_URL << endl;
    cout << endl;

    // Display compilation instructions
    cout << "========================================" << endl;
    cout << "Compilation Instructions:" << endl;
    cout << "========================================" << endl;
    cout << "Development: g++ -DDEV env_example.cpp -o ../build/env_dev.exe" << endl;
    cout << "Testing:     g++ -DTEST env_example.cpp -o ../build/env_test.exe" << endl;
    cout << "Production:  g++ env_example.cpp -o ../build/env_prod.exe" << endl;
    cout << "========================================" << endl;

    return 0;
}
