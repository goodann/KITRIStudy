#include "GameCommon.h"

SINGLETON_INIT(WindowManager)

void WindowManager::myCreateWindow(HINSTANCE _hInst, int _nW, int _nH, char * _name)
{
	m_hInst		= _hInst;
	m_nWidth	= _nW;
	m_nHeight	= _nH;

	// 1. 윈도우 구조체 설정(채우기)
	WNDCLASS wndClass;
	ZeroMemory(&wndClass, sizeof(wndClass));

	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // 바탕색상
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// 마우스 커서 이미지
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// 대표 아이콘
	wndClass.hInstance = m_hInst;		// 인스턴스 ID
	wndClass.lpfnWndProc = WndProc; // 콜백함수 주소
	wndClass.lpszClassName = _name;	// 클레스 이름 ( CREATEWINDOW함수의 이름과 동일해야됨!!)
									//wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	// 2. 레지스터 등록
	RegisterClass(&wndClass);

	// 3. 윈도우 생성
	m_hWnd = CreateWindow(_name,	// 클레스 이름(윈도우클래스와 동일하게)
		_name,						// 캡션바 이름
		WS_OVERLAPPEDWINDOW,		// 윈도우 스타일
		0, 0,						// 모니터좌표 위치
		m_nWidth, m_nHeight,		// 윈도우 넓이 높이
		NULL,						// 부모윈도우(안씀)
		NULL,						// 메뉴
		m_hInst,					// 인스턴스 핸들
		NULL);						// 여분메모리

	if (m_hWnd == false)
		MessageBox(NULL, "HWND 생성실패", "실패", MB_OK);

	// 4. 윈도우 화면 출력
	ShowWindow(m_hWnd, SW_SHOW);

	ResizeWindow();
}

void WindowManager::ResizeWindow(void)
{
	// 현재 윈도우 스타일 얻기
	DWORD _winStyle = (DWORD)GetWindowLong(m_hWnd, GWL_STYLE);

	// 전체 윈도우 크기 얻기
	RECT _oldRect;
	GetWindowRect(m_hWnd, &_oldRect);

	// 변경 클라이언 크기
	RECT _newRect = { 0, 0, m_nWidth, m_nHeight };

	// 클라이언트 영역 재설정
	AdjustWindowRect(&_newRect, _winStyle, FALSE);

	// 보정된 윈도우 넓이 높이
	int _w = (_newRect.right - _newRect.left);
	int _h = (_newRect.bottom - _newRect.top);

	// 다시 그리기
	SetWindowPos(m_hWnd, HWND_NOTOPMOST,
		_oldRect.left, _oldRect.top, _w, _h, SWP_SHOWWINDOW);

}

int WindowManager::Loop(void)
{
	MSG msg;

	while (true)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			// 게임루프
			GAMEMGR->Loop();
		}
	}

	return (int)msg.wParam;
}

LRESULT WindowManager::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	GAMEMGR->WndProc(hWnd, iMsg, wParam, lParam);

	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);		// 윈도우 종료 함수
		break;
	default:
		break;
	}

	return (DefWindowProc(hWnd, iMsg, wParam, lParam));
}

WindowManager::WindowManager()
{
	m_hInst		= 0;
	m_hWnd		= 0;
	m_nWidth	= 0;
	m_nHeight	= 0;
}


WindowManager::~WindowManager()
{
}
