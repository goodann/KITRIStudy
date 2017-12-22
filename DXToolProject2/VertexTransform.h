#pragma once

class VertexTransform :
	public Transform
{
protected:
	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	LPDIRECT3DINDEXBUFFER9 m_pIB;
	GETTER(int,nStrideSize);
	GETTER(DWORD,dwFVF);
	GETTER(int,nTriCnt);
	GETTER(int, nVerCnt);
	GETTER(int, nFaceCnt);
	GETTER(void*, pData);
	GETTER(void*, pInData);
public:
	virtual void Init(OBJECTINFO _info);
	virtual void Render(void);
	virtual void Release(void);
	virtual void Modifiy(void* data,int size,int start=0);

	VertexTransform();
	virtual ~VertexTransform();
};

