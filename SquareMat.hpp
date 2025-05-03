//anksilae@gmail.com

#ifndef SQUAREMAT_HPP
#define SQUAREMAT_HPP

#include <iostream>
#include <functional>

namespace matrix {

class SquareMat {
private:
    int size;
    double** data;

public:

//--------------------------------//
// Constructors and Destructor
//--------------------------------//

    SquareMat(int size);// Constructor from 2D array input
    explicit SquareMat(int size, double scalar);// Constructor to initialize all elements to scalar
    SquareMat(const SquareMat& other);        // Copy constructor
    ~SquareMat();                             // Destructor

//--------------------------------//
// Access operators
//--------------------------------//

    double* operator[](int index);              // Access row for modification
    const double* operator[](int index) const;  // Access row for reading only

//--------------------------------//
// Assignment operators
//--------------------------------//

    SquareMat& operator=(const SquareMat& other); // Assignment from another matrix
    SquareMat& operator=(double scalar);             // Assignment from a scalar (fills matrix)

//--------------------------------//
// Arithmetic operators
//--------------------------------//

    SquareMat operator+(const SquareMat& other) const; // Matrix addition
    SquareMat operator-(const SquareMat& other) const; // Matrix subtraction
    SquareMat operator-() const;                       // Unary minus (negation)
    SquareMat operator*(const SquareMat& other) const; // Matrix multiplication
    friend SquareMat operator*(const SquareMat& mat, double scalar); // Matrix * scalar
    friend SquareMat operator*(double scalar, const SquareMat& mat); // Scalar * matrix
    SquareMat operator%(const SquareMat& other) const;            // Element-wise multiplication (%)
    SquareMat operator%(int scalar) const;                        // Element-wise modulo with scalar
    SquareMat operator/(double scalar) const;                        // Division by scalar
    SquareMat operator^(int power) const;                         // Matrix raised to power

    SquareMat& operator++();   // Pre-increment (++mat)
    SquareMat operator++(int); // Post-increment (mat++)
    SquareMat& operator--();   // Pre-decrement (--mat)
    SquareMat operator--(int); // Post-decrement (mat--)

    SquareMat operator~() const; // Transpose (~)

//--------------------------------//
// Comparison operators
//--------------------------------//

    bool operator==(const SquareMat& other) const; // Equality based on sum of elements
    bool operator!=(const SquareMat& other) const; // Inequality based on sum of elements
    bool operator<(const SquareMat& other) const;  // Less than based on sum
    bool operator>(const SquareMat& other) const;  // Greater than based on sum
    bool operator<=(const SquareMat& other) const; // Less than or equal based on sum
    bool operator>=(const SquareMat& other) const; // Greater than or equal based on sum

    double operator!() const; // Determinant using upper triangular form (!)

//--------------------------//
// Self application operators
//--------------------------//

    SquareMat& operator+=(const SquareMat& other); // Add and assign
    SquareMat& operator-=(const SquareMat& other); // Subtract and assign
    SquareMat& operator*=(const SquareMat& other); // Multiply matrices and assign
    SquareMat& operator/=(double scalar);             // Divide by scalar and assign
    SquareMat& operator%=(const SquareMat& other); // Element-wise multiplication and assign
    SquareMat& operator*=(double scalar);             // Multiply by scalar and assign
    SquareMat& operator%=(double scalar);             // Modulo by scalar and assign

//--------------------------//
// Print
//--------------------------//

    friend std::ostream& operator<<(std::ostream& out, const SquareMat& mat); // Print matrix to output stream

private:

//--------------------------//
// Private functions
//--------------------------//

    SquareMat toUpperTriangular(int& swapCount) const; // Convert to upper triangular form (for determinant)
    double getSum() const;                             // Return the sum of all elements
    int comparator(const SquareMat& a, const SquareMat& b) const; // Compare matrices based on sum
};

} // namespace matrix

#endif
