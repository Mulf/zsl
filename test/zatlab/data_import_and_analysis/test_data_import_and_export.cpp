#include "zatlab/data_import_and_analysis/data_import_and_export.h"
#include <gtest/gtest.h>
#include <filesystem>


#define STRING(x) #x
#define XSTRING(x) STRING(x)

using namespace zsl;
using namespace std::filesystem;

TEST(data_import_and_export, standard_file_formats) {
	const std::string curSrcDir = XSTRING(CURRENT_SOURCE_DIR);
	const path srcDir{curSrcDir};
	if(!exists(srcDir)) {
		Z_THROW(ZErrorCode::FILE_NOT_EXIST, "");
	}

	path filepath =  srcDir/ "magic4.csv";

	std::string filename = curSrcDir + "/magic4.csv";
	auto magic4 = readmatrix(filename);
	matrix_d A = {
		{16.0, 2.0, 3.0, 13.0},
		{5.0, 11.0, 10.0, 8.0},
		{9.0, 7.0, 6.0, 12.0},
		{4.0, 14.0, 15.0, 1.0}};
	EXPECT_EQ(magic4, A);

	vector_d v{1, 2, 3, 4, 5};
	auto v_col = readvector(curSrcDir + "/colvec.csv");
	auto v_row = readvector(curSrcDir + "/rowvec.csv");
	EXPECT_EQ(v, v_col);
	EXPECT_EQ(v, v_row);

	auto outmatFile = curSrcDir + "/magic4-out.csv";
	if(exists(outmatFile)) remove(outmatFile);
	writematrix(A, outmatFile);
	auto outMat = readmatrix(outmatFile);
	EXPECT_EQ(outMat, A);
	auto outvecFile = curSrcDir + "/outvec.csv";
	if(exists(outvecFile)) remove(outvecFile);
	writevector(v, outvecFile);
	auto outvec = readvector(outvecFile);
	EXPECT_EQ(outvec, v);
}