#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_TRIGONOMETRY_H
#define ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_TRIGONOMETRY_H

#include "basics/basics.h"
#include "elementary_math_temp.h"


#define DEG_TO_RAD(x) (x * zsl::pi / 180.0)
#define RAD_TO_DEG(x) (x * 180.0 / zsl::pi)

#define MUL_BY_PI(x) (x * zsl::pi)


namespace zsl {
#pragma region Trigonometry
// sin
STD_FUNC_PACK(sin)

inline double sind(double s) {
    return sin(DEG_TO_RAD(s));
}

inline complex_d sind(complex_d s) {
    return sin(DEG_TO_RAD(s));
}

UNARY_FUNC_PACK(sind, sind)

inline double sinpi(double s) {
    return sin(MUL_BY_PI(s));
}

inline complex_d sinpi(complex_d s) {
    return sin(MUL_BY_PI(s));
}

UNARY_FUNC_PACK(sinpi, sinpi)

STD_FUNC_PACK(asin)

STD_FUNC_PACK(sinh)

STD_FUNC_PACK(asinh)


// cos
STD_FUNC_PACK(cos);

inline double cosd(double s) {
    return cos(DEG_TO_RAD(s));
}

inline complex_d cosd(complex_d s) {
    return cos(DEG_TO_RAD(s));
}

UNARY_FUNC_PACK(cosd, cosd)

inline double cospi(double s) {
    return cos(MUL_BY_PI(s));
}

inline complex_d cospi(complex_d s) {
    return cos(MUL_BY_PI(s));
}

UNARY_FUNC_PACK(cospi, cospi)

STD_FUNC_PACK(acos)

STD_FUNC_PACK(cosh)

STD_FUNC_PACK(acosh)

// tan
STD_FUNC_PACK(tan)

inline double tand(double s) {
    return tan(DEG_TO_RAD(s));
}

inline complex_d tand(complex_d s) {
    return tan(DEG_TO_RAD(s));
}

UNARY_FUNC_PACK(tand, tand)

inline double tanpi(double s) {
    return tan(MUL_BY_PI(s));
}

inline complex_d tanpi(complex_d s) {
    return tan(MUL_BY_PI(s));
}

UNARY_FUNC_PACK(tanpi, tanpi)

STD_FUNC_PACK(atan)

STD_FUNC_PACK(tanh)

STD_FUNC_PACK(atanh)

// csc
inline double csc(double x) {
    return 1.0 / std::sin(x);
}

inline complex_d csc(complex_d x) {
    return 1.0 / std::sin(x);
}

UNARY_FUNC_PACK(csc, csc)

inline double cscd(double s) {
    return csc(DEG_TO_RAD(s));
}

inline complex_d cscd(complex_d s) {
    return csc(DEG_TO_RAD(s));
}

UNARY_FUNC_PACK(cscd, cscd)

inline double acsc(double s) {
    return asin(1.0 / s);
}

inline complex_d acsc(complex_d s) {
    return asin(1.0 / s);
}

UNARY_FUNC_PACK(acsc, acsc)

inline double acscd(double s) {
    return DEG_TO_RAD(asin(1.0 / s));
}

inline complex_d acscd(complex_d s) {
    return DEG_TO_RAD(asin(1.0 / s));
}

UNARY_FUNC_PACK(acscd, acscd)

inline double acsch(double s) {
    return asinh(1.0 / s);
}

inline complex_d acsch(complex_d s) {
    return asinh(1.0 / s);
}

UNARY_FUNC_PACK(acsch, acsch)

// sec
inline double sec(double x) {
    return 1.0 / std::cos(x);
}

inline complex_d sec(complex_d x) {
    return 1.0 / std::cos(x);
}

UNARY_FUNC_PACK(sec, sec)

inline double secd(double s) {
    return sec(DEG_TO_RAD(s));
}

inline complex_d secd(complex_d s) {
    return sec(DEG_TO_RAD(s));
}

UNARY_FUNC_PACK(secd, secd)

inline double asec(double s) {
    return acos(1.0 / s);
}

inline complex_d asec(complex_d s) {
    return acos(1.0 / s);
}

UNARY_FUNC_PACK(asec, asec)

inline double asecd(double s) {
    return DEG_TO_RAD(acos(1.0 / s));
}

inline complex_d asecd(complex_d s) {
    return DEG_TO_RAD(acos(1.0 / s));
}

UNARY_FUNC_PACK(asecd, asecd)

inline double asech(double s) {
    return acosh(1.0 / s);
}

inline complex_d asech(complex_d s) {
    return acosh(1.0 / s);
}

UNARY_FUNC_PACK(asech, asech)

// cot
inline double cot(double x) {
    return 1.0 / std::tan(x);
}

inline complex_d cot(complex_d x) {
    return 1.0 / std::tan(x);
}

UNARY_FUNC_PACK(cot, cot)

inline double cotd(double s) {
    return cot(DEG_TO_RAD(s));
}

inline complex_d cotd(complex_d s) {
    return cot(DEG_TO_RAD(s));
}

UNARY_FUNC_PACK(cotd, cotd)

inline double acot(double s) {
    return atan(1.0 / s);
}

inline complex_d acot(complex_d s) {
    return atan(1.0 / s);
}

UNARY_FUNC_PACK(acot, acot)

inline double acotd(double s) {
    return DEG_TO_RAD(atan(1.0 / s));
}

inline complex_d acotd(complex_d s) {
    return DEG_TO_RAD(atan(1.0 / s));
}

UNARY_FUNC_PACK(acotd, acotd)

inline double acoth(double s) {
    return atanh(1.0 / s);
}

inline complex_d acoth(complex_d s) {
    return atanh(1.0 / s);
}

UNARY_FUNC_PACK(acoth, acoth)

// conversions
inline double deg2rad(double x) {
    return DEG_TO_RAD(x);
}

inline complex_d deg2rad(complex_d x) {
    return DEG_TO_RAD(x);
}

UNARY_FUNC_PACK(deg2rad, deg2rad)

inline double rad2deg(double x) {
    return RAD_TO_DEG(x);
}

inline complex_d rad2deg(complex_d x) {
    return RAD_TO_DEG(x);
}

UNARY_FUNC_PACK(rad2deg, rad2deg)

#pragma endregion
}

#endif // ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_TRIGONOMETRY_H
