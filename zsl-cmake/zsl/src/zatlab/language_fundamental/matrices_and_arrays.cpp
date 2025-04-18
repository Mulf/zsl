#include "zatlab/language_fundamental/matrices_and_arrays.h"

namespace zsl {

	vector_d vzeros(size_t n) {
		return vector_d(n, 0.0);
	}

	vector_d vones(size_t n) {
		return vector_d(n, 1.0);
	}

}