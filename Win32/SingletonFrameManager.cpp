#include"IncludeAPI.h"


SINGLETON_INIT(SingletonFrameManager);
void SingletonFrameManager::Init(void)
{
	m_FPSTimer.SetTimer(1.0f);
	m_LimitTimer.SetTimer(0.01f);
}
void SingletonFrameManager::Update(void)
{
	FpsCheck();
}
void SingletonFrameManager::FpsCheck(void)
{
	if (m_FPSTimer.TimeCheck())
	{
		m_iFPS = m_iFpsCount;
		m_iFpsCount = 0;
	}
	else
		m_iFpsCount++;
}
bool SingletonFrameManager::LimitFPS(void)
{
	if (m_LimitTimer.TimeCheck())
		return true;

	return false;
}
SingletonFrameManager::SingletonFrameManager()
{
	m_iFPS = 0;
	m_iFpsCount = 0;

	Init();
}


SingletonFrameManager::~SingletonFrameManager()
{
}
