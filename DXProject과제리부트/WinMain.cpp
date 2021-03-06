#include "GameCommon.h"



int WINAPI WinMain(
	HINSTANCE hIns,		// 윈도우 id
	HINSTANCE hPrev,	// 이전인스턴스 win32 NULL
	LPSTR lpszCmd,		// 케맨드라인 문자
	int nCmdShow		// 윈도우가 출력상태
)
{
	srand((unsigned int)(time(NULL)));
	WINMGR->myCreateWindow(hIns, 800, 600, "KITRI_API");
	DXMGR->CreateDirect3D();
	INPUTMGR->SetUp();
	GAMEMGR->Init();
	

	int returnValue = WINMGR->Loop();

	delete WINMGR;
	delete GAMEMGR;
	delete DXMGR;

	return returnValue;
}
