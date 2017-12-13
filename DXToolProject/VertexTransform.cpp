#include"GameCommon.h"



void VertexTransform::Init(OBJECTINFO _info)
{
	Transform::Init(_info);
	m_pData = _info.pData;

	m_nStrideSize = _info.nSize / _info.nTriangleCnt / 3;
	m_dwFVF = _info.dwFVF;
	m_nTriCnt = _info.nTriangleCnt;


	DEVICE->CreateVertexBuffer(_info.nSize, 0,
		_info.dwFVF, D3DPOOL_DEFAULT, &m_pVB, NULL);

	if (m_pVB)
	{
		void* pData = NULL;
		m_pVB->Lock(0, _info.nSize, &pData, 0);
		memcpy(pData, _info.pData, _info.nSize);
		m_pVB->Unlock();
	}
	else
	{
		char tmp[128] = { 0, };
		sprintf(tmp, "버텍스버퍼 생성실패:%s", _info.strName.c_str());
		MessageBox(NULL, tmp, "error", MB_OK);
	}
	
}

void VertexTransform::Render(void)
{
	DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);
	DEVICE->SetStreamSource(0, m_pVB, 0, m_nStrideSize);
	DEVICE->SetFVF(m_dwFVF);
	DEVICE->DrawPrimitive(D3DPT_TRIANGLELIST,0, m_nTriCnt);
}

void VertexTransform::Release(void)
{
	SAFE_RELEASE(m_pVB);
}


VertexTransform::VertexTransform()
{
	m_pVB = nullptr;

	SetvPos(VEC3ZERO);
	SetvDir(VEC3FORWARD);
	SetvRot(VEC3ZERO);
	SetvScale(VEC3ONE);
	SetvRotAxis(VEC3ZERO);
}


VertexTransform::~VertexTransform()
{
	Release();
}
