#ifndef MATRIXC_H
#define MATRIXC_H

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
