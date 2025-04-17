#include <stdio.h>
#include "matrixC.h"

int main() {
    // Test case: A + (3 * B) * C^T
    Matrix A = createMatrix(2, 2, 0);
    Matrix B = createMatrix(2, 3, 0);
    Matrix C = createMatrix(2, 3, 0);

    setElement(&A, 0, 0, 6); setElement(&A, 0, 1, 4);
    setElement(&A, 1, 0, 8); setElement(&A, 1, 1, 3);
    printMatrix(&A);

    setElement(&B, 0, 0, 1); setElement(&B, 0, 1, 2); setElement(&B, 0, 2, 3);
    setElement(&B, 1, 0, 4); setElement(&B, 1, 1, 5); setElement(&B, 1, 2, 6);
    printMatrix(&B);

    setElement(&C, 0, 0, 2); setElement(&C, 0, 1, 4); setElement(&C, 0, 2, 6);
    setElement(&C, 1, 0, 1); setElement(&C, 1, 1, 3); setElement(&C, 1, 2, 5);
    printMatrix(&C);

    Matrix C_T = transposeMatrix(&C);
    printMatrix(&C_T);

    printf("testing matrix struct with given test case\n");

    Matrix scalarMult = multiplyScalar(3, &B);
    Matrix prod = multiplyMatrix(&scalarMult, &C_T);
    Matrix result = addMatrix(&A, &prod);
    printMatrix(&result);

    // Clean up
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&C_T);
    freeMatrix(&scalarMult);
    freeMatrix(&prod);
    freeMatrix(&result);

    return 0;
}
