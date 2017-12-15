#pragma once
class Tree:public ShotableObject
{
public:
	static LPDIRECT3DTEXTURE9 m_Texture;
	D3DFVF_XYZ_NORMAL_UV		m_arrVertex[6];
	D3DMATERIAL9 m_Material;
	
	/*
	D3DXVECTOR3				m_vRot;
	D3DXVECTOR3				m_vScale;
	D3DXVECTOR3				m_vDir;
	D3DXVECTOR3				m_voldDir;

	D3DXMATRIX				m_mTrans;
	D3DXMATRIX				m_mRot;
	D3DXMATRIX				m_mScale;
	D3DXMATRIX				m_mTM;
	*/
	baseObject* m_Parent;
	
	LPD3DXMATRIX				m_pmParentTM;
	LPD3DXMATRIX				m_pmParentRot;
	LPD3DXMATRIX				m_pmParentPos;
	LPD3DXMATRIX				m_pmParentScale;
	
	D3DXMATRIX m_mParentInverse;
	D3DXMATRIX m_mRenTM;
	D3DXVECTOR3 m_vRollingRot;

	D3DXVECTOR3 CollisionVec;
	bool m_isDead;
	bool m_isDeading;
	int m_hp;
	float degree;
	float acc;
	float val;

	bool m_IsSomerSaulting;
	const float m_JumpPower = 20;
	float m_CurrentPower;
	const float m_Gravity=-9.8f;
	
public:
	//bool m_life;
	D3DXVECTOR3				m_vPos;

	//bool IsSphereCollision(D3DXVECTOR3 _targetPos, D3DXVECTOR3 _targetVal, float _targetRadius,string _tag="none",Tree** m_pDocking=nullptr);
	bool IsSphereCollision(baseObject* Object);
	float m_Radius;
	//void Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale);
	void Init(OBJECTINFO info);
	void Update(float dtime);
	void Render(void);
	void Release(void);
	void OnCollision(D3DXVECTOR3 _targetPos, D3DXVECTOR3 _targetAcc,string _tag, Tree** m_pDocking = nullptr);
	void OnCollision(baseObject* _Object, Tree** m_pDocking = nullptr);
	
	void SomerSault();
public:
	Tree();
	~Tree();
};

