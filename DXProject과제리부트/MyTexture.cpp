#include"GameCommon.h"



void MyTexture::Init(string _name, D3DXCOLOR _color) {
	m_Name = _name;
	D3DXIMAGE_INFO _info;
	//if (_color.r == -1)
	//D3DXCreateTextureFromFile(DEVICE, m_Name.c_str(), &m_Texture);
	//else {
	D3DXCreateTextureFromFileEx(DEVICE, m_Name.c_str(),
		D3DFMT_UNKNOWN, D3DFMT_UNKNOWN, D3DFMT_UNKNOWN, D3DFMT_UNKNOWN, D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT, D3DX_FILTER_LINEAR, D3DX_DEFAULT, _color, &_info, nullptr,
		&m_Texture);
	//}
	if (m_Texture == nullptr) {
		char temp[50] = { 0, };
		sprintf(temp, "Texture Load File : %s ", m_Name.c_str());
		MessageBox(nullptr, temp, "Fail", MB_OK);
	}
	m_width = (float)_info.Width;
	m_Height = (float)_info.Height;
}

void MyTexture::Release(void)
{
	SAFE_RELEASE(m_Texture);
}

MyTexture::MyTexture()
{
	m_Texture = nullptr;
}


MyTexture::~MyTexture()
{
	Release();
}
