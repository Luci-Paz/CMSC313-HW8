/**
 * @file matrix.h
 * @brief Header file for the Matrix class
 * @details This file contains the declaration of the Matrix class, which provides
 *          basic matrix operations such as addition, subtraction, multiplication,
 *          division, and transposition. The class uses a 2D vector to store the matrix
 *          data and provides methods to manipulate and access the matrix elements.
 * @author Lucian Pazour
 * @date (yy-dd-mm) 2025-16-04
 */



 #ifndef MATRIX_H
 #define MATRIX_H
 
 class Matrix {
     private:
         int rows;
         int cols;
         double** data;
 
         void allocateMemory();
         void deallocateMemory();
 
     public:
         Matrix(int rows, int cols, double initVal);    // Constructor
         Matrix(const Matrix& secondMat);               // Copy Constructor
         ~Matrix();                                     // Destructor
         Matrix& operator=(const Matrix& secondMat);    // Assignment Operator

         // return the number of rows and columns
         int getRows() const;
         int getCols() const;

         // Set and get element at (row, col)
         void setElement(int row, int col, double value);
         double getElement(int row, int col) const;

         // Add initial values to matrix
         void inputMatrix();

         // Print the matrix
         void printMatrix() const;
 
         // Matrix operations
         // Add, subtract, multiply by scalar, multiply, and transpose
         Matrix operator+(const Matrix& secondMat) const;
         Matrix operator-(const Matrix& secondMat) const;
         Matrix operator*(double scalar) const;
         Matrix operator*(const Matrix& secondMat) const;
         Matrix transpose() const;

 };
 
 #endif // MATRIX_H