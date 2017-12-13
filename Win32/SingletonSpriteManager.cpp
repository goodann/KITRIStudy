#include"IncludeAPI.h"

SINGLETON_INIT(SingletonSpriteManager)


SingletonSpriteManager::SingletonSpriteManager()
{
	FILE* fp;
	//int idx = 0;
	_wfopen_s(&fp, _T("Resource/Sprites.txt"), _T("r+"));
	wchar_t buffer[1024] = { 0, };


	bool _isColor;
	bool _isTex;
	std::wstring _name;
	WORD _ColorR, _ColorG, _ColorB;
	WORD _TexX,_TexY;


	while (true) {
		//fwprintf(fp,_T("%s/%s/%d/%d/%d/%s/%d/%d"))
		fgetws(buffer, 1024, fp);
		int idx = 0;
		std::wstring buffer2 = buffer;
		std::wstring str;
		
		idx = buffer2.find_first_of(_T("/"));
		str = buffer2.substr(0, idx);
		buffer2 = buffer2.substr(idx + 1);

		_name = str;
		idx = buffer2.find_first_of(_T("/"));
		str = buffer2.substr(0, idx);
		buffer2 = buffer2.substr(idx + 1);
		if (str == _T("true")) {
			_isColor = true;
			
			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);

			_ColorR = _ttoi(str.c_str());
			//str = buffer2.Tokenize(_T("/"), idx);
			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);
			
			_ColorG = _ttoi(str.c_str());
			
			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);

			_ColorB = _ttoi(str.c_str());
		}
		else {
			_isColor = false;
			
			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);

			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);

			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);

			_ColorR = 0;
			_ColorG = 0;
			_ColorB = 0;
		}

		idx = buffer2.find_first_of(_T("/"));
		str = buffer2.substr(0, idx);
		buffer2 = buffer2.substr(idx + 1);

		if (str == _T("true")) {
			_isTex = true;
			
			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);

			_TexX = _ttoi(str.c_str());
			
			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);


			_TexY = _ttoi(str.c_str());
		}
		else {
			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);
			idx = buffer2.find_first_of(_T("/"));
			str = buffer2.substr(0, idx);
			buffer2 = buffer2.substr(idx + 1);
			_TexX = 0;
			_TexY = 0;
			_isTex = false;
		}
		Sprite* pImage = nullptr;
		// 로드처음
		pImage = new Sprite;
		m_ScreenDC = GetDC(WINMGR->GetHWND());
		if (_isTex) {
			pImage->LoadSprite(m_ScreenDC, _name.c_str(),Vector2(_TexX,_TexY),_isColor, RGB(_ColorR, _ColorG, _ColorB));
		}
		else {
			pImage->LoadSprite(m_ScreenDC, _name.c_str(), _isColor, RGB(_ColorR, _ColorG, _ColorB));
		}
		ReleaseDC(WINMGR->GetHWND(),m_ScreenDC);
		m_mapImages[_name] = pImage;
		if (feof(fp))
			break;
	}

	fclose(fp);

}


//Sprite * SingletonSpriteManager::GetSprite(std::wstring _name, DWORD color)
//{
//	if (m_mapImages[_name] != NULL)
//	{
//		return m_mapImages[_name];
//	}
//	Sprite* pImage = nullptr;
//	// 로드처음
//	pImage = new Sprite;
//	pImage->LoadSprite(m_ScreenDC, _name.c_str(), color);
//
//	return (m_mapImages[_name] = pImage);
//}

Sprite * SingletonSpriteManager::GetSprite(std::wstring _name)
{

	if (m_mapImages[_name] != NULL)
	{
		return m_mapImages[_name];
	}
	Sprite* pImage = nullptr;
	// 로드처음
	pImage = new Sprite;
	pImage->LoadSprite(m_ScreenDC, _name.c_str());

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
