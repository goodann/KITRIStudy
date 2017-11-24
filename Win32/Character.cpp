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
	if (m_Pos.left() < 0 || m_Pos.right()>WINMGR->GetWidth() || m_Pos.bottom() > WINMGR->GetHeight() || m_Pos.top() < -800) {
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
	m_Weapon = nullptr;
	//m_Speed(0, 0);
}


Character::~Character()
{
}
