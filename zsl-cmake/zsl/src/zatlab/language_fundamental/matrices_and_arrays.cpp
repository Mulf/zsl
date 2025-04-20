#include "zatlab/language_fundamental/matrices_and_arrays.h"

#include <algorithm>
#include <iterator>


namespace zsl {
#pragma region Create and Combine Arrays
	vector_d vcat(const vector_d& v1, const vector_d& v2) {
		vector_d r{ v1.size() + v2.size(), vector_d::allocator_type{} };
		std::copy(v1.begin(), v1.end(), r.begin());
		std::copy(v2.begin(), v2.end(), r.begin() + v1.size());

		return r;
	}

	matrix_d cat(size_t dim, const matrix_d& A, const matrix_d& B) {
		assert(dim == 1 || dim == 2);

		if (A.empty()) {
			return B;
		}
		else if (B.empty()) {
			return A;
		}

		if (dim == 1) {
			assert(A[0].size() == B[0].size());
			auto r = A;
			for (const auto& v : B) {
				r.push_back(v);
			}

			return r;
		}
		else {
			assert(A.size() == B.size());
			matrix_d r{};
			for (size_t i = 0; i < A.size(); i++) {
				r.push_back(vcat(A[i], B[i]));
			}
			return r;
		}
	}

	matrix_d horzcat(const matrix_d& A, const matrix_d& B) {
		return cat(2, A, B);
	}

	matrix_d horzcat(const matrix_d& A, const vector_d& v) {
		assert(A.size() == v.size());

		auto r = A;
		for (size_t i = 0; i < A.size(); i++) {
			r[i].push_back(v[i]);
		}
		return r;
	}

	vector_d horzcat(const vector_d& v, const vector_d& w) {
		return vcat(v, w);
	}

	matrix_d vertcat(const matrix_d& A, const matrix_d& B) {
		return cat(1, A, B);
	}

	vector_d vones(size_t n) {
		return vector_d(n, 1.0);
	}

	matrix_d ones(size_t n) {
		return matrix_d(n, vones(n));
	}

	matrix_d ones(size_t sz1, size_t sz2) {
		return matrix_d(sz1, vones(sz2));
	}

	vector_d vzeros(size_t n) {
		return vector_d(n, 0.0);
	}

	matrix_d zeros(size_t n) {
		return matrix_d(n, vzeros(n));
	}

	matrix_d zeros(size_t sz1, size_t sz2) {
		return matrix_d(sz1, vzeros(sz2));
	}
#pragma endregion 

#pragma region Create Grids
	vector_d linspace(double x1, double x2) {
		return linspace(x1, x2, 100);
	}

	vector_d linspace(double x1, double x2, size_t n) {
		vector_d r{ n, vector_d::allocator_type{} };
		for (size_t i = 0; i < n; i++) {
			r[i] = x1 + (x2 - x1) * static_cast<double>(i) / static_cast<double>(n - 1);
		}

		return r;
	}
#pragma endregion

#pragma region Determine Size, Shape, and Order
	double length(const vector_d& v) {
		return static_cast<double>(v.size());
	}

	double length(const matrix_d& A) {
		return std::max(size(A, 1), size(A, 2));
	}

	double size(const vector_d& v) {
		return static_cast<double>(v.size());
	}

	vector_d size(const matrix_d& A) {
		if (A.empty()) {
			return { 0.0, 0.0 };
		}
		return { static_cast<double>(A.size()), static_cast<double>(A[0].size()) };
	}

	double size(const matrix_d& A, size_t dim) {
		assert(dim == 1 || dim == 2);

		if (A.empty()) {
			return 0.0;
		}

		if (dim == 1) {
			return static_cast<double>(A.size());
		}
		return static_cast<double>(A[0].size());
	}

	double numel(const vector_d& v) {
		return static_cast<double>(v.size());
	}

	double numel(const matrix_d& A) {
		assert(is_matrix(A));
		if (A.empty()) {
			return 0;
		}
		return static_cast<double>(A.size() * A[0].size());
	}
#pragma endregion 

#pragma region Resize, Reshape, and Rearrange
	matrix_d head(const matrix_d& A) {
		return head(A, 8);
	}

	matrix_d head(const matrix_d& A, size_t k) {
		matrix_d ans{};
		for (size_t i = 0; i < k; i++)
		{
			ans.push_back(A[i]);
		}

		return ans;
	}

	matrix_d tail(const matrix_d& A) {
		return tail(A, 8);
	}

	matrix_d tail(const matrix_d& A, size_t k) {
		matrix_d ans{};
		for (size_t i = 0; i < k; i++) {
			ans.push_back(A[A.size() - 1 - i]);
		}

		return ans;
	}
#pragma endregion

#pragma region Indexing
	vector_d colon(double j, double k) {
		size_t N = static_cast<size_t>(k - j) + 1;

		vector_d x{ N, vector_d::allocator_type{} };
		for (size_t i = 0; i < N; i++)
		{
			x[i] = j + static_cast<double>(i);
		}
		
		return x;
	}

	vector_d colon(double j, double i, double k) {
		if (i == 0) {
			return {j};
		}

		if ((k - j) * i < 0) {
			return {};
		}

		if (k == j) {
			return vector_d{ i };
		}

		size_t N = static_cast<size_t>((k - j) / i) + 1;
		vector_d x{ N, vector_d::allocator_type{} };
		for (size_t idx = 0; idx < N; idx++) {
			x[idx] = j + i * idx;
		}

		return x;
	}

	vector_d colon(const vector_d& v) {
		return v;
	}

	vector_d colon(const matrix_d& A) {
		vector_d v{ static_cast<size_t>(numel(A)), vector_d::allocator_type{} };
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

	vector_d colon(const vector_d& v, size_t j, size_t k) {
		assert(j < v.size() && k < v.size());
		
		if (j > k) {
			return {};
		}

		vector_d ans{ k - j + 1, vector_d::allocator_type{} };
		std::copy(v.begin() + j, v.begin() + k + 1, ans.begin());

		return ans;
	}

	matrix_d colon(const matrix_d& A, size_t j, size_t k) {
		assert(j < A.size() && k < A.size());

		if (j > k) {
			return {};
		}

		matrix_d ans{ k - j + 1, matrix_d::allocator_type{} };
		std::copy(A.begin() + j, A.begin() + k + 1, ans.begin());

		return ans;
	}

	vector_d colon_col(const matrix_d& A, size_t n) {
		if (A.empty()) {
			return {};
		}

		assert(n < A[0].size());

		vector_d v{ A.size(), vector_d::allocator_type{} };
		for (size_t i = 0; i < A.size(); i++) {
			v[i] = A[i][n];
		}

		return v;
	}

	vector_d colon_row(const matrix_d& A, size_t m) {
		if (A.empty()) {
			return {};
		}

		assert(m < A.size());

		return A[m];
	}
#pragma endregion
}