// Program to compute statistical analysis on array of numbers
#include <iostream>
#include <iomanip>
#include <numeric>
using namespace std;

// Populate array with user input
bool populateDataset(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
    {
        cerr << "Error: Invalid array or size!\n";
        return false;
    }

    cout << "Enter " << datasetLength << " numbers: ";
    for (int index = 0; index < datasetLength; index++)
    {
        if (!(cin >> dataPoints[index]))
        {
            cerr << "Error: Invalid input at position " << (index + 1) << "\n";
            cin.clear();
            cin.ignore(10000, '\n');
            return false;
        }
    }
    return true;
}

// Calculate sum of all elements
int computeTotalSum(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
        return 0;

    int sum = 0;
    for (int i = 0; i < datasetLength; i++)
        sum += dataPoints[i];
    return sum;
}

// Calculate average of array
double determineArithmeticMean(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
        return 0.0;
    return static_cast<double>(computeTotalSum(dataPoints, datasetLength)) / datasetLength;
}

// Check if array contains negative values
bool containsNegativeValues(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
        return false;

    for (int i = 0; i < datasetLength; i++)
        if (dataPoints[i] < 0)
            return true;
    return false;
}

int main()
{
    int datasetLength;
    cout << "Enter the number of data points: ";

    if (!(cin >> datasetLength) || datasetLength <= 0)
    {
        cerr << "Error: Invalid input!\n";
        return 1;
    }

    if (datasetLength > 1000000)
    {
        cerr << "Error: Size too large (max 1,000,000)!\n";
        return 1;
    }

    // Allocate memory
    int *numericalDataset = nullptr;
    try
    {
        numericalDataset = new int[datasetLength];
    }
    catch (const bad_alloc &e)
    {
        cerr << "Error: Memory allocation failed!\n";
        return 1;
    }

    // Get user input
    if (!populateDataset(numericalDataset, datasetLength))
    {
        delete[] numericalDataset;
        return 1;
    }

    // Calculate and display results
    bool hasNegatives = containsNegativeValues(numericalDataset, datasetLength);
    double mean = determineArithmeticMean(numericalDataset, datasetLength);

    cout << "\nDataset size: " << datasetLength << "\n";
    cout << "Mean: " << fixed << setprecision(2) << mean << "\n";
    if (hasNegatives)
        cout << "Note: Contains negative values\n";

    // Clean up
    delete[] numericalDataset;
    numericalDataset = nullptr;

    return 0;
}