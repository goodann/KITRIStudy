#pragma once
class GameManager
{
	SINGLETON_FUNC(GameManager);

public:
	int m_CameraType;
	D3DVIEWPORT9 m_OrgViewPort;
	WorldAxis			m_Axis;
	WorldGrid			m_Grid;
	WorldCamera			m_WorldCamera;
	CubeObject*			m_pCubeObject;
	AirPlane* m_pAirPlane;
	LPDIRECT3DTEXTURE9 m_pBottomTexture;
	LPDIRECT3DTEXTURE9 m_pGrassTexture;
	LPDIRECT3DTEXTURE9 m_pMaskTexture;
	LPDIRECT3DTEXTURE9 m_pWaterTexture;
	LPDIRECT3DTEXTURE9 m_pSnowTexture[5];
	LPDIRECT3DTEXTURE9 m_pRiverTexture;
	D3DXMATRIX m_OrgView;

	D3DXMATRIX m_mTexTrans;
	D3DXVECTOR3 m_vTexPos;

	FILE* m_File;

	int m_Winter;

	int m_TimeState;
	bool				m_bWire;
	bool		m_Collision;
	bool m_FireOn;
	bool m_bClicked;
	Terrain* m_Terrain;

	D3DXVECTOR3 m_ClickedPos;

	D3DXCOLOR m_sky;
	D3DXVECTOR3 DebugVec1;
	D3DXVECTOR3 DebugVec2;
	float DebugDis;

	int m_ToolMode;
	int m_ModelMode;
	baseObject* m_SelectedObject;



public:
	list<baseObject*> m_ListObj;

	void CreateObejct(baseObject* _obj) { m_ListObj.push_back(_obj); }



	void DebugView(void);
	void WndProc(HWND hWnd,
			UINT iMsg, WPARAM wParam, LPARAM lParam);

public:
	//D3DXMATRIX GetCamBillboardTM(void) {		return m_WorldCamera.getBillBoard();}
	void Init(void);
	void Update(float dTime);
	void Render(void);
	void RenderBottom(void);
	void RenderRiver(void);
	void Release(void);
	void Loop(void);
	void ViewPortMinimap(void);

	void Save(void);
	void Load(void);
};


