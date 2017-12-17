#pragma once
class MyTexture
{
	GETTER(LPDIRECT3DTEXTURE9, Texture);
	GETTER(string, Name);
	GETTER(float, width);
	GETTER(float, Height);
public:
	//virtual void Init(string _info);
	//virtual void Init(ParticleInfo _info);
	//virtual void Update(float dTime);
	//virtual void Render(void);
	virtual void Release(void);
	void Init(string _name, D3DXCOLOR _color = D3DXCOLOR(-1, -1, -1, -1));
	//void Release(void);
	MyTexture();
	~MyTexture();
};

