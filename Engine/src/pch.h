#define WIN32_LEAN_AND_MEAN
#define _CRT_SECURE_NO_WARNINGS
#ifdef _HAS_EXCEPTIONS
#undef _HAS_EXCEPTIONS
#endif
#ifndef _HAS_EXCEPTIONS
#define _HAS_EXCEPTIONS 0
#endif

// WinAPI
#include <Windows.h>

// DirectX

// Other includes
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <iostream>
#include <fstream>
#include <string>
#include <functional>

// Containers
#include <queue>
#include <bitset>

// Engine Serveces
#ifdef _DEBUG
#include "Console/Console.h"
#endif // _DEBUG
#include "Exception/Exception.h"
#include "Graphics/Graphics.h"
#include "Keyboard/Keyboard.h"
#include "Mouse/Mouse.h"
#include "Sound/Sound.h"
#include "Threads/Threads.h"
#include "Window/Window.h"

using namespace Engine;