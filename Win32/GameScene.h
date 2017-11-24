#pragma once

class GameScene :
	public Scene
{
protected:


public:
	virtual GameObject* CreateObject(std::wstring _name, std::wstring _classname,int _x, int _y, DWORD color = -1);
	
	void ObjectClear(void);
public:
	HDC GetScreenDC(void) { return m_hDC; }
	void DebugView(HDC _backDC);
public:
	virtual void Init(HDC hdc);
	virtual void Update(void);
	virtual void Render(HDC _backDC);
	virtual void Release();
	GameScene();
	~GameScene();
};

