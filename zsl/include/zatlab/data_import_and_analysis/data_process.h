#ifndef DATA_PROCESSS_H
#define DATA_PROCESSS_H

#include "basics/basics.h"


namespace zsl {


#pragma region Noise Reduction

// Noise Reduction
// switch to zatlab/data_import_and_analysis/descriptive_statistics.h
// movmean
// movmedian
// movsum

vector_d smoothdata(const vector_d &v, const std::string &method, size_t window);

#pragma endregion

#pragma region Clean and Inspect Data

// sampling
bool isuniform(const vector_d &v);
#pragma endregion
}

#endif