#pragma once
class Transform
{
protected:
	PROPERTY_FUNC(D3DXMATRIX, mTM);
	GETTER(D3DXMATRIX, mTrans);
	GETTER(D3DXMATRIX, mRot);
	GETTER(D3DXMATRIX, mScale);
	GETTER(D3DXMATRIX*, mpMat);

	PROPERTY_FUNC(D3DMATERIAL9,Material);
	PROPERTY_FUNC(D3DXCOLOR, Color);
	PROPERTY_FUNC2(D3DXVECTOR3, vPos);
	PROPERTY_FUNC2(D3DXVECTOR3, vDir);
	PROPERTY_FUNC2(D3DXVECTOR3, vUp);
	PROPERTY_FUNC2(D3DXVECTOR3, vRight);
	PROPERTY_FUNC(D3DXVECTOR3, vRot);
	PROPERTY_FUNC(D3DXVECTOR3, vScale);
	PROPERTY_FUNC(D3DXVECTOR3, vRotAxis);
	PROPERTY_FUNC(D3DXVECTOR3, vCollDir);
	PROPERTY_FUNC(float, fRadius);
public:
	void SetOrgvDir(D3DXVECTOR3 _a) { m_OrgvDir = _a; }
	virtual void Init(OBJECTINFO _info);
	virtual void Update(float dtime);
	virtual void Render(void) {};
	virtual void Release(void) {};
	void SetAddMatrix(D3DXMATRIX* _pMat);
	virtual void SetAddIndexedMatrix(int index,D3DXVECTOR3 _pivot, D3DXMATRIX* _pMat) {};
	void MoveForward(float speed, bool bColl = false);
	void Rotate(D3DXVECTOR3 vRot);
	void TargetTransform(baseObject* pTarget);
	Transform();
	virtual ~Transform();
};

