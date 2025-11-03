#ifndef ZSL_BASICS_DEFINES_H
#define ZSL_BASICS_DEFINES_H

#include <complex>
#include <functional>
#include <vector>
#include <numbers>
#include <limits>

//#ifdef ZSL_DLL
//#define ZSL_API __declspec(dllexport)
//#else
//#define ZSL_API __declspec(dllimport)
//#endif


namespace zsl {
constexpr double pi = std::numbers::pi_v<double>;
//constexpr double eps = std::numeric_limits<double>::epsilon();


using vector_d = std::vector<double>;
using vector_sz = std::vector<size_t>;
using complex_d = std::complex<double>;
using vector_c = std::vector<std::complex<double>>;
using vector2_d = std::vector<std::vector<double>>;
using vector2_c = std::vector<std::vector<std::complex<double>>>;

template <typename T>
concept Vector = std::is_same_v<T, vector_d> || std::is_same_v<T, vector_c>;

template <typename T>
concept Matrix = std::is_same_v<T, vector2_d> || std::is_same_v<T, vector2_c>;

template <class Matrix> bool is_matrix(const Matrix &A) {
  for (size_t i = 1; i < A.size(); i++) {
    if (A[i].size() != A[0].size()) {
      return false;
    }
  }
  return true;
}

using UnaryOp = std::function<double(double)>;

constexpr double ABS_EPS = 1e-4;
} // namespace zsl

#endif // !ZSL_BASICS_DEFINES_H
