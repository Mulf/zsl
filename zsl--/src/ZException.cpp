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
    std::ostringstream stackStream;

    // 获取当前线程上下文
    CONTEXT context;
    RtlCaptureContext(&context);

    // 初始化栈帧
    STACKFRAME64 stackFrame = {};
    stackFrame.AddrPC.Offset = context.Rip;
    stackFrame.AddrPC.Mode = AddrModeFlat;
    stackFrame.AddrFrame.Offset = context.Rbp;
    stackFrame.AddrFrame.Mode = AddrModeFlat;
    stackFrame.AddrStack.Offset = context.Rsp;
    stackFrame.AddrStack.Mode = AddrModeFlat;

    HANDLE process = GetCurrentProcess();
    HANDLE thread = GetCurrentThread();

    // 限制最大帧数
    const int maxFrames = 50;

    for (int i = 0; i < maxFrames; i++)
    {
        if (!StackWalk64(
            IMAGE_FILE_MACHINE_AMD64,
            process,
            thread,
            &stackFrame,
            &context,
            nullptr,
            SymFunctionTableAccess64,
            SymGetModuleBase64,
            nullptr))
        {
            break;
        }

        if (stackFrame.AddrPC.Offset == 0)
        {
            break;
        }

        // 获取符号信息
        DWORD64 displacement = 0;
        char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
        PSYMBOL_INFO symbol = (PSYMBOL_INFO)buffer;
        symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        symbol->MaxNameLen = MAX_SYM_NAME;

        if (SymFromAddr(process, stackFrame.AddrPC.Offset, &displacement, symbol))
        {
            stackStream << "[" << i << "] " << symbol->Name << " (";

            // 尝试获取行号信息
            IMAGEHLP_LINE64 line;
            line.SizeOfStruct = sizeof(IMAGEHLP_LINE64);
            DWORD lineDisplacement = 0;

            if (SymGetLineFromAddr64(process, stackFrame.AddrPC.Offset,
                &lineDisplacement, &line))
            {
                stackStream << line.FileName << ":" << line.LineNumber;
            }
            else
            {
                stackStream << "unknown file";
            }

            stackStream << ")\n";
        }
        else
        {
            stackStream << "[" << i << "] Unknown function\n";
        }
    }

    return stackStream.str();
}