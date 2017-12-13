#include"IncludeAPI.h"

void Bullet::Update(void)
{
	GameObject::Update();
}

void Bullet::OnCollisionHit(GameObject * pCollObj)
{
	if (pCollObj->TAG().find(_T("Bullet")) == std::string::npos) {
		if (m_Tag == _T("PlayersBullet")) {
 			if (pCollObj->TAG().find(_T("Player")) != std::string::npos)
				return;
		} 
		else if (m_Tag == _T("EnemyBullet"))
		{
			if (pCollObj->TAG().find(_T("Enemy")) != std::string::npos)
				return;
		}
		AnimatedGameObject* pObj = new AnimatedGameObject;
		pObj->Init(_T("explosion.bmp"), m_Pos.m_pos,1.0f);
		GAMEMGR->CreateObject(pObj);
		m_Life = false;
		pCollObj->Attacked(1);
	}
}

void Bullet::Init(std::wstring _name, int _x, int _y)
{
	GameObject::Init(_name, _x, _y);
	PHYSICMGR->AddCollider(this);
}

void Bullet::Init(std::wstring _name, Vector2 _pos)
{
	GameObject::Init(_name, _pos);
	PHYSICMGR->AddCollider(this);
}


Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
