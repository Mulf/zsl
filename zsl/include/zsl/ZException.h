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

    // ��ȡ������
    int error_code() const noexcept {
        return _errorCode;
    }

    // ��ȡλ����Ϣ
    const std::string& location() const noexcept {
        return _location;
    }

    // ��ȡ����ջ��Ϣ
    const std::string& stacktrace() const noexcept {
        return _stackTrace;
    }

    // ��д what() ����
    const char* what() const noexcept override;

   
private:
    int _errorCode;
    std::string _message;
    std::string _location;
    std::string _stackTrace;
    mutable std::string _fullMessage; // ����������Ϣ

   
    

    // ��ȡ����ջ
    static std::string _capture_stacktrace();
   
    // ��ʼ������ϵͳ
    static void Init_Symbols();
    // �������ϵͳ
    static void Cleanup_Symbols();


    // ����ϵͳ��ʼ����־
    static bool s_symbolsInitialized;
};

// ���쳣�׳��ĺ�
#define Z_THROW(errorCode, message) \
    throw ZException(errorCode, message, __FILE__, __LINE__, __FUNCTION__)

