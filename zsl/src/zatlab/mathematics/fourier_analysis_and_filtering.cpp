#include "zatlab/mathematics/fourier_analysis_and_filtering.h"
#include "zatlab/language_fundamentals/matrices_and_arrays.h"
#include <gsl.h>

#include <iostream>


namespace _ {
using namespace zsl;

bool is_radix2(size_t x) {
	return (x & (x - 1))== 0;
}

}

namespace zsl {


#pragma region Fourier Transform

vector_c fft(const vector_d &v) {
	if(v.empty()) {
		Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "FFT input vector is empty");
	}

	const size_t N = v.size();
	vector_c w{v.size(), vector_c::allocator_type{}};
	for(size_t i = 0; i < v.size(); i++)
	{
		w[i].real(v[i]);
	}

	if(_::is_radix2(N)) {
		gsl_fft_complex_radix2_forward(reinterpret_cast<gsl_complex_packed_array>(w.data()), 1, N);
		return w;
	}



	gsl_fft_complex_wavetable *wt = gsl_fft_complex_wavetable_alloc(N);
	gsl_fft_complex_workspace *ws = gsl_fft_complex_workspace_alloc(N);

	
	

	int error = gsl_fft_complex_forward(reinterpret_cast<double *>(w.data()), 1, N, wt, ws);
	if(error != 0) {
		std::cerr << "GSL FFT failed." << std::endl;
		gsl_fft_complex_wavetable_free(wt);
		gsl_fft_complex_workspace_free(ws);
		return {};
	}

	gsl_fft_complex_wavetable_free (wt);
	gsl_fft_complex_workspace_free (ws);

	return w;
}

vector_c ifft(const vector_c &v) {
	if(v.empty()) {
		Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "FFT input vector is empty");
	}

	const size_t N = v.size();
	vector_c w{v.size(), vector_c::allocator_type{}};
	for(size_t i = 0; i < v.size(); i++)
	{
		w[i]= v[i];
	}

	if(_::is_radix2(N)) {
		gsl_fft_complex_radix2_inverse(reinterpret_cast<gsl_complex_packed_array>(w.data()), 1, N);
		return w;
	}



	gsl_fft_complex_wavetable *wt = gsl_fft_complex_wavetable_alloc(N);
	gsl_fft_complex_workspace *ws = gsl_fft_complex_workspace_alloc(N);




	int error = gsl_fft_complex_backward(reinterpret_cast<double *>(w.data()), 1, N, wt, ws);
	if(error != 0) {
		std::cerr << "GSL FFT failed." << std::endl;
		gsl_fft_complex_wavetable_free(wt);
		gsl_fft_complex_workspace_free(ws);
		return {};
	}

	gsl_fft_complex_wavetable_free (wt);
	gsl_fft_complex_workspace_free (ws);

	return w;
}

// fftshfit
vector_c fftshift(const vector_c &v) {
	if(v.size() % 2 == 0) {
		return circshift(v, v.size() / 2);
	}
	return circshift(v, (v.size() - 1) / 2);
}

// ifftshfit
vector_c ifftshift(const vector_c &v) {
	if(v.size() % 2 == 0) {
		return circshift(v, v.size() / 2);
	}
	return circshift(v, (v.size() + 1) / 2);
}

#pragma endregion

}