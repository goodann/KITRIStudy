#include"GameCommon.h"

SINGLETON_INIT(FrameManager)
FrameManager::FrameManager()
{
	m_dwDeltaTime=0;
	m_dwOldDeltaTime = timeGetTime();


	m_dwFPSCount=0;
	m_dwOldFPS = timeGetTime();
}


FrameManager::~FrameManager()
{
}

void FrameManager::Update()
{

	DWORD dwCurrTime = timeGetTime();

	if (dwCurrTime >= m_dwOldFPS + 1000) {
		m_FPS = m_dwFPSCount;
		m_dwFPSCount = 0;
		m_dwOldFPS = dwCurrTime;
	}else{
		m_dwFPSCount++;
	}
	//delta

	m_dwDeltaTime = dwCurrTime - m_dwOldDeltaTime;
	m_dwOldDeltaTime = dwCurrTime;
}
