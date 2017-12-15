#include"GameCommon.h"



void Star::Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale)
{
	float r = (float)(rand()%255);
	float g = (float)(rand() % 255);
	float b= (float)(rand() % 255);
	m_angle = 0;
	r /= 255;
	g /= 255;
	b /= 255;

	m_vPos = _pos;
	m_vRot = _rot;
	m_vScale = _scale;
	m_voldDir = m_vDir = D3DXVECTOR3(0, 0, 1);

	m_arrVertex[0].vPos = D3DXVECTOR3(0, 3, 0);
	m_arrVertex[1].vPos = D3DXVECTOR3(0, -2, 0);
	m_arrVertex[2].vPos = D3DXVECTOR3(-2, -3, 0);

	m_arrVertex[3].vPos = D3DXVECTOR3(0, 3, 0);
	m_arrVertex[4].vPos = D3DXVECTOR3(2, -3, 0);
	m_arrVertex[5].vPos = D3DXVECTOR3(0, -2, 0);

	m_arrVertex[6].vPos = D3DXVECTOR3(-3, 1, 0);
	m_arrVertex[7].vPos = D3DXVECTOR3(3, 1, 0);
	m_arrVertex[8].vPos = D3DXVECTOR3(0, -1, 0);

	m_arrVertex[0].color = D3DXCOLOR(r, g, b, 0);
	m_arrVertex[1].color = D3DXCOLOR(r, g, b, 0);
	m_arrVertex[2].color = D3DXCOLOR(r, g, b, 0);
	m_arrVertex[3].color = D3DXCOLOR(r, g, b, 0);
	m_arrVertex[4].color = D3DXCOLOR(r, g, b, 0);
	m_arrVertex[5].color = D3DXCOLOR(r, g, b, 0);
	m_arrVertex[6].color = D3DXCOLOR(r, g, b, 0);
	m_arrVertex[7].color = D3DXCOLOR(r, g, b, 0);
	m_arrVertex[8].color = D3DXCOLOR(r, g, b, 0);

}

void Star::Update(float dtime)
{
	m_vPos.y -= 50*dtime;
	if (m_vPos.y < 0)
		m_vPos.y += 50;
	m_vRot.y+= D3DX_PI / 180.0f *0.1;
	//m_angle += D3DX_PI / 180.0f*10;
	//m_mRot
	//D3DXMatrixRotationX(&m_mRot, m_angle);
	//D3DXMatrixRotationY(&m_mRot, m_angle);
	//D3DXMatrixRotationZ(&m_mRot, m_angle);

	D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
	D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);

	D3DXVec3TransformNormal(&m_vDir, &m_voldDir, &m_mRot);
	D3DXVec3Normalize(&m_vDir, &m_vDir);

	m_mTM = m_mScale * m_mRot * m_mTrans;
}

void Star::Render(void)
{
	DEVICE->SetRenderState(D3DRS_LIGHTING, false); // 라이팅
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드

	DEVICE->SetFVF(D3DFVF_XYZ_COLOR::FVF);
	DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);

	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 3,
		m_arrVertex, sizeof(D3DFVF_XYZ_COLOR));

	//DEVICE->DrawPrimitiveUP(D3DPT_LINELIST, 1, m_dirLine, sizeof(D3DFVF_XYZ_COLOR));

	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드
}

void Star::Release(void)
{

}

Star::Star()
{

}


Star::~Star()
{
}
