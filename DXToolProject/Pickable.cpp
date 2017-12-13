#include"GameCommon.h"


void Pickable::Init()
{
	
}

void Pickable::Update(void)
{
	D3DXVec3TransformCoord(&m_CollSpherePos, &D3DXVECTOR3(0, 0, 0), &m_mTrans);
	D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
}

void Pickable::Render()
{
	DEVICE->SetRenderState(D3DRS_LIGHTING, false); // ������

	DEVICE->SetFVF(D3DFVF_XYZ_COLOR::FVF);
	DEVICE->SetTransform(D3DTS_WORLD, &m_mTrans);
	DWORD val;
	DEVICE->GetRenderState(D3DRS_FILLMODE, &val);
	DEVICE->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	m_CollSphere->DrawSubset(0);
	DEVICE->SetRenderState(D3DRS_FILLMODE, val);
}

bool Pickable::PickingSphereCheck(baseObject* Target,D3DXVECTOR3 * pickPos, MouseRay ray)
{
	
	//���̿� Ÿ�ٰ��� �Ÿ� ����
	D3DXVECTOR3 vDis = Target ->GetTransform()->GetvPos()- ray.m_vPos;
	//���� ����� �Ÿ����� ���� ���
	float len = D3DXVec3Dot(&vDis, &ray.m_vDir);
	if (len < 0)
		return false;
	//len�� ��� ��ġ
	vDis = ray.m_vPos + ray.m_vDir*len;
	//���� ������� Ÿ�� ���Ϳ��� �Ÿ�����
	D3DXVECTOR3 vDis2 = vDis - Target->GetTransform()->GetvPos();
	//�Ÿ�
	len = D3DXVec3Length(&vDis2);
	//���� �Ÿ��� �۴ٸ� �浹
	
	if (len < Target->GetPickRadius()) {
		*pickPos = vDis;
		return true;
	}

	return false;
}
bool Pickable::PickingTrianglesCheck(baseObject * Target, D3DXVECTOR3 * pickPos, MouseRay ray)
{
	float u, v, t;
	VertexTransform* trans = dynamic_cast<VertexTransform*>(Target->GetTransform());
	D3DFVF_XYZ_NORMAL_UV* pData = (D3DFVF_XYZ_NORMAL_UV*)(trans->GetpData());
	int cnt = trans->GetnTriCnt();
	//VertexTransform
	for (int i = 0; i < cnt; i++) {
		if (D3DXIntersectTri(&pData[3*i].vPos, &pData[3*i+1].vPos, &pData[3*i+2].vPos, &ray.m_vPos, &ray.m_vDir, &u, &v, &t))
		{
			*pickPos = ray.m_vPos + (t*ray.m_vDir);
			return true;
		}
	}
	return false;
}
Pickable::Pickable()
{
	m_CollSphere = nullptr;
	D3DXCreateSphere(DEVICE, 1.5f, 36, 36, &m_CollSphere, nullptr);
	m_PickRadius = 1;
	
}


Pickable::~Pickable()
{
	SAFE_RELEASE(m_CollSphere);
}
