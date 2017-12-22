#include"GameCommon.h"



void UIButton::Init(string nor, string over, string click, int _x, int _y, void(*DelegateFunc)(void *), string Label)
{

	m_pTexture[BT_NORMAL] = TEXMGR->GetTexture(nor);
	m_pTexture[BT_OVER] = TEXMGR->GetTexture(over);
	m_pTexture[BT_CLICK] = TEXMGR->GetTexture(click);
	m_vPos.x = _x;
	m_vPos.y = _y;
	m_vScale.x = m_pTexture[BT_NORMAL]->GetWidth();
	m_vScale.y = m_pTexture[BT_NORMAL]->GetHeight();

	D3DFVF_XYZ_TEX1 vtxs[] =
	{
		{ D3DXVECTOR3(0,0,0), 0, 0 },
	{ D3DXVECTOR3(1,0,0), 1, 0 },
	{ D3DXVECTOR3(0,1,0), 0, 1 },
	{ D3DXVECTOR3(1,1,0), 1, 1 }
	};
	m_text.Init(FT_UI, D3DXCOLOR(1, 1, 1, 1), m_vScale.x / 2 - 24, m_vScale.y / 2 - 5, 256, 64);
	m_text.m_Text = Label;
	m_text.SetParent(this);
	DEVICE->CreateVertexBuffer(sizeof(vtxs), 0,
		D3DFVF_XYZ_TEX1::FVF, D3DPOOL_DEFAULT,
		&m_pVB, NULL);
	void* pData = NULL;
	m_pVB->Lock(0, sizeof(vtxs), &pData, 0);
	memcpy(pData, vtxs, sizeof(vtxs));
	m_pVB->Unlock();
	//m_text.Init(FT_BOADER, D3DXCOLOR(1, 1, 1, 1), 10, 10, 256, 64);
	m_pDelegateFunc = DelegateFunc;
}

void UIButton::Update(float dTime)
{
	D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);

	if (m_Parent)
		m_mTM = m_mScale * m_mTrans*(m_Parent->GetmTM());
	else
		m_mTM = m_mScale * m_mTrans;
}

void UIButton::Render(void)
{

	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);

	DEVICE->SetTexture(0, m_pTexture[m_enBTNType]->GetTexture());
	DEVICE->SetStreamSource(0, m_pVB, 0, sizeof(D3DFVF_XYZ_TEX1));
	DEVICE->SetFVF(D3DFVF_XYZ_TEX1::FVF);
	DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);

	DEVICE->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);
	DEVICE->SetTexture(0, NULL);
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);

}


void UIButton::Release(void)
{
	SAFE_RELEASE(m_pVB);
}


void UIButton::WndProc(HWND hWnd, UINT iMsg, WPARAM vParam, LPARAM lParam)
{

	switch (iMsg)
	{
	case WM_MOUSEMOVE:
		IsPtInRect(LOWORD(lParam), HIWORD(lParam));
		if (bIsPtInRect)
		{
			if (m_enBTNType != BT_CLICK)
				m_enBTNType = BT_OVER;
		}
		else
			if (m_enBTNType != BT_CLICK)
				m_enBTNType = BT_NORMAL;
		break;
	case WM_LBUTTONDOWN:
		if (bIsPtInRect)
			m_enBTNType = BT_CLICK;
		break;
	case WM_LBUTTONUP:
		if (bIsPtInRect) {
			if (m_enBTNType == BT_CLICK) {
				m_enBTNType = BT_OVER;
				if (m_pDelegateFunc)
					m_pDelegateFunc(m_pData);
			}
		}
		else {
			m_enBTNType = BT_NORMAL;
		}
		break;
	default:
		break;
	}

}

UIButton::UIButton()
{

	m_pDelegateFunc = nullptr;
	m_enBTNType = BT_NORMAL;
	m_pTexture[BT_CLICK] = nullptr;
	m_pTexture[BT_OVER] = nullptr;
	m_pTexture[BT_NORMAL] = nullptr;
	m_pVB = nullptr;

	m_vPos = D3DXVECTOR3(0, 0, 1);
	m_vScale = D3DXVECTOR3(0, 0, 1);
	bIsPtInRect = false;
	m_pData = nullptr;
}


UIButton::~UIButton()
{
	Release();
	SAFE_DELETE(m_pData);
}
