#include "zatlab/data_import_and_analysis/descriptive_statistics.h"
#include <algorithm>


namespace zsl {

double max(const vector_d &v) {
	return *std::max_element(v.begin(), v.end());
}

}