#include "zsl/ZException.h"

bool ZException::s_symbolsInitialized = false;

ZException::ZException(int errorCode, const std::string& message,
    const char* file, int line, const char* function)
    : m_errorCode(errorCode), m_message(message)
{
    // ����λ����Ϣ
    std::ostringstream locStream;
    locStream << file << ":" << line << " in " << function;
    m_location = locStream.str();

    // ��ȡ����ջ
    m_stackTrace = CaptureStackTrace();

    // ��������������Ϣ
    std::ostringstream fullStream;
    fullStream << "Error [" << m_errorCode << "]: " << m_message << "\n"
        << "Location: " << m_location << "\n"
        << "Stack trace:\n" << m_stackTrace;
    m_fullMessage = fullStream.str();

    // ȷ������ϵͳ�ѳ�ʼ��
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
            // �����ʼ��ʧ�ܣ����Լ�¼��־�������׳��쳣����ݹ�
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

    // ��ȡ��ǰ�߳�������
    CONTEXT context;
    RtlCaptureContext(&context);

    // ��ʼ��ջ֡
    STACKFRAME64 stackFrame = {};
    stackFrame.AddrPC.Offset = context.Rip;
    stackFrame.AddrPC.Mode = AddrModeFlat;
    stackFrame.AddrFrame.Offset = context.Rbp;
    stackFrame.AddrFrame.Mode = AddrModeFlat;
    stackFrame.AddrStack.Offset = context.Rsp;
    stackFrame.AddrStack.Mode = AddrModeFlat;

    HANDLE process = GetCurrentProcess();
    HANDLE thread = GetCurrentThread();

    // �������֡��
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

        // ��ȡ������Ϣ
        DWORD64 displacement = 0;
        char buffer[sizeof(SYMBOL_INFO) + MAX_SYM_NAME * sizeof(TCHAR)];
        PSYMBOL_INFO symbol = (PSYMBOL_INFO)buffer;
        symbol->SizeOfStruct = sizeof(SYMBOL_INFO);
        symbol->MaxNameLen = MAX_SYM_NAME;

        if (SymFromAddr(process, stackFrame.AddrPC.Offset, &displacement, symbol))
        {
            stackStream << "[" << i << "] " << symbol->Name << " (";

            // ���Ի�ȡ�к���Ϣ
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