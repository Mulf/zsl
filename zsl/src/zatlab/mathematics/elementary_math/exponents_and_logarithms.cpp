#include "zatlab/mathematics/elementary_math/exponents_and_logarithms.h"
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

vector2_d unary_func(const vector2_d &X, double (*func)(double)) {
	vector2_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_d &x){
		return unary_func(x, func);
	});
	return Y;
}

vector2_c unary_func(const vector2_c &X, complex_d (*func)(const complex_d &)) {
	vector2_c Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_c &x){
		return unary_func(x, func);
	});
	return Y;
}

vector2_d unary_func(const vector2_c &X, double (*func)(const complex_d &)) {
	vector2_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_c &x){
		return unary_func(x, func);
	});
	return Y;
}

static inline double pow2(double x) {
	return std::pow(2, x);
}

static inline complex_d pow2(const complex_d &z) {
	return std::pow(2, z);
}

}

namespace zsl {

#pragma region  Exponents and Logarithms
// exp
vector_d exp(const vector_d &v) {
	return _::unary_func(v, std::exp);
}

vector_c exp(const vector_c &v) {
	return _::unary_func(v, std::exp);
}

vector2_d exp(const vector2_d &A) {
	return _::unary_func(A, std::exp);
}

vector2_c exp(const vector2_c &A) {
	return _::unary_func(A, std::exp);
}

// log
vector_d log(const vector_d &v) {
	return _::unary_func(v, std::log);
}

vector_c log(const vector_c &v) {
	return _::unary_func(v, std::log);
}

vector2_d log(const vector2_d &A) {
	return _::unary_func(A, std::log);
}

vector2_c log(const vector2_c &A) {
	return _::unary_func(A, std::log);
}

// log10
vector_d log10(const vector_d &v) {
	return _::unary_func(v, std::log10);
}

vector_c log10(const vector_c &v) {
	return _::unary_func(v, std::log10);
}

vector2_d log10(const vector2_d &A) {
	return _::unary_func(A, std::log10);
}

vector2_c log10(const vector2_c &A) {
	return _::unary_func(A, std::log10);
}

// log2
vector_d log2(const vector_d &v) {
	return _::unary_func(v, std::log2);
}

vector_c log2(const vector_c &v) {
	return _::unary_func(v, +[](const complex_d &z){
		return complex_d{std::log2(std::abs(z)), std::arg(z) / std::log(2)};
	});
}

vector2_d log2(const vector2_d &A) {
	return _::unary_func(A, std::log2);
}

vector2_c log2(const vector2_c &A) {
	return _::unary_func(A, +[](const complex_d &z){
		return complex_d{std::log2(std::abs(z)), std::arg(z) / std::log(2)};
	});
}

// pow2
double pow2(double x) {
	return _::pow2(x);
}

complex_d pow2(const complex_d &z) {
	return _::pow2(z);
}

vector_d pow2(const vector_d &v) {
	return _::unary_func(v, _::pow2);
}

vector_c pow2(const vector_c &v) {
	return _::unary_func(v, _::pow2);
}

vector2_d pow2(const vector2_d &A) {
	return _::unary_func(A, _::pow2);
}

vector2_c pow2(const vector2_c &A) {
	return _::unary_func(A, _::pow2);
}

// sqrt
vector_d sqrt(const vector_d &v) {
	return _::unary_func(v, std::sqrt);
}

vector_c sqrt(const vector_c &v) {
	return _::unary_func(v, std::sqrt);
}

vector2_d sqrt(const vector2_d &A) {
	return _::unary_func(A, std::sqrt);
}

vector2_c sqrt(const vector2_c &A) {
	return _::unary_func(A, std::sqrt);
}
#pragma endregion
}
