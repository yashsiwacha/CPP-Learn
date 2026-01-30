#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

// Global cache array for memoization
const int MAX_STEPS = 100;
int Cache[MAX_STEPS];

/**
 * Recursive function to calculate the total number of ways to climb to the top
 * @param totalSteps - The total number of steps in the staircase
 * @return The number of ways to reach the top
 */
int stairCaseCounter(int totalSteps) {
    // Base case: Already at top (0 steps) - only 1 way
    if (totalSteps == 0) {
        return 1;
    }
    
    // Base case: Single step - only 1 way
    if (totalSteps == 1) {
        return 1;
    }
    
    // Base case: Two steps - 2 ways (1+1 or 2)
    if (totalSteps == 2) {
        return 2;
    }
    
    // Check if result is already cached
    if (Cache[totalSteps] != -1) {
        return Cache[totalSteps];
    }
    
    // Recursive case: Sum of ways from (n-1) and (n-2) steps
    // You can reach step n from step (n-1) by taking 1 step
    // Or from step (n-2) by taking 2 steps
    Cache[totalSteps] = stairCaseCounter(totalSteps - 1) + stairCaseCounter(totalSteps - 2);
    
    return Cache[totalSteps];
}

/**
 * Function to calculate stairs without memoization (for comparison)
 */
int stairCaseCounterNoCache(int totalSteps) {
    if (totalSteps == 0) return 1;
    if (totalSteps == 1) return 1;
    if (totalSteps == 2) return 2;
    
    return stairCaseCounterNoCache(totalSteps - 1) + stairCaseCounterNoCache(totalSteps - 2);
}

int main() {
    int totalSteps;
    
    cout << "========================================" << endl;
    cout << "   Staircase Climbing Calculator" << endl;
    cout << "========================================" << endl;
    cout << endl;
    
    // Get user input
    cout << "Enter the total number of steps in the staircase: ";
    cin >> totalSteps;
    
    // Input validation: Check for negative numbers
    if (totalSteps < 0) {
        cout << "\nError: Total number of steps cannot be negative!" << endl;
        cout << "Please enter a positive number." << endl;
        return 1;
    }
    
    // Input validation: Check if exceeds cache size
    if (totalSteps >= MAX_STEPS) {
        cout << "\nWarning: The number of steps (" << totalSteps << ") exceeds the maximum cache size (" << MAX_STEPS - 1 << ")." << endl;
        cout << "Please enter a number less than " << MAX_STEPS << "." << endl;
        return 1;
    }
    
    // Initialize cache with -1 (indicating not computed yet)
    memset(Cache, -1, sizeof(Cache));
    
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "Calculating with Memoization..." << endl;
    cout << "----------------------------------------" << endl;
    
    // Calculate with memoization
    clock_t start_with_cache = clock();
    int waysWithCache = stairCaseCounter(totalSteps);
    clock_t end_with_cache = clock();
    double time_with_cache = double(end_with_cache - start_with_cache) / CLOCKS_PER_SEC;
    
    cout << "Total number of ways to climb " << totalSteps << " steps: " << waysWithCache << endl;
    cout << "Time taken (with memoization): " << time_with_cache * 1000 << " milliseconds" << endl;
    
    // Demonstrate without memoization for smaller values (to show performance difference)
    if (totalSteps <= 40) {
        cout << endl;
        cout << "----------------------------------------" << endl;
        cout << "Calculating without Memoization..." << endl;
        cout << "----------------------------------------" << endl;
        
        clock_t start_no_cache = clock();
        int waysNoCache = stairCaseCounterNoCache(totalSteps);
        clock_t end_no_cache = clock();
        double time_no_cache = double(end_no_cache - start_no_cache) / CLOCKS_PER_SEC;
        
        cout << "Total number of ways to climb " << totalSteps << " steps: " << waysNoCache << endl;
        cout << "Time taken (without memoization): " << time_no_cache * 1000 << " milliseconds" << endl;
        
        cout << endl;
        cout << "========================================" << endl;
        cout << "Performance Comparison:" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Speedup factor: " << (time_no_cache / time_with_cache) << "x faster with memoization!" << endl;
        cout << "========================================" << endl;
    } else {
        cout << endl;
        cout << "Note: Skipping non-memoized calculation for large input" << endl;
        cout << "(It would take too long without memoization!)" << endl;
    }
    
    cout << endl;
    cout << "Explanation:" << endl;
    cout << "- You can climb 1 or 2 steps at a time." << endl;
    cout << "- Each unique combination of 1s and 2s that sum to " << totalSteps << " is counted as one way." << endl;
    
    return 0;
}
