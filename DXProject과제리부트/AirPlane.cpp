#include"GameCommon.h"


void AirPlane::Init(OBJECTINFO _info)
{
	baseObject::Init(_info);
	m_Transform->SetAddIndexedMatrix(5,D3DXVECTOR3(0, -0.4f, 0), &m_mPPTM);
	m_Speed = 1.0f;
}

void AirPlane::Update(float dTime)
{
	


	//if (m_LBoom == nullptr) {
	//	m_LBoom = new AirPlaneBoom;
	//	OBJECTINFO info;
	//	ZeroInfo(&info);
	//	info.vPos = m_Transform->GetvPos();
	//	info.vRot = m_Transform->GetvRot();
	//	info.vScale = VEC3ONE ;
	//	info.fRadius = 1.0f;
	//	info.Parent = this;
	//	m_LBoom->Init(info);
	//	//m_LBoom->Init(m_Transform->GetvPos(), m_Transform->GetvRot(), VEC3ONE*10);
	//}
	//if (m_RBoom == nullptr) {
	//	m_RBoom = new AirPlaneBoom;
	//	OBJECTINFO info;
	//	ZeroInfo(&info);
	//	info.vPos = m_Transform->GetvPos();
	//	info.vRot = m_Transform->GetvRot();
	//	info.vScale = VEC3ONE ;
	//	info.fRadius = 1.0f;
	//	info.Parent = this;
	//	m_RBoom->Init(info);
	//	//m_RBoom->Init(m_Transform->GetvPos(), m_Transform->GetvRot(), VEC3ONE*10);
	//}
	//m_LBoom->Update(dTime);
	//m_RBoom->Update(dTime);
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
	baseObject::Update(dTime);
	//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	//m_mTM = m_mTrans;

}

void AirPlane::Render(void)
{
	m_Transform->Render();
	//if(m_LBoom)
	//m_LBoom->Render();
	//if(m_RBoom)
	//m_RBoom->Render();
}

void AirPlane::Release(void)
{
}

AirPlane::AirPlane()
{
	m_LBoom = nullptr;
	m_RBoom = nullptr;
	m_fPosRadian = 0;
}


AirPlane::~AirPlane()
{
}
