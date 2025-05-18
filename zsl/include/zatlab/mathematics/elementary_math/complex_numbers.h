#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_COMPLEX_NUMBERS_H
#define ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_COMPLEX_NUMBERS_H

#include "basics/basics.h"

namespace zsl {

#pragma region Complex Numbers
// abs
vector_d abs(const vector_d &v);
matrix_d abs(const matrix_d &X);
vector_d abs(const vector_c &v);
matrix_d abs(const matrix_c &X);
// angle
vector_d angle(const vector_c &v);
matrix_d angle(const matrix_c &X);
// conj
vector_c conj(const vector_c &v);
matrix_c conj(const matrix_c &Z);
// imag
vector_d imag(const vector_c &v);
matrix_d imag(const matrix_c &X);
// imag
vector_d real(const vector_c &v);
matrix_d real(const matrix_c &X);
// sign
// imag
vector_d sign(const vector_d &v);
matrix_d sign(const matrix_d &X);
vector_c sign(const vector_c &v);
matrix_c sign(const matrix_c &Z);

#pragma endregion
} // namespace zsl


#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_COMPLEX_NUMBERS_H
