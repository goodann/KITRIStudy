#include"GameCommon.h"



void Tank::Init(void)
{
	m_Radius = 1;
	m_CurrentPower = 0;
	m_Gravity = D3DXVECTOR3(0, -9.8f, 0);
	m_vRollingRot = D3DXVECTOR3(0, 0, 0);
	m_JumpPower = 20;
	m_Mass = 100;
	m_Body.m_pmRatentTM = &m_mRenTM;
	//m_Top.m_pmParentTM = &m_Body.m_mTM;
	m_rotateSpeed = 0.5f;
	m_moveSpeed = 5;
	//m_Top.m_pvParentRot = &m_vRot;
	m_isJumping = false;
	m_pDocking = nullptr;
	m_isBoarding = false;
	OBJECTINFO info;
	
	ZeroInfo(&info);
	info.vScale = VEC3ONE;
	info.vDir = VEC3FORWARD;
	info.vPos = D3DXVECTOR3(0, 0.5, 5);
	info.Pollygon = PG_VOID;
	//m_vPos = D3DXVECTOR3(0, 0, 5);
	//m_vRot = D3DXVECTOR3(0, 0, 0);
	//m_vScale = D3DXVECTOR3(1, 1, 1);
	//m_voldDir = m_vDir = D3DXVECTOR3(0, 0, 1);
	m_rotateSpeed =0.5f;
	//info.vPos = m_vPos;
	//info.vRot = m_vRot;

	baseObject::Init(info);

	m_Body.Init(this);
	m_Top.Init(this);
}

void Tank::Update(float dtime)
{

	if (m_isBoarding) {
		D3DXVECTOR3 MOVING(0, 0, 0);

		
		if (INPUTMGR->GetKey(VK_UP)) {
			//MOVING += m_vDir*m_moveSpeed*dtime;
			m_Transform->MoveForward(m_moveSpeed*dtime);
		}
		if (INPUTMGR->GetKey(VK_DOWN)) {
			//MOVING -= m_vDir*m_moveSpeed*dtime;
			m_Transform->MoveForward(-m_moveSpeed*dtime);
		}
		


		//D3DXVECTOR3 MOVED = m_vPos + MOVING;
		bool isCollision = false;


		for (auto& a : GAMEMGR->m_Tree) {
			tag = "Player";
			if (a->IsSphereCollision(this)) {
				isCollision = true;
			}
		}
		if (isCollision == false) {
			//m_vPos = MOVED;
		}

		/*
		if (INPUTMGR->GetKey(VK_LEFT))
		{
			m_vRot.y -= D3DX_PI * m_rotateSpeed*dtime;
		}

		if (INPUTMGR->GetKey(VK_RIGHT))
		{
			m_vRot.y += D3DX_PI * m_rotateSpeed*dtime;
		}
		*/

		if (INPUTMGR->GetKey(VK_LEFT))
		{
			m_Transform->Rotate(D3DXVECTOR3(0, -D3DX_PI * m_rotateSpeed*dtime, 0));
		}

		if (INPUTMGR->GetKey(VK_RIGHT))
		{
			m_Transform->Rotate(D3DXVECTOR3(0, D3DX_PI * m_rotateSpeed*dtime, 0));
		}


		if (INPUTMGR->GetKeyDown(VK_CONTROL)) {
			m_DownJumpKey = true;

		}
		else {
			m_DownJumpKey = false;
		}

		if (m_DownJumpKey == true)
		{
			if (!m_isJumping) {
				m_CurrentPower = m_JumpPower;
				m_isJumping = true;
			}
			else if (!m_doubleJumping) {
				m_CurrentPower = m_JumpPower;
				m_doubleJumping = true;
			}
		}

		if (m_Transform->GetvPos().y >= 0.5 || m_CurrentPower > 0) {
			m_CurrentPower += m_Gravity.y * 5 * dtime;

			m_Transform->GetvPos().y += m_CurrentPower*dtime;
		}
		if (m_Transform->GetvPos().y <= 0.5 && m_CurrentPower < 0) {
			m_Transform->GetvPos().y = 0.5;
			m_CurrentPower = 0;
			m_isJumping = false;
			m_doubleJumping = false;
		}


		if (m_doubleJumping) {
			m_vRollingRot.x += 3 * D3DX_PI / 180.0f;
		}
		else {
			m_vRollingRot.x = 0;
		}
		
	}
	

	//D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);
	//D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
	//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);

	//D3DXVec3TransformNormal(&m_vDir, &m_voldDir, &m_mRot);
	//D3DXVec3Normalize(&m_vDir, &m_vDir);

	//m_mTM = m_mScale * m_mRot * m_mTrans;
	//m_Transform->SetmTM(m_mTM);
	baseObject::Update(dtime);
	m_Body.Update(dtime);
	m_Top.Update(dtime, m_isBoarding);
	
}

void Tank::Render(void)
{
	//m_mRenTM = m_mTM;
	//D3DXMATRIX m_mat2;
	//D3DXMatrixRotationYawPitchRoll(&m_mat2, m_vRollingRot.y, m_vRollingRot.x, m_vRollingRot.z);
	//m_mRenTM = m_mScale *m_mat2 * m_mRot *  m_mTrans;
	DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드
	//m_Transform->Render();
	m_Body.Render();
	m_Top.Render();
}

void Tank::Release(void)
{
}

Tank::Tank()
{

}


Tank::~Tank()
{
	Release();
}
