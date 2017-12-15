#pragma once
class GameManager
{
	SINGLETON_FUNC(GameManager);

public:
	enum FILTERMODE
	{
		FM_POINT,			// 근접점 샘필링
		FM_LINEAR,			// 선형 필터링
		FM_ANISOTROPIC		// 비등방성 필터링
	};
	FILTERMODE					m_FilterMode;
	bool						m_bMipmapMode;	// 밉맵사용 변수
	D3DXVECTOR3 m_ClickedPos;
	ShotableObject* m_SelectedObject;
	bool m_bClicked;
	int m_CameraType;
	D3DVIEWPORT9 m_OrgViewPort;
	WorldAxis			m_Axis;
	WorldGrid			m_Grid;
	WorldCamera			m_WorldCamera;
	FPSCamera m_FPSCamera;
	TargetCamera m_TargetCamera;
	Tank* m_Tank;
	TrianglePlayer*		m_pTriPlayer;
	CubeObject*			m_pCubeObject;
	Windmill* m_WindMill;
	Boss* m_Boss;
	AirPlane* m_pAirPlane;
	LPDIRECT3DTEXTURE9 m_pBottomTexture;
	LPDIRECT3DTEXTURE9 m_pGrassTexture;
	LPDIRECT3DTEXTURE9 m_pMaskTexture;
	LPDIRECT3DTEXTURE9 m_pWaterTexture;
	LPDIRECT3DTEXTURE9 m_pSnowTexture[5];
	LPDIRECT3DTEXTURE9 m_pRiverTexture;
	LPDIRECT3DTEXTURE9 m_pWhiteTexture;
	D3DXMATRIX m_OrgView;

	D3DXMATRIX m_mTexTrans;
	D3DXVECTOR3 m_vTexPos;
	Terrain* m_Terrain;
	int m_Winter;

	int m_TimeState;
	bool				m_bWire;
	bool		m_Collision;
	bool m_FireOn;
	D3DXCOLOR m_sky;
	D3DXVECTOR3 DebugVec1;
	D3DXVECTOR3 DebugVec2;
	float DebugDis;

public:
	list<baseObject*> m_ListObj;

	void CreateObejct(baseObject* _obj) { m_ListObj.push_back(_obj); }
	void DeleteObejct(baseObject* _obj) { m_ListObj.remove(_obj); }

	list<Tree*> m_Tree;
	Star m_Star[50];


	void DebugView(void);
	void WndProc(HWND hWnd,
			UINT iMsg, WPARAM wParam, LPARAM lParam);

public:
	//D3DXMATRIX GetCamBillboardTM(void) {		return m_WorldCamera.getBillBoard();}
	void Init(void);
	void Update(float dTime);
	void Render(void);
	void RenderObject(void);

	void RenderMode(void);
	void RenderBottom(void);
	void RenderRiver(void);
	void Release(void);
	void Loop(void);
	void ViewPortMinimap(void);
};


