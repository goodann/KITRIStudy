#include"IncludeAPI.h"



Position::Position(float _x, float _y, float _w, float _h)
{
	m_pos.x = _x;
	m_pos.y = _y;
	m_size.x = _w;
	m_size.y = _h;
}

Position::Position()
{
	m_pos.x = 0;
	m_pos.y = -1000;
	m_size.x = 0;
	m_size.y = 0;
}

Position::Position(Vector2 _pos, Vector2 _size)
{
	m_pos = _pos;
	m_size = _size;
}


Position::~Position()
{
}
