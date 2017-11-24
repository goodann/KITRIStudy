#include"IncludeAPI.h"



Vector2::Vector2() : x(0),y(0)
{
}

Vector2  Vector2::operator+(const Vector2 & right)
{
	Vector2 newVec(this->x + right.x, this->y + right.y);
	return newVec;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

Vector2 & Vector2::operator+=(const Vector2 & right)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	this->x += right.x;
	this->y += right.y;
	return (*this);
}


void Vector2::operator()(float _x, float _y)
{
	x = _x;
	y = _y;
}

Vector2::~Vector2()
{
}
