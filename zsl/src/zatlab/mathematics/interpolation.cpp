#include "zatlab/mathematics/interpolation.h"
#include "zatlab/data_import_and_analysis/data_process.h"


namespace _ {


//vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq) {
//
//
//}



}

namespace zsl {

vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq) {

	vector_d vq{xq.size(), vector_d::allocator_type{}};

	return vq;
}

vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq, const std::string &method) {
	

	vector_d vq{xq.size(), vector_d::allocator_type{}};
	

	return vq;

}

}