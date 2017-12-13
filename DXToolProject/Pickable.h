#pragma once

class Pickable
{
	PROPERTY_FUNC(float, PickRadius);
protected:
	LPD3DXMESH m_CollSphere;
	D3DXVECTOR3 m_CollSpherePos;
	D3DXMATRIX				m_mTrans;
	D3DXVECTOR3				m_vPos;
	
	

public:
	void Init(OBJECTINFO _info);
	void Update(void);
	void Render();
	bool PickingSphereCheck(baseObject* Target, D3DXVECTOR3* pickPos, MouseRay ray);
	bool PickingTrianglesCheck(baseObject* Target, D3DXVECTOR3* pickPos, MouseRay ray);
	virtual bool PickingCheck(baseObject* Target, D3DXVECTOR3* pickPos, MouseRay ray)=0;
public:
	Pickable();
	~Pickable();
};

