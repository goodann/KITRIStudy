#include"IncludeAPI.h"



void DefaultMovingAI::Update()
{
	m_Target->Position().m_pos.y += m_Speed;
}

DefaultMovingAI::DefaultMovingAI()
{
	m_Speed = 5;
}


DefaultMovingAI::~DefaultMovingAI()
{
}
