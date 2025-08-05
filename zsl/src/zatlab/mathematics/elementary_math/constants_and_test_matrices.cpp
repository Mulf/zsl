#include "zatlab/mathematics/elementary_math/constants_and_test_matrices.h"
#include <limits>
#include <cmath>

namespace zsl {

constexpr double eps() {
	return std::numeric_limits<double>::epsilon();
}

double eps(double x) {
	return std::nextafter(x, std::numeric_limits<double>::infinity()) - x;
}



}