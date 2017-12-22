#include"GameCommon.h"



void River::Init()
{
	
	for (int i = 0; i < 8; ++i)
	{
		DEVICE->SetSamplerState(i, D3DSAMP_MIPFILTER,
			D3DTEXF_LINEAR);

		DEVICE->SetSamplerState(i, D3DSAMP_MINFILTER,
			D3DTEXF_ANISOTROPIC);
		DEVICE->SetSamplerState(i, D3DSAMP_MAGFILTER,
			D3DTEXF_ANISOTROPIC);
		DEVICE->SetSamplerState(i, D3DSAMP_MAXANISOTROPY,
			16);

	}

	m_arrVertex[0].vPos = D3DXVECTOR3(-10, 0, 10);
	m_arrVertex[0].u = 0;  m_arrVertex[0].v = 0;
	m_arrVertex[1].vPos = D3DXVECTOR3(10, 0, 10);
	m_arrVertex[1].u = 1;  m_arrVertex[1].v = 0;
	m_arrVertex[2].vPos = D3DXVECTOR3(-10, 0, -10);
	m_arrVertex[2].u = 0;  m_arrVertex[2].v = 1;
	m_arrVertex[3].vPos = D3DXVECTOR3(10, 0, -10);
	m_arrVertex[3].u = 1;  m_arrVertex[3].v = 1;

	m_pTexture = TEXMGR->GetTexture("water2.bmp");
	m_pTextureBump = TEXMGR->GetTexture("waterbump1.bmp");
	OBJECTINFO info;
	ZeroInfo(&info);
	info.vScale = D3DXVECTOR3(10, 1, 0.5f);
	baseObject::Init(info);
}

void River::Update(float dTime)
{
	m_fAngle += D3DX_PI * 0.05f *dTime;
	D3DXMatrixRotationY(&m_mRot, m_fAngle);

	m_fTexX += 0.1f * dTime;
	//m_mTexTrans._31 = m_mTexTrans._32 = m_fTexX;
	m_mTexTrans._31 = m_fTexX;
	baseObject::Update(dTime);
}

void River::Render(void)
{
	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);

	DEVICE->SetRenderState(D3DRS_LIGHTING, false);
	//DEVICE->SetTransform(D3DTS_WORLD, &m);
	DEVICE->SetTransform(D3DTS_WORLD, &m_Transform->GetmTM());
	DEVICE->SetFVF(D3DFVF_XYZ_TEX1::FVF);

	{
		DEVICE->SetRenderState(D3DRS_ZWRITEENABLE, false);
		DEVICE->SetRenderState(D3DRS_STENCILENABLE, true);
		DEVICE->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
		DEVICE->SetRenderState(D3DRS_STENCILREF, 1);

		DEVICE->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);

	}


	// 범프맵
	DEVICE->SetTexture(0, m_pTextureBump->GetTexture());
	DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_BUMPENVMAP);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);


	DEVICE->SetTextureStageState(0, D3DTSS_BUMPENVMAT00,
		*((DWORD*)&(m_mRot._11)));
	DEVICE->SetTextureStageState(0, D3DTSS_BUMPENVMAT01,
		*((DWORD*)&(m_mRot._13)));
	DEVICE->SetTextureStageState(0, D3DTSS_BUMPENVMAT10,
		*((DWORD*)&(m_mRot._31)));
	DEVICE->SetTextureStageState(0, D3DTSS_BUMPENVMAT11,
		*((DWORD*)&(m_mRot._33)));

	DEVICE->SetTransform(D3DTS_TEXTURE0, &m_mTexTrans);
	DEVICE->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS
		, D3DTTFF_COUNT2);

	// 일반 맵 이미지
	DEVICE->SetTexture(1, m_pTexture->GetTexture());
	DEVICE->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	DEVICE->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 0);


	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2,
		m_arrVertex, sizeof(D3DFVF_XYZ_TEX1));

	DEVICE->SetTexture(0, NULL);
	DEVICE->SetTexture(1, NULL);
	for(int i=0;i<8;i++)
		DEVICE->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);

	DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DEVICE->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);

	DEVICE->SetTexture(0, nullptr);
	DEVICE->SetTransform(D3DTS_TEXTURE0, &m);


	DEVICE->SetRenderState(D3DRS_STENCILENABLE, false);
	DEVICE->SetRenderState(D3DRS_ZWRITEENABLE, true);
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드

}

River::River()
{
	m_fAngle = 0;
	m_fTexX = 0;
	D3DXMatrixIdentity(&m_mTexTrans);
}


River::~River()
{
}

