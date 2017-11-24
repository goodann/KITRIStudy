#pragma once
class Sprite
{
	HDC			m_hDC;
	HDC			m_hMemDC;

	Vector2 m_size;
	DWORD		m_Color;

public:
	Vector2& Size();
	void LoadSprite(HDC _dc, LPCWSTR _name, DWORD color = -1);
	void RenderSprite(HDC _backDC, int _x, int _y);
	void RenderSprite(HDC _backDC, int _x, int _y, int _width);
	void RenderSprite(HDC _backDC, int _x, int _y, int _texX, int _texY);
	void RenderSprite(HDC _backDC, int _x, int _y, BLENDFUNCTION _blenFunc);
	void RenderSprite(HDC _backDC, int _x, int _y, RECT _rcDraw);

	void RenderSprite(HDC _backDC, Vector2 _pos);
	void RenderSprite(HDC _backDC, Vector2 _pos, int _width);
	void RenderSprite(HDC _backDC, Vector2 _pos, Vector2 _texSIze);
	void RenderSprite(HDC _backDC, Vector2 _pos, BLENDFUNCTION _blenFunc);
	void RenderSprite(HDC _backDC, Vector2 _pos, RECT _rcDraw);
	void ReleaseSprite(void);
public:
	Sprite();
	~Sprite();
};

