#include <gtest/gtest.h>
#include <zsl/std_vector_op.h>

using namespace zsl;

TEST(test_vadd, normal)
{
	std::vector<double> a{1.0, 2.0, 3.0};
	std::vector<double> b{2.0, 3.0, 4.0};
	std::vector<double> r{3.0, 5.0, 7.0};
 	EXPECT_EQ(vadd(a, b), r);
}

