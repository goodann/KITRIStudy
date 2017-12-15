#include "GameCommon.h"



int WINAPI WinMain(
	HINSTANCE hIns,		// ������ id
	HINSTANCE hPrev,	// �����ν��Ͻ� win32 NULL
	LPSTR lpszCmd,		// �ɸǵ���� ����
	int nCmdShow		// �����찡 ��»���
)
{
	srand((unsigned int)time(NULL));

	WINMGR->myCreateWindow(hIns, 672, 800, _T("KITRI_API"));
	DXMGR->CreateDirect3D();
	GAMEMGR->Init();
	

	int returnValue = WINMGR->Loop();

	delete WINMGR;
	delete GAMEMGR;
	delete DXMGR;

	return returnValue;
}
