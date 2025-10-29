#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_COMPLEX_NUMBERS_H
#define ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_COMPLEX_NUMBERS_H

#include "basics/basics.h"

namespace zsl {

#pragma region Complex Numbers
// abs
vector_d abs(const vector_d &v);
vector2_d abs(const vector2_d &X);
vector_d abs(const vector_c &v);
vector2_d abs(const vector2_c &X);
// angle
vector_d angle(const vector_c &v);
vector2_d angle(const vector2_c &X);
// conj
vector_c conj(const vector_c &v);
vector2_c conj(const vector2_c &Z);
// imag
vector_d imag(const vector_c &v);
vector2_d imag(const vector2_c &X);
// imag
vector_d real(const vector_c &v);
vector2_d real(const vector2_c &X);
// sign
// imag
vector_d sign(const vector_d &v);
vector2_d sign(const vector2_d &X);
vector_c sign(const vector_c &v);
vector2_c sign(const vector2_c &Z);

#pragma endregion
} // namespace zsl


#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_COMPLEX_NUMBERS_H
