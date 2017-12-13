#pragma once
class Bullet :
	public GameObject
{
public:
	void Update(void);
	void OnCollisionHit(GameObject* pCollObj);
	virtual void Init(std::wstring _name, int _x, int _y);
	virtual void Init(std::wstring _name, Vector2 _pos);
	Bullet();
	~Bullet();
};

