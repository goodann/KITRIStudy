#pragma once
class Character :
	public GameObject
{
protected:
	Weapon* m_Weapon;
	myTimer m_ShotTimer;
public:
	void Shot();
	virtual void Update();
	void SetTimer(float _time);
	Character();
	~Character();
};

