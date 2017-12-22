#include "GameCommon.h"


bool TrianglePlayer::IsSphereCollision(D3DXVECTOR3 _targetPos, float _targetRadius)
{
	D3DXVECTOR3 vDIs = _targetPos - m_Transform->GetvPos();
	if (	D3DXVec3LengthSq(&vDIs) <= (m_Radius + _targetRadius)*(m_Radius + _targetRadius))
		return true;
	else
		return false;
}

bool TrianglePlayer::IsSphereCollision(D3DXVECTOR3 a_Pos, float a_Radius, D3DXVECTOR3 _targetPos, float _targetRadius)
{
	D3DXVECTOR3 vDIs = _targetPos - a_Pos;
	if (D3DXVec3LengthSq(&vDIs) <= (a_Radius + _targetRadius)*(a_Radius + _targetRadius))
		return true;
	else
		return false;
}

bool TrianglePlayer::IsSphereCollision()
{
	D3DXVECTOR3 vDIs = m_targetPos - -m_Transform->GetvPos();
	if (D3DXVec3LengthSq(&vDIs) <= (m_Radius + m_targetRadius)*(m_Radius + m_targetRadius))
		return true;
	else
		return false;
}

void TrianglePlayer::Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale)
{
	
	OBJECTINFO info;
	ZeroInfo(&info);
	m_VoidHand=m_Hand = D3DXVECTOR3(-1/3, 1, 1);
	info.fRadius = 1;

	info.vPos = _pos;
	info.vRot = _rot;
	info.vScale = _scale;
	//m_voldDir = m_vDir = D3DXVECTOR3(0, 0, 1);
	
	m_rotateSpeed = 5.0f;
	m_moveSpeed = 5.0f;
	m_isBoarding = false;
	m_pDocking = false;
	m_isJumping = false;
	m_vRollingRot = D3DXVECTOR3(0, 0, 0);
	m_CurrentPower = 0;
	m_Gravity = D3DXVECTOR3(0, -9.8f, 0);
	m_vRollingRot = D3DXVECTOR3(0, 0, 0);
	m_JumpPower = 25;
	m_Mass = 100;
	m_Radius = 1;
	m_fRadius = 1;
	baseObject::Init(info);
	m_Transform->Init(info);
	//OBJECTINFO info;
	ZeroInfo(&info);
	info.vPos = D3DXVECTOR3(0, 1, 0);
	info.vRot = D3DXVECTOR3(0, 0, 0);
	info.vScale = D3DXVECTOR3(0.1f, 0.1f, 0.1f);
	info.Color = D3DXCOLOR(0, 0, 0, 1);
	info.Parent = this;
	m_head.Init(info);
	info.vPos = D3DXVECTOR3(-1.0f / 3, 0.75f, 0);
	info.vScale = D3DXVECTOR3(0.5f / 3, 1.0f / 3, 0.5f / 3);
	info.Color = D3DXCOLOR(0, 0, 1, 1);
	m_LArm.Init(info);
	//m_head.Init(info);
	info.vPos = D3DXVECTOR3(1.0f / 3, 0.75f, 0);
	info.vScale = D3DXVECTOR3(0.5f / 3, 1.0f / 3, 0.5f / 3);
	info.Color = D3DXCOLOR(1, 0, 0, 1);
	m_RArm.Init(info);
	info.vPos = D3DXVECTOR3(0, 1.75f / 3, 0);
	info.vScale = D3DXVECTOR3(0.5f / 3, 1.0f / 3, 0.5f / 3);
	info.Color = D3DXCOLOR(0, 1, 0, 1);
	m_Body.Init(info);
	info.vPos = D3DXVECTOR3(-1.0f / 3, 0.5f / 3, 0);
	info.vScale = D3DXVECTOR3(0.5f / 3, 1.0f / 3, 0.5f / 3);
	info.Color = D3DXCOLOR(0, 1, 1, 1);
	m_LLeg.Init(info);
	info.vPos = D3DXVECTOR3(1.0f / 3, 0.5f / 3, 0);
	info.vScale = D3DXVECTOR3(0.5f / 3, 1.0f / 3, 0.5f / 3);
	info.Color = D3DXCOLOR(1, 1, 0, 1);
	m_RLeg.Init(info);
	info.vPos = D3DXVECTOR3(0,0, 0);
	info.vScale = D3DXVECTOR3(0.05f, 0.05f, 0.05f);
	info.Color = D3DXCOLOR(1, 0, 1, 1);
	m_Buff.Init(info);
	/*
	m_head.Init(D3DXVECTOR3(0,1,0), D3DXVECTOR3(0,0,0), D3DXVECTOR3(0.1f,0.1f,0.1f), D3DXCOLOR(0, 0, 0, 1),&m_mRenTM);
	m_LArm.Init(D3DXVECTOR3(-1.0f / 3, 0.75f, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.5f/3, 1.0f/3, 0.5f/3), D3DXCOLOR(0,0,1,1), &m_mRenTM);
	m_RArm.Init(D3DXVECTOR3(1.0f /3, 0.75f, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.5f/3, 1.0f/3, 0.5f/3), D3DXCOLOR(1,0,0, 1), &m_mRenTM);
	m_Body.Init(D3DXVECTOR3(0, 1.75f/3, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.5f/3, 1.0f/3, 0.5f/3), D3DXCOLOR(0,1,0, 1), &m_mRenTM);
	m_LLeg.Init(D3DXVECTOR3(-1.0f /3,0.5f/3, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.5f/3, 1.0f/3, 0.5f/3), D3DXCOLOR(0,1,1, 1), &m_mRenTM);
	m_RLeg.Init(D3DXVECTOR3(1.0f / 3, 0.5f / 3, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.5f / 3, 1.0f / 3, 0.5f / 3), D3DXCOLOR(1,1,0, 1), &m_mRenTM);
	m_Buff.Init(D3DXVECTOR3(0,-0,0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.05f,0.05f,0.05f), D3DXCOLOR(1, 0, 1, 1), &m_mRenTM);
	*/
	buffTheta = 0;
	m_isBuff = false;
	m_isWheelWind = false;

	m_LArm.m_up = false;
	m_RArm.m_up = true;
	m_LArm.m_ArmDir = true;
	m_RArm.m_ArmDir = false;
	m_RArm.m_isMoving = true;
	m_LArm.m_vOriginPivotAxis = D3DXVECTOR3(1, 0, 0);
	m_RArm.m_vOriginPivotAxis = D3DXVECTOR3(-1, 0, 0);
	m_LArm.m_vPivotPoint = D3DXVECTOR3(0,0.75,  0);
	m_RArm.m_vPivotPoint = D3DXVECTOR3(0,0.75,  0);
	m_LArm.m_limitPosiDegree = D3DXToRadian(60);
	m_LArm.m_limitNegaDegree = D3DXToRadian (-60);
	m_RArm.m_limitPosiDegree = D3DXToRadian(60);
	m_RArm.m_limitNegaDegree = D3DXToRadian (-60);


	m_RLeg.m_up = false;
	m_LLeg.m_up = true;
	m_RLeg.m_ArmDir = true;
	m_LLeg.m_ArmDir = false;
	m_LLeg.m_isMoving = true;
	m_RLeg.m_vOriginPivotAxis = D3DXVECTOR3(1, 0, 0);
	m_LLeg.m_vOriginPivotAxis = D3DXVECTOR3(-1, 0, 0);
	m_RLeg.m_vPivotPoint = D3DXVECTOR3(0, 0.75, 0);
	m_LLeg.m_vPivotPoint = D3DXVECTOR3(0, 0.75, 0);
	m_RLeg.m_limitPosiDegree = D3DXToRadian(60);
	m_RLeg.m_limitNegaDegree = D3DXToRadian(-60);
	m_LLeg.m_limitPosiDegree = D3DXToRadian(60);
	m_LLeg.m_limitNegaDegree = D3DXToRadian(-60);
	m_ArmDowning = false;
	m_isDocking = false;
}

void TrianglePlayer::Update(float dTime)
{
	if (!m_isBoarding) {
		
		if (m_isBuff) {
			m_Buff.m_vPos.y = 0.5;
			m_Buff.m_vPos.x = cos(buffTheta);
			m_Buff.m_vPos.z = sin(buffTheta);
			m_BuffTime += dTime;
			buffTheta += D3DX_PI *7.0f*dTime;
			//m_Material.Ambient= m_Material.Diffuse = D3DXCOLOR(1, 0, 0, 1);
			D3DLIGHT9 Light;
			ZeroMemory(&Light, sizeof(Light));
			Light.Type = D3DLIGHTTYPE::D3DLIGHT_DIRECTIONAL;//태양광
			Light.Diffuse = D3DXCOLOR(1, 0, 0, 1);
			Light.Direction = D3DXVECTOR3(1, -1, 1);
			DEVICE->SetLight(0, &Light);
			GAMEMGR->m_sky= D3DXCOLOR(1, 0, 0, 1);
		}
		else {
			buffTheta = 0;
			m_Buff.m_vPos.y = -50;
			//m_Material.Ambient = m_Material.Diffuse = D3DXCOLOR(1, 1, 1, 1);
			D3DLIGHT9 Light;
			ZeroMemory(&Light, sizeof(Light));
			Light.Type = D3DLIGHTTYPE::D3DLIGHT_DIRECTIONAL;//태양광
			switch (GAMEMGR->m_TimeState)
			{
			case 1:
				GAMEMGR->m_sky = D3DXCOLOR(0.2f, 0.2f, 0.5f, 1);
				Light.Diffuse = D3DXCOLOR(0.6f, 0.6f, 1, 1);
				DEVICE->SetRenderState(D3DRS_AMBIENT, D3DXCOLOR(0.2f, 0.2f, 0.2f, 1));
				break;
			case 2:
				GAMEMGR->m_sky = D3DXCOLOR(0.6f, 0.6f, 1.0f, 1);
				Light.Diffuse = D3DXCOLOR(1, 1, 1, 1);
				DEVICE->SetRenderState(D3DRS_AMBIENT, D3DXCOLOR(0.2f, 0.2f, 0.2f, 1));
				break;
			case 3:
				GAMEMGR->m_sky = D3DXCOLOR(0.8f, 0.3f, 0.0f, 1);
				Light.Diffuse = D3DXCOLOR(1, 0.6f, 0.6f, 1);
				DEVICE->SetRenderState(D3DRS_AMBIENT, D3DXCOLOR(0.2f, 0.2f, 0.2f, 1));
				break;
			case 4:
				GAMEMGR->m_sky = D3DXCOLOR(0.1f, 0.1f, 0.1f, 1);
				Light.Diffuse = D3DXCOLOR(0, 0, 0, 1);
				DEVICE->SetRenderState(D3DRS_AMBIENT, D3DXCOLOR(0.1f, 0.1f, 0.1f, 1));
				break;
			}
			
			Light.Direction = D3DXVECTOR3(1, -1, 1);
			DEVICE->SetLight(0, &Light);
		}
		if (m_BuffTime > 10) {
			m_isBuff = false;
			m_BuffTime = 0;
		}
		D3DXVECTOR3 MOVING(0, 0, 0);

		if (INPUTMGR->GetKeyDown('C')) {
			m_isClocking = !m_isClocking;
			m_clockingTimer.SetTimer(20.0f);

		}
		if (m_clockingTimer.TimeCheck()) {
			m_isClocking = false;
		}
		if (INPUTMGR->GetKey(VK_UP))
		{
			//MOVING = m_Transform->GetvDir()*m_moveSpeed*dTime;
			m_Transform->MoveForward(m_moveSpeed*dTime);
			m_LArm.m_isMoving = true;
			m_RArm.m_isMoving = true;
			m_LLeg.m_isMoving = true;
			m_RLeg.m_isMoving = true;
		}else if (INPUTMGR->GetKey(VK_DOWN))
		{
			
			//MOVING = -m_Transform->GetvDir()*m_moveSpeed*dTime;
			m_Transform->MoveForward(-m_moveSpeed*dTime);
			m_LArm.m_isMoving = true;
			m_RArm.m_isMoving = true;
			m_LLeg.m_isMoving = true;
			m_RLeg.m_isMoving = true;
		}
		else {
			m_LArm.m_isMoving = false;
			m_RArm.m_isMoving = false;
			m_LLeg.m_isMoving = false;
			m_RLeg.m_isMoving = false;
		}
		D3DXVECTOR3 MOVED = m_Transform->GetvPos() + MOVING;
		bool isCollision = false;
		
		if (!m_isClocking) {
			for (auto& a : GAMEMGR->m_Tree) {
				if (m_isBuff || m_isWheelWind) {
					//if (a->IsSphereCollision(MOVED, m_Transform->GetvDir(), m_Radius, "Bullet", &m_pDocking)) {
					tag = "Bullet";
					if (a->IsSphereCollision(this)) {
						isCollision = false;
					}
				}
				else {
					tag = "Player";
					if (a->GetbLife() == false)
						continue;
					
					if (a->IsSphereCollision(this)) {
						isCollision = true;
						if (m_pDocking != nullptr && !m_isDocking) {
							D3DXMatrixInverse(&(m_pDocking->m_mParentInverse), nullptr, &m_Transform->GetmTM());
							m_isDocking = true;

							m_pDocking->m_pmParentTM = &m_Transform->GetmTM();
							m_pDocking->m_pmParentRot = &m_Transform->GetmRot();
							m_pDocking->m_pmParentPos = &m_Transform->GetmTrans();
							m_pDocking->m_pmParentScale = &m_Transform->GetmScale();

						}
					}
				}
			}
		}
		if (isCollision) {
			m_Transform->MoveForward(-m_moveSpeed*dTime);
		}
		if (INPUTMGR->GetKey(VK_LEFT))
		{
			m_Transform->Rotate(D3DXVECTOR3(0, -D3DX_PI / 8 * m_rotateSpeed*dTime, 0));
		}

		if (INPUTMGR->GetKey(VK_RIGHT))
		{
			m_Transform->Rotate(D3DXVECTOR3(0, D3DX_PI / 8 * m_rotateSpeed*dTime, 0));
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
				m_isBuff = true;
				m_BuffTime = 0;
			}
		}

		if (m_Transform->GetvPos().y >= 0.5 || m_CurrentPower > 0) {
			m_CurrentPower += m_Gravity.y * 5 * dTime;

			m_Transform->GetvPos().y += m_CurrentPower*dTime;
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


		if (INPUTMGR->GetKey('A')) {
			if(m_RArm.m_vRot.x > D3DXToRadian(-90))
				m_RArm.m_vRot.x += D3DXToRadian(-180)*dTime;
			else {
				if (m_RArm.m_vPos.z >= 0)
				{
					m_RArm.m_vRot.x = D3DXToRadian(-90);

					Bullet* newBullet = new Bullet;



					m_RArm.m_vPos.z -= 0.5f;
					D3DXVECTOR3 vBulletPos = D3DXVECTOR3(1.0f / 3, 2.0f / 3, 1.0f / 3);
					D3DXVec3TransformCoord(&vBulletPos, &vBulletPos, &m_Transform->GetmTM());
					OBJECTINFO _info;
					//ZeroMemory(&_info, sizeof(_info));
					ZeroInfo(&_info);
					_info.vDir = VEC3FORWARD;
					
					_info.vPos = vBulletPos;
					_info.vRot = m_Transform->GetvRot();
					_info.vScale = m_Transform->GetvScale()*0.3f;
					_info.vDir = m_Transform->GetvDir()+D3DXVECTOR3(0,0.5f,0);
					D3DXVec3Normalize(&(_info.vDir), &(_info.vDir));
					//_info.Parent = this;
					newBullet->Init(_info);
					//newBullet->Init(m_vPos, m_vRot, m_vScale*0.3f);

					//newBullet->m_mpParentTM = &m_Transform->GetmTM();
					m_bullet.push_back(newBullet);
				}
			}
		}
		else {
			if (m_RArm.m_vRot.x <0 && m_ArmDowning)
				m_RArm.m_vRot.x -= D3DXToRadian(-180)*dTime;
			if (m_ArmDowning && m_RArm.m_vRot.x >= 0) {
				m_ArmDowning = false;
			}
		}
		if (INPUTMGR->GetKeyUp('A')) {
			//m_RArm.m_vRot.x = D3DXToRadian(0);
			m_ArmDowning = true;
		}
		

		static float degree;
		if (INPUTMGR->GetKey('Q')) {
			m_isWheelWind = true;
			if (m_RArm.m_vRot.z < D3DXToRadian(90))
				m_RArm.m_vRot.z += D3DXToRadian(180)*dTime;
			if (m_LArm.m_vRot.z > D3DXToRadian(-90))
				m_LArm.m_vRot.z += D3DXToRadian(-180)*dTime;
			else {
				
				m_vRollingRot.y += degree;
				degree += D3DXToRadian(190)*dTime;
			}
		}
		if (INPUTMGR->GetKeyUp('Q')) {
			m_isWheelWind = false;
			degree = 0;
			m_vRollingRot.y = 0;
		}
		if (!m_isWheelWind) {
			if (m_RArm.m_vRot.z >0)
				m_RArm.m_vRot.z -= D3DXToRadian(180)*dTime;
			if (m_LArm.m_vRot.z < 0)
				m_LArm.m_vRot.z -= D3DXToRadian(-180)*dTime;
		}

		if (m_RArm.m_vPos.z < 0) {
			m_RArm.m_vPos.z += 0.004f;
		}

		for (auto a = m_bullet.begin(); a != m_bullet.end();) {
			(*a)->Update(dTime);
			auto b = a;
			a++;
			if (D3DXVec3Length(&(*b)->GetTransform()->GetvPos()) > 40) {
				//delete *b;
				(*b)->SetbLife(false);
				//m_bullet.erase(b);
				continue;
			}
			for (auto& c : GAMEMGR->m_Tree) {
				(*b)->tag = "Bullet";
				GAMEMGR->DebugVec1 = c->GetTransform()->GetvPos();
				GAMEMGR->DebugVec2 = (*b)->GetTransform()->GetvPos();
				if (GAMEMGR->DebugDis < 1) {
					b=b;
				}
				if (c->IsSphereCollision(*b)) {
					//delete *b;
					(*b)->SetbLife(false);
					(*b)->SetbDead(true);
					//m_bullet.erase(b);
					break;
				}

			}
		}
		



		for (auto a = m_bullet.begin(); a != m_bullet.end();) {
			auto b = a;
			a++;
			if ((*b)->GetbLife() == false) {
				//delete *b;
				//m_bullet.erase(b);
			}
		}
		
	}
	else {
		m_Transform->GetvPos().y = -10;
	}
	m_Transform->Update(dTime);

	D3DXMATRIX m_mat2;
	D3DXMatrixRotationYawPitchRoll(&m_mat2, m_vRollingRot.y, m_vRollingRot.x, m_vRollingRot.z);

	D3DXMATRIX m_tmp = m_Transform->GetmTM();
	m_Transform->SetmTM(m_Transform->GetmScale() * m_mat2* m_Transform->GetmRot()  * m_Transform->GetmTrans());


	m_head.Update(dTime);
	m_LArm.Update(dTime);
	m_RArm.Update(dTime);
	m_Body.Update(dTime);
	m_LLeg.Update(dTime);
	m_RLeg.Update(dTime);
	m_Buff.Update(dTime);
	
	
	//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	//D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
	//D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);

	//D3DXVec3TransformNormal(&m_vDir, &m_voldDir, &m_mRot);
	//D3DXVec3Normalize(&m_vDir, &m_vDir);
	//D3DXVec3TransformNormal(&m_Hand, &m_VoidHand, &m_mRot);
	////D3DXVec3Normalize(&m_vDir, &m_Hand);
	D3DXVec3TransformNormal(&m_Hand, &m_VoidHand, &m_Transform->GetmRot());
	//m_mTM = m_mScale * m_mRot * m_mTrans;
	
}

void TrianglePlayer::Render(void)
{
	//m_mRenTM = m_mTM;
	



	DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드
	//DEVICE->SetMaterial(&m_Material);
	//DEVICE->SetFVF(D3DFVF_XYZ_COLOR::FVF);
	//DEVICE->SetTransform(D3DTS_WORLD, &m_mRenTM);

	//DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2,m_arrVertex, sizeof(D3DFVF_XYZ_COLOR));
	//DEVICE->SetRenderState()
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	DEVICE->SetRenderState(D3DRS_ALPHATESTENABLE, false);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_CONSTANT);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	if (m_isClocking) {

		DEVICE->SetTextureStageState(0, D3DTSS_CONSTANT, D3DXCOLOR(1, 1, 1, 0.3f));

		
	}
	else {
		DEVICE->SetTextureStageState(0, D3DTSS_CONSTANT, D3DXCOLOR(1, 1, 1, 1));
	}

	m_head.Render();
	m_LArm.Render();
	m_RArm.Render();
	m_Body.Render();
	m_LLeg.Render();
	m_RLeg.Render();
	m_Buff.Render();

	//DEVICE->DrawPrimitiveUP(D3DPT_LINELIST, 1, m_dirLine, sizeof(D3DFVF_XYZ_COLOR));
	/////////////replect


	D3DLIGHT9 orgl, l;
	DEVICE->GetLight(0, &orgl);

	l = orgl;

	D3DXVECTOR3 v = l.Direction;
	v.x = -v.x;
	v.z = -v.z;
	l.Direction = v;
	DEVICE->SetLight(0, &l);


	D3DXMATRIX out;
	D3DXPLANE plane(0, 1, 0, 0);
	D3DXVECTOR3 riverPos = m_Transform->GetvPos();
	D3DXVECTOR3 riverNor = -m_Transform->GetvPos();
	riverPos.y = 0;
	
	//D3DXPlaneFromPointNormal(&plane, &riverPos, &D3DXVECTOR3(0.2, -1, 1));
	D3DXVec3Normalize(&riverNor, &riverNor);
	riverNor.y = -1;
	D3DXVec3Normalize(&riverNor, &riverNor);
	D3DXPlaneFromPointNormal(&plane, &riverPos, &riverNor);
	
	D3DXMatrixReflect(&out, &plane);

	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CW); // 컬링모드
	{
		DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		//DEVICE->SetRenderState(D3DRS_ZWRITEENABLE, false);
		DEVICE->SetRenderState(D3DRS_STENCILENABLE, true);
		DEVICE->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_EQUAL);
		DEVICE->SetRenderState(D3DRS_STENCILREF, 1);
		DEVICE->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_KEEP);
	}
	{
			DEVICE->SetRenderState(D3DRS_FOGENABLE, TRUE);				  // 안개On
			DEVICE->SetRenderState(D3DRS_FOGCOLOR, D3DXCOLOR(0, 0, 0, 1)); // 안개색상
			
																		   // 안개 옵션 : 버텍스 선형 안개
			
			
			float sp = 0.0f;
			float ep = 20.0f;
			DEVICE->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_LINEAR);	// 선형안개
			DEVICE->SetRenderState(D3DRS_FOGSTART, *(DWORD*)(&sp));		// 안개 시작점
			DEVICE->SetRenderState(D3DRS_FOGEND, *(DWORD*)(&ep));		// 안개 끝점
			DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
			//DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
			DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
			DEVICE->SetTextureStageState(1, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

	}
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CONSTANT);
	DEVICE->SetTextureStageState(0, D3DTSS_CONSTANT, D3DXCOLOR(1, 1, 1, 0.5));
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	m_head.Render(&out);
	m_LArm.Render(&out);
	m_RArm.Render(&out);
	m_Body.Render(&out);
	m_LLeg.Render(&out);
	m_RLeg.Render(&out);
	m_Buff.Render(&out);

	DEVICE->SetRenderState(D3DRS_SPECULARENABLE, false);
	DEVICE->SetRenderState(D3DRS_STENCILENABLE, false);
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);

	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드
	DEVICE->SetLight(0, &orgl);

	DEVICE->SetRenderState(D3DRS_FOGENABLE, false);
	//m_Transform->SetmTM(m_tmp);
	for (auto& a : m_bullet) {
		a->Render();
	}
	
}

void TrianglePlayer::Release(void)
{
}

TrianglePlayer::TrianglePlayer()
{
	m_isClocking = false;
}


TrianglePlayer::~TrianglePlayer()
{
}

