
#ifndef WET_MATAMVIDIA_H
#define WET_MATAMVIDIA_H

#include "Matrix.h"
#include "Utilities.h"

#include <string>
#include <iostream>
#include <ostream>


class MataMvidia {

private:
    std::string movieName; // the name of the movie
    std::string authorName; // who created the movie
    int movieLength; // number of frames
    Matrix* frames;

public:
    MataMvidia( const std::string& movieName, const std::string& creatorName,
                 Matrix* framesArray, int movieLength );
    ~MataMvidia();
    MataMvidia( const MataMvidia& movie);

    MataMvidia& operator=(const MataMvidia& otherMovie);
    const Matrix& operator[](int index) const;
    Matrix& operator[](int index);
    MataMvidia& operator+=(const MataMvidia& otherMovie);
    MataMvidia& operator+=(const Matrix& otherMatrix);

    friend std::ostream& operator<<( std::ostream&, const MataMvidia& MataMvidia);

};

MataMvidia operator+(const MataMvidia& movie1, const MataMvidia& movie2);

#endif //WET_MATAMVIDIA_H
