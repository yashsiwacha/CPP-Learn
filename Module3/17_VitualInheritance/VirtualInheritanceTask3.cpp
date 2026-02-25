//
// Created by YashSiwach on 17-02-2026.
//

#include <iostream>

class ConstructionTrace
{
public:
    static int nextStep()
    {
        static int step = 0;
        return ++step;
    }
};

class Device
{
    int id;
    static int constructionCount;

public:
    explicit Device(int deviceId)
        : id(deviceId)
    {
        ++constructionCount;
        std::cout << "[Step " << ConstructionTrace::nextStep() << "] Device constructor called. ID = " << id << std::endl;
    }

    static int getConstructionCount()
    {
        return constructionCount;
    }
};

int Device::constructionCount = 0;

class Phone : virtual public Device
{
public:
    explicit Phone(int deviceId = -1)
        : Device(deviceId)
    {
        std::cout << "[Step " << ConstructionTrace::nextStep() << "] Phone constructor called." << std::endl;
    }
};

class Camera : virtual public Device
{
public:
    explicit Camera(int deviceId = -1)
        : Device(deviceId)
    {
        std::cout << "[Step " << ConstructionTrace::nextStep() << "] Camera constructor called." << std::endl;
    }
};

class Smartphone : public Phone, public Camera
{
public:
    explicit Smartphone(int deviceId)
        // For a virtual base, only the most-derived class initializes it.
        // So this Device(deviceId) call is the one that actually runs.
        : Device(deviceId), Phone(deviceId), Camera(deviceId)
    {
        std::cout << "[Step " << ConstructionTrace::nextStep() << "] Smartphone constructor called." << std::endl;
    }
};

int main()
{
    std::cout << "Creating Smartphone object..." << std::endl;
    std::cout << "Expected constructor order: Device -> Phone -> Camera -> Smartphone" << std::endl;

    // With virtual inheritance, Device is constructed once, before Phone and Camera.
    Smartphone sm(101);
    std::cout << "Device constructor call count in this run = " << Device::getConstructionCount()
              << " (confirms virtual base constructed once)." << std::endl;

    return 0;
}
