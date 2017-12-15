#pragma once
class FrameManager
{
	SINGLETON_FUNC(FrameManager)
	DWORD m_dwDeltaTime;
	DWORD m_dwOldDeltaTime;

	
	DWORD m_dwFPSCount;
	DWORD m_dwOldFPS;

	GETTER(DWORD,FPS);
public:
	void Update();
	float GetDeltaTime() { return m_dwDeltaTime/1000.0f; }

};

