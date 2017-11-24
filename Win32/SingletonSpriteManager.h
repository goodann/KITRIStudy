#pragma once
class SingletonSpriteManager
{
	SINGLETON_FUNC(SingletonSpriteManager)
	HDC m_ScreenDC;
	std::map<std::wstring, Sprite*>		m_mapImages;


public:
	void SetScreenDC(HDC _HDC) { m_ScreenDC = _HDC; }
	int GetSpriteCount(void) { return (int)m_mapImages.size(); }

	Sprite* GetSprite(std::wstring _name, DWORD color = -1);
	void ReleaseSprite(void);
};

