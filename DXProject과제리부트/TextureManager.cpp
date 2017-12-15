#include"GameCommon.h"

SINGLETON_INIT(TextureManager)

TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
	Release();
}

MyTexture * TextureManager::GetTexture(string _name)
{
	if (m_mapTextures[_name] != nullptr) {
		return m_mapTextures[_name];
	}
	MyTexture* pTexture = new MyTexture;
	pTexture->Init(_name);
	return (m_mapTextures[_name] = pTexture);
}

void TextureManager::Release(void)
{
	for (auto p : m_mapTextures) {
		SAFE_DELETE(p.second);
	}
	m_mapTextures.clear();
}
