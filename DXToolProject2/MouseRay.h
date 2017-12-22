#pragma once
class MouseRay
{
public:
	D3DXVECTOR3 m_vPos;
	D3DXVECTOR3 m_vDir;
	void CreateViewSpaceRay(int x, int y);
	void RayTransform(D3DXMATRIX m);
public:
	MouseRay();
	virtual ~MouseRay();
};

