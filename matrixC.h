/**
 * @file matrixC.h
 * @brief Header file for the Matrix struct
 * @details This file contains the declaration of the Matrix struct, which provides
 *          basic matrix operations such as addition, subtraction, multiplication,
 *          and transposition. The struct uses a 2D array to store the matrix
 *          data and provides functions to manipulate and access the matrix elements.
 * @author Lucian Pazour
 * @date (yy-dd-mm) 2025-16-04
 */

#ifndef MATRIXC_H
#define MATRIXC_H


// define struct Matrix
typedef struct {
    int rows;
    int cols;
    double** data;
} Matrix;

// Memory management
Matrix createMatrix(int rows, int cols, double initVal);
void freeMatrix(Matrix* m);

// Getters and setters
int getRows(const Matrix* m);
int getCols(const Matrix* m);
void setElement(Matrix* m, int row, int col, double value);
double getElement(const Matrix* m, int row, int col);

// Display
void printMatrix(const Matrix* m);

// Matrix operations
Matrix addMatrix(const Matrix* a, const Matrix* b);
Matrix subtractMatrix(const Matrix* a, const Matrix* b);
Matrix multiplyScalar(double scalar, const Matrix* m);
Matrix multiplyMatrix(const Matrix* a, const Matrix* b);
Matrix transposeMatrix(const Matrix* m);


#endif // MATRIXC_H
