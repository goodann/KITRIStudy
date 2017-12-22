#include"GameCommon.h"



void UI::Init(int _x, int _y, string TextureName, bool* visibleOption,D3DXCOLOR _color, UI*_Parent )
{
	D3DFVF_XYZ_TEX1 vtxs[] = {
		{ D3DXVECTOR3(0,0,0),0,0 },
	{ D3DXVECTOR3(1,0,0),1,0 },
	{ D3DXVECTOR3(0,1,0),0,1 },
	{ D3DXVECTOR3(1,1,0),1,1 }

	};
	DEVICE->CreateVertexBuffer(sizeof(vtxs), 0, D3DFVF_XYZ_TEX1::FVF, D3DPOOL_DEFAULT, &m_pVB, nullptr);
	m_vPos = D3DXVECTOR3(_x, _y, 1);
	if (m_pVB) {
		void* pData;
		m_pVB->Lock(0, sizeof(vtxs), &pData, 0);
		memcpy(pData, vtxs, sizeof(vtxs));
		m_pVB->Unlock();
	}
	//m_pTexture=TEXMGR->GetTexture("UI/panel-info.png");
	m_pTexture = TEXMGR->GetTexture(TextureName, _color);
	m_vScale.x = m_pTexture->GetWidth();
	m_vScale.y = m_pTexture->GetHeight();
	m_vScale.z = 1;
	m_Parent = _Parent;
	m_bpVisible = visibleOption;
	

}

void UI::Update(float dTime)
{
	if (m_bpVisible)
		m_bVisible = *m_bpVisible;

	//m_vScale.x = m_pTexture->GetWidth();
	//m_vScale.y = m_pTexture->GetHeight();
	//m_vScale.z = 1;

	
	D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, m_vPos.z);
	//D3DXMatrixRotationYawPitchRoll(&m_mRot, m_vRot.y, m_vRot.x, m_vRot.z);
	D3DXMatrixScaling(&m_mScale, m_vScale.x, m_vScale.y, m_vScale.z);
	D3DXVECTOR3 pos;
	if (m_Parent) {
		D3DXVec3TransformCoord(&pos, &m_vPos, &m_Parent->GetmTM());
		D3DXMatrixTranslation(&m_mTrans, pos.x, pos.y, pos.z);
		m_mTM = m_mScale * m_mTrans;
		//D3DXMatrixTranslation(&m_mTrans, m_vPos.x, m_vPos.y, 0);
		//m_mTM = m_mScale*  m_mTrans * m_Parent->GetmTM();
		//m_mTM._11= m_vScale.x;
		//m_mTM._22 = m_vScale.y;
		//m_mTM._33=1;
		//m_mTM._44 = 1;
	}
	else
		m_mTM = m_mScale * m_mTrans;
}

void UI::Render(void)
{
	//DEVICE->SetRenderState(D3DRS_LIGHTING, false); // 라이팅
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, true);
	DEVICE->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	DEVICE->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	DEVICE->SetTexture(0, m_pTexture->GetTexture());
	DEVICE->SetStreamSource(0, m_pVB, 0, sizeof(D3DFVF_XYZ_TEX1));
	DEVICE->SetFVF(D3DFVF_XYZ_TEX1::FVF);
	DEVICE->SetTransform(D3DTS_WORLD, &m_mTM);

	DEVICE->DrawPrimitive(D3DPT_TRIANGLESTRIP, 0, 2);// (D3DPT_TRIANGLELIST, 12		m_arrVertex, sizeof(D3DFVF_XYZ_COLOR));

	DEVICE->SetTexture(0, nullptr);
	DEVICE->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	//DEVICE->SetRenderState(D3DRS_LIGHTING, true); // 라이팅

}

void UI::Release(void)
{

	SAFE_RELEASE(m_pVB);
}
bool UI::IsPtInRect(int _x, int _y)
{

	RECT rc;
	D3DXVECTOR3 vUIPos;
	if (m_Parent) {
		D3DXVec3TransformCoord(&vUIPos, &m_vPos, &m_Parent->GetmTM());
	}
	else {
		vUIPos = m_vPos;
	}
	SetRect(&rc, vUIPos.x, vUIPos.y, vUIPos.x + m_vScale.x, vUIPos.y + m_vScale.y);
	POINT pt;
	pt.x = _x;
	pt.y = _y;
	bIsPtInRect = PtInRect(&rc, pt);
	return false;
}



UI::UI()
{
	m_bVisible = true;
	m_pTexture = nullptr;
	m_pVB = NULL;
	m_vPos = D3DXVECTOR3(0, 0, 1);
	GAMEMGR->m_ListUI.push_back(this);
	m_bpVisible = nullptr;
	D3DXMatrixIdentity(&m_mTM);
	D3DXMatrixIdentity(&m_mScale);
	D3DXMatrixIdentity(&m_mTrans);
}


UI::~UI()
{
	GAMEMGR->m_ListUI.remove(this);
	Release();
}
