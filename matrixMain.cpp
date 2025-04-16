/**
 * @file matrixMain.cpp
 * @brief Main file to test the Matrix class
 */

 #include "matrix.h"
 #include <iostream>

 int main() {
    
    //Test case for HW8, A + (3 * B) * C^T
    
    // Create matrices A, B, and C with given dimensions
    Matrix A(2, 2, 0);
    Matrix B(2, 3, 0);
    Matrix C(2, 3, 0); 

    // Initialize matrices A, B, and C with some values
    A.setElement(0, 0, 6); A.setElement(0, 1, 4);
    A.setElement(1, 0, 8); A.setElement(1, 1, 3);
    A.printMatrix();

    B.setElement(0, 0, 1); B.setElement(0, 1, 2); B.setElement(0, 2, 3);
    B.setElement(1, 0, 4); B.setElement(1, 1, 5); B.setElement(1, 2, 6);
    B.printMatrix();

    C.setElement(0, 0, 2); C.setElement(0, 1, 4); C.setElement(0, 2, 6);
    C.setElement(1, 0, 1); C.setElement(1, 1, 3); C.setElement(1, 2, 5);
    C.printMatrix();


    //Display the transpose of C
    C.transpose().printMatrix();


    // Run the test case
    std::cout << "testing matrix class with given test case\n";
    Matrix result = A + (3 * B) * C.transpose();
    result.printMatrix();
    std::cout << "\n\n";

    
    return 0;
}
