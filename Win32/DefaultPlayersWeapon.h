#pragma once
class DefaultPlayersWeapon:public Weapon
{
public:
	void Fire(Character* _Shooter);
	DefaultPlayersWeapon();
	~DefaultPlayersWeapon();
};

