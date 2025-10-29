#include <gtest/gtest.h>
#include <zatlab/language_fundamentals/operators_and_elementary_operations/arithmetic_operations.h>


using namespace zsl;
using namespace std::literals::complex_literals;

constexpr double EPS = 1e-4;

static bool expect_near(const vector_d &v, const vector_d &w){
	for(size_t i = 0; i < v.size(); i++){
		EXPECT_NEAR(v[i], w[i], EPS);
	}
	return true;
}

static bool expect_near(const vector_c &v, const vector_c &w){
	for(size_t i = 0; i < v.size(); i++){
		EXPECT_NEAR(v[i].real(), w[i].real(), EPS);
		EXPECT_NEAR(v[i].imag(), w[i].imag(), EPS);
	}
	return true;
}

static bool expect_near(const vector2_d &A, const vector2_d &B){
	for(size_t i = 0; i < A.size(); i++){
		expect_near(A[i], B[i]);
	}
	return true;
}

static bool expect_near(const vector2_c &A, const vector2_c &B){
	for(size_t i = 0; i < A.size(); i++){
		expect_near(A[i], B[i]);
	}
	return true;
}



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
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		double d = 1;
		complex_d c = 1.0 + 2.0i;
		vector2_d B{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		vector2_c C{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		vector2_c E{
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
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector_d d = {1, 1, 1};
		vector_c c = {1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i};
		vector2_d B{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		vector2_c C{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		vector2_c E{
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
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector2_d d = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
		vector2_c c = {
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i}};
		vector2_d B{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		vector2_c C{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		vector2_c E{
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
	// vector - vector
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
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		double d = -1;
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		complex_d c = -1.0 - 2.0i;

		vector2_d A_sub_d{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		vector2_d d_sub_A{{-2, -3, -4}, {-5, -6, -7}, {-8, -9, -10}};
		vector2_c A_sub_c{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c c_sub_A{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		vector2_c B_sub_d{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c d_sub_B{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		vector2_c B_sub_c{
			{2.0 + 4.0i, 3.0 + 4.0i, 4.0 + 4.0i},
			{5.0 + 4.0i, 6.0 + 4.0i, 7.0 + 4.0i},
			{8.0 + 4.0i, 9.0 + 4.0i, 10.0 + 4.0i}};
		vector2_c c_sub_B{
			{-2.0 - 4.0i, -3.0 - 4.0i, -4.0  - 4.0i},
			{-5.0 - 4.0i, -6.0 - 4.0i, -7.0  - 4.0i},
			{-8.0 - 4.0i, -9.0 - 4.0i, -10.0 - 4.0i}};

		vector2_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		vector2_c E{
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
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector_d d = {-1, -1, -1 };
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		vector_c c = {-1.0 - 2.0i, -1.0 - 2.0i, -1.0 - 2.0i};

		vector2_d A_sub_d{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		vector2_d d_sub_A{{-2, -3, -4}, {-5, -6, -7}, {-8, -9, -10}};
		vector2_c A_sub_c{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c c_sub_A{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		vector2_c B_sub_d{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c d_sub_B{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		vector2_c B_sub_c{
			{2.0 + 4.0i, 3.0 + 4.0i, 4.0 + 4.0i},
			{5.0 + 4.0i, 6.0 + 4.0i, 7.0 + 4.0i},
			{8.0 + 4.0i, 9.0 + 4.0i, 10.0 + 4.0i}};
		vector2_c c_sub_B{
			{-2.0 - 4.0i, -3.0 - 4.0i, -4.0 - 4.0i},
			{-5.0 - 4.0i, -6.0 - 4.0i, -7.0 - 4.0i},
			{-8.0 - 4.0i, -9.0 - 4.0i, -10.0 - 4.0i}};

		vector2_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		vector2_c E{
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
	// matrix - matrix
	{
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector2_d d = {{-1, -1, -1}, {-1, -1, -1}, {-1, -1, -1}};
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		vector2_c c = {
			{-1.0 - 2.0i, -1.0 - 2.0i, -1.0 - 2.0i},
			{-1.0 - 2.0i, -1.0 - 2.0i, -1.0 - 2.0i},
			{-1.0 - 2.0i, -1.0 - 2.0i, -1.0 - 2.0i}};

		vector2_d A_sub_d{{2, 3, 4}, {5, 6, 7}, {8, 9, 10}};
		vector2_d d_sub_A{{-2, -3, -4}, {-5, -6, -7}, {-8, -9, -10}};
		vector2_c A_sub_c{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c c_sub_A{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		vector2_c B_sub_d{
			{2.0 + 2.0i, 3.0 + 2.0i, 4.0 + 2.0i},
			{5.0 + 2.0i, 6.0 + 2.0i, 7.0 + 2.0i},
			{8.0 + 2.0i, 9.0 + 2.0i, 10.0 + 2.0i}};
		vector2_c d_sub_B{
			{-2.0 - 2.0i, -3.0 - 2.0i, -4.0 - 2.0i},
			{-5.0 - 2.0i, -6.0 - 2.0i, -7.0 - 2.0i},
			{-8.0 - 2.0i, -9.0 - 2.0i, -10.0 - 2.0i}};
		vector2_c B_sub_c{
			{2.0 + 4.0i, 3.0 + 4.0i, 4.0 + 4.0i},
			{5.0 + 4.0i, 6.0 + 4.0i, 7.0 + 4.0i},
			{8.0 + 4.0i, 9.0 + 4.0i, 10.0 + 4.0i}};
		vector2_c c_sub_B{
			{-2.0 - 4.0i, -3.0 - 4.0i, -4.0 - 4.0i},
			{-5.0 - 4.0i, -6.0 - 4.0i, -7.0 - 4.0i},
			{-8.0 - 4.0i, -9.0 - 4.0i, -10.0 - 4.0i}};

		vector2_c D{
			{3.0 + 2.0i, 4.0 + 2.0i, 5.0 + 2.0i},
			{6.0 + 2.0i, 7.0 + 2.0i, 8.0 + 2.0i},
			{9.0 + 2.0i, 10.0 + 2.0i, 11.0 + 2.0i}};
		vector2_c E{
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
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		double d = 2;
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		complex_d c = 1.0 + 2.0i;

		vector2_d A_mul_d{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		vector2_d d_mul_A{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		vector2_c A_mul_c{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		vector2_c c_mul_A{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		vector2_c B_mul_d{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		vector2_c d_mul_B{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		vector2_c B_mul_c{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		vector2_c c_mul_B{
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
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector_d d{2, 2, 2};
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		vector_c c = {1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i};

		vector2_d A_mul_d{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		vector2_d d_mul_A{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		vector2_c A_mul_c{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		vector2_c c_mul_A{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		vector2_c B_mul_d{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		vector2_c d_mul_B{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		vector2_c B_mul_c{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		vector2_c c_mul_B{
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
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector2_d d{{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		vector2_c c = {
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i}};

		vector2_d A_mul_d{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		vector2_d d_mul_A{{2, 4, 6}, {8, 10, 12}, {14, 16, 18}};
		vector2_c A_mul_c{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		vector2_c c_mul_A{
			{1.0 + 2.0i, 2.0 + 4.0i, 3.0 + 6.0i},
			{4.0 + 8.0i, 5.0 + 10.0i, 6.0 + 12.0i},
			{7.0 + 14.0i, 8.0 + 16.0i, 9.0 + 18.0i}};
		vector2_c B_mul_d{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		vector2_c d_mul_B{
			{2.0 + 4.0i, 4.0 + 4.0i, 6.0 + 4.0i},
			{8.0 + 4.0i, 10.0 + 4.0i, 12.0 + 4.0i},
			{14.0 + 4.0i, 16.0 + 4.0i, 18.0 + 4.0i}};
		vector2_c B_mul_c{
			{-3.0 + 4.0i, -2.0 + 6.0i, -1.0 + 8.0i},
			{0.0 + 10.0i, 1.0 + 12.0i, 2.0 + 14.0i},
			{3.0 + 16.0i, 4.0 + 18.0i, 5.0 + 20.0i}};
		vector2_c c_mul_B{
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

TEST(arithmetic_operations, rdivide) {
	// vector / scalar
	{
		vector_d v{1, 2, 3};
		vector_c w{1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i};
		double d = 2;
		complex_d c = 1.0 + 2.0i;
		vector_d v_div_d = {0.5, 1, 1.5};
		vector_d d_div_v = {2, 1, 0.66667};
		vector_c v_div_c = {0.2 - 0.4i, 0.4 - 0.8i, 0.6 - 1.2i};
		vector_c c_div_v = {1.0 + 2.0i, 0.5 + 1.0i, 0.33333 + 0.66667i};
		vector_c w_div_d = {0.5 + 0.5i, 1.0 + 1.0i, 1.5 + 1.5i};
		vector_c d_div_w = {1.0 - 1.0i, 0.5 - 0.5i, 0.33333 - 0.33333i};
		vector_c w_div_c = {0.6 - 0.2i, 1.2 - 0.4i, 1.8 - 0.6i};
		vector_c c_div_w = {1.5 + 0.5i, 0.75 + 0.25i, 0.5 + 0.16667i};
		expect_near(rdivide(v, d), v_div_d);
		expect_near(rdivide(d, v), d_div_v);
		expect_near(rdivide(v, c), v_div_c);
		expect_near(rdivide(c, v), c_div_v);
		expect_near(rdivide(w, d), w_div_d);
		expect_near(rdivide(d, w), d_div_w);
		expect_near(rdivide(w, c), w_div_c);
		expect_near(rdivide(c, w), c_div_w);
		expect_near(v / d, v_div_d);
		expect_near(d / v, d_div_v);
		expect_near(v / c, v_div_c);
		expect_near(c / v, c_div_v);
		expect_near(w / d, w_div_d);
		expect_near(d / w, d_div_w);
		expect_near(w / c, w_div_c);
		expect_near(c / w, c_div_w);

		auto v1{v};
		auto v2{v};
		rdivide_self(v1, d);
		v2 /= d;
		expect_near(v1, v_div_d);
		expect_near(v2, v_div_d);
		auto w1{w};
		auto w2{w};
		rdivide_self(w1, c);
		w2 /= c;
		expect_near(w1, w_div_c);
		expect_near(w2, w_div_c);
		auto w3{w};
		auto w4{w};
		rdivide_self(w3, d);
		w4 /= d;
		expect_near(w3, w_div_d);
		expect_near(w4, w_div_d);
	}
	// vector / vector
	{
		vector_d v{1, 2, 3};
		vector_d a = {2, 2, 2};
		vector_c w{1.0 + 1.0i, 2.0 + 2.0i, 3.0 + 3.0i};
		vector_c b = {1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i};
		vector_d v_div_a{0.5, 1, 1.5};
		vector_c w_div_b{0.6 - 0.2i, 1.2 - 0.4i, 1.8 - 0.6i};
		vector_c v_div_w{0.5 - 0.5i, 0.5 - 0.5i, 0.5 - 0.5i};
		vector_c w_div_v{1.0 + 1.0i, 1.0 + 1.0i, 1.0 + 1.0i};

		EXPECT_EQ(rdivide(v, a), v_div_a);
		EXPECT_EQ(rdivide(w, b), w_div_b);
		EXPECT_EQ(rdivide(v, w), v_div_w);
		EXPECT_EQ(rdivide(w, v), w_div_v);

		auto v1{v};
		auto v2{v};
		auto w1{w};
		auto w2{w};
		auto w3{w};
		auto w4{w};
		rdivide_self(v1, a);
		rdivide_self(w1, b);
		rdivide_self(w2, v);
		v2 /= a;
		w3 /= b;
		w4 /= v;
		EXPECT_EQ(v1, v_div_a);
		EXPECT_EQ(v2, v_div_a);
		EXPECT_EQ(w1, w_div_b);
		EXPECT_EQ(w2, w_div_v);
		EXPECT_EQ(w3, w_div_b);
		EXPECT_EQ(w4, w_div_v);
	}
	// matrix / scalar
	{
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		double d = 2;
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		complex_d c = 1.0 + 2.0i;

		vector2_d A_div_d{{0.5, 1.0, 1.5},{2.0, 2.5, 3.0},{3.5, 4.0, 4.5}};
		vector2_d d_div_A{{2.0, 1.0, 0.66667},{0.5, 0.4, 0.33333},{0.28571, 0.25, 0.22222}};
		vector2_c A_div_c{
			{0.2 - 0.4i, 0.4 - 0.8i, 0.6 - 1.2i},
			{0.8 - 1.6i, 1.0 - 2.0i, 1.2 - 2.4i},
			{1.4 - 2.8i, 1.6 - 3.2i, 1.8 - 3.6i}};
		vector2_c c_div_A{
			{1.0 + 2.0i, 0.5 + 1i, 0.33333 + 0.66667i},
			{0.25 + 0.5i, 0.2 + 0.4i, 0.16667 + 0.33333i},
			{0.14286 + 0.28571i, 0.125 + 0.25i, 0.11111 + 0.22222i}};
		vector2_c B_div_d{
			{0.5 + 1.0i, 1.0 + 1.0i, 1.5 + 1i},
			{2.0 + 1.0i, 2.5 + 1i, 3.0 + 1.0i},
			{3.5 + 1.0i, 4.0 + 1.0i, 4.5 + 1.0i}};
		vector2_c d_div_B{
			{0.4 - 0.8i, 0.5 - 0.5i, 0.46154 - 0.30769i},
			{0.4 - 0.2i, 0.34483 - 0.13793i, 0.3 - 0.1i},
			{0.26415 - 0.075472i, 0.23529 - 0.058824i, 0.21176 - 0.047059i}};
		vector2_c B_div_c{
			{1.0 + 0.0i, 1.2 - 0.4i, 1.4 - 0.8i},
			{1.6 - 1.2i, 1.8 - 1.6i, 2.0 - 2.0i},
			{2.2 - 2.4i, 2.4 - 2.8i, 2.6 - 3.2i}};
		vector2_c c_div_B{
			{1.0 + 0.0i, 0.75 + 0.25i, 0.53846 + 0.30769i},
			{0.4 + 0.3i, 0.31034 + 0.27586i, 0.25 + 0.25i},
			{0.20755 + 0.22642i, 0.17647 + 0.20588i, 0.15294 + 0.18824i}};
		expect_near(rdivide(A, d), A_div_d);
		expect_near(rdivide(d, A), d_div_A);
		expect_near(rdivide(A, c), A_div_c);
		expect_near(rdivide(c, A), c_div_A);
		expect_near(rdivide(B, d), B_div_d);
		expect_near(rdivide(d, B), d_div_B);
		expect_near(rdivide(B, c), B_div_c);
		expect_near(rdivide(c, B), c_div_B);
		expect_near(A / d, A_div_d);
		expect_near(d / A, d_div_A);
		expect_near(A / c, A_div_c);
		expect_near(c / A, c_div_A);
		expect_near(B / d, B_div_d);
		expect_near(d / B, d_div_B);
		expect_near(B / c, B_div_c);
		expect_near(c / B, c_div_B);

		auto A1{A};
		auto A2{A};
		rdivide_self(A1, d);
		A2 /= d;
		expect_near(A1, A_div_d);
		expect_near(A2, A_div_d);
		auto B1{B};
		auto B2{B};
		rdivide_self(B1, d);
		B2 /= d;
		expect_near(B1, B_div_d);
		expect_near(B2, B_div_d);
		auto B3{B};
		auto B4{B};
		rdivide_self(B3, c);
		B4 /= c;
		expect_near(B3, B_div_c);
		expect_near(B4, B_div_c);
	}
	// matrix / vector
	{
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector_d d = {2, 2, 2};
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		vector_c c = {1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i};

		vector2_d A_div_d{{0.5, 1.0, 1.5}, {2.0, 2.5, 3.0}, {3.5, 4.0, 4.5}};
		vector2_d d_div_A{{2.0, 1.0, 0.66667}, {0.5, 0.4, 0.33333}, {0.28571, 0.25, 0.22222}};
		vector2_c A_div_c{
			{0.2 - 0.4i, 0.4 - 0.8i, 0.6 - 1.2i},
			{0.8 - 1.6i, 1.0 - 2.0i, 1.2 - 2.4i},
			{1.4 - 2.8i, 1.6 - 3.2i, 1.8 - 3.6i}};
		vector2_c c_div_A{
			{1.0 + 2.0i, 0.5 + 1i, 0.33333 + 0.66667i},
			{0.25 + 0.5i, 0.2 + 0.4i, 0.16667 + 0.33333i},
			{0.14286 + 0.28571i, 0.125 + 0.25i, 0.11111 + 0.22222i}};
		vector2_c B_div_d{
			{0.5 + 1.0i, 1.0 + 1.0i, 1.5 + 1i},
			{2.0 + 1.0i, 2.5 + 1i, 3.0 + 1.0i},
			{3.5 + 1.0i, 4.0 + 1.0i, 4.5 + 1.0i}};
		vector2_c d_div_B{
			{0.4 - 0.8i, 0.5 - 0.5i, 0.46154 - 0.30769i},
			{0.4 - 0.2i, 0.34483 - 0.13793i, 0.3 - 0.1i},
			{0.26415 - 0.075472i, 0.23529 - 0.058824i, 0.21176 - 0.047059i}};
		vector2_c B_div_c{
			{1.0 + 0.0i, 1.2 - 0.4i, 1.4 - 0.8i},
			{1.6 - 1.2i, 1.8 - 1.6i, 2.0 - 2.0i},
			{2.2 - 2.4i, 2.4 - 2.8i, 2.6 - 3.2i}};
		vector2_c c_div_B{
			{1.0 + 0.0i, 0.75 + 0.25i, 0.53846 + 0.30769i},
			{0.4 + 0.3i, 0.31034 + 0.27586i, 0.25 + 0.25i},
			{0.20755 + 0.22642i, 0.17647 + 0.20588i, 0.15294 + 0.18824i}};
		expect_near(rdivide(A, d), A_div_d);
		expect_near(rdivide(d, A), d_div_A);
		expect_near(rdivide(A, c), A_div_c);
		expect_near(rdivide(c, A), c_div_A);
		expect_near(rdivide(B, d), B_div_d);
		expect_near(rdivide(d, B), d_div_B);
		expect_near(rdivide(B, c), B_div_c);
		expect_near(rdivide(c, B), c_div_B);
		expect_near(A / d, A_div_d);
		expect_near(d / A, d_div_A);
		expect_near(A / c, A_div_c);
		expect_near(c / A, c_div_A);
		expect_near(B / d, B_div_d);
		expect_near(d / B, d_div_B);
		expect_near(B / c, B_div_c);
		expect_near(c / B, c_div_B);

		auto A1{A};
		auto A2{A};
		rdivide_self(A1, d);
		A2 /= d;
		expect_near(A1, A_div_d);
		expect_near(A2, A_div_d);
		auto B1{B};
		auto B2{B};
		rdivide_self(B1, d);
		B2 /= d;
		expect_near(B1, B_div_d);
		expect_near(B2, B_div_d);
		auto B3{B};
		auto B4{B};
		rdivide_self(B3, c);
		B4 /= c;
		expect_near(B3, B_div_c);
		expect_near(B4, B_div_c);
	}
	// matrix / matrix
	{
		vector2_d A{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
		vector2_d d = {{2, 2, 2}, {2, 2, 2}, {2, 2, 2}};
		vector2_c B{
			{1.0 + 2.0i, 2.0 + 2.0i, 3.0 + 2.0i},
			{4.0 + 2.0i, 5.0 + 2.0i, 6.0 + 2.0i},
			{7.0 + 2.0i, 8.0 + 2.0i, 9.0 + 2.0i}};
		vector2_c c = {
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i},
			{1.0 + 2.0i, 1.0 + 2.0i, 1.0 + 2.0i}};

		vector2_d A_div_d{{0.5, 1.0, 1.5}, {2.0, 2.5, 3.0}, {3.5, 4.0, 4.5}};
		vector2_d d_div_A{{2.0, 1.0, 0.66667}, {0.5, 0.4, 0.33333}, {0.28571, 0.25, 0.22222}};
		vector2_c A_div_c{
			{0.2 - 0.4i, 0.4 - 0.8i, 0.6 - 1.2i},
			{0.8 - 1.6i, 1.0 - 2.0i, 1.2 - 2.4i},
			{1.4 - 2.8i, 1.6 - 3.2i, 1.8 - 3.6i}};
		vector2_c c_div_A{
			{1.0 + 2.0i, 0.5 + 1i, 0.33333 + 0.66667i},
			{0.25 + 0.5i, 0.2 + 0.4i, 0.16667 + 0.33333i},
			{0.14286 + 0.28571i, 0.125 + 0.25i, 0.11111 + 0.22222i}};
		vector2_c B_div_d{
			{0.5 + 1.0i, 1.0 + 1.0i, 1.5 + 1i},
			{2.0 + 1.0i, 2.5 + 1i, 3.0 + 1.0i},
			{3.5 + 1.0i, 4.0 + 1.0i, 4.5 + 1.0i}};
		vector2_c d_div_B{
			{0.4 - 0.8i, 0.5 - 0.5i, 0.46154 - 0.30769i},
			{0.4 - 0.2i, 0.34483 - 0.13793i, 0.3 - 0.1i},
			{0.26415 - 0.075472i, 0.23529 - 0.058824i, 0.21176 - 0.047059i}};
		vector2_c B_div_c{
			{1.0 + 0.0i, 1.2 - 0.4i, 1.4 - 0.8i},
			{1.6 - 1.2i, 1.8 - 1.6i, 2.0 - 2.0i},
			{2.2 - 2.4i, 2.4 - 2.8i, 2.6 - 3.2i}};
		vector2_c c_div_B{
			{1.0 + 0.0i, 0.75 + 0.25i, 0.53846 + 0.30769i},
			{0.4 + 0.3i, 0.31034 + 0.27586i, 0.25 + 0.25i},
			{0.20755 + 0.22642i, 0.17647 + 0.20588i, 0.15294 + 0.18824i}};
		expect_near(rdivide(A, d), A_div_d);
		expect_near(rdivide(d, A), d_div_A);
		expect_near(rdivide(A, c), A_div_c);
		expect_near(rdivide(c, A), c_div_A);
		expect_near(rdivide(B, d), B_div_d);
		expect_near(rdivide(d, B), d_div_B);
		expect_near(rdivide(B, c), B_div_c);
		expect_near(rdivide(c, B), c_div_B);
		expect_near(A / d, A_div_d);
		expect_near(d / A, d_div_A);
		expect_near(A / c, A_div_c);
		expect_near(c / A, c_div_A);
		expect_near(B / d, B_div_d);
		expect_near(d / B, d_div_B);
		expect_near(B / c, B_div_c);
		expect_near(c / B, c_div_B);

		auto A1{A};
		auto A2{A};
		rdivide_self(A1, d);
		A2 /= d;
		expect_near(A1, A_div_d);
		expect_near(A2, A_div_d);
		auto B1{B};
		auto B2{B};
		rdivide_self(B1, d);
		B2 /= d;
		expect_near(B1, B_div_d);
		expect_near(B2, B_div_d);
		auto B3{B};
		auto B4{B};
		rdivide_self(B3, c);
		B4 /= c;
		expect_near(B3, B_div_c);
		expect_near(B4, B_div_c);
	}
	
}
