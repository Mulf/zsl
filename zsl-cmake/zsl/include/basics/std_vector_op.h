#ifndef ZSL_BASICS_STD_VECTOR_OP_H
#define ZSL_BASICS_STD_VECTOR_OP_H

#include <vector>

namespace zsl
{
	std::vector<double>  vadd(const std::vector<double>& v1, const std::vector<double>& v2);
	std::vector<double>  vadd(const std::vector<double>& v, double a);
	std::vector<double>  vadd(double a, const std::vector<double>& v);
	std::vector<double>  vsub(const std::vector<double>& v1, const std::vector<double>& v2);
	std::vector<double>  vsub(const std::vector<double>& v, double a);
	std::vector<double>  vsub(double a, const std::vector<double>& v);
	std::vector<double>  vmul(const std::vector<double>& v1, const std::vector<double>& v2);
	std::vector<double>  vmul(const std::vector<double>& v, double a);
	std::vector<double>  vmul(double a, const std::vector<double>& v);
	std::vector<double>  vdiv(const std::vector<double>& v1, const std::vector<double>& v2);
	std::vector<double>  vdiv(const std::vector<double>& v, double a);
	std::vector<double>  vdiv(double a, const std::vector<double>& v);

	void vadd_self(std::vector<double>& v, const std::vector<double>& w);
	void vadd_self(std::vector<double>& v, double a);
	void vsub_self(std::vector<double>& v, const std::vector<double>& w);
	void vsub_self(std::vector<double>& v, double a);
	void vmul_self(std::vector<double>& v, const std::vector<double>& w);
	void vmul_self(std::vector<double>& v, double a);
	void vdiv_self(std::vector<double>& v, const std::vector<double>& w);
	void vdiv_self(std::vector<double>& v, double a);
}

std::vector<double>  operator+(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<double>  operator+(const std::vector<double>& v, double a);
std::vector<double>  operator+(double a, const std::vector<double>& v);
std::vector<double>  operator-(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<double>  operator-(const std::vector<double>& v, double a);
std::vector<double>  operator-(double a, const std::vector<double>& v);
std::vector<double>  operator*(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<double>  operator*(const std::vector<double>& v, double a);
std::vector<double>  operator*(double a, const std::vector<double>& v);
std::vector<double>  operator/(const std::vector<double>& v1, const std::vector<double>& v2);
std::vector<double>  operator/(const std::vector<double>& v, double a);
std::vector<double>  operator/(double a, const std::vector<double>& v);

void operator+=(std::vector<double>& v, const std::vector<double>& w);
void operator+=(std::vector<double>& v, double a);
void operator-=(std::vector<double>& v, const std::vector<double>& w);
void operator-=(std::vector<double>& v, double a);
void operator*=(std::vector<double>& v, const std::vector<double>& w);
void operator*=(std::vector<double>& v, double a);
void operator/=(std::vector<double>& v, const std::vector<double>& w);
void operator/=(std::vector<double>& v, double a);


#endif // !ZSL_STD_VECTOR_OP_H
