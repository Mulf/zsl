#include <zatlab/data_import_and_analysis/descriptive_statistics.h>
#include <zsl.h>
#include <gtest/gtest.h>

constexpr double EPS = 1e-4;


using namespace zsl;
void expect_equal(MinMaxVal v1, MinMaxVal v2) {
	EXPECT_EQ(v1.minVal, v2.minVal);
	EXPECT_EQ(v1.maxVal, v2.maxVal);
}

static bool expect_near(const vector_d &v, const vector_d &w){
	for(size_t i = 0; i < v.size(); i++){
		EXPECT_NEAR(v[i], w[i], EPS);
	}
	return true;
}

static bool expect_equal(const vector_d &v, const vector_d &w){
	for(size_t i = 0; i < v.size(); i++){
		EXPECT_EQ(v[i], w[i]);
	}
	return true;
}


TEST(data_process, basic_statistics) {
	{
		vector_d v = {23, 42, 37, 18, 52, 15};
		EXPECT_EQ(max(v), 52);
		EXPECT_EQ(max_index(v), 4);
		EXPECT_EQ(min(v), 15);
		EXPECT_EQ(min_index(v), 5);
		expect_equal(bounds(v), {15, 52});
	}

	{
		vector_d v = {4, 2, -9};
		EXPECT_EQ(stdev(v), 7);
		EXPECT_EQ(var(v), 49);
		EXPECT_NEAR(rms(v), 5.8023, EPS);
	}

}


TEST(data_process, Covariance_and_Correlation) {

}

TEST(data_process, Moving_Statistics) {
	{
		vector_d v{3, 14, 15, 9, 26, 53, 58};
		vector_d m3{5.5, 1, 1, 6, 17, 5, 2.5};
		vector_d m4{5.5, 1, 3, 3, 8.5, 16, 5};
		auto w3 = movmad(v, 3);
		auto w4 = movmad(v, 4);
		auto x3 = movmad(v, {1, 1});
		auto x4 = movmad(v, {2, 1});
		expect_near(w3, m3);
		expect_near(w4, m4);
		expect_equal(x3, w3);
		expect_equal(x4, w4);
	}
	{
		vector_d v{3, 14, 15, 9, 26, 53, 58};
		vector_d m3{14, 15, 15, 26, 53, 58, 58};
		vector_d m4{14, 15, 15, 26, 53, 58, 58};
		auto w3 = movmax(v, 3);
		auto w4 = movmax(v, 4);
		auto x3 = movmax(v, {1, 1});
		auto x4 = movmax(v, {2, 1});
		expect_near(w3, m3);
		expect_near(w4, m4);
		expect_equal(x3, w3);
		expect_equal(x4, w4);
	}
	{
		vector_d v{3, 14, 15, 9, 26, 53, 58};
		vector_d m3{8.5, 10.6667, 12.6667, 16.6667, 29.3333, 45.6667, 55.5};
		vector_d m4{8.5, 10.6667, 10.25, 16, 25.75, 36.5, 45.6667};
		auto w3 = movmean(v, 3);
		auto w4 = movmean(v, 4);
		auto x3 = movmean(v, {1, 1});
		auto x4 = movmean(v, {2, 1});
		expect_near(w3, m3);
		expect_near(w4, m4);
		expect_equal(x3, w3);
		expect_equal(x4, w4);
	}
	{
		vector_d v{3, 14, 15, 9, 26, 53, 58};
		vector_d m3{8.5, 14, 14, 15, 26, 53, 55.5};
		vector_d m4{8.5, 14, 11.5, 14.5, 20.5, 39.5, 53};
		auto w3 = movmedian(v, 3);
		auto w4 = movmedian(v, 4);
		auto x3 = movmedian(v, {1, 1});
		auto x4 = movmedian(v, {2, 1});
		expect_near(w3, m3);
		expect_near(w4, m4);
		expect_equal(x3, w3);
		expect_equal(x4, w4);
	}
	{
		vector_d v{3, 14, 15, 9, 26, 53, 58};
		vector_d m3{3, 3, 9, 9, 9, 26, 53};
		vector_d m4{3, 3, 3, 9, 9, 9, 26};
		auto w3 = movmin(v, 3);
		auto w4 = movmin(v, 4);
		auto x3 = movmin(v, {1, 1});
		auto x4 = movmin(v, {2, 1});
		expect_near(w3, m3);
		expect_near(w4, m4);
		expect_equal(x3, w3);
		expect_equal(x4, w4);
	}
	{
		vector_d v{3, 14, 15, 9, 26, 53, 58};
		vector_d m3{7.7782, 6.6583, 3.2146, 8.6217, 22.1886, 17.2143, 3.5355};
		vector_d m4{7.7782, 6.6583, 5.5, 7.1647, 19.4829, 23.1012, 17.2143};
		auto w3 = movstd(v, 3);
		auto w4 = movstd(v, 4);
		auto x3 = movstd(v, {1, 1});
		auto x4 = movstd(v, {2, 1});
		expect_near(w3, m3);
		expect_near(w4, m4);
		expect_equal(x3, w3);
		expect_equal(x4, w4);
	}
	{
		vector_d v{3, 14, 15, 9, 26, 53, 58};
		vector_d m3{17, 32, 38, 50, 88, 137, 111};
		vector_d m4{17, 32, 41, 64, 103, 146, 137};
		auto w3 = movsum(v, 3);
		auto w4 = movsum(v, 4);
		auto x3 = movsum(v, {1, 1});
		auto x4 = movsum(v, {2, 1});
		expect_near(w3, m3);
		expect_near(w4, m4);
		expect_equal(x3, w3);
		expect_equal(x4, w4);
	}
	{
		vector_d v{3, 14, 15, 9, 26, 53, 58};
		vector_d m3{60.5, 44.3333, 10.3333, 74.3333, 492.3333, 296.3333, 12.5};
		vector_d m4{60.5, 44.3333, 30.25, 51.3333, 379.5833, 533.6667, 296.3333};
		auto w3 = movvar(v, 3);
		auto w4 = movvar(v, 4);
		auto x3 = movvar(v, {1, 1});
		auto x4 = movvar(v, {2, 1});
		expect_near(w3, m3);
		expect_near(w4, m4);
		expect_equal(x3, w3);
		expect_equal(x4, w4);
	}
}