#pragma once
class CubeObject : public baseObject
{
	//D3DFVF_XYZ_COLOR		m_arrVertex[36];
	//LPD3DXMESH m_pMesh;
	D3DMATERIAL9 m_Material;
	D3DXVECTOR3 m_vPiv;
	D3DXMATRIX m_mPiv;
public:
	//Transform* m_Trnasform;
	float m_scaleSize;
	D3DXMATRIX				m_mReTrans[2];
	D3DXMATRIX				m_mTrans;
	D3DXMATRIX				m_mRot;
	D3DXMATRIX				m_mScale;


	D3DXMATRIX				m_mPivotAxis;
	
	D3DXMATRIX				m_mPivotPoint;
	D3DXMATRIX				m_mInversPivotPoint;


	D3DXVECTOR3				m_vOriginPivotAxis;
	D3DXVECTOR3				m_vPivotAxis;
	D3DXVECTOR3				m_vPivotPoint;
	D3DXVECTOR3				m_vPos;
	D3DXVECTOR3				m_vRot;
	D3DXVECTOR3				m_vScale;
	
	baseObject* m_Parent;
	LPD3DXMATRIX m_ParentTM;

	D3DXMATRIX				m_mTM;
	float m_Radius;
	float m_degree;
	float m_WheelDegree;

	//D3DXVECTOR3				m_vDir;
	//D3DXVECTOR3				m_voldDir;
	
	bool m_up;
	bool m_isMoving;
	bool m_beingWheelWind;
	bool m_ArmDir;
	float m_limitPosiDegree;
	float m_limitNegaDegree;
	bool m_RotateDir;
	//void Init(D3DXVECTOR3 _pos= D3DXVECTOR3(0,0,0), D3DXVECTOR3 _Rot= D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 _scal= D3DXVECTOR3(1, 1, 1), D3DXCOLOR _color = D3DXCOLOR(0,0,0,1), LPD3DXMATRIX _pTM=nullptr);
	virtual void Init(OBJECTINFO _info);
	virtual void Update(float dTime);
	virtual void Render(void);
	virtual void Release(void);
public:
	CubeObject();
	~CubeObject();
};

