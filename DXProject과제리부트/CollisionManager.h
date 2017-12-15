#pragma once
class CollisionManager : public MySingleton<CollisionManager>
{
public:
	list<CollisonSphere*>			m_listColls;
	GETTER(bool, bDraw);

public:
	void CreateCollisionSphere(OBJECTINFO _info);

	void IsCollisionSphere(CollisonSphere * pColl, float dTime, bool isForward = true);
	baseObject* IsCheckColl(CollisonSphere* pColl);

	void Update(float dTime);
	void Render(void);
	void DeleteCollison(CollisonSphere* pColl);

public:
	CollisionManager();
	~CollisionManager();
};
