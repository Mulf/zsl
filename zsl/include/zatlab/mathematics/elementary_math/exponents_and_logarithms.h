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
template<Form F>
auto pow2(const F &v) {
    return unary_func(v, [](auto x) { return std::pow(2, x); });
}

template<Form F>
void pow2_self(F &v) {
    unary_func_self(v, [](auto x) { return std::pow(2, x); });
}

template<Form R, Form F>
void pow2_to(R &r, const F &v) {
    unary_func_to(r, v, [](auto x) { return std::pow(2, x); });
}

// sqrt
STD_FUNC_PACK(sqrt)

#pragma endregion
}

#endif // !ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_EXPONENTS_AND_LOGRAITHMS_H


