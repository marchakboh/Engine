#pragma once

namespace Engine
{
	class Window
	{
	private:
		class Windows_WindowClass
		{
		public:
			static const wchar_t* getClassName();
			static HINSTANCE getHinstanse();
		private:
			Windows_WindowClass();
			~Windows_WindowClass();
			Windows_WindowClass(const Windows_WindowClass&) = delete;
			Windows_WindowClass& operator=(const Windows_WindowClass&) = delete;
			static constexpr const wchar_t* _windowClassName = L"MainWindowClass";
			static Windows_WindowClass _windowClass;
			HINSTANCE _hInst;
		};
	public:
		Window(int width, int height, const wchar_t* title);
		Window() = delete;
		~Window();
		Window(const Window&) = delete;
		Window& operator=(const Window&) = delete;
		enum class WindowStyle
		{
			UNDECORATED,
			UNDECORATED_FULL_SCREEN,
			FULL_SCREEN,
			DEFAULT
		};
	private:
		static LRESULT CALLBACK HandleMsgSetup(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		static LRESULT CALLBACK HandleMsgThunk(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		LRESULT HandleMsg(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
		void createWindow();
		void initGame();
	public:
		int Start();
		void SetWindowStyle(const WindowStyle& style);
	private:
		int _mX;
		int _mY;
		int _mWidth;
		int _mHeight;
		wchar_t* _mTitle;

		bool _bIsAlive;

		HWND _mHwnd;

		WindowStyle _mStyle;
	};
}