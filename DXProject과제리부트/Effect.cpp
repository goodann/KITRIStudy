#include"GameCommon.h"



float Effect::fRandom(float _min, float _max)
{
	int nMin = (int)(_min * 100);
	int nMax = (int)(_max * 100);
	if (_max - _min < 0)
		return 0;
	float v = (float)(rand() % (nMax - nMin)) + nMin;
	return (v / 100.0f);
}

D3DXVECTOR3 Effect::fRandomVec3(D3DXVECTOR3 _min, D3DXVECTOR3 _max)
{
	int nMinx = (int)(_min.x * 100);
	int nMaxx = (int)(_max.x * 100);
	int nMiny = (int)(_min.y * 100);
	int nMaxy = (int)(_max.y * 100);
	int nMinz = (int)(_min.z * 100);
	int nMaxz = (int)(_max.z * 100);
	float vx = 0;
	float vy = 0;
	float vz = 0;
	if (nMaxx - nMinx != 0)
		vx = (float)(rand() % (nMaxx - nMinx)) + nMinx;
	if (nMaxy - nMiny != 0)
		vy = (float)(rand() % (nMaxy - nMiny)) + nMiny;
	if (nMaxz - nMinz != 0)
		vz = (float)(rand() % (nMaxz - nMinz)) + nMinz;
	return D3DXVECTOR3((vx / 100.0f), (vy / 100.0f), (vz / 100.0f));
}

Effect::Effect()
{
}


Effect::~Effect()
{
}
