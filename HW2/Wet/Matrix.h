//
// Created by Nataly Haddad on 09/07/2024.
//

#ifndef WET_Matrix_H
#define WET_Matrix_H

#include <iostream>
#include "Utilities.h"

class Matrix {

private:

    int length; // number of rows
    int width; // number of columns
    int* data; // one-dimensional array to store Matrix elements

public:
    
    // constructor that initializes a matrix with initValue
    Matrix(int n, int m, int initialValue); 

    // constructor that initializes a matrix with zeroes
    Matrix( int n, int m );

    // default constructor that initializes a 0x0 Matrix
    Matrix();

    // copy constructor
    Matrix(const Matrix& matrix);

    // assignment operator
    Matrix& operator=(const Matrix& matrix);

    // destructor
    ~Matrix();

    // operator () for accessing elements in the matrix (non-const version)
    int& operator()(int row, int column);

    // operator () for accessing elements in the matrix (const version)
    const int& operator()(int row, int column) const;

    // addition assignment operator
    Matrix& operator+=(const Matrix& matrix);

    // subtractions assignment operator
    Matrix& operator-=(const Matrix& matrix);

    // multiplication assignment operator
    Matrix& operator*=(const Matrix& matrix);

    // unary minus operator
    Matrix operator-() const;

    // multiplication by scalar assignment operator
    Matrix& operator*=(const int scalar);

    // returns rotated matrix clockwise
    Matrix rotateClockwise() const;

    // returns rotated matrix counterclockwise
    Matrix rotateCounterClockwise() const;

    // returns transposed matrix
    Matrix transpose() const;

    // prints matrix
    friend std::ostream& operator<<(std::ostream& os, const Matrix& Matrix);

    // equality operator
    friend bool operator==(const Matrix& matrix1, const Matrix& matrix2);

    static double CalcFrobeniusNorm(const Matrix& matrix);

};

// matrix addition operator
Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);

// matrix subtraction operator
Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);

// matrix multiplication operator
Matrix operator*(const Matrix& matrix1, const Matrix& matrix2);

// multiplication by scalar operator
Matrix operator*(const int scalar, const Matrix& matrix);

// multiplication by scalar operator
Matrix operator*(const Matrix& matrix, const int scalar);

// inequality operator
bool operator!=(const Matrix& matrix1, const Matrix& matrix2);

// turns a scalar to a scalar matrix
Matrix turnToScalarMatrix(int scalar, int length, int width);

// Method to calculate Frobenius norm of the current matrix


#endif //WET_Matrix_H
