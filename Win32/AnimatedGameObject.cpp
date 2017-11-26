#include"IncludeAPI.h"


void AnimatedGameObject::Init(std::wstring _name, int _x, int _y, int _w, int _h, DWORD color, float _time)
{
	GameObject::Init(_name, _x, _y, _w, _h, color);
	m_Timer.SetTimer(_time/((_w*_h)/(m_Pos.m_size.x)*(m_Pos.m_size.y)));
}

void AnimatedGameObject::Init(std::wstring _name, Vector2 _pos, Vector2 _size, DWORD color, float _time)
{
	GameObject::Init(_name, _pos,_size, color);
	m_Timer.SetTimer(_time / (
		(m_TotalSize.x*m_TotalSize.y) / ((m_Pos.m_size.x)*(m_Pos.m_size.y))));
}

void AnimatedGameObject::Render(HDC _backDC)
{
		m_Sprite->RenderSprite(_backDC,m_Pos.start(),m_Pos.m_size,m_texPos);
	if (m_Timer.TimeCheck()) {
		m_texPos.x += m_Pos.m_size.x;
		m_texPos.y += ((int)m_texPos.x/ (int)m_TotalSize.x) * m_Pos.m_size.y;
		m_texPos.x = ((int)m_texPos.x % (int)m_TotalSize.x);
		if (m_texPos.y >= m_TotalSize.y) {
			m_Life = false;
		}
	}
	
}


AnimatedGameObject::AnimatedGameObject()
{
	m_Timer.SetTimer(0.2f);
	m_texPos(0, 0);
}


AnimatedGameObject::~AnimatedGameObject()
{
}
