#pragma once
class UI
{
protected:
	MyTexture * m_pTexture;

	LPDIRECT3DVERTEXBUFFER9 m_pVB;


	RECT m_rc;
	bool bIsPtInRect;


	list<UI*> m_children;



	PROPERTY_FUNC(D3DXVECTOR3,vPos);
	GETTER(D3DXVECTOR3, vRot);
	PROPERTY_FUNC(D3DXVECTOR3, vScale);

	GETTER(D3DXMATRIX,mTM);
	GETTER(D3DXMATRIX,mTrans);
	GETTER(D3DXMATRIX,mScale);
	PROPERTY_FUNC(UI*, Parent);
	GETTER(D3DXVECTOR3,vPosUI);
	

	PROPERTY_FUNC(bool, bVisible);
	PROPERTY_FUNC(bool*, bpVisible);
	


public:
	virtual void Init(int _x, int _y,string TextureName,bool* visibleOption=nullptr, D3DXCOLOR _color = D3DXCOLOR(-1, -1, -1, -1),UI* _Parent=nullptr);
	virtual void Update(float dTime);
	virtual void Render(void);
	virtual void Release(void);
	virtual void WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam) {};
	virtual bool IsPtInRect(int _x, int _y);
public:
	UI();
	virtual ~UI();
};

