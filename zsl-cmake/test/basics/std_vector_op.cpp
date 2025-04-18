#include <gtest/gtest.h>
#include <basics/std_vector_op.h>

using namespace zsl;

TEST(std_vector_op, vadd)
{
	std::vector<double> a{1.0, 2.0, 3.0};
	std::vector<double> b{2.0, 3.0, 4.0};
	std::vector<double> r{3.0, 5.0, 7.0};
	double d = 1.0;
	std::vector<double> r2{2.0, 3.0, 4.0};

 	EXPECT_EQ(vadd(a, b), r);
	EXPECT_EQ(vadd(a, d), r2);
	EXPECT_EQ(vadd(d, a), r2);

	auto a1 = a;
	auto a2 = a;
	vadd_self(a1, b);
	a2 += b;
	EXPECT_EQ(a1, r);
	EXPECT_EQ(a2, r);

	auto a3 = a;
	auto a4 = a;
	vadd_self(a3, d);
	a4 += d;
	EXPECT_EQ(a3, r2);
	EXPECT_EQ(a4, r2);

}


TEST(std_vector_op, vsub)
{
	std::vector<double> a{1.0, 2.0, 3.0};
	std::vector<double> b{2.0, 3.0, 4.0};
	std::vector<double> r{-1.0, -1.0, -1.0};
	EXPECT_EQ(vsub(a, b), r);
	EXPECT_EQ(a - b, r);

	double d = 1.0;
	std::vector<double> r2{0.0, 1.0, 2.0};
	std::vector<double> r3{0.0, -1.0, -2.0};
	EXPECT_EQ(vsub(a, d), r2);
	EXPECT_EQ(a - d, r2);
	EXPECT_EQ(vsub(d, a), r3);
	EXPECT_EQ(d - a, r3);

	auto a1 = a;
	auto a2 = a;
	vsub_self(a1, b);
	a2 -= b;
	EXPECT_EQ(a1, r);
	EXPECT_EQ(a2, r);

	auto a3 = a;
	auto a4 = a;
	vsub_self(a3, d);
	a4 -= d;
	EXPECT_EQ(a3, r2);
	EXPECT_EQ(a3, r2);
}

TEST(std_vector_op, vmul)
{
	std::vector<double> a{1.0, 2.0, 3.0};
	std::vector<double> b{1.0, 2.0, 3.0};
	std::vector<double> r{1.0, 4.0, 9.0};
	EXPECT_EQ(vmul(a, b), r);
	EXPECT_EQ(a * b, r);
	auto a1 = a;
	auto a2 = a;
	vmul_self(a1, b);
	a2 *= b;
	EXPECT_EQ(a1, r);
	EXPECT_EQ(a2, r);

	double d = 3.0;
	std::vector<double> r2{3.0, 6.0, 9.0};
	EXPECT_EQ(vmul(a, d), r2);
	EXPECT_EQ(a * d, r2);
	EXPECT_EQ(vmul(d, a), r2);
	EXPECT_EQ(d * a, r2);
	auto a3 = a;
	auto a4 = a;
	vmul_self(a3, d);
	a4 *= d;
	EXPECT_EQ(a3, r2);
	EXPECT_EQ(a4, r2);
}

TEST(std_vector_op, vdiv)
{
	std::vector<double> a{1.0, 2.0, 3.0};
	std::vector<double> b{2.0, 4.0, 6.0};
	std::vector<double> r{0.5, 0.5, 0.5};
	EXPECT_EQ(vdiv(a, b), r);
	EXPECT_EQ(a / b, r);
	auto a1 = a;
	auto a2 = a;
	vdiv_self(a1, b);
	a2 /= b;
	EXPECT_EQ(a1, r);
	EXPECT_EQ(a2, r);


	double d = 2.0;
	std::vector<double> r2{0.5, 1.0, 1.5};
	EXPECT_EQ(vdiv(a, d), r2);
	EXPECT_EQ(a / d, r2);
	auto a3 = a;
	auto a4 = a;
	vdiv_self(a3, d);
	a4 /= d;
	EXPECT_EQ(a3, r2);
	EXPECT_EQ(a4, r2);

	double e = 6;
	std::vector<double> r3{6.0, 3.0, 2.0};
	EXPECT_EQ(vdiv(e, a), r3);
	EXPECT_EQ(e / a, r3);
}


TEST(std_vector_op, madd) {


}

