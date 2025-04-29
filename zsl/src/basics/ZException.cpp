#include "basics/ZException.h"

#include <windows.h>
#include <dbghelp.h>
#include <map>
#include <sstream>


#pragma comment(lib, "dbghelp.lib")

namespace zsl {

static std::map<ZErrorCode, std::string> ErrorInfoMap = {
    {ZErrorCode::LANG_INVALID_INDEX, "Index out range"},
    {ZErrorCode::LANG_INVLAID_INDEX_RANGE, "Invalid index range"},
    {ZErrorCode::MATH_ZERO_DIVISOR, "Divisor is 0"},
    {ZErrorCode::MATH_EMPTY_VEC, "Vector or matrix is empty"},
    {ZErrorCode::MATH_DIM_UNMATCH,
     "Dimensions of matrices(vectors) are different"},
    {ZErrorCode::MATH_INVALID_MATRIX, "Invalid matrix"}};

bool ZException::s_symbolsInitialized = false;

ZException::ZException(ZErrorCode errorCode, std::string message,
                       const char *file, int line, const char *function)
    : _errorCode{errorCode}, _message{} {
  // 构建位置信息
  std::ostringstream locStream;
  locStream << file << ":" << line << " in " << function;
  _location = locStream.str();

  // 获取调用栈
  _stackTrace = _capture_stacktrace();

  if (_message.empty()) {
    if (ErrorInfoMap.find(_errorCode) != ErrorInfoMap.end()) {
      _message = ErrorInfoMap.at(_errorCode);
    } else {
      _message = "Unknown Error";
    }
  } else {
    if (ErrorInfoMap.find(_errorCode) != ErrorInfoMap.end()) {
      _message = ErrorInfoMap.at(_errorCode) + ": [" + message + "]";
    } else {
      _message = "Unknown Error: [" + message + "]";
    }
  }

  // 确保符号系统已初始化
  Init_Symbols();
}

ZException::~ZException() { Cleanup_Symbols(); }

void ZException::_append_message(const std::string &msg) {
  if (msg.empty()) {
    _message = msg;
  } else {
    _message += ", " + msg;
  }
}

const char *ZException::what() const noexcept {
  // 构建完整错误信息
  std::ostringstream fullStream;
  fullStream << "Error [" << static_cast<int>(_errorCode) << "]: " << _message
             << "\n"
             << "Location: " << _location << "\n"
             << "Stack trace:\n"
             << _stackTrace;
  _fullMessage = fullStream.str();

  return _fullMessage.c_str();
}

std::string ZException::_capture_stacktrace() {
  std::stringstream ss;
  SymInitialize(GetCurrentProcess(), NULL, TRUE);

  void *stack[100];
  USHORT frames = CaptureStackBackTrace(2, 99, stack, NULL);

  SYMBOL_INFO *symbol =
      (SYMBOL_INFO *)malloc(sizeof(SYMBOL_INFO) + 256 * sizeof(char));
  if (symbol == NULL)
    return std::string{"Fail to allocate memory for SYMBOL_INFO"};
  symbol->MaxNameLen = 255;
  symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
  DWORD64 displacement;

  for (USHORT i = 0; i < frames; i++) {
    DWORD64 address = (DWORD64)stack[i];
    if (SymFromAddr(GetCurrentProcess(), address, &displacement, symbol)) {
      IMAGEHLP_LINE64 line{};
      line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
      DWORD lineDisplacement;

      if (SymGetLineFromAddr64(GetCurrentProcess(), address, &lineDisplacement,
                               &line)) {
        ss << "  " << symbol->Name << " + " << displacement
           << " (Line: " << line.LineNumber << ", File: " << line.FileName
           << ")\n";
      } else {
        ss << "  " << symbol->Name << " + " << displacement
           << " (Line info not available)\n";
      }
    } else {
      ss << "  0x" << std::hex << address << std::dec
         << " (Symbol not found)\n";
    }
  }

  free(symbol);
  SymCleanup(GetCurrentProcess());

  return ss.str();
}

void ZException::Init_Symbols() {
  if (!s_symbolsInitialized) {
    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);
    if (!SymInitialize(GetCurrentProcess(), nullptr, TRUE)) {
      // 如果初始化失败，可以记录日志，但不抛出异常避免递归
      OutputDebugStringA("Failed to initialize debug symbols\n");
    }
    s_symbolsInitialized = true;
  }
}

void ZException::Cleanup_Symbols() {
  if (s_symbolsInitialized) {
    SymCleanup(GetCurrentProcess());
    s_symbolsInitialized = false;
  }
}

ZZeorDivisorException::ZZeorDivisorException(const char *file, int line,
                                             const char *function)
    : ZException(ZErrorCode::MATH_ZERO_DIVISOR, "", file, line, function) {}

ZZeorDivisorException::~ZZeorDivisorException() = default;

ZEmptyVecException::ZEmptyVecException(const char *file, int line,
                                       const char *function)
    : ZException(ZErrorCode::MATH_EMPTY_VEC, "", file, line, function) {}

ZEmptyVecException::~ZEmptyVecException() = default;

ZDimUnmatchException::ZDimUnmatchException(const vector_d &v1,
                                           const vector_d &v2, const char *file,
                                           int line, const char *function)
    : ZException(ZErrorCode::MATH_DIM_UNMATCH, "", file, line, function) {
  std::string msg{};
  msg += "length of v1 is: " + std::to_string(v1.size());
  msg += ", length of v2 is: " + std::to_string(v2.size());
  _append_message(msg);
}

ZDimUnmatchException::~ZDimUnmatchException() = default;

} // namespace zsl