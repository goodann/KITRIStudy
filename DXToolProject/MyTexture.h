#pragma once
class MyTexture
{
	GETTER(LPDIRECT3DTEXTURE9, Texture);
	GETTER(string, Name);

public:
	void Init(string _name);
	void Release(void);
	MyTexture();
	~MyTexture();
};

