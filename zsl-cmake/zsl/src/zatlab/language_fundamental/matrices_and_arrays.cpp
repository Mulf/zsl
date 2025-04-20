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
}