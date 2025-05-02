#include <gtest/gtest.h>
#include <zatlab/language_fundamentals/operators_and_elementary_operations/arithmetic_operations.h>


using namespace zsl;
using namespace std::literals::complex_literals;

TEST(arithmetic_operations, plus) {
	// vector + scalar
	{ 
		vector_d v{1, 2, 3};
		vector_c w{1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i};
		double d = 1;
		complex_d c = 1.0 + 2.0i;
		vector_d v_add_d{2, 3, 4};
		vector_c v_add_c{2.0 + 2i, 3.0 + 2i, 4.0 + 2i};
		vector_c w_add_d{2.0 + 1.0i, 3.0 + 2.0i, 4.0 + 3.0i};
		vector_c w_add_c{2.0 + 3.0i, 3.0 + 4.0i, 4.0 + 5.0i};
		EXPECT_EQ(plus(v, d), v_add_d);
		EXPECT_EQ(plus(d, v), v_add_d);
		EXPECT_EQ(plus(v, c), v_add_c);
		EXPECT_EQ(plus(c, v), v_add_c);
		EXPECT_EQ(plus(w, d), w_add_d);
		EXPECT_EQ(plus(d, w), w_add_d);
		EXPECT_EQ(plus(w, c), w_add_c);
		EXPECT_EQ(plus(c, w), w_add_c);
		EXPECT_EQ(v + d, v_add_d);
		EXPECT_EQ(d + v, v_add_d);
		EXPECT_EQ(v + c, v_add_c);
		EXPECT_EQ(c + v, v_add_c);
		EXPECT_EQ(w + d, w_add_d);
		EXPECT_EQ(d + w, w_add_d);
		EXPECT_EQ(w + c, w_add_c);
		EXPECT_EQ(c + w, w_add_c);

		auto v1{v};
		auto v2{v};
		plus_self(v1, d);
		v2 += d;
		EXPECT_EQ(v1, v_add_d);
		EXPECT_EQ(v2, v_add_d);
		auto w1{w};
		auto w2{w};
		plus_self(w1, c);
		w2 += c;
		EXPECT_EQ(w1, w_add_c);
		EXPECT_EQ(w2, w_add_c);
		auto w3{w};
		auto w4{w};
		plus_self(w3, d);
		w4 += d;
		EXPECT_EQ(w3, w_add_d);
		EXPECT_EQ(w4, w_add_d);

	}
	// vector + vector
	{
		vector_d v{1, 2, 3};
		vector_d a{1, 1, 1};
		vector_c w{1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i};
		vector_c b{1.0 + 1.0i, 1.0 + 1.0i, 1.0 + 1.0i};
		vector_d v_add_a{2, 3, 4};
		vector_c w_add_b{2.0 + 2.0i, 3.0 + 3.0i, 4.0 + 4.0i};
		vector_c v_add_w{2.0 + 1.0i, 4.0 + 2.0i, 6.0 + 3.0i};
		vector_c w_add_v{2.0 + 1.0i, 4.0 + 2.0i, 6.0 + 3.0i};

		EXPECT_EQ(plus(v, a), v_add_a);
		EXPECT_EQ(plus(w, b), w_add_b);
		EXPECT_EQ(plus(v, w), v_add_w);
		EXPECT_EQ(plus(w, v), w_add_v);
		
		auto v1{v};
		auto v2{v};
		auto w1{w};
		auto w2{w};
		auto w3{w};
		auto w4{w};
		plus_self(v1, a);
		plus_self(w1, b);
		plus_self(w2, v);
		v2 += a;
		w3 += b;
		w4 += v;
		EXPECT_EQ(v1, v_add_a);
		EXPECT_EQ(v2, v_add_a);
		EXPECT_EQ(w1, w_add_b);
		EXPECT_EQ(w2, w_add_v);
		EXPECT_EQ(w3, w_add_b);
		EXPECT_EQ(w4, w_add_v);
	}
	// matrix + scalar
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		double d = 1;
		complex_d c = 1.0 + 2.0i;
		matrix_d B{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		matrix_c C{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		matrix_c E{
			{3.0 + 4.0i, 4.0 + 4.0i, 5.0 + 4.0i},
			{6.0 + 4.0i, 7.0 + 4.0i, 8.0 + 4.0i},
			{9.0 + 4.0i, 10.0 + 4.0i, 11.0 + 4.0i}};
		EXPECT_EQ(plus(A, d), B);
		EXPECT_EQ(plus(d, A), B);
		EXPECT_EQ(plus(A, c), C);
		EXPECT_EQ(plus(c, A), C);
		EXPECT_EQ(plus(C, d), D);
		EXPECT_EQ(plus(d, C), D);
		EXPECT_EQ(plus(C, c), E);
		EXPECT_EQ(plus(c, C), E);
		EXPECT_EQ(A + d, B);
		EXPECT_EQ(d + A, B);
		EXPECT_EQ(A + c, C);
		EXPECT_EQ(c + A, C);
		EXPECT_EQ(C + d, D);
		EXPECT_EQ(d + C, D);
		EXPECT_EQ(C + c, E);
		EXPECT_EQ(c + C, E);

		auto A1{A};
		auto A2{A};
		plus_self(A1, d);
		A2 += d;
		EXPECT_EQ(A1, B);
		EXPECT_EQ(A2, B);
		auto C1{C};
		auto C2{C};
		plus_self(C1, d);
		C2 += d;
		EXPECT_EQ(C1, D);
		EXPECT_EQ(C2, D);
		auto C3{C};
		auto C4{C};
		plus_self(C3, c);
		C4 += c;
		EXPECT_EQ(C3, E);
		EXPECT_EQ(C4, E);
	}

	// matrix + vector
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector_d d = {1, 1, 1};
		vector_c c = {1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i};
		matrix_d B{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		matrix_c C{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		matrix_c E{
			{3.0 + 4.0i, 4.0 + 4.0i, 5.0 + 4.0i},
			{6.0 + 4.0i, 7.0 + 4.0i, 8.0 + 4.0i},
			{9.0 + 4.0i, 10.0 + 4.0i, 11.0 + 4.0i}};
		EXPECT_EQ(plus(A, d), B);
		EXPECT_EQ(plus(d, A), B);
		EXPECT_EQ(plus(A, c), C);
		EXPECT_EQ(plus(c, A), C);
		EXPECT_EQ(plus(C, d), D);
		EXPECT_EQ(plus(d, C), D);
		EXPECT_EQ(plus(C, c), E);
		EXPECT_EQ(plus(c, C), E);
		EXPECT_EQ(A + d, B);
		EXPECT_EQ(d + A, B);
		EXPECT_EQ(A + c, C);
		EXPECT_EQ(c + A, C);
		EXPECT_EQ(C + d, D);
		EXPECT_EQ(d + C, D);
		EXPECT_EQ(C + c, E);
		EXPECT_EQ(c + C, E);

		auto A1{A};
		auto A2{A};
		plus_self(A1, d);
		A2 += d;
		EXPECT_EQ(A1, B);
		EXPECT_EQ(A2, B);
		auto C1{C};
		auto C2{C};
		plus_self(C1, d);
		C2 += d;
		EXPECT_EQ(C1, D);
		EXPECT_EQ(C2, D);
		auto C3{C};
		auto C4{C};
		plus_self(C3, c);
		C4 += c;
		EXPECT_EQ(C3, E);
		EXPECT_EQ(C4, E);
	}
	// matrix + matrix
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		matrix_d d = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
		matrix_c c = {
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i}};
		matrix_d B{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		matrix_c C{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		matrix_c E{
			{3.0 + 4.0i, 4.0 + 4.0i, 5.0 + 4.0i},
			{6.0 + 4.0i, 7.0 + 4.0i, 8.0 + 4.0i},
			{9.0 + 4.0i, 10.0 + 4.0i, 11.0 + 4.0i}};
		EXPECT_EQ(plus(A, d), B);
		EXPECT_EQ(plus(d, A), B);
		EXPECT_EQ(plus(A, c), C);
		EXPECT_EQ(plus(c, A), C);
		EXPECT_EQ(plus(C, d), D);
		EXPECT_EQ(plus(d, C), D);
		EXPECT_EQ(plus(C, c), E);
		EXPECT_EQ(plus(c, C), E);
		EXPECT_EQ(A + d, B);
		EXPECT_EQ(d + A, B);
		EXPECT_EQ(A + c, C);
		EXPECT_EQ(c + A, C);
		EXPECT_EQ(C + d, D);
		EXPECT_EQ(d + C, D);
		EXPECT_EQ(C + c, E);
		EXPECT_EQ(c + C, E);

		auto A1{A};
		auto A2{A};
		plus_self(A1, d);
		A2 += d;
		EXPECT_EQ(A1, B);
		EXPECT_EQ(A2, B);
		auto C1{C};
		auto C2{C};
		plus_self(C1, d);
		C2 += d;
		EXPECT_EQ(C1, D);
		EXPECT_EQ(C2, D);
		auto C3{C};
		auto C4{C};
		plus_self(C3, c);
		C4 += c;
		EXPECT_EQ(C3, E);
		EXPECT_EQ(C4, E);

	}
}

TEST(arithmetic_operations, minus) {
	// vector - scalar
	{
		vector_d v{1, 2, 3};
		vector_c w{1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i};
		double d = -1;
		complex_d c = -1.0 - 2.0i;
		vector_d v_sub_d{2, 3, 4};
		vector_d d_sub_v{-2, -3, -4};
		vector_c v_sub_c{2.0 + 2i, 3.0 + 2i, 4.0 + 2i};
		vector_c c_sub_v{-2.0 - 2i, -3.0 - 2i, -4.0 - 2i};
		vector_c w_sub_d{2.0 + 1.0i, 3.0 + 2.0i, 4.0 + 3.0i};
		vector_c d_sub_w{-2.0 - 1.0i, -3.0 - 2.0i, -4.0 - 3.0i};
		vector_c w_sub_c{2.0 + 3.0i, 3.0 + 4.0i, 4.0 + 5.0i};
		vector_c c_sub_w{-2.0 - 3.0i, -3.0 - 4.0i, -4.0 - 5.0i};
		EXPECT_EQ(minus(v, d), v_sub_d);
		EXPECT_EQ(minus(d, v), d_sub_v);
		EXPECT_EQ(minus(v, c), v_sub_c);
		EXPECT_EQ(minus(c, v), c_sub_v);
		EXPECT_EQ(minus(w, d), w_sub_d);
		EXPECT_EQ(minus(d, w), d_sub_w);
		EXPECT_EQ(minus(w, c), w_sub_c);
		EXPECT_EQ(minus(c, w), c_sub_w);
		EXPECT_EQ(v - d, v_sub_d);
		EXPECT_EQ(d - v, d_sub_v);
		EXPECT_EQ(v - c, v_sub_c);
		EXPECT_EQ(c - v, c_sub_v);
		EXPECT_EQ(w - d, w_sub_d);
		EXPECT_EQ(d - w, d_sub_w);
		EXPECT_EQ(w - c, w_sub_c);
		EXPECT_EQ(c - w, c_sub_w);

		auto v1{v};
		auto v2{v};
		minus_self(v1, d);
		v2 -= d;
		EXPECT_EQ(v1, v_sub_d);
		EXPECT_EQ(v2, v_sub_d);
		auto w1{w};
		auto w2{w};
		minus_self(w1, c);
		w2 -= c;
		EXPECT_EQ(w1, w_sub_c);
		EXPECT_EQ(w2, w_sub_c);
		auto w3{w};
		auto w4{w};
		minus_self(w3, d);
		w4 -= d;
		EXPECT_EQ(w3, w_sub_d);
		EXPECT_EQ(w4, w_sub_d);
	}
	// vector + vector
	{
		vector_d v{1, 2, 3};
		vector_d a{-1, -1, -1};
		vector_c w{1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i};
		vector_c b{-1.0 - 1.0i, -1.0 - 1.0i, -1.0 - 1.0i};
		vector_d v_sub_a{2, 3, 4};
		vector_c w_sub_b{2.0 + 2.0i, 3.0 + 3.0i, 4.0 + 4.0i};
		vector_c v_sub_w{0.0 - 1.0i, 0.0 - 2.0i, 0.0 - 3.0i};
		vector_c w_sub_v{0.0 + 1.0i, 0.0 + 2.0i, 0.0 + 3.0i};

		EXPECT_EQ(minus(v, a), v_sub_a);
		EXPECT_EQ(minus(w, b), w_sub_b);
		EXPECT_EQ(minus(v, w), v_sub_w);
		EXPECT_EQ(minus(w, v), w_sub_v);

		auto v1{v};
		auto v2{v};
		auto w1{w};
		auto w2{w};
		auto w3{w};
		auto w4{w};
		minus_self(v1, a);
		minus_self(w1, b);
		minus_self(w2, v);
		v2 -= a;
		w3 -= b;
		w4 -= v;
		EXPECT_EQ(v1, v_sub_a);
		EXPECT_EQ(v2, v_sub_a);
		EXPECT_EQ(w1, w_sub_b);
		EXPECT_EQ(w2, w_sub_v);
		EXPECT_EQ(w3, w_sub_b);
		EXPECT_EQ(w4, w_sub_v);
	}
	// matrix - scalar
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		double d = -1;
		matrix_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		complex_d c = -1.0 - 2.0i;

		matrix_d A_sub_d{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		matrix_d d_sub_A{{-2, -3, -4}, {-5, -6, -7}, {-8, -9, -10}};
		matrix_c A_sub_c{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c c_sub_A{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		matrix_c B_sub_d{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c d_sub_B{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		matrix_c B_sub_c{
			{2.0 + 4.0i, 3.0 + 4.0i, 4.0 + 4.0i},
			{5.0 + 4.0i, 6.0 + 4.0i, 7.0 + 4.0i},
			{8.0 + 4.0i, 9.0 + 4.0i, 10.0 + 4.0i}};
		matrix_c c_sub_B{
			{-2.0 - 4.0i, -3.0 - 4.0i, -4.0  - 4.0i},
			{-5.0 - 4.0i, -6.0 - 4.0i, -7.0  - 4.0i},
			{-8.0 - 4.0i, -9.0 - 4.0i, -10.0 - 4.0i}};

		matrix_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		matrix_c E{
			{3.0 + 4.0i, 4.0 + 4.0i, 5.0 + 4.0i},
			{6.0 + 4.0i, 7.0 + 4.0i, 8.0 + 4.0i},
			{9.0 + 4.0i, 10.0 + 4.0i, 11.0 + 4.0i}};
		EXPECT_EQ(minus(A, d), A_sub_d);
		EXPECT_EQ(minus(d, A), d_sub_A);
		EXPECT_EQ(minus(A, c), A_sub_c);
		EXPECT_EQ(minus(c, A), c_sub_A);
		EXPECT_EQ(minus(B, d), B_sub_d);
		EXPECT_EQ(minus(d, B), d_sub_B);
		EXPECT_EQ(minus(B, c), B_sub_c);
		EXPECT_EQ(minus(c, B), c_sub_B);
		EXPECT_EQ(A - d, A_sub_d);
		EXPECT_EQ(d - A, d_sub_A);
		EXPECT_EQ(A - c, A_sub_c);
		EXPECT_EQ(c - A, c_sub_A);
		EXPECT_EQ(B - d, B_sub_d);
		EXPECT_EQ(d - B, d_sub_B);
		EXPECT_EQ(B - c, B_sub_c);
		EXPECT_EQ(c - B, c_sub_B);

		auto A1{A};
		auto A2{A};
		minus_self(A1, d);
		A2 -= d;
		EXPECT_EQ(A1, A_sub_d);
		EXPECT_EQ(A2, A_sub_d);
		auto B1{B};
		auto B2{B};
		minus_self(B1, d);
		B2 -= d;
		EXPECT_EQ(B1, B_sub_d);
		EXPECT_EQ(B2, B_sub_d);
		auto B3{B};
		auto B4{B};
		minus_self(B3, c);
		B4 -= c;
		EXPECT_EQ(B3, B_sub_c);
		EXPECT_EQ(B4, B_sub_c);
	}
	// matrix - vector
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector_d d = {-1, -1, -1 };
		matrix_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		vector_c c = {-1.0 - 2.0i, -1.0 - 2.0i, -1.0 - 2.0i};

		matrix_d A_sub_d{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		matrix_d d_sub_A{{-2, -3, -4}, {-5, -6, -7}, {-8, -9, -10}};
		matrix_c A_sub_c{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c c_sub_A{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		matrix_c B_sub_d{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c d_sub_B{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		matrix_c B_sub_c{
			{2.0 + 4.0i, 3.0 + 4.0i, 4.0 + 4.0i},
			{5.0 + 4.0i, 6.0 + 4.0i, 7.0 + 4.0i},
			{8.0 + 4.0i, 9.0 + 4.0i, 10.0 + 4.0i}};
		matrix_c c_sub_B{
			{-2.0 - 4.0i, -3.0 - 4.0i, -4.0 - 4.0i},
			{-5.0 - 4.0i, -6.0 - 4.0i, -7.0 - 4.0i},
			{-8.0 - 4.0i, -9.0 - 4.0i, -10.0 - 4.0i}};

		matrix_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		matrix_c E{
			{3.0 + 4.0i, 4.0 + 4.0i, 5.0 + 4.0i},
			{6.0 + 4.0i, 7.0 + 4.0i, 8.0 + 4.0i},
			{9.0 + 4.0i, 10.0 + 4.0i, 11.0 + 4.0i}};
		EXPECT_EQ(minus(A, d), A_sub_d);
		EXPECT_EQ(minus(d, A), d_sub_A);
		EXPECT_EQ(minus(A, c), A_sub_c);
		EXPECT_EQ(minus(c, A), c_sub_A);
		EXPECT_EQ(minus(B, d), B_sub_d);
		EXPECT_EQ(minus(d, B), d_sub_B);
		EXPECT_EQ(minus(B, c), B_sub_c);
		EXPECT_EQ(minus(c, B), c_sub_B);
		EXPECT_EQ(A - d, A_sub_d);
		EXPECT_EQ(d - A, d_sub_A);
		EXPECT_EQ(A - c, A_sub_c);
		EXPECT_EQ(c - A, c_sub_A);
		EXPECT_EQ(B - d, B_sub_d);
		EXPECT_EQ(d - B, d_sub_B);
		EXPECT_EQ(B - c, B_sub_c);
		EXPECT_EQ(c - B, c_sub_B);

		auto A1{A};
		auto A2{A};
		minus_self(A1, d);
		A2 -= d;
		EXPECT_EQ(A1, A_sub_d);
		EXPECT_EQ(A2, A_sub_d);
		auto B1{B};
		auto B2{B};
		minus_self(B1, d);
		B2 -= d;
		EXPECT_EQ(B1, B_sub_d);
		EXPECT_EQ(B2, B_sub_d);
		auto B3{B};
		auto B4{B};
		minus_self(B3, c);
		B4 -= c;
		EXPECT_EQ(B3, B_sub_c);
		EXPECT_EQ(B4, B_sub_c);
	}
	
	// matrix - vector
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		matrix_d d = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
		matrix_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		matrix_c c = {
			{-1.0 - 2.0i, -1.0 - 2.0i, -1.0 - 2.0i},
			{-1.0 - 2.0i, -1.0 - 2.0i, -1.0 - 2.0i},
			{-1.0 - 2.0i, -1.0 - 2.0i, -1.0 - 2.0i}};

		matrix_d A_sub_d{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		matrix_d d_sub_A{{-2, -3, -4}, {-5, -6, -7}, {-8, -9, -10}};
		matrix_c A_sub_c{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c c_sub_A{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		matrix_c B_sub_d{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		matrix_c d_sub_B{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		matrix_c B_sub_c{
			{2.0 + 4.0i, 3.0 + 4.0i, 4.0 + 4.0i},
			{5.0 + 4.0i, 6.0 + 4.0i, 7.0 + 4.0i},
			{8.0 + 4.0i, 9.0 + 4.0i, 10.0 + 4.0i}};
		matrix_c c_sub_B{
			{-2.0 - 4.0i, -3.0 - 4.0i, -4.0 - 4.0i},
			{-5.0 - 4.0i, -6.0 - 4.0i, -7.0 - 4.0i},
			{-8.0 - 4.0i, -9.0 - 4.0i, -10.0 - 4.0i}};

		matrix_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		matrix_c E{
			{3.0 + 4.0i, 4.0 + 4.0i, 5.0 + 4.0i},
			{6.0 + 4.0i, 7.0 + 4.0i, 8.0 + 4.0i},
			{9.0 + 4.0i, 10.0 + 4.0i, 11.0 + 4.0i}};
		EXPECT_EQ(minus(A, d), A_sub_d);
		EXPECT_EQ(minus(d, A), d_sub_A);
		EXPECT_EQ(minus(A, c), A_sub_c);
		EXPECT_EQ(minus(c, A), c_sub_A);
		EXPECT_EQ(minus(B, d), B_sub_d);
		EXPECT_EQ(minus(d, B), d_sub_B);
		EXPECT_EQ(minus(B, c), B_sub_c);
		EXPECT_EQ(minus(c, B), c_sub_B);
		EXPECT_EQ(A - d, A_sub_d);
		EXPECT_EQ(d - A, d_sub_A);
		EXPECT_EQ(A - c, A_sub_c);
		EXPECT_EQ(c - A, c_sub_A);
		EXPECT_EQ(B - d, B_sub_d);
		EXPECT_EQ(d - B, d_sub_B);
		EXPECT_EQ(B - c, B_sub_c);
		EXPECT_EQ(c - B, c_sub_B);

		auto A1{A};
		auto A2{A};
		minus_self(A1, d);
		A2 -= d;
		EXPECT_EQ(A1, A_sub_d);
		EXPECT_EQ(A2, A_sub_d);
		auto B1{B};
		auto B2{B};
		minus_self(B1, d);
		B2 -= d;
		EXPECT_EQ(B1, B_sub_d);
		EXPECT_EQ(B2, B_sub_d);
		auto B3{B};
		auto B4{B};
		minus_self(B3, c);
		B4 -= c;
		EXPECT_EQ(B3, B_sub_c);
		EXPECT_EQ(B4, B_sub_c);
	}
}

TEST(arithmetic_operations, times) {
	// vector * scalar
	{
		vector_d v{1, 2, 3};
		vector_c w{1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i};
		double d = 2;
		complex_d c = 1.0 + 2.0i;
		vector_d v_mul_d{2, 4, 6};
		vector_c v_mul_c{1.0 + 2i, 2.0 + 4i, 3.0 + 6.0i};
		vector_c w_mul_d{2.0 + 2.0i, 4.0 + 4.0i, 6.0 + 6.0i};
		vector_c w_mul_c{-1.0 + 3.0i, -2.0 + 6.0i, -3.0 + 9.0i};
		EXPECT_EQ(times(v, d), v_mul_d);
		EXPECT_EQ(times(d, v), v_mul_d);
		EXPECT_EQ(times(v, c), v_mul_c);
		EXPECT_EQ(times(c, v), v_mul_c);
		EXPECT_EQ(times(w, d), w_mul_d);
		EXPECT_EQ(times(d, w), w_mul_d);
		EXPECT_EQ(times(w, c), w_mul_c);
		EXPECT_EQ(times(c, w), w_mul_c);
		EXPECT_EQ(v * d, v_mul_d);
		EXPECT_EQ(d * v, v_mul_d);
		EXPECT_EQ(v * c, v_mul_c);
		EXPECT_EQ(c * v, v_mul_c);
		EXPECT_EQ(w * d, w_mul_d);
		EXPECT_EQ(d * w, w_mul_d);
		EXPECT_EQ(w * c, w_mul_c);
		EXPECT_EQ(c * w, w_mul_c);

		auto v1{v};
		auto v2{v};
		times_self(v1, d);
		v2 *= d;
		EXPECT_EQ(v1, v_mul_d);
		EXPECT_EQ(v2, v_mul_d);
		auto w1{w};
		auto w2{w};
		times_self(w1, c);
		w2 *= c;
		EXPECT_EQ(w1, w_mul_c);
		EXPECT_EQ(w2, w_mul_c);
		auto w3{w};
		auto w4{w};
		times_self(w3, d);
		w4 *= d;
		EXPECT_EQ(w3, w_mul_d);
		EXPECT_EQ(w4, w_mul_d);
	}
	
	// vector * vector
	{
		vector_d v{1, 2, 3};
		vector_d a{2, 2, 2};
		vector_c w{1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i};
		vector_c b{1.0 + 1.0i, 1.0 + 1.0i, 1.0 + 1.0i};
		vector_d v_mul_a{2, 4, 6};
		vector_c w_mul_b{0.0 + 2.0i, 0.0 + 4.0i, 0.0 + 6.0i};
		vector_c v_mul_w{1.0 + 1.0i, 4.0 + 4.0i, 9.0 + 9.0i};
		vector_c w_mul_v{1.0 + 1.0i, 4.0 + 4.0i, 9.0 + 9.0i};

		EXPECT_EQ(times(v, a), v_mul_a);
		EXPECT_EQ(times(w, b), w_mul_b);
		EXPECT_EQ(times(v, w), v_mul_w);
		EXPECT_EQ(times(w, v), w_mul_v);

		auto v1{v};
		auto v2{v};
		auto w1{w};
		auto w2{w};
		auto w3{w};
		auto w4{w};
		times_self(v1, a);
		times_self(w1, b);
		times_self(w2, v);
		v2 *= a;
		w3 *= b;
		w4 *= v;
		EXPECT_EQ(v1, v_mul_a);
		EXPECT_EQ(v2, v_mul_a);
		EXPECT_EQ(w1, w_mul_b);
		EXPECT_EQ(w2, w_mul_v);
		EXPECT_EQ(w3, w_mul_b);
		EXPECT_EQ(w4, w_mul_v);
	}
	
	// matrix * scalar
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		double d = 2;
		matrix_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		complex_d c = 1.0 + 2.0i;

		matrix_d A_mul_d{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		matrix_d d_mul_A{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		matrix_c A_mul_c{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		matrix_c c_mul_A{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		matrix_c B_mul_d{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		matrix_c d_mul_B{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		matrix_c B_mul_c{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		matrix_c c_mul_B{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		EXPECT_EQ(times(A, d), A_mul_d);
		EXPECT_EQ(times(d, A), d_mul_A);
		EXPECT_EQ(times(A, c), A_mul_c);
		EXPECT_EQ(times(c, A), c_mul_A);
		EXPECT_EQ(times(B, d), B_mul_d);
		EXPECT_EQ(times(d, B), d_mul_B);
		EXPECT_EQ(times(B, c), B_mul_c);
		EXPECT_EQ(times(c, B), c_mul_B);
		EXPECT_EQ(A * d, A_mul_d);
		EXPECT_EQ(d * A, d_mul_A);
		EXPECT_EQ(A * c, A_mul_c);
		EXPECT_EQ(c * A, c_mul_A);
		EXPECT_EQ(B * d, B_mul_d);
		EXPECT_EQ(d * B, d_mul_B);
		EXPECT_EQ(B * c, B_mul_c);
		EXPECT_EQ(c * B, c_mul_B);

		auto A1{A};
		auto A2{A};
		times_self(A1, d);
		A2 *= d;
		EXPECT_EQ(A1, A_mul_d);
		EXPECT_EQ(A2, A_mul_d);
		auto B1{B};
		auto B2{B};
		times_self(B1, d);
		B2 *= d;
		EXPECT_EQ(B1, B_mul_d);
		EXPECT_EQ(B2, B_mul_d);
		auto B3{B};
		auto B4{B};
		times_self(B3, c);
		B4 *= c;
		EXPECT_EQ(B3, B_mul_c);
		EXPECT_EQ(B4, B_mul_c);
	}
	
	// matrix * vector
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector_d d{2, 2, 2};
		matrix_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		vector_c c = {1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i};

		matrix_d A_mul_d{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		matrix_d d_mul_A{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		matrix_c A_mul_c{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		matrix_c c_mul_A{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		matrix_c B_mul_d{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		matrix_c d_mul_B{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		matrix_c B_mul_c{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		matrix_c c_mul_B{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		EXPECT_EQ(times(A, d), A_mul_d);
		EXPECT_EQ(times(d, A), d_mul_A);
		EXPECT_EQ(times(A, c), A_mul_c);
		EXPECT_EQ(times(c, A), c_mul_A);
		EXPECT_EQ(times(B, d), B_mul_d);
		EXPECT_EQ(times(d, B), d_mul_B);
		EXPECT_EQ(times(B, c), B_mul_c);
		EXPECT_EQ(times(c, B), c_mul_B);
		EXPECT_EQ(A * d, A_mul_d);
		EXPECT_EQ(d * A, d_mul_A);
		EXPECT_EQ(A * c, A_mul_c);
		EXPECT_EQ(c * A, c_mul_A);
		EXPECT_EQ(B * d, B_mul_d);
		EXPECT_EQ(d * B, d_mul_B);
		EXPECT_EQ(B * c, B_mul_c);
		EXPECT_EQ(c * B, c_mul_B);

		auto A1{A};
		auto A2{A};
		times_self(A1, d);
		A2 *= d;
		EXPECT_EQ(A1, A_mul_d);
		EXPECT_EQ(A2, A_mul_d);
		auto B1{B};
		auto B2{B};
		times_self(B1, d);
		B2 *= d;
		EXPECT_EQ(B1, B_mul_d);
		EXPECT_EQ(B2, B_mul_d);
		auto B3{B};
		auto B4{B};
		times_self(B3, c);
		B4 *= c;
		EXPECT_EQ(B3, B_mul_c);
		EXPECT_EQ(B4, B_mul_c);
	}
	
	// matrix * matrix
	{
		matrix_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		matrix_d d{{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
		matrix_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		matrix_c c = {
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i}};

		matrix_d A_mul_d{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		matrix_d d_mul_A{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		matrix_c A_mul_c{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		matrix_c c_mul_A{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		matrix_c B_mul_d{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		matrix_c d_mul_B{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		matrix_c B_mul_c{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		matrix_c c_mul_B{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		EXPECT_EQ(times(A, d), A_mul_d);
		EXPECT_EQ(times(d, A), d_mul_A);
		EXPECT_EQ(times(A, c), A_mul_c);
		EXPECT_EQ(times(c, A), c_mul_A);
		EXPECT_EQ(times(B, d), B_mul_d);
		EXPECT_EQ(times(d, B), d_mul_B);
		EXPECT_EQ(times(B, c), B_mul_c);
		EXPECT_EQ(times(c, B), c_mul_B);
		EXPECT_EQ(A *d, A_mul_d);
		EXPECT_EQ(d *A, d_mul_A);
		EXPECT_EQ(A *c, A_mul_c);
		EXPECT_EQ(c *A, c_mul_A);
		EXPECT_EQ(B *d, B_mul_d);
		EXPECT_EQ(d *B, d_mul_B);
		EXPECT_EQ(B *c, B_mul_c);
		EXPECT_EQ(c *B, c_mul_B);

		auto A1{A};
		auto A2{A};
		times_self(A1, d);
		A2 *= d;
		EXPECT_EQ(A1, A_mul_d);
		EXPECT_EQ(A2, A_mul_d);
		auto B1{B};
		auto B2{B};
		times_self(B1, d);
		B2 *= d;
		EXPECT_EQ(B1, B_mul_d);
		EXPECT_EQ(B2, B_mul_d);
		auto B3{B};
		auto B4{B};
		times_self(B3, c);
		B4 *= c;
		EXPECT_EQ(B3, B_mul_c);
		EXPECT_EQ(B4, B_mul_c);
	}
	
}
