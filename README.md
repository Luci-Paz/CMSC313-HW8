# CMSC313-HW8: Matrix Library in C and C++

## Author:
Lucian Pazour (UMBC / CMSC313-01, MoWe 8:30AM - 9:45AM / 04152025)

---

## Purpose of Software:
This Project provides a matrix library implemented in both **C (C99)** and **C++ (c++11)**. It supports:  
- Matrix **addition**
- Matrix **subtraction**
- Matrix **multiplication with another matrix**
- Matrix **multiplication with a scalar**
- Martix **transposition**

>[!NOTE]
>List of functions at the bottom of README for both C and C++ code

---

## File Descriptions

| File Name           | Language | Description |
|---------------------|----------|-------------|
| `matrixC.h`         | C        | Header file declaring the `Matrix` struct and matrix operation functions. |
| `matrixC.c`         | C        | Implementation of the C matrix functions. (source code) |
| `testCaseC.c`       | C        | A test program for validating matrix operations using the C implementation. (source code) |
| `matrixCpp.h`       | C++      | Header file for the `Matrix` class, describing the matrix operations. |
| `matrixCpp.cpp`     | C++      | Implementation of the C++ matrix functions. (source code) |
| `testCaseCpp.cpp`   | C++      | A test program for verifying the functionality of the C++ matrix class. (source code) |
| `Makefile`          | Make     | Automates the build process for both the C and C++ matrix libraries and their test programs. |

---


## Build Instructions
To build the project, first ensure `gcc`, `g++` and `make` are installed. You can check if they are by running the following commands:
```
$ gcc --version
$ g++ --version
$ make --version
```
<br>

**There are also different make commands for different project builds.**  

**1. The basic build will produce 64-bit code and is run with the following command:**
```
make
```
- This will produce the object files (`*.o`) and executables (`matrixTestCpp64.exe` and `matrixTestC64.exe`) for the project 

<br> 

**2. To compile the 32-bit code for the project, run the following command:**
```
make Release32bit
```
- This will produce the object files (`*.o`) and executables (`matrixTestCpp32.exe` and `matrixTestC32.exe`) for the project  

<br>

**3. To debug the 64-bit code, run the following command:**
```
make debug
```
- This will produce the object files (`*.o`) and executables (`matrixTestCpp64.exe` and `matrixTestC64.exe`) for the project  

<br>

**4. To debug the 32-bit code, run the following command:**
```
make debug32bit
```
- This will produce the object files (`*.o`) and executables (`matrixTestCpp32.exe` and `matrixTestC32.exe`) for the project  

<br>

**You can clean up the compiled code with:**
```
make clean
```
- This will delete the object files (`*.o`) and executables (`*.exe`)

---  

## Testing Methodology
After building, run each test executable:
```
./nameOfTestExecutable
```
- There are two executables for each build. One for the C code and one for the C++ code. They both display the same test case results to the terminal window when run. The first test case shown is the one outlined in the HW assignment. The others display different arithmetic cases as well as cases that produce a dimension error, these are the last three tests.

<br>

**Running the C++ executable results in the following screen:**  

<br>

![Image of test case output for the C++ program. It shows the values in the initial matrices, the output of the test case outlined in the HW assignment and additional test cases for
arithmetic operations](/images/ImageOfCppCodeTests.png)

<br>

**Running the C executable results in the following screen:**

<br>

![Image of test case output for the C program. It shows the values in the initial matrices, the output of the test case outlined in the HW assignment and additional test cases for
arithmetic operations](/images/ImageOfCCodeTests.png)

<br>

**Creating Your Own Tests**  
To create a new matrix in the C++ code:
```cpp
//Declare a new matrix, specifying (rows, columns, initialElementsValue)
Matrix matrixName(2, 3, 0);

// Resultant matrix
//  | 0 0 0 |
//  | 0 0 0 |

//Change the value of an element (rowCoordinate, columnCoordinate, newValue)
matrixName.setElement(0, 0, 6);

// Resultant matrix
//  | 6 0 0 |
//  | 0 0 0 |


```

<br>

To create a new matrix in the C code:
```c
//Declare a new matrix, specifying (rows, columns, initialElementsValue)
Matrix matrixName = createMatrix(2, 3, 0);

// Resultant matrix
//  | 0 0 0 |
//  | 0 0 0 |

//Change the value of an element (&matrixName, rowCoordinate, columnCoordinate, newValue)
matrixName.setElement(&matrixName, 0, 0, 6);

// Resultant matrix
//  | 6 0 0 |
//  | 0 0 0 |

```

---


# Additional Information
1. Memory is manually managed in the C program, make sure any new matrices made are properly freed.
2. Operator overloading in the C++ program makes it easier to write arithmetic expressions.
3. Standard matrix dimension rules apply. For addition and subtraction, the matrices must have the same dimensions. For multiplication, the number of columns of the first matrix must match the rows of the second matrix. If these rules are broken they should be caught, returning an empty matrix and outputting a message saying the dimensions of the matrices are incorrect for that operation.

<br>

**Functions for each library**  
| Function (C++) | What it does |
| --------------------------- | ------------ |
| Matrix(); | Default Constructor |
| Matrix(int rows, int cols, double initVal); | Constructor to specify matrix dimensions and initial element value |
| Matrix(const Matrix& secondMat); | Copy Constructor |
| ~Matrix(); | Destructor |
| Matrix& operator=(const Matrix& secondMat); | Assignment Operator | 
| int getRows() const; | Return number of rows in the matrix object | 
| int getCols() const; | Return number of columns in the matrix object |
| void setElement(int row, int col, double value); | Set and get element at (row, col) |
| double getElement(int row, int col) const; | Return the value of an element at (row, col) |
| void inputMatrix(); | Add initial values to matrix from user inputs |
| void printMatrix() const; | Output the formatted matrix to the terminal |
| Matrix operator+(const Matrix& secondMat) const; | Add two matrices together with the `+` operator |
| Matrix operator-(const Matrix& secondMat) const; | Subtract two matrices together with the `=` operator |
| Matrix operator*(double scalar) const; | Multiply a matrix by a scalar value with the `*` operator |
| Matrix operator*(const Matrix& secondMat) const; | Multiply the matrix by another matrix using the `*` operator |
| friend Matrix operator*(double scalar, const Matrix& secondMat); | Another scalar multiplication function but for `scalar * matrix` instead of `matrix * scalar` using the `*` operator |
| Matrix transpose() const; | Return the transpose of a matrix |

<br>

| Function (C) | What it does |
| --------------------------- | ------------ |
| Matrix createMatrix(int rows, int cols, double initVal); | Function to specify the matrix structs rows, columns and initial values |
| void freeMatrix(Matrix* m) | Free up the memory allocated for the matrix struct | 
| int getRows(const Matrix* m); | Return number of rows in the matrix struct | 
| int getCols(const Matrix* m); | Return number of columns in the matrix struct |
| void setElement(Matrix* m, int row, int col, double value); | Set and get element at (row, col) for the specified matrix struct |
| double getElement(const Matrix* m, int row, int col); | Return the value of an element at (row, col) for the specified matrix struct |
| void printMatrix(const Matrix* m); | Output the formatted matrix to the terminal |
| Matrix addMatrix(const Matrix* a, const Matrix* b); | Add two matrices together |
| Matrix subtractMatrix(const Matrix* a, const Matrix* b); | Subtract matrix b from matrix a |
| Matrix multiplyScalar(double scalar, const Matrix* m); | Multiply a matrix by a scalar value |
| Matrix multiplyMatrix(const Matrix* a, const Matrix* b); | Multiply the two specified matrices together |
| Matrix transposeMatrix(const Matrix* m); | Return the transpose of a matrix |
