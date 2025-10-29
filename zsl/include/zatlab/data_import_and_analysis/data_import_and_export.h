#ifndef DATA_IMPORT_AND_EXPORT_H
#define DATA_IMPORT_AND_EXPORT_H

#include "basics/basics.h"

namespace zsl {

vector_d readvector(const std::string &filename);
vector2_d readmatrix(const std::string &filename);

void writevector(const vector_d &v, const std::string &filename);
void writematrix(const vector2_d &A, const std::string &filename);

} // namespace zsl

#endif // !DATA_IMPORT_AND_EXPORT_H
