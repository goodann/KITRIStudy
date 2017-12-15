#pragma once
class Tank;
class TankBody:public CubeObject
{
	//D3DFVF_XYZ_COLOR		m_arrVertex[36];
	LPD3DXMESH m_pMesh;
	D3DMATERIAL9 m_Material;
public:
	

	D3DXMATRIX				m_mTrans;
	D3DXMATRIX				m_mRot;
	D3DXMATRIX				m_mScale;

	D3DXVECTOR3				m_vPos;
	D3DXVECTOR3				m_vRot;
	D3DXVECTOR3				m_vScale;
	//D3DXVECTOR3				m_vDir;
	//D3DXVECTOR3				m_voldDir;

	D3DXMATRIX				m_mTM;
	LPD3DXMATRIX m_pmRatentTM;

	float m_targetRadius;
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_Radius;
public:
	void Init(Tank* Parent);
	void Update(float dtime);
	void Render(void);
	void Release(void);
	TankBody();
	~TankBody();
};

