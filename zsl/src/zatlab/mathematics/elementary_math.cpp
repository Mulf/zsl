#include "zatlab/mathematics/elementary_math.h"
#include <cmath>
#include <algorithm>

#define DEG_TO_RAD(x)  (x * zsl::pi / 180.0)
#define RAD_TO_DEG(x)	(x * 180.0 / zsl::pi)




namespace _ {
using namespace zsl;

static inline double pow2(double x) {
	return std::pow(2, x);
}

static inline complex_d pow2(const complex_d &z) {
	return std::pow(2, z);
}

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

matrix_d unary_func(const matrix_d &X, double (*func)(double)) {
	matrix_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_d& x){
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

matrix_d sin(const matrix_d &A) {
	return _::unary_func(A, std::sin);
}

matrix_c sin(const matrix_c &A) {
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

matrix_d sind(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::sin(DEG_TO_RAD(x));
	});
}

matrix_c sind(const matrix_c &A) {
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

matrix_d sinpi(const matrix_d &A) {
	return _::unary_func(A, +[](double x){
		return std::sin(x * pi);
	});
}

matrix_c sinpi(const matrix_c &A) {
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

matrix_d asin(const matrix_d &A) {
	return _::unary_func(A, std::asin);
}

matrix_c asin(const matrix_c &A) {
	return _::unary_func(A, std::asin);
}

vector_d sinh(const vector_d &v) {
	return _::unary_func(v, std::sinh);
}

vector_c sinh(const vector_c &v) {
	return _::unary_func(v, std::sinh);
}

matrix_d sinh(const matrix_d &A) {
	return _::unary_func(A, std::sinh);
}

matrix_c sinh(const matrix_c &A) {
	return _::unary_func(A, std::sinh);
}

vector_d asinh(const vector_d &v) {
	return _::unary_func(v, std::asinh);
}

vector_c asinh(const vector_c &A) {
	return _::unary_func(A, std::asinh);
}


matrix_d asinh(const matrix_d &A) {
	return _::unary_func(A, std::asinh);
}

matrix_c asinh(const matrix_c &A) {
	return _::unary_func(A, std::asinh);
}

// cos
vector_d cos(const vector_d &v) {
	return _::unary_func(v, std::cos);
}

vector_c cos(const vector_c &v) {
	return _::unary_func(v, std::cos);
}

matrix_d cos(const matrix_d &A) {
	return _::unary_func(A, std::cos);
}

matrix_c cos(const matrix_c &A) {
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

matrix_d cosd(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::cos(DEG_TO_RAD(x));
	});
}

matrix_c cosd(const matrix_c &A) {
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

matrix_d cospi(const matrix_d &A) {
	return _::unary_func(A, +[](double x){
		return std::cos(x * pi);
	});
}

matrix_c cospi(const matrix_c &A) {
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

matrix_d acos(const matrix_d &A) {
	return _::unary_func(A, std::acos);
}

matrix_c acos(const matrix_c &A) {
	return _::unary_func(A, std::acos);
}

vector_d cosh(const vector_d &v) {
	return _::unary_func(v, std::cosh);
}

vector_c cosh(const vector_c &v) {
	return _::unary_func(v, std::cosh);
}

matrix_d cosh(const matrix_d &A) {
	return _::unary_func(A, std::cosh);
}

matrix_c cosh(const matrix_c &A) {
	return _::unary_func(A, std::cosh);
}

vector_d acosh(const vector_d &v) {
	return _::unary_func(v, std::acosh);
}

vector_c acosh(const vector_c &A) {
	return _::unary_func(A, std::acosh);
}

matrix_d acosh(const matrix_d &A) {
	return _::unary_func(A, std::acosh);
}

matrix_c acosh(const matrix_c &A) {
	return _::unary_func(A, std::acosh);
}

// tan
vector_d tan(const vector_d &v) {
	return _::unary_func(v, std::tan);
}

vector_c tan(const vector_c &v) {
	return _::unary_func(v, std::tan);
}

matrix_d tan(const matrix_d &A) {
	return _::unary_func(A, std::tan);
}

matrix_c tan(const matrix_c &A) {
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

matrix_d tand(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::tan(DEG_TO_RAD(x));
	});
}

matrix_c tand(const matrix_c &A) {
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

matrix_d tanpi(const matrix_d &A) {
	return _::unary_func(A, +[](double x){
		return std::tan(x * pi);
	});
}

matrix_c tanpi(const matrix_c &A) {
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

matrix_d atan(const matrix_d &A) {
	return _::unary_func(A, std::atan);
}

matrix_c atan(const matrix_c &A) {
	return _::unary_func(A, std::atan);
}

vector_d tanh(const vector_d &v) {
	return _::unary_func(v, std::tanh);
}

vector_c tanh(const vector_c &v) {
	return _::unary_func(v, std::tanh);
}

matrix_d tanh(const matrix_d &A) {
	return _::unary_func(A, std::tanh);
}

matrix_c tanh(const matrix_c &A) {
	return _::unary_func(A, std::tanh);
}

vector_d atanh(const vector_d &v) {
	return _::unary_func(v, std::atanh);
}

vector_c atanh(const vector_c &A) {
	return _::unary_func(A, std::atanh);
}


matrix_d atanh(const matrix_d &A) {
	return _::unary_func(A, std::atanh);
}

matrix_c atanh(const matrix_c &A) {
	return _::unary_func(A, std::atanh);
}


// csc
vector_d csc(const vector_d &v) {
	return _::unary_func(v, +[](double x){ return 1 / std::sin(x); });
}

matrix_d csc(const matrix_d &A) {
	return  _::unary_func(A, +[](double x){ return 1 / std::sin(x); });
}

vector_d cscd(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return 1 / std::sin(DEG_TO_RAD(x));
	});
}

matrix_d cscd(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return 1 / std::sin(DEG_TO_RAD(x));
	});
}

vector_d acsc(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acsc not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return std::asin(1 / x); });
}

matrix_d acsc(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acsc not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return std::asin(1 / x); });
}

vector_d acscd(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acscd not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return std::asin(1 / DEG_TO_RAD(x)); });
}

matrix_d acscd(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acscd not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return std::asin(1 / DEG_TO_RAD(x)); });
}

vector_d csch(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function csch not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return 1 / std::sinh(x); });
}

matrix_d csch(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function csch not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return 1 / std::sinh(x); });
}

vector_d acsch(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acsch not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){
		return std::log(1 / x + std::sqrt(1 / (x * x) + 1));
	});
}

matrix_d acsch(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function csch not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){
		return std::log(1 / x + std::sqrt(1 / (x * x) + 1));
	});
}

// sec
vector_d sec(const vector_d &v) {
	return _::unary_func(v, +[](double x){ return 1 / std::cos(x); });
}

matrix_d sec(const matrix_d &A) {
	return  _::unary_func(A, +[](double x){ return 1 / std::cos(x); });
}

vector_d secd(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return 1 / std::cos(DEG_TO_RAD(x));
	});
}

matrix_d secd(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return 1 / std::cos(DEG_TO_RAD(x));
	});
}

vector_d asec(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function asec not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return std::acos(1 / x); });
}

matrix_d asec(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function asec not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return std::acos(1 / x); });
}

vector_d asecd(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function asecd not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return std::acos(1 / DEG_TO_RAD(x)); });
}

matrix_d asecd(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function asecd not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return std::acos(1 / DEG_TO_RAD(x)); });
}

vector_d sech(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function sech not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return 1 / std::cosh(x); });
}

matrix_d sech(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function sech not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return 1 / std::cosh(x); });
}

vector_d asech(const vector_d &v) {
	for(auto x : v) {
		if(x <= 0 || x > 1) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function asech not defined out of (0, 1]");
		}
	}

	return _::unary_func(v, +[](double x){
		return std::log(1 / x + std::sqrt(1 / (x * x) + 1));
	});
}

matrix_d asech(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x <= 0 || x > 1) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function sech not define out of (0, 1]");
			}
		}
	}

	return _::unary_func(A, +[](double x){
		return std::log(1 / x + std::sqrt(1 / (x * x) - 1));
	});
}


// cot
vector_d cot(const vector_d &v) {
	return _::unary_func(v, +[](double x){ return 1 / std::tan(x); });
}

matrix_d cot(const matrix_d &A) {
	return  _::unary_func(A, +[](double x){ return 1 / std::tan(x); });
}

vector_d cotd(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return 1 / std::tan(DEG_TO_RAD(x));
	});
}

matrix_d cotd(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return 1 / std::tan(DEG_TO_RAD(x));
	});
}

vector_d acot(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acot not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return std::atan(1 / x); });
}

matrix_d acot(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acot not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return std::atan(1 / x); });
}

vector_d acotd(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acotd not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return std::atan(1 / DEG_TO_RAD(x)); });
}

matrix_d acotd(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acotd not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return std::atan(1 / DEG_TO_RAD(x)); });
}

vector_d coth(const vector_d &v) {
	for(auto x : v) {
		if(x == 0) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function coth not defined at 0");
		}
	}

	return _::unary_func(v, +[](double x){ return 1 / std::tanh(x); });
}

matrix_d coth(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(x == 0) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function coth not define at 0");
			}
		}
	}

	return _::unary_func(A, +[](double x){ return 1 / std::tanh(x); });
}

vector_d acoth(const vector_d &v) {
	for(auto x : v) {
		if(-1 <= x && x <= 1) {
			Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function acoth not defined in [-1, 1]");
		}
	}

	return _::unary_func(v, +[](double x){
		return 0.5 * std::log((x + 1) / (x - 1));
	});
}

matrix_d acoth(const matrix_d &A) {
	for(auto &v : A) {
		for(auto x : v) {
			if(-1 <= x && x <= 1) {
				Z_THROW(ZErrorCode::MATH_ZERO_DIVISOR, "Function coth not define in [-1, 1]");
			}
		}
	}

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

matrix_d deg2rad(const matrix_d &A) {
	matrix_d B(A.size());
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

matrix_d rad2deg(const matrix_d &A) {
	matrix_d B(A.size());
	for(auto &v : A) {
		for(size_t i = 0; i < A.size(); i++) {
			B[i] = rad2deg(A[i]);
		}
	}
	return B;
}

#pragma endregion

#pragma region  Exponents and Logarithms
// exp
vector_d exp(const vector_d &v) {
	return _::unary_func(v, std::exp);
}

vector_c exp(const vector_c &v) {
	return _::unary_func(v, std::exp);
}

matrix_d exp(const matrix_d &A) {
	return _::unary_func(A, std::exp);
}

matrix_c exp(const matrix_c &A) {
	return _::unary_func(A, std::exp);
}

// log
vector_d log(const vector_d &v) {
	return _::unary_func(v, std::log);
}

vector_c log(const vector_c &v) {
	return _::unary_func(v, std::log);
}

matrix_d log(const matrix_d &A) {
	return _::unary_func(A, std::log);
}

matrix_c log(const matrix_c &A) {
	return _::unary_func(A, std::log);
}

// log10
vector_d log10(const vector_d &v) {
	return _::unary_func(v, std::log10);
}

vector_c log10(const vector_c &v) {
	return _::unary_func(v, std::log10);
}

matrix_d log10(const matrix_d &A) {
	return _::unary_func(A, std::log10);
}

matrix_c log10(const matrix_c &A) {
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

matrix_d log2(const matrix_d &A) {
	return _::unary_func(A, std::log2);
}

matrix_c log2(const matrix_c &A) {
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

matrix_d pow2(const matrix_d &A) {
	return _::unary_func(A, _::pow2);
}

matrix_c pow2(const matrix_c &A) {
	return _::unary_func(A, _::pow2);
}

// sqrt
vector_d sqrt(const vector_d &v) {
	return _::unary_func(v, std::sqrt);
}

vector_c sqrt(const vector_c &v) {
	return _::unary_func(v, std::sqrt);
}

matrix_d sqrt(const matrix_d &A) {
	return _::unary_func(A, std::sqrt);
}

matrix_c sqrt(const matrix_c &A) {
	return _::unary_func(A, std::sqrt);
}
#pragma endregion
}