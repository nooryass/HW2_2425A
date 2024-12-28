#include "MataMvidia.h"

// Constructor
MataMvidia::MataMvidia(const std::string& movieTitle, const std::string& creatorName,
                       Matrix* frameArray, int numFrames)
    : movieName(movieTitle), authorName(creatorName), movieLength(numFrames) {
    frames = new Matrix[numFrames];
    for (int frameIndex = 0; frameIndex < numFrames; ++frameIndex) {
        frames[frameIndex] = frameArray[frameIndex];
    }
}

// Destructor
MataMvidia::~MataMvidia() {
    delete[] frames;
}

// Copy Constructor
MataMvidia::MataMvidia(const MataMvidia& otherMovie)
    : movieName(otherMovie.movieName), authorName(otherMovie.authorName), movieLength(otherMovie.movieLength) {
    frames = new Matrix[movieLength];
    for (int frameIndex = 0; frameIndex < movieLength; ++frameIndex) {
        frames[frameIndex] = otherMovie.frames[frameIndex];
    }
}

// Assignment Operator
MataMvidia& MataMvidia::operator=(const MataMvidia& otherMovie) {
    if (this == &otherMovie) {
        return *this;
    }

    Matrix* newFrames = new Matrix[otherMovie.movieLength];
    for (int frameIndex = 0; frameIndex < otherMovie.movieLength; ++frameIndex) {
        newFrames[frameIndex] = otherMovie.frames[frameIndex];
    }

    delete[] frames;
    movieLength = otherMovie.movieLength;
    movieName = otherMovie.movieName;
    authorName = otherMovie.authorName;
    frames = newFrames;

    return *this;
}

// [] Operator (Read-Only)
const Matrix& MataMvidia::operator[](int frameIndex) const {
    if (frameIndex < 0 || frameIndex >= movieLength) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[frameIndex];
}

// [] Operator (Read-Write)
Matrix& MataMvidia::operator[](int frameIndex) {
    if (frameIndex < 0 || frameIndex >= movieLength) {
        exitWithError(MatamErrorType::OutOfBounds);
    }
    return frames[frameIndex];
}

// Addition Assignment Operator (Movie + Movie)
MataMvidia& MataMvidia::operator+=(const MataMvidia& otherMovie) {
    for (int frameIndex = 0; frameIndex < otherMovie.movieLength; ++frameIndex) {
        (*this) += otherMovie[frameIndex];
    }
    return *this;
}

// Addition Operator (Movie + Movie)
MataMvidia operator+(const MataMvidia& firstMovie, const MataMvidia& secondMovie) {
    MataMvidia newMovie(firstMovie);
    newMovie += secondMovie;
    return newMovie;
}

// Addition Assignment Operator (Movie + Matrix)
MataMvidia& MataMvidia::operator+=(const Matrix& additionalFrame) {
    Matrix* updatedFrames = new Matrix[movieLength + 1];
    for (int frameIndex = 0; frameIndex < movieLength; ++frameIndex) {
        updatedFrames[frameIndex] = frames[frameIndex];
    }
    updatedFrames[movieLength] = additionalFrame;

    delete[] frames;
    frames = updatedFrames;
    movieLength++;

    return *this;
}

// Prints Movie Details
std::ostream& operator<<(std::ostream& outputStream, const MataMvidia& movie) {
    outputStream << "Movie Title: " << movie.movieName << std::endl;
    outputStream << "Creator: " << movie.authorName << std::endl;

    for (int frameIndex = 0; frameIndex < movie.movieLength; ++frameIndex) {
        outputStream << std::endl;
        outputStream << "Frame " << frameIndex << ":" << std::endl;
        outputStream << movie.frames[frameIndex];
    }

    outputStream << std::endl << "-----End of Movie-----" << std::endl;
    return outputStream;
}
