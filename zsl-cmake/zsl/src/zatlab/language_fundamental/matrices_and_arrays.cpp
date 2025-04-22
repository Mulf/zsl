#include "zatlab/language_fundamental/matrices_and_arrays.h"

#include <algorithm>
#include <iterator>


namespace zsl {
#pragma region Create and Combine Arrays
	// cat
	vector_d cat(const vector_d& v1, const vector_d& v2) {
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
				r.push_back(cat(A[i], B[i]));
			}
			return r;
		}
	}

	// diag
	matrix_d diag(const vector_d& v) {
		auto A = zeros(v.size());
		for (size_t i = 0; i < v.size(); i++) {
			A[i][i] = v[i];
		}
		return A;
	}

	matrix_d diag(const vector_d& v, int k) {
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

	vector_d diag(const matrix_d& A) {
		if (A.empty()) {
			return {};
		}
		const size_t N = std::min(A.size(), A[0].size());
		vector_d x{ N, vector_d::allocator_type{} };
		for (size_t i = 0; i < x.size(); i++) {
			x[i] = A[i][i];
		}
	}

	vector_d diag(const matrix_d& A, int k) {
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
			vector_d x{ N, vector_d::allocator_type{} };
			for (size_t i = 0; i < x.size(); i++) {
				x[i] = A[i][i+k];
			}

			return x;
		}

		const size_t N = std::min(A.size(), A[0].size() + k);
		vector_d x{ N, vector_d::allocator_type{} };
		for (size_t i = 0; i < x.size(); i++) {
			x[i] = A[i - k][i];
		}

		return x;
	}

	// eye
	matrix_d eye(size_t n) {
		return diag(vones(n));
	}

	matrix_d eye(size_t n, size_t m) {
		assert(n != 0 && m != 0);

		matrix_d A = zeros(n, m);
		const size_t N = std::min(n, m);
		for (size_t i = 0; i < N; i++) {
			A[i][i] = 1;
		}

		return A;
	}

	// horzcat 
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
		return cat(v, w);
	}

	// vercat
	matrix_d vertcat(const matrix_d& A, const matrix_d& B) {
		return cat(1, A, B);
	}

	// ones
	vector_d vones(size_t n) {
		return vector_d(n, 1.0);
	}

	matrix_d ones(size_t n) {
		return matrix_d(n, vones(n));
	}

	matrix_d ones(size_t sz1, size_t sz2) {
		return matrix_d(sz1, vones(sz2));
	}

	// zeros
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
	// length
	double length(const vector_d& v) {
		return static_cast<double>(v.size());
	}

	double length(const matrix_d& A) {
		return std::max(size(A, 1), size(A, 2));
	}

	// size
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

	// numel
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
	// resize
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

	// tail
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

	// reshape
	matrix_d reshape(const vector_d& v, const std::pair<size_t, size_t>& sz) {
		if (v.empty()) {
			return {};
		}

		assert(v.size() == sz.first * sz.second);

		size_t idx = 0;
		matrix_d B{ sz.first, vector_d{sz.second, vector_d::allocator_type{}} };
		for (size_t col = 0; col < sz.second; col++) {
			for (size_t row = 0; row < sz.first; row++) {
				B[row][col] = v[idx++];	
			}
		}

		return B;
	}

	matrix_d reshape(const matrix_d& A, const std::pair<size_t, size_t>& sz) {
		if (A.empty()) {
			return A;
		}

		assert(A.size() * A[0].size() == sz.first * sz.second);

		size_t i = 0;
		size_t j = 0;
		const size_t rowA = A.size();
		matrix_d B{ sz.first, vector_d{sz.second, vector_d::allocator_type{}} };
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

	matrix_d reshape(const vector_d& v, std::optional<size_t> sz1, std::optional<size_t> sz2) {
		assert(sz1 || sz2);

		if (v.empty()) {
			return {};
		}

		if (sz1 && !sz2) {
			const size_t N = v.size();
			assert(N % *sz1 == 0);
			return reshape(v, *sz1, N / *sz1);
		}
		else if (!sz1 && sz2) {
			const size_t N = v.size();
			assert(N % *sz2 == 0);
			return reshape(v, N / *sz2, *sz2);
		}

		return reshape(v, { *sz1, *sz2 });
	}

	matrix_d reshape(const matrix_d& A, std::optional<size_t> sz1, std::optional<size_t> sz2) {
		assert(sz1 || sz2);

		if (A.empty()) {
			return {};
		}
		
		if (sz1 && !sz2) {
			const size_t N = A.size() * A[0].size();
			assert(N % *sz1 == 0);
			return reshape(A, *sz1, N / *sz1);
		}
		else if (!sz1 && sz2) {
			const size_t N = A.size() * A[0].size();
			assert(N % *sz2 == 0);
			return reshape(A, N / *sz2, *sz2);
		}

		return reshape(A, {*sz1, *sz2});
	}

	// circshift
	vector_d circshift(const vector_d& v, int k) {
		k = k % static_cast<int>(v.size());
		if (k < 0) {
			k += static_cast<int>(v.size());
		}

		vector_d A{ v.size(), vector_d::allocator_type{} };
		std::copy(v.end() - k, v.end(), A.begin());
		std::copy(v.begin(), v.end() - k, A.begin() + k);

		return A;
	}

	matrix_d circshift(const matrix_d& A, int k) {
		k = k % static_cast<int>(A.size());
		if (k < 0) {
			k += static_cast<int>(A.size());
		}

		matrix_d B{ A.size(), matrix_d::allocator_type{} };
		std::copy(A.end() - k, A.end(), B.begin());
		std::copy(A.begin(), A.end() - k, B.begin() + k);

		return B;
	}

	matrix_d circshift(const matrix_d& A, int k, size_t dim) {
		assert(dim == 0 || dim == 1);
		if (dim == 0) {
			return circshift(A, k);
		}

		auto B = A;
		for (auto& v : B) {
			v = circshift(v, k);
		}

		return {};
	}

	matrix_d circshift(const matrix_d& A, std::pair<int, int> K) {
		return circshift(circshift(A, 0, K.first), 1, K.second);
	}

	// flip
	vector_d flip(const vector_d& v) {
		auto w = v;
		std::reverse(w.begin(), w.end());
		return w;
	}

	vector_d& flip_self(vector_d& v) {
		std::reverse(v.begin(), v.end());
		return v;
	}

	matrix_d flip(const matrix_d& A) {
		auto B = A;
		std::reverse(B.begin(), B.end());
		return B;
	}

	matrix_d& flip_self(matrix_d& A) {
		std::reverse(A.begin(), A.end());
		return A;
	}

	matrix_d flip(const matrix_d& A, size_t dim) {
		assert(dim == 0 || dim == 1);
		if (dim == 0) {
			return flip(A);
		}
		
		auto B = A;
		for (auto& v : B) {
			flip_self(v);
		}

		return B;
	}

	matrix_d &flip_self(matrix_d& A, size_t dim) {
		assert(dim == 0 || dim == 1);
		if (dim == 0) {
			return flip_self(A);
		}

		for (auto& v : A) {
			flip_self(v);
		}

		return A;
	}

#pragma endregion

#pragma region Indexing
	// colon
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
			return {};
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

	vector_d colon(const vector_d& v, size_t j, int i, size_t k) {
		if (i == 0) {
			return {};
		}
		if (i > 0 ) {
			if (j > k) {
				return {};
			}

			assert(j < v.size() && k < v.size());

			const size_t isz = static_cast<size_t>(i);
			const size_t N = (k - j) / isz + 1;
			vector_d ans{ N, vector_d::allocator_type{} };
			
			for (size_t p = 0; p < N; p++) {
				ans[p] = v[j + p * isz];
			}

			return ans;
		}

		assert(i < 0);
		if (j < k) {
			return {};
		}

		assert(j < v.size() && k < v.size());

		const size_t isz = static_cast<size_t>(-i);
		const size_t N = (j - k) / isz + 1;
		vector_d ans{ N, vector_d::allocator_type{} };
		for (size_t p = 0; p < N; p++) {
			ans[p] = v[j - p * isz];
		}

		return ans;
	}

	vector_d col(const matrix_d& A, size_t n) {
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

	matrix_d cols(const matrix_d& A, size_t j, size_t k) {
		if (A.empty()) {
			return {};
		}
		
		if (j > k) {
			return {};
		}

		assert(j < A[0].size() && k < A[0].size());

		matrix_d ans{ A.size(), matrix_d::allocator_type{}};
		for (size_t r = 0; r < A.size(); r++) {
			ans[r] = colon(A[r], j, k);
		}

		return ans;
	}

	matrix_d cols(const matrix_d& A, size_t j, int i, size_t k) {
		if (A.empty()) {
			return A;
		}

		if (i == 0) {
			return {};
		}

		if (i > 0) {
			if (j > k) {
				return {};
			}

			assert(j < A[0].size() && k < A[0].size());

			matrix_d ans{ A.size(), matrix_d::allocator_type{}};
			for (size_t r = 0; r < A.size(); r++) {
				ans[r] = colon(A[r], j, i, k);
			}

			return ans;
		}


		assert(i < 0);
		if (j < k) {
			return {};
		}

		assert(j < A.size() && k < A.size());

		matrix_d ans{ A.size(), vector_d::allocator_type{}};
		for (size_t r = 0; r < A.size(); r++) {
			ans[r] = colon(A[r], j, i, k);
		}

		return ans;
	}

	vector_d row(const matrix_d& A, size_t m) {
		if (A.empty()) {
			return {};
		}

		assert(m < A.size());

		return A[m];
	}

	matrix_d rows(const matrix_d& A, size_t j, size_t k) {
		if (A.empty()) {
			return A;
		}

		if (j > k) {
			return {};
		}

		assert(j < A.size() && k < A.size());

		const size_t N = k - j + 1;
		matrix_d ans{ N, matrix_d::allocator_type{} };
		for (size_t r = 0; r < N; r++) {
			ans[r] = A[r + j];
		}

		return ans;
	}

	matrix_d rows(const matrix_d& A, size_t j, int i, size_t k) {
		if (A.empty()) {
			return A;
		}

		if (i == 0) {
			return {};
		}

		if (i > 0) {
			if (j > k) {
				return {};
			}

			assert(j < A.size() && k < A.size());

			const size_t isz = static_cast<size_t>(i);
			const size_t N = (k - j) / isz + 1;
			matrix_d ans{ N, vector_d::allocator_type{} };
			for (size_t r = 0; r < N; r++) {
				ans[r] = A[j + r * isz];
			}

			return ans;
		}


		assert(i < 0);
		if (j < k) {
			return {};
		}

		assert(j < A.size() && k < A.size());

		const size_t isz = static_cast<size_t>(-i);
		const size_t N = (j - k) / isz + 1;
		matrix_d ans{ N, vector_d::allocator_type{} };
		for (size_t r = 0; r < N; r++) {
			ans[r] = A[j - r * isz];
		}

		return ans;
	}

	// ind2sub
	std::pair<size_t, size_t> ind2sub(const std::pair<size_t, size_t>& sz, size_t ind) {
		size_t col = ind / sz.first;
		size_t row = ind % sz.first;
		return { row, col };
	}

	std::vector<std::pair<size_t, size_t>> ind2sub(const std::pair<size_t, size_t>& sz, const std::vector<size_t>& ind) {
		std::vector<std::pair<size_t, size_t>> sub(ind.size());
		for (size_t i = 0; i < ind.size(); i++) {
			sub[i] = ind2sub(sz, ind[i]);
		}

		return sub;
	}

	// sub2ind
	size_t sub2ind(const std::pair<size_t, size_t>& sz, const std::pair<size_t, size_t>& sub) {
		return sz.first * sub.second + sub.first;
	}

	std::vector<size_t> sub2ind(const std::pair<size_t, size_t>& sz, const std::vector<std::pair<size_t, size_t>>& sub) {
		std::vector<size_t> ind(sub.size());
		for (size_t i = 0; i < sub.size(); i++) {
			ind[i] = sz.first * sub[i].second + sub[i].first;
		}

		return ind;
	}
#pragma endregion
}