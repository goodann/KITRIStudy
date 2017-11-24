#include"Objects.h"



void Bullet::Update(void)
{
	GameObject::Update();
}

void Bullet::OnCollisionHit(GameObject * pCollObj)
{
	if (m_Tag == _T("EnemyBullet"))
	{
		if (pCollObj->TAG().find(_T("Enemy")) != std::string::npos)
			return;
		return;
	}
	m_Life = false;
}

Bullet::Bullet()
{
}


Bullet::~Bullet()
{
}
