#include "GameCommon.h"


void WorldCamera::SetUp(D3DXVECTOR3 vEye)
{
	m_vEye = vEye;

	ViewTransform();
	ProjectionTransform();
}

void WorldCamera::ViewTransform(void)
{
	D3DXMatrixLookAtLH(&m_mView, &m_vEye, &m_vLookAt, &m_vUp);
	DEVICE->SetTransform(D3DTS_VIEW, &m_mView);
	m_Billboard._11 = m_mView._11;
	m_Billboard._13 = m_mView._13;
	m_Billboard._31 = m_mView._31;
	m_Billboard._33 = m_mView._33;
	D3DXMatrixInverse(&m_Billboard, 0, &m_Billboard);
}

void WorldCamera::ProjectionTransform(void)
{
	D3DXMatrixPerspectiveFovLH(&m_mProj, D3DX_PI / 4, 
		(float)WINMGR->GetWidth() / WINMGR->GetHeight(), 0.1f, 1000.0f);
	DEVICE->SetTransform(D3DTS_PROJECTION, &m_mProj);
}

void WorldCamera::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_MOUSEMOVE:
	{
		if (m_bRButtonDown)
		{
			int iDeltaX = LOWORD(lParam) - m_ptOrgMouse.x;
			int iDeltaY = HIWORD(lParam) - m_ptOrgMouse.y;

			m_fMouseRotX = iDeltaY / 100.f;
			m_fMouseRotY = iDeltaX / 100.f;

			m_ptOrgMouse.x = LOWORD(lParam);
			m_ptOrgMouse.y = HIWORD(lParam);

			D3DXMATRIXA16 matCamRot, matCamRotX, matCamRotY;
			D3DXMatrixRotationX(&matCamRotX, m_fMouseRotX);
			D3DXMatrixRotationY(&matCamRotY, m_fMouseRotY);

			matCamRot = matCamRotX * matCamRotY;
			D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matCamRot);

			ViewTransform();
		}
	}
	break;
		case WM_RBUTTONDOWN:
		{
			m_ptOrgMouse.x = LOWORD(lParam);
			m_ptOrgMouse.y = HIWORD(lParam);
			m_bRButtonDown = true;
		}
		break;

		case WM_RBUTTONUP:
			m_bRButtonDown = false;
			break;

		case WM_MOUSEWHEEL:
		{
			float fWheel = GET_WHEEL_DELTA_WPARAM(wParam) / 100.f;
			
			D3DXVECTOR3 vDir = m_vLookAt - m_vEye;
			D3DXVec3Normalize(&vDir, &vDir);

			m_vEye += vDir * fWheel;

			ViewTransform();
		}
		break;
	}
}

WorldCamera::WorldCamera()
	: m_vEye(0,0,0)
	, m_vLookAt(0,0,0)
	, m_vUp(0,1,0)
	, m_fMouseRotX(0)
	, m_fMouseRotY(0)
	, m_bRButtonDown(false)
{
	m_ptOrgMouse.x = 0;
	m_ptOrgMouse.y = 0;
	D3DXMatrixIdentity(&m_Billboard);
}


WorldCamera::~WorldCamera()
{
}
