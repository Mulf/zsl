#include <gtest/gtest.h>
#include <zatlab/language_fundamental/matrices_and_arrays.h>

using namespace zsl;

TEST(matrices_and_arrays, create_and_combine_arrays) {
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

TEST(matrices_and_arrays, create_grids) {
	// linespace
	{
		vector_d y = linspace(-5, 5, 7);
		vector_d y1{ -5.0000, -3.3333, -1.6667,  0, 1.6667, 3.3333, 5.0000 };
		for (size_t i = 0; i < y.size(); i++) {
			EXPECT_NEAR(y[i], y1[i], ABS_EPS);
		}
		
	}
}

TEST(matrices_and_arrays, determine_size_shape_and_order) {
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


TEST(matrices_and_arrays, indexing) {
	vector_d x{ 1, 2, 3, 4, 5, 6, 7, 8 , 9, 10 };
	EXPECT_EQ(colon(1, 10), x);

	vector_d x2{ 0, 0.1, 0.2, 0.3, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1 };
	vector_d x3 = colon(0, 0.1, 1);
	for (size_t i = 0; i < x2.size(); i++) {
		EXPECT_NEAR(x2[i], x3[i], ABS_EPS);
	}

	vector_d y{ 10, 8, 6, 4, 2, 0 };
	EXPECT_EQ(colon(10, -2, 0), y);

	EXPECT_EQ(colon(1, 0, 1), vector_d{});
	EXPECT_EQ(colon(1, -1, 2), vector_d{});
	EXPECT_EQ(colon(1, 1, -2), vector_d{});

	EXPECT_EQ(colon(x), x);
	vector_d x4{ 3.0, 4.0, 5.0 };
	EXPECT_EQ(colon(x, 2, 4), x4);
	EXPECT_EQ(colon(x, 2, 2), vector_d{ 3 });
	EXPECT_EQ(colon(x, 4, 2), vector_d{});
	vector_d x5{ 1, 3, 5, 7, 9 };
	EXPECT_EQ(colon(x, 0, 2, 8), x5);
	EXPECT_EQ(colon(x, 0, 2, 9), x5);
	vector_d x6{ 10, 8, 6, 4, 2 };
	EXPECT_EQ(colon(x, 9, -2, 0), x6);
	EXPECT_EQ(colon(x, 9, -2, 1), x6);

	matrix_d A{
		{1, 2, 3, 4},
		{5, 6, 7, 8},
		{9, 10, 11, 12},
		{13, 14, 15, 16} };
	vector_d r2{ 5, 6, 7, 8 };
	EXPECT_EQ(row(A, 1), r2);
	matrix_d r3{ {5, 6, 7, 8}, {9, 10, 11, 12} };
	EXPECT_EQ(rows(A, 1, 2), r3);
	matrix_d r4{ {1, 2, 3, 4}, {9, 10, 11, 12} };
	EXPECT_EQ(rows(A, 0, 2, 2), r4);
	EXPECT_EQ(rows(A, 0, 2, 3), r4);
	matrix_d r5{ {9, 10, 11, 12}, {1, 2, 3, 4} };
	EXPECT_EQ(rows(A, 2, -2, 0), r5);

	vector_d c2{ 2, 6, 10, 14};
	EXPECT_EQ(col(A, 1), c2);
	matrix_d c3{ {2,3}, {6,7}, {10, 11}, {14, 15} };
	EXPECT_EQ(cols(A, 1, 2), c3);
	matrix_d c4{ {2, 4}, {6, 8}, {10, 12}, {14, 16} };
	EXPECT_EQ(cols(A, 1, 2, 3), c4);
	matrix_d c5{ {4, 2}, {8, 6}, {12, 10}, {16, 14} };
	EXPECT_EQ(cols(A, 3, -2, 1), c5);
	
	//EXPECT_EQ(colon(A, 1, 2), r23);
}


