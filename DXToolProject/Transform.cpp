#include"GameCommon.h"




void Transform::SetAddMatrix(D3DXMATRIX* _pMat)
{
	m_mpMat = _pMat;
}

void Transform::MoveForward(float speed, bool bColl)
{
	if (bColl)
		m_vPos += m_vCollDir * speed;
	else
		m_vPos += m_vDir * speed;
}

void Transform::Rotate(D3DXVECTOR3 vRot)
{


	m_vRot += vRot;

	D3DXVec3TransformNormal(&m_vDir, &m_OrgvDir, &m_mRot);
	D3DXVec3Normalize(&m_vDir, &m_vDir);


}

void Transform::TargetTransform(baseObject * pTarget)
{
	D3DXVec3TransformCoord(&m_vPos, &m_OrgvPos,
		&pTarget->GetTransform()->GetmTM());
}
Transform::Transform()
{
	m_mpMat = nullptr;
}


Transform::~Transform()
{
}

void Transform::Init(OBJECTINFO _info)
{
	m_OrgvDir = m_vDir = VEC3FORWARD;
	m_vPos = _info.vPos;
	m_vRot = _info.vRot;
	m_vScale = _info.vScale;
	m_vDir = _info.vDir;
	m_Material = _info.Material;
	m_Color = _info.Color;
	m_OrgvUp = m_vUp = D3DXVECTOR3(0, 1, 0);
	m_OrgvRight
		= m_vRight = D3DXVECTOR3(1, 0, 0);
	

	if (D3DXVec3Length(&_info.vDir) <= 0.01f)
		m_vDir = VEC3FORWARD;
	m_Material.Ambient = m_Material.Diffuse = _info.Color;
	D3DXMatrixIdentity(&m_mTrans);
	D3DXMatrixIdentity(&m_mScale);
	D3DXMatrixIdentity(&m_mRot);
	D3DXMatrixIdentity(&m_mTM);
}

void Transform::Update(float dtime)
{
	D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
	D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);

	D3DXVec3TransformNormal(&m_vUp, &m_OrgvUp, &m_mRot);
	D3DXVec3Normalize(&m_vUp, &m_vUp);

	D3DXVec3TransformNormal(&m_vRight, &m_OrgvRight, &m_mRot);
	D3DXVec3Normalize(&m_vRight, &m_vRight);

	D3DXVec3TransformNormal(&m_vDir, &m_OrgvDir, &m_mRot);
	D3DXVec3Normalize(&m_vDir, &m_vDir);

	m_mTM = m_mScale * m_mRot * m_mTrans;
		
	
}
