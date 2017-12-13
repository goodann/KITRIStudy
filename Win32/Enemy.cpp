#include"IncludeAPI.h"
#include "Enemy.h"


void Enemy::Init(std::wstring _name, int _x, int _y, MovingAI * _moveAI, Weapon * _Weapon)
{
	Character::Init(_name, _x, _y);
	if (_moveAI == nullptr)
		m_MovingAI = new DefaultMovingAI;
	else
		m_MovingAI = _moveAI;
	if (_Weapon == nullptr) {
		m_Weapon = new DefaultEnemysWeapon;
	}
	else {
		m_Weapon = _Weapon;
	}
}

void Enemy::Init(std::wstring _name, Vector2 _pos, MovingAI * _moveAI, Weapon * _Weapon)
{
	Character::Init(_name, _pos);
	m_MovingAI = _moveAI;
	m_Weapon = _Weapon;
}

void Enemy::Update()
{
	Character::Update();
	m_MovingAI->Update();
	
	//m_Weapon->Fire();
}

Enemy::Enemy()
{
	m_HP = 3;
	m_ShotTimer.SetTimer(0.5f);
}


Enemy::~Enemy()
{
}

void Enemy::OnDelete()
{
	if (m_Pos.left() < 0 || m_Pos.right()>WINMGR->GetWidth() || m_Pos.bottom() > WINMGR->GetHeight() || m_Pos.top() <0) {
		return;
	}
	AnimatedGameObject* pObj = new AnimatedGameObject;
	pObj->Init(_T("explosions.bmp"), m_Pos.m_pos, 1.5f);
	GAMEMGR->CreateObject(pObj);
}
