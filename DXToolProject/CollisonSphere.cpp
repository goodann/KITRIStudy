#include "GameCommon.h"


void CollisonSphere::Init(OBJECTINFO _info)
{
	m_Transform = new MeshTransform;
	m_Transform->SetvPos(_info.m_collInfo.vPos);

	m_collInfo = _info.m_collInfo;

	int selcnt = m_collInfo.fRadius * 20;
	if (selcnt < 10)  selcnt = 10;
	//D3DXCreateSphere(DEVICE, m_collInfo.fRadius,	selcnt, selcnt, &m_pMesh, NULL);
}

void CollisonSphere::Update(float dTime)
{
	m_Transform->TargetTransform(m_collInfo.pTarget);

	baseObject::Update(dTime);
}

void CollisonSphere::Render(void)
{
	DWORD org;
	DEVICE->GetRenderState(D3DRS_FILLMODE, &org);

	DEVICE->SetRenderState(D3DRS_LIGHTING, false);
	DEVICE->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	DEVICE->SetTransform(D3DTS_WORLD, &m_Transform->GetmTM());
	//m_pMesh->DrawSubset(0);
	DEVICE->SetRenderState(D3DRS_FILLMODE, org);
}

void CollisonSphere::Release(void)
{
	//SAFE_RELEASE(m_pMesh);
	SAFE_DELETE(m_Transform);
}

CollisonSphere::CollisonSphere()
{
}


CollisonSphere::~CollisonSphere()
{
	Release();
}
