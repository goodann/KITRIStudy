#pragma once
class Bullet :
	public GameObject
{
public:
	void Update(void);
	void OnCollisionHit(GameObject* pCollObj);
	Bullet();
	~Bullet();
};

