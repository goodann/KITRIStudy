#include"IncludeAPI.h"

SINGLETON_INIT(SingletonSpriteManager)


SingletonSpriteManager::SingletonSpriteManager()
{
}


Sprite * SingletonSpriteManager::GetSprite(std::wstring _name, DWORD color)
{
	if (m_mapImages[_name] != NULL)
	{
		return m_mapImages[_name];
	}
	Sprite* pImage = nullptr;
	// 로드처음
	pImage = new Sprite;
	pImage->LoadSprite(m_ScreenDC, _name.c_str(), color);

	return (m_mapImages[_name] = pImage);
}

void SingletonSpriteManager::ReleaseSprite(void)
{
	for (auto itor = m_mapImages.begin();
		itor != m_mapImages.end(); ++itor)
	{
		Sprite* pImage = (*itor).second;
		delete pImage;
	}

	m_mapImages.clear();
}

SingletonSpriteManager::~SingletonSpriteManager()
{
}
