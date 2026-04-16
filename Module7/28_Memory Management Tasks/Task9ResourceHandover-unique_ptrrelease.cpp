#include <iostream>
#include <memory>
#include <string>

// Section A: Resource handover with unique_ptr::release()
class LogMessage
{
private:
    std::string message_content;

public:
    explicit LogMessage(const std::string &content) : message_content(content)
    {
        std::cout << "LogMessage '" << message_content << "' created. Address: " << this << std::endl;
    }

    void printContent() const
    {
        std::cout << message_content << std::endl;
    }

    ~LogMessage()
    {
        std::cout << "LogMessage '" << message_content << "' destroyed. Address: " << this << std::endl;
    }
};

void handleLegacyLog(LogMessage *rawMessage)
{
    if (rawMessage == nullptr)
    {
        std::cout << "Legacy system received a nullptr log." << std::endl;
        return;
    }

    std::cout << "Legacy system is now handling log: ";
    rawMessage->printContent();

    delete rawMessage;
    std::cout << "Legacy system finished processing and deleting the log." << std::endl;
}

// Section B: Basic unique_ptr ownership with a custom SensorReport type
class SensorReport
{
private:
    int value;
    std::string sensorName;

public:
    SensorReport(int initialValue, const std::string &initialSensorName)
        : value(initialValue), sensorName(initialSensorName)
    {
        std::cout << "SensorReport for " << sensorName << " created." << std::endl;
    }

    void displayDetails() const
    {
        std::cout << "Sensor: " << sensorName << ", Value: " << value << std::endl;
    }

    ~SensorReport()
    {
        std::cout << "SensorReport for " << sensorName << " destroyed." << std::endl;
    }
};

int main()
{
    std::cout << "=== Section A: LogMessage ownership release ===" << std::endl;

    std::unique_ptr<LogMessage> myLog = std::make_unique<LogMessage>("System Startup Event");

    std::cout << "myLog unique_ptr created. Managed address: " << myLog.get() << std::endl;
    std::cout << "Initial managed content: ";
    myLog->printContent();

    // Release ownership from unique_ptr and receive raw pointer.
    // After this line, myLog no longer owns any object.
    LogMessage *handedOverLog = myLog.release();
    std::cout << "myLog has released ownership. Raw pointer: " << handedOverLog << std::endl;

    // Check immediately after release() to prove state change.
    if (!myLog)
    {
        std::cout << "myLog unique_ptr is now empty (nullptr) after release()." << std::endl;
    }
    else
    {
        std::cout << "Error: myLog unique_ptr is NOT empty after release()!" << std::endl;
    }

    // Legacy side now owns and deletes the resource.
    handleLegacyLog(handedOverLog);

    // Optional edge-case check requested in feedback.
    handleLegacyLog(nullptr);

    std::cout << "\n=== Section B: SensorReport unique_ptr usage ===" << std::endl;

    int rawSensorValue = 75;
    std::string sensorIdentifier = "Pressure_A01";

    std::unique_ptr<SensorReport> criticalReportPtr =
        std::make_unique<SensorReport>(rawSensorValue, sensorIdentifier);

    std::cout << "Processing critical sensor report:" << std::endl;
    criticalReportPtr->displayDetails();

    // unique_ptr is non-copyable (uncommenting next line should fail compilation):
    // std::unique_ptr<SensorReport> anotherReport = criticalReportPtr;

    std::cout << "Program completed. Remaining managed objects will auto-clean at scope end." << std::endl;

    return 0;
}
