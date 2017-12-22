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
	D3DXCreateTextureFromFile(DEVICE, "tree.png", &Tree::m_Texture);
	if (Tree::m_Texture == nullptr) {
		MessageBox(NULL, "texture load fail", "error", MB_OK);
	}
	D3DXCreateTextureFromFile(DEVICE, "Water.jpg", &m_pWaterTexture);
	if (m_pWaterTexture == nullptr) {
		MessageBox(NULL, "texture load fail", "error", MB_OK);
	}
	D3DXCreateTextureFromFile(DEVICE, "White.png", &m_pWhiteTexture);
	if (m_pWhiteTexture == nullptr) {
		MessageBox(NULL, "texture load fail", "error", MB_OK);
	}
	
	D3DXCreateTextureFromFile(DEVICE, "Snow1.jpg", &m_pSnowTexture[0]);
	D3DXCreateTextureFromFile(DEVICE, "Snow2.jpg", &m_pSnowTexture[1]);
	D3DXCreateTextureFromFile(DEVICE, "Snow3.jpg", &m_pSnowTexture[2]);
	D3DXCreateTextureFromFile(DEVICE, "Snow4.jpg", &m_pSnowTexture[3]);
	D3DXCreateTextureFromFile(DEVICE, "Snow5.jpg", &m_pSnowTexture[4]);
	D3DXCreateTextureFromFile(DEVICE, "windmill.dds", &Windmill::m_pTexture);
	
	m_sky = D3DXCOLOR(0.6f, 0.6f, 0.6f, 0);
	m_FireOn = false;
	m_TimeState = 2;
	D3DLIGHT9 Light;
	ZeroMemory(&Light, sizeof(Light));
	Light.Type = D3DLIGHTTYPE::D3DLIGHT_DIRECTIONAL;//태양광

	Light.Diffuse = D3DXCOLOR(1, 1, 1, 1);
	Light.Direction = D3DXVECTOR3(1, -1, 1);



	DEVICE->SetLight(0, &Light);
	DEVICE->LightEnable(0, true);
	DEVICE->SetRenderState(D3DRS_AMBIENT, D3DXCOLOR(0.2f, 0.2f, 0.2f, 1));
	
	m_Axis.Setup();
	m_Grid.Setup();
	
	m_pTriPlayer = new TrianglePlayer;

	m_pTriPlayer->Init(D3DXVECTOR3(0, 1, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	m_FPSCamera.Init(m_pTriPlayer->GetTransform(), D3DXToRadian(45), (FLOAT)WINMGR->GetWidth() / WINMGR->GetHeight());
	
	OBJECTINFO info;
	ZeroInfo(&info);
	info.Pollygon = PG_FROMXFILE;
	info.vScale = VEC3ONE;
	info.FileName = "Resource/Airplane/airplane 2.x";
	info.vPos = D3DXVECTOR3(0, 10, 0);
	
	m_pAirPlane = new AirPlane;
	m_pAirPlane->Init(info);
	m_TargetCamera.Init(m_pAirPlane->GetTransform(), D3DXToRadian(45), (FLOAT)WINMGR->GetWidth() / WINMGR->GetHeight());

	m_Tank = new Tank;
	info.vPos = D3DXVECTOR3(5, 1, 0);
	m_Tank->Init();
	

	m_pCubeObject = new CubeObject;

	ZeroInfo(&info);
	info.vScale = VEC3ONE;
	info.Pollygon = PG_BOX;
	m_pCubeObject->Init(info);
	m_pTriPlayer->m_targetPos = m_pCubeObject->m_vPos;
	m_pTriPlayer->m_targetRadius = m_pCubeObject->m_Radius;

	m_Boss = new Boss;
	info.vPos = D3DXVECTOR3(10, 0.5, 10);
	m_Boss->Init(info);

	m_WindMill = new Windmill;
	info.vPos = D3DXVECTOR3(0, 0, 5);
	m_WindMill->Init(info);

	m_Terrain = new Terrain;
	m_Terrain->Init();



	ParticleInfo ptInfo;
	ParticleEffectInfo preInfo;

	info.vPos = D3DXVECTOR3(5, 0, 5);

	preInfo.lifeTime = 2.0f;
	preInfo.minLifeTime = 0.5f;
	preInfo.maxLifeTime = 2.5f;
	preInfo.vPos = D3DXVECTOR3(0, 0, 0);
	preInfo.vMinPos = D3DXVECTOR3(-1, -1, -1);
	preInfo.vMaxPos = D3DXVECTOR3(1, 1, 1);


	preInfo.vVelocity = D3DXVECTOR3(0, 20, 0);
	preInfo.vMinVelocity = D3DXVECTOR3(-5, 0, -5);
	preInfo.vMaxVelocity = D3DXVECTOR3(5, 0, 5);
	preInfo.sFileName = "DarknessFlash.png";
	ptInfo.EffectInfo = preInfo;
	ptInfo.MaxParticleCount = 50;
	ptInfo.ParticleMakeCycle = 0.1f;
	ptInfo.ObjInfo = info;
	ptInfo.EffectInfo.ObjInfo = info;
	ptInfo.EffectInfo.UseGravity = true;
	Particle* newPt = new Particle;
	info.vPos = D3DXVECTOR3(0, 1, 1);
	newPt->Init(ptInfo);

	for (int i = 0; i < 50; i++) {
		int x = rand() % 50;
		int y = rand() % 50;
		x -= 25;
		y -= 25;
		//x = 0;
		//y=10;
		Tree* newTree = new Tree;

		OBJECTINFO info;
		ZeroInfo(&info);
		info.vPos = D3DXVECTOR3((float)x, 0, (float)y);
		info.vScale = VEC3ONE;
		newTree->Init(info);
		m_Tree.push_back(newTree);
	}

	for (int i = 0; i < 50; i++) {
		int x = rand() % 50;
		int y = rand() % 50;
		int z = rand() % 50;
		x -= 25;
		z -= 25;
		m_Star[i].Init(D3DXVECTOR3((float)x, (float)y, (float)z), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0.3f, 0.3f, 0.3f));
	}
	m_WorldCamera.SetUp(D3DXVECTOR3(0, 10, -10));
	FONTMGR->Setup();

	UI* m_zoomUI = new UI;
	m_zoomUI->Init(0, 0, "UI/ss.dds", &m_bZoom);
	UI* m_SightUI = new UI;
	m_SightUI->Init(WINMGR->GetWidth()/2-50, WINMGR->GetHeight() / 2-50, "UI/redSight.png",&m_bZoom,D3DXCOLOR(1,1,1,1));

	UI* m_InfoUI = new UI;
	m_InfoUI->Init(0,0,"UI/panel-info.png.png", &m_bInfomation);
	m_PlayerUI = new UI;

	UI* m_MapUI = new UI;
	m_MapUI->Init(WINMGR->GetWidth() - 200, 0, "Field1.dds");
	m_MapUI->SetvScale(D3DXVECTOR3(200, 200, 1));
	m_PlayerUI->Init(0, 0, "UI/player.png", nullptr, D3DXCOLOR(1, 1, 1, 1),m_MapUI);

	UICheckBox* Check1 = new UICheckBox;
	Check1->Init(0, WINMGR->GetHeight() - 400, "UI/btn-check-false.png", "UI/btn-check-true.png", &m_bGrid);
	Check1->SetText("그리드");
	UICheckBox* Check2 = new UICheckBox;
	Check2->Init(0, WINMGR->GetHeight() - 200, "UI/btn-check-false.png", "UI/btn-check-true.png", &m_bAsix);
	Check2->SetText("축");

	River* _river = new River;
	_river->Init();
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
	if (INPUTMGR->GetKeyDown('7')) {
		m_pAirPlane->GetLBoom()->Fire();
		m_pAirPlane->GetRBoom()->Fire();
	}
	if (INPUTMGR->GetKeyDown('8')) {
		if(m_Winter>0)
			m_Winter--;
	}
	if (INPUTMGR->GetKeyDown('9')) {
		if (m_Winter<5)
			m_Winter++ ;
	}
	if (INPUTMGR->GetKeyDown('0')) {
		m_CameraType++;
		if (m_CameraType >= 3)
			m_CameraType = 0;
		if (m_CameraType==0) {
			m_WorldCamera.SetUp(D3DXVECTOR3(0, 10, -10));
		}
		
	}
	if (INPUTMGR->GetKeyDown('5')) {
		m_FireOn = !m_FireOn;
		D3DLIGHT9 Light;
		ZeroMemory(&Light, sizeof(Light));
		Light.Type = D3DLIGHTTYPE::D3DLIGHT_POINT;
		
		Light.Position = m_pTriPlayer->GetTransform()->GetvPos()+ m_pTriPlayer->m_Hand;
		Light.Range = 5.0f;
		Light.Diffuse = D3DXCOLOR(1, 1, 1, 1);
		//Light.Direction = D3DXVEC555TOR3(0, 0, 0);
		DEVICE->SetLight(1, &Light);
		DEVICE->LightEnable(1, true);
	}
	if (m_FireOn) {
		D3DLIGHT9 Light;
		D3DXVECTOR3 hand = D3DXVECTOR3(-1, 1, 0);
		ZeroMemory(&Light, sizeof(Light));
		Light.Type = D3DLIGHTTYPE::D3DLIGHT_POINT;
		Light.Attenuation0 = 0.2f;
		Light.Position = m_pTriPlayer->GetTransform()->GetvPos() + m_pTriPlayer->m_Hand;
		Light.Range = 10.0f;
		Light.Diffuse = D3DXCOLOR(1, 1, 1, 1);
		DEVICE->SetLight(1, &Light);

	}
	else {
		DEVICE->LightEnable(1, false);

	}
	m_Axis.Update(dTime);
	if (INPUTMGR->GetKeyDown('6')) {
		switch (m_FilterMode)
		{
		case FM_POINT:
			m_FilterMode = FM_LINEAR;
			break;
		case FM_LINEAR:
			m_FilterMode = FM_ANISOTROPIC;
			break;
		case FM_ANISOTROPIC:
			m_FilterMode = FM_POINT;
			break;
		default:
			break;
		}
	}
	if (INPUTMGR->GetKeyDown('M')) {
		m_bMipmapMode = !m_bMipmapMode;
	}
	for (auto& a : m_ListObj) {
		a->Update(dTime);
	}
	
	for (int i = 0; i < 50; i++) {
		
		m_Star[i].Update(dTime);
	}
	m_Collision = m_pTriPlayer->IsSphereCollision();
	if (m_pTriPlayer->IsSphereCollision(m_Tank->GetTransform()->GetvPos(), m_Tank->m_Radius)) {
		m_Tank->m_isBoarding = true;
		m_pTriPlayer->m_isBoarding = true;
		m_TargetCamera.SetpTarget(m_Tank->GetTransform());
		m_FPSCamera.SetpTarget(m_Tank->GetTransform());
	}

	if (INPUTMGR->GetKeyDown(VK_LBUTTON)) {
		if (m_CameraType == 1) {
			POINT pt;
			pt = GetClientPoint();
			MouseRay ray;
			ray.CreateViewSpaceRay((int)pt.x, (int)pt.y);
			D3DXMATRIX view;
			DEVICE->GetTransform(D3DTS_VIEW, &view);
			ray.RayTransform(view);

			for (auto& i : GAMEMGR->m_Tree) {
				MouseRay ray2 = ray;
				D3DXMATRIX m = i->GetTransform()->GetmTM();
				ray2.RayTransform(m);
				if (i->PickingCheck(i, &m_ClickedPos, ray2)) {
					m_SelectedObject = i;
					m_bClicked = true;
					D3DXVECTOR3 dir = i->GetTransform()->GetvPos()- m_pTriPlayer->GetTransform()->GetvPos();
					D3DXVec3Normalize(&dir, &dir);
					i->OnCollision(m_pTriPlayer->GetTransform()->GetvPos(), dir, "Bullet");
					break;
				}
			}
		}
	}
	if (INPUTMGR->GetKey(VK_LSHIFT)) {
		if (m_CameraType == 1) {
			m_bZoom = true;
		}
	}
	if (INPUTMGR->GetKeyUp(VK_LSHIFT)) {
		m_bZoom = false;
	}

	if (INPUTMGR->GetKey(VK_TAB)) {
		if (m_CameraType == 1) {
			m_bInfomation = true;
		}
	}
	if (INPUTMGR->GetKeyUp(VK_TAB)) {
		m_bInfomation = false;
	}
	
	for (auto a = m_ListObj.begin(); a != m_ListObj.end();) {
		auto b = a;
		a++;
		if ((*b)->GetbDead() == true) {
			auto tmp = *b;
			m_ListObj.erase(b);
			delete tmp;
			
		}
	}
	if (INPUTMGR->GetKeyDown('B')) {
		if (m_Tank->m_isBoarding == true) {
			m_Tank->m_isBoarding = false;
			m_pTriPlayer->m_isBoarding = false;
			m_pTriPlayer->GetTransform()->GetvPos() = m_Tank->GetTransform()->GetvPos() + m_Tank->GetTransform()->GetvDir() * 3;
			m_pTriPlayer->GetTransform()->GetvRot() = m_Tank->GetTransform()->GetvRot();
			m_TargetCamera.SetpTarget(m_pTriPlayer->GetTransform());
			m_FPSCamera.SetpTarget(m_pTriPlayer->GetTransform());

		}
	}
	m_vTexPos.x += dTime*0.01f;
	m_mTexTrans._31 = m_vTexPos.x;

	D3DXVECTOR3 pos = (m_pTriPlayer->GetTransform()->GetvPos());
	pos.y = pos.z;
	pos.z = 1;

	pos.x += (m_Terrain->GetfSize() / 2);
	pos.y += (m_Terrain->GetfSize() / 2);

	pos.x= pos.x/ m_Terrain->GetfSize();
	pos.y= 1 -pos.y/ m_Terrain->GetfSize();
	m_PlayerUI->SetvPos(pos);

	if (m_CameraType == 1) {
		m_FPSCamera.Update(dTime);
	}
		m_TargetCamera.Update(dTime);
		for (auto& i : m_ListUI) {
			i->Update(dTime);
		}

}

void GameManager::Render(void)
{
	
	DEVICE->Clear(0,	// RECT CNT
		NULL, // RECT
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER | D3DCLEAR_STENCIL, // 클리어 타입(화면버퍼|깊이버퍼)
		m_sky,	// 타겟버퍼 클리어 색상
		1.0f, // 깊이버퍼 클리어 값(깊이값)
		0);   // 스텐실버퍼(반사, 그림자) 초기값
	RenderMode();
	DEVICE->BeginScene(); // 디바이스 그리겟다고 알림


	RenderObject();
	if (m_CameraType == 0) {
		m_WorldCamera.UIModeOn();
		{
			for (auto& i : m_ListUI) {
				if (i->GetbVisible())
					i->Render();
			}
			m_PlayerUI->Render();

		}
		m_WorldCamera.UIModeOff();
	}else 	if (m_CameraType == 1) {
		m_FPSCamera.UIModeOn();
		{
			for (auto& i : m_ListUI) {
				if (i->GetbVisible())
					i->Render();
			}

		}
		m_FPSCamera.UIModeOff();
	}


	DebugView();
	
	DEVICE->SetTexture(0, NULL);
	DEVICE->SetRenderState(D3DRS_FOGENABLE, FALSE);

	DEVICE->EndScene(); // 디바이스 다그렸다고 알림

	DEVICE->Present(NULL, NULL, NULL, NULL);
	
}

void GameManager::RenderObject(void)
{
	
	if(m_bAsix)
		m_Axis.Render();
	if (m_bGrid)
		m_Grid.Render();
	///ground

	//{
	//	DEVICE->SetRenderState(D3DRS_FOGENABLE, TRUE);				  // 안개On
	//	DEVICE->SetRenderState(D3DRS_FOGCOLOR, D3DXCOLOR(1, 1, 1, 1)); // 안개색상

	//																   // 안개 옵션 : 버텍스 선형 안개
	//	float sp = 1.0f;
	//	float ep = 50.0f;
	//	DEVICE->SetRenderState(D3DRS_FOGVERTEXMODE, D3DFOG_LINEAR);	// 선형안개
	//	DEVICE->SetRenderState(D3DRS_FOGSTART, *(DWORD*)(&sp));		// 안개 시작점
	//	DEVICE->SetRenderState(D3DRS_FOGEND, *(DWORD*)(&ep));		// 안개 끝점
	//}

	RenderBottom();
	//RenderRiver();
	///
	// 오브젝트 렌더코드

	//float sp = 1.0f;
	//float ep = 50.0f;
	//DEVICE->SetRenderState(D3DRS_FOGTABLEMODE, D3DFOG_LINEAR);	// 선형안개
	//DEVICE->SetRenderState(D3DRS_FOGSTART, *(DWORD*)(&sp));		// 안개 시작점
	//DEVICE->SetRenderState(D3DRS_FOGEND, *(DWORD*)(&ep));		// 안개 끝점

	for (int i = 0; i < 50; i++) {
		m_Star[i].Render();
	}
	for (auto& a : m_ListObj) {
		if ((baseObject*)m_pTriPlayer == a)
			continue;
			a->Render();
	}
	//RenderRiver();
	m_pTriPlayer->Render();

	for(int i=0;i<8;++i)
		DEVICE->SetTexture(i, nullptr);
}


void GameManager::RenderBottom(void)
{

}

void GameManager::RenderMode(void)
{
	for (int i = 0; i < 8; ++i) {
		if (m_FilterMode == FM_POINT) {
			// 근접점 샘플링
			// - 디폴트 필터링 방식이며 가장 품질이 떨어지지만
			//   가장 빠른 속도를 가짐
			DEVICE->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_POINT);
			DEVICE->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_POINT);
		}
		if (m_FilterMode == FM_LINEAR) {

			// 선형 필터링(권장)
			// - 비교적 높은 품질의 결과를 만들어내면
			//   근접점 샘플링 보단 느리지만
			//   하드웨어 성능을 고려하면 속도는 빠른편
			DEVICE->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
			DEVICE->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
		}
		if (m_FilterMode == FM_ANISOTROPIC) {

			// 비등방성 필터링
			// - 가장 높은 품질의 결과를 만들어 내지만
			//   실행속도는 가장 느림.
			// - 실행속도와 결과물을 타협하여 옵션을 설정하면 되지만
			//   요새 하드웨어 성능이 좋아서 최상위 옵션을 걸고
			//   사용자가 선택할 수 있게 하는것1이 최선.
			DEVICE->SetSamplerState(i, D3DSAMP_MAGFILTER, D3DTEXF_ANISOTROPIC);
			DEVICE->SetSamplerState(i, D3DSAMP_MINFILTER, D3DTEXF_ANISOTROPIC);
			DEVICE->SetSamplerState(i, D3DSAMP_MAXANISOTROPY, 4);
		}
		// 밉 맵
		// - 원본 텍스쳐보다 작은 텍스쳐들을 메모리에 저장해 두었다가
		//   가장 알맞는 텍스쳐로 렌더링 하는 방식
		if (m_bMipmapMode)
			DEVICE->SetSamplerState(i, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
		else
			DEVICE->SetSamplerState(i, D3DSAMP_MIPFILTER, D3DTEXF_NONE);
	}

}
void GameManager::RenderRiver(void)
{
	D3DXMATRIX m;
	D3DXMatrixIdentity(&m);
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

	{
		DEVICE->SetRenderState(D3DRS_ZWRITEENABLE, false);
		DEVICE->SetRenderState(D3DRS_STENCILENABLE, true);
		DEVICE->SetRenderState(D3DRS_STENCILFUNC, D3DCMP_ALWAYS);
		DEVICE->SetRenderState(D3DRS_STENCILREF, 1);

		DEVICE->SetRenderState(D3DRS_STENCILPASS, D3DSTENCILOP_REPLACE);

	}
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE); // 컬링모드

	DEVICE->SetTexture(0, m_pWaterTexture);

	D3DMATERIAL9 material;
	ZeroMemory(&material, sizeof(material));
	material.Diffuse =material.Ambient = D3DXCOLOR(1, 1, 1, 1);
	DEVICE->SetMaterial(&material);
	D3DXMATRIX mTM;
	D3DXMatrixIdentity(&mTM);
	DEVICE->SetTransform(D3DTS_WORLD, &mTM);

	
	DEVICE->SetFVF(D3DFVF_XYZ_NORMAL_UV::FVF);

	DEVICE->SetRenderState(D3DRS_LIGHTING, true);
	//DEVICE->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	//DEVICE->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	//DEVICE->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	DEVICE->SetTextureStageState(0, D3DTSS_TEXTURETRANSFORMFLAGS, D3DTTFF_COUNT2);
	DEVICE->SetTransform(D3DTS_TEXTURE0, &m_mTexTrans);

	DEVICE->DrawPrimitiveUP(D3DPT_TRIANGLELIST, 2, m_River, sizeof(D3DFVF_XYZ_NORMAL_UV));

	//for (int i = 0; i<8; i++)
	//	DEVICE->SetTexture(i, nullptr);
	//DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드

	
	DEVICE->SetTexture(0, nullptr);
	DEVICE->SetTransform(D3DTS_TEXTURE0, &m);


	DEVICE->SetRenderState(D3DRS_STENCILENABLE, false);
	DEVICE->SetRenderState(D3DRS_ZWRITEENABLE, true);
	DEVICE->SetRenderState(D3DRS_CULLMODE, D3DCULL_CCW); // 컬링모드
}

void GameManager::Release(void)
{
	SAFE_DELETE(m_Tank);
	SAFE_DELETE(m_WindMill);
	int j = 0;
	//for (auto i = m_ListObj.begin(); i != m_ListObj.end();) {

	//	auto k = *i;
	//	i++;
	//	SAFE_DELETE(k);
	//}
	m_ListObj.clear();
	//for (auto& i : m_ListUI) {
	//	SAFE_DELETE(i);
	//}
	m_ListUI.clear();
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

void GameManager::OnGridButton(void * _vp)
{

}

void GameManager::OnAsixButton(void *_vp)
{
}

void GameManager::DebugView (void)
{
	int _x = 10;
	int _y = 10;
	char textBuffer[128] = { 0, };
	D3DXCOLOR _color = D3DXCOLOR(1, 1, 1, 1);
	DebugDis = D3DXVec3LengthSq(&(DebugVec1 - DebugVec2));
	FONTMGR->DrawTextA(_x, _y, _color, "<충돌 정보>");
	FONTMGR->DrawTextA(_x, _y+=15, _color, "(%.2f,%.2f,%.2f <=> %.2f,%.2f,%.2f dis :%.2f",
		DebugVec1.x, DebugVec1.y, DebugVec1.z, DebugVec2.x, DebugVec2.y, DebugVec2.z,DebugDis
		);
	sprintf(textBuffer, "(%.2f,%.2f,%.2f <=> %.2f,%.2f,%.2f dis :%.2f\n",
		DebugVec1.x, DebugVec1.y, DebugVec1.z, DebugVec2.x, DebugVec2.y, DebugVec2.z, DebugDis);
	switch (m_FilterMode) {
	case FM_POINT:
		FONTMGR->DrawTextA(_x, _y += 15, _color, "근접점");
		break;
	case FM_LINEAR:
		FONTMGR->DrawTextA(_x, _y += 15, _color, "리니어");
		break;
	case FM_ANISOTROPIC:
		FONTMGR->DrawTextA(_x, _y += 15, _color, "비등방성");
		break;
	}
	FONTMGR->DrawTextA(_x, _y += 15, _color, m_bMipmapMode?"밉맵ON":"밉맵OFF");
}

void GameManager::WndProc(HWND hWnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	if (m_CameraType==0) {
		m_WorldCamera.WndProc(hWnd, iMsg, wParam, lParam);
	}
	for (auto& i : m_ListUI) {
		i->WndProc(hWnd, iMsg, wParam, lParam);
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
	m_bMipmapMode = false;
	m_FilterMode = FM_POINT;
	m_bZoom = false;
	m_bInfomation = false;
	m_bAsix = true;
	m_bGrid = true;
}


GameManager::~GameManager()
{
	Release();
}



