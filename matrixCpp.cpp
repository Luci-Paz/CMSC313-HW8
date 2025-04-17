/**
 * @file matrixC.h 
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
 #include "matrixCpp.h"
 //using namespace std;
 

 // Default Constructor
Matrix::Matrix() : rows(0), cols(0), data(nullptr) {
     // No initialization needed
 } // end default constructor


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
// Get the number of rows and columns in the matrix
 int Matrix::getRows() const { return rows; }
 int Matrix::getCols() const { return cols; }


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
     std::cout << "Enter elements (" << rows << "x" << cols << "):\n";
     
     // Loop through each element and prompt user for input
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j) {
             std::cout << "Element [" << i << "][" << j << "]: ";
             std::cin >> data[i][j];
         } //end inner for loop
    // end outer for loop
 } // end inputMatrix


 // Method to print the matrix
 void Matrix::printMatrix() const {

    // loop through each element and display it
     for (int i = 0; i < rows; ++i) {
        
        std::cout << "|";
        for (int j = 0; j < cols; ++j)
             std::cout << std::setw(5) << data[i][j] << " "; 
            // end inner for loop
         
         std::cout << "|" << "\n";
     } //end outer for loop
    std::cout << std::endl;
 } //end printMatrix
 

// Matrix operations ============================================================
// Operator override to add two matrices
 Matrix Matrix::operator+(const Matrix& secondMat) const {
    
    // Check if the dimensions of the matricies are the same
    if (rows != secondMat.rows || cols != secondMat.cols) {
         std::cout << "Addition error: matrix dimensions do not match.\n";
         return Matrix(0, 0, 0); // Return an empty matrix
     } //end if
 

     // Create a new matrix to store and return the result
     Matrix result(rows, cols, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
            // add the elements of the two matrices
             result.data[i][j] = data[i][j] + secondMat.data[i][j];
            // end inner for loop
        // end outer for loop

     return result;
 } // end operator+
 

// Operator override to subtract two matrices
 Matrix Matrix::operator-(const Matrix& secondMat) const {
     if (rows != secondMat.rows || cols != secondMat.cols) {
        std::cout << "Subtraction error: matrix dimensions do not match.\n";
        return Matrix(0, 0, 0); // Return an empty matrix
     } //end if
 

    // Create a new matrix to store and return the result
     Matrix result(rows, cols, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
            // subtract the elements of the two matrices
             result.data[i][j] = data[i][j] - secondMat.data[i][j];
            // end inner for loop
        // end outer for loop

     return result;
 } //end operator-
 

 // Operator override to multiply a matrix by a scalar
 Matrix Matrix::operator*(double scalar) const {
    
    // Create a new matrix to store and return the result    
     Matrix result(rows, cols, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
            // multiply each element by the scalar
             result.data[i][j] = data[i][j] * scalar;
            // end inner for loop
        // end outer for loop

     return result;
 } // end operator*(scalar)


// Friend function to multiply a scalar by a matrix
Matrix operator*(double scalar, const Matrix& secondMat) {
    
     // Create a new matrix to store and return the result
     Matrix result(secondMat.rows, secondMat.cols, 0);
     for (int i = 0; i < secondMat.rows; ++i)
         for (int j = 0; j < secondMat.cols; ++j)
            // multiply each element by the scalar
             result.data[i][j] = scalar * secondMat.data[i][j];
            // end inner for loop
        // end outer for loop

     return result;
 } // end operator*(scalar, matrix)
 

 // Operator override to multiply two matrices
 Matrix Matrix::operator*(const Matrix& secondMat) const {
     
    // Check if the matrices can be multiplied
     if (cols != secondMat.rows) {
         std::cout << "Multiplication error: incompatible matrix dimensions.\n";
         return Matrix(0, 0, 0); // Return an empty matrix
     } //end if

 
     // Create a new matrix to store and return the result
     Matrix result(rows, secondMat.cols, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < secondMat.cols; ++j)
             for (int k = 0; k < cols; ++k)
                // multiply and add the elements of the two matrices
                 result.data[i][j] += data[i][k] * secondMat.data[k][j];
                // end k for loop
            // end j for loop
        // end i for loop

     return result;
 } // end operator*(matrix)
 

 // Method to return the transpose of the matrix
 Matrix Matrix::transpose() const {

    // Create a new matrix to store and return the result
     Matrix result(cols, rows, 0);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
            // swap the rows and columns
             result.data[j][i] = data[i][j];
            // end inner for loop
        // end outer for loop

     return result;
 } // end transpose

 // end matrix.cpp
 
