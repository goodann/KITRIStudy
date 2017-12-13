#include"GameCommon.h"



baseObject::baseObject()
{
	GAMEMGR->CreateObejct(this);
	m_Transform = nullptr;
}


baseObject::~baseObject()
{
	Release();
	SAFE_DELETE(m_Transform);
}

void baseObject::Init(OBJECTINFO _info)
{
	m_PollygonType = _info.Pollygon;
	switch (_info.Pollygon) {
	case PG_VOID:
		m_Transform = new Transform;
		break;
	case PG_TRIANGLES:
		m_Transform = new VertexTransform;
		
		break;
	default:
		m_Transform = new MeshTransform;
		break;
	}
	m_Transform->Init(_info);
	if (_info.m_bColl)
	{
		_info.m_collInfo.pTarget = this;
		COLLMGR->CreateCollisionSphere(_info);
	}
	m_fRadius = _info.fRadius;
	if(_info.strName!=nullptr)
		tag = _info.strName;
}

void baseObject::Update(float dTime)
{
	m_Transform->Update(dTime);
}

void baseObject::Render(void)
{
	m_Transform->Render();
}

void baseObject::Release(void)
{
}

bool baseObject::PickingCheck(baseObject * Target, D3DXVECTOR3 * pickPos, MouseRay ray)
{
	if (m_PollygonType==PG_TRIANGLES) {
		return PickingTrianglesCheck(Target, pickPos, ray);
	}
	else {
		return PickingSphereCheck(Target, pickPos, ray);
	}
	return false;
}
