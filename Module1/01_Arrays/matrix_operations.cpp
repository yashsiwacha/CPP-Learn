// Program to perform matrix operations (addition, subtraction, multiplication, transpose)
#include <iostream>
#include <iomanip>
using namespace std;

// Get matrix dimensions from user
void getDimensions(int &rows, int &cols, const string &matrixName)
{
    do
    {
        cout << "Enter dimensions for " << matrixName << " (rows columns): ";
        cin >> rows >> cols;

        if (rows <= 0 || cols <= 0)
            cout << "Error: Dimensions must be positive.\n";
        else if (rows > 100 || cols > 100)
            cout << "Error: Dimensions cannot exceed 100x100.\n";
        else
            break;
    } while (true);
}

// Input matrix elements from user
void inputMatrix(int rows, int cols, int matrix[][100], const string &matrixName)
{
    cout << "\nEnter elements for " << matrixName << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "  [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Add two matrices
void addMatrix(int rows, int cols, int matrix1[][100], int matrix2[][100], int result[][100])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] + matrix2[i][j];
}

// Subtract two matrices
void subtractMatrix(int rows, int cols, int matrix1[][100], int matrix2[][100], int result[][100])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = matrix1[i][j] - matrix2[i][j];
}

// Multiply two matrices
void multiplyMatrices(int r1, int c1, int r2, int c2, int mat1[][100], int mat2[][100], int result[][100])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;
            for (int k = 0; k < c1; k++)
                result[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

// Transpose a matrix
void transposeMatrix(int rows, int cols, int matrix[][100], int result[][100])
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[j][i] = matrix[i][j];
}

// Print matrix
void printMatrix(int rows, int cols, int matrix[][100])
{
    cout << "\n";
    for (int i = 0; i < rows; i++)
    {
        cout << "[ ";
        for (int j = 0; j < cols; j++)
        {
            cout << setw(6) << matrix[i][j];
            if (j < cols - 1)
                cout << " ";
        }
        cout << " ]\n";
    }
    cout << endl;
}

// Get two matrices with same dimensions for addition/subtraction
bool getTwoMatricesSameDimensions(int mat1[][100], int mat2[][100], int &rows, int &cols)
{
    int rows2, cols2;

    getDimensions(rows, cols, "first matrix");
    getDimensions(rows2, cols2, "second matrix");

    if (rows != rows2 || cols != cols2)
    {
        cout << "\nError: Matrices must have same dimensions.\n";
        cout << "First: " << rows << "x" << cols << ", Second: " << rows2 << "x" << cols2 << "\n\n";
        return false;
    }

    inputMatrix(rows, cols, mat1, "first matrix");
    inputMatrix(rows, cols, mat2, "second matrix");
    return true;
}
int main()
{
    int mat1[100][100], mat2[100][100], result[100][100];
    int rows1, cols1, rows2, cols2;
    int choice;

    cout << "\nMatrix Operations\n";
    cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Transpose\n5. Exit\n";
    cout << "Choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1: // Addition
        cout << "\nMatrix Addition\n";
        if (getTwoMatricesSameDimensions(mat1, mat2, rows1, cols1))
        {
            addMatrix(rows1, cols1, mat1, mat2, result);
            cout << "\nResult (" << rows1 << "x" << cols1 << "):";
            printMatrix(rows1, cols1, result);
        }
        break;

    case 2: // Subtraction
        cout << "\nMatrix Subtraction\n";
        if (getTwoMatricesSameDimensions(mat1, mat2, rows1, cols1))
        {
            subtractMatrix(rows1, cols1, mat1, mat2, result);
            cout << "\nResult (" << rows1 << "x" << cols1 << "):";
            printMatrix(rows1, cols1, result);
        }
        break;

    case 3: // Multiplication
        cout << "\nMatrix Multiplication\n";
        getDimensions(rows1, cols1, "first matrix");
        getDimensions(rows2, cols2, "second matrix");

        if (cols1 != rows2)
        {
            cout << "\nError: Cannot multiply. Columns of first (" << cols1 << ") must equal rows of second (" << rows2 << ")\n";
            break;
        }

        inputMatrix(rows1, cols1, mat1, "first matrix");
        inputMatrix(rows2, cols2, mat2, "second matrix");

        multiplyMatrices(rows1, cols1, rows2, cols2, mat1, mat2, result);
        cout << "\nResult (" << rows1 << "x" << cols2 << "):";
        printMatrix(rows1, cols2, result);
        break;

    case 4: // Transpose
        cout << "\nMatrix Transpose\n";
        getDimensions(rows1, cols1, "matrix");
        inputMatrix(rows1, cols1, mat1, "matrix");
        transposeMatrix(rows1, cols1, mat1, result);
        cout << "\nTranspose (" << cols1 << "x" << rows1 << "):";
        printMatrix(cols1, rows1, result);
        break;

    case 5:
        break;

    default:
        cout << "\nInvalid choice\n";
        break;
    }

    return 0;
}