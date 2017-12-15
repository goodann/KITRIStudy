#include"GameCommon.h"


//void Bullet::Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale)
//{
//	OBJECTINFO info;
//	m_radius = 1 * D3DXVec3Length(&_scale);
//	m_speed = 40.0f;
//	m_vPos = _pos;
//	m_vRot = _rot;
//	m_vScale = _scale;
//	m_voldDir = m_vDir = D3DXVECTOR3(0, 0, 1);
//
//	info.fRadius = 5 * D3DXVec3Length(&_scale);
//	info.vPos = _pos;
//	info.vRot = _rot;
//	info.vScale = _scale;
//	info.vDir = D3DXVECTOR3(0, 0, 1);
//	info.Pollygon = PG_BOX;
//	info.Pollygon = PG_CYLINDER;
//	baseObject::Init(info);
//	m_fRadius = 1 * D3DXVec3Length(&_scale);
//
//	m_arrVertex[0].vPos = D3DXVECTOR3(-1, 0, 0);
//	m_arrVertex[1].vPos = D3DXVECTOR3(-1, 2, 0);
//	m_arrVertex[2].vPos = D3DXVECTOR3(1, 2, 0);
//
//	m_arrVertex[3].vPos = D3DXVECTOR3(-1, 0, 0);
//	m_arrVertex[4].vPos = D3DXVECTOR3(1, 2, 0);
//	m_arrVertex[5].vPos = D3DXVECTOR3(1, 0, 0);
//
//	m_arrVertex[0].color = D3DXCOLOR(0, 0, 0, 0);
//	m_arrVertex[1].color = D3DXCOLOR(0, 0, 0, 0);
//	m_arrVertex[2].color = D3DXCOLOR(0, 0, 0, 0);
//	m_arrVertex[3].color = D3DXCOLOR(0, 0, 0, 0);
//	m_arrVertex[4].color = D3DXCOLOR(0, 0, 0, 0);
//	m_arrVertex[5].color = D3DXCOLOR(0, 0, 0, 0);
//	//
//	// 앞면
//	m_arrVertex[0].vPos = D3DXVECTOR3(-1, -1, -2);
//	m_arrVertex[1].vPos = D3DXVECTOR3(-1, 1, -2);
//	m_arrVertex[2].vPos = D3DXVECTOR3(1, 1, -2);
//	m_arrVertex[3].vPos = D3DXVECTOR3(-1, -1, -2);
//	m_arrVertex[4].vPos = D3DXVECTOR3(1, 1, -2);
//	m_arrVertex[5].vPos = D3DXVECTOR3(1, -1, -2);
//
//	// 뒷면
//	m_arrVertex[7].vPos = D3DXVECTOR3(-1, -1, 2);
//	m_arrVertex[6].vPos = D3DXVECTOR3(-1, 1, 2);
//	m_arrVertex[8].vPos = D3DXVECTOR3(1, 1, 2);
//	m_arrVertex[10].vPos = D3DXVECTOR3(-1, -1, 2);
//	m_arrVertex[9].vPos = D3DXVECTOR3(1, 1, 2);
//	m_arrVertex[11].vPos = D3DXVECTOR3(1, -1, 2);
//
//	// 오른쪽
//	m_arrVertex[12].vPos = D3DXVECTOR3(1, -1, -2);
//	m_arrVertex[13].vPos = D3DXVECTOR3(1, 1, -2);
//	m_arrVertex[14].vPos = D3DXVECTOR3(1, 1, 2);
//	m_arrVertex[15].vPos = D3DXVECTOR3(1, -1, -2);
//	m_arrVertex[16].vPos = D3DXVECTOR3(1, 1, 2);
//	m_arrVertex[17].vPos = D3DXVECTOR3(1, -1, 2);
//
//	// 왼쪽
//	m_arrVertex[19].vPos = D3DXVECTOR3(-1, -1, -2);
//	m_arrVertex[18].vPos = D3DXVECTOR3(-1, 1, -2);
//	m_arrVertex[20].vPos = D3DXVECTOR3(-1, 1, 2);
//	m_arrVertex[22].vPos = D3DXVECTOR3(-1, -1, -2);
//	m_arrVertex[21].vPos = D3DXVECTOR3(-1, 1, 2);
//	m_arrVertex[23].vPos = D3DXVECTOR3(-1, -1, 2);
//
//	// 윗면
//	m_arrVertex[24].vPos = D3DXVECTOR3(-1, 1, -2);
//	m_arrVertex[25].vPos = D3DXVECTOR3(-1, 1, 2);
//	m_arrVertex[26].vPos = D3DXVECTOR3(1, 1, 2);
//	m_arrVertex[27].vPos = D3DXVECTOR3(-1, 1, -2);
//	m_arrVertex[28].vPos = D3DXVECTOR3(1, 1, 2);
//	m_arrVertex[29].vPos = D3DXVECTOR3(1, 1, -2);
//
//	// 아래면
//	m_arrVertex[31].vPos = D3DXVECTOR3(-1, -1, -2);
//	m_arrVertex[30].vPos = D3DXVECTOR3(-1, -1, 2);
//	m_arrVertex[32].vPos = D3DXVECTOR3(1, -1, 2);
//	m_arrVertex[34].vPos = D3DXVECTOR3(-1, -1, -2);
//	m_arrVertex[33].vPos = D3DXVECTOR3(1, -1, 2);
//	m_arrVertex[35].vPos = D3DXVECTOR3(1, -1, -2);
//
//	for (int i = 0; i < 36; ++i)
//		m_arrVertex[i].color = D3DXCOLOR(0.2f, 0.4f, 0.9f, 2);
//
//
//	D3DXMatrixIdentity(&m_mTrans);
//
//	D3DXMatrixTranslation(&m_mTrans, 0, 0, 0);
//	//m_mTrans._43 = 15;
//	//m_vPos = D3DXVECTOR3(0, 0, 15);
//
//	//
//
//
//}

void Bullet::Init(OBJECTINFO _info)
{
	m_Speed = 40.0f;
	_info.Pollygon = PG_BOX;
	_info.Pollygon = PG_CYLINDER;
	_info.fRadius = D3DXVec3Length(&_info.vScale);
	
	m_Gravity = VEC3ZERO;
	//_info.vRot;
	//D3DXVECTOR3 a= D3DXVECTOR3(0,0,1);
	//D3DXVec3TransformNormal(&a, &a, &m_Transform->GetmTM());
	//D3DXVec3
	//&_info.vRot
	//D3DXVec3Cross(&a, &a, &_info.vDir);
	//m_Transform->Rotate(a);
	baseObject::Init(_info);

}

void Bullet::Update(float dtime)
{
	//D3DXVECTOR4 aa;
	if (m_Transform->GetvPos().y <= 0 && m_isTankBullet) {
		for (auto& a : GAMEMGR->m_Tree) {
			D3DXVECTOR3 v =(a->GetTransform()->GetvPos() - m_Transform->GetvPos());
			float sq = D3DXVec3LengthSq(&v);
			if (sq < 100) {
				a->SomerSault();
			}
		}
		m_bLife = false;
	}
	D3DXVECTOR3 pos = m_Transform->GetvPos();
	D3DXVECTOR3 voidDir = m_Transform->GetOrgvDir();
	D3DXVECTOR3 dir = m_Transform->GetvDir();

	pos += dir*m_Speed*dtime+m_Gravity*dtime;
	
	m_Gravity += GRAVITY*dtime;
	m_Transform->SetvPos(pos);
	if (D3DXVec3Length(&pos) > 40)
		m_bLife = false;

	baseObject::Update(dtime);
}

void Bullet::Render(void)
{
	DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드

	//DEVICE->SetFVF(D3DFVF_XYZ_COLOR::FVF);
	//DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);
	baseObject::Render();
	//DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2,m_arrVertex, sizeof(D3DFVF_XYZ_COLOR));

	//DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 12, m_arrVertex, sizeof(D3DFVF_XYZ_COLOR));

	//DEVICE->DrawPrimitiveUP(D3DPT_LINELIST, 1, m_dirLine, sizeof(D3DFVF_XYZ_COLOR));

	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드
}

void Bullet::Release(void)
{
}

Bullet::Bullet()
{
	m_bLife = true;
	m_Gravity = D3DXVECTOR3(0, -9.8f, 0);
	m_isTankBullet = false;
}


Bullet::~Bullet()
{
	GAMEMGR->m_pTriPlayer->m_bullet.remove(this);
}
