#pragma once
class Effect:public baseObject
{
protected:
	//GETTER(bool, bLife);
	MyTexture * m_pTexture;
	LPDIRECT3DVERTEXBUFFER9 m_pVB;
	D3DFVF_XYZ_NORMAL_UV m_arrVtx[4];
	//ParticleInfo m_ParticleInfo;


	D3DXVECTOR3 m_vVelocity;
	float m_fLifeTime;

	//D3DXVECTOR3 m_vPos;
	//D3DXVECTOR3 m_vRot;
	//D3DXVECTOR3 m_vScale;

	//D3DXMATRIX m_mTM;
	//D3DXMATRIX m_mTrans;
	//D3DXMATRIX m_mRot;
	//D3DXMATRIX m_mScale;
public:
	virtual void Update(float dTime)=0;
	virtual void Render(void)=0;
	virtual void Release(void)=0;
	float fRandom(float _min, float _max);
	D3DXVECTOR3 fRandomVec3(D3DXVECTOR3 _min, D3DXVECTOR3 _max);
	Effect();
	virtual ~Effect();
};

