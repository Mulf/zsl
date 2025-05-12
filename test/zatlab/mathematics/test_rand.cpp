#include <zatlab/mathematics/random_number_generation.h>
#include <gtest/gtest.h>
#include <matplot/matplot.h>

using namespace zsl;
using namespace matplot;

TEST(random_nmumber, rand) {
	const size_t N = 1000;
	vector_d v(N);
	for(size_t i = 0; i < N; i++) {
		v[i] = zsl::rand();
	}

	plot(v);
	show();

}