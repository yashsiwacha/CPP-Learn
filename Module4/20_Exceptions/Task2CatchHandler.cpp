#include <iostream>
using namespace std;

class SystemError
{
public:
    const char *message;

    SystemError(const char *msg) : message(msg) {}
};

class NetworkError
{
public:
    const char *message;

    NetworkError(const char *msg) : message(msg) {}
};

void complexOperation()
{
    // Changes behavior each time this function is called.
    static int counter = 0;
    counter++;

    // 1st: SystemError, 2nd: NetworkError, 3rd: int, 4th: const char*
    if (counter == 1)
    {
        throw SystemError("System module failed to initialize.");
    }
    else if (counter == 2)
    {
        throw NetworkError("Unable to connect to remote server.");
    }
    else if (counter == 3)
    {
        throw -1;
    }
    else if (counter == 4)
    {
        throw "Very unexpected error!";
    }
    else
    {
        cout << "Operation completed successfully." << endl;
    }
}

int main()
{
    // Attempt 1
    cout << "Attempt 1:" << endl;
    try
    {
        complexOperation();
    }
    // Catch blocks are checked top to bottom.
    catch (NetworkError netErr)
    {
        cout << "Network error caught: " << netErr.message << endl;
    }
    catch (SystemError sysErr)
    {
        cout << "System error caught: " << sysErr.message << endl;
    }
    catch (int errorCode)
    {
        cout << "Generic integer error caught: " << errorCode << endl;
    }
    catch (...)
    {
        cout << "Unknown exception caught!" << endl;
    }
    cout << "--- End of processing ---" << endl;

    // Attempt 2
    cout << "Attempt 2:" << endl;
    try
    {
        complexOperation();
    }
    catch (NetworkError netErr)
    {
        cout << "Network error caught: " << netErr.message << endl;
    }
    catch (SystemError sysErr)
    {
        cout << "System error caught: " << sysErr.message << endl;
    }
    catch (int errorCode)
    {
        cout << "Generic integer error caught: " << errorCode << endl;
    }
    catch (...)
    {
        cout << "Unknown exception caught!" << endl;
    }
    cout << "--- End of processing ---" << endl;

    // Attempt 3
    cout << "Attempt 3:" << endl;
    try
    {
        complexOperation();
    }
    catch (NetworkError netErr)
    {
        cout << "Network error caught: " << netErr.message << endl;
    }
    catch (SystemError sysErr)
    {
        cout << "System error caught: " << sysErr.message << endl;
    }
    catch (int errorCode)
    {
        cout << "Generic integer error caught: " << errorCode << endl;
    }
    catch (...)
    {
        cout << "Unknown exception caught!" << endl;
    }
    cout << "--- End of processing ---" << endl;

    // Attempt 4
    cout << "Attempt 4:" << endl;
    try
    {
        complexOperation();
    }
    catch (NetworkError netErr)
    {
        cout << "Network error caught: " << netErr.message << endl;
    }
    catch (SystemError sysErr)
    {
        cout << "System error caught: " << sysErr.message << endl;
    }
    catch (int errorCode)
    {
        cout << "Generic integer error caught: " << errorCode << endl;
    }
    catch (...)
    {
        cout << "Unknown exception caught!" << endl;
    }
    cout << "--- End of processing ---" << endl;

    // Attempt 5
    cout << "Attempt 5:" << endl;
    try
    {
        complexOperation();
    }
    catch (NetworkError netErr)
    {
        cout << "Network error caught: " << netErr.message << endl;
    }
    catch (SystemError sysErr)
    {
        cout << "System error caught: " << sysErr.message << endl;
    }
    catch (int errorCode)
    {
        cout << "Generic integer error caught: " << errorCode << endl;
    }
    catch (...)
    {
        cout << "Unknown exception caught!" << endl;
    }
    cout << "--- End of processing ---" << endl;

    return 0;
}