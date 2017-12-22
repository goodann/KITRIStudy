
#include"GameCommon.h"

SINGLETON_INIT(FontManager)
FontManager::FontManager()
	: m_pFont(NULL)
{
}


FontManager::~FontManager()
{
	Release();
}

LPD3DXFONT FontManager::GetFonts(FONTTYPE enType)
{

	if (m_mapFonts[enType] != NULL)
		return m_mapFonts[enType];

	switch (enType)
	{
	case FT_DEFAULT:
	{
		D3DXFONT_DESC fd;
		ZeroMemory(&fd, sizeof(D3DXFONT_DESC));

		fd.Width = 6;
		fd.Height = 12;
		fd.Weight = FW_MEDIUM; // FW_BOLD
		fd.CharSet = DEFAULT_CHARSET;
		strcpy_s(fd.FaceName, "±¼¸²Ã¼");

		D3DXCreateFontIndirect(DEVICE, &fd,
			&m_mapFonts[enType]);
	}
	break;

	case FT_BOADER:
	{
		D3DXFONT_DESC fd;
		ZeroMemory(&fd, sizeof(D3DXFONT_DESC));

		fd.Width = 12;
		fd.Height = 24;
		fd.Weight = FW_BOLD; // FW_BOLD
		fd.CharSet = DEFAULT_CHARSET;
		strcpy_s(fd.FaceName, "±¼¸²Ã¼");

		D3DXCreateFontIndirect(DEVICE, &fd,
			&m_mapFonts[enType]);
	}
	break;
	case FT_UI:
	{
		D3DXFONT_DESC fd;
		ZeroMemory(&fd, sizeof(D3DXFONT_DESC));

		fd.Width = 10;
		fd.Height = 20;
		fd.Weight = FW_BOLD; // FW_BOLD
		fd.CharSet = DEFAULT_CHARSET;
		strcpy_s(fd.FaceName, "¹ÙÅÁÃ¼");

		D3DXCreateFontIndirect(DEVICE, &fd,
			&m_mapFonts[enType]);
	}
	break;
	}

	return m_mapFonts[enType];
}

void FontManager::Setup(void)
{
	D3DXFONT_DESC fd;
	ZeroMemory(&fd, sizeof(D3DXFONT_DESC));

	fd.Width = 6;
	fd.Height = 12;
	fd.Weight = FW_MEDIUM; // FW_BOLD
	fd.CharSet = DEFAULT_CHARSET;
	strcpy_s(fd.FaceName, "±¼¸²Ã¼");
	//fd.Italic

	D3DXCreateFontIndirect(DEVICE, &fd, &m_pFont);
}

void FontManager::DrawText(int _x, int _y, D3DXCOLOR _color, char * msg, ...)
{
	char _szBuff[256] = { 0, };

	va_list vl;
	va_start(vl, msg);
	vsprintf_s(_szBuff, msg, vl);
	va_end(vl);

	RECT rc = { _x, _y, 0, 0 };
	m_pFont->DrawText(NULL, _szBuff, (int)strlen(_szBuff),
		&rc, DT_NOCLIP, _color);
}

void FontManager::Release(void)
{
	SAFE_RELEASE(m_pFont);
}
