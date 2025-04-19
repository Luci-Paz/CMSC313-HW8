#include <stdio.h>
#include "matrixC.h"

int main() {
    
    // Test case: A + (3 * B) * C^T
    Matrix A = createMatrix(2, 2, 0);
    Matrix B = createMatrix(2, 3, 0);
    Matrix C = createMatrix(2, 3, 0);

    // Initialize matrices A, B, and C
    setElement(&A, 0, 0, 6); setElement(&A, 0, 1, 4);
    setElement(&A, 1, 0, 8); setElement(&A, 1, 1, 3);
    printMatrix(&A);

    setElement(&B, 0, 0, 1); setElement(&B, 0, 1, 2); setElement(&B, 0, 2, 3);
    setElement(&B, 1, 0, 4); setElement(&B, 1, 1, 5); setElement(&B, 1, 2, 6);
    printMatrix(&B);

    setElement(&C, 0, 0, 2); setElement(&C, 0, 1, 4); setElement(&C, 0, 2, 6);
    setElement(&C, 1, 0, 1); setElement(&C, 1, 1, 3); setElement(&C, 1, 2, 5);
    printMatrix(&C);

    // Create a transpose of C
    Matrix C_T = transposeMatrix(&C);
    printMatrix(&C_T);

    // Test case: A + (3 * B) * C^T
    printf("testing matrix struct with given test case\n");
    Matrix scalarMult = multiplyScalar(3, &B);
    Matrix prod = multiplyMatrix(&scalarMult, &C_T);
    Matrix result = addMatrix(&A, &prod);
    printMatrix(&result);

    printf("Testing additional self made test cases\n");
    // Test case: C - B
    printf("Testing C - B\n");
    Matrix subtracitonTest = subtractMatrix(&C, &B);
    printMatrix(&subtracitonTest);

    // Test case: A + A
    printf("Testing A + A\n");
    Matrix additionTest = addMatrix(&A, &A);
    printMatrix(&additionTest);

    // Test case: 3 * A
    printf("Testing 3 * A\n");
    Matrix scalarMultA = multiplyScalar(3, &A);
    printMatrix(&scalarMultA);

    // Test case: A * A
    printf("Testing A * A\n");
    Matrix multiplicationTestSquare = multiplyMatrix(&A, &A);
    printMatrix(&multiplicationTestSquare);

    // Test case: B * C_T
    printf("Testing B * C_T\n");
    Matrix multiplicationTest = multiplyMatrix(&B, &C_T);
    printMatrix(&multiplicationTest);

    // Test case: A * B
    printf("Testing A * B\n");
    Matrix multiplicationTestMismatch = multiplyMatrix(&A, &B);
    printMatrix(&multiplicationTestMismatch);



    // Test cases for dimension mismatch
    // Test case: A + B
    printf("Testing A + B (dimension mismatch)\n");
    Matrix additionTestMismatch = addMatrix(&A, &B);
    printMatrix(&additionTestMismatch);

    // Test case: A - B
    printf("Testing A - B (dimension mismatch)\n");
    Matrix subtractionTestMismatch = subtractMatrix(&A, &B);
    printMatrix(&subtractionTestMismatch);

    // Test case: B * A
    printf("Testing B * A (dimension mismatch)\n");
    Matrix multiplicationTestBA = multiplyMatrix(&B, &A);
    printMatrix(&multiplicationTestBA);
    
    

    // Clean up
    freeMatrix(&A);
    freeMatrix(&B);
    freeMatrix(&C);
    freeMatrix(&C_T);
    freeMatrix(&scalarMult);
    freeMatrix(&prod);
    freeMatrix(&subtracitonTest);
    freeMatrix(&additionTest);
    freeMatrix(&multiplicationTest);
    freeMatrix(&result);

    return 0;
}
