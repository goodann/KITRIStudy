#include "GameCommon.h"

void ZeroInfo(OBJECTINFO * info)
{
	ZeroMemory(info, sizeof(*info));
	info->vPos = VEC3ZERO;
	info->vScale = VEC3ONE;
	info->vRot = VEC3ZERO;
	info->strName.resize(255);
	info->FileName.resize(255);
}


float fRandom(float max, float min)
{
	int _max = (int)(max * 100);
	int _min = (int)(min * 100);
	int r = rand() % (_max - _min) + _min;
	return (r / 100.0f);
}

POINT GetClientPoint(void)
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(WINMGR->GetHWND(), &pt);
	return pt;
	return POINT();
}
