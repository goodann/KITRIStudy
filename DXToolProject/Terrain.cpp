#include"GameCommon.h"



void Terrain::Init()
{	

	OBJECTINFO _info;
	ZeroInfo(&_info);
	_info.strName.resize(255);
	_info.FileName.resize(255);
	for (int i = 0; i <2500; i++) {
		m_ground[i * 6].vPos = {
			-25.0f + (i % 50) ,
			-0.1f,
			-25.0f + (i / 50) + 1 };
		m_ground[i * 6 + 4].vPos = m_ground[i * 6 + 1].vPos = {
			-25.0f + (i % 50) + 1,
			-0.1f,
			-25.0f + (i / 50) + 1 };
		m_ground[i * 6 + 3].vPos = m_ground[i * 6 + 2].vPos = {
			-25.0f + (i % 50) ,
			-0.1f,
			-25.0f + (i / 50) };
		m_ground[i * 6 + 5].vPos = {
			-25.0f + i % 50 + 1,
			-0.1f,
			-25.0f + (i / 50) };
		m_ground[i * 6].u = ((i % 50) / 50.0f);
		m_ground[i * 6 + 4].u = m_ground[i * 6 + 1].u = ((i % 50 + 1) / 50.0f);
		m_ground[i * 6 + 3].u = m_ground[i * 6 + 2].u = ((i % 50) / 50.0f);
		m_ground[i * 6 + 5].u = ((i % 50 + 1) / 50.0f);

		m_ground[i * 6].v = (50 - (i / 50 + 1)) / 50.0f;
		m_ground[i * 6 + 4].v = m_ground[i * 6 + 1].v = (50 - (i / 50 + 1)) / 50.0f;
		m_ground[i * 6 + 3].v = m_ground[i * 6 + 2].v = (50 - (i / 50)) / 50.0f;
		m_ground[i * 6 + 5].v = (50 - (i / 50)) / 50.0f;
	}
	for (int i = 0; i < 15000; i++) {
		m_ground[i].vNormal = D3DXVECTOR3(0, 1, 0);
	}
	_info.Pollygon = PG_TRIANGLES;
	_info.pData = m_ground;
	_info.nTriangleCnt = 5000;
	
	_info.dwFVF = D3DFVF_XYZ_NORMAL_UV::FVF;
	_info.nSize = 15000 * sizeof(D3DFVF_XYZ_NORMAL_UV);
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

	DEVICE->SetRenderState(D3DRS_LIGHTING, true); // ������
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // �ø����

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

		//DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_INVSRCCOLOR); // mask�� ����� �׸� �κ��� ���
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



	//for (int i = 0; i < 5000; i++) {
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
}


Terrain::~Terrain()
{
}
