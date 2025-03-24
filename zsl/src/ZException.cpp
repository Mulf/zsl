#include "zsl/ZException.h"

bool ZException::s_symbolsInitialized = false;

ZException::ZException(int errorCode, const std::string& message,
    const char* file, int line, const char* function)
    : m_errorCode(errorCode), m_message(message)
{
    // 构建位置信息
    std::ostringstream locStream;
    locStream << file << ":" << line << " in " << function;
    m_location = locStream.str();

    // 获取调用栈
    m_stackTrace = CaptureStackTrace();

    // 构建完整错误信息
    std::ostringstream fullStream;
    fullStream << "Error [" << m_errorCode << "]: " << m_message << "\n"
        << "Location: " << m_location << "\n"
        << "Stack trace:\n" << m_stackTrace;
    m_fullMessage = fullStream.str();

    // 确保符号系统已初始化
    InitSymbols();
}

int ZException::GetErrorCode() const noexcept
{
    return m_errorCode;
}

const std::string& ZException::GetLocation() const noexcept
{
    return m_location;
}

const std::string& ZException::GetStackTrace() const noexcept
{
    return m_stackTrace;
}

const char* ZException::what() const noexcept
{
    return m_fullMessage.c_str();
}

void ZException::InitSymbols()
{
    if (!s_symbolsInitialized)
    {
        SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS | SYMOPT_LOAD_LINES);
        if (!SymInitialize(GetCurrentProcess(), nullptr, TRUE))
        {
            // 如果初始化失败，可以记录日志，但不抛出异常避免递归
            OutputDebugStringA("Failed to initialize debug symbols\n");
        }
        s_symbolsInitialized = true;
    }
}

void ZException::CleanupSymbols()
{
    if (s_symbolsInitialized)
    {
        SymCleanup(GetCurrentProcess());
        s_symbolsInitialized = false;
    }
}

std::string ZException::CaptureStackTrace()
 {
    std::stringstream ss;
    SymInitialize(GetCurrentProcess(), NULL, TRUE);

    void* stack[100];
    USHORT frames = CaptureStackBackTrace(2, 99, stack, NULL);

    SYMBOL_INFO* symbol = (SYMBOL_INFO*)malloc(sizeof(SYMBOL_INFO) + 256 * sizeof(char));
    symbol->MaxNameLen = 255;
    symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
    DWORD64 displacement;

    ss << "Caller Call Stack:\n";
    for (USHORT i = 0; i < frames; i++) {
        DWORD64 address = (DWORD64)stack[i];
        if (SymFromAddr(GetCurrentProcess(), address, &displacement, symbol)) {
            IMAGEHLP_LINE64 line;
            line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
            DWORD lineDisplacement;

            if (SymGetLineFromAddr64(GetCurrentProcess(), address, &lineDisplacement, &line)) {
                ss << "  " << symbol->Name << " + " << displacement
                    << " (Line: " << line.LineNumber << ", File: " << line.FileName << ")\n";
            }
            else {
                ss << "  " << symbol->Name << " + " << displacement << " (Line info not available)\n";
            }
        }
        else {
            ss << "  0x" << std::hex << address << std::dec << " (Symbol not found)\n";
        }
    }

    free(symbol);
    SymCleanup(GetCurrentProcess());

    return ss.str();
}
