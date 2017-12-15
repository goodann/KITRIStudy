#include "GameCommon.h"

WorldGrid::WorldGrid(void)
	: m_pFVFVertexs(NULL)
	, m_iLineCount(0)
	, m_iTileXCount(0)
	, m_iTileInterval(0)
{
}

WorldGrid::~WorldGrid(void)
{
	Destroy();
}

void WorldGrid::Setup( void )
{
	m_iTileXCount = 10;
	m_iTileInterval = 5;
	
	int iCountX   = (m_iTileXCount*m_iTileInterval) + 1;
	int iCountY   = (m_iTileXCount*m_iTileInterval) + 1;
	int iVtxCount = (iCountX + iCountY) * 2;

	m_pFVFVertexs = new D3DFVF_XYZ_COLOR[iVtxCount];
	ZeroMemory(m_pFVFVertexs, sizeof(D3DFVF_XYZ_COLOR)*iVtxCount);

	// 그리드 시작위치 
	float fStartX = -((iCountX-1) / 2.0f);
	float fStartZ =  ((iCountY-1) / 2.0f);

	// x축
	int   idx = 0;

	for( int i = 0; i < iCountX; i++ )
	{
		float _fZ 						= fStartZ - i;
		
		// 정점
		m_pFVFVertexs[idx].vPos			= D3DXVECTOR3(fStartX, 0.001f, _fZ);
		m_pFVFVertexs[idx +1].vPos		= D3DXVECTOR3(-fStartX, 0.001f, _fZ);

		// 색상
		m_pFVFVertexs[idx].color = (i % m_iTileInterval == 0) ?	D3DXCOLOR(0, 0, 0, 1) : D3DXCOLOR(0.3f, 0.3f, 0.3f, 2);
		m_pFVFVertexs[idx + 1].color = (i % m_iTileInterval == 0) ? D3DXCOLOR(0, 0, 0, 1) : D3DXCOLOR(0.3f, 0.3f, 0.3f, 2);

		idx += 2;
	}

	// z축
	for(int i=0; i < iCountY; i++)
	{
		float _fX = fStartX + i;

		// 정점
		m_pFVFVertexs[idx].vPos			= D3DXVECTOR3(_fX, 0.001f, fStartZ);
		m_pFVFVertexs[idx +1].vPos		= D3DXVECTOR3(_fX, 0.001f, -fStartZ);

		// 색상
		m_pFVFVertexs[idx].color		= (i % m_iTileInterval == 0) ? D3DXCOLOR(0, 0, 0, 1) : D3DXCOLOR(0.3f, 0.3f, 0.3f, 2);
		m_pFVFVertexs[idx +1].color	= (i % m_iTileInterval == 0) ? D3DXCOLOR(0, 0, 0, 1)  : D3DXCOLOR(0.3f, 0.3f, 0.3f, 2);

		idx += 2;
	}

	m_iLineCount = iVtxCount / 2;
}

void WorldGrid::Render( void )
{
	D3DXMATRIX mTM;
	D3DXMatrixIdentity(&mTM);
	DEVICE->SetTransform(D3DTS_WORLD, &mTM);
	DEVICE->SetRenderState(D3DRS_LIGHTING, false);
	DEVICE->SetFVF(D3DFVF_XYZ_COLOR::FVF);
	DEVICE->DrawPrimitiveUP(D3DPT_LINELIST, m_iLineCount, m_pFVFVertexs, sizeof(D3DFVF_XYZ_COLOR));
}

void WorldGrid::Destroy( void )
{
	SAFE_DELETE_ARRAY(m_pFVFVertexs);
}