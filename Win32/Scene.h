#pragma once
class Scene
{
protected:
	std::wstring m_SceneName;
	HDC		m_hDC;
	HDC		m_hBackDC;

	std::list<GameObject*>			m_listObjects;
public:
	std::wstring& SceneName() { return m_SceneName; }
	virtual void Init(HDC hdc) = 0;
	virtual void Update(void) = 0;
	virtual void Render(HDC _backDC) = 0;
	virtual void Release() = 0;
	virtual void CreateObject(GameObject * _Obj);
	Scene();
	virtual ~Scene() = 0;
};

