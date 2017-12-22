#pragma once
class WorldAxis
{
	float		m_fWidth;
	float		m_fHeight;

	D3DFVF_XYZ_COLOR m_arrVertexsX[3 * 6];
	D3DFVF_XYZ_COLOR m_arrVertexsY[3 * 6];
	D3DFVF_XYZ_COLOR m_arrVertexsZ[3 * 6];

public:
	void Setup(void);
	void Update(float dTime);
	void Render(void);
	void Destroy(void);

public:
	WorldAxis();
	virtual ~WorldAxis();
};

