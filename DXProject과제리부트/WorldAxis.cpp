#include "GameCommon.h"

void WorldAxis::Setup(void)
{
	//Y
	m_arrVertexsY[0].vPos = D3DXVECTOR3(0, 0, 0);
	m_arrVertexsY[1].vPos = D3DXVECTOR3(-m_fWidth, m_fHeight, -m_fWidth);
	m_arrVertexsY[2].vPos = D3DXVECTOR3(m_fWidth, m_fHeight, -m_fWidth);

	m_arrVertexsY[3].vPos = D3DXVECTOR3(0, 0, 0);
	m_arrVertexsY[4].vPos = D3DXVECTOR3(m_fWidth, m_fHeight, -m_fWidth);
	m_arrVertexsY[5].vPos = D3DXVECTOR3(m_fWidth, m_fHeight, m_fWidth);
	 
	m_arrVertexsY[6].vPos = D3DXVECTOR3(0, 0, 0);
	m_arrVertexsY[7].vPos = D3DXVECTOR3(m_fWidth, m_fHeight, m_fWidth);
	m_arrVertexsY[8].vPos = D3DXVECTOR3(-m_fWidth, m_fHeight, m_fWidth);

	m_arrVertexsY[9].vPos = D3DXVECTOR3(0, 0, 0);
	m_arrVertexsY[10].vPos = D3DXVECTOR3(-m_fWidth, m_fHeight, m_fWidth);
	m_arrVertexsY[11].vPos = D3DXVECTOR3(-m_fWidth, m_fHeight, -m_fWidth);

	m_arrVertexsY[12].vPos = D3DXVECTOR3(-m_fWidth, m_fHeight, m_fWidth);
	m_arrVertexsY[13].vPos = D3DXVECTOR3(m_fWidth, m_fHeight, m_fWidth);
	m_arrVertexsY[14].vPos = D3DXVECTOR3(-m_fWidth, m_fHeight, -m_fWidth);

	m_arrVertexsY[15].vPos = D3DXVECTOR3(-m_fWidth, m_fHeight, -m_fWidth);
	m_arrVertexsY[16].vPos = D3DXVECTOR3(m_fWidth, m_fHeight, m_fWidth);
	m_arrVertexsY[17].vPos = D3DXVECTOR3(m_fWidth, m_fHeight, -m_fWidth);

	for (int i = 0; i < 18; ++i)
		m_arrVertexsY[i].color = D3DXCOLOR(0, 1, 0, 2);

	// x
	D3DXMATRIX _mRot;
	D3DXMatrixRotationZ(&_mRot, -D3DXToRadian(90));

	for (int i = 0; i < 18; ++i)
	{
		D3DXVec3TransformCoord(&m_arrVertexsX[i].vPos, &m_arrVertexsY[i].vPos, &_mRot);
		m_arrVertexsX[i].color = D3DXCOLOR(1, 0, 0, 2);
	}

	// Z
	D3DXMatrixRotationX(&_mRot, D3DXToRadian(90));

	for (int i = 0; i < 18; ++i)
	{
		D3DXVec3TransformCoord(&m_arrVertexsZ[i].vPos, &m_arrVertexsY[i].vPos, &_mRot);
		m_arrVertexsZ[i].color = D3DXCOLOR(0, 0, 1, 2);
	}
}

void WorldAxis::Update(float dTime)
{
}

void WorldAxis::Render(void)
{
	D3DXMATRIX mTM;
	D3DXMatrixIdentity(&mTM);
	DEVICE->SetTransform(D3DTS_WORLD, &mTM);
	
	DEVICE->SetRenderState(D3DRS_LIGHTING, false);
	DEVICE->SetFVF(D3DFVF_XYZ_COLOR::FVF);					// 포맷형식

	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST,				// 그리는 형식( 3개 정점을 이어 그리기 )
		6,													// 삼각형 갯수
		&m_arrVertexsX,										// 정점 시작 주소
		sizeof(D3DFVF_XYZ_COLOR));							// 정점 사이즈

	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST,				// 그리는 형식( 3개 정점을 이어 그리기 )
		6,													// 삼각형 갯수
		&m_arrVertexsY,										// 정점 시작 주소
		sizeof(D3DFVF_XYZ_COLOR));							// 정점 사이즈

	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST,				// 그리는 형식( 3개 정점을 이어 그리기 )
		6,													// 삼각형 갯수
		&m_arrVertexsZ,										// 정점 시작 주소
		sizeof(D3DFVF_XYZ_COLOR));							// 정점 사이즈
}

void WorldAxis::Destroy(void)
{
}

WorldAxis::WorldAxis()
	: m_fWidth(0.2f)
	, m_fHeight(2.0f)
{
}


WorldAxis::~WorldAxis()
{
}
