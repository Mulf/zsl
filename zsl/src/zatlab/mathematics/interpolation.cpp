#include "zatlab/mathematics/interpolation.h"
#include "interpolation.h"
#include "linalg.h"

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

//vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq) {
//
//
//}



}

namespace zsl {
using namespace alglib;

vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq) {
	auto xa = _::to_real_1d_array(x);
	auto ya = _::to_real_1d_array(v);
	spline1dinterpolant s{};
	spline1dbuildlinear(xa, ya, s);

	vector_d vq{xq.size(), vector_d::allocator_type{}};
	for(size_t i = 0; i < xq.size(); i++) {
		vq[i] = spline1dcalc(s, xq[i]);
	}

	return vq;
}

vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq, const std::string &method) {
	auto xa = _::to_real_1d_array(x);
	auto ya = _::to_real_1d_array(v);
	spline1dinterpolant s{};

	if(method == "cubic")
	{
		spline1dbuildcubic(xa, ya, s);
	}
	else if(method == "spline") {

	}


	vector_d vq{xq.size(), vector_d::allocator_type{}};
	for(size_t i = 0; i < xq.size(); i++) {
		vq[i] = spline1dcalc(s, xq[i]);
	}

	return vq;

}

}