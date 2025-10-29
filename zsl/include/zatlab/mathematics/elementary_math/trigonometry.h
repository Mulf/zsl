#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_TRIGONOMETRY_H
#define ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_TRIGONOMETRY_H

#include "basics/basics.h"


namespace zsl {
#pragma region Trigonometry
// sin
vector_d sin(const vector_d &v);
vector_c sin(const vector_c &v);
vector2_d sin(const vector2_d &v);
vector2_c sin(const vector2_c &A);
vector_d sind(const vector_d &v);
vector_c sind(const vector_c &v);
vector2_d sind(const vector2_d &A);
vector2_c sind(const vector2_c &A);
vector_d sinpi(const vector_d &v);
vector_c sinpi(const vector_c &v);
vector2_d sinpi(const vector2_d &A);
vector2_c sinpi(const vector2_c &A);
vector_d asin(const vector_d &v);
vector_c asin(const vector_c &v);
vector2_d asin(const vector2_d &A);
vector2_c asin(const vector2_c &A);
vector_d sinh(const vector_d &v);
vector_c sinh(const vector_c &v);
vector2_d sinh(const vector2_d &A);
vector2_c sinh(const vector2_c &A);
vector_d asinh(const vector_d &v);
vector_c asinh(const vector_c &v);
vector2_d asinh(const vector2_d &A);
vector2_c asinh(const vector2_c &A);

// cos
vector_d cos(const vector_d &v);
vector_c cos(const vector_c &v);
vector2_d cos(const vector2_d &v);
vector2_c cos(const vector2_c &A);
vector_d cosd(const vector_d &v);
vector_c cosd(const vector_c &v);
vector2_d cosd(const vector2_d &A);
vector2_c cosd(const vector2_c &A);
vector_d cospi(const vector_d &v);
vector_c cospi(const vector_c &v);
vector2_d cospi(const vector2_d &A);
vector2_c cospi(const vector2_c &A);
vector_d acos(const vector_d &v);
vector_c acos(const vector_c &v);
vector2_d acos(const vector2_d &A);
vector2_c acos(const vector2_c &A);
vector_d cosh(const vector_d &v);
vector_c cosh(const vector_c &v);
vector2_d cosh(const vector2_d &A);
vector2_c cosh(const vector2_c &A);
vector_d acosh(const vector_d &v);
vector_c acosh(const vector_c &v);
vector2_d acosh(const vector2_d &A);
vector2_c acosh(const vector2_c &A);

// tan
vector_d tan(const vector_d &v);
vector_c tan(const vector_c &v);
vector2_d tan(const vector2_d &v);
vector2_c tan(const vector2_c &A);
vector_d tand(const vector_d &v);
vector_c tand(const vector_c &v);
vector2_d tand(const vector2_d &A);
vector2_c tand(const vector2_c &A);
vector_d tanpi(const vector_d &v);
vector_c tanpi(const vector_c &v);
vector2_d tanpi(const vector2_d &A);
vector2_c tanpi(const vector2_c &A);
vector_d atan(const vector_d &v);
vector_c atan(const vector_c &v);
vector2_d atan(const vector2_d &A);
vector2_c atan(const vector2_c &A);
vector_d tanh(const vector_d &v);
vector_c tanh(const vector_c &v);
vector2_d tanh(const vector2_d &A);
vector2_c tanh(const vector2_c &A);
vector_d atanh(const vector_d &v);
vector_c atanh(const vector_c &v);
vector2_d atanh(const vector2_d &A);
vector2_c atanh(const vector2_c &A);

// csc
vector_d csc(const vector_d &v);
vector2_d csc(const vector2_d &v);
vector_d cscd(const vector_d &v);
vector2_d cscd(const vector2_d &A);
vector_d acsc(const vector_d &v);
vector2_d acsc(const vector2_d &A);
vector_d acscd(const vector_d &v);
vector2_d acscd(const vector2_d &A);
vector_d csch(const vector_d &v);
vector2_d csch(const vector2_d &A);
vector_d acsch(const vector_d &v);
vector2_d acsch(const vector2_d &A);

// sec
vector_d sec(const vector_d &v);
vector2_d sec(const vector2_d &v);
vector_d secd(const vector_d &v);
vector2_d secd(const vector2_d &A);
vector_d asec(const vector_d &v);
vector2_d asec(const vector2_d &A);
vector_d asecd(const vector_d &v);
vector2_d asecd(const vector2_d &A);
vector_d sech(const vector_d &v);
vector2_d sech(const vector2_d &A);
vector_d asech(const vector_d &v);
vector2_d asech(const vector2_d &A);

// cot
vector_d cot(const vector_d &v);
vector2_d cot(const vector2_d &v);
vector_d cotd(const vector_d &v);
vector2_d cotd(const vector2_d &A);
vector_d acot(const vector_d &v);
vector2_d acot(const vector2_d &A);
vector_d acotd(const vector_d &v);
vector2_d acotd(const vector2_d &A);
vector_d coth(const vector_d &v);
vector2_d coth(const vector2_d &A);
vector_d acoth(const vector_d &v);
vector2_d acoth(const vector2_d &A);

// conversions
double deg2rad(double x);
vector_d deg2rad(const vector_d &v);
vector2_d deg2rad(const vector2_d &A);
double rad2deg(double x);
vector_d rad2deg(const vector_d &v);
vector2_d rad2deg(const vector2_d &A);

#pragma endregion
}

#endif // ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_TRIGONOMETRY_H
