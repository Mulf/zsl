#include "basics/ZException.h"

#include <map>
#include <sstream>
#include <stacktrace>
#include <format>


namespace zsl {

static std::map<ZErrorCode, std::string> ErrorInfoMap = {
	{ZErrorCode::LANG_INVALID_INDEX, "Index out range"},
	{ZErrorCode::LANG_INVALID_RANGE, "Invalid index range"},
	{ZErrorCode::MATH_ZERO_DIVISOR, "Divisor is 0"},
	{ZErrorCode::MATH_EMPTY_VEC, "Vector or matrix is empty"},
	{ZErrorCode::MATH_DIM_UNMATCH, "Dimensions of matrices(vectors) not match"},
	{ZErrorCode::MATH_INVALID_MATRIX, "Invalid matrix"},
	{ZErrorCode::MATH_INVALID_LEN, "Invalid length of vector"},
	{ZErrorCode::FILE_NOT_EXIST, "File or directory not exists"},
	{ZErrorCode::FILE_FAIL_TO_OPEN, "Fail to open file"}
};

ZException::ZException(std::source_location loc) :
	_errorCode{},
	_message{},
	_location{},
	_stackTrace{},
	_fullMessage{} {

	std::ostringstream ss;
	auto trace = std::stacktrace::current();
	for(const auto &entry : trace) {
		if(!entry.source_file().contains("cpp")) continue;
		ss << "file: " << entry.source_file() << ", "
			<< "line: " << entry.source_line() << ", "
			<< "description: " << entry.description() << "\n";
	}
	_stackTrace = ss.str();

	std::ostringstream locStream;
	locStream << loc.file_name() << "(line " << loc.line() << ") -> " << loc.function_name();
	_location = locStream.str();
}


ZException::ZException(ZErrorCode errorCode, std::string message, std::source_location loc) :
	_errorCode{errorCode},
	_message{},
	_location{},
	_stackTrace{},
	_fullMessage{} {
	// location info
	std::ostringstream locStream;
	locStream << loc.file_name() << "(line " << loc.line() << ") -> " << loc.function_name();
	_location = locStream.str();

	std::ostringstream ss;
	auto trace = std::stacktrace::current();
	for(const auto &entry : trace) {
		if(!entry.source_file().contains("cpp")) continue;
		ss << "file: " << entry.source_file() << ", "
			<< "line: " << entry.source_line() << ", "
			<< "description: " << entry.description() << "\n";
	}
	_stackTrace = ss.str();

	if(message.empty()) {
		if(ErrorInfoMap.contains(_errorCode)) {
			_message = ErrorInfoMap.at(_errorCode);
		} else {
			_message = "Undefined Error";
		}
	} else {
		if(ErrorInfoMap.contains(_errorCode)) {
			_message = std::format("{} -> {}", ErrorInfoMap.at(_errorCode), message);
		} else {
			_message = std::format("Undefined Error: [{}]", message);
		}
	}
}

ZException::~ZException() = default;

void ZException::_append_message(const std::string &msg) {
	if(msg.empty()) {
		_message = msg;
	} else {
		_message += ", " + msg;
	}
}

const char *ZException::what() const noexcept {
	std::ostringstream fullStream;
	fullStream << "Error [" << static_cast<int>(_errorCode) << "]: " << _message << "\n"
		<< "Location: " << _location << "\n"
		<< "Stack trace:\n"
		<< _stackTrace;
	_fullMessage = fullStream.str();

	return _fullMessage.c_str();
}

} // namespace zsl