/**
 * @file testCaseCpp.cpp
 * @brief Main file to test the Matrix class 
 * @details This file contains the main function that tests the Matrix class
 *          by running a specific test case. The test case involves creating
 *          matrices A, B, and C, initializing them with values, and performing
 *          matrix operations such as addition, multiplication, and transposition.
 * @author Lucian Pazour
 * @date (yy-dd-mm) 2025-16-04
 */


 #include "matrixCpp.h"
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
    std::cout << "Matrix A:" << std::endl;
    A.printMatrix();

    B.setElement(0, 0, 1); B.setElement(0, 1, 2); B.setElement(0, 2, 3);
    B.setElement(1, 0, 4); B.setElement(1, 1, 5); B.setElement(1, 2, 6);
    std::cout << "Matrix B:" << std::endl;
    B.printMatrix();

    C.setElement(0, 0, 2); C.setElement(0, 1, 4); C.setElement(0, 2, 6);
    C.setElement(1, 0, 1); C.setElement(1, 1, 3); C.setElement(1, 2, 5);
    std::cout << "Matrix C:" << std::endl;
    C.printMatrix();


    //Display the transpose of C
    Matrix CT = C.transpose();
    std::cout << "Matrix C^T:" << std::endl;
    CT.printMatrix();


    // Run the test case A + (3 * B) * C^T
    std::cout << "testing matrix class with given test case [A + (3 * B) * C^T]\n";
    Matrix result = A + (3 * B) * C.transpose();
    result.printMatrix();
    std::cout << std::endl;


    // Additional Test Cases
    std::cout << "Testing additional self made test cases\n";
    // Test case: C - B
    std::cout << "Testing C - B\n";
    Matrix subtractionTest = C - B;
    subtractionTest.printMatrix();

    // Test case: A + A
    std::cout << "Testing A + A\n";
    Matrix additionTest = A + A;
    additionTest.printMatrix();

    // Test case: 3 * A
    std::cout << "Testing 3 * A\n";
    Matrix scalarMultA = 3 * A;
    scalarMultA.printMatrix();

    // Test case: A * A
    std::cout << "Testing A * A\n";
    Matrix multiplicationTestSquare = A * A;
    multiplicationTestSquare.printMatrix();

    // Test case: B * C^T
    std::cout << "Testing B * C^T\n";
    Matrix multiplicationTestRect = B * CT;
    multiplicationTestRect.printMatrix();

    // Test case: A * B
    std::cout << "Testing A * B\n";
    Matrix multiplicationTestAB = A * B;
    multiplicationTestAB.printMatrix();


    // Test cases for dimension mismatch
    std::cout << "Testing dimension mismatch cases\n";

    // Test case: A + B
    std::cout << "Testing A + B (dimension mismatch)\n";
    Matrix additionTestMismatch = A + B;
    additionTestMismatch.printMatrix();

    // Test case: A - B
    std::cout << "Testing A - B (dimension mismatch)\n";
    Matrix subtractionTestMismatch = A - B;
    subtractionTestMismatch.printMatrix();

    // Test case: B * A
    std::cout << "Testing B * A (dimension mismatch)\n";
    Matrix multiplicationTestBA = B * A;
    multiplicationTestBA.printMatrix();
    
    std::cout << "End of test case" << std::endl;

    return 0;

} // end main
// end testCaseCpp
