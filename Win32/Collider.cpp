#include"IncludeAPI.h"



Collider::Collider()
{
	m_target = nullptr;
}

Collider::Collider(GameObject * _pObj)
{
	m_target = _pObj;
}

void Collider::OnCollisionHit(Collider * _other)
{

}


Collider::~Collider()
{
}
