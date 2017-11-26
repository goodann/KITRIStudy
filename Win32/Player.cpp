#include"IncludeAPI.h"



void Player::Update()
{
	//Character::Update();
	KeyInput();
}

void Player::KeyInput()
{
	if ((GETKEY(VK_LEFT)))
	{
		if (GETKEY(VK_UP) || GETKEY(VK_DOWN))
			m_Pos.x() -= m_Speed.x / ROOT2;
		else
			m_Pos.x() -= m_Speed.x;

		if (m_Pos.left() < 0)
			m_Pos.x() = 0+m_Pos.width()/2;
	}

	if ((GETKEY(VK_RIGHT)))
	{
		if (GETKEY(VK_UP) || GETKEY(VK_DOWN))
			m_Pos.x() += m_Speed.x / ROOT2;
		else
			m_Pos.x() += m_Speed.x;

		if (m_Pos.right() > 672)
			m_Pos.x() = 672 - m_Pos.width()/2;
	}

	if ((GETKEY(VK_UP)))
	{
		if (GETKEY(VK_LEFT) || GETKEY(VK_RIGHT))
			m_Pos.y() -= m_Speed.y / ROOT2;
		else
			m_Pos.y() -= m_Speed.y;

		if (m_Pos.top() < 0)
			m_Pos.y() = 0+m_Pos.height()/2;
	}

	if ((GETKEY(VK_DOWN)))
	{
		if (GETKEY(VK_LEFT) || GETKEY(VK_RIGHT))
			m_Pos.y() += m_Speed.y / ROOT2;
		else
			m_Pos.y() += m_Speed.y;

		if (m_Pos.bottom() > 800)
			m_Pos.y() = 800 - m_Pos.height()/2;
	}

	GETKEYDOWN(VK_SPACE, m_IsSpaceKey, Fire)
}

void Player::Shot()
{
	
}

void Player::Fire()
{
	if (m_ShotTimer.TimeCheck()) {
 		m_Weapon->Fire(this);
	}
}

Player::Player()
{
	m_Speed(3, 3);
	m_Weapon = new DefaultPlayersWeapon;
	m_ShotTimer.SetTimer(0.1f);
	const type_info &rtype_info = typeid((*this));
	m_HP = 100;
	m_ClassName = Multi2Wide(rtype_info.name());
	m_Tag = _T("Player");
}


Player::~Player()
{
}
