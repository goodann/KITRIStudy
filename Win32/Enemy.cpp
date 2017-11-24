#include"IncludeAPI.h"
#include "Enemy.h"


void Enemy::Init(std::wstring _name, int _x, int _y, DWORD color, MovingAI * _moveAI, Weapon * _Weapon)
{
	GameObject::Init(_name, _x, _y, color);
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

void Enemy::Init(std::wstring _name, Vector2 _pos, DWORD color, MovingAI * _moveAI, Weapon * _Weapon)
{
	GameObject::Init(_name, _pos, color);
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
	m_ShotTimer.SetTimer(0.5f);
}


Enemy::~Enemy()
{
}
