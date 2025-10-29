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
vector2_d plus(const vector2_d &A, double d);
vector2_d plus(double d, const vector2_d &A);
vector2_c plus(const vector2_d &A, const complex_d &c);
vector2_c plus(const complex_d &c, const vector2_d &A);
vector2_c plus(const vector2_c &A, double d);
vector2_c plus(double d, const vector2_c &A);
vector2_c plus(const vector2_c &A, const complex_d &c);
vector2_c plus(const complex_d &c, const vector2_c &A);
vector2_d &plus_self(vector2_d &A, double d);
vector2_c &plus_self(vector2_c &A, const complex_d &c);
vector2_c &plus_self(vector2_c &A, double d);
// matrix + vector
vector2_d plus(const vector2_d &A, const vector_d &v);
vector2_d plus(const vector_d &v, const vector2_d &A);
vector2_c plus(const vector2_d &A, const vector_c &v);
vector2_c plus(const vector_c &v, const vector2_d &A);
vector2_c plus(const vector2_c &A, const vector_d &v);
vector2_c plus(const vector_d &v, const vector2_c &A);
vector2_c plus(const vector2_c &A, const vector_c &v);
vector2_c plus(const vector_c &v, const vector2_c &A);
vector2_d &plus_self(vector2_d &A, const vector_d &v);
vector2_c &plus_self(vector2_c &A, const vector_c &v);
vector2_c &plus_self(vector2_c &A, const vector_d &v);
// matrix + matrix
vector2_d plus(const vector2_d &A, const vector2_d &B);
vector2_c plus(const vector2_c &A, const vector2_c &B);
vector2_c plus(const vector2_d &A, const vector2_c &B);
vector2_c plus(const vector2_c &A, const vector2_d &B);
vector2_d &plus_self(vector2_d &A, const vector2_d &B);
vector2_c &plus_self(vector2_c &A, const vector2_c &B);
vector2_c &plus_self(vector2_c &A, const vector2_d &B);
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
vector2_d minus(const vector2_d &A, double d);
vector2_d minus(double d, const vector2_d &A);
vector2_c minus(const vector2_d &A, const complex_d &c);
vector2_c minus(const complex_d &c, const vector2_d &A);
vector2_c minus(const vector2_c &A, double d);
vector2_c minus(double d, const vector2_c &A);
vector2_c minus(const vector2_c &A, const complex_d &c);
vector2_c minus(const complex_d &c, const vector2_c &A);
vector2_d &minus_self(vector2_d &A, double d);
vector2_c &minus_self(vector2_c &A, const complex_d &c);
vector2_c &minus_self(vector2_c &A, double d);
// matrix - vector
vector2_d minus(const vector2_d &A, const vector_d &v);
vector2_d minus(const vector_d &v, const vector2_d &A);
vector2_c minus(const vector2_d &A, const vector_c &v);
vector2_c minus(const vector_c &v, const vector2_d &A);
vector2_c minus(const vector2_c &A, const vector_d &v);
vector2_c minus(const vector_d &v, const vector2_c &A);
vector2_c minus(const vector2_c &A, const vector_c &v);
vector2_c minus(const vector_c &v, const vector2_c &A);
vector2_d &minus_self(vector2_d &A, const vector_d &v);
vector2_c &minus_self(vector2_c &A, const vector_c &v);
vector2_c &minus_self(vector2_c &A, const vector_d &v);
// matrix - matrix
vector2_d minus(const vector2_d &A, const vector2_d &B);
vector2_c minus(const vector2_c &A, const vector2_c &B);
vector2_c minus(const vector2_d &A, const vector2_c &B);
vector2_c minus(const vector2_c &A, const vector2_d &B);
vector2_d &minus_self(vector2_d &A, const vector2_d &B);
vector2_c &minus_self(vector2_c &A, const vector2_c &B);
vector2_c &minus_self(vector2_c &A, const vector2_d &B);
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
vector2_d times(const vector2_d &A, double d);
vector2_d times(double d, const vector2_d &A);
vector2_c times(const vector2_d &A, const complex_d &c);
vector2_c times(const complex_d &c, const vector2_d &A);
vector2_c times(const vector2_c &A, double d);
vector2_c times(double d, const vector2_c &A);
vector2_c times(const vector2_c &A, const complex_d &c);
vector2_c times(const complex_d &c, const vector2_c &A);
vector2_d &times_self(vector2_d &A, double d);
vector2_c &times_self(vector2_c &A, const complex_d &c);
vector2_c &times_self(vector2_c &A, double d);
// matrix .* vector
vector2_d times(const vector2_d &A, const vector_d &v);
vector2_d times(const vector_d &v, const vector2_d &A);
vector2_c times(const vector2_d &A, const vector_c &v);
vector2_c times(const vector_c &v, const vector2_d &A);
vector2_c times(const vector2_c &A, const vector_d &v);
vector2_c times(const vector_d &v, const vector2_c &A);
vector2_c times(const vector2_c &A, const vector_c &v);
vector2_c times(const vector_c &v, const vector2_c &A);
vector2_d &times_self(vector2_d &A, const vector_d &v);
vector2_c &times_self(vector2_c &A, const vector_c &v);
vector2_c &times_self(vector2_c &A, const vector_d &v);
// matrix .* matrix
vector2_d times(const vector2_d &A, const vector2_d &B);
vector2_c times(const vector2_c &A, const vector2_c &B);
vector2_c times(const vector2_d &A, const vector2_c &B);
vector2_c times(const vector2_c &A, const vector2_d &B);
vector2_d &times_self(vector2_d &A, const vector2_d &B);
vector2_c &times_self(vector2_c &A, const vector2_c &B);
vector2_c &times_self(vector2_c &A, const vector2_d &B);
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
vector2_d rdivide(const vector2_d &A, double d);
vector2_d rdivide(double d, const vector2_d &A);
vector2_c rdivide(const vector2_d &A, const complex_d &c);
vector2_c rdivide(const complex_d &c, const vector2_d &A);
vector2_c rdivide(const vector2_c &A, double d);
vector2_c rdivide(double d, const vector2_c &A);
vector2_c rdivide(const vector2_c &A, const complex_d &c);
vector2_c rdivide(const complex_d &c, const vector2_c &A);
vector2_d &rdivide_self(vector2_d &A, double d);
vector2_c &rdivide_self(vector2_c &A, const complex_d &c);
vector2_c &rdivide_self(vector2_c &A, double d);
// matrix ./ vector
vector2_d rdivide(const vector2_d &A, const vector_d &v);
vector2_d rdivide(const vector_d &v, const vector2_d &A);
vector2_c rdivide(const vector2_d &A, const vector_c &v);
vector2_c rdivide(const vector_c &v, const vector2_d &A);
vector2_c rdivide(const vector2_c &A, const vector_d &v);
vector2_c rdivide(const vector_d &v, const vector2_c &A);
vector2_c rdivide(const vector2_c &A, const vector_c &v);
vector2_c rdivide(const vector_c &v, const vector2_c &A);
vector2_d &rdivide_self(vector2_d &A, const vector_d &v);
vector2_c &rdivide_self(vector2_c &A, const vector_c &v);
vector2_c &rdivide_self(vector2_c &A, const vector_d &v);
// matrix ./ matrix
vector2_d rdivide(const vector2_d &A, const vector2_d &B);
vector2_c rdivide(const vector2_c &A, const vector2_c &B);
vector2_c rdivide(const vector2_d &A, const vector2_c &B);
vector2_c rdivide(const vector2_c &A, const vector2_d &B);
vector2_d &rdivide_self(vector2_d &A, const vector2_d &B);
vector2_c &rdivide_self(vector2_c &A, const vector2_c &B);
vector2_c &rdivide_self(vector2_c &A, const vector2_d &B);
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
zsl::vector2_d operator+(const zsl::vector2_d &A, double d);
zsl::vector2_d operator+(double d, const zsl::vector2_d &A);
zsl::vector2_c operator+(const zsl::vector2_d &A, const zsl::complex_d &c);
zsl::vector2_c operator+(const zsl::complex_d &c, const zsl::vector2_d &A);
zsl::vector2_c operator+(const zsl::vector2_c &A, double d);
zsl::vector2_c operator+(double d, const zsl::vector2_c &A);
zsl::vector2_c operator+(const zsl::vector2_c &A, const zsl::complex_d &c);
zsl::vector2_c operator+(const zsl::complex_d &c, const zsl::vector2_c &A);
zsl::vector2_d &operator+=(zsl::vector2_d &A, double d);
zsl::vector2_c &operator+=(zsl::vector2_c &A, const zsl::complex_d &c);
zsl::vector2_c &operator+=(zsl::vector2_c &A, double d);
// matrix + vector
zsl::vector2_d operator+(const zsl::vector2_d &A, const zsl::vector_d &v);
zsl::vector2_d operator+(const zsl::vector_d &v, const zsl::vector2_d &A);
zsl::vector2_c operator+(const zsl::vector2_d &A, const zsl::vector_c &v);
zsl::vector2_c operator+(const zsl::vector_c &v, const zsl::vector2_d &A);
zsl::vector2_c operator+(const zsl::vector2_c &A, const zsl::vector_d &v);
zsl::vector2_c operator+(const zsl::vector_d &v, const zsl::vector2_c &A);
zsl::vector2_c operator+(const zsl::vector2_c &A, const zsl::vector_c &v);
zsl::vector2_c operator+(const zsl::vector_c &v, const zsl::vector2_c &A);
zsl::vector2_d &operator+=(zsl::vector2_d &A, const zsl::vector_d &v);
zsl::vector2_c &operator+=(zsl::vector2_c &A, const zsl::vector_c &v);
zsl::vector2_c &operator+=(zsl::vector2_c &A, const zsl::vector_d &v);
// matrix + matrix
zsl::vector2_d operator+(const zsl::vector2_d &A, const zsl::vector2_d &B);
zsl::vector2_c operator+(const zsl::vector2_c &A, const zsl::vector2_c &B);
zsl::vector2_c operator+(const zsl::vector2_d &A, const zsl::vector2_c &B);
zsl::vector2_c operator+(const zsl::vector2_c &A, const zsl::vector2_d &B);
zsl::vector2_d &operator+=(zsl::vector2_d &A, const zsl::vector2_d &B);
zsl::vector2_c &operator+=(zsl::vector2_c &A, const zsl::vector2_c &B);
zsl::vector2_c &operator+=(zsl::vector2_c &A, const zsl::vector2_d &B);
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
zsl::vector2_d operator-(const zsl::vector2_d &A, double d);
zsl::vector2_d operator-(double d, const zsl::vector2_d &A);
zsl::vector2_c operator-(const zsl::vector2_d &A, const zsl::complex_d &c);
zsl::vector2_c operator-(const zsl::complex_d &c, const zsl::vector2_d &A);
zsl::vector2_c operator-(const zsl::vector2_c &A, double d);
zsl::vector2_c operator-(double d, const zsl::vector2_c &A);
zsl::vector2_c operator-(const zsl::vector2_c &A, const zsl::complex_d &c);
zsl::vector2_c operator-(const zsl::complex_d &c, const zsl::vector2_c &A);
zsl::vector2_d &operator-=(zsl::vector2_d &A, double d);
zsl::vector2_c &operator-=(zsl::vector2_c &A, const zsl::complex_d &c);
zsl::vector2_c &operator-=(zsl::vector2_c &A, double d);
// matrix - vector
zsl::vector2_d operator-(const zsl::vector2_d &A, const zsl::vector_d &v);
zsl::vector2_d operator-(const zsl::vector_d &v, const zsl::vector2_d &A);
zsl::vector2_c operator-(const zsl::vector2_d &A, const zsl::vector_c &v);
zsl::vector2_c operator-(const zsl::vector_c &v, const zsl::vector2_d &A);
zsl::vector2_c operator-(const zsl::vector2_c &A, const zsl::vector_d &v);
zsl::vector2_c operator-(const zsl::vector_d &v, const zsl::vector2_c &A);
zsl::vector2_c operator-(const zsl::vector2_c &A, const zsl::vector_c &v);
zsl::vector2_c operator-(const zsl::vector_c &v, const zsl::vector2_c &A);
zsl::vector2_d &operator-=(zsl::vector2_d &A, const zsl::vector_d &v);
zsl::vector2_c &operator-=(zsl::vector2_c &A, const zsl::vector_c &v);
zsl::vector2_c &operator-=(zsl::vector2_c &A, const zsl::vector_d &v);
// matrix - matrix
zsl::vector2_d operator-(const zsl::vector2_d &A, const zsl::vector2_d &B);
zsl::vector2_c operator-(const zsl::vector2_c &A, const zsl::vector2_c &B);
zsl::vector2_c operator-(const zsl::vector2_d &A, const zsl::vector2_c &B);
zsl::vector2_c operator-(const zsl::vector2_c &A, const zsl::vector2_d &B);
zsl::vector2_d &operator-=(zsl::vector2_d &A, const zsl::vector2_d &B);
zsl::vector2_c &operator-=(zsl::vector2_c &A, const zsl::vector2_c &B);
zsl::vector2_c &operator-=(zsl::vector2_c &A, const zsl::vector2_d &B);
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
zsl::vector2_d operator*(const zsl::vector2_d &A, double d);
zsl::vector2_d operator*(double d, const zsl::vector2_d &A);
zsl::vector2_c operator*(const zsl::vector2_d &A, const zsl::complex_d &c);
zsl::vector2_c operator*(const zsl::complex_d &c, const zsl::vector2_d &A);
zsl::vector2_c operator*(const zsl::vector2_c &A, double d);
zsl::vector2_c operator*(double d, const zsl::vector2_c &A);
zsl::vector2_c operator*(const zsl::vector2_c &A, const zsl::complex_d &c);
zsl::vector2_c operator*(const zsl::complex_d &c, const zsl::vector2_c &A);
zsl::vector2_d &operator*=(zsl::vector2_d &A, double d);
zsl::vector2_c &operator*=(zsl::vector2_c &A, const zsl::complex_d &c);
zsl::vector2_c &operator*=(zsl::vector2_c &A, double d);
// matrix * vector
zsl::vector2_d operator*(const zsl::vector2_d &A, const zsl::vector_d &v);
zsl::vector2_d operator*(const zsl::vector_d &v, const zsl::vector2_d &A);
zsl::vector2_c operator*(const zsl::vector2_d &A, const zsl::vector_c &v);
zsl::vector2_c operator*(const zsl::vector_c &v, const zsl::vector2_d &A);
zsl::vector2_c operator*(const zsl::vector2_c &A, const zsl::vector_d &v);
zsl::vector2_c operator*(const zsl::vector_d &v, const zsl::vector2_c &A);
zsl::vector2_c operator*(const zsl::vector2_c &A, const zsl::vector_c &v);
zsl::vector2_c operator*(const zsl::vector_c &v, const zsl::vector2_c &A);
zsl::vector2_d &operator*=(zsl::vector2_d &A, const zsl::vector_d &v);
zsl::vector2_c &operator*=(zsl::vector2_c &A, const zsl::vector_c &v);
zsl::vector2_c &operator*=(zsl::vector2_c &A, const zsl::vector_d &v);
// matrix * matrix
zsl::vector2_d operator*(const zsl::vector2_d &A, const zsl::vector2_d &B);
zsl::vector2_c operator*(const zsl::vector2_c &A, const zsl::vector2_c &B);
zsl::vector2_c operator*(const zsl::vector2_d &A, const zsl::vector2_c &B);
zsl::vector2_c operator*(const zsl::vector2_c &A, const zsl::vector2_d &B);
zsl::vector2_d &operator*=(zsl::vector2_d &A, const zsl::vector2_d &B);
zsl::vector2_c &operator*=(zsl::vector2_c &A, const zsl::vector2_c &B);
zsl::vector2_c &operator*=(zsl::vector2_c &A, const zsl::vector2_d &B);
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
zsl::vector2_d operator/(const zsl::vector2_d &A, double d);
zsl::vector2_d operator/(double d, const zsl::vector2_d &A);
zsl::vector2_c operator/(const zsl::vector2_d &A, const zsl::complex_d &c);
zsl::vector2_c operator/(const zsl::complex_d &c, const zsl::vector2_d &A);
zsl::vector2_c operator/(const zsl::vector2_c &A, double d);
zsl::vector2_c operator/(double d, const zsl::vector2_c &A);
zsl::vector2_c operator/(const zsl::vector2_c &A, const zsl::complex_d &c);
zsl::vector2_c operator/(const zsl::complex_d &c, const zsl::vector2_c &A);
zsl::vector2_d &operator/=(zsl::vector2_d &A, double d);
zsl::vector2_c &operator/=(zsl::vector2_c &A, const zsl::complex_d &c);
zsl::vector2_c &operator/=(zsl::vector2_c &A, double d);
// matrix / vector
zsl::vector2_d operator/(const zsl::vector2_d &A, const zsl::vector_d &v);
zsl::vector2_d operator/(const zsl::vector_d &v, const zsl::vector2_d &A);
zsl::vector2_c operator/(const zsl::vector2_d &A, const zsl::vector_c &v);
zsl::vector2_c operator/(const zsl::vector_c &v, const zsl::vector2_d &A);
zsl::vector2_c operator/(const zsl::vector2_c &A, const zsl::vector_d &v);
zsl::vector2_c operator/(const zsl::vector_d &v, const zsl::vector2_c &A);
zsl::vector2_c operator/(const zsl::vector2_c &A, const zsl::vector_c &v);
zsl::vector2_c operator/(const zsl::vector_c &v, const zsl::vector2_c &A);
zsl::vector2_d &operator/=(zsl::vector2_d &A, const zsl::vector_d &v);
zsl::vector2_c &operator/=(zsl::vector2_c &A, const zsl::vector_c &v);
zsl::vector2_c &operator/=(zsl::vector2_c &A, const zsl::vector_d &v);
// matrix / matrix
zsl::vector2_d operator/(const zsl::vector2_d &A, const zsl::vector2_d &B);
zsl::vector2_c operator/(const zsl::vector2_c &A, const zsl::vector2_c &B);
zsl::vector2_c operator/(const zsl::vector2_d &A, const zsl::vector2_c &B);
zsl::vector2_c operator/(const zsl::vector2_c &A, const zsl::vector2_d &B);
zsl::vector2_d &operator/=(zsl::vector2_d &A, const zsl::vector2_d &B);
zsl::vector2_c &operator/=(zsl::vector2_c &A, const zsl::vector2_c &B);
zsl::vector2_c &operator/=(zsl::vector2_c &A, const zsl::vector2_d &B);
#pragma endregion

#endif // !ZSL_ZATLAB_OPERATORS_AND_ARITHMETIC_OPERATOR_H
