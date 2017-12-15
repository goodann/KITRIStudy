#include"GameCommon.h"



bool ShotableObject::PickingCheck(ShotableObject * Target, D3DXVECTOR3 * pickPos, MouseRay ray)
{
	if (m_PollygonType == PG_TRIANGLES) {
		return PickingTrianglesCheck(Target, pickPos, ray);
	}
	else {
		return PickingSphereCheck(Target, pickPos, ray);
	}
	return false;
}
bool ShotableObject::PickingMeshCheck(ShotableObject * Target, D3DXVECTOR3 * pickPos, MouseRay ray)
{
	auto m_pMesh=((MeshTransform*)Target->GetTransform())->GetpMesh();
	float u, v, t;
	VertexTransform* trans = dynamic_cast<VertexTransform*>(Target->GetTransform());
	D3DFVF_XYZ_NORMAL_UV* pData = (D3DFVF_XYZ_NORMAL_UV*)(trans->GetpData());
	int cnt = trans->GetnTriCnt();
	//VertexTransform
	BOOL bHit;
	DWORD index;
	for (int i = 0; i < cnt; i++) {
		
		D3DXIntersect((LPD3DXBASEMESH)(&m_pMesh), &ray.m_vPos, &ray.m_vDir, &bHit, &index, &u, &v, &t, nullptr, nullptr);
		{
		*pickPos = ray.m_vPos + (t*ray.m_vDir);
		return true;
		}
		
	}
	return false;
}


ShotableObject::ShotableObject()
{
}


ShotableObject::~ShotableObject()
{
}
