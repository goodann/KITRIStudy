#pragma once

class MyTexture;
class MeshTransform :
	public Transform
{
	
protected:
	D3DMATERIAL9* m_pMaterials;
	MyTexture** m_ppTextures;

	D3DXVECTOR3 m_vPos;

	GETTER(DWORD, MaterialCount);


	LPD3DXMESH					m_pMesh;
	GETTER(float, fRadius);
	int m_index;
	D3DXVECTOR3 m_pivot;
public:
	void PathDivision(const char* _total, char* _path, char*_name);
	virtual void SetAddIndexedMatrix(int index,D3DXVECTOR3 _pivot,D3DXMATRIX* _pMat);


	virtual void Init(OBJECTINFO _info);
	virtual void Render(void);
	virtual void Release(void);
	MeshTransform();
	~MeshTransform();
};

