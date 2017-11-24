#pragma once
struct Vector2
{
	float x;
	float y;
	Vector2(float _x, float _y) :x(_x), y(_y) {};
	Vector2();
	Vector2 operator+(const Vector2& right);
	Vector2& operator+=(const Vector2& right);
	void operator() (float _x, float _y);
	~Vector2();
};

