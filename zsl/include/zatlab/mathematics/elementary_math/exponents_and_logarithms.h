#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_EXPONENTS_AND_LOGRAITHMS_H

#include "basics/basics.h"

namespace zsl {

#pragma region Exponents and Logarithms
// exp
vector_d exp(const vector_d &v);
vector_c exp(const vector_c &v);
vector2_d exp(const vector2_d &A);
vector2_c exp(const vector2_c &A);
// log
vector_d log(const vector_d &v);
vector_c log(const vector_c &v);
vector2_d log(const vector2_d &A);
vector2_c log(const vector2_c &A);
// log10
vector_d log10(const vector_d &v);
vector_c log10(const vector_c &v);
vector2_d log10(const vector2_d &A);
vector2_c log10(const vector2_c &A);
// log2
vector_d log2(const vector_d &v);
vector_c log2(const vector_c &v);
vector2_d log2(const vector2_d &A);
vector2_c log2(const vector2_c &A);
// pow2
double pow2(double x);
complex_d pow2(const complex_d &z);
vector_d pow2(const vector_d &v);
vector_c pow2(const vector_c &v);
vector2_d pow2(const vector2_d &A);
vector2_c pow2(const vector2_c &A);
// sqrt
vector_d sqrt(const vector_d &v);
vector_c sqrt(const vector_c &v);
vector2_d sqrt(const vector2_d &A);
vector2_c sqrt(const vector2_c &A);

#pragma endregion
}

#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_EXPONENTS_AND_LOGRAITHMS_H


