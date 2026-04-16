#include <iostream>
#include <memory>
#include <string>

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
    int rawSensorValue = 75;
    std::string sensorIdentifier = "Pressure_A01";

    std::unique_ptr<SensorReport> criticalReportPtr =
        std::make_unique<SensorReport>(rawSensorValue, sensorIdentifier);

    std::cout << "\nProcessing critical sensor report:" << std::endl;
    criticalReportPtr->displayDetails();

    // Copying is not allowed with unique_ptr; this would fail to compile:
    // std::unique_ptr<SensorReport> anotherReport = criticalReportPtr;

    std::cout << "\nProgram finishing. unique_ptr will auto-clean the report." << std::endl;
    return 0;
}
