#ifndef ZSL_BASICS_DEFINES_H
#define ZSL_BASICS_DEFINES_H

#include <complex>
#include <functional>
#include <vector>
#include <numbers>
#include <limits>

namespace zsl {
constexpr double pi = std::numbers::pi_v<double>;
constexpr double EPS = std::numeric_limits<double>::epsilon();


using vector_d = std::vector<double>;
using vector_sz = std::vector<size_t>;
using complex_d = std::complex<double>;
using vector_c = std::vector<std::complex<double>>;
using matrix_d = std::vector<std::vector<double>>;
using matrix_c = std::vector<std::vector<std::complex<double>>>;

template <typename T>
concept Vector = std::is_same_v<T, vector_d> || std::is_same_v<T, vector_c>;

template <typename T>
concept Matrix = std::is_same_v<T, matrix_c> || std::is_same_v<T, matrix_c>;

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
