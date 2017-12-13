#include"IncludeAPI.h"



void StartScene::Init(HDC hdc)
{
	m_Sprite = SPRITEMGR->GetSprite(_T("logo.bmp"));

	m_BlenFunc.SourceConstantAlpha = 255;
	m_Timer.SetTimer(0.05f);
}

void StartScene::Update(void)
{
	if (m_Timer.TimeCheck()) {
		if (m_BlenFunc.SourceConstantAlpha > 0)
			m_BlenFunc.SourceConstantAlpha--;
	}
}

void StartScene::Render(HDC _backDC)
{
	m_Sprite->RenderSprite(_backDC, 0, 200, m_BlenFunc);
}

void StartScene::Release()
{
	m_map = SPRITEMGR->GetSprite(_T("map.bmp"));
}

StartScene::StartScene()
{
	m_Sprite = nullptr;
	ZeroMemory(&m_BlenFunc,sizeof(m_BlenFunc));
	m_SceneName = _T("StartScene");
}


StartScene::~StartScene()
{
}
