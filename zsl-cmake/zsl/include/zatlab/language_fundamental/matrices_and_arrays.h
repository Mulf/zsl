#ifndef ZSL_ZATLAB_LANGUAGE_FUNDAMENTAL_MATRICES_AND_ARRARYS_H
#define ZSL_ZATLAB_LANGUAGE_FUNDAMENTAL_MATRICES_AND_ARRARYS_H

#include "basics/basics.h"

namespace zsl {
#pragma region Create and Combine Arrays
	vector_d vcat(const vector_d& v1, const vector_d &v2);
	matrix_d cat(size_t dim, const matrix_d& A, const matrix_d& B);

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
}

#endif