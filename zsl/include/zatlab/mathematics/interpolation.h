#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include "basics/basics.h"

namespace zsl {
// interp
vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq);
vector_d interp1(const vector_d &x, const vector_d &v, const vector_d &xq, const std::string &method);
}

#endif // !

