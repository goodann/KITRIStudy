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
		dxParam.BackBufferWidth = WINMGR->GetWidth(); //����� ����
		dxParam.BackBufferHeight = WINMGR->GetHeight(); //����� ����
		dxParam.BackBufferCount = 1; //����� ����
		dxParam.Windowed = true;//â��� true ��üȭ�� false
		dxParam.SwapEffect = D3DSWAPEFFECT_DISCARD;//�������� ��ũ������<->����� �����ͽ���
		dxParam.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;//������ �׷���
		dxParam.EnableAutoDepthStencil = true;
		dxParam.AutoDepthStencilFormat = D3DFMT_D16;	//���̹��� ���ø���
		m_D3D->CreateDevice(D3DADAPTER_DEFAULT, //���� ����� ����Ʈ �����
			D3DDEVTYPE_HAL	//�ϵ����
			, WINMGR->GetHWND(), //������ ������ �ڵ�
			D3DCREATE_HARDWARE_VERTEXPROCESSING,//��÷ ó�����(GPU���)
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
