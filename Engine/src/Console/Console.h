#pragma once

#ifdef _DEBUG

namespace Engine
{
	class Console
	{
	public:
		static void InitConsole();

		static void Write(int value);
		static void Write(long value);
		static void Write(char value);
		static void Write(double value);
		static void Write(float value);
		static void Write(wchar_t value);
		static void Write(std::string value);

		static void Write(int values[], int length);
		static void Write(long values[], int length);
		static void Write(char values[], int length);
		static void Write(double values[], int length);
		static void Write(float values[], int length);
		static void Write(wchar_t values[], int length);
		static void Write(std::string values[], int length);

		static void Write(const int* values, int length);
		static void Write(const long* values, int length);
		static void Write(const char* values, int length);
		static void Write(const double* values, int length);
		static void Write(const float* values, int length);
		static void Write(const wchar_t* values, int length);
		static void Write(const std::string* values, int length);

		static void Write(const char* format, ...);

		static void WriteLine(int value);
		static void WriteLine(long value);
		static void WriteLine(char value);
		static void WriteLine(double value);
		static void WriteLine(float value);
		static void WriteLine(wchar_t value);
		static void WriteLine(std::string value);

		static void WriteLine(int values[], int length);
		static void WriteLine(long values[], int length);
		static void WriteLine(char values[], int length);
		static void WriteLine(double values[], int length);
		static void WriteLine(float values[], int length);
		static void WriteLine(wchar_t values[], int length);
		static void WriteLine(std::string values[], int length);

		static void WriteLine(const int* values, int length);
		static void WriteLine(const long* values, int length);
		static void WriteLine(const char* values, int length);
		static void WriteLine(const double* values, int length);
		static void WriteLine(const float* values, int length);
		static void WriteLine(const wchar_t* values, int length);
		static void WriteLine(const std::string* values, int length);

		static void WriteLine(const char* format, ...);

		static void Error(CONST LPCWSTR szMessage);

	private:
		HANDLE output;
		HANDLE input;
	};
}

#endif // _DEBUG