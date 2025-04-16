/**
 * @file matrixMain.cpp
 * @brief Main file to test the Matrix class
 */

 #include "matrix.h"
 #include <iostream>

 int main() {
    int r, c;

    std::cout << "Matrix A - Enter rows and columns: ";
    std::cin >> r >> c;
    Matrix A(r, c);
    A.inputMatrix();

    std::cout << "Matrix B - Enter rows and columns: ";
    std::cin >> r >> c;
    Matrix B(r, c);
    B.inputMatrix();

    std::cout << "\nMatrix A:\n";
    A.printMatrix();

    std::cout << "\nMatrix B:\n";
    B.printMatrix();

    Matrix sum = A.add(B);
    std::cout << "\nA + B:\n";
    sum.printMatrix();

    Matrix diff = A.subtract(B);
    std::cout << "\nA - B:\n";
    diff.printMatrix();

    double scalar;
    std::cout << "\nEnter scalar to multiply Matrix A: ";
    std::cin >> scalar;
    Matrix scalarMult = A.multiplyByScalar(scalar);
    std::cout << "\nA * " << scalar << ":\n";
    scalarMult.printMatrix();

    if (A.getCols() == B.getRows()) {
        Matrix prod = A.multiply(B);
        std::cout << "\nA * B:\n";
        prod.printMatrix();
    } else {
        std::cout << "\nA * B not possible (dimension mismatch)\n";
    }

    Matrix transA = A.transpose();
    std::cout << "\nTranspose of A:\n";
    transA.printMatrix();

    return 0;
}
