#include"GameCommon.h"


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
	if (m_D3D) {
		D3DPRESENT_PARAMETERS dxParam;
		ZeroMemory(&dxParam, sizeof(dxParam));
		dxParam.BackBufferWidth = WINMGR->GetWidth(); //백버퍼 넓이
		dxParam.BackBufferHeight = WINMGR->GetHeight(); //백버퍼 높이
		dxParam.BackBufferCount = 1; //백버퍼 갯수
		dxParam.Windowed = true;//창모드 true 전체화면 false
		dxParam.SwapEffect = D3DSWAPEFFECT_DISCARD;//스왑종류 스크린버퍼<->백버퍼 포인터스왑
		dxParam.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;//무조건 그려라
		dxParam.EnableAutoDepthStencil = true;
		dxParam.AutoDepthStencilFormat = D3DFMT_D16;	//깊이버퍼 사용시만팅
		m_D3D->CreateDevice(D3DADAPTER_DEFAULT, //비디오 어댑터 디폴트 모니터
			D3DDEVTYPE_HAL	//하드웨어
			, WINMGR->GetHWND(), //연결한 윈도우 핸들
			D3DCREATE_HARDWARE_VERTEXPROCESSING,//정첨 처리방식(GPU사용)
			&dxParam, &m_D3DDevice);
			if (m_D3DDevice == nullptr) {
				MessageBox(NULL, _T("CreateDevice Fail"), _T("Fail"), MB_OK);
		}


	}
	else {
		MessageBox(NULL,_T("Create3D3Fail"),_T( "Fail"), MB_OK);
	}
	
}

void DirectManager::Release(void)
{
	SAFE_RELEASE(m_D3DDevice);
	SAFE_RELEASE(m_D3D);
}
