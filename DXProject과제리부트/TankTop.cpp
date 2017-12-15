#include"GameCommon.h"


void TankTop::Init(Tank* Parent) {
	m_fRadius = 1;
	//// ¾Õ¸é
	//m_arrVertex[0].vPos = D3DXVECTOR3(-0.5, -0.5, -0.5);
	//m_arrVertex[1].vPos = D3DXVECTOR3(-0.5, 0.5, -0.5);
	//m_arrVertex[2].vPos = D3DXVECTOR3(0.5, 0.5, -0.5);
	//m_arrVertex[3].vPos = D3DXVECTOR3(-0.5, -0.5, -0.5);
	//m_arrVertex[4].vPos = D3DXVECTOR3(0.5, 0.5, -0.5);
	//m_arrVertex[5].vPos = D3DXVECTOR3(0.5, -0.5, -0.5);

	//// µÞ¸é
	//m_arrVertex[7].vPos = D3DXVECTOR3(-0.5, -0.5, 0.5);
	//m_arrVertex[6].vPos = D3DXVECTOR3(-0.5, 0.5, 0.5);
	//m_arrVertex[8].vPos = D3DXVECTOR3(0.5, 0.5, 0.5);
	//m_arrVertex[10].vPos = D3DXVECTOR3(-0.5, -0.5, 0.5);
	//m_arrVertex[9].vPos = D3DXVECTOR3(0.5, 0.5, 0.5);
	//m_arrVertex[11].vPos = D3DXVECTOR3(0.5, -0.5, 0.5);

	//// ¿À¸¥ÂÊ
	//m_arrVertex[12].vPos = D3DXVECTOR3(0.5, -0.5, -0.5);
	//m_arrVertex[13].vPos = D3DXVECTOR3(0.5, 0.5, -0.5);
	//m_arrVertex[14].vPos = D3DXVECTOR3(0.5, 0.5, 0.5);
	//m_arrVertex[15].vPos = D3DXVECTOR3(0.5, -0.5, -0.5);
	//m_arrVertex[16].vPos = D3DXVECTOR3(0.5, 0.5, 0.5);
	//m_arrVertex[17].vPos = D3DXVECTOR3(0.5, -0.5, 0.5);

	//// ¿ÞÂÊ
	//m_arrVertex[19].vPos = D3DXVECTOR3(-0.5, -0.5, -0.5);
	//m_arrVertex[18].vPos = D3DXVECTOR3(-0.5, 0.5, -0.5);
	//m_arrVertex[20].vPos = D3DXVECTOR3(-0.5, 0.5, 0.5);
	//m_arrVertex[22].vPos = D3DXVECTOR3(-0.5, -0.5, -0.5);
	//m_arrVertex[21].vPos = D3DXVECTOR3(-0.5, 0.5, 0.5);
	//m_arrVertex[23].vPos = D3DXVECTOR3(-0.5, -0.5, 0.5);

	//// À­¸é
	//m_arrVertex[24].vPos = D3DXVECTOR3(-0.5, 0.5, -0.5);
	//m_arrVertex[25].vPos = D3DXVECTOR3(-0.5, 0.5, 0.5);
	//m_arrVertex[26].vPos = D3DXVECTOR3(0.5, 0.5, 0.5);
	//m_arrVertex[27].vPos = D3DXVECTOR3(-0.5, 0.5, -0.5);
	//m_arrVertex[28].vPos = D3DXVECTOR3(0.5, 0.5, 0.5);
	//m_arrVertex[29].vPos = D3DXVECTOR3(0.5, 0.5, -0.5);

	//// ¾Æ·¡¸é
	//m_arrVertex[31].vPos = D3DXVECTOR3(-0.5, -0.5, -0.5);
	//m_arrVertex[30].vPos = D3DXVECTOR3(-0.5, -0.5, 0.5);
	//m_arrVertex[32].vPos = D3DXVECTOR3(0.5, -0.5, 0.5);
	//m_arrVertex[34].vPos = D3DXVECTOR3(-0.5, -0.5, -0.5);
	//m_arrVertex[33].vPos = D3DXVECTOR3(0.5, -0.5, 0.5);
	//m_arrVertex[35].vPos = D3DXVECTOR3(0.5, -0.5, -0.5);

	//for (int i = 0; i < 36; ++i)
	//	m_arrVertex[i].color = D3DXCOLOR(0.6f,0.6f, 0, 1);
	/////////
	//// ¾Õ¸é
	//m_VarrelArrVertex[0].vPos = D3DXVECTOR3(-0.25, -0.25, 0);
	//m_VarrelArrVertex[1].vPos = D3DXVECTOR3(-0.25, 0.25, 0);
	//m_VarrelArrVertex[2].vPos = D3DXVECTOR3(0.25, 0.25, 0);
	//m_VarrelArrVertex[3].vPos = D3DXVECTOR3(-0.25, -0.25, 0);
	//m_VarrelArrVertex[4].vPos = D3DXVECTOR3(0.25, 0.25, 0);
	//m_VarrelArrVertex[5].vPos = D3DXVECTOR3(0.25, -0.25, 0);

	//// µÞ¸é
	//m_VarrelArrVertex[7].vPos = D3DXVECTOR3(-0.25, -0.25, 2);
	//m_VarrelArrVertex[6].vPos = D3DXVECTOR3(-0.25, 0.25, 2);
	//m_VarrelArrVertex[8].vPos = D3DXVECTOR3(0.25, 0.25, 2);
	//m_VarrelArrVertex[10].vPos = D3DXVECTOR3(-0.25, -0.25, 2);
	//m_VarrelArrVertex[9].vPos = D3DXVECTOR3(0.25, 0.25, 2);
	//m_VarrelArrVertex[11].vPos = D3DXVECTOR3(0.25, -0.25, 2);

	//// ¿À¸¥ÂÊ
	//m_VarrelArrVertex[12].vPos = D3DXVECTOR3(0.25, -0.25, 0);
	//m_VarrelArrVertex[13].vPos = D3DXVECTOR3(0.25, 0.25, 0);
	//m_VarrelArrVertex[14].vPos = D3DXVECTOR3(0.25, 0.25, 2);
	//m_VarrelArrVertex[15].vPos = D3DXVECTOR3(0.25, -0.25, 0);
	//m_VarrelArrVertex[16].vPos = D3DXVECTOR3(0.25, 0.25, 2);
	//m_VarrelArrVertex[17].vPos = D3DXVECTOR3(0.25, -0.25, 2);

	//// ¿ÞÂÊ
	//m_VarrelArrVertex[19].vPos = D3DXVECTOR3(-0.25, -0.25, 0);
	//m_VarrelArrVertex[18].vPos = D3DXVECTOR3(-0.25, 0.25, 0);
	//m_VarrelArrVertex[20].vPos = D3DXVECTOR3(-0.25, 0.25, 2);
	//m_VarrelArrVertex[22].vPos = D3DXVECTOR3(-0.25, -0.25, 0);
	//m_VarrelArrVertex[21].vPos = D3DXVECTOR3(-0.25, 0.25, 2);
	//m_VarrelArrVertex[23].vPos = D3DXVECTOR3(-0.25, -0.25, 2);

	//// À­¸é
	//m_VarrelArrVertex[24].vPos = D3DXVECTOR3(-0.25, 0.25, 0);
	//m_VarrelArrVertex[25].vPos = D3DXVECTOR3(-0.25, 0.25, 2);
	//m_VarrelArrVertex[26].vPos = D3DXVECTOR3(0.25, 0.25, 2);
	//m_VarrelArrVertex[27].vPos = D3DXVECTOR3(-0.25, 0.25, 0);
	//m_VarrelArrVertex[28].vPos = D3DXVECTOR3(0.25, 0.25, 2);
	//m_VarrelArrVertex[29].vPos = D3DXVECTOR3(0.25, 0.25, 0);

	//// ¾Æ·¡¸é
	//m_VarrelArrVertex[31].vPos = D3DXVECTOR3(-0.25, -0.25, 0);
	//m_VarrelArrVertex[30].vPos = D3DXVECTOR3(-0.25, -0.25, 2);
	//m_VarrelArrVertex[32].vPos = D3DXVECTOR3(0.25, -0.25, 2);
	//m_VarrelArrVertex[34].vPos = D3DXVECTOR3(-0.25, -0.25, 0);
	//m_VarrelArrVertex[33].vPos = D3DXVECTOR3(0.25, -0.25, 2);
	//m_VarrelArrVertex[35].vPos = D3DXVECTOR3(0.25, -0.25, 0);

	//for (int i = 0; i < 36; ++i)
	//	m_VarrelArrVertex[i].color = D3DXCOLOR(0.1f,0.1f, 0.1f, 0);

	/////////
	OBJECTINFO info;
	ZeroInfo(&info);
	info.vScale = VEC3ONE;

	ZeroMemory(&info.Material, sizeof(info.Material));
	info.Material.Ambient= info.Material.Diffuse= D3DXCOLOR(0.6f, 0.6f, 0.6f, 0);
	D3DXCreateBox(DEVICE, 1, 1, 1, &m_pMesh, nullptr);
	D3DXCreateBox(DEVICE, 0.5, 0.5, 2, &m_pVarrelMesh, nullptr);
	info.Pollygon = PG_VOID;
	baseObject::Init(info);
	//D3DXMatrixIdentity(&m_mTrans);

	//D3DXMatrixTranslation(&m_mTrans, 0, 0, 0);
	m_rotateSpeed = 0.5f;
	m_vRotateSpeed = 0.1f;
}

void TankTop::Update(float dtime,bool _isBoarding)
{
	if (_isBoarding) {

		if (INPUTMGR->GetKey('Z'))
			m_Transform->Rotate(D3DXVECTOR3(0, -D3DX_PI*dtime*m_rotateSpeed, 0));
			//m_vRot.y -= D3DX_PI*dtime*m_rotateSpeed;
		if (INPUTMGR->GetKey('X'))
			//m_vRot.y += D3DX_PI*dtime*m_rotateSpeed;
			m_Transform->Rotate(D3DXVECTOR3(0, D3DX_PI*dtime*m_rotateSpeed, 0));

		if (INPUTMGR->GetKey('C') && m_Transform->GetvRot().x > -30 * D3DX_PI / 180)
			//m_vRot.x -= D3DX_PI*dtime*m_vRotateSpeed;
			m_Transform->Rotate(D3DXVECTOR3(-D3DX_PI*dtime*m_rotateSpeed, 0,0));
		if (INPUTMGR->GetKey('V') && m_Transform->GetvRot().x < 10 * D3DX_PI / 180)
			//m_vRot.x += D3DX_PI*dtime*m_vRotateSpeed;
			m_Transform->Rotate(D3DXVECTOR3(D3DX_PI*dtime*m_rotateSpeed, 0, 0));


		if (INPUTMGR->GetKeyDown('A'))
		//if (INPUTMGR->GetKey('A'))
		{
			Bullet* newBullet = new Bullet;

			newBullet->m_isTankBullet = true;


			D3DXVECTOR3 vBulletPos = D3DXVECTOR3(0, 0, 2);
			//D3DXVec3TransformCoord(&vBulletPos, &vBulletPos, &m_mTM);
			//D3DXVECTOR3 vBulletRot = m_vRot;

			//vBulletRot += *m_pvParentRot;
			//D3DXVec3TransformNormal(&vBulletRot, &vBulletRot, m_pmParentTM);
			//newBullet->Init(vBulletPos, vBulletRot, m_vScale*0.1f);
			//newBullet->Init(m_vPos, m_vRot, m_vScale*0.3f);

			//newBullet->m_mpParentTM = &m_mTM;

			OBJECTINFO _info;
			ZeroInfo(&_info);
			_info.vDir = VEC3FORWARD;

			_info.vPos = vBulletPos;
			_info.vRot = m_Transform->GetvRot();
			_info.vScale = m_Transform->GetvScale()*0.1f;
			_info.Parent = this;
			newBullet->Init(_info);


			m_bullet.push_back(newBullet);
		}
		for (auto a = m_bullet.begin(); a != m_bullet.end();) {
			(*a)->Update(dtime);
			auto b = a;
			a++;
			if (D3DXVec3Length(&(*b)->GetTransform()->GetvPos()) > 40) {
				delete *b;
				m_bullet.erase(b);
				continue;
			}
			for (auto& c : GAMEMGR->m_Tree) {
				(*b)->tag = "Bullet";
				GAMEMGR->DebugVec1 = c->GetTransform()->GetvPos();
				GAMEMGR->DebugVec2 = (*b)->GetTransform()->GetvPos();
				if (GAMEMGR->DebugDis < 1) {
					b = b;
				}
				if (c->IsSphereCollision(*b)) {
					delete *b;
					m_bullet.erase(b);
					break;
				}

			}
		}
		

	}
	for (auto a = m_bullet.begin(); a != m_bullet.end();) {
		auto b = a;
		a++;
		if ((*b)->GetbLife() == false) {
			delete *b;
			m_bullet.erase(b);
		}
	}

	//D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);
	//D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);

	//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	//m_vVPos = m_vPos+ D3DXVECTOR3(0, 0, 1);
	//D3DXMatrixTranslation(&m_mVTrans, m_vVPos.x, m_vVPos.y, m_vVPos.z);
	//if (m_pmParentTM) {
	//	m_mTM = m_mScale * m_mRot * m_mTrans *(*m_pmParentTM);
	//	m_mVTM= m_mScale * m_mRot * m_mVTrans *(*m_pmParentTM);
	//}
	//else {
	//	m_mTM = m_mScale * m_mRot * m_mTrans;
	//	m_mVTM = m_mScale * m_mRot * m_mVTrans;
	//}


}

void TankTop::Render(void)
{
	DEVICE->SetRenderState(D3DRS_LIGHTING, true); // ¶óÀÌÆÃ
	DEVICE->SetMaterial(&m_Material);

	
//	DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);
	m_pMesh->DrawSubset(0);
//	DEVICE->SetTransform(D3DTS_WORLD, &m_mVTM);
	m_pVarrelMesh->DrawSubset(0);

	for (auto& a : m_bullet) {
		a->Render();
	}
}

void TankTop::Release(void)
{
	SAFE_RELEASE(m_pMesh);
}
TankTop::TankTop()
{
	m_pMesh = nullptr;
	
	//m_vPos = D3DXVECTOR3(0, 1.5f, 0);
	//m_vRot = D3DXVECTOR3(0, 0, 0);
	//m_vScale = D3DXVECTOR3(1, 1, 1);
	//m_pmParentTM = nullptr;
}


TankTop::~TankTop()
{
	Release();
}
