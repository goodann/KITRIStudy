#pragma once
class Tank:public baseObject
{
public:
	TankBody m_Body;
	TankTop m_Top;
public:

	//D3DXMATRIX				m_mTrans;
	//D3DXMATRIX				m_mRot;
	//D3DXMATRIX				m_mScale;

	//D3DXVECTOR3				m_vPos;
	//D3DXVECTOR3				m_vRot;
	//D3DXVECTOR3				m_vScale;
	//D3DXVECTOR3				m_vDir;
	//D3DXVECTOR3				m_voldDir;
	D3DXVECTOR3				m_vRollingRot;


	//D3DXMATRIX				m_mTM;

	float m_targetRadius;
	float m_moveSpeed;
	float m_rotateSpeed;
	float m_Radius;
	float m_Mass;
	float m_JumpPower;
	float m_CurrentPower;
	bool m_isJumping;
	bool m_DownJumpKey;
	bool m_doubleJumping;
	bool m_isBoarding;
	D3DXVECTOR3 m_Gravity;
	D3DXMATRIX				m_mRenTM;
	
	
	Tree* m_pDocking;
public:
	void Init(void);
	void Update(float dtime);
	void Render(void);
	void Release(void);
public:
	Tank();
	~Tank();
};

