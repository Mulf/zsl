#include "basics/std_vector_op.h"
#include "basics/ZException.h"

#include <cassert>

using namespace zsl;


vector_d  zsl::vadd(const vector_d& v1, const vector_d& v2)
{
	Z_EXPECT_SAME_LEN(v1, v2);

	const size_t N = v1.size();
	vector_d ans{N, vector_d::allocator_type{}};
	for (size_t i = 0; i < N; i++)
	{
		ans[i] = v1[i] + v2[i];
	}

	return ans;
}

vector_d  zsl::vadd(const vector_d& v, double a)
{
	vector_d ans{v.size(), vector_d::allocator_type{}};
	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = v[i] + a;
	}

	return ans;
}

vector_d  zsl::vadd(double a, const vector_d& v) {
	return v + a;
}

vector_d  zsl::vsub(const vector_d& v1, const vector_d& v2)
{
	Z_EXPECT_SAME_LEN(v1, v2);

	const size_t N = v1.size();
	vector_d ans{N, vector_d::allocator_type{}};
	for (size_t i = 0; i < N; i++)
	{
		ans[i] = v1[i] - v2[i];
	}

	return ans;
}

vector_d  zsl::vsub(const vector_d& v, double a)
{
	vector_d ans{v.size(), vector_d::allocator_type{}};
	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = v[i] - a;
	}

	return ans;
}

vector_d  zsl::vsub(double a, const vector_d& v) {
	const size_t N = v.size();
	vector_d ans{N, vector_d::allocator_type{}};
	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = a - v[i];
	}

	return ans;
}

vector_d  zsl::vmul(const vector_d& v1, const vector_d& v2)
{
	Z_EXPECT_SAME_LEN(v1, v2);
	const size_t N = v1.size();
	vector_d ans{N, vector_d::allocator_type{}};

	for (size_t i = 0; i < N; i++)
	{
		ans[i] = v1[i] * v2[i];
	}

	return ans;
}

vector_d  zsl::vmul(const vector_d& v, double a)
{
	vector_d ans{v.size(), vector_d::allocator_type{}};
	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = v[i] * a;
	}

	return ans;
}

vector_d  zsl::vmul(double a, const vector_d& v) {
	return v * a;
}

vector_d  zsl::vdiv(const vector_d& v1, const vector_d& v2)
{
	Z_EXPECT_SAME_LEN(v1, v2);

	const size_t N = v1.size();
	vector_d ans{N, vector_d::allocator_type{}};

	for (size_t i = 0; i < N; i++)
	{
		Z_EXPECTOR_NON_ZERO_DIVISOR(v2[i]);

		ans[i] = v1[i] / v2[i];
	}

	return ans;
}

vector_d  zsl::vdiv(const vector_d& v, double a)
{
	Z_EXPECTOR_NON_ZERO_DIVISOR(a);

	vector_d ans{v.size(), vector_d::allocator_type{}};
	for (size_t i = 0; i < v.size(); i++)
	{
		ans[i] = v[i] / a;
	}

	return ans;
}

vector_d  zsl::vdiv(double a, const vector_d& v) {
	vector_d ans{v.size(), vector_d::allocator_type{}};
	for (size_t i = 0; i < v.size(); i++)
	{
		Z_EXPECTOR_NON_ZERO_DIVISOR(v[i]);

		ans[i] = a / v[i];
	}

	return ans;
}

void zsl::vadd_self(vector_d& v, const vector_d& w)
{
	Z_EXPECT_SAME_LEN(v, w);

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] += w[i];
	}
}

void zsl::vadd_self(vector_d& v, double a)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] += a;
	}
}

void zsl::vsub_self(vector_d& v, const vector_d& w)
{
	Z_EXPECT_SAME_LEN(v, w);

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] -= w[i];
	}
}

void zsl::vsub_self(vector_d& v, double a)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] -= a;
	}
}

void zsl::vmul_self(vector_d& v, const vector_d& w)
{
	Z_EXPECT_SAME_LEN(v, w);

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= w[i];
	}
}

void zsl::vmul_self(vector_d& v, double a)
{
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= a;
	}
}

void zsl::vdiv_self(vector_d& v, const vector_d& w)
{
	Z_EXPECT_SAME_LEN(v, w);

	for (size_t i = 0; i < v.size(); i++)
	{
		assert(w[i] != 0);
		v[i] /= w[i];
	}
}

void zsl::vdiv_self(vector_d& v, double a)
{
	Z_EXPECTOR_NON_ZERO_DIVISOR(a);

	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] /= a;
	}
}


vector_d  operator+(const vector_d& v1, const vector_d& v2)
{
	return zsl::vadd(v1, v2);
}

vector_d  operator+(const vector_d& v, double a)
{
	return zsl::vadd(v, a);
}

vector_d  operator+(double a, const vector_d& v){
	return zsl::vadd(a, v);
}

vector_d  operator-(const vector_d& v1, const vector_d& v2)
{
	return zsl::vsub(v1, v2);
}

vector_d  operator-(const vector_d& v, double a)
{
	return zsl::vsub(v, a);
}

vector_d  operator-(double a, const vector_d& v) {
	return zsl::vsub(a, v);
}

vector_d  operator*(const vector_d& v1, const vector_d& v2)
{
	return zsl::vmul(v1, v2);
}

vector_d  operator*(const vector_d& v, double a)
{
	return zsl::vmul(v, a);
}

vector_d  operator*(double a, const vector_d& v) {
	return zsl::vmul(a, v);
}

vector_d  operator/(const vector_d& v1, const vector_d& v2)
{
	return zsl::vdiv(v1, v2);
}

vector_d  operator/(const vector_d& v, double a)
{
	return zsl::vdiv(v, a);
}

vector_d  operator/(double a, const vector_d& v) {
	return zsl::vdiv(a, v);
}

void operator+=(vector_d& v, const vector_d& w)
{
	zsl::vadd_self(v, w);
}

void operator+=(vector_d& v, double a)
{
	zsl::vadd_self(v, a);
}

void operator-=(vector_d& v, const vector_d& w)
{
	zsl::vsub_self(v, w);
}

void operator-=(vector_d& v, double a)
{
	zsl::vsub_self(v, a);
}

void operator*=(vector_d& v, const vector_d& w)
{
	zsl::vmul_self(v, w);
}

void operator*=(vector_d& v, double a)
{
	zsl::vmul_self(v, a);
}

void operator/=(vector_d& v, const vector_d& w)
{
	zsl::vdiv_self(v, w);
}

void operator/=(vector_d& v, double a)
{
	zsl::vdiv_self(v, a);
}