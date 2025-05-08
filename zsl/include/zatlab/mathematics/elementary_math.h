#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H
#define ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H

#include "basics/basics.h"

namespace zsl {
#pragma region Trigonometry
// sine
vector_d sin(const vector_d &v);
matrix_d sin(const matrix_d &v);
vector_d sind(const vector_d &v);
matrix_d sind(const matrix_d &A);
vector_d sinpi(const vector_d &v);
matrix_d sinpi(const matrix_d &A);
vector_d asin(const vector_d &v);
matrix_d asin(const matrix_d &A);

// cos
vector_d cos(const vector_d &v);
matrix_d cos(const matrix_d &v);




#pragma endregion
}


#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_H
