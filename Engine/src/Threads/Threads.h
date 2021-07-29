#pragma once

namespace Engine
{
	class Threads
	{
	private:
		static Threads* instance;
		Threads() {}
		Threads(const Threads&) {}
		Threads& operator=(const Threads&) {}
	public:
		static bool Initialize(std::function<bool(void)> windowLoop);
		static Threads* Instance();
	private:
		static DWORD WINAPI WindowThreadProc(CONST LPVOID lpParam);
	private:
		std::function<bool(void)> windowMainLoop;
		HANDLE hMainThreads[1];
	};
}