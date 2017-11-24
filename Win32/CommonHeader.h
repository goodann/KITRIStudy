#pragma once

#ifndef __COMMONHEADER_H__
#define __COMMONHEADER_H__


#pragma comment(lib, "msimg32.lib")
#pragma comment(lib, "winmm.lib")

#include <Windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<tchar.h>
#include <map>
#include <list>
#include <string>
#include <atlconv.h>

enum SCENETYPE{ST_START,ST_GAME,ST_GAMEOVER,ST_MAX};
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
#define MGR(__mgr)		__mgr::GetInstance();
#define SINGLETON_INIT(mgr) mgr* mgr::m_pInstance = NULL;

#define PI 3.1415926535897932
#define DEGREETORADIAN(_value) _value * PI / 180.0f;
#define ROOT2 1.41421f
#define GETKEY(key) ((GetAsyncKeyState(key) & 0x8000) == 0x8000)

#define GETKEYDOWN(key, value, func) \
if(value == false && (GetAsyncKeyState(key) & 0x8000) == 0x8000) \
{ \
	value = true; \
	func(); \
}\
if( value ) \
{ \
	if( (GetAsyncKeyState(key) & 0x8001) == 0x0000 )\
		value = false; \
}




#endif // !__COMMONHEADER_H__