// Program demonstrating different data types with sensor data
#include <iostream>
using namespace std;

int main()
{
    char sensor_type = 'n';
    int sensor_id = 12;
    float temperature_celsius = 12.22;
    double humidity_recorded = 40.3333;
    bool active_status = true;
    short level_of_recording = 1213;
    long time_of_recording = 12435646456;
    unsigned int workers = 2341234;

    cout << "Sensor Type: " << sensor_type << "\n";
    cout << "Sensor ID: " << sensor_id << "\n";
    cout << "Temperature: " << temperature_celsius << " Celsius\n";
    cout << "Humidity: " << humidity_recorded << "\n";
    cout << "Active: " << active_status << "\n";
    cout << "Recording Level: " << level_of_recording << "\n";
    cout << "Time: " << time_of_recording << "\n";
    cout << "Workers: " << workers << "\n";

    return 0;
}