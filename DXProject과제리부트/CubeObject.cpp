#include "GameCommon.h"

//void CubeObject::Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _Rot, D3DXVECTOR3 _scal, D3DXCOLOR _color, LPD3DXMATRIX _pTM)
//{
//	m_limitPosiDegree = 0;
//	m_limitNegaDegree = 0;
//	m_isMoving = false;
//	m_vOriginPivotAxis=m_vPivotAxis = D3DXVECTOR3(0, 0, 0);
//	m_vPivotPoint = D3DXVECTOR3(0, 0, 0);
//	m_vPos = _pos;
//	m_vRot = _Rot;
//	m_vScale = _scal;
//	m_Radius = 1;
//	m_ParentTM=_pTM;
//	m_RotateDir = true;
//	D3DXCreateBox(DEVICE, 2, 2, 2, &m_pMesh, nullptr);
//	ZeroMemory(&m_Material, sizeof(m_Material));
//	
//	//for (int i = 0; i < 36; ++i)
//		//m_arrVertex[i].color = D3DXCOLOR(1, 1, 0, 1);
//		//m_arrVertex[i].color = _color;
//	m_Material.Ambient = m_Material.Diffuse = _color;
//	//m_Material.Ambient = m_Material.Diffuse = D3DXCOLOR(1, 1, 0, 1);
//	D3DXMatrixIdentity(&m_mTrans);
//
//	//D3DXMatrixTranslation(&m_mTrans, 0, 0, 0);
//	//m_mTrans._43 = 15;
//	//m_vPos = D3DXVECTOR3(0, 0, 15);
//}

void CubeObject::Init(OBJECTINFO _info)
{
	_info.Pollygon = PG_BOX;
	baseObject::Init(_info);
	m_limitPosiDegree = 0;
	m_limitNegaDegree = 0;
	m_isMoving = false;
	m_vOriginPivotAxis = m_vPivotAxis = D3DXVECTOR3(0, 0, 0);
	m_vPivotPoint = D3DXVECTOR3(0, 0, 0);
	m_vPos = _info.vPos;
	m_vRot = _info.vRot;
	m_vScale = _info.vScale;
	m_Radius = _info.fRadius;

	m_RotateDir = true;
	//D3DXCreateBox(DEVICE, 2, 2, 2, &m_pMesh, nullptr);
	ZeroMemory(&m_Material, sizeof(m_Material));

	//for (int i = 0; i < 36; ++i)
	//m_arrVertex[i].color = D3DXCOLOR(1, 1, 0, 1);
	//m_arrVertex[i].color = _color;
	m_Material.Ambient = m_Material.Diffuse = _info.Color;
	//m_Material.Ambient = m_Material.Diffuse = D3DXCOLOR(1, 1, 0, 1);
	D3DXMatrixIdentity(&m_mTrans);

	

}

void CubeObject::Update(float dTime)
{
	const float j= D3DXToRadian(90)*dTime;
	static float i;
	if (m_isMoving) {
		if (m_vOriginPivotAxis != D3DXVECTOR3(0, 0, 0)) {
			m_vPivotAxis = (m_vOriginPivotAxis* i);
			if (m_RotateDir) {
				i += j;
				if (i > m_limitPosiDegree) {
					m_RotateDir = false;
				}
			}
			else {
				i -= j;
				if (i < m_limitNegaDegree) {
					m_RotateDir = true;
				}
			}
		}
	}
	else {
		m_vPivotAxis = (m_vOriginPivotAxis* 0);
	}
	D3DXMatrixRotationYawPitchRoll(&m_mPivotAxis, m_vPivotAxis.y, m_vPivotAxis.x, m_vPivotAxis.z);
	D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
	D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	D3DXMatrixTranslation(&m_mPivotPoint, m_vPivotPoint.x, m_vPivotPoint.y, m_vPivotPoint.z);
	D3DXMatrixInverse(&m_mInversPivotPoint, nullptr, &m_mPivotPoint);

	m_Transform->Update(dTime);
	//if (m_ParentTM) {
		//m_Transform->SetmTM(m_mInversPivotPoint*m_mScale *m_mPivotAxis* m_mRot *  m_mTrans*(*m_ParentTM)); 
		//m_Transform->SetvDir( )
			//D3DXVec3TransformNormal(&m_vDir, &m_OrgvDir, &m_mRot);
	//D3DXVec3Normalize(&m_vDir, &m_vDir);
	if(m_Parent){
		m_Transform->SetmTM(m_mInversPivotPoint*m_mScale *m_mPivotAxis* m_mRot *  m_mTrans*(m_Parent->GetTransform()->GetmTM()));
		//m_Transform->SetmTM(m_mInversPivotPoint*m_mScale *m_mPivotAxis* m_mRot *  m_mTrans*(*m_ParentTM)); 
		D3DXVec3TransformNormal(&(m_Transform->GetvDir()), &(m_Transform->GetOrgvDir()), &(m_Parent->GetTransform()->GetmRot()));
		D3DXVec3Normalize(&(m_Transform->GetvDir()), &(m_Transform->GetvDir()));
	}
	else {
		//m_mTM = m_mScale * m_mRot * m_mTrans;
		m_Transform->SetmTM(m_mInversPivotPoint*m_mScale *m_mPivotAxis* m_mRot);
	}
	
}

void CubeObject::Render(void)
{
	//DEVICE->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	//DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅
	//DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드
	DEVICE->SetTransform(D3DTS_WORLD, &m_Transform->GetmTM());
	DEVICE->SetMaterial(&m_Material);
	m_Transform->Render();
	//m_pMesh->DrawSubset(0);
	//DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드
	//DEVICE->SetRenderState(D3DRS_LIGHTING, false); // 라이팅
	//DEVICE->SetRenderState(D3DRS_NORMALIZENORMALS, false);
}

void CubeObject::Render(D3DXMATRIX * pmTM)
{
	DEVICE->SetTransform(D3DTS_WORLD, &(m_Transform->GetmTM()*(*pmTM)));
	DEVICE->SetMaterial(&m_Material);
	m_Transform->Render();
}

void CubeObject::Release(void)
{
	//SAFE_RELEASE(m_pMesh);
}

CubeObject::CubeObject()
{
	m_ParentTM = nullptr;
	GAMEMGR->DeleteObejct(this);
}


CubeObject::~CubeObject()
{
	Release();
}
