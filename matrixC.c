#include <stdio.h>
#include <stdlib.h>
#include "matrixC.h"

Matrix createMatrix(int rows, int cols, double initVal) {
    Matrix m;
    m.rows = rows;
    m.cols = cols;
    m.data = (double**)malloc(rows * sizeof(double*));
    for (int i = 0; i < rows; ++i) {
        m.data[i] = (double*)malloc(cols * sizeof(double));
        for (int j = 0; j < cols; ++j)
            m.data[i][j] = initVal;
    }
    return m;
}

void freeMatrix(Matrix* m) {
    for (int i = 0; i < m->rows; ++i)
        free(m->data[i]);
    free(m->data);
    m->data = NULL;
    m->rows = m->cols = 0;
}

int getRows(const Matrix* m) { return m->rows; }
int getCols(const Matrix* m) { return m->cols; }

void setElement(Matrix* m, int row, int col, double value) {
    m->data[row][col] = value;
}

double getElement(const Matrix* m, int row, int col) {
    return m->data[row][col];
}

void printMatrix(const Matrix* m) {
    for (int i = 0; i < m->rows; ++i) {
        printf("|");
        for (int j = 0; j < m->cols; ++j)
            printf("%5.2f ", m->data[i][j]);
        printf("|\n");
    }
    printf("\n");
}

Matrix addMatrix(const Matrix* a, const Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Addition error: matrix dimensions do not match.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(a->rows, a->cols, 0);
    for (int i = 0; i < a->rows; ++i)
        for (int j = 0; j < a->cols; ++j)
            result.data[i][j] = a->data[i][j] + b->data[i][j];
    return result;
}

Matrix subtractMatrix(const Matrix* a, const Matrix* b) {
    if (a->rows != b->rows || a->cols != b->cols) {
        fprintf(stderr, "Subtraction error: matrix dimensions do not match.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(a->rows, a->cols, 0);
    for (int i = 0; i < a->rows; ++i)
        for (int j = 0; j < a->cols; ++j)
            result.data[i][j] = a->data[i][j] - b->data[i][j];
    return result;
}

Matrix multiplyScalar(double scalar, const Matrix* m) {
    Matrix result = createMatrix(m->rows, m->cols, 0);
    for (int i = 0; i < m->rows; ++i)
        for (int j = 0; j < m->cols; ++j)
            result.data[i][j] = scalar * m->data[i][j];
    return result;
}

Matrix multiplyMatrix(const Matrix* a, const Matrix* b) {
    if (a->cols != b->rows) {
        fprintf(stderr, "Multiplication error: incompatible matrix dimensions.\n");
        exit(EXIT_FAILURE);
    }

    Matrix result = createMatrix(a->rows, b->cols, 0);
    for (int i = 0; i < a->rows; ++i)
        for (int j = 0; j < b->cols; ++j)
            for (int k = 0; k < a->cols; ++k)
                result.data[i][j] += a->data[i][k] * b->data[k][j];
    return result;
}

Matrix transposeMatrix(const Matrix* m) {
    Matrix result = createMatrix(m->cols, m->rows, 0);
    for (int i = 0; i < m->rows; ++i)
        for (int j = 0; j < m->cols; ++j)
            result.data[j][i] = m->data[i][j];
    return result;
}
