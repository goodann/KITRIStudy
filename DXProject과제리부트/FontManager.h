#pragma once

#define FONTMGR FontManager::GetInstance()

class FontManager
{
	SINGLETON_FUNC(FontManager);

	LPD3DXFONT			m_pFont;

public:
	void Setup(void);
	void DrawText(int _x, int _y, D3DXCOLOR _color,
		char* msg, ...);
	void Release(void);
};

