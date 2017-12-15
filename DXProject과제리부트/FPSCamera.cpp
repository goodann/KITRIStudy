#include"GameCommon.h"


FPSCamera::FPSCamera()
{
	m_pTarget = nullptr;
	m_vLook = D3DXVECTOR3(0, 0, 0);
	m_vOrgUp = m_vUp = D3DXVECTOR3(0, 1, 0);
	m_vDir = D3DXVECTOR3(0, 0, 1);
	m_vHoriz = D3DXVECTOR3(1, 0, 0);
	m_fFovy = 0;
	m_fAspect = 0;
	m_fNear = 0.01f;
	m_fFar = 1000.0f;
	m_vOrgHead=m_vHead = D3DXVECTOR3(0, 1, 0.2f);
}


FPSCamera::~FPSCamera()
{
}

void FPSCamera::Init(Transform * Target,float fov, float aspect)
{
	m_OrgPoint = GetClientPoint();
	m_pTarget = Target;
	m_fFovy = fov;
	m_fAspect = aspect;
	m_vLook = Target->GetvPos()+Target->GetvDir();
	LocalVectorUpdate();
}

void FPSCamera::Update(float dTime)
{
	D3DXVec3TransformCoord(&m_vHead, &m_vOrgHead, &(m_pTarget->GetmRot()));
	POINT currentPoint = GetClientPoint();
	int _y = currentPoint.y - m_OrgPoint.y;
	int _x = currentPoint.x - m_OrgPoint.x;
	RotateX(_y / 360.0f);
	//static float a;
	//a = D3DXToRadian(90*dTime);
	RotateY(_x / 360.0f);


	m_OrgPoint = currentPoint;
}

void FPSCamera::ViewTransform(void)
{
	//D3DXVec3TransformNormal(&m_vLook, &m_vLook, &m_pTarget->GetmRot());
	D3DXMatrixLookAtLH(&m_mView, &(m_pTarget->GetvPos()+ m_vHead), &m_vLook, &m_vOrgUp);
	
	DEVICE->SetTransform(D3DTS_VIEW, &m_mView);
}

void FPSCamera::ProjectionTransform(void)
{
	D3DXMatrixPerspectiveFovLH(&m_mProj, m_fFovy, m_fAspect, m_fNear, m_fFar);
	DEVICE->SetTransform(D3DTS_PROJECTION, &m_mProj);
}

void FPSCamera::LocalVectorUpdate(void)
{
	D3DXVECTOR3 a;
	//D3DXVec3Normalize(&m_vDir, &(m_vLook - (m_pTarget->GetvPos()+ m_vHead)));
	D3DXVec3Normalize(&m_vDir, &(m_vLook - (m_pTarget->GetvPos() + m_vHead)));

	D3DXVec3Cross(&m_vHoriz, &m_vUp, &m_vDir);
	D3DXVec3Normalize(&m_vHoriz, &m_vHoriz);

	D3DXVec3Cross(&m_vUp, &m_vDir, &m_vHoriz);
	D3DXVec3Normalize(&m_vUp, &m_vUp);
	ViewTransform();
	ProjectionTransform();
}

void FPSCamera::RotateX(float angle)
{
	D3DXMATRIX mRot;
	D3DXMatrixRotationAxis(&mRot, &m_vHoriz, angle);
	D3DXVec3TransformNormal(&m_vDir, &m_vDir, &mRot);
	//
	D3DXVec3Normalize(&m_vDir, &m_vDir);
	D3DXVec3Cross(&m_vUp, &m_vDir, &m_vHoriz);
	D3DXVECTOR3 m_vDir2;
	D3DXVec3TransformNormal(&m_vDir2, &m_vDir, &m_pTarget->GetmRot());
	//m_vLook = (m_pTarget->GetvPos()+ m_vHead) + m_vDir*10.0f;
	m_vLook = (m_pTarget->GetvPos() + m_vHead) + m_vDir2*10.0f;
	if (m_vLook.y < 0)
		m_vLook.y = 0;
	ViewTransform();
	ProjectionTransform();
}

void FPSCamera::RotateY(float angle)
{

	D3DXMATRIX mRot;
	D3DXMatrixRotationAxis(&mRot, &m_vOrgUp, angle);
	D3DXVec3TransformNormal(&m_vDir, &m_vDir, &mRot);
	D3DXVec3Normalize(&m_vDir, &m_vDir);
	D3DXVec3Cross(&m_vHoriz, &m_vOrgUp, &m_vDir);
	D3DXVECTOR3 m_vDir2;
	D3DXVec3TransformNormal(&m_vDir2, &m_vDir, &m_pTarget->GetmRot());
	//m_vLook = (m_pTarget->GetvPos()+ m_vHead) + m_vDir*10.0f;
	m_vLook = (m_pTarget->GetvPos() + m_vHead) + m_vDir2*10.0f;
	//m_vLook = (m_pTarget->GetvPos()+ m_vHead) + m_vDir*10.0f;
	if (m_vLook.y < 0)
		m_vLook.y = 0;
	ViewTransform();
	ProjectionTransform();
}

void FPSCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}
