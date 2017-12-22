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

		d3dpp.BackBufferWidth = WINMGR->GetWidth();		// 백버퍼 넓이
		d3dpp.BackBufferHeight = WINMGR->GetHeight();	// 백버퍼 높이
		d3dpp.BackBufferCount = 1;						// 백버퍼 갯수(무조건 하나)
		d3dpp.Windowed = true;							// true(윈도우) false(전체모드)
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;		// 스왑종류
		d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE; // 무조건 그려라
		d3dpp.EnableAutoDepthStencil = TRUE;			// 깊이버퍼 사용 유무
		d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;		// 깊어버퍼 사용시만 셋팅

		m_D3D->CreateDevice(
			D3DADAPTER_DEFAULT,		// 비디오 어댑터 디폴트 모니터
			D3DDEVTYPE_HAL,			// 하드웨어
			WINMGR->GetHWND(),		// 연결한 윈도우 핸들
			D3DCREATE_HARDWARE_VERTEXPROCESSING, // 정점 처리방식(GPU)
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
