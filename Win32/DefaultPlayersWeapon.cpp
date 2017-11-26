#include"IncludeAPI.h"



void DefaultPlayersWeapon::Fire(Character* _Shooter)
{
	Bullet* newBullet = new Bullet;

	newBullet->Init(_T("Resource/Bullet.bmp"), _Shooter->Position().m_pos, RGB(0, 0, 255));
	GAMEMGR->CreateObject(newBullet);
	newBullet->Speed()(0, -5);
	newBullet->TAG() = _T("PlayersBullet");
	//GAMEMGR->CreateObject(_T("Resource/Bullet.bmp"), _T("Bullet"), _Shooter->Position.Position(), RGB(0, 0, 255));
}

DefaultPlayersWeapon::DefaultPlayersWeapon()
{
}


DefaultPlayersWeapon::~DefaultPlayersWeapon()
{
}
