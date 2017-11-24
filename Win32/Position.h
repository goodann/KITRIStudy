#pragma once

struct Position
{
	Vector2 m_pos;
	Vector2 m_size;

	inline float& x() { return m_pos.x; }
	inline float& y() { return m_pos.y; }
	inline float& width() { return m_size.x; }
	inline float& height() { return m_size.y; }
	inline float left() { return m_pos.x-m_size.x/2; }
	inline float right() { return m_pos.x+m_size.x/2; }
	inline float top() { return m_pos.y - m_size.y / 2;	}
	inline float bottom() { return m_pos.y + m_size.y / 2; }
	inline Vector2 start() { Vector2 vec(left(), top()); return vec; }
	inline Vector2 end() { Vector2 vec(right(), bottom()); return vec; }
	Position(float _x,float _y,float _w,float _h);
	Position();
	Position(Vector2 _pos ,Vector2 _size);
	~Position();
};

