#pragma once

class VertexTransform :
	public Transform
{
protected:
	LPDIRECT3DVERTEXBUFFER9		m_pVB;
	GETTER(int,nStrideSize);
	GETTER(DWORD,dwFVF);
	GETTER(int,nTriCnt);
	GETTER(void*, pData);
public:
	virtual void Init(OBJECTINFO _info);
	virtual void Render(void);
	virtual void Release(void);

	VertexTransform();
	virtual ~VertexTransform();
};

