#ifndef ZSL_BASICS_STD_VECTOR_OP_H
#define ZSL_BASICS_STD_VECTOR_OP_H

#include <vector>
#include "defines.h"

namespace zsl
{
	vector_d  vadd(const vector_d& v1, const vector_d& v2);
	vector_d  vadd(const vector_d& v, double a);
	vector_d  vadd(double a, const vector_d& v);
	vector_d  vsub(const vector_d& v1, const vector_d& v2);
	vector_d  vsub(const vector_d& v, double a);
	vector_d  vsub(double a, const vector_d& v);
	vector_d  vmul(const vector_d& v1, const vector_d& v2);
	vector_d  vmul(const vector_d& v, double a);
	vector_d  vmul(double a, const vector_d& v);
	vector_d  vdiv(const vector_d& v1, const vector_d& v2);
	vector_d  vdiv(const vector_d& v, double a);
	vector_d  vdiv(double a, const vector_d& v);

	void vadd_self(vector_d& v, const vector_d& w);
	void vadd_self(vector_d& v, double a);
	void vsub_self(vector_d& v, const vector_d& w);
	void vsub_self(vector_d& v, double a);
	void vmul_self(vector_d& v, const vector_d& w);
	void vmul_self(vector_d& v, double a);
	void vdiv_self(vector_d& v, const vector_d& w);
	void vdiv_self(vector_d& v, double a);


}

zsl::vector_d  operator+(const zsl::vector_d& v1, const zsl::vector_d& v2);
zsl::vector_d  operator+(const zsl::vector_d& v, double a);
zsl::vector_d  operator+(double a, const zsl::vector_d& v);
zsl::vector_d  operator-(const zsl::vector_d& v1, const zsl::vector_d& v2);
zsl::vector_d  operator-(const zsl::vector_d& v, double a);
zsl::vector_d  operator-(double a, const zsl::vector_d& v);
zsl::vector_d  operator*(const zsl::vector_d& v1, const zsl::vector_d& v2);
zsl::vector_d  operator*(const zsl::vector_d& v, double a);
zsl::vector_d  operator*(double a, const zsl::vector_d& v);
zsl::vector_d  operator/(const zsl::vector_d& v1, const zsl::vector_d& v2);
zsl::vector_d  operator/(const zsl::vector_d& v, double a);
zsl::vector_d  operator/(double a, const zsl::vector_d& v);

void operator+=(zsl::vector_d& v, const zsl::vector_d& w);
void operator+=(zsl::vector_d& v, double a);
void operator-=(zsl::vector_d& v, const zsl::vector_d& w);
void operator-=(zsl::vector_d& v, double a);
void operator*=(zsl::vector_d& v, const zsl::vector_d& w);
void operator*=(zsl::vector_d& v, double a);
void operator/=(zsl::vector_d& v, const zsl::vector_d& w);
void operator/=(zsl::vector_d& v, double a);


#endif // !ZSL_STD_VECTOR_OP_H
