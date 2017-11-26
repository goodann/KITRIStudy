#pragma once
class Collider
{
	GameObject* m_target;
public:
	inline GameObject* Target() { return m_target; }
	Collider();
	Collider(GameObject* _pObj);
	void OnCollisionHit(Collider* _other);
	~Collider();
};

