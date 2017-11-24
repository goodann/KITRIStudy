#pragma once
class MovingAI
{
protected:
	Character* m_Target;
	float m_Speed;
public:
	virtual void Update() = 0;
	inline virtual void SetSpeed(float _speed) { m_Speed = _speed; }
	virtual void Init(Character* _target, float _speed) {
		m_Target = _target; m_Speed = _speed;
	}
	MovingAI();
	virtual ~MovingAI();
};

