#pragma once
class Enemy :
	public Character
{
protected:
	MovingAI* m_MovingAI;
	//Weapon* m_Weapon;
public:
	virtual void Init(std::wstring _name, int _x, int _y, MovingAI* _moveAI=nullptr, Weapon* _Weapon = nullptr);
	virtual void Init(std::wstring _name, Vector2 _pos, MovingAI* _moveAI = nullptr, Weapon* _Weapon = nullptr);
	virtual void Update();
	Enemy();
	~Enemy();
	virtual void OnDelete();
};

