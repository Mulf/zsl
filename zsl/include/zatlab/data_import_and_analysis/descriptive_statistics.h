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

//vector_d mink(const vector_d &v);

#pragma endregion


}

#endif // !DESCRIPTIVE_STATISTICS_H
