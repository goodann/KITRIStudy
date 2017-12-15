#pragma once
class WorldCamera
{
	D3DXMATRIX			m_mView;
	D3DXMATRIX			m_mProj;
	D3DXMATRIX m_Billboard;

	PROPERTY_FUNC(D3DXVECTOR3,vEye);			// 카메라 위치
	PROPERTY_FUNC(D3DXVECTOR3, vLookAt);		// 카메라 바라보는곳
	PROPERTY_FUNC(D3DXVECTOR3, vUp);			// 카메리 업벡터

	POINT				m_ptOrgMouse;	// 마우스 이전위치 값(카메리회전용)
	float				m_fMouseRotX;	// 마우스 x축 감도
	float				m_fMouseRotY;	// 마우스 y축 감도

	bool				m_bRButtonDown;

public:

	D3DXMATRIX getBillBoard(void) {
		return m_Billboard; 
	}
	void SetUp(D3DXVECTOR3 vEye);
	void ViewTransform(void);
	void ProjectionTransform(void);
	void WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	WorldCamera();
	virtual ~WorldCamera();
};

