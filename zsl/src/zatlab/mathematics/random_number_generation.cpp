#include "zatlab/mathematics/random_number_generation.h"
//#include "linalg.h"
#include <random>

namespace zsl{
double rand() {
	std::default_random_engine gen;
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	return dist(gen);
}

vector_d rand_v(size_t n) {
	std::default_random_engine gen;
	std::uniform_real_distribution<double> dist(0.0, 1.0);
	vector_d v{n, vector_d::allocator_type{}};
	for(size_t i = 0; i < n; i++) {
		v[i] = dist(gen);
	}
	return v;
}

vector2_d rand(size_t n) {
	vector2_d A;
	for(size_t i = 0; i < n; i++) {
		A.push_back(rand_v(n));
	}
	return A;
}

vector2_d rand(size_t n, size_t m) {
	vector2_d A;
	for(size_t i = 0; i < n; i++) {
		A.push_back(rand_v(m));
	}
	return A;
}

}