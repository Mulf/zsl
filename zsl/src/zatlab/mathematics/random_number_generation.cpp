#include "zatlab/mathematics/random_number_generation.h"
#include "linalg.h"

namespace zsl{
double rand() {
	return alglib::randomreal();
}

}