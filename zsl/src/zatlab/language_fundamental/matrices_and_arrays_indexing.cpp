#include "zatlab/language_fundamental/matrices_and_arrays.h"

namespace zsl {
	Colon::Colon(size_t first, size_t last) :
		Colon(first, 1, last) {}
	
	Colon::Colon(size_t first, int interval, size_t last) :
		first{ first },
		interval{ interval },
		last { last } {
		if (interval == 0) {
			Z_THROW(ZErrorCode::LANG_INVLAID_INDEX_RANGE, "interval is 0");
		} 
		else if (interval > 0 && first > last) {
			Z_THROW(ZErrorCode::LANG_INVLAID_INDEX_RANGE, "interval > 0 while first > last");
		}
		else if (interval < 0 && first < last) {
			Z_THROW(ZErrorCode::LANG_INVLAID_INDEX_RANGE, "interval < 0 while first < last");
		}
	}

	vector_sz Colon::to_vector() const {
		const size_t N = count();
		vector_sz ans{ N, vector_sz::allocator_type{} };
		for (int r = 0; r < N; r++) {
			const int i = static_cast<int>(first) + r * interval;
			ans[static_cast<size_t>(r)] =  static_cast<size_t>(i);
		}

		return ans;
	}

	size_t Colon::count() const {
		if (interval > 0) {
			const size_t isz = static_cast<size_t>(interval);
			return (last -first) / isz + 1;
		}

		const size_t isz = static_cast<size_t>(-interval);
		return (first - last) / isz + 1;
	}


#pragma region Indexing
	// colon
	vector_d colon(double j, double k) {
		if (j > k) {
			return {};
		}

		size_t N = static_cast<size_t>(k - j) + 1;

		vector_d x{ N, vector_d::allocator_type{} };
		for (size_t i = 0; i < N; i++)
		{
			x[i] = j + static_cast<double>(i);
		}

		return x;
	}

	vector_sz colon(size_t j, size_t k) {
		if (j > k) {
			return {};
		}
		size_t N = static_cast<size_t>(k - j) + 1;

		vector_sz x{ N, vector_sz::allocator_type{} };
		for (size_t i = 0; i < N; i++)
		{
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
			return vector_d{ i };
		}

		size_t N = static_cast<size_t>((k - j) / i) + 1;
		vector_d x{ N, vector_d::allocator_type{} };
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
			vector_sz ans{ N, vector_sz::allocator_type{} };
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
		vector_sz ans{ N, vector_sz::allocator_type{} };
		for (size_t r = 0; r < N; r++) {
			ans[r] = j - r * isz;
		}

		return ans;
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
		if (i > 0) {
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

	vector_d block(const vector_d& v, const Colon& rng) {
		if (v.empty()) {
			return {};
		}

		const size_t N = rng.count();
		vector_d ans{ N, vector_d::allocator_type{} };
		for (int r = 0; r < N; r++) {
			const int i = static_cast<int>(rng.first) + r * rng.interval;
			ans[static_cast<size_t>(r)] = v[static_cast<size_t>(i)];
		}

		return ans;
	}

	vector_d set_block(const vector_d& v, const Colon& rng, const vector_d& w) {
		if (rng.count() != w.size()) {
			
		}

		return {};
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

	matrix_d cols(const matrix_d& A, const Colon& rng) {
		if (A.empty()) {
			return A;
		}

		if (rng.interval > 0) {
			matrix_d ans{ A.size(), matrix_d::allocator_type{} };
			for (size_t r = 0; r < A.size(); r++) {
				ans[r] = block(A[r], rng);
			}

			return ans;
		}

		matrix_d ans{ A.size(), vector_d::allocator_type{} };
		for (size_t r = 0; r < A.size(); r++) {
			ans[r] = block(A[r], rng);
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

	matrix_d rows(const matrix_d& A, const Colon& rng) {
		if (A.empty()) {
			return {};
		}

		if (rng.interval > 0) {
			const size_t isz = static_cast<size_t>(rng.interval);
			const size_t N = (rng.last - rng.first) / isz + 1;
			matrix_d ans{ N, vector_d::allocator_type{} };
			for (size_t r = 0; r < N; r++) {
				ans[r] = A[rng.first + r * isz];
			}

			return ans;
		}

		const size_t isz = static_cast<size_t>(-rng.interval);
		const size_t N = (rng.first - rng.last) / isz + 1;
		matrix_d ans{ N, vector_d::allocator_type{} };
		for (size_t r = 0; r < N; r++) {
			ans[r] = A[rng.first - r * isz];
		}
	}

	matrix_d block(const matrix_d& A, const Colon& rowRng, const Colon& colRng) {
		auto rowIndices = rowRng.to_vector();
		auto colIndices = colRng.to_vector();
		matrix_d ans = zeros(rowIndices.size(), colIndices.size());

		for (size_t i = 0; i < rowIndices.size(); i++) {
			for (size_t j = 0; j < colIndices.size(); j++) {
				ans[i][j] = A[rowIndices[i]][colIndices[j]];
			}
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