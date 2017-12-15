#pragma once
class AirPlane;
class AirPlaneBoom :	public Bullet
{
	PROPERTY_FUNC(bool, isFired);
	PROPERTY_FUNC(AirPlane*, Parent);
public:
	//virtual void Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale);
	virtual void Init(OBJECTINFO _info);
	virtual void Update(float dtime);
	virtual void Render(void);
	void Fire();
	AirPlaneBoom();
	virtual ~AirPlaneBoom();
};

