#ifndef RANDOM_NUMBER_GENERATION_H
#define RANDOM_NUMBER_GENERATION_H

#include "basics/basics.h"

namespace zsl {
double rand();
vector_d rand_v(size_t n);
matrix_d rand(size_t n);
matrix_d rand(size_t n, size_t m);

}

#endif // !RANDOM_NUMBER_GENERATION_H
