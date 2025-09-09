#include "zatlab/mathematics/interpolation.h"
#include "zatlab/data_import_and_analysis/data_process.h"

#include <gsl/gsl_errno.h>
#include <gsl/gsl_spline.h>

namespace _ {
using namespace zsl;

vector_d interp(const vector_d &x, const vector_d &v, const vector_d &xq, const gsl_interp_type *type) {
	gsl_interp_accel *acc = gsl_interp_accel_alloc();
	gsl_spline *spline = gsl_spline_alloc(type, x.size());
	gsl_spline_init(spline, x.data(), v.data(), x.size());

	vector_d vq{xq.size(), vector_d::allocator_type{}};
	for(size_t i = 0; i < xq.size(); i++) {
		vq[i] = gsl_spline_eval(spline, xq[i], acc);
	}
	gsl_spline_free(spline);
	gsl_interp_accel_free(acc);

	return vq;
}



}

namespace zsl {


vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq, const std::string &method) {
	vector_d vq{};

	if(method == "linear") {
		vq = interp1(x, v, xq);
	}
	else if(method == "cspline") {
		vq = cspline(x, v, xq);
	}

	return vq;

}

vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq) {
	assert(x.size() == v.size());
	return _::interp(x, v, xq, gsl_interp_linear);
}


vector_d cspline(const vector_d &x, const vector_d &v, const vector_d &xq) {
	assert(x.size() == v.size());
	return _::interp(x, v, xq, gsl_interp_cspline);
}

// akima
vector_d akima(const vector_d &x, const vector_d &v, const vector_d &xq) {
	assert(x.size() == v.size());
	return _::interp(x, v, xq, gsl_interp_akima);
}

}