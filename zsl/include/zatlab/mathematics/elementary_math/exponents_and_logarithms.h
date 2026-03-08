#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_EXPONENTS_AND_LOGRAITHMS_H

#include "basics/basics.h"
#include "elementary_math_temp.h"

namespace zsl {

#pragma region Exponents and Logarithms
// exp
STD_FUNC_PACK(exp)

// log
STD_FUNC_PACK(log)

// log10
STD_FUNC_PACK(log10)

// log2
STD_FUNC_PACK(log2)

// pow2
inline double pow2(double x) {
    return std::pow(2.0, x);
}
UNARY_FUNC_PACK(pow2, pow2)

// sqrt
STD_FUNC_PACK(sqrt)

#pragma endregion
}

#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_EXPONENTS_AND_LOGRAITHMS_H


