#pragma once
class DefaultBossMovingAI :
	public MovingAI
{
	int m_eventY; 
	bool m_horiMove;
	bool m_horiDir;
	myTimer m_MovingTimer;
	myTimer m_shottingTimer;
public:
	virtual void Update();
	DefaultBossMovingAI();
	~DefaultBossMovingAI();
};

