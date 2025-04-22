#include <gtest/gtest.h>
#include <zatlab/language_fundamental/matrices_and_arrays.h>

using namespace zsl;

TEST(matrices_and_arrays, create_and_combine_arrays) {
	// cat
	{
		vector_d v{ 1, 2, 3 };
		vector_d w{ 4, 5 };
		vector_d x{ 1, 2, 3, 4, 5 };
		EXPECT_EQ(cat(v, {}), v);
		EXPECT_EQ(cat({}, v), v);
		EXPECT_EQ(cat(v, w), x);


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

	// diag
	{
		vector_d v{ 2, 1, -1, -2, -5 };
		matrix_d D{ 
			{2, 0, 0, 0, 0},
			{0, 1, 0, 0, 0},
			{0, 0, -1, 0, 0},
			{0, 0, 0, -2, 0},
			{0, 0, 0, 0, -5} };
		matrix_d D1{
			{0, 2, 0, 0, 0, 0},
			{0, 0, 1, 0, 0, 0},
			{0, 0, 0, -1, 0, 0},
			{0, 0, 0, 0, -2, 0},
			{0, 0, 0, 0, 0, -5},
			{0, 0, 0, 0, 0, 0} };
		matrix_d D2{
			{0, 0, 0, 0, 0, 0},
			{2, 0, 0, 0, 0, 0},
			{0, 1, 0, 0, 0, 0},
			{0, 0, -1, 0, 0, 0},
			{0, 0, 0, -2, 0, 0},
			{0, 0, 0, 0, -5, 0} };
		EXPECT_EQ(diag(vector_d{}), matrix_d{});
		EXPECT_EQ(diag(v), D);
		EXPECT_EQ(diag(v, 1), D1);
		EXPECT_EQ(diag(v, -1), D2);
		EXPECT_EQ(diag(D1, 1), v);
		EXPECT_EQ(diag(D2, -1), v);
	}

	// eye
	{
		matrix_d I{ 
			{1, 0, 0, 0},
			{0, 1, 0, 0},
			{0, 0, 1, 0},
			{0, 0, 0, 1} };
		matrix_d I1{ 
			{1, 0, 0},
			{0, 1, 0} };
		EXPECT_EQ(eye(4), I);
		EXPECT_EQ(eye(2, 3), I1);
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
		EXPECT_EQ(vzeros(0), vector_d{});
		EXPECT_EQ(zeros(0), matrix_d{});
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
	// size
	{
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

	// Reshape
	{
		// reshape
		{
			vector_d A = colon(1, 10);
			matrix_d B = { {1, 6}, {2, 7}, {3, 8}, {4, 9}, {5, 10} };
			EXPECT_EQ(reshape(A, { 5, 2 }), B);
			EXPECT_EQ(reshape(A, 5, {}), B);
			EXPECT_EQ(reshape(A, {}, 2), B);

			matrix_d C = {
				{16,  2,  3, 13},
				{ 5, 11, 10,  8},
				{ 9,  7,  6, 12},
				{ 4, 14, 15,  1} };
			matrix_d D = {
				{16,  3},
				{ 5, 10},
				{ 9,  6},
				{ 4, 15},
				{ 2, 13},
				{11,  8},
				{ 7, 12},
				{14,  1} };
			EXPECT_EQ(reshape(C, { 5, 2 }), D);
			EXPECT_EQ(reshape(C, 5, {}), D);
			EXPECT_EQ(reshape(C, {}, 2), D);
		}
	}

	// Rearrange
	{
		// circshift
		{
			vector_d v = colon(1, 10);
			vector_d w{ 8,  9, 10, 1, 2, 3, 4, 5, 6, 7 };
			EXPECT_EQ(circshift(w, 3), w);
			EXPECT_EQ(circshift(w, -7), w);

			matrix_d A{ {1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7} };
			matrix_d B{ {5, 5}, {6, 6}, {7, 7}, {1, 1}, {2, 2}, {3, 3}, {4, 4} };
			EXPECT_EQ(circshift(A, 3), B);
			EXPECT_EQ(circshift(A, -4), B);

			matrix_d X{
				{1, 1, 0, 0},
				{1, 1, 0, 0},
				{0, 0, 0, 0},
				{0, 0, 0, 0} };
			matrix_d Y{
				{0, 1, 1, 0},
				{0, 1, 1, 0},
				{0, 0, 0, 0},
				{0, 0, 0, 0} };
			matrix_d Z{
				{0, 0, 0, 0},
				{0, 1, 1, 0},
				{0, 1, 1, 0},
				{0, 0, 0, 0} };
			EXPECT_EQ(circshift(X, 1, 2), Y);
			EXPECT_EQ(circshift(X, { 1, 1 }), Z);
			EXPECT_EQ(circshift(Z, { -1, -1 }), X);
		}

		// flip
		{
			vector_d a{ 1, 2, 3 };
			vector_d b{ 3, 2, 1 };
			EXPECT_EQ(flip(a), b);
			auto a1 = a;
			flip_self(a1);
			EXPECT_EQ(a1, b);
		}
	}
}


TEST(matrices_and_arrays, indexing) {
	// colon
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

	vector_d c2{ 2, 6, 10, 14 };
	EXPECT_EQ(col(A, 1), c2);
	matrix_d c3{ {2,3}, {6,7}, {10, 11}, {14, 15} };
	EXPECT_EQ(cols(A, 1, 2), c3);
	matrix_d c4{ {2, 4}, {6, 8}, {10, 12}, {14, 16} };
	EXPECT_EQ(cols(A, 1, 2, 3), c4);
	matrix_d c5{ {4, 2}, {8, 6}, {12, 10}, {16, 14} };
	EXPECT_EQ(cols(A, 3, -2, 1), c5);


	// ind2sub & sub2ind
	std::vector<size_t> ind{ 2, 3, 4, 5 };
	std::pair<size_t, size_t> sz{ 3, 3 };
	std::vector<std::pair<size_t, size_t>> sub = { {2, 0}, {0, 1}, {1, 1}, {2, 1} };

	{
		auto ans = ind2sub(sz, ind);
		EXPECT_EQ(ind2sub(sz, ind[0]), ans[0]);
		EXPECT_EQ(ind2sub(sz, ind[1]), ans[1]);
		EXPECT_EQ(ans, sub);
	}

	{
		auto ans = sub2ind(sz, sub);
		EXPECT_EQ(sub2ind(sz, sub[0]), ans[0]);
		EXPECT_EQ(sub2ind(sz, sub[1]), ans[1]);
		EXPECT_EQ(ans, ind);
	}


}
