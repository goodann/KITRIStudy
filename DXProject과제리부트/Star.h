#pragma once
class Star
{

	D3DFVF_XYZ_COLOR		m_arrVertex[9];

	D3DXVECTOR3				m_vPos;
	D3DXVECTOR3				m_vRot;
	D3DXVECTOR3				m_vScale;
	D3DXVECTOR3				m_vDir;
	D3DXVECTOR3				m_voldDir;

	D3DXMATRIX				m_mTrans;
	D3DXMATRIX				m_mRot;
	D3DXMATRIX				m_mScale;
	D3DXMATRIX				m_mTM;
	float m_angle;

public:
	void Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale);
	void Update(float dtime);
	void Render(void);
	void Release(void);

public:
	Star();
	~Star();
};

