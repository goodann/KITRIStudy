#pragma once
class SingletonWindowManager
{
	SINGLETON_FUNC(SingletonWindowManager);

	HINSTANCE		m_hInst;
	HWND			m_hWnd;
	int				m_nWidth;
	int				m_nHeight;

public:
	HWND GetHWND(void) { return m_hWnd; }
	int  GetWidth(void) { return m_nWidth; }
	int GetHeight(void) { return m_nHeight; }

	void myCreateWindow(HINSTANCE _hInst, int _nW,
		int _nH, LPCWSTR _name);
	void ResizeWindow(void);

	int Loop(void);
	static LRESULT CALLBACK WndProc(HWND hWnd,
		UINT iMsg, WPARAM wParam, LPARAM lParam);

public:
};

