#pragma once
class DefaultEnemysWeapon :
	public Weapon
{
public:
	void Fire(Character* _Shooter);
	DefaultEnemysWeapon();
	~DefaultEnemysWeapon();
};

