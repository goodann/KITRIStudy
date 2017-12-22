#pragma once
class Terrain :
	public baseObject
{
	D3DFVF_XYZ_NORMAL_UV m_ground[15000];
	int m_fCount;
	float m_fSize;
public:
	void Init();
	void Render();
	Terrain();
	virtual ~Terrain();
};

