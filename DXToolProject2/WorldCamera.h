#pragma once
class WorldCamera
{
	D3DXMATRIX			m_mView;
	D3DXMATRIX			m_mProj;
	D3DXMATRIX m_Billboard;

	PROPERTY_FUNC(D3DXVECTOR3,vEye);			// ī�޶� ��ġ
	PROPERTY_FUNC(D3DXVECTOR3, vLookAt);		// ī�޶� �ٶ󺸴°�
	PROPERTY_FUNC(D3DXVECTOR3, vUp);			// ī�޸� ������

	POINT				m_ptOrgMouse;	// ���콺 ������ġ ��(ī�޸�ȸ����)
	float				m_fMouseRotX;	// ���콺 x�� ����
	float				m_fMouseRotY;	// ���콺 y�� ����

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

