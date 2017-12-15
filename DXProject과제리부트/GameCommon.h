#pragma once

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "dinput8.lib")

#define DIRECTINPUT_VERSION 0x0800

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>

#include "d3dx9.h"
#include "d3d9.h"
#include "dinput.h"

#include <map>
#include <list>
#include <vector>
#include <string>
#include <time.h>
using namespace std;

// 메모리 해제 및 반환
#define SAFE_DELETE(p)			{ if(p) {delete p;		p = NULL;} }
#define SAFE_DELETE_ARRAY(p)    { if(p) {delete [] p;	p = NULL;} }
#define SAFE_RELEASE(p)			{ if(p) {p->Release();  p = NULL;} }

#define VEC3ZERO		D3DXVECTOR3(0,0,0)
#define VEC3ONE			D3DXVECTOR3(1,1,1)
#define VEC3FORWARD		D3DXVECTOR3(0,0,1)
#define VEC3UP		D3DXVECTOR3(0,1,0)
#define VEC3RIGHT		D3DXVECTOR3(1,0,0)


// 싱글턴패턴
#define SINGLETON_FUNC(mgr) \
private: static mgr* m_pInstance; \
public:	static mgr* GetInstance(void) \
{ \
	if (m_pInstance == NULL) \
		m_pInstance = new mgr; \
	return m_pInstance; \
} \
private: mgr(); \
public: ~mgr(); private: 

#define SINGLETON_INIT(mgr) mgr* mgr::m_pInstance = NULL;
#include "MySingleton.h"

//프로퍼티
#define PROPERTY_FUNC(_type, _funcName) \
protected: _type m_##_funcName; \
public: void Set##_funcName(_type _v) \
{ m_##_funcName = _v; } \
public: _type& Get##_funcName() \
{ return m_##_funcName; } \
private:

#define PROPERTY_FUNC2(_type, _funcName) \
protected: _type m_##_funcName; \
protected: _type m_Org##_funcName; \
public: void Set##_funcName(_type _v) \
{ m_##_funcName = m_Org##_funcName = _v; } \
public: _type& Get##_funcName() \
{ return m_##_funcName; } \
public: _type& GetOrg##_funcName() \
{ return m_Org##_funcName; } \
private:

#define GETTER(_type, _funcName) \
protected: _type m_##_funcName; \
public: _type& Get##_funcName() \
{ return m_##_funcName; } \
private:

#define SETTER(_type, _funcName) \
protected: _type m_##_funcName; \
public: void Set##_funcName(_type _v) \
{ m_##_funcName = _v; } \
private:

class baseObject;
struct COLLSPHEREINFO
{
	float			fRadius;
	D3DXVECTOR3		vPos;
	baseObject*		pTarget;
};

enum Pollygon { PG_VOID,PG_TRIANGLES, PG_SPHERE, PG_BOX, PG_CYLINDER, PG_TEAPOT, PG_TORUS,PG_FROMXFILE };


struct OBJECTINFO
{
	string			strName;

	D3DXVECTOR3		vPos;
	D3DXVECTOR3		vRot;
	D3DXVECTOR3		vScale;
	D3DXVECTOR3		vDir;
	D3DXCOLOR Color;
	D3DMATERIAL9 Material;
	enum Pollygon Pollygon;
	void*			pData;
	int				nSize;
	DWORD			dwFVF;
	int				nTriangleCnt;

	float fRadius;

	string FileName;
	baseObject* Parent;
	bool			m_bColl;
	COLLSPHEREINFO  m_collInfo;
};

void ZeroInfo(OBJECTINFO* info);


struct D3DFVF_XYZ_COLOR
{
	D3DXVECTOR3		vPos;
	DWORD			color;

	enum {FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};


struct D3DFVF_XYZ_NORMAL
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR3 vNormal;

	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL };
};

struct D3DFVF_XYZ_NORMAL_UV
{
	D3DXVECTOR3		vPos;
	D3DXVECTOR3 vNormal;
	float u;
	float v;

	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL| D3DFVF_TEX1 };
};
float fRandom(float max, float min);
POINT GetClientPoint(void);
#include"myTimer.h"
#include"MouseRay.h"
#include "Shotable.h"

#include "Transform.h"
#include "VertexTransform.h"
#include "MeshTransform.h"

#include "WorldAxis.h"
#include "WorldCamera.h"
#include "WorldGrid.h"
#include "FPSCamera.h"
#include "TargetCamera.h"


#include "MyTexture.h"
#include "TextureManager.h"

#include "baseObject.h"
#include "ShotableObject.h"
#include "CollisonSphere.h"
#include "CollisionManager.h"
#include "Windmill.h"

#include"Terrain.h"
#include "Effect.h"


#include "Enemy.h"
#include "Boss.h"

#include "Bullet.h"
#include "AirPlaneBoom.h"

#include "Tree.h"

#include "CubeObject.h"
#include "TrianglePlayer.h"
#include "AirPlane.h"


#include "Star.h"

#include "TankTop.h"
#include "TankBody.h"
#include "Tank.h"

#include "InputManager.h"
#include "DirectManager.h"
#include "GameManager.h"
#include "WindowManager.h"
#include "FontManager.h"
#include "FrameManager.h"


#define GAMEMGR		GameManager::GetInstance()
#define WINMGR		WindowManager::GetInstance()
#define DXMGR		DirectManager::GetInstance()
#define DEVICE		DXMGR->GetDevice()
#define INPUTMGR	InputManager::GetInstance()
#define FONTMGR	FontManager::GetInstance()
#define FRAMEMGR	FrameManager::GetInstance()
#define COLLMGR		CollisionManager::GetInstance()
#define TEXMGR TextureManager::GetInstance()
#define GRAVITY D3DXVECTOR3(0, -9.8f, 0)