/**
 * @file matrixC.h
 * @brief Implementation file for the Matrix struct
 * @details This file contains the implementation of the Matrix struct, which provides
 *          basic matrix operations such as addition, subtraction, multiplication,
 *          and transposition. The struct uses a 2D array to store the matrix
 *          data and provides functions to manipulate and access the matrix elements.
 * @author Lucian Pazour
 * @date (yy-dd-mm) 2025-18-04
 */


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "matrixC.h"


// Function to create a matrix with given dimensions and initial value
Matrix createMatrix(int rows, int cols, double initVal) {
    
    Matrix m;   
    m.rows = rows;
    m.cols = cols;
    
    // Allocate memory for the matrix
    m.data = (double**)malloc(rows * sizeof(double*));

    // Allocate memory for each row
    for (int i = 0; i < rows; ++i) {
        
        // Allocate memory for each column
        m.data[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; ++j)
            m.data[i][j] = initVal;
        // end inner for loop
    } // end outer for loop

    return m;
} // end createMatrix


// Private helper function to check matrix dimensions
static bool dimensionTest(const Matrix* a, const Matrix* b, const int choice) {
    
    // Check if add, sub or multiply and if dimensions match
    // Add/Subtract if choice == 1
    if ((choice == 1) && (a->rows != b->rows || a->cols != b->cols)) {
        printf("Arithmetic error: matrix dimensions do not match.\n");
        return false; // Return false if error
    }
    // Multiply if choice == 2
    else if ((choice == 2) && (a->cols != b->rows)) {
        printf("Multiplication error: incompatible matrix dimensions.\n");
        return false; // Return false if error
    } // end if-elseif

    return true; // Return true if no error
} // end dimensionTest


// Function to free the memory allocated for the matrix
void freeMatrix(Matrix* m) {
    
    // Free each row
    for (int i = 0; i < m->rows; ++i)
        free(m->data[i]); 
    // end for loop 

    // Free the array of pointers
    free(m->data);
    m->data = NULL;
    m->rows = m->cols = 0; 
} // end freeMatrix


// Functions to get the number of rows and columns
int getRows(const Matrix* m) { return m->rows; } // end getRows
int getCols(const Matrix* m) { return m->cols; } // end getCols


// Function to set an element in a matrix
void setElement(Matrix* m, int row, int col, double value) {
    m->data[row][col] = value;
} //end setElement


// Function to get an element from a matrix
double getElement(const Matrix* m, int row, int col) {
    return m->data[row][col];
} // end getElement


// Function to print the matrix
void printMatrix(const Matrix* m) {
    
    // Print the matrix in a formatted way
    for (int i = 0; i < m->rows; ++i) {
        printf("|");
        for (int j = 0; j < m->cols; ++j)
            printf("%5.2f ", m->data[i][j]);
        // end inner for loop

        printf("|\n");
    } // end outer for loop

    printf("\n");
} // end printMatrix


// Matrix operations ============================================================
// Function to add two matrices
Matrix addMatrix(const Matrix* a, const Matrix* b) {
    
    // Check if dimensions match
    if (dimensionTest(a, b, 1) == false) {
        return createMatrix(0, 0, 0); // Return an empty matrix
    } //end if


    // Create a new matrix to store the result of addition
    Matrix result = createMatrix(a->rows, a->cols, 0);
    for (int i = 0; i < a->rows; ++i)
        for (int j = 0; j < a->cols; ++j)
            result.data[i][j] = a->data[i][j] + b->data[i][j];
    return result;
} //end addMatrix


// Function to subtract two matrices
Matrix subtractMatrix(const Matrix* a, const Matrix* b) {
    
    // Check if dimensions match
    if (dimensionTest(a, b, 1) == false) {
        return createMatrix(0, 0, 0); // Return an empty matrix
    } // end if

    // Create a new matrix to store the result of subtraction
    Matrix result = createMatrix(a->rows, a->cols, 0);
    for (int i = 0; i < a->rows; ++i)
        for (int j = 0; j < a->cols; ++j)
            result.data[i][j] = a->data[i][j] - b->data[i][j];
        // end inner for loop
    // end outer for loop

    return result;
} // end subtractMatrix


// Function to multiply a matrix by a scalar
Matrix multiplyScalar(double scalar, const Matrix* m) {
    
    // Create a new matrix to store the result of multiplication
    Matrix result = createMatrix(m->rows, m->cols, 0);
    for (int i = 0; i < m->rows; ++i)
        for (int j = 0; j < m->cols; ++j)
            result.data[i][j] = scalar * m->data[i][j];
        // end inner for loop
    // end outer for loop

    return result;
} // end multiplyScalar


// Function to multiply two matrices
Matrix multiplyMatrix(const Matrix* a, const Matrix* b) {
    
    // Check if dimensions match for multiplication
    if (dimensionTest(a, b, 2) == false) {
        return createMatrix(0, 0, 0); // Return an empty matrix
    } // end if


    // Create a new matrix to store the result of multiplication
    Matrix result = createMatrix(a->rows, b->cols, 0);
    for (int i = 0; i < a->rows; ++i)
        for (int j = 0; j < b->cols; ++j)
            for (int k = 0; k < a->cols; ++k)
                result.data[i][j] += a->data[i][k] * b->data[k][j];
            // end k for loop
        // end j for loop
    // end i for loop

    return result;
} // end multiplyMatrix


// Function to find the transpose of a matrix
Matrix transposeMatrix(const Matrix* m) {

    // Create a new matrix to store the result of transposition
    Matrix result = createMatrix(m->cols, m->rows, 0);
    for (int i = 0; i < m->rows; ++i)
        for (int j = 0; j < m->cols; ++j)
            result.data[j][i] = m->data[i][j];
        // end inner for loop
    // end outer for loop

    return result;
} // end transposeMatrix



