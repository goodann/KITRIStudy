#pragma once
class Enemy :
	public Character
{
	MovingAI* m_MovingAI;
	//Weapon* m_Weapon;
public:
	virtual void Init(std::wstring _name, int _x, int _y, DWORD color = -1, MovingAI* _moveAI=nullptr, Weapon* _Weapon = nullptr);
	virtual void Init(std::wstring _name, Vector2 _pos, DWORD color = -1, MovingAI* _moveAI = nullptr, Weapon* _Weapon = nullptr);
	virtual void Update();
	Enemy();
	~Enemy();
	virtual void OnDelete();
};

