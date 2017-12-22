#pragma once
class Terrain :
	public baseObject
{
	D3DFVF_XYZ_NORMAL_UV2 m_ground[15000];
	PROPERTY_FUNC(int,fSize);
public:
	void Init();
	void Render();
	Terrain();
	virtual ~Terrain();
};

