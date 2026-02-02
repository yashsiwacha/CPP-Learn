// Program to compute statistical analysis on array of numbers
#include <iostream>
#include <iomanip>
#include <numeric>
using namespace std;

// Function to populate array with user input
bool populateDataset(int *dataPoints, int datasetLength)
{
    // Validate pointer and array size
    if (dataPoints == nullptr || datasetLength <= 0)
    {
        cerr << "Error: Invalid array or size!" << endl;
        return false;
    }

    cout << "Enter " << datasetLength << " numbers: ";
    for (int index = 0; index < datasetLength; index++)
    {
        // Check if input is valid integer
        if (!(cin >> dataPoints[index]))
        {
            cerr << "Error: Invalid input detected at position " << (index + 1) << endl;
            cin.clear();             // Clear error state
            cin.ignore(10000, '\n'); // Discard bad input
            return false;
        }
    }
    return true;
}

// Function to calculate sum of all elements
int computeTotalSum(int *dataPoints, int datasetLength)
{
    // Validate inputs
    if (dataPoints == nullptr || datasetLength <= 0)
    {
        cerr << "Warning: Cannot compute sum of invalid array!" << endl;
        return 0;
    }

    int cumulativeSum = 0;
    // Loop through array and add each element
    for (int index = 0; index < datasetLength; index++)
    {
        cumulativeSum += dataPoints[index];
    }
    return cumulativeSum;
}

// Function to calculate average (mean) of array
double determineArithmeticMean(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
    {
        cerr << "Warning: Cannot calculate mean of invalid/empty array!" << endl;
        return 0.0;
    }
    return static_cast<double>(computeTotalSum(dataPoints, datasetLength)) / datasetLength;
}

bool containsNegativeValues(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
        return false;

    for (int index = 0; index < datasetLength; index++)
    {
        if (dataPoints[index] < 0)
        {
            return true;
        }
    }
    return false;
}

void displayResults(double meanValue, int datasetLength, bool hasNegatives)
{
    cout << "\n=== Statistical Analysis ===" << endl;
    cout << "Dataset size: " << datasetLength << endl;
    cout << "Arithmetic mean: " << fixed << setprecision(2) << meanValue << endl;
    if (hasNegatives)
    {
        cout << "Note: Dataset contains negative values" << endl;
    }
}

int main()
{
    int datasetLength;
    cout << "Enter the number of data points: ";

    if (!(cin >> datasetLength))
    {
        cerr << "Error: Invalid input! Please enter a valid integer." << endl;
        return 1;
    }

    if (datasetLength <= 0)
    {
        cerr << "Error: Dataset size must be positive!" << endl;
        return 1;
    }

    if (datasetLength > 1000000)
    {
        cerr << "Error: Dataset size too large (max 1,000,000)!" << endl;
        return 1;
    }

    int *numericalDataset = nullptr;
    try
    {
        numericalDataset = new int[datasetLength];
    }
    catch (const bad_alloc &e)
    {
        cerr << "Error: Memory allocation failed! " << e.what() << endl;
        return 1;
    }

    if (!populateDataset(numericalDataset, datasetLength))
    {
        cerr << "Error: Failed to populate dataset!" << endl;
        delete[] numericalDataset;
        return 1;
    }

    bool hasNegatives = containsNegativeValues(numericalDataset, datasetLength);
    double meanValue = determineArithmeticMean(numericalDataset, datasetLength);
    displayResults(meanValue, datasetLength, hasNegatives);

    delete[] numericalDataset;
    numericalDataset = nullptr;

    return 0;
}