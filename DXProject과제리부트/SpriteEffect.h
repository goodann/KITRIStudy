#pragma once

struct spriteInfo {
	OBJECTINFO ObjInfo;
	string pTexName;//�ؽ�ó �̸�
	int nSpriteCntX;//���ö���Ʈ x����
	int nSpriteCntY;//���ö���Ʈ y����
	float fTotalTime;//�� �ð�
	bool bLoop;//����
	D3DCOLOR color;
};

class SpriteEffect :
	public Effect
{
private:
	int m_nTotalSpriteCnt;//�� ����(x*y)
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

