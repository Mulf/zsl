#ifndef ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_CONSTANTS_AND_TEST_MATRICES_H
#define ZSL_ZATLAB_MATHEMATICS_ELEMENTARY_MATH_CONSTANTS_AND_TEST_MATRICES_H

#include "basics/basics.h"
#include <limits>

namespace zsl {

constexpr double eps() {
    return std::numeric_limits<double>::epsilon();
}

inline double eps(double x) {
    return std::nextafter(x, std::numeric_limits<double>::infinity()) - x;
}

}

#endif