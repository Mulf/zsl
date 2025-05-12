#ifndef ZSL_ZATLAB_OPERATORS_AND_ARITHMETIC_OPERATOR_H
#define ZSL_ZATLAB_OPERATORS_AND_ARITHMETIC_OPERATOR_H

#include "basics/basics.h"

namespace zsl {
#pragma region Addition
// vector + scalar
vector_d plus(const vector_d &v, double d);
vector_d plus(double d, const vector_d &v);
vector_c plus(const vector_d &v, const complex_d &c);
vector_c plus(const complex_d &c, const vector_d &v);
vector_c plus(const vector_c &v, double d);
vector_c plus(double d, const vector_c &v);
vector_c plus(const vector_c &v, const complex_d &c);
vector_c plus(const complex_d &c, const vector_c &v);
vector_d &plus_self(vector_d &v, double d);
vector_c &plus_self(vector_c &v, const complex_d &c);
vector_c &plus_self(vector_c &v, double d);
// vector + vector
vector_d plus(const vector_d &v, const vector_d &w);
vector_c plus(const vector_c &v, const vector_c &w);
vector_c plus(const vector_d &v, const vector_c &w);
vector_c plus(const vector_c &v, const vector_d &w);
vector_d &plus_self(vector_d &v, const vector_d &w);
vector_c &plus_self(vector_c &v, const vector_c &w);
vector_c &plus_self(vector_c &v, const vector_d &w);
// matrix + scalar
matrix_d plus(const matrix_d &A, double d);
matrix_d plus(double d, const matrix_d &A);
matrix_c plus(const matrix_d &A, const complex_d &c);
matrix_c plus(const complex_d &c, const matrix_d &A);
matrix_c plus(const matrix_c &A, double d);
matrix_c plus(double d, const matrix_c &A);
matrix_c plus(const matrix_c &A, const complex_d &c);
matrix_c plus(const complex_d &c, const matrix_c &A);
matrix_d &plus_self(matrix_d &A, double d);
matrix_c &plus_self(matrix_c &A, const complex_d &c);
matrix_c &plus_self(matrix_c &A, double d);
// matrix + vector
matrix_d plus(const matrix_d &A, const vector_d &v);
matrix_d plus(const vector_d &v, const matrix_d &A);
matrix_c plus(const matrix_d &A, const vector_c &v);
matrix_c plus(const vector_c &v, const matrix_d &A);
matrix_c plus(const matrix_c &A, const vector_d &v);
matrix_c plus(const vector_d &v, const matrix_c &A);
matrix_c plus(const matrix_c &A, const vector_c &v);
matrix_c plus(const vector_c &v, const matrix_c &A);
matrix_d &plus_self(matrix_d &A, const vector_d &v);
matrix_c &plus_self(matrix_c &A, const vector_c &v);
matrix_c &plus_self(matrix_c &A, const vector_d &v);
// matrix + matrix
matrix_d plus(const matrix_d &A, const matrix_d &B);
matrix_c plus(const matrix_c &A, const matrix_c &B);
matrix_c plus(const matrix_d &A, const matrix_c &B);
matrix_c plus(const matrix_c &A, const matrix_d &B);
matrix_d &plus_self(matrix_d &A, const matrix_d &B);
matrix_c &plus_self(matrix_c &A, const matrix_c &B);
matrix_c &plus_self(matrix_c &A, const matrix_d &B);
#pragma endregion

#pragma region Subtraction
// vector - scalar
vector_d minus(const vector_d &v, double d);
vector_d minus(double d, const vector_d &v);
vector_c minus(const vector_d &v, const complex_d &c);
vector_c minus(const complex_d &c, const vector_d &v);
vector_c minus(const vector_c &v, double d);
vector_c minus(double d, const vector_c &v);
vector_c minus(const vector_c &v, const complex_d &c);
vector_c minus(const complex_d &c, const vector_c &v);
vector_d &minus_self(vector_d &v, double d);
vector_c &minus_self(vector_c &v, const complex_d &c);
vector_c &minus_self(vector_c &v, double d);
// vector - vector
vector_d minus(const vector_d &v, const vector_d &w);
vector_c minus(const vector_c &v, const vector_c &w);
vector_c minus(const vector_d &v, const vector_c &w);
vector_c minus(const vector_c &v, const vector_d &w);
vector_d &minus_self(vector_d &v, const vector_d &w);
vector_c &minus_self(vector_c &v, const vector_c &w);
vector_c &minus_self(vector_c &v, const vector_d &w);
// matrix - scalar
matrix_d minus(const matrix_d &A, double d);
matrix_d minus(double d, const matrix_d &A);
matrix_c minus(const matrix_d &A, const complex_d &c);
matrix_c minus(const complex_d &c, const matrix_d &A);
matrix_c minus(const matrix_c &A, double d);
matrix_c minus(double d, const matrix_c &A);
matrix_c minus(const matrix_c &A, const complex_d &c);
matrix_c minus(const complex_d &c, const matrix_c &A);
matrix_d &minus_self(matrix_d &A, double d);
matrix_c &minus_self(matrix_c &A, const complex_d &c);
matrix_c &minus_self(matrix_c &A, double d);
// matrix - vector
matrix_d minus(const matrix_d &A, const vector_d &v);
matrix_d minus(const vector_d &v, const matrix_d &A);
matrix_c minus(const matrix_d &A, const vector_c &v);
matrix_c minus(const vector_c &v, const matrix_d &A);
matrix_c minus(const matrix_c &A, const vector_d &v);
matrix_c minus(const vector_d &v, const matrix_c &A);
matrix_c minus(const matrix_c &A, const vector_c &v);
matrix_c minus(const vector_c &v, const matrix_c &A);
matrix_d &minus_self(matrix_d &A, const vector_d &v);
matrix_c &minus_self(matrix_c &A, const vector_c &v);
matrix_c &minus_self(matrix_c &A, const vector_d &v);
// matrix - matrix
matrix_d minus(const matrix_d &A, const matrix_d &B);
matrix_c minus(const matrix_c &A, const matrix_c &B);
matrix_c minus(const matrix_d &A, const matrix_c &B);
matrix_c minus(const matrix_c &A, const matrix_d &B);
matrix_d &minus_self(matrix_d &A, const matrix_d &B);
matrix_c &minus_self(matrix_c &A, const matrix_c &B);
matrix_c &minus_self(matrix_c &A, const matrix_d &B);
#pragma endregion

#pragma region Muliplication
// vector * scalar
vector_d times(const vector_d &v, double d);
vector_d times(double d, const vector_d &v);
vector_c times(const vector_d &v, const complex_d &c);
vector_c times(const complex_d &c, const vector_d &v);
vector_c times(const vector_c &v, double d);
vector_c times(double d, const vector_c &v);
vector_c times(const vector_c &v, const complex_d &c);
vector_c times(const complex_d &c, const vector_c &v);
vector_d &times_self(vector_d &v, double d);
vector_c &times_self(vector_c &v, const complex_d &c);
vector_c &times_self(vector_c &v, double d);
// vector .* vector
vector_d times(const vector_d &v, const vector_d &w);
vector_c times(const vector_c &v, const vector_c &w);
vector_c times(const vector_d &v, const vector_c &w);
vector_c times(const vector_c &v, const vector_d &w);
vector_d &times_self(vector_d &v, const vector_d &w);
vector_c &times_self(vector_c &v, const vector_c &w);
vector_c &times_self(vector_c &v, const vector_d &w);
// matrix * scalar
matrix_d times(const matrix_d &A, double d);
matrix_d times(double d, const matrix_d &A);
matrix_c times(const matrix_d &A, const complex_d &c);
matrix_c times(const complex_d &c, const matrix_d &A);
matrix_c times(const matrix_c &A, double d);
matrix_c times(double d, const matrix_c &A);
matrix_c times(const matrix_c &A, const complex_d &c);
matrix_c times(const complex_d &c, const matrix_c &A);
matrix_d &times_self(matrix_d &A, double d);
matrix_c &times_self(matrix_c &A, const complex_d &c);
matrix_c &times_self(matrix_c &A, double d);
// matrix .* vector
matrix_d times(const matrix_d &A, const vector_d &v);
matrix_d times(const vector_d &v, const matrix_d &A);
matrix_c times(const matrix_d &A, const vector_c &v);
matrix_c times(const vector_c &v, const matrix_d &A);
matrix_c times(const matrix_c &A, const vector_d &v);
matrix_c times(const vector_d &v, const matrix_c &A);
matrix_c times(const matrix_c &A, const vector_c &v);
matrix_c times(const vector_c &v, const matrix_c &A);
matrix_d &times_self(matrix_d &A, const vector_d &v);
matrix_c &times_self(matrix_c &A, const vector_c &v);
matrix_c &times_self(matrix_c &A, const vector_d &v);
// matrix .* matrix
matrix_d times(const matrix_d &A, const matrix_d &B);
matrix_c times(const matrix_c &A, const matrix_c &B);
matrix_c times(const matrix_d &A, const matrix_c &B);
matrix_c times(const matrix_c &A, const matrix_d &B);
matrix_d &times_self(matrix_d &A, const matrix_d &B);
matrix_c &times_self(matrix_c &A, const matrix_c &B);
matrix_c &times_self(matrix_c &A, const matrix_d &B);
#pragma endregion

#pragma region Rdivide
// vector / scalar
vector_d rdivide(const vector_d &v, double d);
vector_d rdivide(double d, const vector_d &v);
vector_c rdivide(const vector_d &v, const complex_d &c);
vector_c rdivide(const complex_d &c, const vector_d &v);
vector_c rdivide(const vector_c &v, double d);
vector_c rdivide(double d, const vector_c &v);
vector_c rdivide(const vector_c &v, const complex_d &c);
vector_c rdivide(const complex_d &c, const vector_c &v);
vector_d &rdivide_self(vector_d &v, double d);
vector_c &rdivide_self(vector_c &v, const complex_d &c);
vector_c &rdivide_self(vector_c &v, double d);
// vector ./ vector
vector_d rdivide(const vector_d &v, const vector_d &w);
vector_c rdivide(const vector_c &v, const vector_c &w);
vector_c rdivide(const vector_d &v, const vector_c &w);
vector_c rdivide(const vector_c &v, const vector_d &w);
vector_d &rdivide_self(vector_d &v, const vector_d &w);
vector_c &rdivide_self(vector_c &v, const vector_c &w);
vector_c &rdivide_self(vector_c &v, const vector_d &w);
// matrix / scalar
matrix_d rdivide(const matrix_d &A, double d);
matrix_d rdivide(double d, const matrix_d &A);
matrix_c rdivide(const matrix_d &A, const complex_d &c);
matrix_c rdivide(const complex_d &c, const matrix_d &A);
matrix_c rdivide(const matrix_c &A, double d);
matrix_c rdivide(double d, const matrix_c &A);
matrix_c rdivide(const matrix_c &A, const complex_d &c);
matrix_c rdivide(const complex_d &c, const matrix_c &A);
matrix_d &rdivide_self(matrix_d &A, double d);
matrix_c &rdivide_self(matrix_c &A, const complex_d &c);
matrix_c &rdivide_self(matrix_c &A, double d);
// matrix ./ vector
matrix_d rdivide(const matrix_d &A, const vector_d &v);
matrix_d rdivide(const vector_d &v, const matrix_d &A);
matrix_c rdivide(const matrix_d &A, const vector_c &v);
matrix_c rdivide(const vector_c &v, const matrix_d &A);
matrix_c rdivide(const matrix_c &A, const vector_d &v);
matrix_c rdivide(const vector_d &v, const matrix_c &A);
matrix_c rdivide(const matrix_c &A, const vector_c &v);
matrix_c rdivide(const vector_c &v, const matrix_c &A);
matrix_d &rdivide_self(matrix_d &A, const vector_d &v);
matrix_c &rdivide_self(matrix_c &A, const vector_c &v);
matrix_c &rdivide_self(matrix_c &A, const vector_d &v);
// matrix ./ matrix
matrix_d rdivide(const matrix_d &A, const matrix_d &B);
matrix_c rdivide(const matrix_c &A, const matrix_c &B);
matrix_c rdivide(const matrix_d &A, const matrix_c &B);
matrix_c rdivide(const matrix_c &A, const matrix_d &B);
matrix_d &rdivide_self(matrix_d &A, const matrix_d &B);
matrix_c &rdivide_self(matrix_c &A, const matrix_c &B);
matrix_c &rdivide_self(matrix_c &A, const matrix_d &B);
#pragma endregion
} // namespace zsl

#pragma region Addition Plus sign Overload
// vector + scalar
zsl::vector_d operator+(const zsl::vector_d &v, double d);
zsl::vector_d operator+(double d, const zsl::vector_d &v);
zsl::vector_c operator+(const zsl::vector_d &v, const zsl::complex_d &c);
zsl::vector_c operator+(const zsl::complex_d &c, const zsl::vector_d &v);
zsl::vector_c operator+(const zsl::vector_c &v, double d);
zsl::vector_c operator+(double d, const zsl::vector_c &v);
zsl::vector_c operator+(const zsl::vector_c &v, const zsl::complex_d &c);
zsl::vector_c operator+(const zsl::complex_d &c, const zsl::vector_c &v);
zsl::vector_d &operator+=(zsl::vector_d &v, double d);
zsl::vector_c &operator+=(zsl::vector_c &v, const zsl::complex_d &c);
zsl::vector_c &operator+=(zsl::vector_c &v, double d);
// vector + vector
zsl::vector_d operator+(const zsl::vector_d &v, const zsl::vector_d &w);
zsl::vector_c operator+(const zsl::vector_c &v, const zsl::vector_c &w);
zsl::vector_c operator+(const zsl::vector_d &v, const zsl::vector_c &w);
zsl::vector_c operator+(const zsl::vector_c &v, const zsl::vector_d &w);
zsl::vector_d &operator+=(zsl::vector_d &v, const zsl::vector_d &w);
zsl::vector_c &operator+=(zsl::vector_c &v, const zsl::vector_c &w);
zsl::vector_c &operator+=(zsl::vector_c &v, const zsl::vector_d &w);
// matrix + scalar
zsl::matrix_d operator+(const zsl::matrix_d &A, double d);
zsl::matrix_d operator+(double d, const zsl::matrix_d &A);
zsl::matrix_c operator+(const zsl::matrix_d &A, const zsl::complex_d &c);
zsl::matrix_c operator+(const zsl::complex_d &c, const zsl::matrix_d &A);
zsl::matrix_c operator+(const zsl::matrix_c &A, double d);
zsl::matrix_c operator+(double d, const zsl::matrix_c &A);
zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::complex_d &c);
zsl::matrix_c operator+(const zsl::complex_d &c, const zsl::matrix_c &A);
zsl::matrix_d &operator+=(zsl::matrix_d &A, double d);
zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::complex_d &c);
zsl::matrix_c &operator+=(zsl::matrix_c &A, double d);
// matrix + vector
zsl::matrix_d operator+(const zsl::matrix_d &A, const zsl::vector_d &v);
zsl::matrix_d operator+(const zsl::vector_d &v, const zsl::matrix_d &A);
zsl::matrix_c operator+(const zsl::matrix_d &A, const zsl::vector_c &v);
zsl::matrix_c operator+(const zsl::vector_c &v, const zsl::matrix_d &A);
zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::vector_d &v);
zsl::matrix_c operator+(const zsl::vector_d &v, const zsl::matrix_c &A);
zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::vector_c &v);
zsl::matrix_c operator+(const zsl::vector_c &v, const zsl::matrix_c &A);
zsl::matrix_d &operator+=(zsl::matrix_d &A, const zsl::vector_d &v);
zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::vector_c &v);
zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::vector_d &v);
// matrix + matrix
zsl::matrix_d operator+(const zsl::matrix_d &A, const zsl::matrix_d &B);
zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::matrix_c &B);
zsl::matrix_c operator+(const zsl::matrix_d &A, const zsl::matrix_c &B);
zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::matrix_d &B);
zsl::matrix_d &operator+=(zsl::matrix_d &A, const zsl::matrix_d &B);
zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::matrix_c &B);
zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::matrix_d &B);
#pragma endregion

#pragma region Subtraction Sign Overload
// vector - scalar
zsl::vector_d operator-(const zsl::vector_d &v, double d);
zsl::vector_d operator-(double d, const zsl::vector_d &v);
zsl::vector_c operator-(const zsl::vector_d &v, const zsl::complex_d &c);
zsl::vector_c operator-(const zsl::complex_d &c, const zsl::vector_d &v);
zsl::vector_c operator-(const zsl::vector_c &v, double d);
zsl::vector_c operator-(double d, const zsl::vector_c &v);
zsl::vector_c operator-(const zsl::vector_c &v, const zsl::complex_d &c);
zsl::vector_c operator-(const zsl::complex_d &c, const zsl::vector_c &v);
zsl::vector_d &operator-=(zsl::vector_d &v, double d);
zsl::vector_c &operator-=(zsl::vector_c &v, const zsl::complex_d &c);
zsl::vector_c &operator-=(zsl::vector_c &v, double d);
// vector - vector
zsl::vector_d operator-(const zsl::vector_d &v, const zsl::vector_d &w);
zsl::vector_c operator-(const zsl::vector_c &v, const zsl::vector_c &w);
zsl::vector_c operator-(const zsl::vector_d &v, const zsl::vector_c &w);
zsl::vector_c operator-(const zsl::vector_c &v, const zsl::vector_d &w);
zsl::vector_d &operator-=(zsl::vector_d &v, const zsl::vector_d &w);
zsl::vector_c &operator-=(zsl::vector_c &v, const zsl::vector_c &w);
zsl::vector_c &operator-=(zsl::vector_c &v, const zsl::vector_d &w);
// matrix - scalar
zsl::matrix_d operator-(const zsl::matrix_d &A, double d);
zsl::matrix_d operator-(double d, const zsl::matrix_d &A);
zsl::matrix_c operator-(const zsl::matrix_d &A, const zsl::complex_d &c);
zsl::matrix_c operator-(const zsl::complex_d &c, const zsl::matrix_d &A);
zsl::matrix_c operator-(const zsl::matrix_c &A, double d);
zsl::matrix_c operator-(double d, const zsl::matrix_c &A);
zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::complex_d &c);
zsl::matrix_c operator-(const zsl::complex_d &c, const zsl::matrix_c &A);
zsl::matrix_d &operator-=(zsl::matrix_d &A, double d);
zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::complex_d &c);
zsl::matrix_c &operator-=(zsl::matrix_c &A, double d);
// matrix - vector
zsl::matrix_d operator-(const zsl::matrix_d &A, const zsl::vector_d &v);
zsl::matrix_d operator-(const zsl::vector_d &v, const zsl::matrix_d &A);
zsl::matrix_c operator-(const zsl::matrix_d &A, const zsl::vector_c &v);
zsl::matrix_c operator-(const zsl::vector_c &v, const zsl::matrix_d &A);
zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::vector_d &v);
zsl::matrix_c operator-(const zsl::vector_d &v, const zsl::matrix_c &A);
zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::vector_c &v);
zsl::matrix_c operator-(const zsl::vector_c &v, const zsl::matrix_c &A);
zsl::matrix_d &operator-=(zsl::matrix_d &A, const zsl::vector_d &v);
zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::vector_c &v);
zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::vector_d &v);
// matrix - matrix
zsl::matrix_d operator-(const zsl::matrix_d &A, const zsl::matrix_d &B);
zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::matrix_c &B);
zsl::matrix_c operator-(const zsl::matrix_d &A, const zsl::matrix_c &B);
zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::matrix_d &B);
zsl::matrix_d &operator-=(zsl::matrix_d &A, const zsl::matrix_d &B);
zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::matrix_c &B);
zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::matrix_d &B);
#pragma endregion

#pragma region Times Sign Overload
// vector * scalar
zsl::vector_d operator*(const zsl::vector_d &v, double d);
zsl::vector_d operator*(double d, const zsl::vector_d &v);
zsl::vector_c operator*(const zsl::vector_d &v, const zsl::complex_d &c);
zsl::vector_c operator*(const zsl::complex_d &c, const zsl::vector_d &v);
zsl::vector_c operator*(const zsl::vector_c &v, double d);
zsl::vector_c operator*(double d, const zsl::vector_c &v);
zsl::vector_c operator*(const zsl::vector_c &v, const zsl::complex_d &c);
zsl::vector_c operator*(const zsl::complex_d &c, const zsl::vector_c &v);
zsl::vector_d &operator*=(zsl::vector_d &v, double d);
zsl::vector_c &operator*=(zsl::vector_c &v, const zsl::complex_d &c);
zsl::vector_c &operator*=(zsl::vector_c &v, double d);
// vector * vector
zsl::vector_d operator*(const zsl::vector_d &v, const zsl::vector_d &w);
zsl::vector_c operator*(const zsl::vector_c &v, const zsl::vector_c &w);
zsl::vector_c operator*(const zsl::vector_d &v, const zsl::vector_c &w);
zsl::vector_c operator*(const zsl::vector_c &v, const zsl::vector_d &w);
zsl::vector_d &operator*=(zsl::vector_d &v, const zsl::vector_d &w);
zsl::vector_c &operator*=(zsl::vector_c &v, const zsl::vector_c &w);
zsl::vector_c &operator*=(zsl::vector_c &v, const zsl::vector_d &w);
// matrix * scalar
zsl::matrix_d operator*(const zsl::matrix_d &A, double d);
zsl::matrix_d operator*(double d, const zsl::matrix_d &A);
zsl::matrix_c operator*(const zsl::matrix_d &A, const zsl::complex_d &c);
zsl::matrix_c operator*(const zsl::complex_d &c, const zsl::matrix_d &A);
zsl::matrix_c operator*(const zsl::matrix_c &A, double d);
zsl::matrix_c operator*(double d, const zsl::matrix_c &A);
zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::complex_d &c);
zsl::matrix_c operator*(const zsl::complex_d &c, const zsl::matrix_c &A);
zsl::matrix_d &operator*=(zsl::matrix_d &A, double d);
zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::complex_d &c);
zsl::matrix_c &operator*=(zsl::matrix_c &A, double d);
// matrix * vector
zsl::matrix_d operator*(const zsl::matrix_d &A, const zsl::vector_d &v);
zsl::matrix_d operator*(const zsl::vector_d &v, const zsl::matrix_d &A);
zsl::matrix_c operator*(const zsl::matrix_d &A, const zsl::vector_c &v);
zsl::matrix_c operator*(const zsl::vector_c &v, const zsl::matrix_d &A);
zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::vector_d &v);
zsl::matrix_c operator*(const zsl::vector_d &v, const zsl::matrix_c &A);
zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::vector_c &v);
zsl::matrix_c operator*(const zsl::vector_c &v, const zsl::matrix_c &A);
zsl::matrix_d &operator*=(zsl::matrix_d &A, const zsl::vector_d &v);
zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::vector_c &v);
zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::vector_d &v);
// matrix * matrix
zsl::matrix_d operator*(const zsl::matrix_d &A, const zsl::matrix_d &B);
zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::matrix_c &B);
zsl::matrix_c operator*(const zsl::matrix_d &A, const zsl::matrix_c &B);
zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::matrix_d &B);
zsl::matrix_d &operator*=(zsl::matrix_d &A, const zsl::matrix_d &B);
zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::matrix_c &B);
zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::matrix_d &B);
#pragma endregion

#pragma region Rdivide Sign Overload
// vector / scalar
zsl::vector_d operator/(const zsl::vector_d &v, double d);
zsl::vector_d operator/(double d, const zsl::vector_d &v);
zsl::vector_c operator/(const zsl::vector_d &v, const zsl::complex_d &c);
zsl::vector_c operator/(const zsl::complex_d &c, const zsl::vector_d &v);
zsl::vector_c operator/(const zsl::vector_c &v, double d);
zsl::vector_c operator/(double d, const zsl::vector_c &v);
zsl::vector_c operator/(const zsl::vector_c &v, const zsl::complex_d &c);
zsl::vector_c operator/(const zsl::complex_d &c, const zsl::vector_c &v);
zsl::vector_d &operator/=(zsl::vector_d &v, double d);
zsl::vector_c &operator/=(zsl::vector_c &v, const zsl::complex_d &c);
zsl::vector_c &operator/=(zsl::vector_c &v, double d);
// vector / vector
zsl::vector_d operator/(const zsl::vector_d &v, const zsl::vector_d &w);
zsl::vector_c operator/(const zsl::vector_c &v, const zsl::vector_c &w);
zsl::vector_c operator/(const zsl::vector_d &v, const zsl::vector_c &w);
zsl::vector_c operator/(const zsl::vector_c &v, const zsl::vector_d &w);
zsl::vector_d &operator/=(zsl::vector_d &v, const zsl::vector_d &w);
zsl::vector_c &operator/=(zsl::vector_c &v, const zsl::vector_c &w);
zsl::vector_c &operator/=(zsl::vector_c &v, const zsl::vector_d &w);
// matrix / scalar
zsl::matrix_d operator/(const zsl::matrix_d &A, double d);
zsl::matrix_d operator/(double d, const zsl::matrix_d &A);
zsl::matrix_c operator/(const zsl::matrix_d &A, const zsl::complex_d &c);
zsl::matrix_c operator/(const zsl::complex_d &c, const zsl::matrix_d &A);
zsl::matrix_c operator/(const zsl::matrix_c &A, double d);
zsl::matrix_c operator/(double d, const zsl::matrix_c &A);
zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::complex_d &c);
zsl::matrix_c operator/(const zsl::complex_d &c, const zsl::matrix_c &A);
zsl::matrix_d &operator/=(zsl::matrix_d &A, double d);
zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::complex_d &c);
zsl::matrix_c &operator/=(zsl::matrix_c &A, double d);
// matrix / vector
zsl::matrix_d operator/(const zsl::matrix_d &A, const zsl::vector_d &v);
zsl::matrix_d operator/(const zsl::vector_d &v, const zsl::matrix_d &A);
zsl::matrix_c operator/(const zsl::matrix_d &A, const zsl::vector_c &v);
zsl::matrix_c operator/(const zsl::vector_c &v, const zsl::matrix_d &A);
zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::vector_d &v);
zsl::matrix_c operator/(const zsl::vector_d &v, const zsl::matrix_c &A);
zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::vector_c &v);
zsl::matrix_c operator/(const zsl::vector_c &v, const zsl::matrix_c &A);
zsl::matrix_d &operator/=(zsl::matrix_d &A, const zsl::vector_d &v);
zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::vector_c &v);
zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::vector_d &v);
// matrix / matrix
zsl::matrix_d operator/(const zsl::matrix_d &A, const zsl::matrix_d &B);
zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::matrix_c &B);
zsl::matrix_c operator/(const zsl::matrix_d &A, const zsl::matrix_c &B);
zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::matrix_d &B);
zsl::matrix_d &operator/=(zsl::matrix_d &A, const zsl::matrix_d &B);
zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::matrix_c &B);
zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::matrix_d &B);
#pragma endregion

#endif // !ZSL_ZATLAB_OPERATORS_AND_ARITHMETIC_OPERATOR_H
