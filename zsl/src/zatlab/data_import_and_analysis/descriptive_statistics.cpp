#include "zatlab/data_import_and_analysis/descriptive_statistics.h"
#include <algorithm>

#include <gsl.h>


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

#pragma endregion

}