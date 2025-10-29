#include <gtest/gtest.h>
#include "basics/check.h"

using namespace zsl;

TEST(basics, check) {
	{
		vector_d v{1.0, 2.0, 3.0};
		vector2_d A{{1.0, 2.0, 3.0, 3.0}, {1.0, 2.0, 0.0, 3.0}};
		expect_valid_index(v, 3);
		//expect_valid_index(A, 2, 2);
		//expect_valid_index(A, 1, 4);
	}
	{
		vector_d v{1.0, 2.0, 3.0};
		vector2_d A{{1.0, 2.0, 3.0, 3.0}, {1.0, 2.0, 0.0, 3.0}};
		//expect_valid_range(v, 3, 2);
		//expect_valid_range(v, 1, 4);
		//expect_valid_range(A, 3, 2, 1, 1);
		//expect_valid_range(A, 0, 1, 1, 0);
		//expect_valid_range(A, 1, 2, 1, 2);
		//expect_valid_range(A, 0, 1, 1, 5);
	}
	{
		vector_d v{1.0, 2.0, 3.0, 3.0};
		vector2_d A{{1.0, 2.0, 3.0, 3.0}, {1.0, 2.0, 0.0, 3.0}};
		// expect_no_zero(v);
		// expect_no_zero(A);
	}

	{
		vector_d v{1.0};
		vector2_d A{{1.0}, {}, {2.0}};
		// expect_not_empty(v);
		// expect_not_empty(A);
	}

	{
		vector2_d A{{1.0}, {2.0}, {2.0, 3.0}};
		//expect_valid_matrix(A);
	}

	{
		vector_d v{1.0, 2.0};
		vector_d w{1.0, 2.0, 3.0};
		vector2_d A{{1.0}, {2.0}, {3.0}};
		vector2_d B{{1.0, 1.0}, {2.0, 2.0}, {3.0, 3.0}};
		//expect_dim_match(v, w);
		//expect_dim_match(A, v);
		//expect_dim_match(v, A);
		//expect_dim_match(A, B);
	}

	{
		vector_d v{2.0};
		//expect_len_gt(v, 1);
	}

	{
		std::string filepath = "E:\\zsl\\main2.cpp";
		//expect_file_exist(filepath);
	}

}
