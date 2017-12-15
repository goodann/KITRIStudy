#pragma once

#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "d3dx9.lib")
#pragma comment(lib, "d3d9.lib")

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<tchar.h>

#include <map>
#include <list>
#include <string>

#include<d3dx9.h>
#include<d3d9.h>



using namespace std;

#define ROOT2 1.41421f
#define API_PI 3.1415f

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


//프로퍼티
#define PROPERTY_FUNC(_type, _funcName) \
protected: _type m_##_funcName; \
public: void Set##_funcName(_type _v) \
{ m_##_funcName = _v; } \
public: _type Get##_funcName() \
{ return m_##_funcName; } \
private:

#define GETTER(_type, _funcName) \
protected: _type m_##_funcName; \
public: _type Get##_funcName() \
{ return m_##_funcName; } \
private:

#define SETTER(_type, _funcName) \
protected: _type m_##_funcName; \
public: void Set##_funcName(_type _v) \
{ m_##_funcName = _v; } \
private:

//메모리 해제 및 반환 
#define SAFE_DELETE(_p)\
{\
if(_p){\
delete _p; \
_p=nullptr;\
}\
}

#define SAFE_DELETE_ARRAY(_p)\
{\
if(_p){\
delete[] _p; \
_p=nullptr;\
}\
}

#define SAFE_RELEASE(_p)\
{\
if(_p){\
_p->Release(); \
_p=nullptr;\
}\
}

#include "DirectManager.h"
#include"GameManager.h"
#include"WindowManager.h"

#define GAMEMGR		GameManager::GetInstance()
#define WINMGR		WindowManager::GetInstance()
#define DXMGR		DirectManager::GetInstance()
#define DXDEV DXMGR->GetD3DDevice()