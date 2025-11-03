#pragma once
#include "defines.h"
#include "ZException.h"

#include <format>
#include <filesystem>


namespace zsl
{
template<typename T>
void expect_valid_index(const std::vector<T> &v, size_t i, std::source_location loc = std::source_location::current()) {
	if(i >= v.size()) {
		std::string msg = std::format("index({}) is not less than length({}) of vector", i, v.size());
		throw ZException{ZErrorCode::LANG_INVALID_INDEX, std::move(msg), std::move(loc)};
	}
}

template<typename T>
void expect_valid_index(const std::vector<std::vector<T>> &A, size_t i, size_t j, std::source_location loc = std::source_location::current()) {
	if(i >= A.size()) {
		std::string msg = std::format("row index({}) is not less than row count({}) of matrix", i, A.size());
		throw ZException{ZErrorCode::LANG_INVALID_INDEX, std::move(msg), std::move(loc)};
	}
	if(j >= A.at(0).size()) {
		std::string msg = std::format("column index({}) is not less than column count({}) of matrix", j, A.at(0).size());
		throw ZException{ZErrorCode::LANG_INVALID_INDEX, std::move(msg), std::move(loc)};
	}
}

template<typename T>
void expect_valid_range(const std::vector<T> &v, size_t first, size_t last, std::source_location loc = std::source_location::current())
{
	if(first >= v.size()) {
		std::string msg = std::format("start index({}) is greater than length({}) of vector", first, v.size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(last >= v.size()) {
		std::string msg = std::format("end index({}) is greater than length({}) of vector", last, v.size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(first > last) {
		std::string msg = std::format("start index({}) is greater than end index({})", first, last);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
}

template<typename T>
void expect_valid_range(const std::vector<T> &v, size_t first, int interval, size_t last, std::source_location loc = std::source_location::current())
{
	if(first >= v.size()) {
		std::string msg = std::format("start index({}) is greater than length({}) of vector", first, v.size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(last >= v.size()) {
		std::string msg = std::format("end index({}) is greater than length({}) of vector", last, v.size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(interval == 0) {
		std::string msg = std::format("interval is 0");
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(interval > 0 && first > last) {
		std::string msg = std::format("start index({}) is greater than end index({}), while interval({}) is greater than 0", first, last, interval);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(interval < 0 && first < last) {
		std::string msg = std::format("start index({}) is less than end index({}), while interval({}) is less than 0", first, last, interval);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
}

template<typename T>
void expect_valid_range(const std::vector<std::vector<T>> &A, size_t i, size_t j, size_t m, size_t n, std::source_location loc = std::source_location::current())
{
	if(i >= A.size()) {
		std::string msg = std::format("row start index({}) is greater than row count({}) of matrix", i, A.size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(j >= A.size()) {
		std::string msg = std::format("row end index({}) is greater than row count({}) of matrix", j, A.size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(m >= A.at(0).size()) {
		std::string msg = std::format("column start index({}) is greater than column count({}) of matrix", m, A.at(0).size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(n >= A.at(0).size()) {
		std::string msg = std::format("column end index({}) is greater than column count({}) of matrix", n, A.at(0).size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(i > j) {
		std::string msg = std::format("row start index({}) is greater than row end index({})", i, j);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(m > n) {
		std::string msg = std::format("column start index({}) is greater than column end index({})", m, n);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
}

template<typename T>
void expect_valid_range(const std::vector<std::vector<T>> &A, size_t i, int a, size_t j, size_t m, int b, size_t n, std::source_location loc = std::source_location::current())
{
	if(i >= A.size()) {
		std::string msg = std::format("row start index({}) is greater than row count({}) of matrix", i, A.size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(j >= A.size()) {
		std::string msg = std::format("row end index({}) is greater than row count({}) of matrix", j, A.size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(m >= A.at(0).size()) {
		std::string msg = std::format("column start index({}) is greater than column count({}) of matrix", m, A.at(0).size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(n >= A.at(0).size()) {
		std::string msg = std::format("column end index({}) is greater than column count({}) of matrix", n, A.at(0).size());
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(a == 0) {
		std::string msg = std::format("row interval is 0");
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(a > 0 && i > j) {
		std::string msg = std::format("row start index({}) is greater than row end index({}), while row interval({}) is greater than 0", i, j, a);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(a < 0 && i < j) {
		std::string msg = std::format("row start index({}) is less than row end index({}), while row interval({}) is less than 0", i, j, a);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(b == 0) {
		std::string msg = std::format("column interval is 0");
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(b > 0 && m > n) {
		std::string msg = std::format("column start index({}) is greater than column end index({}), while row interval({}) is greater than 0", m, n, b);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
	if(b < 0 && m < n) {
		std::string msg = std::format("column start index({}) is less than row column index({}), while column interval({}) is less than 0", m, n, b);
		throw ZException{ZErrorCode::LANG_INVALID_RANGE, std::move(msg), std::move(loc)};
	}
}

template<typename T>
void expect_not_empty(const std::vector<T> &v, std::source_location loc = std::source_location::current()) {
	if(v.empty()) {
		throw ZException{ZErrorCode::MATH_EMPTY_VEC, "vector is empty", std::move(loc)};
	}
}

template<typename T>
void expect_not_empty(const std::vector<std::vector<T>> &A, std::source_location loc = std::source_location::current()) {
	if(A.empty()) {
		throw ZException{ZErrorCode::MATH_EMPTY_VEC, "matrix is empty", std::move(loc)};
	}

	for(size_t i = 0; i < A.size(); i++) {
		if(A.at(i).empty()) {
			std::string msg = std::format("row is empty at [{}]", i);
			throw ZException{ZErrorCode::MATH_EMPTY_VEC, std::move(msg), std::move(loc)};
		}
	}
}

template<typename T>
void expect_valid_matrix(const std::vector<std::vector<T>> &A, std::source_location loc = std::source_location::current())
{
	size_t firstCol = A.at(0).size();
	for(size_t i = 0; i < A.size(); i++) {
		if(A.at(i).size() != firstCol) {
			std::string msg = std::format("column count({}) at row ({}) is different with column count({}) at first row", A.at(i).size(), i, firstCol);
			throw ZException{ZErrorCode::MATH_INVALID_MATRIX, std::move(msg), std::move(loc)};
		}
	}
}

template<typename T>
void expect_no_zero(const std::vector<T> &v, std::source_location loc = std::source_location::current())
{
	size_t zeroIdx = 0;
	bool hasZero = false;
	for(size_t i = 0; i < v.size(); i++) {
		if(v.at(i) == T{}) {
			zeroIdx = i;
			hasZero = true;
			break;
		}
	}
	if(hasZero) {
		std::string msg = std::format("zero at [{}]", zeroIdx);
		throw ZException{ZErrorCode::MATH_ZERO_DIVISOR, std::move(msg), std::move(loc)};
	}
}

template<typename T>
void expect_no_zero(const std::vector<std::vector<T>> &A, std::source_location loc = std::source_location::current())
{
	size_t zeroRow = 0;
	size_t zeroCol = 0;
	bool hasZero = false;
	for(size_t i = 0; i < A.size(); i++) {
		for(size_t j = 0; j < A.at(i).size(); j++) {
			if(A.at(i).at(j) == T{}) {
				zeroRow = i;
				zeroCol = j;
				hasZero = true;
				break;
			}
		}
	}
	if(hasZero) {
		std::string msg = std::format("zero at [{}£¬ {}]", zeroRow, zeroCol);
		throw ZException{ZErrorCode::MATH_ZERO_DIVISOR, std::move(msg), std::move(loc)};
	}
}

template<typename T, typename U>
void expect_dim_match(const std::vector<T> &v, const std::vector<U> &w, std::source_location loc = std::source_location::current())
{
	if(v.size() != w.size()) {
		std::string msg = std::format("length({}) of vector 1 is different with length({}) of vector 2", v.size(), w.size());
		throw ZException{ZErrorCode::MATH_DIM_UNMATCH, std::move(msg), std::move(loc)};
	}
}

template<typename T, typename U>
void expect_dim_match(const  std::vector<std::vector<T>> &A, const std::vector<U> &v, std::source_location loc = std::source_location::current()) {
	if(A.size() != v.size()) {
		std::string msg = std::format("row count({}) of matrix is different with length({}) of vector", A.size(), v.size());
		throw ZException{ZErrorCode::MATH_DIM_UNMATCH, std::move(msg), std::move(loc)};
	}
}

template<typename T, typename U>
void expect_dim_match(const std::vector<T> &v, const std::vector<std::vector<U>> &A, std::source_location loc = std::source_location::current()) {
	if(A.size() != v.size()) {
		std::string msg = std::format("length({}) of vector is different with row count({}) of matrix", v.size(), A.size());
		throw ZException{ZErrorCode::MATH_DIM_UNMATCH, std::move(msg), std::move(loc)};
	}
}

template<typename T, typename U>
void expect_dim_match(const std::vector<std::vector<T>> &A, const std::vector<std::vector<U>> &B, std::source_location loc = std::source_location::current())
{
	if(A.size() != B.size()) {
		std::string msg = std::format("row count of matrix 1({}) is different with row count of matrix 2({})", A.size(), B.size());
		throw ZException{ZErrorCode::MATH_DIM_UNMATCH, std::move(msg), std::move(loc)};
	}

	if(A.at(0).size() != B.at(0).size()) {
		std::string msg = std::format("column count of matrix 1({}) is different with column count of matrix 2({})", A.at(0).size(), B.at(0).size());
		throw ZException{ZErrorCode::MATH_DIM_UNMATCH, std::move(msg), std::move(loc)};
	}
}

template<typename T>
void expect_len_gt(const std::vector<T> &v, size_t len, std::source_location loc = std::source_location::current())
{
	if(v.size() <= len) {
		std::string msg = std::format("length({}) of vector must be greater than ({}) ", v.size(), len);
		throw ZException{ZErrorCode::MATH_INVALID_LEN, std::move(msg), std::move(loc)};
	}
}

inline void expect_file_exist(const std::string &filepath, std::source_location loc = std::source_location::current())
{
	std::filesystem::path filePath{filepath};

	if(!std::filesystem::exists(filePath)) {
		std::string msg = std::format("file {} not exist", filepath);
		throw ZException{ZErrorCode::FILE_NOT_EXIST, std::move(msg), std::move(loc)};
	}
}

}
