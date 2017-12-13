#include "GameCommon.h"


void myTimer::SetTimer(float _timeSecond)
{
	m_nDelayTime = int(_timeSecond * 1000);
	m_dwOldTime = timeGetTime();
}

bool myTimer::TimeCheck(void)
{
	m_dwCurrTime = timeGetTime();

	if (m_dwCurrTime > m_dwOldTime + m_nDelayTime)
	{
		m_dwOldTime = m_dwCurrTime;
		return true;
	}

	return false;
}

myTimer::myTimer()
{
}


myTimer::~myTimer()
{
}
