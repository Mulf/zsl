#ifndef ZSL_ZATLAB_LANGUAGE_FUNDAMENTAL_MATRICES_AND_ARRARYS_H
#define ZSL_ZATLAB_LANGUAGE_FUNDAMENTAL_MATRICES_AND_ARRARYS_H

#include "basics/basics.h"
#include <utility>
#include <optional>

namespace zsl {
#pragma region Create and Combine Arrays
	vector_d cat(const vector_d& v1, const vector_d &v2);
	matrix_d cat(size_t dim, const matrix_d& A, const matrix_d& B);

	matrix_d diag(const vector_d &v);
	matrix_d diag(const vector_d& v, int k);
	vector_d diag(const matrix_d& A);
	vector_d diag(const matrix_d& A, int k);

	matrix_d eye(size_t n);
	matrix_d eye(size_t n, size_t m);

	matrix_d horzcat(const matrix_d& A, const matrix_d& B);
	matrix_d horzcat(const matrix_d& A, const vector_d& v);
	vector_d horzcat(const vector_d& v, const vector_d& w);

	matrix_d vertcat(const matrix_d& A, const matrix_d& B);

	vector_d vones(size_t n);
	matrix_d ones(size_t n);
	matrix_d ones(size_t sz1, size_t sz2);

	vector_d vzeros(size_t n);
	matrix_d zeros(size_t n);
	matrix_d zeros(size_t n);
	matrix_d zeros(size_t sz1, size_t sz2);
#pragma endregion 

#pragma region Create Grids
	vector_d linspace(double x1, double x2);
	vector_d linspace(double x1, double x2, size_t n);
#pragma endregion

#pragma region Determine Size, Shape, and Order
	double length(const vector_d& v);
	double length(const matrix_d& A);

	double numel(const vector_d& v);
	double numel(const matrix_d& A);

	double size(const vector_d& v);
	vector_d size(const matrix_d& A);
	double size(const matrix_d& A, size_t dim);
#pragma endregion 

#pragma region Resize, Reshape, and Rearrange
	// Resize 
	matrix_d head(const matrix_d& A);
	matrix_d head(const matrix_d& A, size_t k);

	matrix_d tail(const matrix_d& A);
	matrix_d tail(const matrix_d& A, size_t k);

	// Reshape
	matrix_d reshape(const vector_d& v, const std::pair<size_t, size_t>& sz);
	matrix_d reshape(const matrix_d& A, const std::pair<size_t, size_t>& sz);
	matrix_d reshape(const vector_d& v, std::optional<size_t> sz1, std::optional<size_t> sz2);
	matrix_d reshape(const matrix_d& A, std::optional<size_t> sz1, std::optional<size_t> sz2);

	// Rearrange
	vector_d circshift(const vector_d& v, int k);
	matrix_d circshift(const matrix_d& A, int k);
	matrix_d circshift(const matrix_d& A, int k, size_t dim);
	matrix_d circshift(const matrix_d& A, std::pair<int, int> K);
	
	vector_d flip(const vector_d& v);
	vector_d &flip_self(vector_d& v);
	matrix_d flip(const matrix_d&A);
	matrix_d &flip_self(matrix_d& A);
	matrix_d flip(const matrix_d& A, size_t dim);
	matrix_d &flip_self(matrix_d& A, size_t dim);

#pragma endregion


#pragma region Indexing
	vector_d colon(double j, double k);
	vector_d colon(double j, double i, double k);
	vector_d colon(const vector_d& v);
	vector_d colon(const matrix_d& A);
	vector_d colon(const vector_d& v, size_t j, size_t k);
	vector_d colon(const vector_d& v, size_t j, int i, size_t k);
	//matrix_d colon(const matrix_d& A, size_t j, size_t k);
	vector_d col(const matrix_d& A, size_t n);
	matrix_d cols(const matrix_d& A, size_t j, size_t k);
	matrix_d cols(const matrix_d &A, size_t j,  int i, size_t k);
	vector_d row(const matrix_d& A, size_t m);
	matrix_d rows(const matrix_d& A, size_t j, size_t k);
	matrix_d rows(const matrix_d& A, size_t j, int i, size_t k);

	// ind2sub
	std::pair<size_t, size_t> ind2sub(const std::pair<size_t, size_t>& sz, size_t ind);
	std::vector<std::pair<size_t, size_t>> ind2sub(const std::pair<size_t, size_t> &sz, const std::vector<size_t> &ind);

	// sub2ind
	size_t sub2ind(const std::pair<size_t, size_t>& sz, const std::pair<size_t, size_t>& sub);
	std::vector<size_t> sub2ind(const std::pair<size_t, size_t>& sz, const std::vector<std::pair<size_t, size_t>>& sub);
#pragma endregion
}

#endif