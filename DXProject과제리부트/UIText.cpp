#include "GameCommon.h"


void UIText::Init(FONTTYPE enType, DWORD color,
	int _x, int _y, int _w, int _h)
{
	m_vPos.x = _x;
	m_vPos.y = _y;
	m_vPos.z = 1;
	m_fWidth = _w;
	m_fHeight = _h;
	m_color = color;

	m_pFont = FONTMGR->GetFonts(enType);
}


void UIText::Render(void)
{
	RECT rc;
	if (m_Parent)
		D3DXVec3TransformCoord(&m_vPosUI, &m_vPos, &m_Parent->GetmTrans());
	else
		m_vPosUI = m_vPos;

	SetRect(&rc, m_vPosUI.x, m_vPosUI.y,
		m_vPosUI.x + m_fWidth, m_vPosUI.y + m_fHeight);

	m_pFont->DrawText(NULL, m_Text.c_str(), m_Text.length(),
		&rc, DT_TOP | DT_LEFT | DT_WORDBREAK, m_color);
}

UIText::UIText()
{
	m_Parent = NULL;
}


UIText::~UIText()
{
}
