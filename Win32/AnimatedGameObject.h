#pragma once
class AnimatedGameObject :
	public GameObject
{
	myTimer m_Timer;
	Vector2 m_texPos;
	
public:

	void Render(HDC _backDC);
	virtual void Init(std::wstring _name, int _x, int _y, int _w, int _h, DWORD color = -1, float _time = 0.8f);
	virtual void Init(std::wstring _name, Vector2 _pos, Vector2 _size, DWORD color = -1, float _time = 0.8f);
	AnimatedGameObject();
	~AnimatedGameObject();
};

