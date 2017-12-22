#include"GameCommon.h"



void MyTexture::Init(string _name)
{
	m_Name = _name;
	D3DXCreateTextureFromFile(DEVICE, m_Name.c_str(), &m_Texture);
	if (m_Texture == nullptr) {
		char temp[50] = { 0, };
		sprintf(temp, "Texture Load File : %s ", m_Name.c_str());
		MessageBox(nullptr, temp, "Fail", MB_OK);
	}
}

void MyTexture::Release(void)
{
	SAFE_RELEASE(m_Texture);
}

MyTexture::MyTexture()
{
}


MyTexture::~MyTexture()
{
	Release();
}
