#pragma once
class AirPlane :
	public baseObject
{
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

