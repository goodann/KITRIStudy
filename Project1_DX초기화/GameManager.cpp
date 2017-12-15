#include "GameCommon.h"

SINGLETON_INIT(GameManager)
void GameManager::DebugView(void) {

}
void GameManager::Init(void)
{

}

void GameManager::Update(void)
{
}

void GameManager::Render(void)
{
	DXDEV->BeginScene();
	DXDEV->Clear(0,//RECT 갯수
		NULL, //REC T
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, //클리어 타입 (화면버퍼|깊이버퍼)
		D3DXCOLOR(0.0f, 0.0f, 1.0f,1.0f),//타겟 버퍼 클리어 색상
		1.0f,//깊이버퍼 클리어 값(깊이값)
		0);//스텐실버퍼(반사,그림자) 초기값

	//Object Render

	//end

	DebugView();
	DXDEV->EndScene();
	DXDEV->Present(NULL, NULL, NULL, NULL);
}

void GameManager::Release(void)
{	
}

void GameManager::Loop(void)
{
	Update();
	Render();
}

GameManager::GameManager()
{
}


GameManager::~GameManager()
{
	Release();
}
