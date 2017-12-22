#include "GameCommon.h"

SINGLETON_INIT(DirectManager)

DirectManager::DirectManager()
{
}


DirectManager::~DirectManager()
{
	Release();
}

void DirectManager::CreateDirect3D(void)
{
	m_D3D = Direct3DCreate9(D3D_SDK_VERSION);

	if (m_D3D)
	{
		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(d3dpp));

		d3dpp.BackBufferWidth = WINMGR->GetWidth();		// ����� ����
		d3dpp.BackBufferHeight = WINMGR->GetHeight();	// ����� ����
		d3dpp.BackBufferCount = 1;						// ����� ����(������ �ϳ�)
		d3dpp.Windowed = true;							// true(������) false(��ü���)
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// ��������
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // ������ �׷���
		d3dpp.EnableAutoDepthStencil = TRUE;			// ���̹��� ��� ����
		d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;		// ������ ���ø� ����

		m_D3D->CreateDevice(
			D3DADAPTER_DEFAULT,		// ���� ����� ����Ʈ �����
			D3DDEVTYPE_HAL,			// �ϵ����
			WINMGR->GetHWND(),		// ������ ������ �ڵ�
			D3DCREATE_HARDWARE_VERTEXPROCESSING, // ���� ó�����(GPU)
			&d3dpp, &m_Device
		);

		if( m_Device == NULL )
			MessageBox(NULL, "CreateDevice Fail", "fail", MB_OK);
	}
	else
		MessageBox(NULL, "CreateD3D Fail", "fail", MB_OK);
}

void DirectManager::Release(void)
{
	SAFE_RELEASE(m_Device);
	SAFE_RELEASE(m_D3D);
}
