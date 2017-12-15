#pragma once
class DirectManager
{
	SINGLETON_FUNC(DirectManager)
	LPDIRECT3D9 m_D3D;
	GETTER(LPDIRECT3DDEVICE9,D3DDevice);
	
public:
	void CreateDirect3D(void);
	void Release(void);
};

