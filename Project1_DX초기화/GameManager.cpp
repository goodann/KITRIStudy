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
	DXDEV->Clear(0,//RECT ����
		NULL, //REC T
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, //Ŭ���� Ÿ�� (ȭ�����|���̹���)
		D3DXCOLOR(0.0f, 0.0f, 1.0f,1.0f),//Ÿ�� ���� Ŭ���� ����
		1.0f,//���̹��� Ŭ���� ��(���̰�)
		0);//���ٽǹ���(�ݻ�,�׸���) �ʱⰪ

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
