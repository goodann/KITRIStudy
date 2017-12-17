#pragma once

struct ParticleEffectInfo {
	float lifeTime;
	float minLifeTime;
	float maxLifeTime;
	//float FireAangle;
	//float PosAangle;


	D3DXVECTOR3 vVelocity;
	D3DXVECTOR3 vMinVelocity;
	D3DXVECTOR3 vMaxVelocity;
	
	D3DXVECTOR3 vPos;
	D3DXVECTOR3 vMinPos;
	D3DXVECTOR3 vMaxPos;
	string sFileName;
	D3DXCOLOR MaskColor;
	OBJECTINFO ObjInfo;
	bool UseGravity;
	
};


class ParticleEffect :
	public Effect
{
protected:
	ParticleEffectInfo m_ParticleInfo;
	PROPERTY_FUNC(bool, UseGravity);

public:
	void Init(ParticleEffectInfo _info);
	void Update(float dTime);
	void Render(void);
	void Release(void);
	ParticleEffect();
	~ParticleEffect();
};

