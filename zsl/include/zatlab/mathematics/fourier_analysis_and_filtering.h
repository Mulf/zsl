#ifndef FOURIER_ANALYSIS_AND_ANALYSIS_H
#define FOURIER_ANALYSIS_AND_ANALYSIS_H

#include "basics/basics.h"

namespace zsl {

#pragma region Fourier Transform
// fft 
vector_c fft(const vector_d &v);

// 
vector_c ifft(const vector_c &v);

// fftshit
vector_c fftshift(const vector_c &v);
// ifftshit
vector_c fftshift(const vector_c &v);


#pragma endregion

}

#endif // !FOURIER_ANALYSIS_AND_ANALYSIS_H
