#pragma once

#include "basics/basics.h"
#include "elementary_math_temp.h"

namespace zsl {

#pragma region Complex Numbers

// abs
STD_FUNC_PACK(abs)

// angle -> arg
STD_FUNC_PACK(arg)
UNARY_FUNC_PACK(angle, std::arg)

// conj
STD_FUNC_PACK(conj)

// imag
STD_FUNC_PACK(imag)

// real
STD_FUNC_PACK(real)


// sign

inline double sign(double x) {
    if (x > 0) {
        return 1.0;
    }
    else if (x < 0) {
        return -1.0;
    }
    return 0.0;
}

inline complex_d sign(const complex_d &z) {
    if (std::abs(z) == 0) {
        return 0;
    }
    return z / std::abs(z);
}


UNARY_FUNC_PACK(sign, sign)

#pragma endregion
} // namespace zsl

