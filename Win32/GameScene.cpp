#include"IncludeAPI.h"



GameScene::GameScene()
{
	m_SceneName = _T("GameScene");
}


GameScene::~GameScene()
{
	Release();
}

GameObject * GameScene::CreateObject(std::wstring _name, std::wstring _classname, int _x, int _y)
{
	GameObject* _pObj = nullptr;
	
	
	if (_classname == _T("Map"))
	{
		_pObj = new Map;
		_pObj->Init(_name, _x, _y);
	}
	else if (_classname == _T("Player"))
	{
		_pObj = new Player;
		_pObj->Init(_name, _x, _y);
	}
	
	else if (_classname == _T("Enemy"))
	{
		_pObj = new Enemy;
		_pObj->Init(_name, _x, _y);
		ENEMYMGR->CreateEnemy(_pObj);
	}
	
	else if (_classname == _T("Bullet"))
	{
		_pObj = new Bullet;
		_pObj->Init(_name, _x, _y);
	}
	else
	{
		wchar_t temp[32] = { 0, };
		swprintf(temp, _T("CreateObjectFail : %s"), _classname.c_str());
		MessageBox(NULL, temp, _T("fail"), MB_OK);
	}
	
	if (_pObj)
		m_listObjects.push_back(_pObj);
	return _pObj;
}
//
//void GameScene::CreateObject(GameObject * _Obj)
//{
//	m_listObjects.push_back(_Obj);
//}

void GameScene::ObjectClear(void)
{
	for (auto itor = m_listObjects.begin();
		itor != m_listObjects.end();)
	{
		GameObject* _pObj = (*itor);

		if (_pObj->Life() == false)
		{
			_pObj->OnDelete();
			ENEMYMGR->DeleteEnemy(_pObj);


			PHYSICMGR->DeleteCollider(_pObj);

			delete _pObj;
			itor = m_listObjects.erase(itor);
		}
		else
			++itor;
	}
}

void GameScene::DebugView(HDC _backDC)
{
	int _x = 10;
	int _y = 30;
	wchar_t textBuffer[128] = { 0, };


	
	swprintf(textBuffer, _T("ImageCount : %d"), SPRITEMGR->GetSpriteCount());
	TextOut(_backDC, _x, _y += 25, textBuffer, lstrlen(textBuffer));

	swprintf(textBuffer, _T("ObjectCount : %d"), (int)m_listObjects.size());
	TextOut(_backDC, _x, _y += 25, textBuffer, lstrlen(textBuffer));

	swprintf(textBuffer, _T("EnemyCount : %d"), ENEMYMGR->GetEnemyCount());
	TextOut(_backDC, _x, _y += 25, textBuffer, lstrlen(textBuffer));

	swprintf(textBuffer, _T("ColliderCount : %d"), PHYSICMGR->GetCollisionCount());
	TextOut(_backDC, _x, _y += 25, textBuffer, lstrlen(textBuffer));
}

void GameScene::Init(HDC hdc)
{
	m_hDC = hdc;
	GameObject* _pObj = nullptr;

	// map
	_pObj = CreateObject(_T("map.bmp"), _T("Map"), 672/2,800/2);
	//CreateObject(_pObj);
	// player
	_pObj = CreateObject(_T("player.bmp"), _T("Player"), 672 / 2 - 17, 700);
	//CreateObject(_pObj);
}

void GameScene::Update(void)
{
	ENEMYMGR->Update();

	for each(auto p in m_listObjects)
		p->Update();

	PHYSICMGR->Update();

	ObjectClear();
}

void GameScene::Render(HDC _backDC)
{
	for each(auto p in m_listObjects)
		p->Render(_backDC);

	//COLLMGR->Render(_backDC);


	DebugView(_backDC);
}

void GameScene::Release()
{
	for each(auto p in m_listObjects)
		delete p;

	m_listObjects.clear();
}
