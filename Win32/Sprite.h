#pragma once
class GameObject;

class Sprite
{
protected:
	HDC			m_hDC;
	HDC			m_hMemDC;

	Vector2 m_size;
	DWORD		m_Color;
	GameObject* m_Target;

public:
	Vector2& Size();
	inline GameObject*& Target() { return m_Target; }
	virtual void LoadSprite(HDC _dc, LPCWSTR _name, DWORD color = -1);
	virtual void RenderSprite(HDC _backDC, int _x, int _y);
	virtual void RenderSprite(HDC _backDC, int _x, int _y, int _width);
	virtual void RenderSprite(HDC _backDC, int _x, int _y, int _texX, int _texY);
	virtual void RenderSprite(HDC _backDC, int _x, int _y, int _w,int _h, int _texX, int _texY);
	virtual void RenderSprite(HDC _backDC, int _x, int _y, BLENDFUNCTION _blenFunc);
	virtual void RenderSprite(HDC _backDC, int _x, int _y, RECT _rcDraw);

	virtual void RenderSprite(HDC _backDC, Vector2 _pos);
	virtual void RenderSprite(HDC _backDC, Vector2 _pos, int _width);
	virtual void RenderSprite(HDC _backDC, Vector2 _pos, Vector2 _texPos);
	virtual void RenderSprite(HDC _backDC, Vector2 _pos, Vector2 _texSIze,Vector2 _texPos);
	virtual void RenderSprite(HDC _backDC, Vector2 _pos, BLENDFUNCTION _blenFunc);
	virtual 	void RenderSprite(HDC _backDC, Vector2 _pos, RECT _rcDraw);
	void ReleaseSprite(void);
public:
	Sprite();
	virtual ~Sprite();
};

