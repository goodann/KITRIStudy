#pragma once
class TrianglePlayer :public baseObject
{
public:
	//D3DFVF_XYZ_COLOR		m_arrVertex[6];
	//D3DFVF_XYZ_COLOR		m_dirLine[2];
	//LPD3DXMESH m_pMesh;
	//D3DMATERIAL9 m_Material;
	/*
	D3DXVECTOR3				m_vPos;
	D3DXVECTOR3				m_vRot;
	D3DXVECTOR3				m_vScale;
	D3DXVECTOR3				m_vDir;
	D3DXVECTOR3				m_voldDir;

	D3DXMATRIX				m_mTrans;
	D3DXMATRIX				m_mRot;
	D3DXMATRIX				m_mScale;
	D3DXMATRIX				m_mTM;
	*/
	myTimer m_clockingTimer;
	bool m_isClocking;
	CubeObject m_head;
	CubeObject m_LArm;
	CubeObject m_RArm;
	CubeObject m_Body;
	CubeObject m_LLeg;
	CubeObject m_RLeg;

	CubeObject m_Buff;
	float buffTheta;
	bool m_isWheelWind;

	

	float m_targetRadius;
	D3DXVECTOR3 m_targetPos;

	list<Bullet*> m_bullet;
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_Radius;


	float m_Mass;
	float m_JumpPower;
	float m_CurrentPower;
	bool m_isJumping;
	bool m_DownJumpKey;
	bool m_doubleJumping;
	bool m_ArmDowning;
	bool m_isBuff;
	float m_BuffTime;
	bool m_isDocking;
	D3DXVECTOR3 m_Gravity;
	D3DXMATRIX				m_mRenTM;
	D3DXVECTOR3				m_vRollingRot;
	D3DXVECTOR3 m_VoidHand;
	D3DXVECTOR3 m_Hand;

	Tree* m_pDocking;


	bool IsSphereCollision(D3DXVECTOR3 _targetPos, float _targetRadius);
	bool IsSphereCollision(D3DXVECTOR3 _aPos, float _aRadius,D3DXVECTOR3 _targetPos, float _targetRadius);
	bool IsSphereCollision();
public:
	bool m_isBoarding;
	void Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale);
	void Update(float dtime);
	void Render(void);
	void Release(void);

public:
	TrianglePlayer();
	~TrianglePlayer();
};

