#pragma once
class Windmill :
	public baseObject
{
public:
	static LPDIRECT3DTEXTURE9 m_pTexture;
	D3DFVF_XYZ_NORMAL_UV m_bodyVertex[12];
	D3DFVF_XYZ_NORMAL_UV m_WindVertex[24];
	VertexTransform m_Wing;
public:
	virtual void Init(OBJECTINFO _info);
	virtual void Render();
	virtual void Update(float dTime);
	Windmill();
	virtual ~Windmill();
};

