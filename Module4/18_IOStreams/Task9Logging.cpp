#include <chrono>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class Logger
{
private:
    ofstream logFile;

public:
    explicit Logger(const string &fileName)
    {
        logFile.open(fileName, ios::app);
        if (!logFile)
        {
            throw runtime_error("Could not open log file: " + fileName);
        }
    }

    void log(const string &message)
    {
        auto now = chrono::system_clock::now();
        time_t currentTime = chrono::system_clock::to_time_t(now);

        tm localTime{};
        localtime_s(&localTime, &currentTime);

        logFile << '[' << put_time(&localTime, "%Y-%m-%d %H:%M:%S") << "] "
                << message << '\n';
    }
};

int main()
{
    const string logFileName = "application.log";

    try
    {
        Logger logger(logFileName);

        logger.log("Application started");
        logger.log("Loading configuration");
        logger.log("Application finished successfully");

        cout << "Logs written to '" << logFileName << "'.\n";
    }
    catch (const exception &error)
    {
        cerr << "Logger error: " << error.what() << '\n';
        return 1;
    }

    return 0;
}
