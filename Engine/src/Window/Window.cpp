#include "pch.h"
#include "Window.h"

using namespace Engine;

Window::Windows_WindowClass Window::Windows_WindowClass::_windowClass;

Window::Windows_WindowClass::Windows_WindowClass()
	: _hInst(GetModuleHandle(nullptr))
{
	// create window class struct
	WNDCLASSEXW wc = { 0 };
	wc.cbSize = sizeof(WNDCLASSEXW);
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = HandleMsgSetup;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = this->getHinstanse();
	wc.hIcon = LoadIconW(nullptr, IDC_ARROW);
	wc.hCursor = LoadCursorW(nullptr, IDI_APPLICATION);
	wc.hbrBackground = CreateSolidBrush(RGB(255, 255, 255));
	wc.hIconSm = LoadIconW(nullptr, IDI_APPLICATION);
	wc.lpszClassName = this->getClassName();
	wc.lpszMenuName = L"";
	// register window class struct
	RegisterClassExW(&wc);
}

Window::Windows_WindowClass::~Windows_WindowClass()
{
	UnregisterClassW(this->getClassName(), this->getHinstanse());
}

const wchar_t* Window::Windows_WindowClass::getClassName()
{
	return _windowClass._windowClassName;
}

HINSTANCE Window::Windows_WindowClass::getHinstanse()
{
	return _windowClass._hInst;
}

void Window::createWindow()
{
	if (this->_mStyle == WindowStyle::FULL_SCREEN)
	{		
		this->_mHeight = GetSystemMetrics(SM_CYSCREEN);
		this->_mWidth = GetSystemMetrics(SM_CXSCREEN);

		SetWindowLong(this->_mHwnd, GWL_STYLE, WS_POPUP);
		SetWindowLong(this->_mHwnd, GWL_EXSTYLE, WS_EX_TOPMOST);

		this->_mX = 0;
		this->_mY = 0;
	}
	else
	{
		this->_mX = (GetSystemMetrics(SM_CXSCREEN) - this->_mWidth) / 2;
		this->_mY = (GetSystemMetrics(SM_CYSCREEN) - this->_mHeight) / 2;
	}

	this->_mHwnd = CreateWindowExW(
		WS_EX_APPWINDOW,
		Windows_WindowClass::getClassName(),
		this->_mTitle,
		WS_OVERLAPPEDWINDOW,
		this->_mX,
		this->_mY,
		this->_mWidth,
		this->_mHeight,
		nullptr, nullptr,
		Windows_WindowClass::getHinstanse(),
		this);
	if (this->_mStyle == WindowStyle::FULL_SCREEN)
		ShowWindow(this->_mHwnd, SW_SHOWMAXIMIZED);
	else
		ShowWindow(this->_mHwnd, SW_SHOWDEFAULT);
}

Window::Window(int width, int height, const wchar_t* title)
	: _mWidth(width)
	, _mHeight(height)
	, _bIsAlive(true)
{
	int titleLentgth = wcslen(title);
	this->_mTitle = new wchar_t[titleLentgth + 1];
	this->_mTitle[titleLentgth] = L'\0';
	for (int i = 0; i < titleLentgth; i++)
		this->_mTitle[i] = title[i];
}

Window::~Window()
{
	ShowCursor(true);
	DestroyWindow(this->_mHwnd);
}

int Window::Start()
{
#ifdef _DEBUG
	Console::InitConsole();
#endif // DEBUG

	//Console::Write(12);
	//Console::Write(12l);
	//Console::Write('d');
	//Console::Write(2.5f);
	Console::Write(2.5);

	this->createWindow();
	this->initGame();

	MSG msg;
	// message loop
	while (GetMessageW(&msg, this->_mHwnd, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
	}

	return 0;
}

LRESULT CALLBACK Window::HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (msg == WM_NCCREATE)
	{
		const CREATESTRUCTW* const pCreate = reinterpret_cast<CREATESTRUCTW*>(lParam);
		Window* const pWnd = static_cast<Window*>(pCreate->lpCreateParams);
		SetWindowLongPtrW(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pWnd));
		SetWindowLongPtrW(hWnd, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(&Window::HandleMsgThunk));
		return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
	}
	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

LRESULT CALLBACK Window::HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	Window* const pWnd = reinterpret_cast<Window*>(GetWindowLongPtrW(hWnd, GWLP_USERDATA));
	return pWnd->HandleMsg(hWnd, msg, wParam, lParam);
}

LRESULT Window::HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_CREATE:
		SetTimer(hWnd, 1, 20, NULL);
		break;

	case WM_TIMER:
		InvalidateRect(hWnd, NULL, FALSE);
		break;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);

		EndPaint(hWnd, &ps);
		break;
	}
	case WM_GETMINMAXINFO:
		((MINMAXINFO*)lParam)->ptMinTrackSize.x = this->_mWidth;
		((MINMAXINFO*)lParam)->ptMinTrackSize.y = this->_mHeight;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.x = this->_mWidth;
		((MINMAXINFO*)lParam)->ptMaxTrackSize.y = this->_mHeight;
		((MINMAXINFO*)lParam)->ptMaxSize.x = this->_mWidth;
		((MINMAXINFO*)lParam)->ptMaxSize.y = this->_mHeight;
		break;

	case WM_CLOSE:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProcW(hWnd, msg, wParam, lParam);
}

void Window::initGame()
{
	
}

void Window::SetWindowStyle(const WindowStyle& style)
{
	this->_mStyle = style;
}