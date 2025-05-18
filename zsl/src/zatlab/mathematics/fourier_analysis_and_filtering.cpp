#include "zatlab/mathematics/fourier_analysis_and_filtering.h"
#include "zatlab/language_fundamentals/matrices_and_arrays.h"
#include "fasttransforms.h"

namespace _ {
using namespace zsl;
using namespace alglib;


static real_1d_array to_real_1d_array(const vector_d &vec) {
	real_1d_array arr;
	arr.setlength(vec.size());

	for(size_t i = 0; i < vec.size(); ++i) {
		arr[i] = vec[i];
	}

	return arr;
}

static vector_d real_1d_array_to_vector(const real_1d_array &arr) {
	std::vector<double> vec;
	ae_int_t n = arr.length();
	vec.reserve(n);

	for(ae_int_t i = 0; i < n; ++i) {
		vec.push_back(arr[i]);
	}

	return vec;
}

static vector_c to_vetor_c(const complex_1d_array &arr) {
	vector_c result;
	ae_int_t n = arr.length();
	result.reserve(static_cast<size_t>(n));

	// Convert each element
	for(ae_int_t i = 0; i < n; ++i) {
		result.emplace_back(arr[i].x, arr[i].y);
	}

	return result;
}

static complex_1d_array to_alglib_complex(const vector_c &vec) {
	complex_1d_array result;
	result.setlength(vec.size());
	for(size_t i = 0; i < vec.size(); ++i) {
		result[i].x = vec[i].real();
		result[i].y = vec[i].imag();
	}
	return result;
}

}

namespace zsl {
using namespace alglib;


#pragma region Fourier Transform

vector_c fft(const vector_d &v) {
	if(v.empty()) {
		Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "FFT input vector is empty");
	}

	real_1d_array x_alglib = _::to_real_1d_array(v);
	complex_1d_array f_alglib;
	fftr1d(x_alglib, f_alglib);

	return _::to_vetor_c(f_alglib);
}

vector_c ifft(const vector_c &v) {
	if(v.empty()) {
		Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "FFT input vector is empty");
	}

	const size_t n = v.size();
	auto alglibInput = _::to_alglib_complex(v);
	alglib::fftc1dinv(alglibInput, n);

	return _::to_vetor_c(alglibInput);
}

// fftshit
vector_c fftshift(const vector_c &v) {
	if(v.size() % 2 == 0) {
		return circshift(v, v.size() / 2);
	}
	return circshift(v, (v.size() - 1) / 2);
}

// ifftshit
vector_c ifftshift(const vector_c &v) {
	if(v.size() % 2 == 0) {
		return circshift(v, v.size() / 2);
	}
	return circshift(v, (v.size() + 1) / 2);
}

#pragma endregion

}