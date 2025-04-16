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
 
 Matrix::Matrix(int r, int c) : rows(r), cols(c) {
     allocateMemory();
 }
 
 Matrix::Matrix(const Matrix& secondMat) : rows(secondMat.rows), cols(secondMat.cols) {
     allocateMemory();
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             data[i][j] = secondMat.data[i][j];
 }
 
 Matrix::~Matrix() {
     deallocateMemory();
 }
 
 Matrix& Matrix::operator=(const Matrix& secondMat) {
     if (this == &secondMat) return *this;
 
     deallocateMemory();
     rows = secondMat.rows;
     cols = secondMat.cols;
     allocateMemory();
 
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             data[i][j] = secondMat.data[i][j];
     return *this;
 }
 
 void Matrix::allocateMemory() {
     data = new double*[rows];
     for (int i = 0; i < rows; ++i)
         data[i] = new double[cols]();
 }
 
 void Matrix::deallocateMemory() {
     for (int i = 0; i < rows; ++i)
         delete[] data[i];
     delete[] data;
 }
 
 void Matrix::setElement(int r, int c, double value) {
     data[r][c] = value;
 }
 
 double Matrix::getElement(int r, int c) const {
     return data[r][c];
 }
 
 void Matrix::inputMatrix() {
     cout << "Enter elements (" << rows << "x" << cols << "):\n";
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j) {
             cout << "Element [" << i << "][" << j << "]: ";
             cin >> data[i][j];
         }
 }
 
 void Matrix::printMatrix() const {
     for (int i = 0; i < rows; ++i) {
         for (int j = 0; j < cols; ++j)
             cout << setw(10) << data[i][j] << " ";
         cout << "\n";
     }
 }
 
 Matrix Matrix::add(const Matrix& secondMat) const {
     if (rows != secondMat.rows || cols != secondMat.cols) {
         cerr << "Addition error: matrix dimensions do not match.\n";
         exit(EXIT_FAILURE);
     }
 
     Matrix result(rows, cols);
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
 
     Matrix result(rows, cols);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             result.data[i][j] = data[i][j] - secondMat.data[i][j];
     return result;
 }
 
 Matrix Matrix::multiplyByScalar(double scalar) const {
     Matrix result(rows, cols);
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
 
     Matrix result(rows, secondMat.cols);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < secondMat.cols; ++j)
             for (int k = 0; k < cols; ++k)
                 result.data[i][j] += data[i][k] * secondMat.data[k][j];
     return result;
 }
 
 Matrix Matrix::transpose() const {
     Matrix result(cols, rows);
     for (int i = 0; i < rows; ++i)
         for (int j = 0; j < cols; ++j)
             result.data[j][i] = data[i][j];
     return result;
 }
 
 int Matrix::getRows() const { return rows; }
 int Matrix::getCols() const { return cols; }