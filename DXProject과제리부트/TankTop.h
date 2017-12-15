#pragma once
class Tank;
class TankTop : public baseObject
{
	//D3DFVF_XYZ_COLOR		m_arrVertex[36];
	//D3DFVF_XYZ_COLOR		m_VarrelArrVertex[36];
	list<Bullet*> m_bullet;

	LPD3DXMESH m_pMesh;
	LPD3DXMESH m_pVarrelMesh;
	D3DMATERIAL9 m_Material;
public:


	//D3DXMATRIX				m_mTrans;
	//D3DXMATRIX				m_mVTrans;
	//D3DXMATRIX				m_mRot;
	//D3DXMATRIX				m_mScale;

	//D3DXVECTOR3				m_vPos;
	//D3DXVECTOR3				m_vVPos;
	//D3DXVECTOR3				m_vRot;
	//
	//D3DXVECTOR3				m_vScale;
	//D3DXVECTOR3				m_vDir;
	//D3DXVECTOR3				m_voldDir;

	//LPD3DXVECTOR3				m_pvParentRot;


	//D3DXMATRIX				m_mTM;
	//D3DXMATRIX				m_mVTM;
	//
	//LPD3DXMATRIX m_pmParentTM;

	float m_targetRadius;
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_vRotateSpeed;
	//float m_Radius;
public:
	void Init(Tank* Parent);
	void Update(float dtime,bool m_isBoarding=true);
	void Render(void);
	void Release(void);
public:
	TankTop();
	~TankTop();
};

