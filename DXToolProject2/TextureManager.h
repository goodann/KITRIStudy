#pragma once
class TextureManager
{
	SINGLETON_FUNC(TextureManager)
		map<string, MyTexture*> m_mapTextures;
public:

	MyTexture* GetTexture(string _name);
	void Release(void);
	int GetTexutreCount(void) { return (int)m_mapTextures.size(); }

};

