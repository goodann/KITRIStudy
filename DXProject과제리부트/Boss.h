#pragma once

class Boss :
	public Enemy
{
protected:
	D3DXVECTOR3 m_TPos;
public:
	Boss();
	void Update(float dTime);
	~Boss();
};

