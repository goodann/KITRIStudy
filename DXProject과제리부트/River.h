#pragma once
class River :
	public baseObject
{
	D3DFVF_XYZ_TEX1			m_arrVertex[4];
	MyTexture*				m_pTexture;
	MyTexture*				m_pTextureBump;
	float					m_fAngle;
	D3DXMATRIX				m_mRot;

	D3DXMATRIX				m_mTexTrans;
	float					m_fTexX;

public:
	void Init();
	void Update(float dTime);
	void Render(void);

public:
	River();
	virtual ~River();
};

