#include"GameCommon.h"



void MouseRay::CreateViewSpaceRay(int x, int y)
{

	m_vPos.x = float(x);
	m_vPos.y = float(y);
	m_vPos.x = (m_vPos.x * 2 / WINMGR->GetWidth() - 1);
	m_vPos.y = 1.0f - (m_vPos.y * 2 / WINMGR->GetHeight());

	//역 프로젝션
	D3DXMATRIX mProj;
	DEVICE->GetTransform(D3DTS_PROJECTION, &mProj);
	D3DXMatrixInverse(&mProj, 0, &mProj);
	D3DXVec3TransformCoord(&m_vDir, &m_vPos, &mProj);
	D3DXVec3Normalize(&m_vDir, &m_vDir);

	// 뷰 공간에서의 레이의 위치와 방향
	m_vPos = D3DXVECTOR3(0, 0, 0);
}

void MouseRay::RayTransform(D3DXMATRIX m)
{
	D3DXMATRIX mInv;
	D3DXMatrixInverse(&mInv, 0, &m);
	D3DXVec3TransformCoord(&m_vPos, &m_vPos, &mInv);
	D3DXVec3TransformNormal(&m_vDir, &m_vDir, &mInv);
	D3DXVec3Normalize(&m_vDir, &m_vDir);
}

MouseRay::MouseRay()
	: m_vPos(0, 0, 0), m_vDir(0, 0, 0)
{
}


MouseRay::~MouseRay()
{
}
