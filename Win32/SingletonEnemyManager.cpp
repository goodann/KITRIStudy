#include"IncludeAPI.h"

SINGLETON_INIT(SingletonEnemyManager);

SingletonEnemyManager::SingletonEnemyManager()
{
	m_EnemyMax = 100;
	m_CurrEnemyCnt = 0;
}


SingletonEnemyManager::~SingletonEnemyManager()
{
}

void SingletonEnemyManager::Init(void)
{

}

void SingletonEnemyManager::Update(void)
{
	if (m_CurrEnemyCnt > m_EnemyMax) return;

	{
		/*
		EnemyInfo _info;
		ZeroMemory(&_info, sizeof(_info));
		_info._x = rand() % (WINMGR->GetWidth() - 64);
		_info._y = -50;
		_info._tag = "Enemy";
		_info._imgName = "Resource/boss.bmp";
		_info.color = RGB(255, 0, 255);
		_info._hp = 100;
		_info._speed = 5.0f;

		_info._AIType = AT_HORIZ;
		_info._eventPos = 100;

		_info._BulletType = BT_GEN;
		_info._bulletMax = 0.1f;
		_info._bulletSpeed = 10;
		_info._delayTime = 1.0f;

		newCreateEnemy(_info);
		*/
	}
	CreateEnemy();
}

void SingletonEnemyManager::CreateEnemy(void)
{
	int cnt = (int)m_listEnemys.size();

	if (cnt < 1)
	{
		int _x = rand() % (WINMGR->GetWidth() - 64);
		int _y = 50;

		Enemy* _pObj = new Enemy;
		
		//_pObj->Speed()(0,5.0f);
		//_pObj->SetMaxHP(100);
		//_pObj->SetHP(100);

		/*
		ShakeDown* pAI = new ShakeDown;
		pAI->SetTarget(_pObj);
		pAI->SetAngleSpeed(5.0f);
		pAI->SetRadius(5.0f);
		*/
		MovingAI* pAI = new DefaultMovingAI;
		pAI->Init(_pObj,5);

		Weapon* pWeapon = new DefaultEnemysWeapon;

		_pObj->Init(_T("Resource/enemy.bmp"), _x, _y, RGB(255, 0, 255),pAI,pWeapon);
		_pObj->TAG() = (_T("Enemy"));
		GAMEMGR->CreateObject(_pObj);
		CreateEnemy(_pObj);
		//pAI->SetEventPos(200);

		//BaseBulletAI* pShotAI = new BaseBulletAI;
		//SunShotAI* pShotAI = new SunShotAI2;
		//CircleRoundAI * pShotAI = new CircleRoundAI;
		//FirWorkAI * pShotAI = new FirWorkAI;
		//pShotAI->SetTarget(_pObj);

		/*
		pShotAI->Init(2.0f);
		_pObj->SetAI(pAI);
		_pObj->SetShotAI(pShotAI);
		HUDBar* pHUD = new HUDBar;
		pHUD->Init(_pObj, "Resource/hpbarback_boss.bmp", "Resource/hpbar_boss.bmp");
		_pObj->SethudBar(pHUD);
		CreateEnemy2(_pObj, pHUD);
		*/
		m_CurrEnemyCnt++;

		// 중복에대한 체크
		/*
		while (true)
		{
			if (COLLMGR->RePosCheck(_pObj))
			{
				int _x = rand() % (WINMGR->GetWidth() - 64);
				_pObj->SetPosX(_x);
			}
			else
				break;
		}
		*/
	}
}

void SingletonEnemyManager::DeleteEnemy(GameObject * _enemy)
{
	for (auto itor = m_listEnemys.begin();
		itor != m_listEnemys.end();)
	{
		GameObject* pObj = (*itor);

		if (pObj == _enemy)
		{
			itor = m_listEnemys.erase(itor);
		}
		else
			++itor;
	}
}
