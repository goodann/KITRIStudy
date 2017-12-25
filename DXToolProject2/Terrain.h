#pragma once
class Terrain :
	public baseObject
{
	D3DFVF_XYZ_NORMAL_UV* m_Vertecs;
	int m_fCount;
	float m_fSize;
	int m_nTotalVertexCount;
	int m_nTotalFaceCnt;
	D3DINDEX* m_pDataIB;
public:
	void Init();
	void Render();

	void InitVB(int tileCnt);
	void InitIB(int tileCnt);
	void Up(int index);
	void UpRect(int index,int size);
	void UpCircle(int index, int size,D3DXVECTOR3 point);
	void UpHill(int index, int size,int height, D3DXVECTOR3 point);
	Terrain();
	virtual ~Terrain();
};

