#include"GameCommon.h"

LPDIRECT3DTEXTURE9 Tree::m_Texture = nullptr;
//bool Tree::IsSphereCollision(D3DXVECTOR3 _targetPos, D3DXVECTOR3 _targetVal, float _targetRadius,string _tag,Tree** m_pDocking){
//
//	if (m_pmParentTM != nullptr)
//		return false;
//	D3DXVECTOR3 vDIs = _targetPos - m_vPos;
//	if (D3DXVec3LengthSq(&vDIs) <= (m_Radius + _targetRadius)*(m_Radius + _targetRadius)) {
//		OnCollision(_targetPos, _targetVal,_tag, m_pDocking);
//		return true;
//	}
//	else {
//		return false;
//	}
//}
bool Tree::IsSphereCollision(baseObject* Object) {
	if (m_pmParentTM != nullptr)
		return false;
	D3DXVECTOR3 _targetPos = Object->GetTransform()->GetvPos();
	D3DXVECTOR3 _targetVal = Object->GetTransform()->GetvDir();
	D3DXVECTOR3 vDIs =  - m_Transform->GetvPos() + _targetPos;
	Tree** m_pDocking = nullptr;
	float r = m_Radius + Object->GetfRadius();
	float l = D3DXVec3LengthSq(&vDIs);
	if ( l<= (r*r)) {
		if (typeid(Object) == typeid(TrianglePlayer)) {
			m_pDocking = &(((TrianglePlayer*)(Object))->m_pDocking);
		}
		//OnCollision(_targetPos, _targetVal, Object->tag, m_pDocking);
		OnCollision(Object, m_pDocking);
		return true;
	}
	else {
		return false;
	}
}
void Tree::Init(OBJECTINFO _info)
{
	m_Radius = 1;
	/*
	m_Transform->SetvPos(_info.vPos);
	m_Transform->SetvRot( _info.vRot);
	m_Transform->SetvScale( _info.vScale);
	_info.Pollygon = PG_TRIANGLES;

	m_voldDir = m_vDir = D3DXVECTOR3(0, 0, 1);
	*/
	m_arrVertex[0].vPos = D3DXVECTOR3(-1, 0, 0);
	m_arrVertex[1].vPos = D3DXVECTOR3(-1, 2, 0);
	m_arrVertex[2].vPos = D3DXVECTOR3(1, 2, 0);

	m_arrVertex[3].vPos = D3DXVECTOR3(-1, 0, 0);
	m_arrVertex[4].vPos = D3DXVECTOR3(1, 2, 0);
	m_arrVertex[5].vPos = D3DXVECTOR3(1, 0, 0);


	m_arrVertex[0].u = 0;
	m_arrVertex[1].u = 0;
	m_arrVertex[2].u = 1;
	m_arrVertex[3].u = 0;
	m_arrVertex[4].u = 1;
	m_arrVertex[5].u = 1;

	m_arrVertex[0].v = 1;
	m_arrVertex[1].v = 0;
	m_arrVertex[2].v = 0;
	m_arrVertex[3].v = 1;
	m_arrVertex[4].v = 0;
	m_arrVertex[5].v = 1;
	for (int i = 0; i < 6; i++) {
		m_arrVertex[i].vNormal = D3DXVECTOR3(0, -1, 0);
	}
	_info.vDir = VEC3FORWARD;
	_info.nSize = sizeof(D3DFVF_XYZ_NORMAL_UV)*6;
	_info.nTriangleCnt = 2;
	_info.Pollygon = PG_TRIANGLES;
	_info.dwFVF = D3DFVF_XYZ_NORMAL_UV::FVF;
	_info.fRadius = 1;
	_info.m_bColl = true;
	_info.m_collInfo.fRadius = 1;
	_info.Color = D3DXCOLOR(1, 1, 1, 1);
	_info.pData = m_arrVertex;
	//_info.pData
	baseObject::Init(_info);

	//m_arrVertex[0].color = D3DXCOLOR(0, 0.5, 0, 0);
	//m_arrVertex[1].color = D3DXCOLOR(0, 1, 0, 0);
	//m_arrVertex[2].color = D3DXCOLOR(0, 0.5, 0, 0);
	//m_arrVertex[3].color = D3DXCOLOR(0, 0.8, 0, 0);
	//m_arrVertex[4].color = D3DXCOLOR(0, 1, 0, 0);
	//m_arrVertex[5].color = D3DXCOLOR(0, 0.8, 0, 0);


	//m_dirLine[0].vPos = D3DXVECTOR3(0, 1, 0);
	//m_dirLine[1].vPos = D3DXVECTOR3(0, 1, 2);
	//m_dirLine[1].color = m_dirLine[0].color = D3DXCOLOR(0, 1, 0, 2);
	ZeroMemory(&m_Material, sizeof(m_Material));
	m_Material.Ambient = m_Material.Diffuse = D3DXCOLOR(1, 1, 1, 1);
	m_pmParentTM = nullptr;
}
//
//void Tree::Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale)
//{
//	m_Radius = 1;
//	m_vPos = _pos;
//	m_vRot = _rot;
//	m_vScale = _scale;
//	m_voldDir = m_vDir = D3DXVECTOR3(0, 0, 2);
//
//	m_arrVertex[0].vPos = D3DXVECTOR3(-1, 0, 0);
//	m_arrVertex[1].vPos = D3DXVECTOR3(0, 2, 0);
//	m_arrVertex[2].vPos = D3DXVECTOR3(1, 0, 0);
//
//	m_arrVertex[3].vPos = D3DXVECTOR3(-1, 1, 0);
//	m_arrVertex[4].vPos = D3DXVECTOR3(0, 3, 0);
//	m_arrVertex[5].vPos = D3DXVECTOR3(1, 1, 0);
//	for (int i = 0; i < 6; i++) {
//		m_arrVertex[i].vNormal=D3DXVECTOR3(0, -1, 0);
//	}
//
//	//m_arrVertex[0].color = D3DXCOLOR(0, 0.5, 0, 0);
//	//m_arrVertex[1].color = D3DXCOLOR(0, 1, 0, 0);
//	//m_arrVertex[2].color = D3DXCOLOR(0, 0.5, 0, 0);
//	//m_arrVertex[3].color = D3DXCOLOR(0, 0.8, 0, 0);
//	//m_arrVertex[4].color = D3DXCOLOR(0, 1, 0, 0);
//	//m_arrVertex[5].color = D3DXCOLOR(0, 0.8, 0, 0);
//
//
//	//m_dirLine[0].vPos = D3DXVECTOR3(0, 1, 0);
//	//m_dirLine[1].vPos = D3DXVECTOR3(0, 1, 2);
//	//m_dirLine[1].color = m_dirLine[0].color = D3DXCOLOR(0, 1, 0, 2);
//	ZeroMemory(&m_Material, sizeof(m_Material));
//	m_Material.Ambient= m_Material.Diffuse= D3DXCOLOR(0, 1, 0, 1);
//	m_pmParentTM = nullptr;
//}

void Tree::Update(float dtime)
{
	D3DXMATRIX mBillboard;
	D3DXMATRIX temp;

	DEVICE->GetTransform(D3DTS_VIEW, &temp);
	//D3DXMatrixIdentity(&mBillboard);

	//mBillboard._11 = temp._11;
	//mBillboard._13 = temp._13;
	//mBillboard._31 = temp._31;
	//mBillboard._33 = temp._33;
	//D3DXMatrixInverse(&mBillboard, 0, &mBillboard);
	//mBillboard = GAMEMGR->GetCamBillboardTM();

	if (m_IsSomerSaulting) {

		//if (m_vPos.y >= 0 || m_CurrentPower > 0) {
		//	m_CurrentPower += m_Gravity * 5 * dtime;

		//	m_vPos.y += m_CurrentPower*dtime;
		//}
		//if (m_vPos.y <= 0 && m_CurrentPower < 0) {
		//	m_vPos.y = 0;
		//	m_CurrentPower = 0;
		//	m_IsSomerSaulting = false;
		//}
		if (m_Transform->GetvPos().y>= 0 || m_CurrentPower > 0) {
			m_CurrentPower += m_Gravity * 5 * dtime;

			m_Transform->GetvPos().y += m_CurrentPower*dtime;
		}
		if (m_Transform->GetvPos().y <= 0 && m_CurrentPower < 0) {
			m_Transform->GetvPos().y = 0;
			m_CurrentPower = 0;
			m_IsSomerSaulting = false;
		}
		
	}
	if (m_IsSomerSaulting) {
		m_vRollingRot.x += 700 * D3DX_PI *dtime;
	}
	else if(!m_isDeading && !m_isDead && m_hp!=5 && m_pmParentTM==nullptr){
		m_vRollingRot.x = D3DX_PI/180.0f*89;
	}
	else {
		m_vRollingRot.x = 0;
	}

	/*
	D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
	D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);

	D3DXVec3TransformNormal(&m_vDir, &m_voldDir, &m_mRot);
	D3DXVec3Normalize(&m_vDir, &m_vDir);
	*/

	if (m_isDeading) {
		D3DXVECTOR3 vec;
		D3DXVECTOR3 vec2 = D3DXVECTOR3(0, 1, 0);
		D3DXVec3Cross(&vec, &CollisionVec, &vec2);
		D3DXVec3Normalize(&vec, &vec);
		m_Transform->GetvRot() -= vec*D3DX_PI / 180.0f*dtime*val;
		val += acc;
		degree+= dtime*val;

		//m_vRot.x += D3DX_PI / 180.0f*0.1f;
		
		if (degree>=89) {
		m_isDeading = false;
		m_isDead = true;
		}
		

	}
	//if(!m_isDead && !m_isDeading)
		//m_Transformm_mTM = m_mScale * m_mRot * mBillboard * m_mTrans;
	//else
		//m_mTM = m_mScale * m_mRot * m_mTrans;
	//if (m_pmParentTM != nullptr) {
	//	D3DXMATRIX m;
	//	
	//	D3DXMatrixInverse(&m, NULL, m_pmParentRot);
	//	m_mTM = m_mScale * m_mRot*m_mTrans;
	//	//
	//}
	//m_mRenTM = m_mTM;
	D3DXMATRIX m_mat2;
	D3DXMatrixRotationYawPitchRoll(&m_mat2, m_vRollingRot.y, m_vRollingRot.x, m_vRollingRot.z);
	//m_mRenTM = m_mScale *m_mat2 * m_mRot *  m_mTrans;
	if (m_pmParentTM != nullptr) {
		//m_mRenTM = m_mScale;
		//m_mRenTM *= m_mat2;
		//m_mRenTM *= m_mRot;

		//m_mRenTM *= m_mTrans;
		m_mRenTM = m_Transform->GetmTM();
		m_mRenTM *= m_mParentInverse;
		m_mRenTM *= (*m_pmParentTM);
		m_Transform->SetmTM(m_mRenTM);

	}
	baseObject::Update(dtime);

}

void Tree::Render(void)
{

	
	//else
		//m_mRenTM = m_mScale *m_mat2* m_mRot *  m_mTrans;

	DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드
	DEVICE->SetTexture(0, Tree::m_Texture);
	DEVICE->SetFVF(D3DFVF_XYZ_NORMAL_UV::FVF);
	//DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);
	DEVICE->SetTransform(D3DTS_WORLD, &m_mRenTM);
	DEVICE->SetMaterial(&m_Material);
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	DEVICE->SetRenderState(D3DRS_ALPHATESTENABLE, true);


	DEVICE->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	DEVICE->SetRenderState(D3DRS_ALPHAREF, DWORD(0.1f * 255));



	DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DEVICE->SetTextureStageState(0, D3DTSS_TEXCOORDINDEX, 0);
	//DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	//DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_DIFFUSE);
	//DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	if (GAMEMGR->m_Winter>0) {

		//DEVICE->SetTexture(0, m_pSnowTexture);
		//DEVICE->SetTexture(6, m_pMaskTexture);
		DEVICE->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_ADD);
		DEVICE->SetTextureStageState(1, D3DTSS_COLORARG1, D3DTA_TEXTURE);
		DEVICE->SetTextureStageState(1, D3DTSS_COLORARG2, D3DTA_CURRENT);
		DEVICE->SetTextureStageState(1, D3DTSS_TEXCOORDINDEX, 0);
		DEVICE->SetTexture(1, GAMEMGR->m_pSnowTexture[GAMEMGR->m_Winter - 1]);
	}
	else {
		DEVICE->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
		DEVICE->SetTextureStageState(1, D3DTSS_COLOROP, D3DTOP_DISABLE);
	}

	baseObject::Render();

	//m_Transform->Render();
	//DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2,m_arrVertex, sizeof(D3DFVF_XYZ_NORMAL));

	//DEVICE->DrawPrimitiveUP(D3DPT_LINELIST, 1, m_dirLine, sizeof(D3DFVF_XYZ_COLOR));
	DEVICE->SetTexture(0, nullptr);
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드

	//알파끄기
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
}

void Tree::Release(void)
{
}

void Tree::OnCollision(D3DXVECTOR3 _targetPos, D3DXVECTOR3 _targetVal,string _tag,Tree** m_pDocking)
{
	
	//D3DXVECTOR3 DXVec3;
	//CollisionVec = (m_vPos - _targetPos);
	CollisionVec = _targetVal;
	if (m_hp == 5 ) {
		if (_tag == "Bullet") {
			m_isDeading = true;
			m_hp--;
		}
	}
	else if (m_hp >= 1) {
		
		if (!m_isDeading && _tag=="Player") {
			if (m_pDocking != nullptr && *m_pDocking == nullptr) {
				*m_pDocking = this;
				//m_vPos -= _targetPos;
				D3DXMatrixInverse(&(*m_pDocking)->m_mParentInverse, nullptr, &m_Transform->GetmTM());



				
			}
			else {
				D3DXVec3Normalize(&_targetVal, &_targetVal);
				m_vPos += _targetVal * 0.1f;
			}
			//m_hp--;
		}
		else if (!m_isDeading && _tag == "Bullet") {
			m_hp--;
		}
		
	}
	else {
		//delete
		m_bLife = false;
	}
}

void Tree::OnCollision(baseObject* _Object, Tree ** m_pDocking)
{
	CollisionVec = _Object->GetSpeed()*_Object->GetTransform()->GetvDir();
	if (m_hp == 5) {
		if (_Object->tag == "Bullet") {
			m_isDeading = true;
			m_hp--;
		}
	}
	else if (m_hp >= 1) {

		if (!m_isDeading && _Object->tag == "Player") {
			if (m_pDocking != nullptr && *m_pDocking == nullptr) {
				*m_pDocking = this;
				//m_vPos -= _targetPos;
				D3DXMatrixInverse(&(*m_pDocking)->m_mParentInverse, nullptr, &m_Transform->GetmTM());




			}
			else {
				D3DXVec3Normalize(&CollisionVec, &CollisionVec);
				m_vPos += CollisionVec * 0.1f;
			}
			//m_hp--;
		}
		else if (!m_isDeading && _Object->tag == "Bullet") {
			m_hp--;
		}

	}
	else {
		//delete
		m_bLife = false;
	}
}

void Tree::SomerSault()
{
	m_IsSomerSaulting = true;
	m_CurrentPower = m_JumpPower;
	m_hp--;
	OnCollision(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0),"Bullet");
}

Tree::Tree()
{
	m_CurrentPower = 0;
	m_hp = 5;
	m_isDead = false;
	m_isDeading = false;
	degree = 0;
	m_bLife = true;
	acc = 0.1f;
	val = 10;
	m_IsSomerSaulting = false;
	m_vRollingRot = D3DXVECTOR3(0, 0, 0);
}


Tree::~Tree()
{
	GAMEMGR->m_Tree.remove(this);
}

