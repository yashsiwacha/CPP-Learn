#include <iostream>

using namespace std;

class SystemError
{
private:
    const char *message;

public:
    explicit SystemError(const char *msg) : message(msg) {}

    const char *what() const
    {
        return message;
    }
};

class NetworkError
{
private:
    const char *message;

public:
    explicit NetworkError(const char *msg) : message(msg) {}

    const char *what() const
    {
        return message;
    }
};

class LogSession
{
private:
    int id;

public:
    explicit LogSession(int sessionId) : id(sessionId)
    {
        cout << "[LogSession " << id << "] started." << '\n';
    }

    ~LogSession()
    {
        cout << "[LogSession " << id << "] ended." << '\n';
    }
};

void complexOperation()
{
    static int callCount = 0;
    callCount++;

    LogSession session(callCount);

    if (callCount == 1)
    {
        throw NetworkError("Connection failed");
    }

    if (callCount == 2)
    {
        throw SystemError("Disk full");
    }

    if (callCount == 3)
    {
        throw 404;
    }

    if (callCount == 4)
    {
        throw "Unknown error";
    }

    cout << "Operation completed successfully." << '\n';
}

int main()
{
    cout << "Starting main block." << '\n'
         << '\n';

    for (int index = 0; index < 5; index++)
    {
        try
        {
            complexOperation();
        }
        catch (NetworkError error)
        {
            cout << "Network error caught: " << error.what() << '\n';
        }
        catch (SystemError error)
        {
            cout << "System error caught: " << error.what() << '\n';
        }
        catch (int errorCode)
        {
            cout << "Generic integer error caught: " << errorCode << '\n';
        }
        catch (...)
        {
            cout << "Unknown exception caught!" << '\n';
        }

        cout << "--- End of processing ---" << '\n'
             << '\n';
    }

    return 0;
}
