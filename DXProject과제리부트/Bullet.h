#pragma once
class Bullet:public baseObject
{
public:
	/*
	D3DFVF_XYZ_COLOR		m_arrVertex[36];

	D3DXVECTOR3				m_vPos;
	D3DXVECTOR3				m_vRot;
	D3DXVECTOR3				m_vScale;
	D3DXVECTOR3				m_vDir;
	D3DXVECTOR3				m_voldDir;
	
	

	D3DXMATRIX				m_mTrans;
	D3DXMATRIX				m_mRot;
	D3DXMATRIX				m_mScale;
	D3DXMATRIX				m_mTM;
	D3DXMATRIX* m_mpParentTM;

	float m_radius;
	*/
	D3DXVECTOR3 m_Gravity;
	//float m_speed;
	float m_angle;
	
	//bool m_Life;
	bool m_isTankBullet;

public:
	//virtual void Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _rot, D3DXVECTOR3 _scale);
	virtual void Init(OBJECTINFO _info);
	virtual void Update(float dtime);
	virtual void Render(void);
	void Release(void);
public:
	Bullet();
	virtual ~Bullet();
};

