#pragma once

#include "basics/basics.h"
#include "elementary_math_temp.h"

namespace zsl {

#pragma region Complex Numbers

// abs
STD_FUNC_PACK(abs)

// angle -> arg
STD_FUNC_PACK(arg)
STD_FUNC_PACK_RENAME(angle, arg)

// conj
STD_FUNC_PACK(conj)

// imag
STD_FUNC_PACK(imag)

// real
STD_FUNC_PACK(real)


// sign
vector_d sign(const vector_d &v);
vector2_d sign(const vector2_d &X);
vector_c sign(const vector_c &v);
vector2_c sign(const vector2_c &Z);

#pragma endregion
} // namespace zsl

