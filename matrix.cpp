/**
 * @file matrix.cpp
 * @brief Implementation of the Matrix class
 * @details This file contains the implementation of the Matrix class, which provides
 *          basic matrix operations such as addition, subtraction, multiplication,
 *          division, and transposition. The class uses a 2D vector to store the matrix
 *          data and provides methods to manipulate and access the matrix elements.
 * @author Lucian Pazour
 * @date (yy-dd-mm) 2025-16-04
 */

 #include <iostream>
 #include <iomanip>
 #include "matrix.h"
 using namespace std;
 
 // Constructor
 Matrix::Matrix(int rows, int cols, double initVal) : rows(rows), cols(cols) {
     allocateMemory();

    // Initialize the matrix with the given value
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            data[i][j] = initVal;
        //end inner for loop
    //end outer for loop
 } // end constructor
 

 // Copy Constructor
 Matrix::Matrix(const Matrix& secondMat) : rows(secondMat.rows), cols(secondMat.cols) {
     allocateMemory();
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             data[i][j] = secondMat.data[i][j];
            // end inner for loop
        // end outer for loop
 } //end copy constructor
 

 // Destructor
 Matrix::~Matrix() {
     deallocateMemory();
 } // end destructor


 // Assignment Operator to assign one matrix to another
 Matrix& Matrix::operator=(const Matrix& secondMat) {
     if (this == &secondMat) return *this;

     // Deallocate current memory and allocate new memory
     deallocateMemory();
     rows = secondMat.rows;
     cols = secondMat.cols;
     allocateMemory();
    
     // Copy the elements from the second matrix
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             data[i][j] = secondMat.data[i][j];
            // end inner for loop
        // end outer for loop
     
     return *this;
 } // end assignment operator
 

 // Private Methods =================================================================
 // Private method to allocate memory for the matrix
 void Matrix::allocateMemory() {
     data = new double*[rows];
     for (int i = 0; i < rows; ++i)
         data[i] = new double[cols]();
 } //end allocateMemory
 

 // Private method to deallocate memory for the matrix
 void Matrix::deallocateMemory() {
     for (int i = 0; i < rows; ++i)
         delete[] data[i];
     delete[] data;
 } //end deallocateMemory
 

 // Public Methods ==================================================================
 // Public methods to set and get elements of the matrix
 // Set the value of a specific element in the matrix
 void Matrix::setElement(int row, int col, double value) {
     data[row][col] = value;
 } //end setElement
 

 // Get the value of a specific element in the matrix
 double Matrix::getElement(int row, int col) const {
     return data[row][col];
 } //end getElement

 
 // Method to input matrix elements from user
 void Matrix::inputMatrix() {
     cout << "Enter elements (" << rows << "x" << cols << "):\n";
     
     // Loop through each element and prompt user for input
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j) {
             cout << "Element [" << i << "][" << j << "]: ";
             cin >> data[i][j];
         } //end inner for loop
    // end outer for loop
 } // end inputMatrix


 // Method to print the matrix
 void Matrix::printMatrix() const {

    // loop through each element and display it
     for (int i = 0; i < rows; ++i) {
         for (int j = 0; j < cols; ++j)
             cout << setw(10) << data[i][j] << " "; 
            // end inner for loop
         
         cout << "\n";
     } //end outer for loop
 } //end printMatrix
 

// Matrix operations ============================================================
// Method to add two matrices
 Matrix Matrix::add(const Matrix& secondMat) const {
     if (rows != secondMat.rows || cols != secondMat.cols) {
         cerr << "Addition error: matrix dimensions do not match.\n";
         exit(EXIT_FAILURE);
     }
 
     Matrix result(rows, cols, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             result.data[i][j] = data[i][j] + secondMat.data[i][j];
     return result;
 }
 
 Matrix Matrix::subtract(const Matrix& secondMat) const {
     if (rows != secondMat.rows || cols != secondMat.cols) {
         cerr << "Subtraction error: matrix dimensions do not match.\n";
         exit(EXIT_FAILURE);
     }
 
     Matrix result(rows, cols, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             result.data[i][j] = data[i][j] - secondMat.data[i][j];
     return result;
 }
 
 Matrix Matrix::multiplyByScalar(double scalar) const {
     Matrix result(rows, cols, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             result.data[i][j] = data[i][j] * scalar;
     return result;
 }
 
 Matrix Matrix::multiply(const Matrix& secondMat) const {
     if (cols != secondMat.rows) {
         cerr << "Multiplication error: incompatible matrix dimensions.\n";
         exit(EXIT_FAILURE);
     }
 
     Matrix result(rows, secondMat.cols, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < secondMat.cols; ++j)
             for (int k = 0; k < cols; ++k)
                 result.data[i][j] += data[i][k] * secondMat.data[k][j];
     return result;
 }
 
 Matrix Matrix::transpose() const {
     Matrix result(cols, rows, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             result.data[j][i] = data[i][j];
     return result;
 }
 
 int Matrix::getRows() const { return rows; }
 int Matrix::getCols() const { return cols; }