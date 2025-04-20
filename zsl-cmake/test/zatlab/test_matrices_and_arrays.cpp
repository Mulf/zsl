#include <gtest/gtest.h>
#include <zatlab/language_fundamental/matrices_and_arrays.h>

using namespace zsl;

TEST(matrices_and_arrays, create_and_combine_arrays_ones_zeros) {
	// cat
	{
		auto A = ones(3);
		auto B = zeros(3);
		matrix_d C1{
			{1, 1, 1},
			{1, 1, 1},
			{1, 1, 1},
			{0, 0, 0},
			{0, 0, 0},
			{0, 0, 0} };
		matrix_d C2{
			{1, 1, 1, 0, 0, 0},
			{1, 1, 1, 0, 0, 0},
			{1, 1, 1, 0, 0, 0} };

		EXPECT_EQ(cat(1, A, B), C1);
		EXPECT_EQ(cat(2, A, B), C2);
	}

	// horzcat
	{
		matrix_d A{ {1, 2}, {3, 4} };
		matrix_d B{ {4, 5, 6}, {7, 8, 9} };
		matrix_d C{
			{1, 2, 4, 5, 6},
			{3, 4, 7, 8, 9} };
		vector_d d{ 5, 6 };
		matrix_d E{ {1, 2, 5}, {3, 4, 6} };
		vector_d v{ 1, 2 };
		vector_d w{ 4, 5, 6 };
		vector_d r{ 1, 2, 4, 5, 6 };


		EXPECT_EQ(horzcat(A, B), C);
		EXPECT_EQ(horzcat(A, d), E);
		EXPECT_EQ(horzcat(v, w), r);
	}

	// vercat
	{
		matrix_d A = { {1, 2, 3}, {4, 5, 6} };
		matrix_d B = { {7, 8, 9} };
		matrix_d C = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

		EXPECT_EQ(vertcat(A, B), C);
	}

	// zeros
	{ 
		vector_d v = vzeros(3);
		vector_d r{ 0.0, 0.0, 0.0 };
		matrix_d m1 = zeros(3);
		matrix_d r1 = { { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } };
		matrix_d m2 = zeros(2, 3);
		matrix_d r2 = { { 0.0, 0.0, 0.0 }, { 0.0, 0.0, 0.0 } };
		EXPECT_EQ(v, r);
		EXPECT_EQ(m1, r1);
		EXPECT_EQ(m2, r2);
	}

	// ones
	{
		auto v3 = vones(4);
		vector_d r3 = { 1.0, 1.0, 1.0, 1.0 };
		matrix_d m4 = ones(3);
		matrix_d r4 = { { 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0 } };
		matrix_d m5 = ones(2, 3);
		matrix_d r5 = { { 1.0, 1.0, 1.0 }, { 1.0, 1.0, 1.0 } };
		EXPECT_EQ(v3, r3);
		EXPECT_EQ(m4, r4);
		EXPECT_EQ(m5, r5);
	}
	

}

TEST(matrices_and_arrays, create_and_combine_arrays_create_grids) {

	// linespace
	{
		vector_d y = linspace(-5, 5, 7);
		vector_d y1{ -5.0000, -3.3333, -1.6667,  0, 1.6667, 3.3333, 5.0000 };
		for (size_t i = 0; i < y.size(); i++) {
			EXPECT_NEAR(y[i], y1[i], ABS_EPS);
		}
		
	}
}

TEST(matrices_and_arrays, create_and_combine_arrays_determine_size_shape_and_order) {
	const vector_d v{ 1, 2, 3 };
	const matrix_d A{ {1, 2, 3}, {4, 5, 6} };
	EXPECT_EQ(length(v), 3);
	EXPECT_EQ(length(A), 3);
	EXPECT_EQ(size(v), 3);
	vector_d sz{ 2.0, 3.0 };
	EXPECT_EQ(size(A), sz);
	EXPECT_EQ(numel(v), 3);
	EXPECT_EQ(numel(A), 6);
}
