#include <zatlab/mathematics/elementary_math/constants_and_test_matrices.h>
#include <gtest/gtest.h>

using namespace zsl;
TEST(constants_and_test_matrices, constans) {
	auto eps_100 = 1.4211e-14;  // from matlab
	auto esp_100_cpp = eps(100);
	EXPECT_NEAR(eps(100), eps_100, EPS);

}