#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <limits>
#include <stdexcept>

using namespace std;

class MedicalMemoryTracker
{
private:
    static int totalMemAllocated;
    static int totalMemDeallocated;

public:
    static void recordAllocation(const char *medicalResource, int size)
    {
        totalMemAllocated += size;
        cout << "[ALLOC] " << medicalResource << " -> " << size
             << " bytes allocated. Total allocated: " << totalMemAllocated << " bytes\n";
    }

    static void recordDeallocation(const char *medicalResource, int size)
    {
        totalMemDeallocated += size;
        cout << "[FREE ] " << medicalResource << " -> " << size
             << " bytes released. Total deallocated: " << totalMemDeallocated << " bytes\n";
    }

    static void reportLeaks()
    {
        const int leakBytes = totalMemAllocated - totalMemDeallocated;
        cout << "\n========== MEMORY STATUS REPORT ==========" << '\n';
        cout << "Total Allocated   : " << totalMemAllocated << " bytes\n";
        cout << "Total Deallocated : " << totalMemDeallocated << " bytes\n";
        cout << "Difference        : " << leakBytes << " bytes\n";

        if (leakBytes == 0)
        {
            cout << "No memory leak detected.\n";
        }
        else
        {
            cout << "Memory leak detected: " << leakBytes << " bytes not freed.\n";
        }
        cout << "==========================================\n\n";
    }

    static void reset()
    {
        totalMemAllocated = 0;
        totalMemDeallocated = 0;
    }
};

int MedicalMemoryTracker::totalMemAllocated = 0;
int MedicalMemoryTracker::totalMemDeallocated = 0;

class MedicalDeviceException : public runtime_error
{
public:
    explicit MedicalDeviceException(const string &message)
        : runtime_error(message) {}
};

class PatientDataException : public runtime_error
{
public:
    explicit PatientDataException(const string &message)
        : runtime_error(message) {}
};

class PatientVitalMonitor
{
private:
    int *heartRateData;
    float *bloodPressureData;
    bool deviceConnected;
    char patientId[32];

    void connectToMedicalDevice()
    {
        if (rand() % 2 == 0)
        {
            throw MedicalDeviceException("E101: Medical device connection failed!");
        }
        deviceConnected = true;
        cout << "Device connected successfully for patient " << patientId << ".\n";
    }

    void calibrateSensors()
    {
        if (rand() % 2 == 0)
        {
            throw MedicalDeviceException("E202: Sensor calibration failed!");
        }
        cout << "Sensor calibration completed for patient " << patientId << ".\n";
    }

    void validatePatientData()
    {
        if (rand() % 2 == 0)
        {
            throw PatientDataException("E303: Corrupted vital signs detected!");
        }
        cout << "Patient data validation passed.\n";
    }

    void analyzeCriticalTrend()
    {
        if (rand() % 2 == 0)
        {
            throw PatientDataException("E404: Critical trend analysis failed!");
        }
        cout << "Critical trend analysis passed.\n";
    }

public:
    explicit PatientVitalMonitor(const char *id)
        : heartRateData(nullptr), bloodPressureData(nullptr), deviceConnected(false), patientId{}
    {
        strncpy(patientId, id, sizeof(patientId) - 1);
        patientId[sizeof(patientId) - 1] = '\0';

        heartRateData = new int[36000];
        MedicalMemoryTracker::recordAllocation("Heart Rate Buffer", 36000 * static_cast<int>(sizeof(int)));

        bloodPressureData = new float[18000];
        MedicalMemoryTracker::recordAllocation("Blood Pressure Buffer", 18000 * static_cast<int>(sizeof(float)));

        try
        {
            connectToMedicalDevice();
            calibrateSensors();
        }
        catch (...)
        {
            cout << "Constructor interrupted by exception. Destructor will not run for this object;"
                 << " partially allocated internal buffers may leak.\n";
            throw;
        }

        cout << "PatientVitalMonitor initialized for patient " << patientId << ".\n";
    }

    ~PatientVitalMonitor()
    {
        cout << "Shutting down monitor for patient " << patientId << ".\n";

        if (heartRateData != nullptr)
        {
            delete[] heartRateData;
            heartRateData = nullptr;
            MedicalMemoryTracker::recordDeallocation("Heart Rate Buffer", 36000 * static_cast<int>(sizeof(int)));
        }

        if (bloodPressureData != nullptr)
        {
            delete[] bloodPressureData;
            bloodPressureData = nullptr;
            MedicalMemoryTracker::recordDeallocation("Blood Pressure Buffer", 18000 * static_cast<int>(sizeof(float)));
        }
    }

    void monitorPatientVitals(int durationMinutes)
    {
        if (durationMinutes <= 0)
        {
            throw invalid_argument("E001: Monitoring duration must be positive!");
        }

        float *ecgAnalysisBuffer = new float[5000];
        MedicalMemoryTracker::recordAllocation("ECG Analysis Buffer", 5000 * static_cast<int>(sizeof(float)));

        try
        {
            validatePatientData();
        }
        catch (...)
        {
            cout << "Exception during data validation. ECG buffer cleanup path is skipped intentionally"
                 << " to demonstrate a leak during stack unwinding.\n";
            throw;
        }

        int *criticalTrendBuffer = new int[1000];
        MedicalMemoryTracker::recordAllocation("Critical Trend Buffer", 1000 * static_cast<int>(sizeof(int)));

        try
        {
            analyzeCriticalTrend();
        }
        catch (...)
        {
            cout << "Exception during trend analysis. Both ECG and critical trend buffers may leak"
                 << " because normal cleanup is not reached.\n";
            throw;
        }

        cout << "Monitoring patient " << patientId << " for " << durationMinutes << " minute(s)...\n";
        for (int minute = 1; minute <= durationMinutes; ++minute)
        {
            if (minute % 5 == 0)
            {
                cout << "Minute " << minute << ": Vitals stable.\n";
            }
        }

        delete[] ecgAnalysisBuffer;
        MedicalMemoryTracker::recordDeallocation("ECG Analysis Buffer", 5000 * static_cast<int>(sizeof(float)));
        cout << "ECG analysis completed - buffer freed\n";

        delete[] criticalTrendBuffer;
        MedicalMemoryTracker::recordDeallocation("Critical Trend Buffer", 1000 * static_cast<int>(sizeof(int)));
        cout << "Critical trend analysis completed - buffer freed\n";
    }
};

int main()
{
    cout << "===============================================\n";
    cout << "Medical Patient Monitor - Memory Leak Detector\n";
    cout << "Demonstrates leaks caused by exception flow\n";
    cout << "===============================================\n\n";

    srand(static_cast<unsigned>(time(nullptr)));

    int attempts = 0;
    cout << "Enter number of monitoring attempts (5-10 recommended): ";
    cin >> attempts;

    if (cin.fail() || attempts <= 0)
    {
        cout << "Invalid attempts count. Exiting.\n";
        return 1;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    MedicalMemoryTracker::reset();

    int currentAttempt = 1;
    while (currentAttempt <= attempts)
    {
        cout << "\n=========== Attempt " << currentAttempt << " ===========\n";

        PatientVitalMonitor *emergencyMonitor = nullptr;
        bool setupSuccessful = false;

        try
        {
            emergencyMonitor = new PatientVitalMonitor("EMERGENCY-001");
            setupSuccessful = true;
            cout << "Monitor setup completed successfully.\n";
        }
        catch (const MedicalDeviceException &e)
        {
            cout << "MedicalDeviceException caught: " << e.what() << '\n';
        }

        if (setupSuccessful && emergencyMonitor != nullptr)
        {
            try
            {
                emergencyMonitor->monitorPatientVitals(10);
            }
            catch (const PatientDataException &e)
            {
                cout << "PatientDataException caught: " << e.what() << '\n';
            }
            catch (const invalid_argument &e)
            {
                cout << "Invalid argument caught: " << e.what() << '\n';
            }
            catch (...)
            {
                cout << "Unexpected exception during monitoring captured in generic handler.\n";
            }
        }

        delete emergencyMonitor;
        emergencyMonitor = nullptr;

        currentAttempt++;
    }

    MedicalMemoryTracker::reportLeaks();

    return 0;
}
