#ifndef ZSL_ZATLAB_LANGUAGE_FUNDAMENTAL_MATRICES_AND_ARRARYS_H
#define ZSL_ZATLAB_LANGUAGE_FUNDAMENTAL_MATRICES_AND_ARRARYS_H

#include "basics/basics.h"

#include <optional>
#include <utility>

namespace zsl {
#pragma region Create and Combine Arrays
// cat
vector_d cat(const vector_d &v1, const vector_d &v2);
vector2_d cat(size_t dim, const vector2_d &A, const vector2_d &B);

// diag
vector2_d diag(const vector_d &v);
vector2_d diag(const vector_d &v, int k);
vector_d diag(const vector2_d &A);
vector_d diag(const vector2_d &A, int k);

// eye
vector2_d eye(size_t n);
vector2_d eye(size_t n, size_t m);

// horzcat
vector2_d horzcat(const vector2_d &A, const vector2_d &B);
vector2_d horzcat(const vector2_d &A, const vector_d &v);
vector_d horzcat(const vector_d &v, const vector_d &w);

// vertcat
vector2_d vertcat(const vector2_d &A, const vector2_d &B);
vector_d vertcat(const vector_d &v, const vector_d &w);

// ones
vector_d ones_v(size_t n);
vector2_d ones(size_t n);
vector2_d ones(size_t sz1, size_t sz2);

// zeros
vector_d zeros_v(size_t n);
vector2_d zeros(size_t n);
vector2_d zeros(size_t n);
vector2_d zeros(size_t sz1, size_t sz2);
#pragma endregion

#pragma region Create Grids
// linspace
vector_d linspace(double x1, double x2);
vector_d linspace(double x1, double x2, size_t n);
#pragma endregion

#pragma region Determine Size, Shape, and Order
// length
size_t length(const vector_d &v);
size_t length(const vector2_d &A);
size_t length(const vector2_c &A);

size_t numel(const vector_d &v);
size_t numel(const vector2_d &A);
size_t numel(const vector2_c &A);

size_t size(const vector_d &v);
vector_sz size(const vector2_d &A);
size_t size(const vector2_d &A, size_t dim);
size_t size(const vector_c &v);
vector_sz size(const vector2_c &A);
size_t size(const vector2_c &A, size_t dim);
#pragma endregion

#pragma region Resize, Reshape, and Rearrange
// Resize
vector2_d head(const vector2_d &A);
vector2_d head(const vector2_d &A, size_t k);

vector2_d tail(const vector2_d &A);
vector2_d tail(const vector2_d &A, size_t k);

// Reshape
vector2_d reshape(const vector_d &v, const std::pair<size_t, size_t> &sz);
vector2_d reshape(const vector2_d &A, const std::pair<size_t, size_t> &sz);
vector2_d reshape(const vector_d &v, std::optional<size_t> sz1,
                 std::optional<size_t> sz2);
vector2_d reshape(const vector2_d &A, std::optional<size_t> sz1,
                 std::optional<size_t> sz2);

// Rearrange
vector_d circshift(const vector_d &v, int k);
vector_c circshift(const vector_c &v, int k);
vector2_d circshift(const vector2_d &A, int k);
vector2_d circshift(const vector2_d &A, int k, size_t dim);
vector2_d circshift(const vector2_d &A, std::pair<int, int> K);

vector_d flip(const vector_d &v);
vector_d &flip_self(vector_d &v);
vector2_d flip(const vector2_d &A);
vector2_d &flip_self(vector2_d &A);
vector2_d flip(const vector2_d &A, size_t dim);
vector2_d &flip_self(vector2_d &A, size_t dim);

#pragma endregion

#pragma region Indexing
struct Colon {
  size_t first;
  size_t last;
  int interval;
  Colon(size_t first, size_t last);
  Colon(size_t first, int interval, size_t last);

  COPYABLE(Colon);

  vector_sz to_vector() const;
  size_t count() const;
};
vector_d colon(double j, double k);
vector_sz colon(size_t j, size_t k);
vector_d colon(double j, double i, double k);
vector_sz colon(size_t j, int i, size_t k);

// block for real matrix/vector
vector_d colon(const vector_d &v);
vector_d colon(const vector2_d &A);
vector_d block(const vector_d &v, const Colon &rng);
vector_d block(const vector_d &v, const vector_sz &indices);
vector_d set_block(const vector_d &v, const Colon &rng, const vector_d &w);
vector_d set_block(const vector_d &v, const vector_sz &indices,
                   const vector_d &w);
vector_d &set_block_self(vector_d &v, const Colon &rng, const vector_d &w);
vector_d &set_block_self(vector_d &v, const vector_sz &rng, const vector_d &w);
vector_d col(const vector2_d &A, size_t n);
vector2_d set_col(const vector2_d &A, size_t n, const vector_d &v);
vector2_d &set_col_self(vector2_d &A, size_t n, const vector_d &v);
vector2_d cols(const vector2_d &A, const Colon &rng);
vector2_d set_cols(const vector2_d &A, const Colon &rng, const vector2_d &V);
vector2_d &set_cols_self(vector2_d &A, const Colon &rng, const vector2_d &V);
vector2_d cols(const vector2_d &A, const vector_sz &indices);
vector2_d set_cols(const vector2_d &A, const vector_sz &indices,
                  const vector2_d &V);
vector2_d &set_cols_self(vector2_d &A, const vector_sz &indices,
                        const vector2_d &V);
vector_d row(const vector2_d &A, size_t m);
vector2_d set_row(const vector2_d &A, size_t m, const vector_d &v);
vector2_d &set_row_self(vector2_d &A, size_t m, const vector_d &v);
vector2_d rows(const vector2_d &A, const Colon &rng);
vector2_d set_rows(const vector2_d &A, const Colon &rng, const vector2_d &V);
vector2_d &set_rows_self(vector2_d &A, const Colon &rng, const vector2_d &V);
vector2_d rows(const vector2_d &A, const vector_sz &indices);
vector2_d set_rows(const vector2_d &A, const vector_sz &indices,
                  const vector2_d &V);
vector2_d &set_rows_self(vector2_d &A, const vector_sz &indices,
                        const vector2_d &V);
vector2_d block(const vector2_d &A, const Colon &rowRng, const Colon &colRng);
vector2_d set_block(const vector2_d &A, const Colon &rowRng, const Colon &colRng,
                   const vector2_d &B);
vector2_d &set_block_self(vector2_d &A, const Colon &rowRng, const Colon &colRng,
                         const vector2_d &B);
vector2_d block(const vector2_d &A, const vector_sz &rowIndices,
               const vector_sz &colIndices);
vector2_d set_block(const vector2_d &A, const vector_sz &rowIndices,
                   const vector_sz &colIndices, const vector2_d &B);
vector2_d &set_block_self(vector2_d &A, const vector_sz &rowIndices,
                         const vector_sz &colIndices, const vector2_d &B);
vector2_d block(const vector2_d &A, const vector_sz &rowIndices,
               const Colon &colRng);
vector2_d set_block(const vector2_d &A, const vector_sz &rowIndices,
                   const Colon &colRng, const vector2_d &B);
vector2_d &set_block_self(vector2_d &A, const vector_sz &rowIndices,
                         const Colon &colRng, const vector2_d &B);
vector2_d block(const vector2_d &A, const Colon &rowRng,
               const vector_sz &colIndices);
vector2_d set_block(const vector2_d &A, const Colon &rowRng,
                   const vector_sz &colIndices, const vector2_d &B);
vector2_d &set_block_self(vector2_d &A, const Colon &rowRng,
                         const vector_sz &colIndices, const vector2_d &B);
// block for complex matrix/vector
vector_c colon(const vector_c &v);
vector_c colon(const vector2_c &A);
vector_c block(const vector_c &v, const Colon &rng);
vector_c block(const vector_c &v, const vector_sz &indices);
vector_c set_block(const vector_c &v, const Colon &rng, const vector_c &w);
vector_c set_block(const vector_c &v, const vector_sz &indices,
                   const vector_c &w);
vector_c &set_block_self(vector_c &v, const Colon &rng, const vector_c &w);
vector_c &set_block_self(vector_c &v, const vector_sz &rng, const vector_c &w);
vector_c col(const vector2_c &A, size_t n);
vector2_c set_col(const vector2_c &A, size_t n, const vector_c &v);
vector2_c &set_col_self(vector2_c &A, size_t n, const vector_c &v);
vector2_c cols(const vector2_c &A, const Colon &rng);
vector2_c set_cols(const vector2_c &A, const Colon &rng, const vector2_c &V);
vector2_c &set_cols_self(vector2_c &A, const Colon &rng, const vector2_c &V);
vector2_c cols(const vector2_c &A, const vector_sz &indices);
vector2_c set_cols(const vector2_c &A, const vector_sz &indices,
                  const vector2_c &V);
vector2_c &set_cols_self(vector2_c &A, const vector_sz &indices,
                        const vector2_c &V);
vector_c row(const vector2_c &A, size_t m);
vector2_c set_row(const vector2_c &A, size_t m, const vector_c &v);
vector2_c &set_row_self(vector2_c &A, size_t m, const vector_c &v);
vector2_c rows(const vector2_c &A, const Colon &rng);
vector2_c set_rows(const vector2_c &A, const Colon &rng, const vector2_c &V);
vector2_c &set_rows_self(vector2_c &A, const Colon &rng, const vector2_c &V);
vector2_c rows(const vector2_c &A, const vector_sz &indices);
vector2_c set_rows(const vector2_c &A, const vector_sz &indices,
                  const vector2_c &V);
vector2_c &set_rows_self(vector2_c &A, const vector_sz &indices,
                        const vector2_c &V);
vector2_c block(const vector2_c &A, const Colon &rowRng, const Colon &colRng);
vector2_c set_block(const vector2_c &A, const Colon &rowRng, const Colon &colRng,
                   const vector2_c &B);
vector2_c &set_block_self(vector2_c &A, const Colon &rowRng, const Colon &colRng,
                         const vector2_c &B);
vector2_c block(const vector2_c &A, const vector_sz &rowIndices,
               const vector_sz &colIndices);
vector2_c set_block(const vector2_c &A, const vector_sz &rowIndices,
                   const vector_sz &colIndices, const vector2_c &B);
vector2_c &set_block_self(vector2_c &A, const vector_sz &rowIndices,
                         const vector_sz &colIndices, const vector2_c &B);
vector2_c block(const vector2_c &A, const vector_sz &rowIndices,
               const Colon &colRng);
vector2_c set_block(const vector2_c &A, const vector_sz &rowIndices,
                   const Colon &colRng, const vector2_c &B);
vector2_c &set_block_self(vector2_c &A, const vector_sz &rowIndices,
                         const Colon &colRng, const vector2_c &B);
vector2_c block(const vector2_c &A, const Colon &rowRng,
               const vector_sz &colIndices);
vector2_c set_block(const vector2_c &A, const Colon &rowRng,
                   const vector_sz &colIndices, const vector2_c &B);
vector2_c &set_block_self(vector2_c &A, const Colon &rowRng,
                         const vector_sz &colIndices, const vector2_c &B);

// ind2sub
std::pair<size_t, size_t> ind2sub(const std::pair<size_t, size_t> &sz,
                                  size_t ind);
std::vector<std::pair<size_t, size_t>>
ind2sub(const std::pair<size_t, size_t> &sz, const std::vector<size_t> &ind);

// sub2ind
size_t sub2ind(const std::pair<size_t, size_t> &sz,
               const std::pair<size_t, size_t> &sub);
std::vector<size_t> sub2ind(const std::pair<size_t, size_t> &sz,
                            const std::vector<std::pair<size_t, size_t>> &sub);
#pragma endregion
} // namespace zsl

#endif