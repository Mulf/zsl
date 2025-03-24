#pragma once 
#include <exception>
#include <exception>
#include <string>


enum class ZErrorCode {
    InvalidParam = 1001,
    IlegalArg = 1002,
    Other
};


class ZException : public std::exception
{
public:

    ZException(int errorCode, const std::string& message, const char* file, int line, const char* function);
    ~ZException();

    // 获取错误码
    int error_code() const noexcept {
        return _errorCode;
    }

    // 获取位置信息
    const std::string& location() const noexcept {
        return _location;
    }

    // 获取调用栈信息
    const std::string& stacktrace() const noexcept {
        return _stackTrace;
    }

    // 重写 what() 方法
    const char* what() const noexcept override;

   
private:
    int _errorCode;
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

// 简化异常抛出的宏
#define Z_THROW(errorCode, message) \
    throw ZException(errorCode, message, __FILE__, __LINE__, __FUNCTION__)

