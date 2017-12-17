#pragma once

struct ParticleInfo
{
	OBJECTINFO ObjInfo;
	ParticleEffectInfo EffectInfo;
	int MaxParticleCount;
	float ParticleMakeCycle;


};
class Particle :
	public baseObject
{
	ParticleInfo m_info;
	//int m_MaxParticleCount;
	//float m_ParticleMakeCycle;

	list<ParticleEffect*> m_listParticles;
public:
	void Init(ParticleInfo _info);
	void Update(float dTime);
	void Render();
	void Release();
	void CreateParticle(ParticleEffectInfo _info);
public:
	Particle();
	~Particle();
};

