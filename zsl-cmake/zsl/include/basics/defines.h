#ifndef ZSL_BASICS_DEFINES_H
#define ZSL_BASICS_DEFINES_H

#include<vector>

namespace zsl {
	constexpr double pi = 3.141592653589;
	
	using vector_d = std::vector<double>;
	using matrix_d = std::vector<std::vector<double>>;
	inline bool is_matrix(const matrix_d& A) {
		for (size_t i = 1; i < A.size(); i++) {
			if (A[i].size() != A[0].size()) {
				return false;
			}
			return true;
		}
	}
	
	constexpr double ABS_EPS = 1e-4;
}

#endif // !ZSL_BASICS_DEFINES_H
