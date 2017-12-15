#pragma once
class GameManager
{
	SINGLETON_FUNC(GameManager)

public:
	void DebugView(void);

public:
	void Init(void);
	void Update(void);
	void Render(void);
	void Release(void);
	void Loop(void);
};

