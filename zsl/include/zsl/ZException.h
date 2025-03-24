#pragma once 
#include <exception>


#pragma once

#include <windows.h>
#include <dbghelp.h>
#include <exception>
#include <string>
#include <sstream>

#pragma comment(lib, "dbghelp.lib")

class ZException : public std::exception
{
public:
    static void CleanupSymbols();

    ZException(int errorCode, const std::string& message, const char* file, int line, const char* function);

    // 获取错误码
    int GetErrorCode() const noexcept;

    // 获取位置信息
    const std::string& GetLocation() const noexcept;

    // 获取调用栈信息
    const std::string& GetStackTrace() const noexcept;

    // 重写 what() 方法
    const char* what() const noexcept override;

   
private:
    int m_errorCode;
    std::string m_message;
    std::string m_location;
    std::string m_stackTrace;
    mutable std::string m_fullMessage; // 缓存完整信息

    // 初始化符号系统
    static void InitSymbols();

    // 清理符号系统
    

    // 获取调用栈
    static std::string CaptureStackTrace();

    // 符号系统初始化标志
    static bool s_symbolsInitialized;
};

// 简化异常抛出的宏
#define Z_THROW(errorCode, message) \
    throw ZException(errorCode, message, __FILE__, __LINE__, __FUNCTION__)

