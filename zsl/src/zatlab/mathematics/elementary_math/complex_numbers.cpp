#include "zatlab/mathematics/elementary_math/complex_numbers.h"
#include <cmath>
#include <algorithm>

#define DEG_TO_RAD(x)  (x * zsl::pi / 180.0)
#define RAD_TO_DEG(x)	(x * 180.0 / zsl::pi)

namespace _ {
using namespace zsl;

vector_d unary_func(const vector_d &x, double (*func)(double)) {
	vector_d y(x.size());
	std::transform(x.begin(), x.end(), y.begin(), [&](double x){
		return func(x);
	});
	return y;
}

vector_c unary_func(const vector_c &x, complex_d (*func)(const complex_d &)) {
	vector_c y(x.size());
	std::transform(x.begin(), x.end(), y.begin(), [&](const complex_d &x){
		return func(x);
	});
	return y;
}

vector_d unary_func(const vector_c &x, double (*func)(const complex_d &)) {
	vector_d y(x.size());
	std::transform(x.begin(), x.end(), y.begin(), [&](const complex_d &x){
		return func(x);
	});
	return y;
}

matrix_d unary_func(const matrix_d &X, double (*func)(double)) {
	matrix_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_d &x){
		return unary_func(x, func);
	});
	return Y;
}

matrix_c unary_func(const matrix_c &X, complex_d (*func)(const complex_d &)) {
	matrix_c Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_c &x){
		return unary_func(x, func);
	});
	return Y;
}

matrix_d unary_func(const matrix_c &X, double (*func)(const complex_d &)) {
	matrix_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_c &x){
		return unary_func(x, func);
	});
	return Y;
}

static inline double sign(double x) {
	if(x > 0) {
		return 1;
	} else if(x < 0) {
		return -1;
	}
	return 0;
}

static inline complex_d sign(const complex_d &z) {
	if(std::abs(z) == 0) {
		return 0;
	}
	return z / std::abs(z);
}

}

namespace zsl {
#pragma region Complex Numbers
vector_d abs(const vector_d &v){
	return _::unary_func(v, std::abs);
}

vector_d abs(const vector_c &v){
	return _::unary_func(v, std::abs);
}

matrix_d abs(const matrix_d &X){
	return _::unary_func(X, std::abs);
}

matrix_d abs(const matrix_c &X){
	return _::unary_func(X, std::abs);
}

// angle
vector_d angle(const vector_c &v){
	return _::unary_func(v, std::arg);
}

matrix_d angle(const matrix_c &X){
	return _::unary_func(X, std::arg);
}

// conj
vector_c conj(const vector_c &v){
	return _::unary_func(v, std::conj);
}

matrix_c conj(const matrix_c &Z){
	return _::unary_func(Z, std::conj);
}

// imag
vector_d imag(const vector_c &v){
	return _::unary_func(v, std::imag);
}

matrix_d imag(const matrix_c &X){
	return _::unary_func(X, std::imag);
}

// real
vector_d real(const vector_c &v){
	return _::unary_func(v, std::real);
}

matrix_d real(const matrix_c &X){
	return _::unary_func(X, std::real);
}

// sign
vector_d sign(const vector_d &v){
	return _::unary_func(v, _::sign);
}

matrix_d sign(const matrix_d &X){
	return _::unary_func(X, _::sign);
}

vector_c sign(const vector_c &v) {
	return _::unary_func(v, _::sign);
}

matrix_c sign(const matrix_c &Z){
	return _::unary_func(Z, _::sign);
}
#pragma endregion
}