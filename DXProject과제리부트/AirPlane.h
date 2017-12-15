#pragma once
class AirPlane :
	public baseObject
{
	PROPERTY_FUNC(AirPlaneBoom*,LBoom);
	PROPERTY_FUNC(AirPlaneBoom*, RBoom);
	D3DXMATRIX m_mPPTM;
	float m_fPosRadian;
public:
	void Init(OBJECTINFO _info);
	void Update(float dTime);
	void Render(void);
	void Release(void);
	AirPlane();
	~AirPlane();
};

