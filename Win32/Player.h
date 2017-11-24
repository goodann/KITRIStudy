#pragma once
class Player :
	public Character
{
	bool m_IsSpaceKey;
public:
	void Update();
	void KeyInput();
	void Shot();
	void Fire();
	Player();
	~Player();
};

