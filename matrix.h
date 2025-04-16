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
         Matrix(int r, int c);                     // Constructor
         Matrix(const Matrix& other);              // Copy Constructor
         ~Matrix();                                // Destructor
         Matrix& operator=(const Matrix& other);   // Assignment Operator
 
         void setElement(int r, int c, double value);
         double getElement(int r, int c) const;
 
         void inputMatrix();
         void printMatrix() const;
 
         Matrix add(const Matrix& other) const;
         Matrix subtract(const Matrix& other) const;
         Matrix multiplyByScalar(double scalar) const;
         Matrix multiply(const Matrix& other) const;
         Matrix transpose() const;
 
         int getRows() const;
         int getCols() const;
 };
 
 #endif // MATRIX_H