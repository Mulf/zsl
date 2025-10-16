#include "zatlab/data_import_and_analysis/descriptive_statistics.h"
#include <algorithm>
#include <gsl.h>


namespace _ {
using namespace zsl;
using MoveStatFunc = int (*)(const gsl_movstat_end_t, const gsl_vector *, gsl_vector *, gsl_movstat_workspace *);

vector_d move_stat(const vector_d &v, size_t k, MoveStatFunc func) {
	vector_d w{v.size(), vector_d::allocator_type{}};

	auto vv = gsl_vector_const_view_array(v.data(), v.size());
	const gsl_vector *gv = &vv.vector;
	auto wv = gsl_vector_view_array(w.data(), w.size());
	gsl_vector *gw = &wv.vector;

	gsl_movstat_workspace *wp = gsl_movstat_alloc(k);
	func(GSL_MOVSTAT_END_TRUNCATE, gv, gw, wp);
	gsl_movstat_free(wp);

	return w;
}

vector_d move_stat(const vector_d &v, const vector_sz &k, MoveStatFunc func) {
	vector_d w{v.size(), vector_d::allocator_type{}};

	auto vv = gsl_vector_const_view_array(v.data(), v.size());
	const gsl_vector *gv = &vv.vector;
	auto wv = gsl_vector_view_array(w.data(), w.size());
	gsl_vector *gw = &wv.vector;
	
	const size_t kb = k.at(0);
	const size_t kf = k.at(1);
	gsl_movstat_workspace *wp = gsl_movstat_alloc2(kb, kf);
	func(GSL_MOVSTAT_END_TRUNCATE, gv, gw, wp);
	gsl_movstat_free(wp);

	return w;
}


}


namespace zsl {

#pragma region Basic Statistics

MinMaxVal bounds(const vector_d &v) {
	MinMaxVal r;
	gsl_stats_minmax(&r.minVal, &r.maxVal, v.data(), 1, v.size());
	return r;
}

double max(const vector_d &v) {
	return gsl_stats_max(v.data(), 1, v.size());
}

size_t max_index(const vector_d &v) {
	return gsl_stats_max_index(v.data(), 1, v.size());
}

double mean(const vector_d &v) {
	return gsl_stats_mean(v.data(), 1, v.size());
}

double median(const vector_d &v) {
	auto w = v;
	return gsl_stats_median(w.data(), 1, w.size());
}

double min(const vector_d &v) {
	return gsl_stats_min(v.data(), 1, v.size());
}

size_t min_index(const vector_d &v) {
	return gsl_stats_min_index(v.data(), 1, v.size());
}

double stdev(const vector_d &v) { 
	return gsl_stats_sd(v.data(), 1, v.size());
}

double var(const vector_d &v) { 
	return gsl_stats_variance(v.data(), 1, v.size());
}

double rms(const vector_d &v) {
	if(v.size() == 0)
	{
		return 0;
	}
	double s = 0;
	for(auto x : v) {
		s += x * x;
	}
	return std::sqrt(s / v.size());
}

#pragma endregion

#pragma region Covariance and Correlation
//double autocorr(const vector_d &v, const vector_d &w)
//{
//	if(v.size() != w.size()) {
//		Z_THROW(ZErrorCode::MATH_DIM_UNMATCH, "length of vector is not same");
//	}
//
//	return gsl_stats_correlation(v.data(), 1, w.data(), 1, v.size());
//}

double cov(const vector_d &v, const vector_d &w)
{
	if(v.size() != w.size()) {
		Z_THROW(ZErrorCode::MATH_DIM_UNMATCH, "length of vector is not same");
	}
	return gsl_stats_covariance(v.data(), 1, w.data(), 1, v.size());
}

double corr(const vector_d &v, const vector_d &w)
{
	if(v.size() != w.size()) {
		Z_THROW(ZErrorCode::MATH_DIM_UNMATCH, "length of vector is not same");
	}
	return gsl_stats_correlation(v.data(), 1, w.data(), 1, v.size());
}
#pragma endregion

#pragma region Moving Statistics
vector_d movmad(const vector_d &v, size_t k) {
	vector_d w{v.size(), vector_d::allocator_type{}};
	vector_d y{v.size(), vector_d::allocator_type{}};

	auto vv = gsl_vector_const_view_array(v.data(), v.size());
	const gsl_vector *gv = &vv.vector;
	auto wv = gsl_vector_view_array(w.data(), w.size());
	gsl_vector *gw = &wv.vector;
	auto yv = gsl_vector_view_array(w.data(), w.size());
	gsl_vector *gy = &yv.vector;

	gsl_movstat_workspace *wp = gsl_movstat_alloc(k);
	gsl_movstat_mad0(GSL_MOVSTAT_END_TRUNCATE, gv, gy, gw, wp);
	gsl_movstat_free(wp);

	return w;
}

vector_d movmad(const vector_d &v, const vector_sz &k) {
	vector_d w{v.size(), vector_d::allocator_type{}};

	auto vv = gsl_vector_const_view_array(v.data(), v.size());
	const gsl_vector *gv = &vv.vector;
	auto wv = gsl_vector_view_array(w.data(), w.size());
	gsl_vector *gw = &wv.vector;
	auto yv = gsl_vector_view_array(w.data(), w.size());
	gsl_vector *gy = &yv.vector;

	const size_t kb = k.at(0);
	const size_t kf = k.at(1);
	gsl_movstat_workspace *wp = gsl_movstat_alloc2(kb, kf);
	gsl_movstat_mad0(GSL_MOVSTAT_END_TRUNCATE, gv, gy, gw, wp);
	gsl_movstat_free(wp);

	return w;
}

vector_d movmax(const vector_d &v, size_t k)
{
	assert(k <= v.size());

	return _::move_stat(v, k, gsl_movstat_max);
}

vector_d movmax(const vector_d &v, const vector_sz &k)
{
	assert(k[0] + k[1] + 1 <= v.size());

	return _::move_stat(v, k, gsl_movstat_max);
}


vector_d movmean(const vector_d &v, size_t k)
{
	assert(k <= v.size());

	return _::move_stat(v, k, gsl_movstat_mean);
}

vector_d movmean(const vector_d &v, const vector_sz &k)
{
	assert(k.size() == 2);
	assert(k[0] + k[1] + 1 <= v.size());
	
	return _::move_stat(v, k, gsl_movstat_mean);
}

vector_d movmedian(const vector_d &v, size_t k)
{
	assert(k <= v.size());

	return _::move_stat(v, k, gsl_movstat_median);
}

vector_d movmedian(const vector_d &v, const vector_sz &k)
{
	assert(k.size() == 2);
	assert(k[0] + k[1] + 1 <= v.size());

	return _::move_stat(v, k, gsl_movstat_median);
}

vector_d movmin(const vector_d &v, size_t k)
{
	assert(k <= v.size());

	return _::move_stat(v, k, gsl_movstat_min);
}

vector_d movmin(const vector_d &v, const vector_sz &k)
{
	assert(k.size() == 2);
	assert(k[0] + k[1] + 1 <= v.size());

	return _::move_stat(v, k, gsl_movstat_min);
}

vector_d movstd(const vector_d &v, size_t k)
{
	assert(k <= v.size());

	return _::move_stat(v, k, gsl_movstat_sd);
}

vector_d movstd(const vector_d &v, const vector_sz &k)
{
	assert(k.size() == 2);
	assert(k[0] + k[1] + 1 <= v.size());

	return _::move_stat(v, k, gsl_movstat_sd);
}

vector_d movsum(const vector_d &v, size_t k)
{
	assert(k <= v.size());

	return _::move_stat(v, k, gsl_movstat_sum);
}

vector_d movsum(const vector_d &v, const vector_sz &k)
{
	assert(k.size() == 2);
	assert(k[0] + k[1] + 1 <= v.size());

	return _::move_stat(v, k, gsl_movstat_sum);
}


vector_d movvar(const vector_d &v, size_t k)
{
	assert(k <= v.size());

	return _::move_stat(v, k, gsl_movstat_variance);
}

vector_d movvar(const vector_d &v, const vector_sz &k)
{
	assert(k.size() == 2);
	assert(k[0] + k[1] + 1 <= v.size());

	return _::move_stat(v, k, gsl_movstat_variance);
}

#pragma endregion

}