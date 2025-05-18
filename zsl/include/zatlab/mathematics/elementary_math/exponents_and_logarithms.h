#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_EXPONENTS_AND_LOGRAITHMS_H

#include "basics/basics.h"

namespace zsl {

#pragma region Exponents and Logarithms
// exp
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

#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_EXPONENTS_AND_LOGRAITHMS_H


