#include"IncludeAPI.h"


SINGLETON_INIT(SingletonGameManager);

SingletonGameManager::SingletonGameManager()
{
	m_hDC = 0;
	m_hBackDC = 0;

	m_SceneType = ST_GAME;
	m_CurrScene = nullptr;
	m_NextScene = nullptr;
}


SingletonGameManager::~SingletonGameManager()
{
	Release();
}

GameObject * SingletonGameManager::CreateObject(std::wstring _name, std::wstring _classname, int _x, int _y, DWORD color)
{
	return nullptr;
}

void SingletonGameManager::CreateObject(GameObject * _Obj)
{
	m_CurrScene->CreateObject(_Obj);
}

void SingletonGameManager::Init(void)
{
	m_hDC = GetDC(WINMGR->GetHWND());

	SPRITEMGR->SetScreenDC(m_hDC);

	// backbuffer
	HBITMAP bit;
	m_hBackDC = CreateCompatibleDC(m_hDC);
	bit = (HBITMAP)LoadImage(NULL, _T("Resource/back.bmp"), IMAGE_BITMAP,
		0, 0, LR_LOADFROMFILE);
	SelectObject(m_hBackDC, bit);
	m_Scenes[ST_START] = new StartScene;
	m_Scenes[ST_START]->Init(m_hDC);
	m_Scenes[ST_GAME] = new GameScene;
	m_Scenes[ST_GAME]->Init(m_hDC);

	m_CurrScene = m_Scenes[m_SceneType];
	m_NextScene = m_Scenes[ST_GAME];
}

void SingletonGameManager::Update(void)
{
	m_CurrScene->Update();

	
	if (m_NextScene == nullptr) 
		return;
	else
		m_CurrScene = m_NextScene;
		
	//m_NextScene = nullptr;
}

void SingletonGameManager::Render(void)
{
	m_CurrScene->Render(m_hBackDC);
	wchar_t tmp[32] = { 0, };
	wsprintf(tmp, _T("fps : %d"), FRAMEMGR->GetFPS());
	TextOut(m_hBackDC, 10, 10, tmp, lstrlen(tmp));
	BitBlt(m_hDC, 0, 0, WINMGR->GetWidth(),
		WINMGR->GetHeight(), m_hBackDC, 0, 0, SRCCOPY);
}

void SingletonGameManager::Release(void)
{
	ReleaseDC(WINMGR->GetHWND(), m_hDC);
}

void SingletonGameManager::Loop(void)
{
	if (FRAMEMGR->LimitFPS() == false)
		return;

	FRAMEMGR->Update();

	Update();
	Render();
}
