#include "zatlab/mathematics/fourier_analysis_and_filtering.h"
#include "zsl.h"
#include <gtest/gtest.h>

using namespace zsl;
using namespace std::literals::complex_literals;

constexpr double EPS = 1e-4;

static bool expect_near(const vector_d &v, const vector_d &w){
	for(size_t i = 0; i < v.size(); i++){
		EXPECT_NEAR(v[i], w[i], EPS);
	}
	return true;
}

static bool expect_near(const vector_c &v, const vector_c &w){
	for(size_t i = 0; i < v.size(); i++){
		EXPECT_NEAR(v[i].real(), w[i].real(), EPS);
		EXPECT_NEAR(v[i].imag(), w[i].imag(), EPS);
	}
	return true;
}

static bool expect_near(const matrix_d &A, const matrix_d &B){
	for(size_t i = 0; i < A.size(); i++){
		expect_near(A[i], B[i]);
	}
	return true;
}

static bool expect_near(const matrix_c &A, const matrix_c &B){
	for(size_t i = 0; i < A.size(); i++){
		expect_near(A[i], B[i]);
	}
	return true;
}



TEST(fourier_analysis_and_filtering, fft) {
	{
		vector_d x{1, 2, 1, -1, 1.5, 2.5, 0.5, -0.5};
		vector_c result_matlab{
			7.0000 + 0.0000i,
			-0.5000 + 0.2071i,
			1.0000 - 6.0000i,
			-0.5000 + 1.2071i,
			1.0000 + 0.0000i,
			-0.5000 - 1.2071i,
			1.0000 + 6.0000i,
			-0.5000 - 0.2071i};
		vector_c w = fft(x);
		expect_near(result_matlab, w);

		auto iv_c = ifft(w);
		auto iv = real(iv_c);
		expect_near(iv, x);
	}
	{
		double Fs = 1000;
		double T = 1 / Fs;
		double L = 1500;
		auto t = colon(0, L - 1) * T;


	}
}