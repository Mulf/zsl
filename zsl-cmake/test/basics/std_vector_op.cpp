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
	matrix_d m1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	matrix_d m2 = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };
	vector_d v = { 1, 2, 3 };
	double d = 1;
	matrix_d r1 = { {2, 3, 4}, {6, 7, 8}, {10, 11, 12} };
	matrix_d r2 = { {2, 3, 4}, {6, 7, 8}, {10, 11, 12} };
	matrix_d r3 = { {2, 3, 4}, {5, 6, 7}, {8, 9, 10} };

	EXPECT_EQ(madd(m1, m2), r1);
	EXPECT_EQ(madd(m1, v), r2);
	EXPECT_EQ(madd(v, m1), r2);
	EXPECT_EQ(madd(m1, d), r3);
	EXPECT_EQ(madd(d, m1), r3);
	EXPECT_EQ(m1 + m2, r1);
	EXPECT_EQ(m1 + v, r2);
	EXPECT_EQ(v + m1, r2);
	EXPECT_EQ(m1 + d, r3);
	EXPECT_EQ(d + m1, r3);

	auto n1 = m1;
	auto n2 = m1;
	auto n3 = m1;
	n1 += m2;
	n2 += v;
	n3 += d;
	EXPECT_EQ(n1, r1);
	EXPECT_EQ(n2, r2);
	EXPECT_EQ(n3, r3);
}


TEST(std_vector_op, msub) {
	matrix_d m1 = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	matrix_d m2 = { {1, 1, 1}, {2, 2, 2}, {3, 3, 3} };
	vector_d v = { 1, 2, 3 };
	double d = 1;
	matrix_d r1 = { {0, 1, 2}, {2, 3, 4}, {4, 5, 6} };
	matrix_d r2 = { {0, -1, -2}, {-2, -3, -4}, {-4, -5, -6} };
	matrix_d r3 = { {0, 1, 2}, {2, 3, 4}, {4, 5, 6} };
	matrix_d r4 = { {0, -1, -2}, {-2, -3, -4}, {-4, -5, -6} };
	matrix_d r5 = { {0, 1, 2}, {3, 4, 5}, {6, 7, 8} };
	matrix_d r6 = { {0, -1, -2}, {-3, -4, -5}, {-6, -7, -8} };

	EXPECT_EQ(msub(m1, m2), r1);
	EXPECT_EQ(msub(m2, m1), r2);
	EXPECT_EQ(msub(m1, v), r3);
	EXPECT_EQ(msub(v, m1), r4);
	EXPECT_EQ(msub(m1, d), r5);
	EXPECT_EQ(msub(d, m1), r6);
	EXPECT_EQ(m1 - m2, r1);
	EXPECT_EQ(m2 - m1, r2);
	EXPECT_EQ(m1 - v, r3);
	EXPECT_EQ(v - m1, r4);
	EXPECT_EQ(m1 - d, r5);
	EXPECT_EQ(d - m1, r6);

	auto n1 = m1;
	auto n2 = m1;
	auto n3 = m1;
	n1 -= m2;
	n2 -= v;
	n3 -= d;
	EXPECT_EQ(n1, r1);
	EXPECT_EQ(n2, r3);
	EXPECT_EQ(n3, r5);
}
