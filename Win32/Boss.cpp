#include"IncludeAPI.h"



void Boss::Init(std::wstring _name, int _x, int _y, MovingAI * _moveAI, Weapon * _Weapon)
{
	Enemy::Init(_name, _x, _y);
	if(_moveAI==nullptr)
		_moveAI = new DefaultBossMovingAI;
	m_MovingAI = _moveAI;
	m_MovingAI->Init(this, 10);
	
	m_HP = 100;
}

void Boss::Init(std::wstring _name, Vector2 _pos, MovingAI * _moveAI, Weapon * _Weapon)
{
	Enemy::Init(_name, _pos);
}

Boss::Boss()
{
	m_ShotTimer.SetTimer(0.5f);
}


Boss::~Boss()
{
	delete m_MovingAI;
}
