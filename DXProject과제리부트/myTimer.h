#pragma once
class myTimer
{
	DWORD m_dwOldTime		= 0;
	DWORD m_dwCurrTime		= 0;
	int	  m_nDelayTime		= 0;

public:
	void SetTimer(float _timeSecond);
	bool TimeCheck(void);

public:
	myTimer();
	~myTimer();
};

