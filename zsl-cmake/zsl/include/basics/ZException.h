#pragma once 
#ifndef ZSL_BASICS_ZEXCEPTION_H
#define ZSL_BASICS_ZEXCEPTION_H

#include <exception>
#include <string>
#include <vector>

namespace zsl {

    enum class ZErrorCode {
        LANG_INVALID_INDEX = 1001,
        MATH_ZERO_DIVISOR = 2001,
        MATH_EMPTY_VEC = 2002,
        MATH_DIFF_VEC_LEN = 2003,
        
        UNKOWN = 9999
    };


    class ZException : public std::exception
    {
    public:

        ZException(ZErrorCode errorCode, std::string message, const char* file, int line, const char* function);
        virtual ~ZException();

        // ��ȡ������
        int error_code() const noexcept {
            return static_cast<int>(_errorCode);
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

    protected:
        void _append_message(const std::string& msg);

    private:
        ZErrorCode _errorCode;
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


    class ZZeorDivisorException : public ZException {
    public:
        ZZeorDivisorException(const char* file, int line, const char* function);
        virtual ~ZZeorDivisorException() override;
    };

    class ZEmptyVecException : public ZException {
    public:
        ZEmptyVecException(const char* file, int line, const char* function);
        virtual ~ZEmptyVecException() override;
    };
    
    class ZVecDiffLenException : public ZException {
    public:
        ZVecDiffLenException(const std::vector<double> &v1, const std::vector<double> &v2, const char* file, int line, const char* function);
        virtual ~ZVecDiffLenException() override;
    };

}

// ���쳣�׳��ĺ�
#define Z_THROW(errorCode, message) \
    throw zsl::ZException(errorCode, message, __FILE__, __LINE__, __FUNCTION__)

#define Z_EXPECTOR_NON_ZERO_DIVISOR(d) \
    if (d == 0) [[unlikely]] throw zsl::ZZeorDivisorException(__FILE__, __LINE__, __FUNCTION__)

#define Z_EXPECT_NON_EMPTY_VEC(v) \
    if (v.empty())[[unlikely]] throw zsl::ZEmptyVecException(__FILE__, __LINE__, __FUNCTION__)

#define Z_EXPECT_SAME_LEN(v1, v2) \
    if (v1.size() != v2.size())[[unlikely]] throw ZVecDiffLenException(v1, v2, __FILE__, __LINE__, __FUNCTION__)

#endif