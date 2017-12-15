#include"GameCommon.h"


void Enemy::Update(float dTime)
{
	baseObject::Update(dTime);
}

Enemy::Enemy()
{
	m_pTarget = nullptr;
}


Enemy::~Enemy()
{
}
