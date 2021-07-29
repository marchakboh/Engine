#include "pch.h"

#ifdef _DEBUG

Engine::Console* ConsolePtr;

void Engine::Console::InitConsole()
{
#ifndef CONSOLESETUP
#define CONSOLESETUP

    AllocConsole();

    HANDLE handle_out = GetStdHandle(STD_OUTPUT_HANDLE);
    int hCrt = _open_osfhandle((long)handle_out, _O_TEXT);
    FILE* hf_out = _fdopen(hCrt, "w");
    setvbuf(hf_out, NULL, _IONBF, 1);
    *stdout = *hf_out;

    HANDLE handle_in = GetStdHandle(STD_INPUT_HANDLE);
    hCrt = _open_osfhandle((long)handle_in, _O_TEXT);
    FILE* hf_in = _fdopen(hCrt, "r");
    setvbuf(hf_in, NULL, _IONBF, 128);
    *stdin = *hf_in;

    ConsolePtr = new Console();
    ConsolePtr->input = handle_in;
    ConsolePtr->output = handle_out;

#endif // !CONSOLESETUP
}

void Engine::Console::Write(int value)
{
    std::wstring result = std::to_wstring(value);
    DWORD dwSize = 0;
    AttachConsole(ATTACH_PARENT_PROCESS);
    WriteConsole(ConsolePtr->output, result.c_str(), result.size(), &dwSize, NULL);
}

void Engine::Console::Write(long value) 
{
    std::wstring result = std::to_wstring(value);
    DWORD dwSize = 0;
    AttachConsole(ATTACH_PARENT_PROCESS);
    WriteConsole(ConsolePtr->output, result.c_str(), result.size(), &dwSize, NULL);
}

void Engine::Console::Write(char value) 
{
    char text[] = { value };
    wchar_t wtext[1];
    mbstowcs(wtext, text, 1);
    LPWSTR ptr = wtext;
    DWORD dwSize = 0;
    AttachConsole(ATTACH_PARENT_PROCESS);
    WriteConsole(ConsolePtr->output, ptr, 1, &dwSize, NULL);
}

void Engine::Console::Write(double value) 
{
    std::wstring result = std::to_wstring(value);
    DWORD dwSize = 0;
    AttachConsole(ATTACH_PARENT_PROCESS);
    WriteConsole(ConsolePtr->output, result.c_str(), result.size(), &dwSize, NULL);
}

void Engine::Console::Write(float value) 
{
    std::wstring result = std::to_wstring(value);
    DWORD dwSize = 0;
    AttachConsole(ATTACH_PARENT_PROCESS);
    WriteConsole(ConsolePtr->output, result.c_str(), result.size(), &dwSize, NULL);
}

void Engine::Console::Write(wchar_t value) 
{

}

void Engine::Console::Write(std::string value) 
{

}

void Engine::Console::Write(int values[], int length) 
{

}

void Engine::Console::Write(long values[], int length) 
{

}

void Engine::Console::Write(char values[], int length) 
{

}

void Engine::Console::Write(double values[], int length) 
{

}

void Engine::Console::Write(float values[], int length) 
{

}

void Engine::Console::Write(wchar_t values[], int length) 
{

}

void Engine::Console::Write(std::string values[], int length) 
{

}

void Engine::Console::Write(const int* values, int length)
{

}

void Engine::Console::Write(const long* values, int length)
{

}

void Engine::Console::Write(const char* values, int length)
{

}

void Engine::Console::Write(const double* values, int length)
{

}

void Engine::Console::Write(const float* values, int length)
{

}

void Engine::Console::Write(const wchar_t* values, int length)
{

}

void Engine::Console::Write(const std::string* values, int length)
{

}

void Engine::Console::Write(const char* format, ...)
{

}

void Engine::Console::WriteLine(int value)
{

}

void Engine::Console::WriteLine(long value)
{

}

void Engine::Console::WriteLine(char value)
{

}

void Engine::Console::WriteLine(double value)
{

}

void Engine::Console::WriteLine(float value)
{

}

void Engine::Console::WriteLine(wchar_t value)
{

}

void Engine::Console::WriteLine(std::string value)
{

}

void Engine::Console::WriteLine(int values[], int length)
{

}

void Engine::Console::WriteLine(long values[], int length)
{

}

void Engine::Console::WriteLine(char values[], int length)
{

}

void Engine::Console::WriteLine(double values[], int length)
{

}

void Engine::Console::WriteLine(float values[], int length)
{

}

void Engine::Console::WriteLine(wchar_t values[], int length)
{

}

void Engine::Console::WriteLine(std::string values[], int length)
{

}

void Engine::Console::WriteLine(const int* values, int length)
{

}

void Engine::Console::WriteLine(const long* values, int length)
{

}

void Engine::Console::WriteLine(const char* values, int length)
{

}

void Engine::Console::WriteLine(const double* values, int length)
{

}

void Engine::Console::WriteLine(const float* values, int length)
{

}

void Engine::Console::WriteLine(const wchar_t* values, int length)
{

}

void Engine::Console::WriteLine(const std::string* values, int length)
{

}

void Engine::Console::WriteLine(const char* format, ...)
{

}

void Engine::Console::Error(CONST LPCWSTR szMessage)
{
    DWORD dwTemp;
    TCHAR szError[256];
    WriteConsole(ConsolePtr->output, szMessage, lstrlen(szMessage), &dwTemp, NULL);
    wsprintf(szError, TEXT("LastError = %d\r\n"), GetLastError());
    WriteConsole(ConsolePtr->output, szError, lstrlen(szError), &dwTemp, NULL);
}

#endif // _DEBUG