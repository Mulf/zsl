#include "zatlab/data_import_and_analysis/data_process.h"
#include "zatlab/data_import_and_analysis/descriptive_statistics.h"
#include "zatlab/mathematics/elementary_math/constants_and_test_matrices.h"

namespace zsl {

bool isuniform(const vector_d &v) {
	if(v.size() < 2) {
		Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "Length of vector must be not less than 1");
	}

	double maxNum = max(v);
	const double TOL = eps(maxNum);

	double step = v[1] - v[0];
	for(size_t i = 2; i < v.size(); i++)
	{
		if(std::abs(v[i] - v[i - 1] - step) > TOL) {
			return false;
		}
	}
	return true;
}

}