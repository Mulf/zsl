#include <gtest/gtest.h>
#include <zatlab/language_fundamental/matrices_and_arrays.h>

using namespace zsl;

TEST(matrices_and_arrays, create_and_combine_arrays) {
	auto v = vzeros(3);
	vector_d r{ 0.0, 0.0, 0.0 };
	EXPECT_EQ(v, r);

	auto v1 = vones(4);
	vector_d r1{ 1.0, 1.0, 1.0, 1.0 };
	EXPECT_EQ(v1, r1);
	

}

