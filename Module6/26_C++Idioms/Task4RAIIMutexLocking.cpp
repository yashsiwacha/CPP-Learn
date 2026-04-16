// Task4RAIIMutexLocking.cpp
// RAII for mutex locking with std::lock_guard: exception-safe synchronization.
#include <exception>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <vector>

int counter = 0;
std::mutex mtx;

void safeIncrement(int iterations, bool simulateException)
{
    for (int i = 0; i < iterations; ++i)
    {
        // lock_guard acquires the mutex now and guarantees unlock at scope exit.
        std::lock_guard<std::mutex> lock(mtx);

        if (simulateException && i == 42)
        {
            throw std::runtime_error("Simulated failure inside critical section");
        }

        ++counter;
    }
}

void worker(int iterations, bool simulateException)
{
    try
    {
        safeIncrement(iterations, simulateException);
    }
    catch (const std::exception &ex)
    {
        // Catch inside each thread so the program continues and can join all threads.
        std::cerr << "Thread caught exception: " << ex.what() << std::endl;
    }
}

int main()
{
    const int threads = 4;
    const int iterations = 10000;

    std::cout << "== RAII Mutex Locking Demo ==" << std::endl;

    // Normal run: no exceptions, expected final value is threads * iterations.
    counter = 0;
    {
        std::vector<std::thread> group;
        for (int i = 0; i < threads; ++i)
        {
            group.emplace_back(worker, iterations, false);
        }
        for (auto &t : group)
        {
            t.join();
        }
    }

    std::cout << "Final counter value (no exception): " << counter << std::endl;
    std::cout << "Expected value: " << (threads * iterations) << std::endl;

    // Optional run: one thread throws; no deadlock because lock_guard still unlocks.
    counter = 0;
    {
        std::vector<std::thread> group;
        group.emplace_back(worker, iterations, true); // one throwing thread
        for (int i = 1; i < threads; ++i)
        {
            group.emplace_back(worker, iterations, false);
        }
        for (auto &t : group)
        {
            t.join();
        }
    }

    std::cout << "Final counter value (with simulated exception): " << counter << std::endl;
    std::cout << "No deadlock observed. Mutex was released automatically via RAII." << std::endl;

    return 0;
}
