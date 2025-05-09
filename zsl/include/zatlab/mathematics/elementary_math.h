#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H
#define ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H

#include "basics/basics.h"

namespace zsl {
#pragma region Trigonometry
// sin
vector_d sin(const vector_d &v);
vector_c sin(const vector_c &v);
matrix_d sin(const matrix_d &v);
matrix_c sin(const matrix_c &A);
vector_d sind(const vector_d &v);
vector_c sind(const vector_c &v);
matrix_d sind(const matrix_d &A);
matrix_c sind(const matrix_c &A);
vector_d sinpi(const vector_d &v);
vector_c sinpi(const vector_c &v);
matrix_d sinpi(const matrix_d &A);
matrix_c sinpi(const matrix_c &A);
vector_d asin(const vector_d &v);
vector_c asin(const vector_c &v);
matrix_d asin(const matrix_d &A);
matrix_c asin(const matrix_c &A);
vector_d sinh(const vector_d &v);
vector_c sinh(const vector_c &v);
matrix_d sinh(const matrix_d &A);
matrix_c sinh(const matrix_c &A);
vector_d asinh(const vector_d &v);
vector_c asinh(const vector_c &v);
matrix_d asinh(const matrix_d &A);
matrix_c asinh(const matrix_c &A);

// cos
vector_d cos(const vector_d &v);
vector_c cos(const vector_c &v);
matrix_d cos(const matrix_d &v);
matrix_c cos(const matrix_c &A);
vector_d cosd(const vector_d &v);
vector_c cosd(const vector_c &v);
matrix_d cosd(const matrix_d &A);
matrix_c cosd(const matrix_c &A);
vector_d cospi(const vector_d &v);
vector_c cospi(const vector_c &v);
matrix_d cospi(const matrix_d &A);
matrix_c cospi(const matrix_c &A);
vector_d acos(const vector_d &v);
vector_c acos(const vector_c &v);
matrix_d acos(const matrix_d &A);
matrix_c acos(const matrix_c &A);
vector_d cosh(const vector_d &v);
vector_c cosh(const vector_c &v);
matrix_d cosh(const matrix_d &A);
matrix_c cosh(const matrix_c &A);
vector_d acosh(const vector_d &v);
vector_c acosh(const vector_c &v);
matrix_d acosh(const matrix_d &A);
matrix_c acosh(const matrix_c &A);

// tan
vector_d tan(const vector_d &v);
vector_c tan(const vector_c &v);
matrix_d tan(const matrix_d &v);
matrix_c tan(const matrix_c &A);
vector_d tand(const vector_d &v);
vector_c tand(const vector_c &v);
matrix_d tand(const matrix_d &A);
matrix_c tand(const matrix_c &A);
vector_d tanpi(const vector_d &v);
vector_c tanpi(const vector_c &v);
matrix_d tanpi(const matrix_d &A);
matrix_c tanpi(const matrix_c &A);
vector_d atan(const vector_d &v);
vector_c atan(const vector_c &v);
matrix_d atan(const matrix_d &A);
matrix_c atan(const matrix_c &A);
vector_d tanh(const vector_d &v);
vector_c tanh(const vector_c &v);
matrix_d tanh(const matrix_d &A);
matrix_c tanh(const matrix_c &A);
vector_d atanh(const vector_d &v);
vector_c atanh(const vector_c &v);
matrix_d atanh(const matrix_d &A);
matrix_c atanh(const matrix_c &A);

// csc
vector_d csc(const vector_d &v);
matrix_d csc(const matrix_d &v);
vector_d cscd(const vector_d &v);
matrix_d cscd(const matrix_d &A);
vector_d acsc(const vector_d &v);
matrix_d acsc(const matrix_d &A);
vector_d acscd(const vector_d &v);
matrix_d acscd(const matrix_d &A);
vector_d csch(const vector_d &v);
matrix_d csch(const matrix_d &A);
vector_d acsch(const vector_d &v);
matrix_d acsch(const matrix_d &A);

// sec
vector_d sec(const vector_d &v);
matrix_d sec(const matrix_d &v);
vector_d secd(const vector_d &v);
matrix_d secd(const matrix_d &A);
vector_d asec(const vector_d &v);
matrix_d asec(const matrix_d &A);
vector_d asecd(const vector_d &v);
matrix_d asecd(const matrix_d &A);
vector_d sech(const vector_d &v);
matrix_d sech(const matrix_d &A);
vector_d asech(const vector_d &v);
matrix_d asech(const matrix_d &A);

// cot
vector_d cot(const vector_d &v);
matrix_d cot(const matrix_d &v);
vector_d cotd(const vector_d &v);
matrix_d cotd(const matrix_d &A);
vector_d acot(const vector_d &v);
matrix_d acot(const matrix_d &A);
vector_d acotd(const vector_d &v);
matrix_d acotd(const matrix_d &A);
vector_d coth(const vector_d &v);
matrix_d coth(const matrix_d &A);
vector_d acoth(const vector_d &v);
matrix_d acoth(const matrix_d &A);

// conversions
double deg2rad(double x);
vector_d deg2rad(const vector_d &v);
matrix_d deg2rad(const matrix_d &A);
double rad2deg(double x);
vector_d rad2deg(const vector_d &v);
matrix_d rad2deg(const matrix_d &A);

#pragma endregion

#pragma region Exponents and Logarithms
//exp
vector_d exp(const vector_d &v);
vector_c exp(const vector_c &v);
matrix_d exp(const matrix_d &A);
matrix_c exp(const matrix_c &A);
// log
vector_d log(const vector_d &v);
vector_c log(const vector_c &v);
matrix_d log(const matrix_d &A);
matrix_c log(const matrix_c &A);
// log10
vector_d log10(const vector_d &v);
vector_c log10(const vector_c &v);
matrix_d log10(const matrix_d &A);
matrix_c log10(const matrix_c &A);
// log2
vector_d log2(const vector_d &v);
vector_c log2(const vector_c &v);
matrix_d log2(const matrix_d &A);
matrix_c log2(const matrix_c &A);
// pow2
double pow2(double x);
complex_d pow2(const complex_d &z);
vector_d pow2(const vector_d &v);
vector_c pow2(const vector_c &v);
matrix_d pow2(const matrix_d &A);
matrix_c pow2(const matrix_c &A);
// sqrt
vector_d sqrt(const vector_d &v);
vector_c sqrt(const vector_c &v);
matrix_d sqrt(const matrix_d &A);
matrix_c sqrt(const matrix_c &A);

#pragma endregion
}


#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H
