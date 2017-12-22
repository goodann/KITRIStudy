#pragma once
#include "UI.h"

enum BTNTYPE { BT_NORMAL, BT_OVER, BT_CLICK, BT_MAX };
class UIButton :
	public UI
{
protected:
	BTNTYPE m_enBTNType;
	void(*m_pDelegateFunc)(void*);
	MyTexture * m_pTexture[BT_MAX];
	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	UIText						m_text;

	

	PROPERTY_FUNC(void*, pData);

public:
	virtual void Init(string nor, string over, string click, int _x, int _y, void(*DelegateFunc)(void*), string Label = "");
	virtual void Update(float dTime);
	virtual void Render(void);
	virtual void Release(void);
	
	virtual void WndProc(HWND hWnd, UINT iMsg, WPARAM vParam, LPARAM lParam);

public:
	UIButton();
	virtual ~UIButton();
};

