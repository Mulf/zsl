#ifndef ZSL_BASICS_STD_VECTOR_OP_H
#define ZSL_BASICS_STD_VECTOR_OP_H

#include <vector>
#include "defines.h"

namespace zsl
{

	vector_d vadd(const vector_d& v1, const vector_d& v2);
	vector_d vadd(const vector_d& v, double a);
	vector_d vadd(double a, const vector_d& v);
	vector_d vsub(const vector_d& v1, const vector_d& v2);
	vector_d vsub(const vector_d& v, double a);
	vector_d vsub(double a, const vector_d& v);
	vector_d vmul(const vector_d& v1, const vector_d& v2);
	vector_d vmul(const vector_d& v, double a);
	vector_d vmul(double a, const vector_d& v);
	vector_d vdiv(const vector_d& v1, const vector_d& v2);
	vector_d vdiv(const vector_d& v, double a);
	vector_d vdiv(double a, const vector_d& v);

	void vadd_self(vector_d& v, const vector_d& w);
	void vadd_self(vector_d& v, double a);
	void vsub_self(vector_d& v, const vector_d& w);
	void vsub_self(vector_d& v, double a);
	void vmul_self(vector_d& v, const vector_d& w);
	void vmul_self(vector_d& v, double a);
	void vdiv_self(vector_d& v, const vector_d& w);
	void vdiv_self(vector_d& v, double a);

	matrix_d madd(const matrix_d& m1, const matrix_d& m2);
	matrix_d madd(const matrix_d& m, const vector_d& v);
	matrix_d madd(const vector_d& v, const matrix_d& m);
	matrix_d madd(const matrix_d& m, double d);
	matrix_d madd(double d, const matrix_d& m);
	void madd_self(matrix_d& m1, const matrix_d& m2);
	void madd_self(matrix_d& m, const vector_d& v);
	void madd_self(matrix_d& m, double d);

	matrix_d msub(const matrix_d& m1, const matrix_d& m2);
	matrix_d msub(const matrix_d& m, const vector_d& v);
	matrix_d msub(const vector_d& m, const matrix_d& v);
	matrix_d msub(const matrix_d& m, double d);
	matrix_d msub(double d, const matrix_d& m);
	void msub_self(matrix_d& m1, const matrix_d& m2);
	void msub_self(matrix_d& m, const vector_d& v);
	void msub_self(matrix_d& m, double d);
}

zsl::vector_d operator+(const zsl::vector_d& v1, const zsl::vector_d& v2);
zsl::vector_d operator+(const zsl::vector_d& v, double a);
zsl::vector_d operator+(double a, const zsl::vector_d& v);
zsl::vector_d operator-(const zsl::vector_d& v1, const zsl::vector_d& v2);
zsl::vector_d operator-(const zsl::vector_d& v, double a);
zsl::vector_d operator-(double a, const zsl::vector_d& v);
zsl::vector_d operator*(const zsl::vector_d& v1, const zsl::vector_d& v2);
zsl::vector_d operator*(const zsl::vector_d& v, double a);
zsl::vector_d operator*(double a, const zsl::vector_d& v);
zsl::vector_d operator/(const zsl::vector_d& v1, const zsl::vector_d& v2);
zsl::vector_d operator/(const zsl::vector_d& v, double a);
zsl::vector_d operator/(double a, const zsl::vector_d& v);

void operator+=(zsl::vector_d& v, const zsl::vector_d& w);
void operator+=(zsl::vector_d& v, double a);
void operator-=(zsl::vector_d& v, const zsl::vector_d& w);
void operator-=(zsl::vector_d& v, double a);
void operator*=(zsl::vector_d& v, const zsl::vector_d& w);
void operator*=(zsl::vector_d& v, double a);
void operator/=(zsl::vector_d& v, const zsl::vector_d& w);
void operator/=(zsl::vector_d& v, double a);

zsl::matrix_d operator+(const zsl::matrix_d& m1, const zsl::matrix_d& m2);
zsl::matrix_d operator+(const zsl::matrix_d& m, const zsl::vector_d& v);
zsl::matrix_d operator+(const zsl::vector_d& m, const zsl::matrix_d& v);
zsl::matrix_d operator+(const zsl::matrix_d& m, double d);
zsl::matrix_d operator+(double d, const zsl::matrix_d& m);
void operator+=(zsl::matrix_d& m1, const zsl::matrix_d& m2);
void operator+=(zsl::matrix_d& m, const zsl::vector_d& v);
void operator+=(zsl::matrix_d& m, double d);

zsl::matrix_d operator-(const zsl::matrix_d& m1, const zsl::matrix_d& m2);
zsl::matrix_d operator-(const zsl::matrix_d& m, const zsl::vector_d& v);
zsl::matrix_d operator-(const zsl::vector_d& m, const zsl::matrix_d& v);
zsl::matrix_d operator-(const zsl::matrix_d& m, double d);
zsl::matrix_d operator-(double d, const zsl::matrix_d& m);
void operator-=(zsl::matrix_d& m1, const zsl::matrix_d& m2);
void operator-=(zsl::matrix_d& m, const zsl::vector_d& v);
void operator-=(zsl::matrix_d& m, double d);


#endif // !ZSL_STD_VECTOR_OP_H
