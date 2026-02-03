// Staircase climbing calculator with memoization
#include <iostream>
#include <cstring>
#include <ctime>
using namespace std;

const int MAX_STEPS = 100;
int Cache[MAX_STEPS];

int stairCaseCounter(int totalSteps)
{
    if (totalSteps <= 1)
        return 1;
    if (totalSteps == 2)
        return 2;

    if (Cache[totalSteps] != -1)
        return Cache[totalSteps];

    Cache[totalSteps] = stairCaseCounter(totalSteps - 1) + stairCaseCounter(totalSteps - 2);
    return Cache[totalSteps];
}

int stairCaseCounterNoCache(int totalSteps)
{
    if (totalSteps <= 1)
        return 1;
    if (totalSteps == 2)
        return 2;
    return stairCaseCounterNoCache(totalSteps - 1) + stairCaseCounterNoCache(totalSteps - 2);
}

int main()
{
    int totalSteps;

    cout << "Staircase Climbing Calculator\n\n";
    cout << "Enter number of steps: ";
    cin >> totalSteps;

    if (totalSteps < 0)
    {
        cout << "Error: Steps cannot be negative\n";
        return 1;
    }

    if (totalSteps >= MAX_STEPS)
    {
        cout << "Error: Maximum " << (MAX_STEPS - 1) << " steps\n";
        return 1;
    }

    memset(Cache, -1, sizeof(Cache));

    // With memoization
    clock_t start = clock();
    int ways = stairCaseCounter(totalSteps);
    clock_t end = clock();
    double timeWith = double(end - start) / CLOCKS_PER_SEC * 1000;

    cout << "\nWays to climb " << totalSteps << " steps: " << ways << "\n";
    cout << "Time (with memoization): " << timeWith << " ms\n";

    // Without memoization (only for small inputs)
    if (totalSteps <= 40)
    {
        start = clock();
        int waysNo = stairCaseCounterNoCache(totalSteps);
        end = clock();
        double timeWithout = double(end - start) / CLOCKS_PER_SEC * 1000;

        cout << "Time (without memoization): " << timeWithout << " ms\n";
        cout << "Speedup: " << (timeWithout / timeWith) << "x faster\n";
    }

    return 0;
}
