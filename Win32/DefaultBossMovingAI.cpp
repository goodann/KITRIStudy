#include"IncludeAPI.h"



void DefaultBossMovingAI::Update()
{
	Position& targetPos = m_Target->Position();
	if (m_Target->Position().m_pos.y < m_eventY) {
			m_Target->Position().m_pos.y += m_Speed/10;
	}
	else {
		if (!m_horiMove) {
			if (m_shottingTimer.TimeCheck()) {
				//m_horiMove = false;
				int seed = rand() % 100;
				m_horiDir = seed % 2;
				m_MovingTimer.SetTimer(1.0f + seed*0.01f);
				m_horiMove = true;
			}
		}
		else {
			if (m_horiDir)
				targetPos.m_pos.x += m_Speed;
			else
				targetPos.m_pos.x -= m_Speed;
			if (targetPos.left() > WINMGR->GetWidth())
				targetPos.m_pos.x -= WINMGR->GetWidth();
			if (targetPos.right() < 0) {
				targetPos.m_pos.x += WINMGR->GetWidth();
			}
			if(m_MovingTimer.TimeCheck() ){
				m_shottingTimer.SetTimer(5.0f);
				m_horiMove = false;
			}
		}
		
	}

	
}
	

DefaultBossMovingAI::DefaultBossMovingAI()
{
	srand(time(nullptr));
	m_horiMove = false;
	m_Speed = 20;
	m_eventY = 150;
	m_shottingTimer.SetTimer(5.0f);
}


DefaultBossMovingAI::~DefaultBossMovingAI()
{
}
