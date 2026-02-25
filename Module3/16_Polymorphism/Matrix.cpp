/*
================================================================================
    COMBINING COMPILE-TIME & RUN-TIME POLYMORPHISM - MATRIX CLASS EXAMPLE
================================================================================

Purpose:
    This program demonstrates both types of polymorphism in C++:
    1. Compile-time Polymorphism (Static Binding)
    2. Run-time Polymorphism (Dynamic Binding)

Key Concepts:

    COMPILE-TIME POLYMORPHISM:
    -------------------------
    • Function Overloading: Multiple functions with same name but different parameters
      - setValue(int, int, int) for integer values
      - setValue(double, double, double) for double values

    • Operator Overloading: Custom behavior for standard operators
      - operator+ for element-wise matrix addition

    • Resolution: Determined at COMPILE-TIME based on function signatures
    • Performance: Fast (no runtime overhead)
    • Flexibility: Limited (fixed at compile time)

    RUN-TIME POLYMORPHISM:
    ----------------------
    • Virtual Functions: Base class declares virtual interface
      - virtual void display() const

    • Override in Derived Classes: Each provides its own implementation
      - SquareMatrix::display() - Square matrix specific formatting
      - IdentityMatrix::display() - Identity matrix specific representation

    • Resolution: Determined at RUN-TIME using vtable (virtual function table)
    • Performance: Slight overhead (vtable pointer lookup)
    • Flexibility: High (behavior determined at runtime based on actual object type)

Class Hierarchy:
    Matrix (Base Class)
    ├── SquareMatrix (Derived)
    └── IdentityMatrix (Derived)

Learning Outcomes:
    • Understand when to use compile-time vs run-time polymorphism
    • Recognize static vs dynamic binding in code
    • Apply both mechanisms together in real-world applications
    • Design flexible, extensible OOP systems

Author: C++ Learning Module - Polymorphism
Date: February 2026
================================================================================
*/

#include <iostream>
#include <vector>
#include <stdexcept>
#include <iomanip>

using namespace std;

// ============================================================================
// BASE CLASS: Matrix
// ============================================================================
// Represents a mathematical matrix with support for both compile-time and
// run-time polymorphism features.
// ============================================================================

class Matrix
{
protected:
    int rows;
    int cols;
    vector<vector<double>> data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c)
    {
        if (r <= 0 || c <= 0)
        {
            throw invalid_argument("Matrix dimensions must be positive");
        }
        data.resize(rows, vector<double>(cols, 0.0));
    }

    // Virtual destructor
    virtual ~Matrix() {}

    // RUN-TIME POLYMORPHISM: Virtual Function
    // Can be overridden by derived classes for custom display behavior
    virtual void display() const
    {
        cout << "\n=== Matrix (" << rows << "x" << cols << ") ===" << endl;
        for (int i = 0; i < rows; i++)
        {
            cout << "| ";
            for (int j = 0; j < cols; j++)
            {
                cout << setw(8) << fixed << setprecision(2) << data[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "==================" << endl;
    }

    // COMPILE-TIME POLYMORPHISM: Function Overloading
    // Overloaded setValue for integer values (version 1)
    void setValue(int row, int col, int value)
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            throw out_of_range("Index out of bounds");
        }
        data[row][col] = static_cast<double>(value);
    }

    // COMPILE-TIME POLYMORPHISM: Function Overloading
    // Overloaded setValue for double values (version 2)
    void setValue(double row, double col, double value)
    {
        int r = static_cast<int>(row);
        int c = static_cast<int>(col);
        if (r < 0 || r >= rows || c < 0 || c >= cols)
        {
            throw out_of_range("Index out of bounds");
        }
        data[r][c] = value;
    }

    // COMPILE-TIME POLYMORPHISM: Operator Overloading
    // Overloaded operator+ for element-wise matrix addition
    Matrix operator+(const Matrix &other) const
    {
        if (rows != other.rows || cols != other.cols)
        {
            throw invalid_argument("Matrix dimensions must match for addition");
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Getters
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    double getValue(int row, int col) const
    {
        if (row < 0 || row >= rows || col < 0 || col >= cols)
        {
            throw out_of_range("Index out of bounds");
        }
        return data[row][col];
    }
};

// ============================================================================
// DERIVED CLASS: SquareMatrix
// ============================================================================
// Specialized matrix where rows == cols (square property)
// Demonstrates RUN-TIME polymorphism by overriding display() method
// ============================================================================
class SquareMatrix : public Matrix
{
public:
    // Constructor - verifies square property
    SquareMatrix(int size) : Matrix(size, size)
    {
        if (size <= 0)
        {
            throw invalid_argument("Square matrix size must be positive");
        }
        cout << "SquareMatrix created with size " << size << "x" << size << endl;
    }

    // Verify if matrix is truly square (additional validation)
    bool isSquare() const
    {
        return rows == cols;
    }

    // RUN-TIME POLYMORPHISM: Override virtual function
    // Custom display with square matrix specific formatting
    void display() const override
    {
        cout << "\n=== Square Matrix (" << rows << "x" << cols << ") ===" << endl;
        if (!isSquare())
        {
            cout << "Warning: Matrix is not square!" << endl;
        }

        for (int i = 0; i < rows; i++)
        {
            cout << "| ";
            for (int j = 0; j < cols; j++)
            {
                cout << setw(8) << fixed << setprecision(2) << data[i][j] << " ";
            }
            cout << "|" << endl;
        }
        cout << "========================" << endl;
    }

    // Additional method to get diagonal elements
    vector<double> getDiagonal() const
    {
        if (!isSquare())
        {
            throw logic_error("Cannot get diagonal of non-square matrix");
        }

        vector<double> diagonal;
        for (int i = 0; i < rows; i++)
        {
            diagonal.push_back(data[i][i]);
        }
        return diagonal;
    }
};

// ============================================================================
// DERIVED CLASS: IdentityMatrix
// ============================================================================
// Special square matrix where diagonal elements are 1, all others are 0
// Demonstrates RUN-TIME polymorphism with distinctive display() override
// ============================================================================
class IdentityMatrix : public Matrix
{
public:
    // Constructor - creates an identity matrix
    IdentityMatrix(int size) : Matrix(size, size)
    {
        if (size <= 0)
        {
            throw invalid_argument("Identity matrix size must be positive");
        }

        // Set diagonal elements to 1
        for (int i = 0; i < size; i++)
        {
            data[i][i] = 1.0;
        }
        cout << "IdentityMatrix created with size " << size << "x" << size << endl;
    }

    // RUN-TIME POLYMORPHISM: Override virtual function
    // Custom display highlighting identity matrix properties
    void display() const override
    {
        cout << "\n=== Identity Matrix (" << rows << "x" << cols << ") ===" << endl;
        cout << "Properties: All diagonal elements = 1, All other elements = 0" << endl;

        for (int i = 0; i < rows; i++)
        {
            cout << "| ";
            for (int j = 0; j < cols; j++)
            {
                if (i == j)
                {
                    // Highlight diagonal with different formatting
                    cout << setw(8) << fixed << setprecision(2) << "[" << data[i][j] << "]";
                }
                else
                {
                    cout << setw(8) << fixed << setprecision(2) << data[i][j] << " ";
                }
            }
            cout << " |" << endl;
        }
        cout << "========================" << endl;
    }

    // Verify if matrix maintains identity property
    bool isIdentity() const
    {
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < cols; j++)
            {
                if (i == j && data[i][j] != 1.0)
                    return false;
                if (i != j && data[i][j] != 0.0)
                    return false;
            }
        }
        return true;
    }
};

// Main function to demonstrate both compile-time and run-time polymorphism
int main()
{
    try
    {
        cout << "\n"
             << string(80, '=') << endl;
        cout << "   COMBINING COMPILE-TIME & RUN-TIME POLYMORPHISM - MATRIX CLASS EXAMPLE" << endl;
        cout << string(80, '=') << endl;

        cout << "\nThis program demonstrates two types of polymorphism in C++:" << endl;
        cout << "1. COMPILE-TIME POLYMORPHISM (Static Binding):" << endl;
        cout << "   - Function Overloading: setValue(int, int, int) vs setValue(double, double, double)" << endl;
        cout << "   - Operator Overloading: operator+ for matrix addition" << endl;
        cout << "\n2. RUN-TIME POLYMORPHISM (Dynamic Binding):" << endl;
        cout << "   - Virtual Functions: display() overridden in derived classes" << endl;
        cout << "   - Dynamic Dispatch: Base pointer calling derived class methods" << endl;

        // ========================================================================
        // PART 1: COMPILE-TIME POLYMORPHISM (FUNCTION OVERLOADING)
        // ========================================================================
        cout << "\n"
             << string(80, '-') << endl;
        cout << "PART 1: COMPILE-TIME POLYMORPHISM - FUNCTION OVERLOADING" << endl;
        cout << string(80, '-') << endl;
        cout << "\nMechanism: The compiler determines which setValue() to call based on argument types." << endl;
        cout << "Binding Time: COMPILE-TIME (Static Binding)\n"
             << endl;

        SquareMatrix matrix1(3);

        cout << "1. Calling setValue(int, int, int) - Integer version:" << endl;
        matrix1.setValue(0, 0, 10); // int, int, int -> calls int version
        matrix1.setValue(0, 1, 20);
        matrix1.setValue(0, 2, 30);
        cout << "   setValue(0, 0, 10) - Resolved at COMPILE-TIME to int version\n"
             << endl;

        cout << "2. Calling setValue(double, double, double) - Double version:" << endl;
        matrix1.setValue(1.0, 0.0, 15.5); // double, double, double -> calls double version
        matrix1.setValue(1.0, 1.0, 25.75);
        matrix1.setValue(1.0, 2.0, 35.25);
        cout << "   setValue(1.0, 0.0, 15.5) - Resolved at COMPILE-TIME to double version\n"
             << endl;

        matrix1.setValue(2, 0, 5);
        matrix1.setValue(2, 1, 15);
        matrix1.setValue(2, 2, 25);

        cout << "Result Matrix (showing both int and double values):" << endl;
        matrix1.display();

        cout << "ANALYSIS: The compiler selected the correct function at compile-time based on" << endl;
        cout << "          the types of arguments passed. No runtime overhead!\n"
             << endl;

        // ========================================================================
        // PART 2: COMPILE-TIME POLYMORPHISM (OPERATOR OVERLOADING)
        // ========================================================================
        cout << "\n"
             << string(80, '-') << endl;
        cout << "PART 2: COMPILE-TIME POLYMORPHISM - OPERATOR OVERLOADING" << endl;
        cout << string(80, '-') << endl;
        cout << "\nMechanism: operator+ is overloaded to perform element-wise matrix addition." << endl;
        cout << "Binding Time: COMPILE-TIME (Static Binding)\n"
             << endl;

        SquareMatrix matrixA(2);
        matrixA.setValue(0, 0, 1);
        matrixA.setValue(0, 1, 2);
        matrixA.setValue(1, 0, 3);
        matrixA.setValue(1, 1, 4);

        SquareMatrix matrixB(2);
        matrixB.setValue(0, 0, 5);
        matrixB.setValue(0, 1, 6);
        matrixB.setValue(1, 0, 7);
        matrixB.setValue(1, 1, 8);

        cout << "Matrix A:" << endl;
        matrixA.display();

        cout << "\nMatrix B:" << endl;
        matrixB.display();

        cout << "\nPerforming: Matrix C = Matrix A + Matrix B" << endl;
        cout << "Using overloaded operator+ (resolved at COMPILE-TIME)\n"
             << endl;

        Matrix matrixC = matrixA + matrixB; // operator+ resolved at compile-time

        cout << "Result Matrix C:" << endl;
        matrixC.display();

        cout << "ANALYSIS: The '+' operator was overloaded for Matrix objects. The compiler" << endl;
        cout << "          knows which operation to perform at compile-time.\n"
             << endl;

        // ========================================================================
        // PART 3: RUN-TIME POLYMORPHISM (VIRTUAL FUNCTIONS)
        // ========================================================================
        cout << "\n"
             << string(80, '-') << endl;
        cout << "PART 3: RUN-TIME POLYMORPHISM - VIRTUAL FUNCTIONS & DYNAMIC DISPATCH" << endl;
        cout << string(80, '-') << endl;
        cout << "\nMechanism: display() is virtual in base class, overridden in derived classes." << endl;
        cout << "Binding Time: RUN-TIME (Dynamic Binding via vtable)\n"
             << endl;

        // Create different matrix types
        SquareMatrix square(3);
        square.setValue(0, 0, 1);
        square.setValue(0, 1, 2);
        square.setValue(0, 2, 3);
        square.setValue(1, 0, 4);
        square.setValue(1, 1, 5);
        square.setValue(1, 2, 6);
        square.setValue(2, 0, 7);
        square.setValue(2, 1, 8);
        square.setValue(2, 2, 9);

        IdentityMatrix identity(3);

        Matrix baseMatrix(2, 3);
        baseMatrix.setValue(0, 0, 10);
        baseMatrix.setValue(0, 1, 20);
        baseMatrix.setValue(0, 2, 30);
        baseMatrix.setValue(1, 0, 40);
        baseMatrix.setValue(1, 1, 50);
        baseMatrix.setValue(1, 2, 60);

        // Store base class pointers pointing to different derived objects
        cout << "Creating an array of base class pointers (Matrix*) pointing to different objects:\n"
             << endl;

        vector<Matrix *> matrices;
        matrices.push_back(&baseMatrix);
        matrices.push_back(&square);
        matrices.push_back(&identity);

        cout << "Now calling display() through base pointers..." << endl;
        cout << "The CORRECT version is determined at RUN-TIME based on actual object type!\n"
             << endl;

        for (size_t i = 0; i < matrices.size(); i++)
        {
            cout << "\n--- Calling matrices[" << i << "]->display() ---" << endl;
            cout << "Object Type: ";

            if (dynamic_cast<IdentityMatrix *>(matrices[i]))
                cout << "IdentityMatrix (resolved at runtime)" << endl;
            else if (dynamic_cast<SquareMatrix *>(matrices[i]))
                cout << "SquareMatrix (resolved at runtime)" << endl;
            else
                cout << "Matrix (base class)" << endl;

            // This call is resolved at RUN-TIME through virtual function table (vtable)
            matrices[i]->display();
        }

        cout << "\nANALYSIS: Even though all are Matrix* pointers, each calls its own display()." << endl;
        cout << "          This is determined at RUN-TIME using the vtable mechanism." << endl;
        cout << "          Small runtime overhead but provides great flexibility!\n"
             << endl;

        // ========================================================================
        // PART 4: COMBINING BOTH TYPES OF POLYMORPHISM
        // ========================================================================
        cout << "\n"
             << string(80, '-') << endl;
        cout << "PART 4: COMBINING COMPILE-TIME & RUN-TIME POLYMORPHISM" << endl;
        cout << string(80, '-') << endl;
        cout << "\nDemonstrating how both mechanisms work together in the same code:\n"
             << endl;

        SquareMatrix mat1(2);
        SquareMatrix mat2(2);

        // COMPILE-TIME: Function overloading (setValue)
        cout << "1. Using COMPILE-TIME polymorphism (function overloading):" << endl;
        mat1.setValue(0, 0, 100);       // int version - compile-time
        mat1.setValue(0.0, 1.0, 200.5); // double version - compile-time
        mat1.setValue(1, 0, 300);
        mat1.setValue(1, 1, 400);

        mat2.setValue(0, 0, 50);
        mat2.setValue(0, 1, 60);
        mat2.setValue(1, 0, 70);
        mat2.setValue(1, 1, 80);

        cout << "   setValue() calls resolved at COMPILE-TIME based on argument types\n"
             << endl;

        // COMPILE-TIME: Operator overloading
        cout << "2. Using COMPILE-TIME polymorphism (operator overloading):" << endl;
        Matrix sum = mat1 + mat2; // operator+ resolved at compile-time
        cout << "   operator+ resolved at COMPILE-TIME\n"
             << endl;

        // RUN-TIME: Virtual function
        cout << "3. Using RUN-TIME polymorphism (virtual function):" << endl;
        Matrix *ptr = &sum;
        cout << "   Calling display() through base pointer (resolved at RUN-TIME):" << endl;
        ptr->display(); // display() resolved at runtime

        cout << "ANALYSIS: This code used:" << endl;
        cout << "          - STATIC binding for setValue() and operator+" << endl;
        cout << "          - DYNAMIC binding for display()" << endl;
        cout << "          Both mechanisms coexist and complement each other!\n"
             << endl;

        // ========================================================================
        // SUMMARY
        // ========================================================================
        cout << "\n"
             << string(80, '=') << endl;
        cout << "SUMMARY: COMPILE-TIME vs RUN-TIME POLYMORPHISM" << endl;
        cout << string(80, '=') << endl;

        cout << "\n┌─────────────────────────────────────────────────────────────────────┐" << endl;
        cout << "│ COMPILE-TIME POLYMORPHISM (Static Binding)                         │" << endl;
        cout << "├─────────────────────────────────────────────────────────────────────┤" << endl;
        cout << "│ • Function Overloading: Multiple functions with same name          │" << endl;
        cout << "│ • Operator Overloading: Custom behavior for operators              │" << endl;
        cout << "│ • Resolved at: COMPILE TIME                                        │" << endl;
        cout << "│ • Performance: Fast (no runtime overhead)                          │" << endl;
        cout << "│ • Flexibility: Limited (fixed at compile time)                     │" << endl;
        cout << "│ • Examples: setValue(), operator+                                  │" << endl;
        cout << "└─────────────────────────────────────────────────────────────────────┘" << endl;

        cout << "\n┌─────────────────────────────────────────────────────────────────────┐" << endl;
        cout << "│ RUN-TIME POLYMORPHISM (Dynamic Binding)                            │" << endl;
        cout << "├─────────────────────────────────────────────────────────────────────┤" << endl;
        cout << "│ • Virtual Functions: Base class defines interface                  │" << endl;
        cout << "│ • Override in Derived: Each class provides implementation          │" << endl;
        cout << "│ • Resolved at: RUN TIME (via vtable)                               │" << endl;
        cout << "│ • Performance: Slight overhead (vtable lookup)                     │" << endl;
        cout << "│ • Flexibility: High (behavior determined at runtime)               │" << endl;
        cout << "│ • Examples: display() virtual function                             │" << endl;
        cout << "└─────────────────────────────────────────────────────────────────────┘" << endl;

        cout << "\n"
             << string(80, '=') << endl;
        cout << "PROGRAM COMPLETED SUCCESSFULLY!" << endl;
        cout << string(80, '=') << endl
             << endl;
    }
    catch (const exception &e)
    {
        cerr << "\n[ERROR] " << e.what() << endl;
        return 1;
    }

    return 0;
}
