#include"GameCommon.h"



void VertexTransform::Init(OBJECTINFO _info)
{
	Transform::Init(_info);
	m_pData = _info.pData;
	m_pInData = _info.pIndecs;
	m_nVerCnt = _info.VertexCnt;
	//m_nFaceCnt=_info.
	if (_info.pIndecs != nullptr) {
		DEVICE->CreateIndexBuffer(_info.nIbSize, 0, D3DFMT_INDEX32, D3DPOOL_DEFAULT, &m_pIB, 0);
		if (m_pIB) {
			void* pData = NULL;
			m_pIB->Lock(0, _info.nIbSize, &pData, 0);
			memcpy(pData, m_pInData, _info.nIbSize);
			m_pIB->Unlock();
		}
	}
	m_nStrideSize = _info.nSize / _info.nTriangleCnt / 3;
	m_dwFVF = _info.dwFVF;
	m_nTriCnt = _info.nTriangleCnt;


	DEVICE->CreateVertexBuffer(_info.nSize, 0,	_info.dwFVF, D3DPOOL_DEFAULT, &m_pVB, NULL);

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
	
	DEVICE->SetFVF(m_dwFVF);
	if (m_pIB == nullptr) {
		DEVICE->SetStreamSource(0, m_pVB, 0, m_nStrideSize);
		DEVICE->DrawPrimitive(D3DPT_TRIANGLELIST, 0, m_nTriCnt);
	}
	else {
		DEVICE->SetStreamSource(0, m_pVB, 0, sizeof(D3DFVF_XYZ_NORMAL_UV));
		DEVICE->SetIndices(m_pIB);
		//DEVICE->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_nVerCnt, 0, m_nTriCnt);
		DEVICE->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, m_nVerCnt, 0, m_nTriCnt);
		//DEVICE->DrawPrimitive(D3DPT_TRIANGLELIST, 0, m_nTriCnt);
	}
}

void VertexTransform::Release(void)
{
	SAFE_RELEASE(m_pVB);
}

void VertexTransform::Modifiy(void * data, int size,int start)
{
	if (m_pVB)
	{
		void* pData = NULL;
		m_pVB->Lock(0, size, &pData, 0);
		memcpy(((BYTE*)pData+ start), data, size);
		m_pVB->Unlock();
	}
}


VertexTransform::VertexTransform()
{
	m_pVB = nullptr;
	m_pIB = nullptr;
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
