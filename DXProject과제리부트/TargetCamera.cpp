#include"GameCommon.h"



TargetCamera::TargetCamera()
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
	m_vOrgHead = m_vHead = D3DXVECTOR3(0, 1,10);
}


TargetCamera::~TargetCamera()
{
}

void TargetCamera::Init(Transform * Target, float fov, float aspect)
{
	m_OrgPoint = GetClientPoint();
	m_pTarget = Target;
	m_fFovy = fov;
	m_fAspect = aspect;
	//m_vLook = Target->GetvPos() + Target->GetvDir();
	m_vLook = Target->GetvPos();
	LocalVectorUpdate();
	D3DXCreateSphere(DEVICE, 1, 36, 36, &m_mesh, 0);
	D3DXMatrixIdentity(&m_mTm);
	D3DXMatrixIdentity(&m_mTm2);
}

void TargetCamera::Update(float dTime)
{
	D3DXMATRIX mView;
	D3DXVECTOR3 pos = m_pTarget->GetvPos();
	D3DXVECTOR3 view = pos - m_pTarget->GetvDir();
	D3DXVECTOR3 CamPos = pos + m_vHead;

	D3DXVec3TransformCoord(&m_vHead, &m_vOrgHead, &m_pTarget->GetmRot());
	D3DXMatrixTranslation(&m_mTm, pos.x, pos.y, pos.z);

	D3DXMatrixTranslation(&m_mTm2, CamPos.x, CamPos.y, CamPos.z);
	//D3DXMatrixLookAtLH(&mView, &(pos+ m_vHead), &view, &D3DXVECTOR3(0, 1, 0));
	if (GAMEMGR->m_CameraType == 2){
		D3DXMatrixLookAtLH(&mView, &(CamPos), &view, &m_pTarget->GetvUp());
		DEVICE->SetTransform(D3DTS_VIEW, &mView);
	}

}

void TargetCamera::Render()
{
	DEVICE->SetTransform(D3DTS_WORLD, &m_mTm);
	m_mesh->DrawSubset(0);
	DEVICE->SetTransform(D3DTS_WORLD, &m_mTm2);
	m_mesh->DrawSubset(0);
}

void TargetCamera::ViewTransform(void)
{
	//D3DXVec3TransformNormal(&m_vLook, &m_vLook, &m_pTarget->GetmRot());
	D3DXMatrixLookAtLH(&m_mView, &(m_pTarget->GetvPos() + m_vHead), &m_vLook, &m_vOrgUp);

	DEVICE->SetTransform(D3DTS_VIEW, &m_mView);
}

void TargetCamera::ProjectionTransform(void)
{
	D3DXMatrixPerspectiveFovLH(&m_mProj, m_fFovy, m_fAspect, m_fNear, m_fFar);
	DEVICE->SetTransform(D3DTS_PROJECTION, &m_mProj);
}

void TargetCamera::LocalVectorUpdate(void)
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

void TargetCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}
