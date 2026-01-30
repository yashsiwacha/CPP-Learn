#include <iostream>
#include <iomanip>
#include <numeric>
using namespace std;

// Populates the dynamic array with user input values
// Returns false if invalid input is detected
bool populateDataset(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
    {
        cerr << "Error: Invalid array or size!" << endl;
        return false;
    }

    cout << "Enter " << datasetLength << " numbers: ";
    for (int index = 0; index < datasetLength; index++)
    {
        if (!(cin >> dataPoints[index]))
        {
            cerr << "Error: Invalid input detected at position " << (index + 1) << endl;
            cin.clear();
            cin.ignore(10000, '\n');
            return false;
        }
    }
    return true;
}

// Computes the cumulative sum of all elements
// Returns 0 if array is invalid
int computeTotalSum(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
    {
        cerr << "Warning: Cannot compute sum of invalid array!" << endl;
        return 0;
    }

    int cumulativeSum = 0;
    for (int index = 0; index < datasetLength; index++)
    {
        cumulativeSum += dataPoints[index];
    }
    return cumulativeSum;
}

// Determines the arithmetic mean of the dataset
// Returns 0.0 if array is invalid or empty
double determineArithmeticMean(int *dataPoints, int datasetLength)
{
    if (dataPoints == nullptr || datasetLength <= 0)
    {
        cerr << "Warning: Cannot calculate mean of invalid/empty array!" << endl;
        return 0.0;
    }
    return static_cast<double>(computeTotalSum(dataPoints, datasetLength)) / datasetLength;
}

// Checks if array contains any negative values
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

// Displays formatted statistical results
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

    // Validate input stream
    if (!(cin >> datasetLength))
    {
        cerr << "Error: Invalid input! Please enter a valid integer." << endl;
        return 1;
    }

    // Validate dataset size
    if (datasetLength <= 0)
    {
        cerr << "Error: Dataset size must be positive!" << endl;
        return 1;
    }

    // Check for unreasonably large sizes to prevent memory issues
    if (datasetLength > 1000000)
    {
        cerr << "Error: Dataset size too large (max 1,000,000)!" << endl;
        return 1;
    }

    // Attempt dynamic memory allocation with error handling
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

    // Populate array with validation
    if (!populateDataset(numericalDataset, datasetLength))
    {
        cerr << "Error: Failed to populate dataset!" << endl;
        delete[] numericalDataset;
        return 1;
    }

    // Check for negative values
    bool hasNegatives = containsNegativeValues(numericalDataset, datasetLength);

    // Calculate and display results
    double meanValue = determineArithmeticMean(numericalDataset, datasetLength);
    displayResults(meanValue, datasetLength, hasNegatives);

    // Clean up memory
    delete[] numericalDataset;
    numericalDataset = nullptr;

    return 0;
}