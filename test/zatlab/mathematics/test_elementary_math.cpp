#include "zatlab/mathematics/elementary_math.h"
#include "zatlab/data_import_and_analysis/data_import_and_export.h"
#include "zatlab/language_fundamentals/matrices_and_arrays.h"
#include "zsl.h"
#include <gtest/gtest.h>
#include <filesystem>

#define STRING(x) #x
#define XSTRING(x) STRING(x)

using namespace zsl;



TEST(mathematics, elementary_math) {
	auto v = linspace(0, 8, 50);
	matrix_d X = {v, v + 1.5};
	auto w = sin(v);
	auto Y = sin(X);

	std::string curDir = XSTRING(CURRENT_SOURCE_DIR);
	writevector(w, curDir + "/w.csv");
	writematrix(X, curDir + "/X.csv");
	writematrix(Y, curDir + "/Y.csv");


}
