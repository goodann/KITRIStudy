#pragma once
class SingletonFrameManager
{
	SINGLETON_FUNC(SingletonFrameManager);
public:

	myTimer		m_FPSTimer;
	myTimer		m_LimitTimer;

	int			m_iFPS;
	int			m_iFpsCount;

public:
	int GetFPS(void) { return m_iFPS; }

	void Init(void);
	void Update(void);
	void FpsCheck(void);
	bool LimitFPS(void);
};

