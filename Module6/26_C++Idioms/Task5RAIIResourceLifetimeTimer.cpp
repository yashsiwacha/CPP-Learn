// Task5RAIIResourceLifetimeTimer.cpp
// RAII for general resource lifetime management using a custom Timer class.
#include <chrono>
#include <cstdint>
#include <iostream>
#include <stdexcept>
#include <string>

class Timer
{
private:
    std::chrono::high_resolution_clock::time_point start;
    std::string label;

public:
    explicit Timer(const std::string &lbl = "")
        : start(std::chrono::high_resolution_clock::now()), label(lbl)
    {
        if (!label.empty())
        {
            std::cout << "Timer started: " << label << std::endl;
        }
    }

    // A Timer owns one timing session; copying/moving it would blur ownership.
    Timer(const Timer &) = delete;
    Timer &operator=(const Timer &) = delete;
    Timer(Timer &&) = delete;
    Timer &operator=(Timer &&) = delete;

    ~Timer()
    {
        const auto end = std::chrono::high_resolution_clock::now();
        const auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

        if (label.empty())
        {
            std::cout << "Elapsed time: " << duration.count() << "us" << std::endl;
        }
        else
        {
            std::cout << "Timer [" << label << "] elapsed: " << duration.count() << "us" << std::endl;
        }
    }
};

void earlyReturnDemo()
{
    Timer t("Early return timing");

    std::int64_t value = 0;
    for (int i = 0; i < 200000; ++i)
    {
        value += i;
        if (i == 100000)
        {
            std::cout << "Early return checkpoint value: " << value << std::endl;
            return; // Timer still stops and reports elapsed time.
        }
    }
}

void exceptionDemo()
{
    Timer t("Exception timing");

    std::int64_t value = 0;
    for (int i = 0; i < 200000; ++i)
    {
        value += i;
        if (i == 120000)
        {
            throw std::runtime_error("Simulated exception after some work");
        }
    }
}

int main()
{
    // RAII idea: constructor does deterministic "start", destructor does deterministic "stop".
    // Scope exit paths (normal, early return, exception) all trigger cleanup/logging automatically.
    {
        Timer t("Loop block timing");

        std::int64_t sum = 0;
        for (int i = 0; i < 1000000; ++i)
        {
            sum += i;
        }

        std::cout << "Sum: " << sum << std::endl;
    } // Timer destructor prints elapsed duration here.

    std::cout << "--- Early return demo ---" << std::endl;
    earlyReturnDemo();

    std::cout << "--- Exception demo ---" << std::endl;
    try
    {
        exceptionDemo();
    }
    catch (const std::exception &ex)
    {
        std::cout << "Caught exception: " << ex.what() << std::endl;
    }

    return 0;
}
