#include"GameCommon.h"



void Terrain::Init()
{	

	m_fSize = 100;
	m_fCount = 50;
	OBJECTINFO _info;
	ZeroInfo(&_info);
	_info.strName.resize(255);
	_info.FileName.resize(255);

	for (int i = 0; i <2500; i++) {
		m_ground[i * 6].vPos = {
			-(m_fSize / 2.0f) + (i % m_fCount)*m_fSize / (float)m_fCount,
			-0.1f,
			-(m_fSize / 2.0f) + ((i / m_fCount) + 1)*m_fSize / (float)m_fCount };
		m_ground[i * 6 + 4].vPos = m_ground[i * 6 + 1].vPos = {
			-(m_fSize / 2.0f) + ((i % m_fCount) + 1)*m_fSize / (float)m_fCount,
			-0.1f,
			-(m_fSize / 2.0f) + ((i / m_fCount) + 1)*m_fSize / (float)m_fCount };
		m_ground[i * 6 + 3].vPos = m_ground[i * 6 + 2].vPos = {
			-(m_fSize / 2.0f) + (i % m_fCount)*m_fSize / (float)m_fCount ,
			-0.1f,
			-(m_fSize / 2.0f) + (i / m_fCount)*m_fSize / (float)m_fCount };
		m_ground[i * 6 + 5].vPos = {
			-(m_fSize / 2.0f) + (i % m_fCount + 1)*m_fSize / (float)m_fCount,
			-0.1f,
			-(m_fSize / 2.0f) + (i / m_fCount)*m_fSize / (float)m_fCount };

		//m_ground[i * 6].u = 0;
		//m_ground[i * 6 + 4].u = m_ground[i * 6 + 1].u = 1;
		//m_ground[i * 6 + 3].u = m_ground[i * 6 + 2].u = 0;
		//m_ground[i * 6 + 5].u = 1;

		//m_ground[i * 6].v = 1;
		//m_ground[i * 6 + 4].v = m_ground[i * 6 + 1].v = 1;
		//m_ground[i * 6 + 3].v = m_ground[i * 6 + 2].v = 0;
		//m_ground[i * 6 + 5].v = 0;


		//m_ground[i * 6].u2 = 0;
		//m_ground[i * 6 + 4].u2 = m_ground[i * 6 + 1].u2 = 1;
		//m_ground[i * 6 + 3].u2 = m_ground[i * 6 + 2].u2 = 0;
		//m_ground[i * 6 + 5].u2 = 1;

		//m_ground[i * 6].v2 = 1;
		//m_ground[i * 6 + 4].v2 = m_ground[i * 6 + 1].v2 = 1;
		//m_ground[i * 6 + 3].v2 = m_ground[i * 6 + 2].v2 = 0;
		//m_ground[i * 6 + 5].v2 = 0;

		m_ground[i * 6].u = ((i % m_fCount) / (float)m_fCount);
		m_ground[i * 6 + 4].u = m_ground[i * 6 + 1].u = ((i % m_fCount + 1) / (float)m_fCount);
		m_ground[i * 6 + 3].u = m_ground[i * 6 + 2].u = ((i % m_fCount) / (float)m_fCount);
		m_ground[i * 6 + 5].u = ((i % m_fCount + 1) / (float)m_fCount);

		m_ground[i * 6].v = (m_fCount - (i / m_fCount + 1)) / (float)m_fCount;
		m_ground[i * 6 + 4].v = m_ground[i * 6 + 1].v = (m_fCount - (i / m_fCount + 1)) / (float)m_fCount;
		m_ground[i * 6 + 3].v = m_ground[i * 6 + 2].v = (m_fCount - (i / m_fCount)) / (float)m_fCount;
		m_ground[i * 6 + 5].v = (m_fCount - (i / m_fCount)) / (float)m_fCount;

	}
	for (int i = 0; i < 15000; i++) {
		m_ground[i].vNormal = D3DXVECTOR3(0, 1, 0);
	}
	_info.Pollygon = PG_TRIANGLES;
	_info.pData = m_ground;
	_info.nTriangleCnt = m_fCount * m_fCount*2;
	
	_info.dwFVF = D3DFVF_XYZ_NORMAL_UV::FVF;
	_info.nSize = m_fCount * m_fCount * 6 * sizeof(D3DFVF_XYZ_NORMAL_UV);
	_info.vPos = VEC3ZERO;
	_info.vScale = VEC3ONE;
	_info.vRot = VEC3ZERO;

	_info.strName = "Terrain";
	_info.FileName = "";
	
	baseObject::Init(_info);
	D3DXMatrixIdentity(&(m_Transform->GetmTM()));
}

void Terrain::Render()
{
	D3DMATERIAL9 m_material;
	ZeroMemory(&m_material, sizeof(m_material));
	//m_material.Ambient=m_material.Diffuse = D3DXCOLOR(0.6f, 0.3f, 0, 1);
	m_material.Ambient = m_material.Diffuse = D3DXCOLOR(1, 1, 1, 1);

	DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드

	DEVICE->SetMaterial(&m_material);

	DEVICE->SetFVF(D3DFVF_XYZ_NORMAL_UV::FVF);


	DEVICE->SetTexture(0, GAMEMGR->m_pMaskTexture);

	DEVICE->SetTexture(1, GAMEMGR->m_pGrassTexture);
	DEVICE->SetTexture(2, GAMEMGR->m_pMaskTexture);
	DEVICE->SetTexture(3, GAMEMGR->m_pBottomTexture);
	//DEVICE->SetTexture(6, m_pRiverTexture);
	//DEVICE->SetTexture(8, m_pWaterTexture);
	//DEVICE->SetTexture(5, m_pWaterTexture);


	DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);

	DEVICE->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(1, D3DTSS_COLORARG2, D3DTA_CURRENT);
	DEVICE->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 0);
	DEVICE->SetTextureStageState(1, D3DTSS_RESULTARG, D3DTA_TEMP);


	DEVICE->SetTextureStageState(2, D3DTSS_COLOROP, D3DTOP_SUBTRACT);
	DEVICE->SetTextureStageState(2, D3DTSS_CONSTANT, D3DXCOLOR(1, 1, 1, 1));
	DEVICE->SetTextureStageState(2, D3DTSS_COLORARG1, D3DTA_CONSTANT);
	DEVICE->SetTextureStageState(2, D3DTSS_COLORARG2, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(2, D3DTSS_TEXCOORDINDEX, 0);

	DEVICE->SetTextureStageState(3, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(3, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(3, D3DTSS_COLORARG2, D3DTA_CURRENT);
	DEVICE->SetTextureStageState(3, D3DTSS_TEXCOORDINDEX, 0);

	DEVICE->SetTextureStageState(4, D3DTSS_COLOROP, D3DTOP_ADD);
	DEVICE->SetTextureStageState(4, D3DTSS_COLORARG1, D3DTA_CURRENT);
	DEVICE->SetTextureStageState(4, D3DTSS_COLORARG2, D3DTA_TEMP);
	DEVICE->SetTextureStageState(4, D3DTSS_TEXCOORDINDEX, 0);

	DEVICE->SetTextureStageState(5, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(5, D3DTSS_COLORARG1, D3DTA_CURRENT);
	DEVICE->SetTextureStageState(5, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DEVICE->SetTextureStageState(5, D3DTSS_TEXCOORDINDEX, 0);
	//DEVICE->SetTextureStageState(5, D3DTSS_RESULTARG, D3DTA_TEMP);
	//m_Winter = 1;
	if (GAMEMGR->m_Winter>0) {

		//DEVICE->SetTexture(0, m_pSnowTexture);
		//DEVICE->SetTexture(6, m_pMaskTexture);

		//DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_INVSRCCOLOR); // mask의 흰색이 그릴 부분일 경우
		//DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);

		DEVICE->SetTextureStageState(6, D3DTSS_COLOROP, D3DTOP_ADD);
		DEVICE->SetTextureStageState(6, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		DEVICE->SetTextureStageState(6, D3DTSS_COLORARG2, D3DTA_CURRENT);
		DEVICE->SetTextureStageState(6, D3DTSS_TEXCOORDINDEX, 0);
		DEVICE->SetTexture(6, GAMEMGR->m_pSnowTexture[GAMEMGR->m_Winter - 1]);
	}
	else {
		DEVICE->SetTextureStageState(6, D3DTSS_COLOROP, D3DTOP_DISABLE);
		//DEVICE->SetTextureStageState(7, D3DTSS_COLOROP, D3DTOP_DISABLE);
	}
	//////////////



	//for (int i = 0; i < m_fCount00; i++) {
	//	//DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLEFAN, 2, m_ground+i*4, sizeof(D3DFVF_XYZ_NORMAL_UV));
		//DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 1, m_ground + i * 3, sizeof(D3DFVF_XYZ_NORMAL_UV));
	//}
	baseObject::Render();
	for (int i = 0; i < 8; i++) {
		DEVICE->SetTexture(i, nullptr);
		DEVICE->SetTextureStageState(i, D3DTSS_COLOROP, D3DTOP_DISABLE);
	}
	//DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);

	DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

}

Terrain::Terrain()
{
	m_fCount = 1;
}


Terrain::~Terrain()
{
}
