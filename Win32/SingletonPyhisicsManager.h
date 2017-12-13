#pragma once
class SingletonPyhisicsManager
{
public:
	SINGLETON_FUNC(SingletonPyhisicsManager);
	std::forward_list<Collider*> m_ListColliders;
	int size;
public:
	int GetCollisionCount() { return size; }
	bool isCollision(Position& a, Position& b);
	void Update();
	void AddCollider(GameObject* _Obj);
	void DeleteCollider(GameObject* _pObj);
	bool RePosCheck(GameObject* _pObj);
};

