#pragma once
#include "UI.h"

class UICheckBox :
	public UI
{
	MyTexture * m_pTextureOn;
	bool m_bChecked;
	bool* m_pObserver;
	UIText m_Text;
public:
	virtual void Init(int _x, int _y, string TextureNameOff,string TextureNameOn, bool* pObserver=nullptr, bool* visibleOption = nullptr, D3DXCOLOR _color = D3DXCOLOR(-1, -1, -1, -1), UI* _Parent = nullptr);
	virtual void Update(float dTime);
	virtual void Render(void);
	virtual void Release(void);
	virtual void WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam);
	void SetText(string str);
public:
	UICheckBox();
	~UICheckBox();
};

