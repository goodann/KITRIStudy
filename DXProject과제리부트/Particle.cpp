#include"GameCommon.h"


void Particle::Init(ParticleInfo _info)
{

	baseObject::Init(_info.ObjInfo);
	m_info = _info;

}

void Particle::Update(float dTime)
{

	static float fOldTime = 0.0f;
	static float fCurrTime = 0.0f;

	fCurrTime += dTime;
	if (fCurrTime > fOldTime) {
		if ((int)m_listParticles.size() < m_info.MaxParticleCount) {
			CreateParticle(m_info.EffectInfo);
			fOldTime = fCurrTime + m_info.ParticleMakeCycle;
		}
	}

	for (auto itor = m_listParticles.begin(); itor != m_listParticles.end();) {
		(*itor)->Update(dTime);
		if ((*itor)->GetbLife()==false) {
			SAFE_DELETE(*itor);
			itor = m_listParticles.erase(itor);
		}
		else {
			++itor;
		}
	}
	baseObject::Update(dTime);
}

void Particle::Render()
{
	//baseObject::Render();
	for (auto& p : m_listParticles) {
		p->Render();
	}
}

void Particle::Release()
{

	for (auto& p : m_listParticles) {
		SAFE_DELETE(p);
	}
	m_listParticles.clear();
	baseObject::Release();
}

void Particle::CreateParticle(ParticleEffectInfo _info)
{

	//_info.lifeTime = 2.0f;
	//_info.minLifeTime = 0.5f;
	//_info.maxLifeTime = 2.5f;
	//_info.vPos = D3DXVECTOR3(0, 0, 0);
	//_info.vMinPos = D3DXVECTOR3(-1, -1, -1);
	//_info.vMaxPos = D3DXVECTOR3(1, 1, 1);

	//_info.vVelocity = D3DXVECTOR3(0, 5, 0);
	//_info.vMinVelocity = D3DXVECTOR3(-5, 0, -5);
	//_info.vMaxVelocity = D3DXVECTOR3(1, 0, 1);
	ParticleEffect *p = new ParticleEffect;
	p->Init(_info);
	m_listParticles.push_back(p);
}

Particle::Particle()
{
	int m_MaxParticleCount=0;
	float m_particleMakeCycle=0;
}


Particle::~Particle()
{
	Release();
}
