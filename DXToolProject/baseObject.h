#pragma once
class CollisonSphere;
class baseObject:public Pickable
{
	GETTER(Pollygon, PollygonType);
public:
	Transform* GetTransform(void)
	{
		return m_Transform;
	}

protected:
	Transform*				m_Transform;

	// vb
	//LPDIRECT3DVERTEXBUFFER9		m_pVB;
	//int							m_nStrideSize;
	//DWORD						m_dwFVF;
	//int							m_nTriCnt;

	//// xmesh
	//LPD3DXMESH					m_pMesh;
	GETTER(float, fRadius);
	PROPERTY_FUNC(CollisonSphere*, pColl);
	PROPERTY_FUNC(float, Speed);
	PROPERTY_FUNC(bool, bLife);
	GETTER(string, FIleName);

public:
	string tag;
	virtual void Init(OBJECTINFO _info);
	virtual void Update(float dTime);
	virtual void Render(void);
	virtual void Release(void);
	virtual void OnCollisionHit(baseObject* pCollObj, float dTime, bool isForward = true) {};
	virtual bool PickingCheck(baseObject* Target, D3DXVECTOR3* pickPos, MouseRay ray);

public:
	baseObject();
	virtual ~baseObject();
};
