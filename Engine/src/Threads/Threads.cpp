#include "pch.h"

Engine::Threads* Engine::Threads::instance = nullptr;

Engine::Threads* Engine::Threads::Instance()
{
	if (instance)
	{
		instance = new Engine::Threads();
	}
	return instance;
}

DWORD WINAPI Engine::Threads::WindowThreadProc(CONST LPVOID lpParam)
{
	Threads::Instance()->windowMainLoop();
	ExitThread(0);
}

bool Engine::Threads::Initialize(std::function<bool(void)> windowLoop)
{
	auto threadInstance = Threads::Instance();

	threadInstance->windowMainLoop = windowLoop;

	for (int i = 0; i < 1; i++)
	{
		threadInstance->hMainThreads[i] = CreateThread(NULL, 0, &threadInstance->WindowThreadProc, NULL, 0, NULL);
		if (threadInstance->hMainThreads[i] == NULL)
			Engine::Console::Error(TEXT("Failed to create thread.\r\n"));
	}

	return true;
}