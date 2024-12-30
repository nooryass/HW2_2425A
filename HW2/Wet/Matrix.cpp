#include "Matrix.h"
#include "Utilities.h"
#include <cmath>

// Constructors and Destructor
Matrix::Matrix() : length(0), width(0), data(nullptr) {}

Matrix::Matrix(int numRows, int numCols) : length(numRows), width(numCols) {
    if (numRows < 0 || numCols < 0) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    data = new int[numRows * numCols];
    for (int elementIndex = 0; elementIndex < numRows * numCols; ++elementIndex) {
        data[elementIndex] = 0;
    }
}

Matrix::Matrix(int numRows, int numCols, int initialValue) : length(numRows), width(numCols) {
    if (numRows < 0 || numCols < 0) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    data = new int[numRows * numCols];
    for (int elementIndex = 0; elementIndex < numRows * numCols; ++elementIndex) {
        data[elementIndex] = initialValue;
    }
}

Matrix::Matrix(const Matrix& sourceMatrix) : length(sourceMatrix.length), width(sourceMatrix.width) {
    if (sourceMatrix.data) {
        data = new int[length * width];
        for (int elementIndex = 0; elementIndex < length * width; ++elementIndex) {
            data[elementIndex] = sourceMatrix.data[elementIndex];
        }
    } else {
        data = nullptr;
    }
}

Matrix::~Matrix() {
    delete[] data;
}

// Assignment Operator
Matrix& Matrix::operator=(const Matrix& sourceMatrix) {
    if (this == &sourceMatrix) {
        return *this;
    }
    int* newData = new int[sourceMatrix.length * sourceMatrix.width];
    for (int elementIndex = 0; elementIndex < sourceMatrix.length * sourceMatrix.width; ++elementIndex) {
        newData[elementIndex] = sourceMatrix.data[elementIndex];
    }
    delete[] data;
    data = newData;
    length = sourceMatrix.length;
    width = sourceMatrix.width;
    return *this;
}

// Element Access Operators
int& Matrix::operator()(int rowIndex, int colIndex) {
    if (rowIndex < 0 || rowIndex >= length || colIndex < 0 || colIndex >= width) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return data[width * rowIndex + colIndex];
}

const int& Matrix::operator()(int rowIndex, int colIndex) const {
    if (rowIndex < 0 || rowIndex >= length || colIndex < 0 || colIndex >= width) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return data[width * rowIndex + colIndex];
}

// Arithmetic Operators
Matrix& Matrix::operator+=(const Matrix& otherMatrix) {
    if (otherMatrix.length != length || otherMatrix.width != width) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    for (int elementIndex = 0; elementIndex < length * width; ++elementIndex) {
        data[elementIndex] += otherMatrix.data[elementIndex];
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& otherMatrix) {
    return *this += -otherMatrix;
}

Matrix& Matrix::operator*=(const Matrix& otherMatrix) {
    if (width != otherMatrix.length) {
        exitWithError(MatamErrorType::UnmatchedSizes);
    }
    Matrix resultMatrix(length, otherMatrix.width);
    for (int rowIndex = 0; rowIndex < length; ++rowIndex) {
        for (int colIndex = 0; colIndex < otherMatrix.width; ++colIndex) {
            for (int commonIndex = 0; commonIndex < width; ++commonIndex) {
                resultMatrix(rowIndex, colIndex) += (*this)(rowIndex, commonIndex) * otherMatrix(commonIndex, colIndex);
            }
        }
    }
    *this = resultMatrix;
    return *this;
}

Matrix& Matrix::operator*=(int scalarValue) {
    for (int elementIndex = 0; elementIndex < length * width; ++elementIndex) {
        data[elementIndex] *= scalarValue;
    }
    return *this;
}

// Unary Operators
Matrix Matrix::operator-() const {
    return *this * -1;
}

// Transformations
Matrix Matrix::rotateClockwise() const {
    Matrix turned_matrix_clockwise(width, length);
    for (int j = 0; j < width; j++) {
        for (int i = length - 1, a = 0; i >= 0; i--, a++) {
            turned_matrix_clockwise(j, a) = this->operator()(i, j);
        }
    }
    return turned_matrix_clockwise;
}

Matrix Matrix::rotateCounterClockwise() const {
    return this->rotateClockwise().rotateClockwise().rotateClockwise();
}

Matrix Matrix::transpose() const {
    Matrix transposedMatrix(width, length);
    for (int rowIndex = 0; rowIndex < length; ++rowIndex) {
        for (int colIndex = 0; colIndex < width; ++colIndex) {
            transposedMatrix(colIndex, rowIndex) = (*this)(rowIndex, colIndex);
        }
    }
    return transposedMatrix;
}

// Static Methods
double Matrix::CalcFrobeniusNorm(const Matrix& matrix) {
    double sumOfSquares = 0.0;
    for (int rowIndex = 0; rowIndex < matrix.length; ++rowIndex) {
        for (int colIndex = 0; colIndex < matrix.width; ++colIndex) {
            sumOfSquares += std::pow(matrix(rowIndex, colIndex), 2);
        }
    }
    return std::sqrt(sumOfSquares);
}

// Friend and Non-Member Operators
Matrix operator+(const Matrix& matrix1, const Matrix& matrix2) {
    return Matrix(matrix1) += matrix2;
}

Matrix operator-(const Matrix& matrix1, const Matrix& matrix2) {
    return Matrix(matrix1) -= matrix2;
}

Matrix operator*(const Matrix& matrix1, const Matrix& matrix2) {
    return Matrix(matrix1) *= matrix2;
}

Matrix operator*(const Matrix& matrix, int scalarValue) {
    return Matrix(matrix) *= scalarValue;
}

Matrix operator*(int scalarValue, const Matrix& matrix) {
    return matrix * scalarValue;
}

bool operator==(const Matrix& matrix1, const Matrix& matrix2) {
    if (matrix1.length != matrix2.length || matrix1.width != matrix2.width) {
        return false;
    }
    for (int i = 0; i < matrix1.length; ++i) {
        for (int j = 0; j < matrix1.width; ++j) {
            if (matrix1(i, j) != matrix2(i, j)) {
                return false;
            }
        }
    }
    return true;
}

bool operator!=(const Matrix& matrix1, const Matrix& matrix2) {
    return !(matrix1 == matrix2);
}

Matrix turnToScalarMatrix(int scalarValue, int numRows, int numCols) {
    Matrix scalarMatrix(numRows, numCols);
    for (int diagonalIndex = 0; diagonalIndex < numRows; ++diagonalIndex) {
        scalarMatrix(diagonalIndex, diagonalIndex) = scalarValue;
    }
    return scalarMatrix;
}

std::ostream& operator<<(std::ostream& outputStream, const Matrix& matrix) {
    if (matrix.length == 0 || matrix.width == 0) {
        return outputStream;
    }
    for (int rowIndex = 0; rowIndex < matrix.length; ++rowIndex) {
        for (int colIndex = 0; colIndex < matrix.width; ++colIndex) {
            outputStream << "|" << matrix(rowIndex, colIndex);
        }
        outputStream << "|" << std::endl;
    }
    return outputStream;
}
