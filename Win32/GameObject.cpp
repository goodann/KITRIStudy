#include"IncludeAPI.h"



std::wstring GameObject::Multi2Wide(const char* pStr)
{
	int len = -1;

	std::wstring wstrOut;

	int nChars = MultiByteToWideChar(CP_ACP, 0, pStr, len, NULL, 0);

	wstrOut.resize(nChars);
	MultiByteToWideChar(CP_ACP, 0, pStr, len, const_cast<wchar_t*>(wstrOut.c_str()), nChars);

	return wstrOut;
}


std::wstring & GameObject::ClassName()
{
	return m_ClassName;
	// TODO: 여기에 반환 구문을 삽입합니다.
}

void GameObject::Init(std::wstring _name, int _x, int _y, DWORD color)
{
	m_Sprite= SPRITEMGR->GetSprite(_name, color);
	m_Pos.x() = (float)_x;
	m_Pos.y()= (float)_y;
	m_Pos.m_size = m_Sprite->Size();
	const type_info &rtype_info = typeid((*this));

	m_ClassName = Multi2Wide(rtype_info.name());
}

void GameObject::Init(std::wstring _name, Vector2 _pos, DWORD color)
{
	m_Sprite = SPRITEMGR->GetSprite(_name, color);
	m_Pos.m_pos = _pos;
	m_Pos.m_size = m_Sprite->Size();
}

void GameObject::Update(void)
{
	m_Pos.x()+=	m_Speed.x;
	m_Pos.y() += m_Speed.y;
	if (m_Pos.left() < 0 || m_Pos.right()>WINMGR->GetWidth() || m_Pos.bottom() > WINMGR->GetHeight() || m_Pos.top() < -800) {
		m_Life = false;
	}
}

void GameObject::Render(HDC _backDC)
{
	m_Sprite->RenderSprite(_backDC, m_Pos.start());
}

void GameObject::Release(void)
{
}

GameObject::GameObject()
{
	m_Sprite = NULL;
	m_Life = true;
	//m_ClassName = _T("GameObject");

}


GameObject::~GameObject()
{
	Release();
}
