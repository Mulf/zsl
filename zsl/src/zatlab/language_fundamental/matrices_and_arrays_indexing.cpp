#include "zatlab/language_fundamentals/matrices_and_arrays.h"

namespace _ {
using namespace zsl;

template <class T>
std::vector<T> block(const std::vector<T> &v, const Colon &rng) {
  const size_t N = rng.count();
  std::vector<T> ans(N, T{});
  for (int r = 0; r < N; r++) {
    const int i = static_cast<int>(rng.first) + r * rng.interval;
    const size_t isz = static_cast<size_t>(i);
    if (isz >= v.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
    ans[static_cast<size_t>(r)] = v[isz];
  }
  return ans;
}

template <class T>
std::vector<T> block(const std::vector<T> &v, const vector_sz &indices) {
  const size_t N = indices.size();
  std::vector<T> ans(N, T{});
  for (size_t r = 0; r < N; r++) {
    const size_t isz = indices.at(r);
    if (isz >= v.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
    ans[r] = v[isz];
  }
  return ans;
}

template <class Vector>
Vector set_block(const Vector &v, const Colon &rng, const Vector &w) {
  if (rng.count() != w.size()) {
    std::string msg = std::format("source vector's length({}) does not match "
                                  "destination block's length({})",
                                  w.size(), rng.count());
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH, msg);
  }
  auto indices = rng.to_vector();
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= v.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }

  auto ans{v};
  for (size_t i = 0; i < w.size(); i++) {
    ans[indices[i]] = w[i];
  }

  return ans;
}

template <class Vector>
Vector set_block(const Vector &v, const vector_sz &indices, const vector_d &w) {
  if (indices.size() != w.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "source vector's length does not match target block's length");
  }
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= v.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }

  auto ans = v;
  for (size_t i = 0; i < w.size(); i++) {
    ans[indices[i]] = w[i];
  }

  return ans;
}

template <class Vector>
Vector &set_block_self(Vector &v, const Colon &rng, const Vector &w) {
  if (rng.count() != w.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "source vector's length does not match target block's length");
  }
  auto indices = rng.to_vector();
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= v.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }

  for (size_t i = 0; i < w.size(); i++) {
    v[indices[i]] = w[i];
  }
  return v;
}

template <class Vector>
Vector &set_block_self(Vector &v, const vector_sz &indices, const Vector &w) {
  if (indices.size() != w.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "source vector's length does not match target block's length");
  }
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= v.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }

  for (size_t i = 0; i < w.size(); i++) {
    v[indices[i]] = w[i];
  }
  return v;
}

template <class T>
std::vector<T> col(const std::vector<std::vector<T>> &A, size_t n) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (n >= A[0].size()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
  }

  std::vector<T> v(A.size(), T{});
  for (size_t i = 0; i < A.size(); i++) {
    v[i] = A[i][n];
  }

  return v;
}

template <class Matrix, class Vector>
Matrix set_col(const Matrix &A, size_t n, const Vector &v) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (n >= A[0].size()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
  }
  if (A.size() != v.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Vector length doest not matrix's length");
  }

  auto B{A};
  for (size_t i = 0; i < A.size(); i++) {
    B[i][n] = v[i];
  }

  return B;
}

template <class Matrix, class Vector>
Matrix &set_col_self(Matrix &A, size_t n, const Vector &v) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (n >= A[0].size()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
  }
  if (A.size() != v.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Vector length doest not matrix's length");
  }

  for (size_t i = 0; i < A.size(); i++) {
    A[i][n] = v[i];
  }

  return A;
}

template <class T>
std::vector<std::vector<T>> cols(const std::vector<std::vector<T>> &A,
                                 const vector_sz &indices) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= A[0].size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }

  std::vector<std::vector<T>> ans(A.size(), std::vector<T>(indices.size()));
  for (size_t i = 0; i < A.size(); i++) {
    for (size_t j = 0; j < indices.size(); j++) {
      ans[i][j] = A[i][indices[j]];
    }
  }
  return ans;
}

template <class Matrix>
Matrix set_cols(const Matrix &A, const vector_sz &indices, const Matrix &V) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A) || !is_matrix(V)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= A[0].size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  if (A.size() != V.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Target matrix's rows do not match source matrix's rows");
  }
  if (indices.size() != V[0].size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Indices' size does not match source matrix's columns");
  }

  auto ans{A};
  for (size_t i = 0; i < A.size(); i++) {
    for (size_t j = 0; j < indices.size(); j++) {
      ans[i][indices[j]] = V[i][j];
    }
  }
  return ans;
}

template <class Matrix>
Matrix &set_cols_self(Matrix &A, const vector_sz &indices, const Matrix &V) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A) || !is_matrix(V)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= A[0].size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  if (A.size() != V.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Target matrix's rows do not match source matrix's rows");
  }
  if (indices.size() != V[0].size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Indices' size does not match source matrix's columns");
  }

  for (size_t i = 0; i < A.size(); i++) {
    for (size_t j = 0; j < indices.size(); j++) {
      A[i][indices[j]] = V[i][j];
    }
  }
  return A;
}

template <class Matrix> Matrix cols(const Matrix &A, const Colon &rng) {
  return cols(A, rng.to_vector());
}

template <class Matrix>
Matrix set_cols(const Matrix &A, const Colon &rng, const Matrix &V) {
  return set_cols(A, rng.to_vector(), V);
}

template <class Matrix>
Matrix &set_cols_self(Matrix &A, const Colon &rng, const Matrix &V) {
  return set_cols_self(A, rng.to_vector(), V);
}

template <class T>
std::vector<T> row(const std::vector<std::vector<T>> &A, size_t m) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (m >= A.size()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
  }

  return A[m];
}

template <class Matrix, class Vector>
Matrix set_row(const Matrix &A, size_t m, const Vector &v) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (m >= A.size()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
  }
  if (v.size() != A[0].size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Vector length doest not matrix's length");
  }

  auto B = A;
  B[m] = v;
  return B;
}

template <class Matrix, class Vector>
Matrix &set_row_self(Matrix &A, size_t m, const Vector &v) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (m >= A.size()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
  }
  if (v.size() != A[0].size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Vector length doest not matrix's length");
  }

  A[m] = v;
  return A;
}

template <class T>
std::vector<std::vector<T>> rows(const std::vector<std::vector<T>> &A,
                                 const vector_sz &indices) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (indices.empty()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "Indices are empty");
  }
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= A.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }

  std::vector<std::vector<T>> ans(indices.size(), std::vector<T>(A[0].size()));
  for (size_t i = 0; i < indices.size(); i++) {
    for (size_t j = 0; j < A[0].size(); j++) {
      ans[i][j] = A[indices[i]][j];
    }
  }
  return ans;
}

template <class Matrix>
Matrix set_rows(const Matrix &A, const vector_sz &indices, const Matrix &V) {
  if (A.empty() || V.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A) || !is_matrix(V)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (indices.empty()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "Indices are empty");
  }
  if (indices.size() != V.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Vectors' row count doest not indices's length");
  }
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= A.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  if (V[0].size() != A[0].size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Vector length doest not matrix's length");
  }

  auto ans = A;
  for (size_t i = 0; i < indices.size(); i++) {
    for (size_t j = 0; j < A[0].size(); j++) {
      ans[indices[i]][j] = V[i][j];
    }
  }
  return ans;
}

template <class Matrix>
Matrix &set_rows_self(Matrix &A, const vector_sz &indices, const Matrix &V) {
  if (A.empty() || V.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A) || !is_matrix(V)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (indices.empty()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "Indices are empty");
  }
  if (indices.size() != V.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Vectors' row count doest not indices's length");
  }
  for (size_t i = 0; i < indices.size(); i++) {
    if (indices[i] >= A.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  if (V[0].size() != A[0].size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Vector length doest not matrix's length");
  }

  for (size_t i = 0; i < indices.size(); i++) {
    for (size_t j = 0; j < A[0].size(); j++) {
      A[indices[i]][j] = V[i][j];
    }
  }
  return A;
}

template <class Matrix>
Matrix set_rows(const Matrix &A, const Colon &rng, const Matrix &V) {
  return set_rows(A, rng.to_vector(), V);
}

template <class Matrix>
Matrix &set_rows_self(Matrix &A, const Colon &rng, const Matrix &V) {
  return set_rows_self(A, rng.to_vector(), V);
}

template <class T>
std::vector<std::vector<T>> rows(const std::vector<std::vector<T>> &A,
                                 const Colon &rng) {
  return rows(A, rng.to_vector());
}

template <class T>
std::vector<std::vector<T>> block(const std::vector<std::vector<T>> &A,
                                  const vector_sz &rowIndices,
                                  const vector_sz &colIndices) {
  if (A.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (rowIndices.empty() || colIndices.empty()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "Indices are empty");
  }
  for (size_t i = 0; i < rowIndices.size(); i++) {
    if (rowIndices[i] >= A.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  for (size_t i = 0; i < colIndices.size(); i++) {
    if (colIndices[i] >= A[0].size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }

  std::vector<std::vector<T>> ans(rowIndices.size(),
                                  std::vector<T>(colIndices.size()));

  for (size_t i = 0; i < rowIndices.size(); i++) {
    for (size_t j = 0; j < colIndices.size(); j++) {
      ans[i][j] = A[rowIndices[i]][colIndices[j]];
    }
  }
  return ans;
}

template <class Matrix>
Matrix set_block(const Matrix &A, const vector_sz &rowIndices,
                 const vector_sz &colIndices, const Matrix &B) {
  if (A.empty() || B.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A) || !is_matrix(B)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (rowIndices.empty() || colIndices.empty()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "Indices are empty");
  }
  for (size_t i = 0; i < rowIndices.size(); i++) {
    if (rowIndices[i] >= A.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  for (size_t i = 0; i < colIndices.size(); i++) {
    if (colIndices[i] >= A[0].size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  if (rowIndices.size() != B.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Row Indices do not match source matrix's rows");
  }
  if (colIndices.size() != B[0].size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Col Indices do not match source matrix's cols");
  }

  auto ans{A};
  for (size_t i = 0; i < rowIndices.size(); i++) {
    for (size_t j = 0; j < colIndices.size(); j++) {
      ans[rowIndices[i]][colIndices[j]] = B[i][j];
    }
  }
  return ans;
}

template <class Matrix>
Matrix &set_block_self(Matrix &A, const vector_sz &rowIndices,
                       const vector_sz &colIndices, const Matrix &B) {
  if (A.empty() || B.empty()) {
    Z_THROW(ZErrorCode::MATH_EMPTY_VEC, "");
  }
  if (!is_matrix(A) || !is_matrix(B)) {
    Z_THROW(ZErrorCode::MATH_INVALID_MATRIX, "");
  }
  if (rowIndices.empty() || colIndices.empty()) {
    Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "Indices are empty");
  }
  for (size_t i = 0; i < rowIndices.size(); i++) {
    if (rowIndices[i] >= A.size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  for (size_t i = 0; i < colIndices.size(); i++) {
    if (colIndices[i] >= A[0].size()) {
      Z_THROW(ZErrorCode::LANG_INVALID_INDEX, "");
    }
  }
  if (rowIndices.size() != B.size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Row Indices do not match source matrix's rows");
  }
  if (colIndices.size() != B[0].size()) {
    Z_THROW(ZErrorCode::MATH_DIM_UNMATCH,
            "Col Indices do not match source matrix's cols");
  }

  for (size_t i = 0; i < rowIndices.size(); i++) {
    for (size_t j = 0; j < colIndices.size(); j++) {
      A[rowIndices[i]][colIndices[j]] = B[i][j];
    }
  }
  return A;
}

template <class T>
std::vector<std::vector<T>> block(const std::vector<std::vector<T>> &A,
                                  const Colon &rowRng, const Colon &colRng) {
  return block(A, rowRng.to_vector(), colRng.to_vector());
}

template <class Matrix>
Matrix set_block(const Matrix &A, const Colon &rowRng, const Colon &colRng,
                 const Matrix &B) {
  return set_block(A, rowRng.to_vector(), colRng.to_vector(), B);
}

template <class Matrix>
Matrix &set_block_self(Matrix &A, const Colon &rowRng, const Colon &colRng,
                       const Matrix &B) {
  return set_block_self(A, rowRng.to_vector(), colRng.to_vector(), B);
}

template <class T>
std::vector<std::vector<T>> block(const std::vector<std::vector<T>> &A,
                                  const vector_sz &rowIndices,
                                  const Colon &colRng) {
  return block(A, rowIndices, colRng.to_vector());
}

template <class Matrix>
Matrix set_block(const Matrix &A, const vector_sz &rowIndices,
                 const Colon &colRng, const Matrix &B) {
  return set_block(A, rowIndices, colRng.to_vector(), B);
}

template <class Matrix>
Matrix &set_block_self(Matrix &A, const vector_sz &rowIndices,
                       const Colon &colRng, const Matrix &B) {
  return set_block_self(A, rowIndices, colRng.to_vector(), B);
}

template <class T>
std::vector<std::vector<T>> block(const std::vector<std::vector<T>> &A,
                                  const Colon &rowRng,
                                  const vector_sz &colIndices) {
  return block(A, rowRng.to_vector(), colIndices);
}

template <class Matrix>
Matrix set_block(const Matrix &A, const Colon &rowRng,
                 const vector_sz &colIndices, const Matrix &B) {
  return set_block(A, rowRng.to_vector(), colIndices, B);
}

template <class Matrix>
Matrix &set_block_self(Matrix &A, const Colon &rowRng,
                       const vector_sz &colIndices, const Matrix &B) {
  return set_block_self(A, rowRng.to_vector(), colIndices, B);
}
} // namespace _

namespace zsl {
Colon::Colon(size_t first, size_t last) : Colon(first, 1, last) {}

Colon::Colon(size_t first, int interval, size_t last)
    : first{first}, interval{interval}, last{last} {
  if (interval == 0) {
    Z_THROW(ZErrorCode::LANG_INVLAID_INDEX_RANGE, "interval is 0");
  } else if (interval > 0 && first > last) {
    Z_THROW(ZErrorCode::LANG_INVLAID_INDEX_RANGE,
            "interval > 0 while first > last");
  } else if (interval < 0 && first < last) {
    Z_THROW(ZErrorCode::LANG_INVLAID_INDEX_RANGE,
            "interval < 0 while first < last");
  }
}

vector_sz Colon::to_vector() const {
  const size_t N = count();
  vector_sz ans{N, vector_sz::allocator_type{}};
  for (int r = 0; r < N; r++) {
    const int i = static_cast<int>(first) + r * interval;
    ans[static_cast<size_t>(r)] = static_cast<size_t>(i);
  }

  return ans;
}

size_t Colon::count() const {
  if (interval > 0) {
    const size_t isz = static_cast<size_t>(interval);
    return (last - first) / isz + 1;
  }

  const size_t isz = static_cast<size_t>(-interval);
  return (first - last) / isz + 1;
}

#pragma region Indexing

#pragma region colon
// colon
vector_d colon(double j, double k) {
  if (j > k) {
    return {};
  }

  size_t N = static_cast<size_t>(k - j) + 1;

  vector_d x{N, vector_d::allocator_type{}};
  for (size_t i = 0; i < N; i++) {
    x[i] = j + static_cast<double>(i);
  }

  return x;
}

vector_sz colon(size_t j, size_t k) {
  if (j > k) {
    return {};
  }
  size_t N = static_cast<size_t>(k - j) + 1;

  vector_sz x{N, vector_sz::allocator_type{}};
  for (size_t i = 0; i < N; i++) {
    x[i] = j + i;
  }

  return x;
}

vector_d colon(double j, double i, double k) {
  if (i == 0) {
    return {};
  }

  if ((k - j) * i < 0) {
    return {};
  }

  if (k == j) {
    return vector_d{i};
  }

  size_t N = static_cast<size_t>((k - j) / i) + 1;
  vector_d x{N, vector_d::allocator_type{}};
  for (size_t idx = 0; idx < N; idx++) {
    x[idx] = j + i * idx;
  }

  return x;
}

vector_sz colon(size_t j, int i, size_t k) {
  if (i == 0) {
    return {};
  }

  if (i > 0) {
    if (j > k) {
      return {};
    }

    const size_t isz = static_cast<size_t>(i);
    const size_t N = (k - j) / isz + 1;
    vector_sz ans{N, vector_sz::allocator_type{}};
    for (size_t r = 0; r < N; r++) {
      ans[r] = j + r * isz;
    }

    return ans;
  }

  if (j < k) {
    return {};
  }

  const size_t isz = static_cast<size_t>(-i);
  const size_t N = (j - k) / isz + 1;
  vector_sz ans{N, vector_sz::allocator_type{}};
  for (size_t r = 0; r < N; r++) {
    ans[r] = j - r * isz;
  }

  return ans;
}

#pragma endregion colon


vector_d colon(const vector_d &v) { return v; }

vector_d colon(const matrix_d &A) {
  vector_d v{static_cast<size_t>(numel(A)), vector_d::allocator_type{}};
  if (v.empty()) {
    return v;
  }
  size_t idx = 0;
  for (size_t j = 0; j < A[0].size(); j++) {
    for (size_t i = 0; i < A.size(); i++) {
      v[idx++] = A[i][j];
    }
  }

  return v;
}

// vector block
vector_d block(const vector_d &v, const Colon &rng) {
  return _::block<double>(v, rng);
}

vector_d block(const vector_d &v, const vector_sz &indices) {
  return _::block<double>(v, indices);
}

vector_d set_block(const vector_d &v, const Colon &rng, const vector_d &w) {
  return _::set_block(v, rng, w);
}

vector_d set_block(const vector_d &v, const vector_sz &indices,
                   const vector_d &w) {
  return _::set_block(v, indices, w);
}

vector_d &set_block_self(vector_d &v, const Colon &rng, const vector_d &w) {
  return _::set_block_self(v, rng, w);
}

vector_d &set_block_self(vector_d &v, const vector_sz &rng, const vector_d &w) {
  return _::set_block_self(v, rng, w);
}

// matrix block
vector_d col(const matrix_d &A, size_t n) { return _::col(A, n); }

matrix_d set_col(const matrix_d &A, size_t n, const vector_d &v) {
  return _::set_col(A, n, v);
}

matrix_d &set_col_self(matrix_d &A, size_t n, const vector_d &v) {
  return _::set_col_self(A, n, v);
}

matrix_d cols(const matrix_d &A, const Colon &rng) { return _::cols(A, rng); }

matrix_d cols(const matrix_d &A, const vector_sz &indices) {
  return _::cols(A, indices);
}

matrix_d set_cols(const matrix_d &A, const Colon &rng, const matrix_d &V) {
  return _::set_cols(A, rng, V);
}

matrix_d &set_cols_self(matrix_d &A, const Colon &rng, const matrix_d &V) {
  return _::set_cols_self(A, rng, V);
}

matrix_d set_cols(const matrix_d &A, const vector_sz &indices,
                  const matrix_d &V) {
  return _::set_cols(A, indices, V);
}

matrix_d &set_cols_self(matrix_d &A, const vector_sz &indices,
                        const matrix_d &V) {
  return _::set_cols_self(A, indices, V);
}

vector_d row(const matrix_d &A, size_t m) { return _::row(A, m); }

matrix_d set_row(const matrix_d &A, size_t m, const vector_d &v) {
  return _::set_row(A, m, v);
}

matrix_d &set_row_self(matrix_d &A, size_t m, const vector_d &v) {
  return _::set_row_self(A, m, v);
}

matrix_d rows(const matrix_d &A, const Colon &rng) { return _::rows(A, rng); }

matrix_d set_rows(const matrix_d &A, const Colon &rng, const matrix_d &V) {
  return _::set_rows(A, rng, V);
}

matrix_d &set_rows_self(matrix_d &A, const Colon &rng, const matrix_d &V) {
  return _::set_rows_self(A, rng, V);
}

matrix_d rows(const matrix_d &A, const vector_sz &indices) {
  return _::rows(A, indices);
}

matrix_d set_rows(const matrix_d &A, const vector_sz &indices,
                  const matrix_d &V) {
  return _::set_rows(A, indices, V);
}

matrix_d &set_rows_self(matrix_d &A, const vector_sz &indices,
                        const matrix_d &V) {
  return _::set_rows_self(A, indices, V);
}

matrix_d block(const matrix_d &A, const Colon &rowRng, const Colon &colRng) {
  return _::block(A, rowRng, colRng);
}

matrix_d set_block(const matrix_d &A, const Colon &rowRng, const Colon &colRng,
                   const matrix_d &B) {
  return _::set_block(A, rowRng, colRng, B);
}
matrix_d &set_block_self(matrix_d &A, const Colon &rowRng, const Colon &colRng,
                         const matrix_d &B) {
  return _::set_block_self(A, rowRng, colRng, B);
}

matrix_d block(const matrix_d &A, const vector_sz &rowIndices,
               const vector_sz &colIndices) {
  return _::block(A, rowIndices, colIndices);
}

matrix_d set_block(const matrix_d &A, const vector_sz &rowIndices,
                   const vector_sz &colIndices, const matrix_d &B) {
  return _::set_block(A, rowIndices, colIndices, B);
}

matrix_d &set_block_self(matrix_d &A, const vector_sz &rowIndices,
                         const vector_sz &colIndices, const matrix_d &B) {
  return _::set_block_self(A, rowIndices, colIndices, B);
}

matrix_d block(const matrix_d &A, const vector_sz &rowIndices,
               const Colon &colRng) {
  return _::block(A, rowIndices, colRng);
}

matrix_d set_block(const matrix_d &A, const vector_sz &rowIndices,
                   const Colon &colRng, const matrix_d &B) {
  return _::set_block(A, rowIndices, colRng, B);
}

matrix_d &set_block_self(matrix_d &A, const vector_sz &rowIndices,
                         const Colon &colRng, const matrix_d &B) {
  return _::set_block_self(A, rowIndices, colRng, B);
}

matrix_d block(const matrix_d &A, const Colon &rowRng,
               const vector_sz &colIndices) {
  return _::block(A, rowRng, colIndices);
}

matrix_d set_block(const matrix_d &A, const Colon &rowRng,
                   const vector_sz &colIndices, const matrix_d &B) {
  return _::set_block(A, rowRng, colIndices, B);
}

matrix_d &set_block_self(matrix_d &A, const Colon &rowRng,
                         const vector_sz &colIndices, const matrix_d &B) {
  return _::set_block_self(A, rowRng, colIndices, B);
}

// ind2sub
std::pair<size_t, size_t> ind2sub(const std::pair<size_t, size_t> &sz,
                                  size_t ind) {
  size_t col = ind / sz.first;
  size_t row = ind % sz.first;
  return {row, col};
}

std::vector<std::pair<size_t, size_t>>
ind2sub(const std::pair<size_t, size_t> &sz, const std::vector<size_t> &ind) {
  std::vector<std::pair<size_t, size_t>> sub(ind.size());
  for (size_t i = 0; i < ind.size(); i++) {
    sub[i] = ind2sub(sz, ind[i]);
  }

  return sub;
}

// sub2ind
size_t sub2ind(const std::pair<size_t, size_t> &sz,
               const std::pair<size_t, size_t> &sub) {
  return sz.first * sub.second + sub.first;
}

std::vector<size_t> sub2ind(const std::pair<size_t, size_t> &sz,
                            const std::vector<std::pair<size_t, size_t>> &sub) {
  std::vector<size_t> ind(sub.size());
  for (size_t i = 0; i < sub.size(); i++) {
    ind[i] = sz.first * sub[i].second + sub[i].first;
  }

  return ind;
}
#pragma endregion
} // namespace zsl