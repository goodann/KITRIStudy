#pragma once
class FPSCamera
{
	//D3DXVECTOR3 m_vEye;
	PROPERTY_FUNC(Transform*,pTarget);
	D3DXVECTOR3 m_vLook;
	D3DXVECTOR3 m_vOrgUp;
	D3DXVECTOR3 m_vUp;
	D3DXVECTOR3 m_vDir;
	D3DXVECTOR3 m_vHoriz;
	D3DXVECTOR3 m_vHead;
	D3DXVECTOR3 m_vOrgHead;

	float m_fFovy;
	float m_fAspect;
	float m_fNear;
	float m_fFar;

	D3DXMATRIX m_mView;
	D3DXMATRIX m_mProj;
	POINT m_OrgPoint;

public:
	void Init(Transform * Target, float fov, float aspect);
	void Update(float dTime);
	void ViewTransform(void);
	void ProjectionTransform(void);
	void LocalVectorUpdate(void);

	void RotateX(float angle);
	void RotateY(float angle);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	FPSCamera();
	~FPSCamera();
};

