#include"GameCommon.h"


void SpriteEffect::Init(spriteInfo _info)
{
	m_SpriteInfo = _info;
	m_fSpriteU = 1.0f / _info.nSpriteCntX;
	m_fSpriteV = 1.0f / _info.nSpriteCntY;
	m_nTotalSpriteCnt = _info.nSpriteCntX*_info.nSpriteCntY;

	m_pTexture = TEXMGR->GetTexture(_info.pTexName, _info.color);
	m_fNextTime = _info.fTotalTime / m_nTotalSpriteCnt;
	//_info.ObjInfo.vPos=_info.v
	m_arrVtx[0].vPos = D3DXVECTOR3(-1, 1, 0);
	m_arrVtx[1].vPos = D3DXVECTOR3(1, 1, 0);
	m_arrVtx[2].vPos = D3DXVECTOR3(-1, -1, 0);
	m_arrVtx[3].vPos = D3DXVECTOR3(1, -1, 0);

	m_arrVtx[0].u = 0;
	m_arrVtx[1].u = m_fSpriteU;
	m_arrVtx[2].u = 0;
	m_arrVtx[3].u = m_fSpriteU;

	m_arrVtx[0].v = 0;
	m_arrVtx[1].v = 0;
	m_arrVtx[2].v = m_fSpriteV;
	m_arrVtx[3].v = m_fSpriteV;
	m_fAddTime = 0;
	DEVICE->CreateVertexBuffer(sizeof(m_arrVtx), 0, D3DFVF_XYZ_NORMAL_UV::FVF, D3DPOOL_DEFAULT, &m_pVB, nullptr);
	if (m_pVB) {
		void* pData = nullptr;
		m_pVB->Lock(0, sizeof(m_arrVtx), &pData, 0);
		memcpy(pData, m_arrVtx, sizeof(m_arrVtx));
		m_pVB->Unlock();
	}
	baseObject::Init(_info.ObjInfo);
}

void SpriteEffect::Update(float dTime)
{


	m_fCurrTime += dTime;
	if (m_fCurrTime > m_fNextTime) {
		m_nCurrSpriteTotal++;
		m_fNextTime += m_SpriteInfo.fTotalTime / m_nTotalSpriteCnt;
		if (m_fCurrTime >= m_SpriteInfo.fTotalTime) {
			if (m_SpriteInfo.bLoop == false) {
				m_bLife = false;
				m_bDead = true;
				return;
			}
			m_fCurrTime = 0;
			m_fNextTime = m_SpriteInfo.fTotalTime / m_nTotalSpriteCnt;
			m_nCurrSpriteTotal = 0;
			m_nCurrSpriteX = 0;
			m_nCurrSpriteY = 0;
		}
		if (m_SpriteInfo.nSpriteCntY > 1) {
			m_nCurrSpriteY = m_nCurrSpriteTotal / m_SpriteInfo.nSpriteCntX;
		}
		m_nCurrSpriteX = m_nCurrSpriteTotal % m_SpriteInfo.nSpriteCntX;
	}
	m_mTexTrans._31 = (float)(m_nCurrSpriteX*m_fSpriteU);
	m_mTexTrans._32 = (float)(m_nCurrSpriteY*m_fSpriteV);
	
	baseObject::Update(dTime);
	return;
}

void SpriteEffect::Render(void)
{
	//baseObject::Render();
	//D3DXMATRIX m;
	//D3DXMatrixIdentity(&m);

	DEVICE->SetTransform(D3DTS_WORLD, &m_Transform->GetmTM());
	//DEVICE->SetTransform(D3DTS_WORLD, &m);
	DEVICE->SetTransform(D3DTS_TEXTURE0, &m_mTexTrans);
	DEVICE->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2);
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

void SpriteEffect::Release(void)
{
	SAFE_RELEASE(m_pVB);
}

SpriteEffect::SpriteEffect()
{
	m_pVB = nullptr;
	m_nTotalSpriteCnt = 0;
	m_nCurrSpriteX = 0;
	m_nCurrSpriteY = 0;
	m_nCurrSpriteTotal = 0;
	m_fSpriteU = 0;
	m_fSpriteV = 0;
	m_fCurrTime = 0;
	D3DXMatrixIdentity(&m_mTexTrans);
}


SpriteEffect::~SpriteEffect()
{
	Release();
}
