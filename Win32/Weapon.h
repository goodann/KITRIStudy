#pragma once
class Character;
class Weapon
{
	
public:
	virtual void Fire(Character* _Shooter) = 0;
	Weapon();
	virtual ~Weapon();
};

