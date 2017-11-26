#pragma once
class GameObject
{
protected:
	Position m_Pos;
	Vector2 m_Speed;
	Sprite* m_Sprite;
	Vector2 m_TotalSize;
	bool m_Life;
	std::wstring m_ClassName;
	std::wstring m_Tag;


public:
	inline bool& Life() { return m_Life; }
	inline std::wstring& TAG() { return m_Tag; }
	std::wstring& ClassName();
	virtual void Init(std::wstring _name, int _x, int _y, DWORD color = -1);
	virtual void Init(std::wstring _name, Vector2 _pos, DWORD color = -1);
	virtual void Init(std::wstring _name, int _x, int _y,int _w,int _h, DWORD color = -1);
	virtual void Init(std::wstring _name, Vector2 _pos, Vector2 _size,DWORD color = -1);
	virtual void Update(void);
	virtual void Render(HDC _backDC);
	virtual void Release(void);
	inline Vector2& Speed() { return m_Speed; }
	inline Position& Position() { return m_Pos; }
	GameObject();
	virtual ~GameObject();
	virtual void OnCollisionHit(GameObject* other) {}
	std::wstring Multi2Wide(const char* pStr);
	virtual void Attacked(int damage);
	virtual void OnDelete() {}
};

