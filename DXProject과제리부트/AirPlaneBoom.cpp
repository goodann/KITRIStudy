#include"GameCommon.h"



void AirPlaneBoom::Init(OBJECTINFO _info)
{
	ZeroMemory(&_info.Material, sizeof(_info.Material));
	ZeroMemory(&_info.Color, sizeof(_info.Color));
	_info.Color = D3DXCOLOR(1, 1, 1, 1);
	m_Parent = dynamic_cast<AirPlane*>(_info.Parent);
	Bullet::Init(_info);
	
}

void AirPlaneBoom::Update(float dtime)
{
	//m_Speed=
	
	D3DXVECTOR3 dis = m_Parent->GetSpeed()*m_Parent->GetTransform()->GetvDir();
	m_Speed = m_Parent->GetSpeed();
	if (m_isFired) {
		Bullet::Update(dtime);
	}
	else
	{
		baseObject::Update(dtime);
	}
}

void AirPlaneBoom::Render(void)
{
	baseObject::Render();
}

void AirPlaneBoom::Fire()
{
	m_isFired = true;
}

AirPlaneBoom::AirPlaneBoom()
{
	m_isFired = false;
	m_Parent = nullptr;
}


AirPlaneBoom::~AirPlaneBoom()
{
	if (m_Parent->GetLBoom()==this) {
		m_Parent->SetLBoom(nullptr);
	}
	else {
		m_Parent->SetRBoom(nullptr);
	}
}
