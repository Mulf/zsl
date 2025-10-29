#pragma once

#include "defines.h"
#include <exception>
#include <string>
#include <vector>
#include <source_location>
#include <expected>

namespace zsl {

enum class ZErrorCode {
	NONE = 0,
	LANG_INVALID_INDEX = 101,
	LANG_INVALID_RANGE = 102,
	MATH_EMPTY_VEC = 201,
	MATH_INVALID_MATRIX = 202,
	MATH_ZERO_DIVISOR = 203,
	MATH_DIM_UNMATCH = 204,
	MATH_INVALID_LEN = 205,
	FILE_NOT_EXIST = 301,
	FILE_FAIL_TO_OPEN = 302,

	UNKOWN = 9999
};

class ZException : public std::exception {
public:
	ZException(std::source_location loc = std::source_location::current());
	ZException(ZErrorCode errorCode, std::string message,
		std::source_location loc = std::source_location::current());
	virtual ~ZException();

	int error_code() const noexcept {
		return static_cast<int>(_errorCode);
	}
	const std::string &location() const noexcept {
		return _location;
	}
	const std::string &stacktrace() const noexcept {
		return _stackTrace;
	}
	const char *what() const noexcept override;

protected:
	void _append_message(const std::string &msg);

private:
	ZErrorCode _errorCode;
	std::string _message;
	std::string _location;
	std::string _stackTrace;
	mutable std::string _fullMessage; // 缓存完整信息

};

// 简化异常抛出的宏
#define Z_THROW(errorCode, message)                                            \
  throw zsl::ZException(errorCode, message)

} // namespace zsl

