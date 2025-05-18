#include <zatlab/data_import_and_analysis/data_process.h>
#include <zsl.h>
#include <gtest/gtest.h>

using namespace zsl;
TEST(data_process, sampling) {
	vector_d v = colon(0.0, 1.0, 100.0);
	EXPECT_TRUE(isuniform(v));

}