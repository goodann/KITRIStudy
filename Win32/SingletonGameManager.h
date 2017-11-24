#pragma once


class SingletonGameManager
{

	SINGLETON_FUNC(SingletonGameManager);

	HDC		m_hDC;
	HDC		m_hBackDC;


	Scene* m_CurrScene;
	Scene* m_Scenes[ST_MAX];
	Scene* m_NextScene;
	SCENETYPE m_SceneType;


public:

	GameObject* CreateObject(std::wstring _name, std::wstring _classname,
		int _x, int _y, DWORD color = -1);
	void CreateObject(GameObject* _Obj);
public:
	void Init(void);
	void Update(void);
	void Render(void);
	void Release(void);
	void Loop(void);
};

