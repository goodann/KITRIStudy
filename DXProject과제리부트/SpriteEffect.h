#pragma once

struct spriteInfo {
	OBJECTINFO ObjInfo;
	string pTexName;//텍스처 이름
	int nSpriteCntX;//스플라이트 x갯수
	int nSpriteCntY;//스플라이트 y갯수
	float fTotalTime;//총 시간
	bool bLoop;//루프
	D3DCOLOR color;
};

class SpriteEffect :
	public Effect
{
private:
	int m_nTotalSpriteCnt;//총 갯수(x*y)
	int m_nCurrSpriteX;
	int m_nCurrSpriteY;
	int m_nCurrSpriteTotal;
	float m_fSpriteU;
	float m_fSpriteV;
	float m_fCurrTime;
	float m_fNextTime;
	float m_fAddTime;
	D3DXMATRIX m_mTexTrans;
	spriteInfo m_SpriteInfo;
public:
	void Init(spriteInfo _info);
	void Update(float dTime);
	void Render(void);
	void Release(void);
	SpriteEffect();
	~SpriteEffect();
};

