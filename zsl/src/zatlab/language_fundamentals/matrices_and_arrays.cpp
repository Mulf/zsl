#include "zatlab/language_fundamentals/matrices_and_arrays.h"

#include <algorithm>
#include <iterator>

namespace _{
using namespace zsl;
template<class Vector>
size_t size(const Vector &v) {
	return v.size();
}

template<class Matrix>
vector_sz size(const Matrix &A) {
	if(A.empty()) {
		return {0, 0};
	}
	return {A.size(), A[0].size()};
}

template<class Matrix>
size_t size(const Matrix &A, size_t dim) {
	assert(dim == 1 || dim == 2);

	if(A.empty()) {
		return 0;
	}

	if(dim == 1) {
		return A.size();
	}
	return A[0].size();
}

template<typename T>
std::vector<T> circshift(const std::vector<T> &v, int k) {
	k = k % static_cast<int>(v.size());
	if(k < 0) {
		k += static_cast<int>(v.size());
	}

	std::vector<T> A(v.size());
	std::copy(v.end() - k, v.end(), A.begin());
	std::copy(v.begin(), v.end() - k, A.begin() + k);

	return A;
}

}

namespace zsl {
#pragma region Create and Combine Arrays
// cat
vector_d cat(const vector_d &v1, const vector_d &v2) {
  vector_d r{v1.size() + v2.size(), vector_d::allocator_type{}};
  std::copy(v1.begin(), v1.end(), r.begin());
  std::copy(v2.begin(), v2.end(), r.begin() + v1.size());

  return r;
}

vector2_d cat(size_t dim, const vector2_d &A, const vector2_d &B) {
  assert(dim == 1 || dim == 2);

  if (A.empty()) {
    return B;
  } else if (B.empty()) {
    return A;
  }

  if (dim == 1) {
    assert(A[0].size() == B[0].size());
    auto r = A;
    for (const auto &v : B) {
      r.push_back(v);
    }

    return r;
  } else {
    assert(A.size() == B.size());
    vector2_d r{};
    for (size_t i = 0; i < A.size(); i++) {
      r.push_back(cat(A[i], B[i]));
    }
    return r;
  }
}

// diag
vector2_d diag(const vector_d &v) {
  auto A = zeros(v.size());
  for (size_t i = 0; i < v.size(); i++) {
    A[i][i] = v[i];
  }
  return A;
}

vector2_d diag(const vector_d &v, int k) {
  if (k == 0) {
    return diag(v);
  }

  if (k > 0) {
    auto A = zeros(v.size() + static_cast<size_t>(k));
    for (size_t i = 0; i < v.size(); i++) {
      A[i][i + static_cast<size_t>(k)] = v[i];
    }
    return A;
  }

  auto A = zeros(v.size() + static_cast<size_t>(-k));
  for (size_t i = 0; i < v.size(); i++) {
    A[i + static_cast<size_t>(-k)][i] = v[i];
  }
  return A;
}

vector_d diag(const vector2_d &A) {
  if (A.empty()) {
    return {};
  }
  const size_t N = std::min(A.size(), A[0].size());
  vector_d x{N, vector_d::allocator_type{}};
  for (size_t i = 0; i < x.size(); i++) {
    x[i] = A[i][i];
  }
  return x;
}

vector_d diag(const vector2_d &A, int k) {
  if (A.empty()) {
    return {};
  }

  if (k == 0) {
    return diag(A);
  }

  const size_t L = std::max(A.size(), A[0].size());
  if (static_cast<size_t>(std::abs(k)) >= L) {
    return {};
  }

  if (k > 0) {
    const size_t N = std::min(A.size(), A[0].size() - k);
    vector_d x{N, vector_d::allocator_type{}};
    for (size_t i = 0; i < x.size(); i++) {
      x[i] = A[i][i + k];
    }

    return x;
  }

  const size_t N = std::min(A.size(), A[0].size() + k);
  vector_d x{N, vector_d::allocator_type{}};
  for (size_t i = 0; i < x.size(); i++) {
    x[i] = A[i - k][i];
  }

  return x;
}

// eye
vector2_d eye(size_t n) { return diag(ones_v(n)); }

vector2_d eye(size_t n, size_t m) {
  assert(n != 0 && m != 0);

  vector2_d A = zeros(n, m);
  const size_t N = std::min(n, m);
  for (size_t i = 0; i < N; i++) {
    A[i][i] = 1;
  }

  return A;
}

// horzcat
vector2_d horzcat(const vector2_d &A, const vector2_d &B) { return cat(2, A, B); }

vector2_d horzcat(const vector2_d &A, const vector_d &v) {
  assert(A.size() == v.size());

  auto r = A;
  for (size_t i = 0; i < A.size(); i++) {
    r[i].push_back(v[i]);
  }
  return r;
}

vector_d horzcat(const vector_d &v, const vector_d &w) { return cat(v, w); }

// vercat
vector2_d vertcat(const vector2_d &A, const vector2_d &B) { return cat(1, A, B); }

vector_d vertcat(const vector_d &v, const vector_d &w) { return cat(v, w); }

// ones
vector_d ones_v(size_t n) { return vector_d(n, 1.0); }

vector2_d ones(size_t n) { return vector2_d(n, ones_v(n)); }

vector2_d ones(size_t sz1, size_t sz2) { return vector2_d(sz1, ones_v(sz2)); }

// zeros
vector_d zeros_v(size_t n) { return vector_d(n, 0.0); }

vector2_d zeros(size_t n) { return vector2_d(n, zeros_v(n)); }

vector2_d zeros(size_t sz1, size_t sz2) { return vector2_d(sz1, zeros_v(sz2)); }
#pragma endregion

#pragma region Create Grids
vector_d linspace(double x1, double x2) { return linspace(x1, x2, 100); }

vector_d linspace(double x1, double x2, size_t n) {
  vector_d r{n, vector_d::allocator_type{}};
  for (size_t i = 0; i < n; i++) {
    r[i] = x1 + (x2 - x1) * static_cast<double>(i) / static_cast<double>(n - 1);
  }

  return r;
}
#pragma endregion

#pragma region Determine Size, Shape, and Order
// length
size_t length(const vector_d &v) { return v.size(); }

size_t length(const vector2_d &A) { return std::max(size(A, 1), size(A, 2)); }

size_t length(const vector2_c &A) {
	return std::max(size(A, 1), size(A, 2));
}

// size
size_t size(const vector_d &v) { return v.size(); }

vector_sz size(const vector2_d &A) {
  if (A.empty()) {
    return {0, 0};
  }
  return {A.size(), A[0].size()};
	//return _::size(A);
}

size_t size(const vector2_d &A, size_t dim) {
  /*assert(dim == 1 || dim == 2);

  if (A.empty()) {
    return 0;
  }

  if (dim == 1) {
    return A.size();
  }
  return A[0].size();*/
	return _::size(A, dim);
}

size_t size(const vector_c &v) {
	return v.size();
}

vector_sz size(const vector2_c &A) {
	if(A.empty()) {
		return {0, 0};
	}
	return {A.size(), A[0].size()};
	//return _::size<vector2_c>(A);
}

size_t size(const vector2_c &A, size_t dim) {
	return _::size(A, dim);
}

// numel
size_t numel(const vector_d &v) { return v.size(); }

size_t numel(const vector2_d &A) {
  assert(is_matrix(A));
  if (A.empty() || A[0].empty()) {
    return 0;
  }
  return A.size() * A[0].size();
}

size_t numel(const vector2_c &A) {
	assert(is_matrix(A));
	if(A.empty() || A[0].empty()) {
		return 0;
	}
	return A.size() * A[0].size();
}
#pragma endregion

#pragma region Resize, Reshape, and Rearrange
// resize
vector2_d head(const vector2_d &A) { return head(A, 8); }

vector2_d head(const vector2_d &A, size_t k) {
  vector2_d ans{};
  for (size_t i = 0; i < k; i++) {
    ans.push_back(A[i]);
  }

  return ans;
}

// tail
vector2_d tail(const vector2_d &A) { return tail(A, 8); }

vector2_d tail(const vector2_d &A, size_t k) {
  vector2_d ans{};
  for (size_t i = 0; i < k; i++) {
    ans.push_back(A[A.size() - 1 - i]);
  }

  return ans;
}

// reshape
vector2_d reshape(const vector_d &v, const std::pair<size_t, size_t> &sz) {
  if (v.empty()) {
    return {};
  }

  assert(v.size() == sz.first * sz.second);

  size_t idx = 0;
  vector2_d B{sz.first, vector_d{sz.second, vector_d::allocator_type{}}};
  for (size_t col = 0; col < sz.second; col++) {
    for (size_t row = 0; row < sz.first; row++) {
      B[row][col] = v[idx++];
    }
  }

  return B;
}

vector2_d reshape(const vector2_d &A, const std::pair<size_t, size_t> &sz) {
  if (A.empty()) {
    return A;
  }

  assert(A.size() * A[0].size() == sz.first * sz.second);

  size_t i = 0;
  size_t j = 0;
  const size_t rowA = A.size();
  vector2_d B{sz.first, vector_d{sz.second, vector_d::allocator_type{}}};
  for (size_t col = 0; col < sz.second; col++) {
    for (size_t row = 0; row < sz.first; row++) {
      B[row][col] = A[i][j];

      i++;
      if (i == rowA) {
        i = 0;
        j++;
      }
    }
  }

  return B;
}

vector2_d reshape(const vector_d &v, std::optional<size_t> sz1,
                 std::optional<size_t> sz2) {
  assert(sz1 || sz2);

  if (v.empty()) {
    return {};
  }

  if (sz1 && !sz2) {
    const size_t N = v.size();
    assert(N % *sz1 == 0);
    return reshape(v, *sz1, N / *sz1);
  } else if (!sz1 && sz2) {
    const size_t N = v.size();
    assert(N % *sz2 == 0);
    return reshape(v, N / *sz2, *sz2);
  }

  return reshape(v, {*sz1, *sz2});
}

vector2_d reshape(const vector2_d &A, std::optional<size_t> sz1,
                 std::optional<size_t> sz2) {
  assert(sz1 || sz2);

  if (A.empty()) {
    return {};
  }

  if (sz1 && !sz2) {
    const size_t N = A.size() * A[0].size();
    assert(N % *sz1 == 0);
    return reshape(A, *sz1, N / *sz1);
  } else if (!sz1 && sz2) {
    const size_t N = A.size() * A[0].size();
    assert(N % *sz2 == 0);
    return reshape(A, N / *sz2, *sz2);
  }

  return reshape(A, {*sz1, *sz2});
}

// circshift
vector_d circshift(const vector_d &v, int k) {
	return _::circshift(v, k);
}

vector_c circshift(const vector_c &v, int k) {
	return _::circshift(v, k);
}

vector2_d circshift(const vector2_d &A, int k) {
  k = k % static_cast<int>(A.size());
  if (k < 0) {
    k += static_cast<int>(A.size());
  }

  vector2_d B{A.size(), vector2_d::allocator_type{}};
  std::copy(A.end() - k, A.end(), B.begin());
  std::copy(A.begin(), A.end() - k, B.begin() + k);

  return B;
}

vector2_d circshift(const vector2_d &A, int k, size_t dim) {
  assert(dim == 0 || dim == 1);
  if (dim == 0) {
    return circshift(A, k);
  }

  auto B = A;
  for (auto &v : B) {
    v = circshift(v, k);
  }

  return {};
}

vector2_d circshift(const vector2_d &A, std::pair<int, int> K) {
  return circshift(circshift(A, 0, K.first), 1, K.second);
}

// flip
vector_d flip(const vector_d &v) {
  auto w = v;
  std::reverse(w.begin(), w.end());
  return w;
}

vector_d &flip_self(vector_d &v) {
  std::reverse(v.begin(), v.end());
  return v;
}

vector2_d flip(const vector2_d &A) {
  auto B = A;
  std::reverse(B.begin(), B.end());
  return B;
}

vector2_d &flip_self(vector2_d &A) {
  std::reverse(A.begin(), A.end());
  return A;
}

vector2_d flip(const vector2_d &A, size_t dim) {
  assert(dim == 0 || dim == 1);
  if (dim == 0) {
    return flip(A);
  }

  auto B = A;
  for (auto &v : B) {
    flip_self(v);
  }

  return B;
}

vector2_d &flip_self(vector2_d &A, size_t dim) {
  assert(dim == 0 || dim == 1);
  if (dim == 0) {
    return flip_self(A);
  }

  for (auto &v : A) {
    flip_self(v);
  }

  return A;
}

#pragma endregion

} // namespace zsl