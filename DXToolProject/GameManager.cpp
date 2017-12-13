#include "GameCommon.h"

SINGLETON_INIT(GameManager)

void GameManager::Init(void)
{
	D3DXMatrixIdentity(&m_mTexTrans);
	m_vTexPos=D3DXVECTOR3(0,0,0);
	DEVICE->GetViewport(&m_OrgViewPort);
	//m_isFPS = false;
	m_CameraType = 0;
	D3DXCreateTextureFromFile(DEVICE, "Grass.jpg", &m_pGrassTexture);
	if (m_pGrassTexture == nullptr) {
		MessageBox(NULL, "texture load fail", "error", MB_OK);
	}
	D3DXCreateTextureFromFile(DEVICE, "Mask.bmp", &m_pMaskTexture);
	if (m_pMaskTexture == nullptr) {
		MessageBox(NULL, "texture load fail", "error", MB_OK);
	}
	D3DXCreateTextureFromFile(DEVICE, "Field1.dds", &m_pBottomTexture);
	if (m_pBottomTexture == nullptr) {
		MessageBox(NULL, "texture load fail", "error", MB_OK);
	}
	D3DXCreateTextureFromFile(DEVICE, "Water.jpg", &m_pWaterTexture);
	if (m_pWaterTexture == nullptr) {
		MessageBox(NULL, "texture load fail", "error", MB_OK);
	}
	D3DXCreateTextureFromFile(DEVICE, "Snow1.jpg", &m_pSnowTexture[0]);
	D3DXCreateTextureFromFile(DEVICE, "Snow2.jpg", &m_pSnowTexture[1]);
	D3DXCreateTextureFromFile(DEVICE, "Snow3.jpg", &m_pSnowTexture[2]);
	D3DXCreateTextureFromFile(DEVICE, "Snow4.jpg", &m_pSnowTexture[3]);
	D3DXCreateTextureFromFile(DEVICE, "Snow5.jpg", &m_pSnowTexture[4]);
	D3DXCreateTextureFromFile(DEVICE, "River.jpg", &m_pRiverTexture);
	
	m_sky = D3DXCOLOR(0.6f, 0.6f, 0.6f, 0);
	m_FireOn = false;
	m_TimeState = 2;
	D3DLIGHT9 Light;
	ZeroMemory(&Light, sizeof(Light));
	Light.Type = D3DLIGHTTYPE::D3DLIGHT_DIRECTIONAL;//태양광
	/*
	Light.Position = D3DXVECTOR3(0, 10, 0);
	Light.Range = 15.0f;


	Light.Phi = D3DXToRadian(80.0f);
	Light.Theta = D3DXToRadian(40.0f);

	Light.Falloff = 2.0f;

	D3DXVECTOR3 dir = D3DXVECTOR3(1, -1, 1);
	D3DXVec3Normalize(&dir,&dir);
	Light.Direction = dir;
	*/


	Light.Diffuse = D3DXCOLOR(1, 1, 1, 1);
	Light.Direction = D3DXVECTOR3(1, -1, 1);



	DEVICE->SetLight(0, &Light);
	DEVICE->LightEnable(0, true);
	DEVICE->SetRenderState(D3DRS_AMBIENT, D3DXCOLOR(0.2f, 0.2f, 0.2f, 1));
	
	m_Terrain = new Terrain;
	m_Terrain->Init();
	m_Axis.Setup();
m_Grid.Setup();



OBJECTINFO info;
ZeroMemory(&info, sizeof(info));
info.Pollygon = PG_FROMXFILE;
info.vScale = VEC3ONE;
info.FileName = "Resource/Airplane/airplane 2.x";
info.vPos = D3DXVECTOR3(0, 10, 0);

m_pAirPlane = new AirPlane;
m_pAirPlane->Init(info);


m_pCubeObject = new CubeObject;
//OBJECTINFO info;
ZeroMemory(&info, sizeof(info));
info.vScale = VEC3ONE;
info.Pollygon = PG_BOX;
info.Color = D3DXCOLOR(1, 1, 1, 1);
m_pCubeObject->Init(info);


m_WorldCamera.SetUp(D3DXVECTOR3(0, 10, -10));
FONTMGR->Setup();
}

void GameManager::Update(float dTime)
{
	INPUTMGR->Update();


	if (INPUTMGR->GetKeyUp(VK_SPACE))
	{
		m_bWire = !m_bWire;

		DEVICE->SetRenderState(D3DRS_FILLMODE,
			m_bWire ? D3DFILL_WIREFRAME : D3DFILL_SOLID);
	}
	if (INPUTMGR->GetKey('1')) {
		m_TimeState = 1;

	}
	if (INPUTMGR->GetKey('2')) {
		m_TimeState = 2;

	}
	if (INPUTMGR->GetKey('3')) {
		m_TimeState = 3;

	}
	if (INPUTMGR->GetKey('4')) {
		m_TimeState = 4;
	}
	if (INPUTMGR->GetKeyDown('8')) {
		if (m_Winter > 0)
			m_Winter--;
	}
	if (INPUTMGR->GetKeyDown('9')) {
		if (m_Winter < 5)
			m_Winter++;
	}
	if (INPUTMGR->GetKeyDown('0')) {
		m_CameraType++;
		if (m_CameraType >= 3)
			m_CameraType = 0;
		if (m_CameraType == 0) {
			m_WorldCamera.SetUp(D3DXVECTOR3(0, 10, -10));
		}
	}
	if (INPUTMGR->GetKeyUp('5')) {
		m_ToolMode++;
		if (m_ToolMode > 2)
			m_ToolMode = 0;

	}

	if (INPUTMGR->GetKeyUp('6')) {
		m_ModelMode++;
		if (m_ModelMode > 2)
			m_ModelMode = 0;

	}

	if (INPUTMGR->GetKeyDown(VK_LBUTTON)) {

		POINT pt;
		pt = GetClientPoint();
		MouseRay ray;
		ray.CreateViewSpaceRay((int)pt.x, (int)pt.y);
		D3DXMATRIX view;
		DEVICE->GetTransform(D3DTS_VIEW, &view);
		ray.RayTransform(view);

		for (auto& i : m_ListObj) {
			if (m_ToolMode != 0) {
				if (i->tag == "Terrain") {
					continue;
				}
			}
			MouseRay ray2 = ray;
			D3DXMATRIX m = i->GetTransform()->GetmTM();
			//ray2.RayTransform(m);
			if (i->PickingCheck(i, &m_ClickedPos, ray2)) {
				
				m_SelectedObject = i;
				m_bClicked = true;
				break;
			}
			else {
				m_bClicked = false;
				m_ClickedPos = D3DXVECTOR3(0, 0, 0);
			}
		}
		if (m_bClicked) {
			if (m_ToolMode == 0) {
				OBJECTINFO info;
				ZeroMemory(&info, sizeof(info));
				info.vPos = m_ClickedPos + VEC3UP * 2;
				info.vScale = VEC3ONE;
				info.Pollygon = PG_FROMXFILE;

				info.fRadius = 10;
				info.Color = D3DXCOLOR(1, 1, 1, 1);
				info.vDir = VEC3FORWARD;
				if (m_ModelMode == 0) {
					info.FileName = "Resource/Airplane/airplane 2.x";
				}
				if (m_ModelMode == 1) {
					info.FileName = "Resource/misc/car.x";
				}
				if (m_ModelMode == 2) {
					info.FileName = "Resource/misc/heli.x";
				}

				baseObject* newObj = new baseObject;
				newObj->Init(info);
			}
			else if (m_ToolMode == 1) {
				m_SelectedObject->SetbLife(false);
			}
		}

		//D3DXVECTOR3 aa = m_Terrain.GetPickPos(ray);
		//m_pCubeObject->m_vPos = aa;
		//if(D3DXVec3Length(&aa)>0.1)
		//m_debugVec3 = aa;
	}

	if (INPUTMGR->GetKey(VK_LBUTTON)) {
		if (m_ToolMode == 2) {
			if(m_SelectedObject)
				m_SelectedObject->GetTransform()->SetvPos(m_ClickedPos + VEC3UP * 2);
		}

	}
	if (INPUTMGR->GetKeyUp(VK_LBUTTON)) {
		m_SelectedObject = nullptr;
	}
	m_Axis.Update(dTime);

	//m_pTriPlayer->Update(dTime);
	//m_Tank->Update(dTime);
	//m_pCubeObject->Update(dTime);
	//m_Boss->Update(dTime);
	//m_pAirPlane->Update(dTime);

	for (auto& a : m_ListObj) {
		a->Update(dTime);
	}
	for (auto a = m_ListObj.begin(); a != m_ListObj.end();) {
		auto b = a;
		a++;
		if ((*b)->GetbLife() == false) {
			delete *b;
			m_ListObj.erase(b);
		}
	}
	m_vTexPos.x += dTime*0.01f;
	m_mTexTrans._31 = m_vTexPos.x;

}

void GameManager::Render(void)
{
	
	DEVICE->Clear(0,	// RECT CNT
		NULL, // RECT
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, // 클리어 타입(화면버퍼|깊이버퍼)
		m_sky,	// 타겟버퍼 클리어 색상
		1.0f, // 깊이버퍼 클리어 값(깊이값)
		0);   // 스텐실버퍼(반사, 그림자) 초기값

	DEVICE->BeginScene(); // 디바이스 그리겟다고 알림
	
	// 오브젝트 렌더코드
	//if(m_CameraType==2)
	//	m_TargetCamera.Render();
	//m_pTriPlayer->Render();
	//m_Tank->Render();
	////m_pCubeObject->Render();
	//m_Boss->Render();
	//m_pAirPlane->Render();


	//for (auto& a : m_Tree) {
	//	a->Render();
	//}
	for (auto& a : m_ListObj) {
		a->Render();
	}
	
	// HELPER
	m_Axis.Render();
	m_Grid.Render();
	///ground
	RenderBottom();
	RenderRiver();

	///
	DebugView();
	DEVICE->GetTransform(D3DTS_VIEW, &m_OrgView);
	ViewPortMinimap();

	DEVICE->Clear(0,	// RECT CNT
		NULL, // RECT
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, // 클리어 타입(화면버퍼|깊이버퍼)
		m_sky,	// 타겟버퍼 클리어 색상
		1.0f, // 깊이버퍼 클리어 값(깊이값)
		0);   // 스텐실버퍼(반사, 그림자) 초기값

	DEVICE->BeginScene(); // 디바이스 그리겟다고 알림

						  // 오브젝트 렌더코드
	
	for (auto& a : m_ListObj) {
		a->Render();
	}

	m_Axis.Render();
	m_Grid.Render();

	RenderBottom();
	RenderRiver();



	DEVICE->SetViewport(&m_OrgViewPort);
	DEVICE->SetTransform(D3DTS_VIEW, &m_OrgView);

	DEVICE->EndScene(); // 디바이스 다그렸다고 알림

	DEVICE->Present(NULL, NULL, NULL, NULL);
	
}

void GameManager::RenderBottom(void)
{
	

}

void GameManager::RenderRiver(void)
{
	D3DFVF_XYZ_NORMAL_UV m_River[6];
	m_River[0].vPos = { -25,0,6 };
	m_River[0].u = 0;
	m_River[0].v = 0;
	m_River[1].vPos = { 25,0,6 };
	m_River[1].u = 1;
	m_River[1].v = 0;
	m_River[2].vPos = { -25,0,-6 };
	m_River[2].u = 0;
	m_River[2].v = 1;
	m_River[3].vPos = { -25,0,-6 };
	m_River[3].u = 0;
	m_River[3].v = 1;
	m_River[4].vPos = { 25,0,6 };
	m_River[4].u = 1;
	m_River[4].v = 0;
	m_River[5].vPos = { 25,0,-6 };
	m_River[5].u = 1;
	m_River[5].v = 1;
	for (int i = 0; i < 6; i++) {
		m_River[i].vNormal = D3DXVECTOR3(0, 1, 0);
	}
	DEVICE->SetTexture(0, m_pWaterTexture);
	//DEVICE->SetTexture(0, m_pRiverTexture);

	//DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_SELECTARG1);
	DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);

	DEVICE->SetFVF(D3DFVF_XYZ_NORMAL_UV::FVF);
	DEVICE->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2);
	DEVICE->SetTransform(D3DTS_TEXTURE0, &m_mTexTrans);

	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, m_River, sizeof(D3DFVF_XYZ_NORMAL_UV));

	for (int i = 0; i<8; i++)
		DEVICE->SetTexture(i, nullptr);
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드

	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
	DEVICE->SetTexture(0, nullptr);
	DEVICE->SetTransform(D3DTS_TEXTURE0, &m);
	//DEVICE->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_DISABLE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	DEVICE->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
}

void GameManager::Release(void)
{
}

void GameManager::Loop(void)
{
	FRAMEMGR->Update();
	float deltaTime = FRAMEMGR->GetDeltaTime();
	Update(deltaTime);
	Render();
}

void GameManager::ViewPortMinimap(void)
{
	D3DXMATRIX mView;
	//D3DXMatrixLookAtLH(&mView, &D3DXVECTOR3(0, 50, 0), &D3DXVECTOR3(0, 0, 0), &D3DXVECTOR3(0, 0, 1));
	D3DXVECTOR3 pos = m_pAirPlane->GetTransform()->GetvPos();
	D3DXVECTOR3 view = pos-m_pAirPlane->GetTransform()->GetvDir()*pos.y;
	view.y = 0;
	D3DXMatrixLookAtLH(&mView, &pos, &view, &D3DXVECTOR3(0, 1, 0));
	DEVICE->SetTransform(D3DTS_VIEW, &mView);
	D3DVIEWPORT9 vp;
	vp.X = WINMGR->GetWidth()-200;
	vp.Y = 0;
	vp.Width = 200;
	vp.Height = 200;
	vp.MinZ = 0.0f;
	vp.MaxZ = 1.0f;
	DEVICE->SetViewport(&vp);
}

void GameManager::DebugView (void)
{
	int _x = 10;
	int _y = 10;
	char textBuffer[128] = { 0, };
	D3DXCOLOR _color = D3DXCOLOR(1, 1, 1, 1);
	DebugDis = D3DXVec3LengthSq(&(DebugVec1 - DebugVec2));
	//OutputDebugString(textBuffer);
	FONTMGR->DrawTextA(_x, _y, _color, "<디자인 툴 정보>");
	FONTMGR->DrawTextA(_x, _y += 15, _color, "-1.추가 2.삭제 3.변경 현재 모드 : %d",m_ToolMode+1);
	FONTMGR->DrawTextA(_x, _y, _color, "<모델 정보>");
	FONTMGR->DrawTextA(_x, _y += 15, _color, "-1.비행기 2.자동차 3.헬리콥터 - 현재 모델 : %d", m_ModelMode + 1);
	
	FONTMGR->DrawTextA(_x, _y += 15, _color, "충돌위치 (%.2f , %.2f , %.2f)", m_ClickedPos.x, m_ClickedPos.y, m_ClickedPos.z);
	FONTMGR->DrawTextA(_x, _y+=15, _color, m_bClicked?"클릭!":"대기중");
	FONTMGR->DrawTextA(_x, _y+=15, _color,"충돌위치 (%.2f , %.2f , %.2f)", m_ClickedPos.x, m_ClickedPos.y, m_ClickedPos.z);
	/*
	FONTMGR->DrawTextA(_x, _y, _color, "<플레이어 정보>");
	FONTMGR->DrawTextA(_x, _y += 15, _color, " -위치 (%.2f,%.2f,%.2f)",m_pTriPlayer->m_vPos.x, m_pTriPlayer->m_vPos.y, m_pTriPlayer->m_vPos.z);
	FONTMGR->DrawTextA(_x, _y += 15, _color, " -방향 (%.2f,%.2f,%.2f)", m_pTriPlayer->m_vDir.x, m_pTriPlayer->m_vDir.y, m_pTriPlayer->m_vDir.z);
	FONTMGR->DrawTextA(_x, _y += 15, _color, " -최종행렬");
	FONTMGR->DrawTextA(_x, _y += 15, _color, "  [%.2f, %.2f, %.2f, %.2f ]", m_pTriPlayer->m_mTM._11, m_pTriPlayer->m_mTM._12, m_pTriPlayer->m_mTM._13, m_pTriPlayer->m_mTM._14);
	FONTMGR->DrawTextA(_x, _y += 15, _color, "  [%.2f, %.2f, %.2f, %.2f ]", m_pTriPlayer->m_mTM._21, m_pTriPlayer->m_mTM._22, m_pTriPlayer->m_mTM._23, m_pTriPlayer->m_mTM._24);
	FONTMGR->DrawTextA(_x, _y += 15, _color, "  [%.2f, %.2f, %.2f, %.2f ]", m_pTriPlayer->m_mTM._31, m_pTriPlayer->m_mTM._32, m_pTriPlayer->m_mTM._33, m_pTriPlayer->m_mTM._34);
	FONTMGR->DrawTextA(_x, _y += 15, _color, "  [%.2f, %.2f, %.2f, %.2f ]", m_pTriPlayer->m_mTM._41, m_pTriPlayer->m_mTM._42, m_pTriPlayer->m_mTM._43, m_pTriPlayer->m_mTM._44);

	FONTMGR->DrawTextA(_x, _y += 15, _color, " -위치 (%.2f,%.2f,%.2f)",m_Tank->m_vPos.x, m_Tank->m_vPos.y, m_Tank->m_vPos.z);
	FONTMGR->DrawTextA(_x, _y += 15, _color, " -방향 (%.2f,%.2f,%.2f)", m_Tank->m_vDir.x, m_Tank->m_vDir.y, m_Tank->m_vDir.z);
	FONTMGR->DrawTextA(_x, _y += 15, _color, " -최종행렬");
	FONTMGR->DrawTextA(_x, _y += 15, _color, "  [%.2f, %.2f, %.2f, %.2f ]", m_Tank->m_mTM._11, m_Tank->m_mTM._12, m_Tank->m_mTM._13, m_Tank->m_mTM._14);
	FONTMGR->DrawTextA(_x, _y += 15, _color, "  [%.2f, %.2f, %.2f, %.2f ]", m_Tank->m_mTM._21, m_Tank->m_mTM._22, m_Tank->m_mTM._23, m_Tank->m_mTM._24);
	FONTMGR->DrawTextA(_x, _y += 15, _color, "  [%.2f, %.2f, %.2f, %.2f ]", m_Tank->m_mTM._31, m_Tank->m_mTM._32, m_Tank->m_mTM._33, m_Tank->m_mTM._34);
	FONTMGR->DrawTextA(_x, _y += 15, _color, "  [%.2f, %.2f, %.2f, %.2f ]", m_Tank->m_mTM._41, m_Tank->m_mTM._42, m_Tank->m_mTM._43, m_Tank->m_mTM._44);
	D3DXVECTOR3 DestPos = m_pCubeObject->m_vPos;
	DestPos -= m_pTriPlayer->m_vPos;
	
	DestPos = m_pTriPlayer->m_targetPos - m_pTriPlayer->m_vPos;

	float len = D3DXVec3Length(&DestPos);
	FONTMGR->DrawTextA(_x, _y += 15, _color, " -원점에서의 거리 (%.2f)", len);
	FONTMGR->DrawTextA(_x, _y += 15, _color, "충돌 (%s)", m_Collision?"충돌!":"충돌안됨");
	*/
}

void GameManager::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	if (m_CameraType==0) {
		m_WorldCamera.WndProc(hWnd, iMsg, wParam, lParam);
	}
}

GameManager::GameManager()
{
	m_Collision = false;
	m_bWire = false;
	m_pSnowTexture[0] = nullptr;
	m_pSnowTexture[1] = nullptr;
	m_pSnowTexture[2] = nullptr;
	m_pSnowTexture[3] = nullptr;
	m_pSnowTexture[4] = nullptr;
	DebugVec2 = DebugVec1 = VEC3ZERO;
	DebugDis = 0;
	m_Winter = 0;
	m_ToolMode = 0;
	m_ModelMode = 0;
	m_SelectedObject = nullptr;
}


GameManager::~GameManager()
{
	Release();
}



