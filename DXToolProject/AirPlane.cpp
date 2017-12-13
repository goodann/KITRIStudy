#include"GameCommon.h"


void AirPlane::Init(OBJECTINFO _info)
{
	baseObject::Init(_info);
	m_Transform->SetAddIndexedMatrix(5,D3DXVECTOR3(0, -0.4f, 0), &m_mPPTM);
	m_Speed = 1.0f;
}

void AirPlane::Update(float dTime)
{
	/*
	static float angle = 0.0f;
	angle += dTime*D3DX_PI * 40;
	D3DXMatrixRotationZ(&m_mPPTM, angle);
	m_fPosRadian-= dTime*D3DX_PI *0.3f;
	//if (m_fPosRadian > D3DX_PI)
		//m_fPosRadian = 0;
	float x = cos(m_fPosRadian);
	float z = sin(m_fPosRadian);

	m_Transform->Rotate(D3DXVECTOR3(0,dTime*D3DX_PI*0.3f,0));
	m_Transform->SetvPos(D3DXVECTOR3(x*10,10,z*10));
	*/
	baseObject::Update(dTime);
	//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	//m_mTM = m_mTrans;

}

void AirPlane::Render(void)
{
	m_Transform->Render();
}

void AirPlane::Release(void)
{
}

AirPlane::AirPlane()
{
	m_fPosRadian = 0;
}


AirPlane::~AirPlane()
{
}
