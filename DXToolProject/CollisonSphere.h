#pragma once
class CollisonSphere : public baseObject
{
	GETTER(COLLSPHEREINFO, collInfo);

public:
	virtual void Init(OBJECTINFO _info);
	virtual void Update(float dTime);
	virtual void Render(void);
	void Release(void);

public:
	CollisonSphere();
	~CollisonSphere();
};

