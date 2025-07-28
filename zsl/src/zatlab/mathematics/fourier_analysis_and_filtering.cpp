#include "zatlab/mathematics/fourier_analysis_and_filtering.h"
#include "zatlab/language_fundamentals/matrices_and_arrays.h"
#include <gsl.h>


namespace _ {
using namespace zsl;



}

namespace zsl {


#pragma region Fourier Transform

vector_c fft(const vector_d &v) {
	if(v.empty()) {
		Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "FFT input vector is empty");
	}

	const size_t N = v.size();
	gsl_fft_complex_wavetable *wt = gsl_fft_complex_wavetable_alloc(N);
	gsl_fft_complex_workspace *ws = gsl_fft_complex_workspace_alloc(N);	
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