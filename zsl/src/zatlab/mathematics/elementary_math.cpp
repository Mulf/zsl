#include "zatlab/mathematics/elementary_math.h"
#include <cmath>
#include <algorithm>

#define DEG_TO_RAD(x)  (x * zsl::pi / 180)

namespace _ {
using namespace zsl;

double deg2rad(double d) {
	return d * pi / 180;
}

vector_d unary_func(const vector_d &x, double (*func)(double)) {
	vector_d y(x.size());
	std::transform(x.begin(), x.end(), y.begin(), [&](double x){
		return func(x);
	});
	return y;
}

vector_d unary_func(const vector_d &x, const UnaryOp &func) {
	vector_d y(x.size());
	std::transform(x.begin(), x.end(), y.begin(), [&](double x){
		return func(x);
	});
	return y;
}


matrix_d unary_func(const matrix_d &X, double (*func)(double)) {
	matrix_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_d& x){
		return unary_func(x, func);
	});
	return Y;
}

matrix_d unary_func(const matrix_d &X, const UnaryOp &func) {
	matrix_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_d &x){
		return unary_func(x, func);
	});
	return Y;
}

}

namespace zsl {
#pragma region Trigonometry
// sine
vector_d sin(const vector_d &v) {
	return _::unary_func(v, std::sin);
}

matrix_d sin(const matrix_d &A) {
	return _::unary_func(A, std::sin);
}

vector_d sind(const vector_d &v) {
	UnaryOp func = [](double x) -> double{
		return std::sin(DEG_TO_RAD(x));
	};
	return _::unary_func(v, func);
}

matrix_d sind(const matrix_d &A) {
	UnaryOp func = [](double x) -> double{
		return std::sin(DEG_TO_RAD(x));
	};
	return _::unary_func(A, func);
}

vector_d sinpi(const vector_d &v) {
	UnaryOp func = [](double x) -> double{
		return std::sin(x * pi);
	};
	return _::unary_func(v, func);
}

matrix_d sinpi(const matrix_d &A) {
	UnaryOp func = [](double x) -> double{
		return std::sin(x * pi);
	};
	return _::unary_func(A, func);
}

vector_d asin(const vector_d &v) {
	return _::unary_func(v, std::asin);
}

matrix_d asin(const matrix_d &A) {
	return _::unary_func(A, std::asin);
}

// cos
vector_d cos(const vector_d &v) {
	return _::unary_func(v, std::cos);
}

matrix_d cos(const matrix_d &A) {
	return _::unary_func(A, std::cos);
}

#pragma endregion
}