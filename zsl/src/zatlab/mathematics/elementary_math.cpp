#include "zatlab/mathematics/elementary_math.h"
#include <cmath>
#include <algorithm>

#define DEG_TO_RAD(x)  (x * zsl::pi / 180)
#define RAD_TO_DEG(x)	(x * 180 / zsl::pi)

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

//vector_d unary_func(const vector_d &x, const UnaryOp &func) {
//	vector_d y(x.size());
//	std::transform(x.begin(), x.end(), y.begin(), [&](double x){
//		return func(x);
//	});
//	return y;
//}


matrix_d unary_func(const matrix_d &X, double (*func)(double)) {
	matrix_d Y(X.size());
	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_d& x){
		return unary_func(x, func);
	});
	return Y;
}

//matrix_d unary_func(const matrix_d &X, const UnaryOp &func) {
//	matrix_d Y(X.size());
//	std::transform(X.begin(), X.end(), Y.begin(), [&](const vector_d &x){
//		return unary_func(x, func);
//	});
//	return Y;
//}

}

namespace zsl {
#pragma region Trigonometry
// sin
vector_d sin(const vector_d &v) {
	return _::unary_func(v, std::sin);
}

matrix_d sin(const matrix_d &A) {
	return _::unary_func(A, std::sin);
}

vector_d sind(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return std::sin(DEG_TO_RAD(x));
	});
}

matrix_d sind(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::sin(DEG_TO_RAD(x));
	});
}

vector_d sinpi(const vector_d &v) {
	return _::unary_func(v, +[](double x) -> double{
		return std::sin(x * pi);
	});
}

matrix_d sinpi(const matrix_d &A) {
	return _::unary_func(A, +[](double x){
		return std::sin(x * pi);
	});
}

vector_d asin(const vector_d &v) {
	return _::unary_func(v, std::asin);
}

matrix_d asin(const matrix_d &A) {
	return _::unary_func(A, std::asin);
}

vector_d sinh(const vector_d &v) {
	return _::unary_func(v, std::sinh);
}

matrix_d sinh(const matrix_d &A) {
	return _::unary_func(A, std::sinh);
}

vector_d asinh(const vector_d &v) {
	return _::unary_func(v, std::asinh);
}

matrix_d asinh(const matrix_d &A) {
	return _::unary_func(A, std::asinh);
}

// cos
vector_d cos(const vector_d &v) {
	return _::unary_func(v, std::cos);
}

matrix_d cos(const matrix_d &A) {
	return _::unary_func(A, std::cos);
}

vector_d cosd(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return std::cos(DEG_TO_RAD(x));
	});
}

matrix_d cosd(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::cos(DEG_TO_RAD(x));
	});
}

vector_d cospi(const vector_d &v) {
	return _::unary_func(v, +[](double x) -> double{
		return std::cos(x * pi);
	});
}

matrix_d cospi(const matrix_d &A) {
	return _::unary_func(A, +[](double x){
		return std::cos(x * pi);
	});
}

vector_d acos(const vector_d &v) {
	return _::unary_func(v, std::acos);
}

matrix_d acos(const matrix_d &A) {
	return _::unary_func(A, std::acos);
}

vector_d cosh(const vector_d &v) {
	return _::unary_func(v, std::cosh);
}

matrix_d cosh(const matrix_d &A) {
	return _::unary_func(A, std::cosh);
}

vector_d acosh(const vector_d &v) {
	return _::unary_func(v, std::acosh);
}

matrix_d acosh(const matrix_d &A) {
	return _::unary_func(A, std::acosh);
}

// tan
vector_d tan(const vector_d &v) {
	return _::unary_func(v, std::tan);
}

matrix_d tan(const matrix_d &A) {
	return _::unary_func(A, std::tan);
}

vector_d tand(const vector_d &v) {
	return _::unary_func(v, +[](double x) {
		return std::tan(DEG_TO_RAD(x));
	});
}

matrix_d tand(const matrix_d &A) {
	return _::unary_func(A, +[](double x) {
		return std::tan(DEG_TO_RAD(x));
	});
}

vector_d tanpi(const vector_d &v) {
	return _::unary_func(v, +[](double x) -> double{
		return std::tan(x * pi);
	});
}

matrix_d tanpi(const matrix_d &A) {
	return _::unary_func(A, +[](double x){
		return std::tan(x * pi);
	});
}

vector_d atan(const vector_d &v) {
	return _::unary_func(v, std::atan);
}

matrix_d atan(const matrix_d &A) {
	return _::unary_func(A, std::atan);
}

vector_d tanh(const vector_d &v) {
	return _::unary_func(v, std::tanh);
}

matrix_d tanh(const matrix_d &A) {
	return _::unary_func(A, std::tanh);
}

vector_d atanh(const vector_d &v) {
	return _::unary_func(v, std::atanh);
}

matrix_d atanh(const matrix_d &A) {
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
		return std::log(1 / x + sqrt(1 / (x * x) + 1));
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
		return std::log(1 / x + sqrt(1 / (x * x) + 1));
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
		return std::log(1 / x + sqrt(1 / (x * x) + 1));
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
		return std::log(1 / x + sqrt(1 / (x * x) - 1));
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
}