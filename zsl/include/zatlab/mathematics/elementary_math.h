#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H
#define ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H

#include "basics/basics.h"

namespace zsl {
#pragma region Trigonometry
// sin
vector_d sin(const vector_d &v);
matrix_d sin(const matrix_d &v);
vector_d sind(const vector_d &v);
matrix_d sind(const matrix_d &A);
vector_d sinpi(const vector_d &v);
matrix_d sinpi(const matrix_d &A);
vector_d asin(const vector_d &v);
matrix_d asin(const matrix_d &A);
vector_d sinh(const vector_d &v);
matrix_d sinh(const matrix_d &A);
vector_d asinh(const vector_d &v);
matrix_d asinh(const matrix_d &A);

// cos
vector_d cos(const vector_d &v);
matrix_d cos(const matrix_d &v);
vector_d cosd(const vector_d &v);
matrix_d cosd(const matrix_d &A);
vector_d cospi(const vector_d &v);
matrix_d cospi(const matrix_d &A);
vector_d acos(const vector_d &v);
matrix_d acos(const matrix_d &A);
vector_d cosh(const vector_d &v);
matrix_d cosh(const matrix_d &A);
vector_d acosh(const vector_d &v);
matrix_d acosh(const matrix_d &A);

// tan
vector_d tan(const vector_d &v);
matrix_d tan(const matrix_d &v);
vector_d tand(const vector_d &v);
matrix_d tand(const matrix_d &A);
vector_d tanpi(const vector_d &v);
matrix_d tanpi(const matrix_d &A);
vector_d atan(const vector_d &v);
matrix_d atan(const matrix_d &A);
vector_d tanh(const vector_d &v);
matrix_d tanh(const matrix_d &A);
vector_d atanh(const vector_d &v);
matrix_d atanh(const matrix_d &A);

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
}


#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H
