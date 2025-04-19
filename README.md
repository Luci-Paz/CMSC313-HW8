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


# Additional Information
