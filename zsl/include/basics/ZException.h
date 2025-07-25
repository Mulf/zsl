#ifndef ZSL_BASICS_ZEXCEPTION_H
#define ZSL_BASICS_ZEXCEPTION_H

#include "defines.h"

#include <exception>
#include <string>
#include <vector>

namespace zsl {

enum class ZErrorCode {
  LANG_INVALID_INDEX = 1001,
  LANG_INVLAID_INDEX_RANGE = 1002,
  MATH_ZERO_DIVISOR = 2001,
  MATH_EMPTY_VEC = 2002,
  MATH_DIM_UNMATCH = 2003,
  MATH_INVALID_MATRIX = 2004,
  MATH_INVALID_LEN = 2005,
  FILE_NOT_EXIST = 3001,
  FILE_FAIL_TO_OPEN = 3002,

  UNKOWN = 9999
};

class ZException : public std::exception {
public:
  ZException(ZErrorCode errorCode, std::string message, const char *file,
             int line, const char *function);
  virtual ~ZException();

  // 获取错误码
  int error_code() const noexcept { return static_cast<int>(_errorCode); }

  // 获取位置信息
  const std::string &location() const noexcept { return _location; }

  // 获取调用栈信息
  const std::string &stacktrace() const noexcept { return _stackTrace; }

  // 重写 what() 方法
  const char *what() const noexcept override;

protected:
  void _append_message(const std::string &msg);

private:
  ZErrorCode _errorCode;
  std::string _message;
  std::string _location;
  std::string _stackTrace;
  mutable std::string _fullMessage; // 缓存完整信息

  // 获取调用栈
  static std::string _capture_stacktrace();

  // 初始化符号系统
  static void Init_Symbols();
  // 清理符号系统
  static void Cleanup_Symbols();

  // 符号系统初始化标志
  static bool s_symbolsInitialized;
};

class ZZeorDivisorException : public ZException {
public:
  ZZeorDivisorException(const char *file, int line, const char *function);
  virtual ~ZZeorDivisorException() override;
};

class ZEmptyVecException : public ZException {
public:
  ZEmptyVecException(const char *file, int line, const char *function);
  virtual ~ZEmptyVecException() override;
};

class ZDimUnmatchException : public ZException {
public:
  ZDimUnmatchException(const vector_d &v1, const vector_d &v2, const char *file,
                       int line, const char *function);
  virtual ~ZDimUnmatchException() override;

  // static bool dim_match(const vector_d& v1, const vector_d& v2);
  // static bool dim_match(const matrix_d& m, const matrix_d& v);
};

// class ZInvalidMatrixException : public ZException {
// public:
//     ZInvalidMatrixException(const matrix_d& A, const char* file, int line,
//     const char* function); virtual ~ZInvalidMatrixException() override;
// };

} // namespace zsl

// 简化异常抛出的宏
#define Z_THROW(errorCode, message)                                            \
  throw zsl::ZException(errorCode, message, __FILE__, __LINE__, __FUNCTION__)

#define Z_EXPECTOR_NON_ZERO_DIVISOR(d)                                         \
  if (d == 0) [[unlikely]]                                                     \
  throw zsl::ZZeorDivisorException(__FILE__, __LINE__, __FUNCTION__)

#define Z_EXPECT_NON_EMPTY_VEC(v)                                              \
  if (v.empty()) [[unlikely]]                                                  \
  throw zsl::ZEmptyVecException(__FILE__, __LINE__, __FUNCTION__)

#define Z_EXPECT_SAME_LEN(v1, v2)                                              \
  if (v1.size() != v2.size()) [[unlikely]]                                     \
  throw ZDimUnmatchException(v1, v2, __FILE__, __LINE__, __FUNCTION__)

#endif