# CMSC313-HW8

# Authoring:
Lucian Pazour (UMBC / CMSC313-01, MoWe 8:30AM - 9:45AM / 04152025)

# Purpose of Software:
Create libraries for C and C++ that define matrix functions for addition, subtraction, multiplication with a scalar and another matrix and transposition.

# Files
**MakeFile**  
Makefile used to compile the library code for both the c and c++ matrix libraries
and the test files for each library. The Makefile also defines a debug and clean argument 

**matrixCpp.h**  
Header file for the c++ matrix library. It outlines the Matrix class and its functions

**matrix.cpp**  
Source file for the c++ matrix library. Defines the Matrix class functions.  
It includes:
- `<iostream>`
- `<iomanip>`
- `"matrixCpp.h"`

**testCaseCpp.cpp**
Source file that contains the main function for a program that runs the test case given in the homework instructions
[A + (3 * B) * C^T].





# Build Instructions
To build the program: 
1. first download the code from the repository, ensuring you have the Makefile, matrix.cpp, matrix.c, matrixCpp.h, matrixC.h, testCaseC.c and testCaseCpp.cpp files.  
2. Then, ensure you have gcc installed on your computer
   ```bash
   $ gcc --version
   ```
3. Then run the Makefile to compile the downloaded c and c++ files. Use the below command
   ```bash
   $ make
   ```  
   This should create object files for each c and c++ source file as well as an executable file for both testCase files. These will be labelled as matrixTest_c
   for the c program test case and matrixTest_cpp for the c++ program test case.
4. The executables can then be run using the following commands:
   ```bash
   $ ./matrixTestCpp
   $ ./matrixTestC
   ```
5. Both tests should output the same thing:
   

# Testing Methodology

# Additional Information
