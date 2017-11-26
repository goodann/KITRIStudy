#include"IncludeAPI.h"


SINGLETON_INIT(SingletonWindowManager);
void SingletonWindowManager::myCreateWindow(HINSTANCE _hInst, int _nW, int _nH, LPCWSTR _name)
{
	m_hInst = _hInst;
	m_nWidth = _nW;
	m_nHeight = _nH;

	// 1. ������ ����ü ����(ä���)
	WNDCLASS wndClass;
	ZeroMemory(&wndClass, sizeof(wndClass));

	wndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH); // ��������
	wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);		// ���콺 Ŀ�� �̹���
	wndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);	// ��ǥ ������
	wndClass.hInstance = m_hInst;		// �ν��Ͻ� ID
	wndClass.lpfnWndProc = WndProc; // �ݹ��Լ� �ּ�
	wndClass.lpszClassName = _name;	// Ŭ���� �̸� ( CREATEWINDOW�Լ��� �̸��� �����ؾߵ�!!)
									//wndClass.lpszMenuName = NULL;
	wndClass.style = CS_HREDRAW | CS_VREDRAW;

	// 2. �������� ���
	RegisterClass(&wndClass);

	// 3. ������ ����
	m_hWnd = CreateWindow(_name,	// Ŭ���� �̸�(������Ŭ������ �����ϰ�)
		_name,						// ĸ�ǹ� �̸�
		WS_OVERLAPPEDWINDOW,		// ������ ��Ÿ��
		0, 0,						// �������ǥ ��ġ
		m_nWidth, m_nHeight,		// ������ ���� ����
		NULL,						// �θ�������(�Ⱦ�)
		NULL,						// �޴�
		m_hInst,					// �ν��Ͻ� �ڵ�
		NULL);						// ���и޸�

	if (m_hWnd == false)
		MessageBox(NULL, _T("HWND ��������"), _T("����"), MB_OK);

	// 4. ������ ȭ�� ���
	ShowWindow(m_hWnd, SW_SHOW);

	ResizeWindow();
}
void SingletonWindowManager::ResizeWindow(void)
{
	// ���� ������ ��Ÿ�� ���
	DWORD _winStyle = (DWORD)GetWindowLong(m_hWnd, GWL_STYLE);

	// ��ü ������ ũ�� ���
	RECT _oldRect;
	GetWindowRect(m_hWnd, &_oldRect);

	// ���� Ŭ���̾� ũ��
	RECT _newRect = { 0, 0, m_nWidth, m_nHeight };

	// Ŭ���̾�Ʈ ���� �缳��
	AdjustWindowRect(&_newRect, _winStyle, FALSE);

	// ������ ������ ���� ����
	int _w = (_newRect.right - _newRect.left);
	int _h = (_newRect.bottom - _newRect.top);

	// �ٽ� �׸���
	SetWindowPos(m_hWnd, HWND_NOTOPMOST,
		_oldRect.left, _oldRect.top, _w, _h, SWP_SHOWWINDOW);
}
int SingletonWindowManager::Loop(void)
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
			// ���ӷ���
			GAMEMGR->Loop();
		}
	}

	return (int)msg.wParam;
}
LRESULT SingletonWindowManager::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);		// ������ ���� �Լ�
		break;
	default:
		break;
	}

	return (DefWindowProc(hWnd, iMsg, wParam, lParam));
}


SingletonWindowManager::SingletonWindowManager()
{
	m_hInst = 0;
	m_hWnd = 0;
	m_nWidth = 0;
	m_nHeight = 0;

}


SingletonWindowManager::~SingletonWindowManager()
{
	
}