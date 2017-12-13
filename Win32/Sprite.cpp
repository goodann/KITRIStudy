#include"IncludeAPI.h"



Sprite::Sprite()
{
	m_Target = nullptr;
	m_hDC = 0;
	m_hMemDC = 0;
	m_size(0, 0);
	m_Color = 0;
	m_texSize (0,0);
	m_isTex = false;
	m_isAlpha = false;
}


Sprite::~Sprite()
{
	ReleaseSprite();
}

Vector2& Sprite::Size()
{
	return m_size;
}

Vector2 & Sprite::TexSize()
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_texSize;
}

void Sprite::LoadSprite(HDC _dc, LPCWSTR _name,  Vector2 _texSize, bool _isAlpha, DWORD color) {
	std::wstring _fileName = _T("Resource/");
	_fileName += _name;
	m_hDC = _dc;
	m_Color = color;
	m_isAlpha = _isAlpha;
	m_texSize = _texSize;
	m_isTex = true;
	// 이미지 로드
	m_hMemDC = CreateCompatibleDC(m_hDC);
	HBITMAP bit = (HBITMAP)LoadImage(NULL, _fileName.c_str(),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(m_hMemDC, bit);
	if (bit == NULL)
	{
		wchar_t tmp[128] = { 0, };
		wsprintf(tmp, _T("Texture Load Fail : %s"), _fileName);
		MessageBox(NULL, tmp, _T("error"), MB_OK);
		return;
	}
	BITMAP		info;
	GetObject(bit, sizeof(info), &info);
	m_size(info.bmWidth, info.bmHeight);

}
void Sprite::LoadSprite(HDC _dc, LPCWSTR _name, bool _isAlpha, DWORD color)
{
	std::wstring _fileName = _T("Resource/");
	_fileName +=_name;
	m_hDC = _dc;
	DWORD aa = RGB(0, 0, 255);
	m_Color = color;
	m_isAlpha = _isAlpha;
	
	m_isTex = false;
	// 이미지 로드
	m_hMemDC = CreateCompatibleDC(m_hDC);
	HBITMAP bit = (HBITMAP)LoadImage(NULL, _fileName.c_str(),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(m_hMemDC, bit);
	if (bit == NULL)
	{
		wchar_t tmp[128] = { 0, };
		wsprintf(tmp, _T("Texture Load Fail : %s"), _fileName);
		MessageBox(NULL, tmp, _T("error"), MB_OK);
		return;
	}
	BITMAP		info;
	GetObject(bit, sizeof(info), &info);
	m_size(info.bmWidth, info.bmHeight);
	
	m_texSize = m_size;
}
/*
void Sprite::LoadSprite(HDC _dc, LPCWSTR _name, DWORD color)
{
	m_hDC = _dc;
	m_Color = color;
	
	// 이미지 로드
	m_hMemDC = CreateCompatibleDC(m_hDC);
	HBITMAP bit = (HBITMAP)LoadImage(NULL, _name,
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	SelectObject(m_hMemDC, bit);


	if (bit == NULL)
	{
		wchar_t tmp[128] = { 0, };
		wsprintf(tmp, _T("Texture Load Fail : %s"), _name);
		MessageBox(NULL, tmp, _T("error"), MB_OK);
		return;
	}

	BITMAP		info;
	GetObject(bit, sizeof(info), &info);
	m_size(info.bmWidth, info.bmHeight);
}
*/
void Sprite::RenderSprite(HDC _backDC, int _x, int _y)
{
	if (m_isAlpha==false)
	{
		BitBlt(_backDC, _x, _y, m_size.x, m_size.y,
			m_hMemDC, 0, 0, SRCCOPY);
	}
	else
	{
		TransparentBlt(_backDC, _x, _y, m_size.x, m_size.y,
			m_hMemDC, 0, 0, m_size.x, m_size.y, m_Color);
	}


	//if (m_Color == -1)
	//{
	//	BitBlt(_backDC, _x, _y, m_size.x, m_size.y,
	//		m_hMemDC, 0, 0, SRCCOPY);
	//}
	//else
	//{
	//	TransparentBlt(_backDC, _x, _y, m_size.x, m_size.y,
	//		m_hMemDC, 0, 0, m_size.x, m_size.y, m_Color);
	//}
}
void Sprite::RenderSprite(HDC _backDC, int _x, int _y, int _texX, int _texY)
{
	//if (m_Color == -1)
	if (m_isAlpha == false)
	{
		BitBlt(_backDC, _x, _y, m_texSize.x, m_texSize.y,
			m_hMemDC, _texX, _texY, SRCCOPY);
	}
	else
	{
		TransparentBlt(_backDC, _x, _y, m_texSize.x, m_texSize.y,
			m_hMemDC, _texX, _texY, m_texSize.x, m_texSize.y, m_Color);
	}
}


void Sprite::RenderSprite(HDC _backDC, int _x, int _y, int _width)
{
	BitBlt(_backDC, _x, _y, _width, m_size.y,
		m_hMemDC, 0, 0, SRCCOPY);
}



void Sprite::RenderSprite(HDC _backDC, int _x, int _y, int _w,int _h,int _texX, int _texY)
{
	if (m_Color == -1)
	{
		BitBlt(_backDC, _x, _y, _w, _h,
			m_hMemDC, _texX, _texY, SRCCOPY);
	}
	else
	{
		TransparentBlt(_backDC, _x, _y, _w, _h,
			m_hMemDC, _texX, _texY, _w, _h, m_Color);
	}
}

void Sprite::RenderSprite(HDC _backDC, int _x, int _y, BLENDFUNCTION _blenFunc)
{
	AlphaBlend(_backDC, _x, _y, m_size.x, m_size.y,
		m_hMemDC, 0, 0, m_size.x, m_size.y, _blenFunc);
}

void Sprite::RenderSprite(HDC _backDC, int _x, int _y, RECT _rcDraw)
{
	BitBlt(_backDC, _x, _y, _rcDraw.right - _rcDraw.left, _rcDraw.bottom - _rcDraw.top,
		m_hMemDC, _rcDraw.left, _rcDraw.top, SRCCOPY);
}

void Sprite::RenderSprite(HDC _backDC, Vector2 _pos)
{
	RenderSprite(_backDC, _pos.x, _pos.y);
}

void Sprite::RenderSprite(HDC _backDC, Vector2 _pos, int _width)
{
	RenderSprite(_backDC, _pos.x, _pos.y,_width);
}

void Sprite::RenderSprite(HDC _backDC, Vector2 _pos, Vector2 _texPos)
{
	RenderSprite(_backDC, _pos.x, _pos.y, _texPos.x, _texPos.y);
}
void Sprite::RenderSprite(HDC _backDC, Vector2 _pos, Vector2 _texSIze,Vector2 _texPos)
{
	RenderSprite(_backDC, _pos.x, _pos.y, _texSIze.x, _texSIze.y,_texPos.x, _texPos.y);
}

void Sprite::RenderSprite(HDC _backDC, Vector2 _pos, BLENDFUNCTION _blenFunc)
{
	RenderSprite(_backDC, _pos.x, _pos.y,_blenFunc);
}

void Sprite::RenderSprite(HDC _backDC, Vector2 _pos, RECT _rcDraw)
{
	RenderSprite(_backDC, _pos.x, _pos.y,_rcDraw);
}

void Sprite::ReleaseSprite(void)
{
	DeleteObject(m_hMemDC);
}
