#ifndef WET_MATAMVIDIA_H
#define WET_MATAMVIDIA_H

#include "Matrix.h"
#include "Utilities.h"

#include <string>
#include <iostream>
#include <ostream>

class MataMvidia {
private:
    // Private Members
    std::string movieName;    // The name of the movie
    std::string authorName;   // The creator of the movie
    int movieLength;          // Number of frames
    Matrix* frames;           // Array of frames

public:
    // Constructors and Destructor
    MataMvidia(const std::string& movieName, const std::string& creatorName,
               Matrix* framesArray, int movieLength);
    MataMvidia(const MataMvidia& movie); // Copy constructor
    ~MataMvidia();                       // Destructor

    // Assignment Operator
    MataMvidia& operator=(const MataMvidia& otherMovie);

    // Operator Overloads
    const Matrix& operator[](int index) const;
    Matrix& operator[](int index);
    MataMvidia& operator+=(const MataMvidia& otherMovie);
    MataMvidia& operator+=(const Matrix& otherMatrix);
    friend std::ostream& operator<<(std::ostream&, const MataMvidia& MataMvidia);

    // Non-Member Function
    friend MataMvidia operator+(const MataMvidia& movie1, const MataMvidia& movie2);
};

#endif //WET_MATAMVIDIA_H
