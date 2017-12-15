#pragma once
class Enemy :
	public baseObject
{
protected:
	baseObject* m_pTarget;
public:
	virtual void Update(float dTime);
	Enemy();
	~Enemy();
};

