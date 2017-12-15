#include"GameCommon.h"

LPDIRECT3DTEXTURE9 Windmill::m_pTexture;

void Windmill::Init(OBJECTINFO _info)
{
	m_bodyVertex[0] = { D3DXVECTOR3(-1,  0, -1),   D3DXVECTOR3(0, 0, -1),  0,1};
	m_bodyVertex[1] = { D3DXVECTOR3(0,  5, 0),   D3DXVECTOR3(0, 0, -1),  0.25f,0 };
	m_bodyVertex[2] = { D3DXVECTOR3(1,  0, -1),   D3DXVECTOR3(0, 0, -1),  0.5f,1 };

	m_bodyVertex[3] = { D3DXVECTOR3(1,  0, -1),   D3DXVECTOR3(1, 0, 0),  0,1 };
	m_bodyVertex[4] = { D3DXVECTOR3(0,  5, 0),   D3DXVECTOR3(1, 0, 0),  0.25f,0 };
	m_bodyVertex[5] = { D3DXVECTOR3(1,  0, 1),   D3DXVECTOR3(1, 0, 0),  0.5f,1 };

	m_bodyVertex[6] = { D3DXVECTOR3(1,  0, 1),   D3DXVECTOR3(0, 0, 1),  0,1 };
	m_bodyVertex[7] = { D3DXVECTOR3(0,  5, 0),   D3DXVECTOR3(0, 0, 1),  0.25f,0 };
	m_bodyVertex[8] = { D3DXVECTOR3(-1,  0, 1),   D3DXVECTOR3(0, 0, 1),  0.5f,1 };

	m_bodyVertex[9] = { D3DXVECTOR3(-1,  0, 1),   D3DXVECTOR3(-1, 0, 0),  0,1 };
	m_bodyVertex[10] = { D3DXVECTOR3(0,  5, 0),   D3DXVECTOR3(-1, 0, 0),  0.25f,0 };
	m_bodyVertex[11] = { D3DXVECTOR3(-1,  0, -1),   D3DXVECTOR3(-1, 0, 0),  0.5f,1 };

	m_WindVertex[0] = { D3DXVECTOR3(-1,  0.20f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.710f, 0.978f };
	m_WindVertex[1] = { D3DXVECTOR3(0, 0.20f, -0.01f), D3DXVECTOR3(0, 0, -1), 0.710f, 0.472f };
	m_WindVertex[2] = { D3DXVECTOR3(-1, -0.30f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.978f };

	m_WindVertex[3] = { D3DXVECTOR3(-1, -0.30f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.978f };
	m_WindVertex[4] = { D3DXVECTOR3(0,  0.20f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.710f, 0.472f };
	m_WindVertex[5] = { D3DXVECTOR3(0, -0.30f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.472f };


	//날개 2번.(3시)
	m_WindVertex[6] = { D3DXVECTOR3(1,  0.30f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.978f };
	m_WindVertex[7] = { D3DXVECTOR3(0,  0.30f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.472f };
	m_WindVertex[8] = { D3DXVECTOR3(1, -0.20f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.710f, 0.978f };

	m_WindVertex[9] = { D3DXVECTOR3(1, -0.20f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.710f, 0.978f };
	m_WindVertex[10] = { D3DXVECTOR3(0,  0.30f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.472f };
	m_WindVertex[11] = { D3DXVECTOR3(0, -0.20f, -0.01f),   D3DXVECTOR3(0, 0, -1),  0.710f, 0.472f };
	//날개 3번.(12시)
	m_WindVertex[12] = { D3DXVECTOR3(0.20f, 0.0f, 0.0f),    D3DXVECTOR3(0, 0, -1),  0.710f, 0.472f };
	m_WindVertex[13] = { D3DXVECTOR3(0.20f, 1.0f, 0.0f),    D3DXVECTOR3(0, 0, -1),  0.710f, 0.978f };
	m_WindVertex[14] = { D3DXVECTOR3(-0.30f, 1.0f, 0.0f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.978f };

	m_WindVertex[15] = { D3DXVECTOR3(-0.30f, 1.0f, 0.0f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.978f };
	m_WindVertex[16] = { D3DXVECTOR3(0.20f, 0.0f, 0.0f),   D3DXVECTOR3(0, 0, -1),  0.710f, 0.472f };
	m_WindVertex[17] = { D3DXVECTOR3(-0.30f, 0.0f, 0.0f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.472f };

	//날개 4번.(6시) 
	m_WindVertex[18] = { D3DXVECTOR3(-0.20f, -1.0f, 0.0f),  D3DXVECTOR3(0, 0, -1),  0.710f, 0.978f };
	m_WindVertex[19] = { D3DXVECTOR3(-0.20f,  0.0f, 0.0f),  D3DXVECTOR3(0, 0, -1),  0.710f, 0.472f };
	m_WindVertex[20] = { D3DXVECTOR3(0.30f, -1.0f, 0.0f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.978f };

	m_WindVertex[21] = { D3DXVECTOR3(0.30f, -1.0f, 0.0f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.978f };
	m_WindVertex[22] = { D3DXVECTOR3(-0.20f,  0.0f, 0.0f),  D3DXVECTOR3(0, 0, -1),  0.710f, 0.472f };
	m_WindVertex[23] = { D3DXVECTOR3(0.30f,  0.0f, 0.0f),   D3DXVECTOR3(0, 0, -1),  0.574f, 0.472f };

	//OBJECTINFO _info;

	//ZeroInfo(&_info);
	_info.Pollygon = PG_TRIANGLES;
	_info.fRadius = 1;
	//_info.vPos = D3DXVECTOR3(0, 0, 0);
	_info.vRot = D3DXVECTOR3(0, 0, 0);
	_info.vScale = D3DXVECTOR3(1, 1, 1);
	_info.Color = D3DXCOLOR(0, 0, 0, 1);
	_info.vDir = VEC3FORWARD;
	_info.nSize = sizeof(D3DFVF_XYZ_NORMAL_UV) * 12;
	_info.nTriangleCnt = 4;
	_info.dwFVF = D3DFVF_XYZ_NORMAL_UV::FVF;
	_info.m_bColl = true;
	_info.m_collInfo.fRadius = 1;
	_info.Color = D3DXCOLOR(1, 1, 1, 1);
	_info.pData = m_bodyVertex;
	baseObject::Init(_info);
	_info.nSize = sizeof(D3DFVF_XYZ_NORMAL_UV) * 24;
	_info.nTriangleCnt = 8;
	_info.pData = m_WindVertex;
	_info.vPos += D3DXVECTOR3(0, 4, -0.5);
	_info.vScale = D3DXVECTOR3(2, 2, 2);
	m_Wing.Init(_info);

}

void Windmill::Render()
{
	D3DMATERIAL9 material;
	ZeroMemory(&material, sizeof(material));
	
	material.Ambient = material.Diffuse = D3DXCOLOR(1, 1, 1, 1);

	DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_SELECTARG1);
	DEVICE->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DEVICE->SetRenderState(D3DRS_ALPHATESTENABLE, true);

	DEVICE->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	DEVICE->SetRenderState(D3DRS_ALPHAREF, DWORD(0.3f * 255));

	DEVICE->SetMaterial(&material);
	DEVICE->SetTexture(0, m_pTexture);
	baseObject::Render();
	m_Wing.Render();


	DEVICE->SetRenderState(D3DRS_LIGHTING, false); // 라이팅
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
}

void Windmill::Update(float dTime)
{
	baseObject::Update(dTime);
	m_Wing.Update(dTime);
	static float a;
	a = D3DXToRadian(90)*dTime;
	m_Wing.Rotate(D3DXVECTOR3(0, 0, a));
}

Windmill::Windmill()
{
}


Windmill::~Windmill()
{
}
