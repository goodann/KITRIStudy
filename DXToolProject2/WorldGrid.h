#pragma once

class WorldGrid
{
public:
	D3DFVF_XYZ_COLOR*				m_pFVFVertexs;
	int								m_iLineCount;
	int								m_iTileXCount;
	int								m_iTileInterval;
	

	void Setup(void);
	void Render(void);
	void Destroy(void);

public:
	WorldGrid(void);
	virtual ~WorldGrid(void);
};
