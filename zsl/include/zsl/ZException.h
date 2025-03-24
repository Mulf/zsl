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

    // ��ȡ������
    int GetErrorCode() const noexcept;

    // ��ȡλ����Ϣ
    const std::string& GetLocation() const noexcept;

    // ��ȡ����ջ��Ϣ
    const std::string& GetStackTrace() const noexcept;

    // ��д what() ����
    const char* what() const noexcept override;

   
private:
    int m_errorCode;
    std::string m_message;
    std::string m_location;
    std::string m_stackTrace;
    mutable std::string m_fullMessage; // ����������Ϣ

    // ��ʼ������ϵͳ
    static void InitSymbols();

    // �������ϵͳ
    

    // ��ȡ����ջ
    static std::string CaptureStackTrace();

    // ����ϵͳ��ʼ����־
    static bool s_symbolsInitialized;
};

// ���쳣�׳��ĺ�
#define Z_THROW(errorCode, message) \
    throw ZException(errorCode, message, __FILE__, __LINE__, __FUNCTION__)

