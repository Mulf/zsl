#include "zatlab/mathematics/elementary_math/trigonometry.h"
#include <cmath>
#include <algorithm>

#define DEG_TO_RAD(x)  (x * zsl::pi / 180.0)
#define RAD_TO_DEG(x)	(x * 180.0 / zsl::pi)

namespace _ {
using namespace zsl;

static vector_d unary_func(const vector_d &x, double (*func)(double)) {
	vector_d y(x.size());
	std::transform(x.begin(), x.end(), y.begin(), [&](double x){
		return func(x);
	});
	return y;
}

static vector_c unary_func(const vector_c &x, complex_d (*func)(const complex_d &)) {
	vector_c y(x.size());
	std::transform(x.begin(), x.end(), y.begin(), [&](const complex_d &x){
		return func(x);
	});
	return y;
}

static vector_d unary_func(const vector_c &x, double (*func)(const complex_d &)) {
	vector_d y(x.size());
	std::transform(x.begin(), x.end(), y.begin(), [&](const complex_d &x){
		return func(x);
	});
	return y;
}

static vector2_d unary_func(const vector2_d &X, double (*func)(double)) {
	vector2_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_d &x){
		return unary_func(x, func);
	});
	return Y;
}

static vector2_c unary_func(const vector2_c &X, complex_d (*func)(const complex_d &)) {
	vector2_c Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_c &x){
		return unary_func(x, func);
	});
	return Y;
}

static vector2_d unary_func(const vector2_c &X, double (*func)(const complex_d &)) {
	vector2_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_c &x){
		return unary_func(x, func);
	});
	return Y;
}
}

namespace zsl {
#pragma region Trigonometry
// sin
vector_d sin(const vector_d &v) {
	return _::unary_func(v, std::sin);
}

vector_c sin(const vector_c &v) {
	return _::unary_func(v, std::sin);
}

vector2_d sin(const vector2_d &A) {
	return _::unary_func(A, std::sin);
}

vector2_c sin(const vector2_c &A) {
	return _::unary_func(A, std::sin);
}

vector_d sind(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return std::sin(DEG_TO_RAD(x));
	});
}

vector_c sind(const vector_c &v) {
	return _::unary_func(v, +[](const complex_d &x) {
		return std::sin(DEG_TO_RAD(x));
	});
}

vector2_d sind(const vector2_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::sin(DEG_TO_RAD(x));
	});
}

vector2_c sind(const vector2_c &A) {
	return _::unary_func(A, +[](const complex_d &x) {
		return std::sin(DEG_TO_RAD(x));
	});
}

vector_d sinpi(const vector_d &v) {
	return _::unary_func(v, +[](double x) -> double{
		return std::sin(x * pi);
	});
}

vector_c sinpi(const vector_c &v) {
	return _::unary_func(v, +[](const complex_d &x) {
		return std::sin(x * pi);
	});
}

vector2_d sinpi(const vector2_d &A) {
	return _::unary_func(A, +[](double x){
		return std::sin(x * pi);
	});
}

vector2_c sinpi(const vector2_c &A) {
	return _::unary_func(A, +[](const complex_d &x){
		return std::sin(x * pi);
	});
}

vector_d asin(const vector_d &v) {
	return _::unary_func(v, std::asin);
}

vector_c asin(const vector_c &v) {
	return _::unary_func(v, std::asin);
}

vector2_d asin(const vector2_d &A) {
	return _::unary_func(A, std::asin);
}

vector2_c asin(const vector2_c &A) {
	return _::unary_func(A, std::asin);
}

vector_d sinh(const vector_d &v) {
	return _::unary_func(v, std::sinh);
}

vector_c sinh(const vector_c &v) {
	return _::unary_func(v, std::sinh);
}

vector2_d sinh(const vector2_d &A) {
	return _::unary_func(A, std::sinh);
}

vector2_c sinh(const vector2_c &A) {
	return _::unary_func(A, std::sinh);
}

vector_d asinh(const vector_d &v) {
	return _::unary_func(v, std::asinh);
}

vector_c asinh(const vector_c &A) {
	return _::unary_func(A, std::asinh);
}


vector2_d asinh(const vector2_d &A) {
	return _::unary_func(A, std::asinh);
}

vector2_c asinh(const vector2_c &A) {
	return _::unary_func(A, std::asinh);
}

// cos
vector_d cos(const vector_d &v) {
	return _::unary_func(v, std::cos);
}

vector_c cos(const vector_c &v) {
	return _::unary_func(v, std::cos);
}

vector2_d cos(const vector2_d &A) {
	return _::unary_func(A, std::cos);
}

vector2_c cos(const vector2_c &A) {
	return _::unary_func(A, std::cos);
}

vector_d cosd(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return std::cos(DEG_TO_RAD(x));
	});
}

vector_c cosd(const vector_c &v) {
	return _::unary_func(v, +[](const complex_d &x) {
		return std::cos(DEG_TO_RAD(x));
	});
}

vector2_d cosd(const vector2_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::cos(DEG_TO_RAD(x));
	});
}

vector2_c cosd(const vector2_c &A) {
	return _::unary_func(A, +[](const complex_d &x) {
		return std::cos(DEG_TO_RAD(x));
	});
}

vector_d cospi(const vector_d &v) {
	return _::unary_func(v, +[](double x) -> double{
		return std::cos(x * pi);
	});
}

vector_c cospi(const vector_c &v) {
	return _::unary_func(v, +[](const complex_d &x) {
		return std::cos(x * pi);
	});
}

vector2_d cospi(const vector2_d &A) {
	return _::unary_func(A, +[](double x){
		return std::cos(x * pi);
	});
}

vector2_c cospi(const vector2_c &A) {
	return _::unary_func(A, +[](const complex_d &x){
		return std::cos(x * pi);
	});
}

vector_d acos(const vector_d &v) {
	return _::unary_func(v, std::acos);
}

vector_c acos(const vector_c &v) {
	return _::unary_func(v, std::acos);
}

vector2_d acos(const vector2_d &A) {
	return _::unary_func(A, std::acos);
}

vector2_c acos(const vector2_c &A) {
	return _::unary_func(A, std::acos);
}

vector_d cosh(const vector_d &v) {
	return _::unary_func(v, std::cosh);
}

vector_c cosh(const vector_c &v) {
	return _::unary_func(v, std::cosh);
}

vector2_d cosh(const vector2_d &A) {
	return _::unary_func(A, std::cosh);
}

vector2_c cosh(const vector2_c &A) {
	return _::unary_func(A, std::cosh);
}

vector_d acosh(const vector_d &v) {
	return _::unary_func(v, std::acosh);
}

vector_c acosh(const vector_c &A) {
	return _::unary_func(A, std::acosh);
}

vector2_d acosh(const vector2_d &A) {
	return _::unary_func(A, std::acosh);
}

vector2_c acosh(const vector2_c &A) {
	return _::unary_func(A, std::acosh);
}

// tan
vector_d tan(const vector_d &v) {
	return _::unary_func(v, std::tan);
}

vector_c tan(const vector_c &v) {
	return _::unary_func(v, std::tan);
}

vector2_d tan(const vector2_d &A) {
	return _::unary_func(A, std::tan);
}

vector2_c tan(const vector2_c &A) {
	return _::unary_func(A, std::tan);
}

vector_d tand(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return std::tan(DEG_TO_RAD(x));
	});
}

vector_c tand(const vector_c &v) {
	return _::unary_func(v, +[](const complex_d &x) {
		return std::tan(DEG_TO_RAD(x));
	});
}

vector2_d tand(const vector2_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::tan(DEG_TO_RAD(x));
	});
}

vector2_c tand(const vector2_c &A) {
	return _::unary_func(A, +[](const complex_d &x) {
		return std::tan(DEG_TO_RAD(x));
	});
}

vector_d tanpi(const vector_d &v) {
	return _::unary_func(v, +[](double x) -> double{
		return std::tan(x * pi);
	});
}

vector_c tanpi(const vector_c &v) {
	return _::unary_func(v, +[](const complex_d &x) {
		return std::tan(x * pi);
	});
}

vector2_d tanpi(const vector2_d &A) {
	return _::unary_func(A, +[](double x){
		return std::tan(x * pi);
	});
}

vector2_c tanpi(const vector2_c &A) {
	return _::unary_func(A, +[](const complex_d &x){
		return std::tan(x * pi);
	});
}

vector_d atan(const vector_d &v) {
	return _::unary_func(v, std::atan);
}

vector_c atan(const vector_c &v) {
	return _::unary_func(v, std::atan);
}

vector2_d atan(const vector2_d &A) {
	return _::unary_func(A, std::atan);
}

vector2_c atan(const vector2_c &A) {
	return _::unary_func(A, std::atan);
}

vector_d tanh(const vector_d &v) {
	return _::unary_func(v, std::tanh);
}

vector_c tanh(const vector_c &v) {
	return _::unary_func(v, std::tanh);
}

vector2_d tanh(const vector2_d &A) {
	return _::unary_func(A, std::tanh);
}

vector2_c tanh(const vector2_c &A) {
	return _::unary_func(A, std::tanh);
}

vector_d atanh(const vector_d &v) {
	return _::unary_func(v, std::atanh);
}

vector_c atanh(const vector_c &A) {
	return _::unary_func(A, std::atanh);
}


vector2_d atanh(const vector2_d &A) {
	return _::unary_func(A, std::atanh);
}

vector2_c atanh(const vector2_c &A) {
	return _::unary_func(A, std::atanh);
}


// csc
vector_d csc(const vector_d &v) {
	return _::unary_func(v, +[](double x){ return 1 / std::sin(x); });
}

vector2_d csc(const vector2_d &A) {
	return  _::unary_func(A, +[](double x){ return 1 / std::sin(x); });
}

vector_d cscd(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return 1 / std::sin(DEG_TO_RAD(x));
	});
}

vector2_d cscd(const vector2_d &A) {
	return _::unary_func(A, +[](double x) {
		return 1 / std::sin(DEG_TO_RAD(x));
	});
}

vector_d acsc(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return std::asin(1 / x); });
}

vector2_d acsc(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return std::asin(1 / x); });
}

vector_d acscd(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return std::asin(1 / DEG_TO_RAD(x)); });
}

vector2_d acscd(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return std::asin(1 / DEG_TO_RAD(x)); });
}

vector_d csch(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return 1 / std::sinh(x); });
}

vector2_d csch(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return 1 / std::sinh(x); });
}

vector_d acsch(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){
		return std::log(1 / x + std::sqrt(1 / (x * x) + 1));
	});
}

vector2_d acsch(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){
		return std::log(1 / x + std::sqrt(1 / (x * x) + 1));
	});
}

// sec
vector_d sec(const vector_d &v) {
	return _::unary_func(v, +[](double x){ return 1 / std::cos(x); });
}

vector2_d sec(const vector2_d &A) {
	return  _::unary_func(A, +[](double x){ return 1 / std::cos(x); });
}

vector_d secd(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return 1 / std::cos(DEG_TO_RAD(x));
	});
}

vector2_d secd(const vector2_d &A) {
	return _::unary_func(A, +[](double x) {
		return 1 / std::cos(DEG_TO_RAD(x));
	});
}

vector_d asec(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return std::acos(1 / x); });
}

vector2_d asec(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return std::acos(1 / x); });
}

vector_d asecd(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return std::acos(1 / DEG_TO_RAD(x)); });
}

vector2_d asecd(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return std::acos(1 / DEG_TO_RAD(x)); });
}

vector_d sech(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return 1 / std::cosh(x); });
}

vector2_d sech(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return 1 / std::cosh(x); });
}

vector_d asech(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){
		return std::log(1 / x + std::sqrt(1 / (x * x) + 1));
	});
}

vector2_d asech(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){
		return std::log(1 / x + std::sqrt(1 / (x * x) - 1));
	});
}


// cot
vector_d cot(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return 1 / std::tan(x); });
}

vector2_d cot(const vector2_d &A) {
	expect_no_zero(A);

	return  _::unary_func(A, +[](double x){ return 1 / std::tan(x); });
}

vector_d cotd(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x) {
		return 1 / std::tan(DEG_TO_RAD(x));
	});
}

vector2_d cotd(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x) {
		return 1 / std::tan(DEG_TO_RAD(x));
	});
}

vector_d acot(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return std::atan(1 / x); });
}

vector2_d acot(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return std::atan(1 / x); });
}

vector_d acotd(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return std::atan(1 / DEG_TO_RAD(x)); });
}

vector2_d acotd(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return std::atan(1 / DEG_TO_RAD(x)); });
}

vector_d coth(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){ return 1 / std::tanh(x); });
}

vector2_d coth(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){ return 1 / std::tanh(x); });
}

vector_d acoth(const vector_d &v) {
	expect_no_zero(v);

	return _::unary_func(v, +[](double x){
		return 0.5 * std::log((x + 1) / (x - 1));
	});
}

vector2_d acoth(const vector2_d &A) {
	expect_no_zero(A);

	return _::unary_func(A, +[](double x){
		return 0.5 * std::log((x + 1) / (x - 1));
	});
}

double deg2rad(double x) {
	return DEG_TO_RAD(x);
}

vector_d deg2rad(const vector_d &v) {
	vector_d w(v.size());
	for(size_t i = 0; i < v.size(); i++) {
		w[i] = DEG_TO_RAD(v[i]);
	}
	return w;
}

vector2_d deg2rad(const vector2_d &A) {
	vector2_d B(A.size());
	for(auto &v : A) {
		for(size_t i = 0; i < A.size(); i++) {
			B[i] = deg2rad(A[i]);
		}
	}
	return B;
}

double rad2deg(double x) {
	return RAD_TO_DEG(x);
}

vector_d rad2deg(const vector_d &v) {
	vector_d w(v.size());
	for(size_t i = 0; i < v.size(); i++) {
		w[i] = RAD_TO_DEG(v[i]);
	}
	return w;
}

vector2_d rad2deg(const vector2_d &A) {
	vector2_d B(A.size());
	for(auto &v : A) {
		for(size_t i = 0; i < A.size(); i++) {
			B[i] = rad2deg(A[i]);
		}
	}
	return B;
}

#pragma endregion

}

