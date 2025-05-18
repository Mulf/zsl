#include "zatlab/language_fundamentals/operators_and_elementary_operations/arithmetic_operations.h"
#include <functional>
#include <type_traits>

#pragma region template basics
template<typename T, typename U>
concept AirthOpResultSame = requires(T t, U u) {
	requires std::is_same_v<decltype(t + u), decltype(t - u)>;
	requires std::is_same_v<decltype(t + u), decltype(t * u)>;
	//requires std::is_same_v<decltype(t + u), decltype(t / u)>;
};

template <class T, class U>
	requires AirthOpResultSame<T, U>
using ArithOp = std::function < auto(const T &, const U &)->decltype(T{} - U{}) > ;

template <class T, class U>
	requires AirthOpResultSame<T, U>
using ArithOpSelf = std::function<T &(T &, const U &)>;

// Arithmetic Operation between Vector and Scalar
template <class T, class U>
	requires AirthOpResultSame<T, U>
auto arith_op_vs(const std::vector<T> &v, const U &s, ArithOp<T, U> &op)
{
  using R = decltype(T{} - U{});
  std::vector<R> ans(v.size(), R{});
  for (size_t i = 0; i < v.size(); i++) {
    ans[i] = op(v[i], s);
  }

  return ans;
}

template <class T, class U>
	requires AirthOpResultSame<T, U>
auto arith_op_vs(const U &s, const std::vector<T> &v, ArithOp<U, T> &op)
{
	using R = decltype(U{} - T{});
	std::vector<R> ans(v.size(), R{});
	for(size_t i = 0; i < v.size(); i++) {
		ans[i] = op(s, v[i]);
	}

	return ans;
}

template <class T, class U>
auto arith_op_vs_self(std::vector<T> &v, const U &s, ArithOpSelf<T, U> &op)
    -> std::vector<decltype(T{} + U{})> & {
  using R = decltype(T{} + U{});
  static_assert(std::is_same_v<T, R>, "T and R must be the same type");
  for (size_t i = 0; i < v.size(); i++) {
    op(v[i], s);
  }

  return v;
}

// Arithmetic Operation between Vector and Vector
template <class T, class U>
auto arith_op_vv(const std::vector<T> &v, const std::vector<U> &w,
                 ArithOp<T, U> &op) -> std::vector<decltype(T{} + U{})> {
  if (v.size() != w.size()) {
    Z_THROW(zsl::ZErrorCode::MATH_DIM_UNMATCH, "Vectors' length are not same");
  }

  using R = decltype(T{} + U{});
  std::vector<R> ans(v.size(), R{});
  for (size_t i = 0; i < v.size(); i++) {
    ans[i] = op(v[i], w[i]);
  }

  return ans;
}

template <class T, class U>
std::vector<T> &arith_op_self_vv(std::vector<T> &v, const std::vector<U> &w,
                                 ArithOpSelf<T, U> &op) {
  if (v.size() != w.size()) {
    Z_THROW(zsl::ZErrorCode::MATH_DIM_UNMATCH, "Vectors' length are not same");
  }

  using R = decltype(T{} + U{});
  static_assert(std::is_same_v<T, R>, "T and R must be the same type");
  for (size_t i = 0; i < v.size(); i++) {
    op(v[i], w[i]);
  }

  return v;
}
#pragma endregion

namespace _ {

#pragma region Addition template
template <class T, class U>
auto plus(const std::vector<T> &v, const U &s)
    -> std::vector<decltype(T{} + U{})> {
  ArithOp<T, U> add = [](const T &t, const U &u) -> decltype(T{} + U{}) {
    return t + u;
  };
  auto ans = arith_op_vs<T, U>(v, s, add);
  return ans;
}

template <class T, class U>
std::vector<T> &plus_self(std::vector<T> &v, const U &s) {
  ArithOpSelf<T, U> add_self = [](T &t, const U &u) -> T & {
    t += u;
    return t;
  };

  return arith_op_vs_self<T, U>(v, s, add_self);
}

template <class T, class U>
auto plus(const std::vector<T> &v, const std::vector<U> &w)
    -> std::vector<decltype(T{} + U{})> {
  ArithOp<T, U> add = [](const T &t, const U &u) -> decltype(T{} + U{}) {
    return t + u;
  };
  auto ans = arith_op_vv(v, w, add);
  return ans;
}

template <class T, class U>
std::vector<T> &plus_self(std::vector<T> &v, const std::vector<U> &w) {
  ArithOpSelf<T, U> add_self = [](T &t, const U &u) -> T & {
    t += u;
    return t;
  };
  arith_op_self_vv(v, w, add_self);
  return v;
}

#pragma endregion Addition template

#pragma region Subtraction template
template <class T, class U>
auto minus(const std::vector<T> &v, const U &s)
-> std::vector<decltype(T{} - U{})> {
	ArithOp<T, U> sub = [](const T &t, const U &u) -> decltype(T{} - U{}) {
		return t - u;
	};
	auto ans = arith_op_vs<T, U>(v, s, sub);
	return ans;
}

template <class T, class U>
auto minus(const U &s, const std::vector<T> &v)
-> std::vector<decltype(T{} - U{}) > {
	ArithOp<U, T> sub = [](const U &u, const T &t) -> decltype(U{} - T{}) {
		return u - t;
	};
	auto ans = arith_op_vs<T, U>(s, v, sub);
	return ans;
}

template <class T, class U>
std::vector<T> &minus_self(std::vector<T> &v, const U &s) {
	ArithOpSelf<T, U> sub_self = [](T &t, const U &u) -> T &{
		t -= u;
		return t;
	};

	return arith_op_vs_self<T, U>(v, s, sub_self);
}

template <class T, class U>
auto minus(const std::vector<T> &v, const std::vector<U> &w)
-> std::vector<decltype(T{} - U{}) > {
	ArithOp<T, U> sub = [](const T &t, const U &u) -> decltype(T{} - U{}) {
		return t - u;
	};
	auto ans = arith_op_vv(v, w, sub);
	return ans;
}

template <class T, class U>
std::vector<T> &minus_self(std::vector<T> &v, const std::vector<U> &w) {
	ArithOpSelf<T, U> sub_self = [](T &t, const U &u) -> T &{
		t -= u;
		return t;
	};
	arith_op_self_vv(v, w, sub_self);
	return v;
}

#pragma endregion Subtraction template

#pragma region Multiplication template
template <class T, class U>
auto times(const std::vector<T> &v, const U &s)
-> std::vector<decltype(T{} + U{})> {
	ArithOp<T, U> mul = [](const T &t, const U &u) -> decltype(T{} + U{}) {
		return t * u;
	};
	auto ans = arith_op_vs<T, U>(v, s, mul);
	return ans;
}

template <class T, class U>
std::vector<T> &times_self(std::vector<T> &v, const U &s) {
	ArithOpSelf<T, U> mul_self = [](T &t, const U &u) -> T &{
		t *= u;
		return t;
	};

	return arith_op_vs_self<T, U>(v, s, mul_self);
}

template <class T, class U>
auto times(const std::vector<T> &v, const std::vector<U> &w)
-> std::vector<decltype(T{} + U{}) > {
	ArithOp<T, U> mul = [](const T &t, const U &u) -> decltype(T{} + U{}) {
		return t * u;
	};
	auto ans = arith_op_vv(v, w, mul);
	return ans;
}

template <class T, class U>
std::vector<T> &times_self(std::vector<T> &v, const std::vector<U> &w) {
	ArithOpSelf<T, U> mul_self = [](T &t, const U &u) -> T &{
		t *= u;
		return t;
	};
	arith_op_self_vv(v, w, mul_self);
	return v;
}
#pragma endregion Multiplication template

#pragma region Rdivide template
template <class T, class U>
auto rdivide(const std::vector<T> &v, const U &s)
-> std::vector<decltype(T{} + U{}) > {
	ArithOp<T, U> div = [](const T &t, const U &u) -> decltype(T{} + U{}) {
		return t / u;
	};
	auto ans = arith_op_vs<T, U>(v, s, div);
	return ans;
}

template <class T, class U>
auto rdivide(const U &s, const std::vector<T> &v)
-> std::vector<decltype(T{} - U{}) > {
	ArithOp<U, T> div = [](const U &u, const T &t) -> decltype(U{} - T{}) {
		return u / t;
	};
	auto ans = arith_op_vs<T, U>(s, v, div);
	return ans;
}

template <class T, class U>
std::vector<T> &rdivide_self(std::vector<T> &v, const U &s) {
	ArithOpSelf<T, U> div_self = [](T &t, const U &u) -> T &{
		t /= u;
		return t;
	};

	return arith_op_vs_self<T, U>(v, s, div_self);
}

template <class T, class U>
auto rdivide(const std::vector<T> &v, const std::vector<U> &w)
-> std::vector<decltype(T{} - U{}) > {
	ArithOp<T, U> div = [](const T &t, const U &u) -> decltype(T{} - U{}) {
		return t / u;
	};
	auto ans = arith_op_vv(v, w, div);
	return ans;
}

template <class T, class U>
std::vector<T> &rdivide_self(std::vector<T> &v, const std::vector<U> &w) {
	ArithOpSelf<T, U> div_self = [](T &t, const U &u) -> T &{
		t /= u;
		return t;
	};
	arith_op_self_vv(v, w, div_self);
	return v;
}

#pragma endregion Rdivide template

} // namespace _

namespace zsl {
#pragma region Addition
// vector + scalar
vector_d plus(const vector_d &v, double d) { return _::plus(v, d); }

vector_d plus(double d, const vector_d &v) { return _::plus(v, d); }

vector_c plus(const vector_d &v, const complex_d &c) { return _::plus(v, c); }

vector_c plus(const complex_d &c, const vector_d &v) { return _::plus(v, c); }

vector_c plus(const vector_c &v, double d) { return _::plus(v, d); }

vector_c plus(double d, const vector_c &v) { return plus(v, d); }

vector_c plus(const vector_c &v, const complex_d &c) { return _::plus(v, c); }

vector_c plus(const complex_d &c, const vector_c &v) { return plus(v, c); }

vector_d &plus_self(vector_d &v, double d) { return _::plus_self(v, d); }

vector_c &plus_self(vector_c &v, const complex_d &c) {
  return _::plus_self(v, c);
}

vector_c &plus_self(vector_c &v, double d) { return _::plus_self(v, d); }

// vector + vector
vector_d plus(const vector_d &v, const vector_d &w) { return _::plus(v, w); }

vector_c plus(const vector_c &v, const vector_c &w) { return _::plus(v, w); }

vector_c plus(const vector_d &v, const vector_c &w) { return _::plus(v, w); }

vector_c plus(const vector_c &v, const vector_d &w) { return _::plus(v, w); }

vector_d &plus_self(vector_d &v, const vector_d &w) {
  return _::plus_self(v, w);
}

vector_c &plus_self(vector_c &v, const vector_c &w) {
  return _::plus_self(v, w);
}

vector_c &plus_self(vector_c &v, const vector_d &w) {
  return _::plus_self(v, w);
}

// matrix + scalar
matrix_d plus(const matrix_d &A, double d) { return _::plus(A, d); }

matrix_d plus(double d, const matrix_d &A) { return plus(A, d); }

matrix_c plus(const matrix_d &A, const complex_d &c) { return _::plus(A, c); }

matrix_c plus(const complex_d &c, const matrix_d &A) { return plus(A, c); }

matrix_c plus(const matrix_c &A, double d) { return _::plus(A, d); }

matrix_c plus(double d, const matrix_c &A) { return plus(A, d); }

matrix_c plus(const matrix_c &A, const complex_d &c) { return _::plus(A, c); }

matrix_c plus(const complex_d &c, const matrix_c &A) {
  return plus(A, c);
}

matrix_d &plus_self(matrix_d &A, double d) { return _::plus_self(A, d); }

matrix_c &plus_self(matrix_c &A, const complex_d &c) {
  return _::plus_self(A, c);
}

matrix_c &plus_self(matrix_c &A, double d) { return _::plus_self(A, d); }

// matrix + vector
matrix_d plus(const matrix_d &A, const vector_d &v) { return _::plus(A, v); }

matrix_d plus(const vector_d &v, const matrix_d &A) { return _::plus(A, v); }

matrix_c plus(const matrix_d &A, const vector_c &v) { return _::plus(A, v); }

matrix_c plus(const vector_c &v, const matrix_d &A) { return _::plus(A, v); }

matrix_c plus(const matrix_c &A, const vector_d &v) { return _::plus(A, v); }

matrix_c plus(const vector_d &v, const matrix_c &A) { return _::plus(A, v); }

matrix_c plus(const matrix_c &A, const vector_c &v) { return _::plus(A, v); }

matrix_c plus(const vector_c &v, const matrix_c &A) { return _::plus(A, v); }

matrix_d &plus_self(matrix_d &A, const vector_d &v) {
  return _::plus_self(A, v);
}

matrix_c &plus_self(matrix_c &A, const vector_c &v) {
  return _::plus_self(A, v);
}

matrix_c &plus_self(matrix_c &A, const vector_d &v) {
  return _::plus_self(A, v);
}
// matrix + matrix
matrix_d plus(const matrix_d &A, const matrix_d &B){
	return _::plus(A, B);
}
matrix_c plus(const matrix_c &A, const matrix_c &B){
	return _::plus(A, B);
}
matrix_c plus(const matrix_d &A, const matrix_c &B){
	return _::plus(A, B);
}
matrix_c plus(const matrix_c &A, const matrix_d &B){
	return _::plus(A, B);
}
matrix_d &plus_self(matrix_d &A, const matrix_d &B){
	return _::plus_self(A, B);
}
matrix_c &plus_self(matrix_c &A, const matrix_c &B){
	return _::plus_self(A, B);
}
matrix_c &plus_self(matrix_c &A, const matrix_d &B){
	return _::plus_self(A, B);
}
#pragma endregion

#pragma region Subtraction
// vector - scalar
vector_d minus(const vector_d &v, double d) {
	return _::minus(v, d);
}

vector_d minus(double d, const vector_d &v) {
	return _::minus(d, v);
}

vector_c minus(const vector_d &v, const complex_d &c) {
	return _::minus(v, c);
}

vector_c minus(const complex_d &c, const vector_d &v) {
	return _::minus(c, v);
}

vector_c minus(const vector_c &v, double d) {
	return _::minus(v, d);
}

vector_c minus(double d, const vector_c &v) {
	return _::minus(d, v);
}

vector_c minus(const vector_c &v, const complex_d &c) {
	return _::minus(v, c);
}

vector_c minus(const complex_d &c, const vector_c &v) {
	return _::minus(c, v);
}

vector_d &minus_self(vector_d &v, double d) {
	return _::minus_self(v, d);
}

vector_c &minus_self(vector_c &v, const complex_d &c) {
	return _::minus_self(v, c);
}

vector_c &minus_self(vector_c &v, double d) {
	return _::minus_self(v, d);
}

// vector - vector
vector_d minus(const vector_d &v, const vector_d &w) {
	return _::minus(v, w);
}

vector_c minus(const vector_c &v, const vector_c &w) {
	return _::minus(v, w);
}

vector_c minus(const vector_d &v, const vector_c &w) {
	return _::minus(v, w);
}

vector_c minus(const vector_c &v, const vector_d &w) {
	return _::minus(v, w);
}

vector_d &minus_self(vector_d &v, const vector_d &w) {
	return _::minus_self(v, w);
}

vector_c &minus_self(vector_c &v, const vector_c &w) {
	return _::minus_self(v, w);
}

vector_c &minus_self(vector_c &v, const vector_d &w) {
	return _::minus_self(v, w);
}

// matrix - scalar
matrix_d minus(const matrix_d &A, double d) {
	return _::minus(A, d);
}

matrix_d minus(double d, const matrix_d &A) {
	return _::minus(d, A);
}

matrix_c minus(const matrix_d &A, const complex_d &c) {
	return _::minus(A, c);
}

matrix_c minus(const complex_d &c, const matrix_d &A) {
	return _::minus(c, A);
}

matrix_c minus(const matrix_c &A, double d) {
	return _::minus(A, d);
}

matrix_c minus(double d, const matrix_c &A) {
	return _::minus(d, A);
}

matrix_c minus(const matrix_c &A, const complex_d &c) {
	return _::minus(A, c);
}

matrix_c minus(const complex_d &c, const matrix_c &A) {
	return _::minus(c, A);
}

matrix_d &minus_self(matrix_d &A, double d) {
	return _::minus_self(A, d);
}

matrix_c &minus_self(matrix_c &A, const complex_d &c) {
	return _::minus_self(A, c);
}

matrix_c &minus_self(matrix_c &A, double d) {
	return _::minus_self(A, d);
}

// matrix - vector
matrix_d minus(const matrix_d &A, const vector_d &v) {
	return _::minus(A, v);
}

matrix_d minus(const vector_d &v, const matrix_d &A) {
	return _::minus(v, A);
}

matrix_c minus(const matrix_d &A, const vector_c &v) {
	return _::minus(A, v);
}

matrix_c minus(const vector_c &v, const matrix_d &A) {
	return _::minus(v, A);
}

matrix_c minus(const matrix_c &A, const vector_d &v) {
	return _::minus(A, v);
}

matrix_c minus(const vector_d &v, const matrix_c &A) {
	return _::minus(v, A);
}

matrix_c minus(const matrix_c &A, const vector_c &v) {
	return _::minus(A, v);
}

matrix_c minus(const vector_c &v, const matrix_c &A) {
	return _::minus(v, A);
}

matrix_d &minus_self(matrix_d &A, const vector_d &v) {
	return _::minus_self(A, v);
}

matrix_c &minus_self(matrix_c &A, const vector_c &v) {
	return _::minus_self(A, v);
}

matrix_c &minus_self(matrix_c &A, const vector_d &v) {
	return _::minus_self(A, v);
}
// matrix - matrix
matrix_d minus(const matrix_d &A, const matrix_d &B){
	return _::minus(A, B);
}
matrix_c minus(const matrix_c &A, const matrix_c &B){
	return _::minus(A, B);
}
matrix_c minus(const matrix_d &A, const matrix_c &B){
	return _::minus(A, B);
}
matrix_c minus(const matrix_c &A, const matrix_d &B){
	return _::minus(A, B);
}
matrix_d &minus_self(matrix_d &A, const matrix_d &B){
	return _::minus_self(A, B);
}
matrix_c &minus_self(matrix_c &A, const matrix_c &B){
	return _::minus_self(A, B);
}
matrix_c &minus_self(matrix_c &A, const matrix_d &B){
	return _::minus_self(A, B);
}
#pragma endregion

#pragma region Muliplication
// vector * scalar
vector_d times(const vector_d &v, double d) {
	return _::times(v, d);
}

vector_d times(double d, const vector_d &v) {
	return _::times(v, d);
}

vector_c times(const vector_d &v, const complex_d &c) {
	return _::times(v, c);
}

vector_c times(const complex_d &c, const vector_d &v) {
	return _::times(v, c);
}

vector_c times(const vector_c &v, double d) {
	return _::times(v, d);
}

vector_c times(double d, const vector_c &v) {
	return times(v, d);
}

vector_c times(const vector_c &v, const complex_d &c) {
	return _::times(v, c);
}

vector_c times(const complex_d &c, const vector_c &v) {
	return times(v, c);
}

vector_d &times_self(vector_d &v, double d) {
	return _::times_self(v, d);
}

vector_c &times_self(vector_c &v, const complex_d &c) {
	return _::times_self(v, c);
}

vector_c &times_self(vector_c &v, double d) {
	return _::times_self(v, d);
}
// vector * vector
vector_d times(const vector_d &v, const vector_d &w) {
	return _::times(v, w);
}

vector_c times(const vector_c &v, const vector_c &w) {
	return _::times(v, w);
}

vector_c times(const vector_d &v, const vector_c &w) {
	return _::times(v, w);
}

vector_c times(const vector_c &v, const vector_d &w) {
	return _::times(v, w);
}

vector_d &times_self(vector_d &v, const vector_d &w) {
	return _::times_self(v, w);
}

vector_c &times_self(vector_c &v, const vector_c &w) {
	return _::times_self(v, w);
}

vector_c &times_self(vector_c &v, const vector_d &w) {
	return _::times_self(v, w);
}
// matrix * scalar
matrix_d times(const matrix_d &A, double d) {
	return _::times(A, d);
}

matrix_d times(double d, const matrix_d &A) {
	return times(A, d);
}

matrix_c times(const matrix_d &A, const complex_d &c) {
	return _::times(A, c);
}

matrix_c times(const complex_d &c, const matrix_d &A) {
	return times(A, c);
}

matrix_c times(const matrix_c &A, double d) {
	return _::times(A, d);
}

matrix_c times(double d, const matrix_c &A) {
	return times(A, d);
}

matrix_c times(const matrix_c &A, const complex_d &c) {
	return _::times(A, c);
}

matrix_c times(const complex_d &c, const matrix_c &A) {
	return times(A, c);
}

matrix_d &times_self(matrix_d &A, double d) {
	return _::times_self(A, d);
}

matrix_c &times_self(matrix_c &A, const complex_d &c) {
	return _::times_self(A, c);
}

matrix_c &times_self(matrix_c &A, double d) {
	return _::times_self(A, d);
}
// matrix * vector
matrix_d times(const matrix_d &A, const vector_d &v) {
	return _::times(A, v);
}

matrix_d times(const vector_d &v, const matrix_d &A) {
	return _::times(A, v);
}

matrix_c times(const matrix_d &A, const vector_c &v) {
	return _::times(A, v);
}

matrix_c times(const vector_c &v, const matrix_d &A) {
	return _::times(A, v);
}

matrix_c times(const matrix_c &A, const vector_d &v) {
	return _::times(A, v);
}

matrix_c times(const vector_d &v, const matrix_c &A) {
	return _::times(A, v);
}

matrix_c times(const matrix_c &A, const vector_c &v) {
	return _::times(A, v);
}

matrix_c times(const vector_c &v, const matrix_c &A) {
	return _::times(A, v);
}

matrix_d &times_self(matrix_d &A, const vector_d &v) {
	return _::times_self(A, v);
}

matrix_c &times_self(matrix_c &A, const vector_c &v) {
	return _::times_self(A, v);
}

matrix_c &times_self(matrix_c &A, const vector_d &v) {
	return _::times_self(A, v);
}
// matrix * matrix
matrix_d times(const matrix_d &A, const matrix_d &B){
	return _::times(A, B);
}
matrix_c times(const matrix_c &A, const matrix_c &B){
	return _::times(A, B);
}
matrix_c times(const matrix_d &A, const matrix_c &B){
	return _::times(A, B);
}
matrix_c times(const matrix_c &A, const matrix_d &B){
	return _::times(A, B);
}
matrix_d &times_self(matrix_d &A, const matrix_d &B){
	return _::times_self(A, B);
}
matrix_c &times_self(matrix_c &A, const matrix_c &B){
	return _::times_self(A, B);
}
matrix_c &times_self(matrix_c &A, const matrix_d &B){
	return _::times_self(A, B);
}
#pragma endregion

#pragma region Rdivide
// vector / scalar
vector_d rdivide(const vector_d &v, double d) {
	return _::rdivide(v, d);
}

vector_d rdivide(double d, const vector_d &v) {
	return _::rdivide(d, v);
}

vector_c rdivide(const vector_d &v, const complex_d &c) {
	return _::rdivide(v, c);
}

vector_c rdivide(const complex_d &c, const vector_d &v) {
	return _::rdivide(c, v);
}

vector_c rdivide(const vector_c &v, double d) {
	return _::rdivide(v, d);
}

vector_c rdivide(double d, const vector_c &v) {
	return _::rdivide(d, v);
}

vector_c rdivide(const vector_c &v, const complex_d &c) {
	return _::rdivide(v, c);
}

vector_c rdivide(const complex_d &c, const vector_c &v) {
	return _::rdivide(c, v);
}

vector_d &rdivide_self(vector_d &v, double d) {
	return _::rdivide_self(v, d);
}

vector_c &rdivide_self(vector_c &v, const complex_d &c) {
	return _::rdivide_self(v, c);
}

vector_c &rdivide_self(vector_c &v, double d) {
	return _::rdivide_self(v, d);
}

// vector / vector
vector_d rdivide(const vector_d &v, const vector_d &w) {
	return _::rdivide(v, w);
}

vector_c rdivide(const vector_c &v, const vector_c &w) {
	return _::rdivide(v, w);
}

vector_c rdivide(const vector_d &v, const vector_c &w) {
	return _::rdivide(v, w);
}

vector_c rdivide(const vector_c &v, const vector_d &w) {
	return _::rdivide(v, w);
}

vector_d &rdivide_self(vector_d &v, const vector_d &w) {
	return _::rdivide_self(v, w);
}

vector_c &rdivide_self(vector_c &v, const vector_c &w) {
	return _::rdivide_self(v, w);
}

vector_c &rdivide_self(vector_c &v, const vector_d &w) {
	return _::rdivide_self(v, w);
}

// matrix / scalar
matrix_d rdivide(const matrix_d &A, double d) {
	return _::rdivide(A, d);
}

matrix_d rdivide(double d, const matrix_d &A) {
	return _::rdivide(d, A);
}

matrix_c rdivide(const matrix_d &A, const complex_d &c) {
	return _::rdivide(A, c);
}

matrix_c rdivide(const complex_d &c, const matrix_d &A) {
	return _::rdivide(c, A);
}

matrix_c rdivide(const matrix_c &A, double d) {
	return _::rdivide(A, d);
}

matrix_c rdivide(double d, const matrix_c &A) {
	return _::rdivide(d, A);
}

matrix_c rdivide(const matrix_c &A, const complex_d &c) {
	return _::rdivide(A, c);
}

matrix_c rdivide(const complex_d &c, const matrix_c &A) {
	return _::rdivide(c, A);
}

matrix_d &rdivide_self(matrix_d &A, double d) {
	return _::rdivide_self(A, d);
}

matrix_c &rdivide_self(matrix_c &A, const complex_d &c) {
	return _::rdivide_self(A, c);
}

matrix_c &rdivide_self(matrix_c &A, double d) {
	return _::rdivide_self(A, d);
}

// matrix / vector
matrix_d rdivide(const matrix_d &A, const vector_d &v) {
	return _::rdivide(A, v);
}

matrix_d rdivide(const vector_d &v, const matrix_d &A) {
	return _::rdivide(v, A);
}

matrix_c rdivide(const matrix_d &A, const vector_c &v) {
	return _::rdivide(A, v);
}

matrix_c rdivide(const vector_c &v, const matrix_d &A) {
	return _::rdivide(v, A);
}

matrix_c rdivide(const matrix_c &A, const vector_d &v) {
	return _::rdivide(A, v);
}

matrix_c rdivide(const vector_d &v, const matrix_c &A) {
	return _::rdivide(v, A);
}

matrix_c rdivide(const matrix_c &A, const vector_c &v) {
	return _::rdivide(A, v);
}

matrix_c rdivide(const vector_c &v, const matrix_c &A) {
	return _::rdivide(v, A);
}

matrix_d &rdivide_self(matrix_d &A, const vector_d &v) {
	return _::rdivide_self(A, v);
}

matrix_c &rdivide_self(matrix_c &A, const vector_c &v) {
	return _::rdivide_self(A, v);
}

matrix_c &rdivide_self(matrix_c &A, const vector_d &v) {
	return _::rdivide_self(A, v);
}
// matrix / matrix
matrix_d rdivide(const matrix_d &A, const matrix_d &B){
	return _::rdivide(A, B);
}
matrix_c rdivide(const matrix_c &A, const matrix_c &B){
	return _::rdivide(A, B);
}
matrix_c rdivide(const matrix_d &A, const matrix_c &B){
	return _::rdivide(A, B);
}
matrix_c rdivide(const matrix_c &A, const matrix_d &B){
	return _::rdivide(A, B);
}
matrix_d &rdivide_self(matrix_d &A, const matrix_d &B){
	return _::rdivide_self(A, B);
}
matrix_c &rdivide_self(matrix_c &A, const matrix_c &B){
	return _::rdivide_self(A, B);
}
matrix_c &rdivide_self(matrix_c &A, const matrix_d &B){
	return _::rdivide_self(A, B);
}
#pragma endregion

} // namespace zsl

#pragma region Addition plus sign overload
// vector + scalar
zsl::vector_d operator+(const zsl::vector_d &v, double d) {
  return zsl::plus(v, d);
}
zsl::vector_d operator+(double d, const zsl::vector_d &v) {
  return zsl::plus(d, v);
}

zsl::vector_c operator+(const zsl::vector_d &v, const zsl::complex_d &c) {
  return zsl::plus(v, c);
}

zsl::vector_c operator+(const zsl::complex_d &c, const zsl::vector_d &v) {
  return zsl::plus(c, v);
}

zsl::vector_c operator+(const zsl::vector_c &v, double d) {
  return zsl::plus(v, d);
}

zsl::vector_c operator+(double d, const zsl::vector_c &v) {
  return zsl::plus(d, v);
}

zsl::vector_c operator+(const zsl::vector_c &v, const zsl::complex_d &c) {
  return zsl::plus(v, c);
}

zsl::vector_c operator+(const zsl::complex_d &c, const zsl::vector_c &v) {
  return zsl::plus(c, v);
}

zsl::vector_d &operator+=(zsl::vector_d &v, double d) {
  return zsl::plus_self(v, d);
}

zsl::vector_c &operator+=(zsl::vector_c &v, const zsl::complex_d &c) {
  return zsl::plus_self(v, c);
}

zsl::vector_c &operator+=(zsl::vector_c &v, double d) {
  return zsl::plus_self(v, d);
}

// vector + vector
zsl::vector_d operator+(const zsl::vector_d &v, const zsl::vector_d &w) {
  return zsl::plus(v, w);
}

zsl::vector_c operator+(const zsl::vector_c &v, const zsl::vector_c &w) {
  return zsl::plus(v, w);
}

zsl::vector_c operator+(const zsl::vector_d &v, const zsl::vector_c &w) {
  return zsl::plus(v, w);
}

zsl::vector_c operator+(const zsl::vector_c &v, const zsl::vector_d &w) {
  return zsl::plus(v, w);
}

zsl::vector_d &operator+=(zsl::vector_d &v, const zsl::vector_d &w) {
  return zsl::plus_self(v, w);
}

zsl::vector_c &operator+=(zsl::vector_c &v, const zsl::vector_c &w) {
  return zsl::plus_self(v, w);
}

zsl::vector_c &operator+=(zsl::vector_c &v, const zsl::vector_d &w) {
  return zsl::plus_self(v, w);
}

// matrix + scalar
zsl::matrix_d operator+(const zsl::matrix_d &A, double d) {
  return zsl::plus(A, d);
}
zsl::matrix_d operator+(double d, const zsl::matrix_d &A) {
  return zsl::plus(d, A);
}
zsl::matrix_c operator+(const zsl::matrix_d &A, const zsl::complex_d &c) {
  return zsl::plus(A, c);
}
zsl::matrix_c operator+(const zsl::complex_d &c, const zsl::matrix_d &A) {
  return zsl::plus(c, A);
}
zsl::matrix_c operator+(const zsl::matrix_c &A, double d) {
  return zsl::plus(A, d);
}
zsl::matrix_c operator+(double d, const zsl::matrix_c &A) {
  return zsl::plus(d, A);
}
zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::complex_d &c) {
  return zsl::plus(A, c);
}
zsl::matrix_c operator+(const zsl::complex_d &c, const zsl::matrix_c &A) {
  return zsl::plus(c, A);
}
zsl::matrix_d &operator+=(zsl::matrix_d &A, double d) {
  return zsl::plus_self(A, d);
}
zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::complex_d &c) {
  return zsl::plus_self(A, c);
}
zsl::matrix_c &operator+=(zsl::matrix_c &A, double d) {
  return zsl::plus_self(A, d);
}
// matrix + vector
zsl::matrix_d operator+(const zsl::matrix_d &A, const zsl::vector_d &v) {
  return zsl::plus(A, v);
}

zsl::matrix_d operator+(const zsl::vector_d &v, const zsl::matrix_d &A) {
  return zsl::plus(A, v);
}

zsl::matrix_c operator+(const zsl::matrix_d &A, const zsl::vector_c &v) {
  return zsl::plus(A, v);
}

zsl::matrix_c operator+(const zsl::vector_c &v, const zsl::matrix_d &A) {
  return zsl::plus(A, v);
}

zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::vector_d &v) {
  return zsl::plus(A, v);
}

zsl::matrix_c operator+(const zsl::vector_d &v, const zsl::matrix_c &A) {
  return zsl::plus(A, v);
}

zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::vector_c &v) {
  return zsl::plus(A, v);
}

zsl::matrix_c operator+(const zsl::vector_c &v, const zsl::matrix_c &A) {
  return zsl::plus(A, v);
}

zsl::matrix_d &operator+=(zsl::matrix_d &A, const zsl::vector_d &v) {
  return zsl::plus_self(A, v);
}

zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::vector_c &v) {
  return zsl::plus_self(A, v);
}

zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::vector_d &v) {
  return zsl::plus_self(A, v);
}
// matrix + matrix
zsl::matrix_d operator+(const zsl::matrix_d &A, const zsl::matrix_d &B){
	return zsl::plus(A, B);
}

zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::matrix_c &B){
	return zsl::plus(A, B);
}

zsl::matrix_c operator+(const zsl::matrix_d &A, const zsl::matrix_c &B){
	return zsl::plus(A, B);
}

zsl::matrix_c operator+(const zsl::matrix_c &A, const zsl::matrix_d &B){
	return zsl::plus(A, B);
}

zsl::matrix_d &operator+=(zsl::matrix_d &A, const zsl::matrix_d &B){
	return zsl::plus_self(A, B);
}

zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::matrix_c &B){
	return zsl::plus_self(A, B);
}

zsl::matrix_c &operator+=(zsl::matrix_c &A, const zsl::matrix_d &B){
	return zsl::plus_self(A, B);
}
#pragma endregion plus sign overload

#pragma region Subtraction minus sign overload
// vector - scalar
zsl::vector_d operator-(const zsl::vector_d &v, double d) {
	return zsl::minus(v, d);
}
zsl::vector_d operator-(double d, const zsl::vector_d &v) {
	return zsl::minus(d, v);
}

zsl::vector_c operator-(const zsl::vector_d &v, const zsl::complex_d &c) {
	return zsl::minus(v, c);
}

zsl::vector_c operator-(const zsl::complex_d &c, const zsl::vector_d &v) {
	return zsl::minus(c, v);
}

zsl::vector_c operator-(const zsl::vector_c &v, double d) {
	return zsl::minus(v, d);
}

zsl::vector_c operator-(double d, const zsl::vector_c &v) {
	return zsl::minus(d, v);
}

zsl::vector_c operator-(const zsl::vector_c &v, const zsl::complex_d &c) {
	return zsl::minus(v, c);
}

zsl::vector_c operator-(const zsl::complex_d &c, const zsl::vector_c &v) {
	return zsl::minus(c, v);
}

zsl::vector_d &operator-=(zsl::vector_d &v, double d) {
	return zsl::minus_self(v, d);
}

zsl::vector_c &operator-=(zsl::vector_c &v, const zsl::complex_d &c) {
	return zsl::minus_self(v, c);
}

zsl::vector_c &operator-=(zsl::vector_c &v, double d) {
	return zsl::minus_self(v, d);
}

// vector - vector
zsl::vector_d operator-(const zsl::vector_d &v, const zsl::vector_d &w) {
	return zsl::minus(v, w);
}

zsl::vector_c operator-(const zsl::vector_c &v, const zsl::vector_c &w) {
	return zsl::minus(v, w);
}

zsl::vector_c operator-(const zsl::vector_d &v, const zsl::vector_c &w) {
	return zsl::minus(v, w);
}

zsl::vector_c operator-(const zsl::vector_c &v, const zsl::vector_d &w) {
	return zsl::minus(v, w);
}

zsl::vector_d &operator-=(zsl::vector_d &v, const zsl::vector_d &w) {
	return zsl::minus_self(v, w);
}

zsl::vector_c &operator-=(zsl::vector_c &v, const zsl::vector_c &w) {
	return zsl::minus_self(v, w);
}

zsl::vector_c &operator-=(zsl::vector_c &v, const zsl::vector_d &w) {
	return zsl::minus_self(v, w);
}

// matrix - scalar
zsl::matrix_d operator-(const zsl::matrix_d &A, double d) {
	return zsl::minus(A, d);
}
zsl::matrix_d operator-(double d, const zsl::matrix_d &A) {
	return zsl::minus(d, A);
}
zsl::matrix_c operator-(const zsl::matrix_d &A, const zsl::complex_d &c) {
	return zsl::minus(A, c);
}
zsl::matrix_c operator-(const zsl::complex_d &c, const zsl::matrix_d &A) {
	return zsl::minus(c, A);
}
zsl::matrix_c operator-(const zsl::matrix_c &A, double d) {
	return zsl::minus(A, d);
}
zsl::matrix_c operator-(double d, const zsl::matrix_c &A) {
	return zsl::minus(d, A);
}
zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::complex_d &c) {
	return zsl::minus(A, c);
}
zsl::matrix_c operator-(const zsl::complex_d &c, const zsl::matrix_c &A) {
	return zsl::minus(c, A);
}
zsl::matrix_d &operator-=(zsl::matrix_d &A, double d) {
	return zsl::minus_self(A, d);
}
zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::complex_d &c) {
	return zsl::minus_self(A, c);
}
zsl::matrix_c &operator-=(zsl::matrix_c &A, double d) {
	return zsl::minus_self(A, d);
}
// matrix - vector
zsl::matrix_d operator-(const zsl::matrix_d &A, const zsl::vector_d &v) {
	return zsl::minus(A, v);
}

zsl::matrix_d operator-(const zsl::vector_d &v, const zsl::matrix_d &A) {
	return zsl::minus(v, A);
}

zsl::matrix_c operator-(const zsl::matrix_d &A, const zsl::vector_c &v) {
	return zsl::minus(A, v);
}

zsl::matrix_c operator-(const zsl::vector_c &v, const zsl::matrix_d &A) {
	return zsl::minus(v, A);
}

zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::vector_d &v) {
	return zsl::minus(A, v);
}

zsl::matrix_c operator-(const zsl::vector_d &v, const zsl::matrix_c &A) {
	return zsl::minus(v, A);
}

zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::vector_c &v) {
	return zsl::minus(A, v);
}

zsl::matrix_c operator-(const zsl::vector_c &v, const zsl::matrix_c &A) {
	return zsl::minus(v, A);
}

zsl::matrix_d &operator-=(zsl::matrix_d &A, const zsl::vector_d &v) {
	return zsl::minus_self(A, v);
}

zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::vector_c &v) {
	return zsl::minus_self(A, v);
}

zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::vector_d &v) {
	return zsl::minus_self(A, v);
}
// matrix - matrix
zsl::matrix_d operator-(const zsl::matrix_d &A, const zsl::matrix_d &B){
	return zsl::minus(A, B);
}

zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::matrix_c &B){
	return zsl::minus(A, B);
}

zsl::matrix_c operator-(const zsl::matrix_d &A, const zsl::matrix_c &B){
	return zsl::minus(A, B);
}

zsl::matrix_c operator-(const zsl::matrix_c &A, const zsl::matrix_d &B){
	return zsl::minus(A, B);
}

zsl::matrix_d &operator-=(zsl::matrix_d &A, const zsl::matrix_d &B){
	return zsl::minus_self(A, B);
}

zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::matrix_c &B){
	return zsl::minus_self(A, B);
}

zsl::matrix_c &operator-=(zsl::matrix_c &A, const zsl::matrix_d &B){
	return zsl::minus_self(A, B);
}
#pragma endregion minus sign overload

#pragma region times sign overload
// vector * scalar
zsl::vector_d operator*(const zsl::vector_d &v, double d) {
	return zsl::times(v, d);
}
zsl::vector_d operator*(double d, const zsl::vector_d &v) {
	return zsl::times(d, v);
}

zsl::vector_c operator*(const zsl::vector_d &v, const zsl::complex_d &c) {
	return zsl::times(v, c);
}

zsl::vector_c operator*(const zsl::complex_d &c, const zsl::vector_d &v) {
	return zsl::times(c, v);
}

zsl::vector_c operator*(const zsl::vector_c &v, double d) {
	return zsl::times(v, d);
}

zsl::vector_c operator*(double d, const zsl::vector_c &v) {
	return zsl::times(d, v);
}

zsl::vector_c operator*(const zsl::vector_c &v, const zsl::complex_d &c) {
	return zsl::times(v, c);
}

zsl::vector_c operator*(const zsl::complex_d &c, const zsl::vector_c &v) {
	return zsl::times(c, v);
}

zsl::vector_d &operator*=(zsl::vector_d &v, double d) {
	return zsl::times_self(v, d);
}

zsl::vector_c &operator*=(zsl::vector_c &v, const zsl::complex_d &c) {
	return zsl::times_self(v, c);
}

zsl::vector_c &operator*=(zsl::vector_c &v, double d) {
	return zsl::times_self(v, d);
}

// vector * vector
zsl::vector_d operator*(const zsl::vector_d &v, const zsl::vector_d &w) {
	return zsl::times(v, w);
}

zsl::vector_c operator*(const zsl::vector_c &v, const zsl::vector_c &w) {
	return zsl::times(v, w);
}

zsl::vector_c operator*(const zsl::vector_d &v, const zsl::vector_c &w) {
	return zsl::times(v, w);
}

zsl::vector_c operator*(const zsl::vector_c &v, const zsl::vector_d &w) {
	return zsl::times(v, w);
}

zsl::vector_d &operator*=(zsl::vector_d &v, const zsl::vector_d &w) {
	return zsl::times_self(v, w);
}

zsl::vector_c &operator*=(zsl::vector_c &v, const zsl::vector_c &w) {
	return zsl::times_self(v, w);
}

zsl::vector_c &operator*=(zsl::vector_c &v, const zsl::vector_d &w) {
	return zsl::times_self(v, w);
}
// matrix * scalar
zsl::matrix_d operator*(const zsl::matrix_d &A, double d) {
	return zsl::times(A, d);
}
zsl::matrix_d operator*(double d, const zsl::matrix_d &A) {
	return zsl::times(d, A);
}
zsl::matrix_c operator*(const zsl::matrix_d &A, const zsl::complex_d &c) {
	return zsl::times(A, c);
}
zsl::matrix_c operator*(const zsl::complex_d &c, const zsl::matrix_d &A) {
	return zsl::times(c, A);
}
zsl::matrix_c operator*(const zsl::matrix_c &A, double d) {
	return zsl::times(A, d);
}
zsl::matrix_c operator*(double d, const zsl::matrix_c &A) {
	return zsl::times(d, A);
}
zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::complex_d &c) {
	return zsl::times(A, c);
}
zsl::matrix_c operator*(const zsl::complex_d &c, const zsl::matrix_c &A) {
	return zsl::times(c, A);
}
zsl::matrix_d &operator*=(zsl::matrix_d &A, double d) {
	return zsl::times_self(A, d);
}
zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::complex_d &c) {
	return zsl::times_self(A, c);
}
zsl::matrix_c &operator*=(zsl::matrix_c &A, double d) {
	return zsl::times_self(A, d);
}
// matrix * vector
zsl::matrix_d operator*(const zsl::matrix_d &A, const zsl::vector_d &v) {
	return zsl::times(A, v);
}

zsl::matrix_d operator*(const zsl::vector_d &v, const zsl::matrix_d &A) {
	return zsl::times(A, v);
}

zsl::matrix_c operator*(const zsl::matrix_d &A, const zsl::vector_c &v) {
	return zsl::times(A, v);
}

zsl::matrix_c operator*(const zsl::vector_c &v, const zsl::matrix_d &A) {
	return zsl::times(A, v);
}

zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::vector_d &v) {
	return zsl::times(A, v);
}

zsl::matrix_c operator*(const zsl::vector_d &v, const zsl::matrix_c &A) {
	return zsl::times(A, v);
}

zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::vector_c &v) {
	return zsl::times(A, v);
}

zsl::matrix_c operator*(const zsl::vector_c &v, const zsl::matrix_c &A) {
	return zsl::times(A, v);
}

zsl::matrix_d &operator*=(zsl::matrix_d &A, const zsl::vector_d &v) {
	return zsl::times_self(A, v);
}

zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::vector_c &v) {
	return zsl::times_self(A, v);
}

zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::vector_d &v) {
	return zsl::times_self(A, v);
}
// matrix * matrix
zsl::matrix_d operator*(const zsl::matrix_d &A, const zsl::matrix_d &B){
	return zsl::times(A, B);
}

zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::matrix_c &B){
	return zsl::times(A, B);
}

zsl::matrix_c operator*(const zsl::matrix_d &A, const zsl::matrix_c &B){
	return zsl::times(A, B);
}

zsl::matrix_c operator*(const zsl::matrix_c &A, const zsl::matrix_d &B){
	return zsl::times(A, B);
}

zsl::matrix_d &operator*=(zsl::matrix_d &A, const zsl::matrix_d &B){
	return zsl::times_self(A, B);
}

zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::matrix_c &B){
	return zsl::times_self(A, B);
}

zsl::matrix_c &operator*=(zsl::matrix_c &A, const zsl::matrix_d &B){
	return zsl::times_self(A, B);
}
#pragma endregion

#pragma region Rdivide sign overload
// vector / scalar
zsl::vector_d operator/(const zsl::vector_d &v, double d) {
	return zsl::rdivide(v, d);
}
zsl::vector_d operator/(double d, const zsl::vector_d &v) {
	return zsl::rdivide(d, v);
}

zsl::vector_c operator/(const zsl::vector_d &v, const zsl::complex_d &c) {
	return zsl::rdivide(v, c);
}

zsl::vector_c operator/(const zsl::complex_d &c, const zsl::vector_d &v) {
	return zsl::rdivide(c, v);
}

zsl::vector_c operator/(const zsl::vector_c &v, double d) {
	return zsl::rdivide(v, d);
}

zsl::vector_c operator/(double d, const zsl::vector_c &v) {
	return zsl::rdivide(d, v);
}

zsl::vector_c operator/(const zsl::vector_c &v, const zsl::complex_d &c) {
	return zsl::rdivide(v, c);
}

zsl::vector_c operator/(const zsl::complex_d &c, const zsl::vector_c &v) {
	return zsl::rdivide(c, v);
}

zsl::vector_d &operator/=(zsl::vector_d &v, double d) {
	return zsl::rdivide_self(v, d);
}

zsl::vector_c &operator/=(zsl::vector_c &v, const zsl::complex_d &c) {
	return zsl::rdivide_self(v, c);
}

zsl::vector_c &operator/=(zsl::vector_c &v, double d) {
	return zsl::rdivide_self(v, d);
}

// vector / vector
zsl::vector_d operator/(const zsl::vector_d &v, const zsl::vector_d &w) {
	return zsl::rdivide(v, w);
}

zsl::vector_c operator/(const zsl::vector_c &v, const zsl::vector_c &w) {
	return zsl::rdivide(v, w);
}

zsl::vector_c operator/(const zsl::vector_d &v, const zsl::vector_c &w) {
	return zsl::rdivide(v, w);
}

zsl::vector_c operator/(const zsl::vector_c &v, const zsl::vector_d &w) {
	return zsl::rdivide(v, w);
}

zsl::vector_d &operator/=(zsl::vector_d &v, const zsl::vector_d &w) {
	return zsl::rdivide_self(v, w);
}

zsl::vector_c &operator/=(zsl::vector_c &v, const zsl::vector_c &w) {
	return zsl::rdivide_self(v, w);
}

zsl::vector_c &operator/=(zsl::vector_c &v, const zsl::vector_d &w) {
	return zsl::rdivide_self(v, w);
}

// matrix / scalar
zsl::matrix_d operator/(const zsl::matrix_d &A, double d) {
	return zsl::rdivide(A, d);
}
zsl::matrix_d operator/(double d, const zsl::matrix_d &A) {
	return zsl::rdivide(d, A);
}
zsl::matrix_c operator/(const zsl::matrix_d &A, const zsl::complex_d &c) {
	return zsl::rdivide(A, c);
}
zsl::matrix_c operator/(const zsl::complex_d &c, const zsl::matrix_d &A) {
	return zsl::rdivide(c, A);
}
zsl::matrix_c operator/(const zsl::matrix_c &A, double d) {
	return zsl::rdivide(A, d);
}
zsl::matrix_c operator/(double d, const zsl::matrix_c &A) {
	return zsl::rdivide(d, A);
}
zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::complex_d &c) {
	return zsl::rdivide(A, c);
}
zsl::matrix_c operator/(const zsl::complex_d &c, const zsl::matrix_c &A) {
	return zsl::rdivide(c, A);
}
zsl::matrix_d &operator/=(zsl::matrix_d &A, double d) {
	return zsl::rdivide_self(A, d);
}
zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::complex_d &c) {
	return zsl::rdivide_self(A, c);
}
zsl::matrix_c &operator/=(zsl::matrix_c &A, double d) {
	return zsl::rdivide_self(A, d);
}
// matrix / vector
zsl::matrix_d operator/(const zsl::matrix_d &A, const zsl::vector_d &v) {
	return zsl::rdivide(A, v);
}

zsl::matrix_d operator/(const zsl::vector_d &v, const zsl::matrix_d &A) {
	return zsl::rdivide(v, A);
}

zsl::matrix_c operator/(const zsl::matrix_d &A, const zsl::vector_c &v) {
	return zsl::rdivide(A, v);
}

zsl::matrix_c operator/(const zsl::vector_c &v, const zsl::matrix_d &A) {
	return zsl::rdivide(v, A);
}

zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::vector_d &v) {
	return zsl::rdivide(A, v);
}

zsl::matrix_c operator/(const zsl::vector_d &v, const zsl::matrix_c &A) {
	return zsl::rdivide(v, A);
}

zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::vector_c &v) {
	return zsl::rdivide(A, v);
}

zsl::matrix_c operator/(const zsl::vector_c &v, const zsl::matrix_c &A) {
	return zsl::rdivide(v, A);
}

zsl::matrix_d &operator/=(zsl::matrix_d &A, const zsl::vector_d &v) {
	return zsl::rdivide_self(A, v);
}

zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::vector_c &v) {
	return zsl::rdivide_self(A, v);
}

zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::vector_d &v) {
	return zsl::rdivide_self(A, v);
}
// matrix / matrix
zsl::matrix_d operator/(const zsl::matrix_d &A, const zsl::matrix_d &B){
	return zsl::rdivide(A, B);
}

zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::matrix_c &B){
	return zsl::rdivide(A, B);
}

zsl::matrix_c operator/(const zsl::matrix_d &A, const zsl::matrix_c &B){
	return zsl::rdivide(A, B);
}

zsl::matrix_c operator/(const zsl::matrix_c &A, const zsl::matrix_d &B){
	return zsl::rdivide(A, B);
}

zsl::matrix_d &operator/=(zsl::matrix_d &A, const zsl::matrix_d &B){
	return zsl::rdivide_self(A, B);
}

zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::matrix_c &B){
	return zsl::rdivide_self(A, B);
}

zsl::matrix_c &operator/=(zsl::matrix_c &A, const zsl::matrix_d &B){
	return zsl::rdivide_self(A, B);
}
#pragma endregion rdivide sign overload
