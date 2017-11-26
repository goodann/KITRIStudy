#include"IncludeAPI.h"


void Character::Shot()
{
	if (m_ShotTimer.TimeCheck()) {
		if (m_Weapon)
			m_Weapon->Fire(this);
	}
}

void Character::Update()
{
	//GameObject::Update();
	if (m_Pos.left() < 0 || m_Pos.right()>WINMGR->GetWidth() || m_Pos.bottom() > WINMGR->GetHeight()+200 || m_Pos.top() < -800) {
		m_Life = false;
	}
	Shot();
}

void Character::SetTimer(float _time)
{
	m_ShotTimer.SetTimer(_time);
}

Character::Character()
{
	m_Power = 1;
	m_Weapon = nullptr;
	//m_Speed(0, 0);
}


Character::~Character()
{
}

void Character::Attacked(int damage)
{
	m_HP -= damage;
	if (m_HP <= 0) {
		m_Life = false;
		this->Update();
	}
}

void Character::Init(std::wstring _name, int _x, int _y, DWORD color)
{
	GameObject::Init(_name, _x, _y, color);
	PHYSICMGR->AddCollider(this);
}

void Character::Init(std::wstring _name, Vector2 _pos, DWORD color)
{
	GameObject::Init(_name, _pos, color);
	PHYSICMGR->AddCollider(this);
}
