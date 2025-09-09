#include <zatlab/data_import_and_analysis/descriptive_statistics.h>
#include <zsl.h>
#include <gtest/gtest.h>

using namespace zsl;
void expect_equal(MinMaxVal v1, MinMaxVal v2) {
	EXPECT_EQ(v1.minVal, v2.minVal);
	EXPECT_EQ(v1.maxVal, v2.maxVal);
}


TEST(data_process, basic_statistics) {
	vector_d v = {23, 42, 37, 18, 52, 15};
	EXPECT_EQ(max(v), 52);
	EXPECT_EQ(max_index(v), 4);
	EXPECT_EQ(min(v), 15);
	EXPECT_EQ(min_index(v), 5);
	expect_equal(bounds(v), {15, 52});

}