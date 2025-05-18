#include "zatlab/mathematics/random_number_generation.h"
#include "linalg.h"
#include <random>

namespace zsl{
double rand() {
	return alglib::randomreal();
}

vector_d rand_v(size_t n) {
	vector_d v{n, vector_d::allocator_type{}};
	for(size_t i = 0; i < n; i++) {
		v[i] = rand();
	}
	return v;
}

matrix_d rand(size_t n) {
	matrix_d A;
	for(size_t i = 0; i < n; i++) {
		A.push_back(rand_v(n));
	}
	return A;
}

matrix_d rand(size_t n, size_t m) {
	matrix_d A;
	for(size_t i = 0; i < n; i++) {
		A.push_back(rand_v(m));
	}
	return A;
}

}