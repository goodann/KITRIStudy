#pragma once
class UIText:public UI
{
public:
	LPD3DXFONT			m_pFont;
	string				m_Text;
	float				m_fWidth;
	float				m_fHeight;
	DWORD				m_color;
	
	void Init(FONTTYPE enType, DWORD color,
		int _x, int _y, int _w, int _h);
	void Render(void);

public:
	UIText();
	virtual ~UIText();
};

