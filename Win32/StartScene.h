#pragma once

class StartScene :
	public Scene
{
	Sprite* m_Sprite;
	BLENDFUNCTION m_BlenFunc;
	myTimer m_Timer;
	Sprite* m_map;
public:
	virtual void Init(HDC hdc);
	virtual void Update(void);
	virtual void Render(HDC _backDC);
	virtual void Release();
	StartScene();
	~StartScene();
};

