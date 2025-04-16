#include "std_vector_op.h"
#include <cassert>


std::vector<double>  zsl::vadd(const std::vector<double>& v1, const std::vector<double>& v2)
{
	assert(v1.size() == v2.size());

	const size_t N = v1.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < N; i++)
	{
		ans[i] = v1[i] + v2[i];
	}

	return ans;
}

std::vector<double>  zsl::vadd(const std::vector<double>& v, double a)
{

	const size_t N = v.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = v[i] + a;
	}

	return ans;
}

std::vector<double>  zsl::vadd(double a, const std::vector<double>& v) {
	return v + a;
}

std::vector<double>  zsl::vsub(const std::vector<double>& v1, const std::vector<double>& v2)
{
	assert(v1.size() == v2.size());

	const size_t N = v1.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < N; i++)
	{
		ans[i] = v1[i] - v2[i];
	}

	return ans;
}

std::vector<double>  zsl::vsub(const std::vector<double>& v, double a)
{
	const size_t N = v.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = v[i] - a;
	}

	return ans;
}

std::vector<double>  zsl::vsub(double a, const std::vector<double>& v) {
	const size_t N = v.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = a - v[i];
	}

	return ans;
}

std::vector<double>  zsl::vmul(const std::vector<double>& v1, const std::vector<double>& v2)
{
	assert(v1.size() == v2.size());

	const size_t N = v1.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < N; i++)
	{
		ans[i] = v1[i] * v2[i];
	}

	return ans;
}

std::vector<double>  zsl::vmul(const std::vector<double>& v, double a)
{
	const size_t N = v.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = v[i] * a;
	}

	return ans;
}

std::vector<double>  zsl::vmul(double a, const std::vector<double>& v) {
	return v * a;
}

std::vector<double>  zsl::vdiv(const std::vector<double>& v1, const std::vector<double>& v2)
{
	assert(v1.size() == v2.size());

	const size_t N = v1.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < N; i++)
	{
		assert(v2[i] != 0);
		ans[i] = v1[i] / v2[i];
	}

	return ans;
}

std::vector<double>  zsl::vdiv(const std::vector<double>& v, double a)
{
	assert(a != 0);
	const size_t N = v.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = v[i] / a;
	}

	return ans;
}

std::vector<double>  zsl::vdiv(double a, const std::vector<double>& v) {
	const size_t N = v.size();
	std::vector<double> ans{N, std::vector<double>::allocator_type{}};

	for (size_t i = 0; i < v.size(); i++)
	{
		assert(v[i] != 0);
		ans[i] = a / v[i];
	}

	return ans;
}

void zsl::vadd_self(std::vector<double>& v, const std::vector<double>& w)
{
	assert(v.size() == w.size());

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] += w[i];
	}
}

void zsl::vadd_self(std::vector<double>& v, double a)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] += a;
	}
}

void zsl::vsub_self(std::vector<double>& v, const std::vector<double>& w)
{
	assert(v.size() == w.size());

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] -= w[i];
	}
}

void zsl::vsub_self(std::vector<double>& v, double a)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] -= a;
	}
}

void zsl::vmul_self(std::vector<double>& v, const std::vector<double>& w)
{
	assert(v.size() == w.size());

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= w[i];
	}
}

void zsl::vmul_self(std::vector<double>& v, double a)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= a;
	}
}

void zsl::vdiv_self(std::vector<double>& v, const std::vector<double>& w)
{
	assert(v.size() == w.size());

	for (size_t i = 0; i < v.size(); i++)
	{
		assert(w[i] != 0);
		v[i] /= w[i];
	}
}

void zsl::vdiv_self(std::vector<double>& v, double a)
{
	assert(a != 0);
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] /= a;
	}
}


std::vector<double>  operator+(const std::vector<double>& v1, const std::vector<double>& v2)
{
	return zsl::vadd(v1, v2);
}

std::vector<double>  operator+(const std::vector<double>& v, double a)
{
	return zsl::vadd(v, a);
}

std::vector<double>  operator+(double a, const std::vector<double>& v){
	return zsl::vadd(a, v);
}

std::vector<double>  operator-(const std::vector<double>& v1, const std::vector<double>& v2)
{
	return zsl::vsub(v1, v2);
}

std::vector<double>  operator-(const std::vector<double>& v, double a)
{
	return zsl::vsub(v, a);
}

std::vector<double>  operator-(double a, const std::vector<double>& v) {
	return zsl::vsub(a, v);
}

std::vector<double>  operator*(const std::vector<double>& v1, const std::vector<double>& v2)
{
	return zsl::vmul(v1, v2);
}

std::vector<double>  operator*(const std::vector<double>& v, double a)
{
	return zsl::vmul(v, a);
}

std::vector<double>  operator*(double a, const std::vector<double>& v) {
	return zsl::vmul(a, v);
}

std::vector<double>  operator/(const std::vector<double>& v1, const std::vector<double>& v2)
{
	return zsl::vdiv(v1, v2);
}

std::vector<double>  operator/(const std::vector<double>& v, double a)
{
	return zsl::vdiv(v, a);
}

std::vector<double>  operator/(double a, const std::vector<double>& v) {
	return zsl::vdiv(a, v);
}

void operator+=(std::vector<double>& v, const std::vector<double>& w)
{
	zsl::vadd_self(v, w);
}

void operator+=(std::vector<double>& v, double a)
{
	zsl::vadd_self(v, a);
}

void operator-=(std::vector<double>& v, const std::vector<double>& w)
{
	zsl::vsub_self(v, w);
}

void operator-=(std::vector<double>& v, double a)
{
	zsl::vsub_self(v, a);
}

void operator*=(std::vector<double>& v, const std::vector<double>& w)
{
	zsl::vmul_self(v, w);
}

void operator*=(std::vector<double>& v, double a)
{
	zsl::vmul_self(v, a);
}

void operator/=(std::vector<double>& v, const std::vector<double>& w)
{
	zsl::vdiv_self(v, w);
}

void operator/=(std::vector<double>& v, double a)
{
	zsl::vdiv_self(v, a);
}