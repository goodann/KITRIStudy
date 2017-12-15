#include"GameCommon.h"



void TankBody::Init(Tank* Parent)
{
	GAMEMGR->DeleteObejct(this);
	OBJECTINFO info;
	ZeroInfo(&info);
	
	info.vScale = D3DXVECTOR3(1, 1, 2);
	info.Pollygon = PG_BOX;
	info.Parent = Parent;
	info.Color = D3DXCOLOR(1, 1, 1, 1);
	CubeObject::Init(info);
	m_Radius = 1;
	ZeroMemory(&m_Material, sizeof(m_Material));
	m_Material.Ambient=m_Material.Diffuse = D3DXCOLOR(1, 1, 1, 1);
	D3DXCreateBox(DEVICE, 2, 2, 4, &m_pMesh, nullptr);

	D3DXMatrixIdentity(&m_mTrans);

	D3DXMatrixTranslation(&m_mTrans, 0, 0, 0);
	//m_mTrans._43 = 15;
	//m_vPos = D3DXVECTOR3(0, 0, 15);
}

void TankBody::Update(float dtime)
{
	CubeObject::Update(dtime);
	//
	//D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);
	//D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
	//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);


	//m_mTM = m_mScale * m_mRot * m_mTrans;
	//
	//if(m_pmRatentTM)
	//	m_mTM = m_mScale * m_mRot * m_mTrans *(*m_pmRatentTM);
	//else
	//	m_mTM = m_mScale * m_mRot * m_mTrans;
}

void TankBody::Render(void)
{
	CubeObject::Render();
	//DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅
	//DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드

	//DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);
	//DEVICE->SetMaterial(&m_Material);

	//m_pMesh->DrawSubset(0);

	//DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드
}

void TankBody::Release(void)
{
	SAFE_DELETE(m_pMesh);
}

TankBody::TankBody()
{
	m_pMesh = nullptr;
	m_vPos = D3DXVECTOR3(0, 1, 0);
	m_vRot = D3DXVECTOR3(0, 0, 0);
	m_vScale = D3DXVECTOR3(1,1,1);
	m_pmRatentTM = nullptr;
}


TankBody::~TankBody()
{
}
