#ifndef DESCRIPTIVE_STATISTICS_H
#define DESCRIPTIVE_STATISTICS_H

#include "basics/basics.h"

namespace zsl {
#pragma region Basic Statistics

struct MinMaxVal
{
	double minVal;
	double maxVal;
};
MinMaxVal bounds(const vector_d &v);

double max(const vector_d &v);
size_t max_index(const vector_d &v);

double mean(const vector_d &v);

double median(const vector_d &v); // copy data & rearrange

//vector_d maxk(const vector_d &v);

double min(const vector_d &v);
size_t min_index(const vector_d &v);

double stdev(const vector_d &v);

double var(const vector_d &v);

double rms(const vector_d &v);

//vector_d mink(const vector_d &v);

#pragma endregion

#pragma region Covariance and Correlation
//double autocorr(const vector_d &v, const vector_d &w);

double cov(const vector_d &v, const vector_d &w);

double corr(const vector_d &v, const vector_d &w);
#pragma endregion

#pragma region Moving Statistics
vector_d movmad(const vector_d &v, size_t k);
vector_d movmad(const vector_d &v, const vector_sz &k);

vector_d movmax(const vector_d &v, size_t k);
vector_d movmax(const vector_d &v, const vector_sz &k);

vector_d movmean(const vector_d &v, size_t k);
vector_d movmean(const vector_d &v, const vector_sz &k);
void movmean_self(vector_d &v, size_t k);
void movmean_self(vector_d &v, const vector_sz &k);

vector_d movmedian(const vector_d &v, size_t k);
vector_d movmedian(const vector_d &v, const vector_sz &k);
void movmedian_self(vector_d &v, size_t k);
void movmedian_self(vector_d &v, const vector_sz &k);

vector_d movmin(const vector_d &v, size_t k);
vector_d movmin(const vector_d &v, const vector_sz &k);

vector_d movstd(const vector_d &v, size_t k);
vector_d movstd(const vector_d &v, const vector_sz &k);

vector_d movsum(const vector_d &v, size_t k);
vector_d movsum(const vector_d &v, const vector_sz &k);

vector_d movvar(const vector_d &v, size_t k);
vector_d movvar(const vector_d &v, const vector_sz &k);

#pragma endregion

}

#endif // !DESCRIPTIVE_STATISTICS_H
