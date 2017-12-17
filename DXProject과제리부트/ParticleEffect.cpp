#include"GameCommon.h"


void ParticleEffect::Init(ParticleEffectInfo _info)
{
	baseObject::Init(_info.ObjInfo);
	m_fLifeTime = _info.lifeTime + (fRandom(_info.minLifeTime, _info.maxLifeTime));
	//m_Transform->Init(_info.ObjInfo);
	m_Transform->SetvPos(_info.ObjInfo.vPos+_info.vPos + fRandomVec3(_info.vMinPos, _info.vMaxPos));
	
	m_vVelocity = _info.vVelocity + fRandomVec3(_info.vMinVelocity, _info.vMaxVelocity);


	m_arrVtx[0].vPos = D3DXVECTOR3(-1, 1, 0);
	m_arrVtx[1].vPos = D3DXVECTOR3(1, 1, 0);
	m_arrVtx[2].vPos = D3DXVECTOR3(-1, -1, 0);
	m_arrVtx[3].vPos = D3DXVECTOR3(1, -1, 0);


	m_arrVtx[0].u = 0;
	m_arrVtx[1].u = 1;
	m_arrVtx[2].u = 0;
	m_arrVtx[3].u = 1;

	m_arrVtx[0].v = 0;
	m_arrVtx[1].v = 0;
	m_arrVtx[2].v = 1;
	m_arrVtx[3].v = 1;
	DEVICE->CreateVertexBuffer(sizeof(m_arrVtx), 0, D3DFVF_XYZ_NORMAL_UV::FVF, D3DPOOL_DEFAULT, &m_pVB, nullptr);
	if (m_pVB) {
		void* pData = nullptr;
		m_pVB->Lock(0, sizeof(m_arrVtx), &pData, 0);
		memcpy(pData, m_arrVtx, sizeof(m_arrVtx));
		m_pVB->Unlock();
	}
	m_UseGravity = _info.UseGravity;
	m_pTexture = TEXMGR->GetTexture(_info.sFileName, _info.MaskColor);
	

}

void ParticleEffect::Update(float dTime)
{
	baseObject::Update(dTime);
	if (m_UseGravity) {
		m_vVelocity += GRAVITY*dTime;
	}
	m_fLifeTime -= dTime;
	if (m_fLifeTime < 0.0f) {
		m_bLife = false;
		return;
	}
	else {
		
		m_Transform->GetvPos() += m_vVelocity * dTime;
		//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
		//m_mTM = m_mTrans;
		return;
	}
}

void ParticleEffect::Render(void)
{
	//baseObject::Render();
	DEVICE->SetTransform(D3DTS_WORLD, &m_Transform->GetmTM());
	//DEVICE->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2);
	DEVICE->SetRenderState(D3DRS_LIGHTING, false);
	DEVICE->SetStreamSource(0, m_pVB, 0, sizeof(D3DFVF_XYZ_NORMAL_UV));
	DEVICE->SetFVF(D3DFVF_XYZ_NORMAL_UV::FVF);
	DEVICE->SetTexture(0, m_pTexture->GetTexture());

	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	DEVICE->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);

	DEVICE->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	DEVICE->SetTexture(0, nullptr);
}

void ParticleEffect::Release(void)
{
	SAFE_RELEASE(m_pVB);
}

ParticleEffect::ParticleEffect()
{
	m_UseGravity = false;
}


ParticleEffect::~ParticleEffect()
{
}
