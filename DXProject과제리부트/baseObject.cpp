#include"GameCommon.h"



baseObject::baseObject()
{
	GAMEMGR->CreateObejct(this);
	m_Transform = nullptr;
	m_alpha = 1;
	m_bDead = false;
	m_bLife = true;
}


baseObject::~baseObject()
{
	Release();
	GAMEMGR->DeleteObejct(this);
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
	
	//if (_info.m_bColl)
	//{
	//	_info.m_collInfo.pTarget = this;
	//	COLLMGR->CreateCollisionSphere(_info);
	//}
	m_fRadius = _info.fRadius;
	tag = _info.strName;
	m_FIleName = _info.FileName;
}

void baseObject::Update(float dTime)
{
	if (m_bLife == false) {
		//m_deadTimer.SetTimer(5.0f);
		m_alpha -= 0.5f * dTime;
	}
	if (m_alpha <= 0)
		m_bDead = true;
	m_Transform->Update(dTime);
}

void baseObject::Render(void)
{
	if (m_alpha<1) {
		
		DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
		DEVICE->SetRenderState(D3DRS_ALPHATESTENABLE, false);
		DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
		DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
		DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_CONSTANT);
		DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
		DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
		DEVICE->SetTextureStageState(0, D3DTSS_CONSTANT, D3DXCOLOR(1, 1, 1, m_alpha));
	}
	m_Transform->Render();
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_ONE);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ZERO);
}

void baseObject::Release(void)
{
}
