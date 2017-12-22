#include"GameCommon.h"



void UICheckBox::Init(int _x, int _y, string TextureNameOff, string TextureNameOn, bool * pObserver, bool * visibleOption, D3DXCOLOR _color, UI * _Parent)
{
	UI::Init(_x, _y, TextureNameOff, visibleOption, _color, _Parent);
	m_pTextureOn = TEXMGR->GetTexture(TextureNameOn, _color);
	m_pObserver = pObserver;
	m_Text.Init(FT_UI, D3DXCOLOR(1, 1, 1, 1), m_vScale.x / 2 - 24, m_vScale.y / 2 - 10, m_vScale.x, m_vScale.y);
	m_Text.SetParent(this);
}

void UICheckBox::Update(float dTime)
{
	UI::Update(dTime);
	if(m_pObserver)
		*m_pObserver = m_bChecked;
}

void UICheckBox::Render(void)
{
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if(m_bChecked)
		DEVICE->SetTexture(0, m_pTextureOn->GetTexture());
	else
		DEVICE->SetTexture(0, m_pTexture->GetTexture());
	DEVICE->SetStreamSource(0, m_pVB, 0, sizeof(D3DFVF_XYZ_TEX1));
	DEVICE->SetFVF(D3DFVF_XYZ_TEX1::FVF);
	DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);

	DEVICE->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);// (D3DPT_TRIANGLELIST, 12		m_arrVertex, sizeof(D3DFVF_XYZ_COLOR));

	DEVICE->SetTexture(0, nullptr);
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	m_Text.Render();
	
}

void UICheckBox::Release(void)
{
}

void UICheckBox::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	switch (iMsg)
	{
	case WM_MOUSEMOVE:
		IsPtInRect(LOWORD(lParam), HIWORD(lParam));
		break;
	case WM_LBUTTONDOWN:
		if (bIsPtInRect) {
			m_bChecked = !m_bChecked;
		}
		break;
		
	default:
		break;
	}


}

void UICheckBox::SetText(string str)
{
	m_Text.m_Text = str;
}

UICheckBox::UICheckBox()
{
	m_bChecked = false;
	m_pObserver = nullptr;
	bIsPtInRect = false;
}


UICheckBox::~UICheckBox()
{
	Release();
}
