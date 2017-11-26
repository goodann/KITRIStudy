#pragma once
class Character :
	public GameObject
{
protected:
	Weapon* m_Weapon;
	myTimer m_ShotTimer;
	int m_HP;
	int m_Power;
public:
	int& Power() { return m_Power; }
	void Shot();
	virtual void Update();
	void SetTimer(float _time);
	Character();
	~Character();
	void Attacked(int damage);
	void Init(std::wstring _name, int _x, int _y, DWORD color);
	void Init(std::wstring _name, Vector2 _pos, DWORD color);
};

