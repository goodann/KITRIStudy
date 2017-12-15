
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
