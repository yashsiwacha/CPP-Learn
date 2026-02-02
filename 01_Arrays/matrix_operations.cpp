// Program to perform matrix operations (addition, subtraction, multiplication, transpose)
#include <iostream>
#include <iomanip>
using namespace std;

void getDimensions(int &rows, int &cols, const string &matrixName)
{
    do
    {
        cout << "Enter dimensions for " << matrixName << " (rows columns): ";
        cin >> rows >> cols;

        if (rows <= 0 || cols <= 0)
        {
            cout << "ERROR: Dimensions must be positive integers. Please try again.\n";
        }
        else if (rows > 100 || cols > 100)
        {
            cout << "ERROR: Dimensions cannot exceed 100x100. Please try again.\n";
        }
        else
        {
            break;
        }
    } while (true);
}

void inputMatrix(int rows, int cols, int matrix[][100], const string &matrixName)
{
    cout << "\nEntering elements for " << matrixName << " (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << "  Element [" << i + 1 << "][" << j + 1 << "]: ";
            cin >> matrix[i][j];
        }
    }
    cout << matrixName << " input complete!\n";
}

void addMatrix(int rows, int cols, int matrix1[][100], int matrix2[][100], int result[][100])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

void subtractMatrix(int rows, int cols, int matrix1[][100], int matrix2[][100], int result[][100])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

void multiplyMatrices(int r1, int c1, int r2, int c2, int mat1[][100], int mat2[][100], int result[][100])
{
    for (int i = 0; i < r1; i++)
    {
        for (int j = 0; j < c2; j++)
        {
            result[i][j] = 0;

            for (int k = 0; k < c1; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

void transposeMatrix(int rows, int cols, int matrix[][100], int result[][100])
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result[j][i] = matrix[i][j];
        }
    }
}

// Enhanced function to print the matrix with improved formatting.
void printMatrix(int rows, int cols, int matrix[][100])
{
    cout << "\n";

    // Handle edge case: single element matrix
    if (rows == 1 && cols == 1)
    {
        cout << "[ " << matrix[0][0] << " ]\n\n";
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        cout << "[ ";
        for (int j = 0; j < cols; j++)
        {
            cout << setw(6) << matrix[i][j];
            if (j < cols - 1)
                cout << " ";
        }
        cout << " ]" << endl;
    }
    cout << endl;
}

// Helper function to handle two-matrix operations (addition/subtraction)
bool getTwoMatricesSameDimensions(int mat1[][100], int mat2[][100], int &rows, int &cols)
{
    int rows2, cols2;

    getDimensions(rows, cols, "first matrix");
    getDimensions(rows2, cols2, "second matrix");

    // Validate that both matrices have the same dimensions
    if (rows != rows2 || cols != cols2)
    {
        cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
        cout << "║                    DIMENSION MISMATCH                     ║\n";
        cout << "╚═══════════════════════════════════════════════════════════╝\n";
        cout << "For this operation, both matrices must have identical dimensions.\n";
        cout << "  • First matrix:  " << rows << " x " << cols << "\n";
        cout << "  • Second matrix: " << rows2 << " x " << cols2 << "\n";
        cout << "\nPlease ensure both matrices have the same number of rows and columns.\n\n";
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

    cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
    cout << "║           MATRIX OPERATIONS CALCULATOR                    ║\n";
    cout << "╚═══════════════════════════════════════════════════════════╝\n";
    cout << "  1. Addition of Two Matrices\n";
    cout << "  2. Subtraction of Two Matrices\n";
    cout << "  3. Multiplication of Two Matrices\n";
    cout << "  4. Transpose of a Matrix\n";
    cout << "  5. Exit\n";
    cout << "═════════════════════════════════════════════════════════════\n";
    cout << "Enter your choice (1-5): ";
    cin >> choice;

    switch (choice)
    {
    case 1: // Addition
        cout << "\n>>> MATRIX ADDITION <<<\n";
        cout << "Both matrices must have the same dimensions.\n\n";

        if (getTwoMatricesSameDimensions(mat1, mat2, rows1, cols1))
        {
            addMatrix(rows1, cols1, mat1, mat2, result);
            cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
            cout << "║              RESULT OF ADDITION (" << rows1 << "x" << cols1 << ")                 ║\n";
            cout << "╚═══════════════════════════════════════════════════════════╝";
            printMatrix(rows1, cols1, result);
        }
        break;

    case 2: // Subtraction
        cout << "\n>>> MATRIX SUBTRACTION <<<\n";
        cout << "Both matrices must have the same dimensions.\n\n";

        if (getTwoMatricesSameDimensions(mat1, mat2, rows1, cols1))
        {
            subtractMatrix(rows1, cols1, mat1, mat2, result);
            cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
            cout << "║            RESULT OF SUBTRACTION (" << rows1 << "x" << cols1 << ")              ║\n";
            cout << "╚═══════════════════════════════════════════════════════════╝";
            printMatrix(rows1, cols1, result);
        }
        break;

    case 3: // Multiplication
        cout << "\n>>> MATRIX MULTIPLICATION <<<\n";
        cout << "Note: Columns of first matrix must equal rows of second matrix.\n\n";

        getDimensions(rows1, cols1, "first matrix");
        getDimensions(rows2, cols2, "second matrix");

        // Validate dimensions for multiplication
        if (cols1 != rows2)
        {
            cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
            cout << "║              MULTIPLICATION NOT POSSIBLE                  ║\n";
            cout << "╚═══════════════════════════════════════════════════════════╝\n";
            cout << "Matrix multiplication requires:\n";
            cout << "  • Columns of first matrix = Rows of second matrix\n\n";
            cout << "Your dimensions:\n";
            cout << "  • First matrix:  " << rows1 << " x " << cols1 << " (columns = " << cols1 << ")\n";
            cout << "  • Second matrix: " << rows2 << " x " << cols2 << " (rows = " << rows2 << ")\n";
            cout << "\nPlease adjust your matrix dimensions and try again.\n\n";
            break;
        }

        inputMatrix(rows1, cols1, mat1, "first matrix");
        inputMatrix(rows2, cols2, mat2, "second matrix");

        multiplyMatrices(rows1, cols1, rows2, cols2, mat1, mat2, result);

        cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
        cout << "║          RESULT OF MULTIPLICATION (" << rows1 << "x" << cols2 << ")             ║\n";
        cout << "╚═══════════════════════════════════════════════════════════╝";
        printMatrix(rows1, cols2, result);
        break;

    case 4: // Transpose
        cout << "\n>>> MATRIX TRANSPOSE <<<\n";
        cout << "The transpose swaps rows and columns of the matrix.\n\n";

        getDimensions(rows1, cols1, "matrix");
        inputMatrix(rows1, cols1, mat1, "matrix");

        transposeMatrix(rows1, cols1, mat1, result);

        cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
        cout << "║       TRANSPOSE OF MATRIX (" << cols1 << "x" << rows1 << " from " << rows1 << "x" << cols1 << ")        ║\n";
        cout << "╚═══════════════════════════════════════════════════════════╝";
        printMatrix(cols1, rows1, result); // Dimensions are swapped
        break;

    case 5: // Exit
        cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
        cout << "║           Thank you for using this program!               ║\n";
        cout << "╚═══════════════════════════════════════════════════════════╝\n\n";
        break;

    default:
        cout << "\n╔═══════════════════════════════════════════════════════════╗\n";
        cout << "║                     INVALID CHOICE                        ║\n";
        cout << "╚═══════════════════════════════════════════════════════════╝\n";
        cout << "Please enter a number between 1 and 5.\n\n";
        break;
    }

    return 0;
}