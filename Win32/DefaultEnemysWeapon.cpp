#include"IncludeAPI.h"



void DefaultEnemysWeapon::Fire(Character * _Shooter)
{
	Bullet* newBullet = new Bullet;

	newBullet->Init(_T("bullet.bmp"), _Shooter->Position().m_pos.x,_Shooter->Position().bottom()+newBullet->Position().m_size.y/2);
	GAMEMGR->CreateObject(newBullet);
	newBullet->Speed()(0, 10);
	newBullet->TAG() = _T("EnemyBullet");
	//GAMEMGR->CreateObject(_T("Resource/Bullet.bmp"), _T("Bullet"), _Shooter->Position.Position(), RGB(0, 0, 25
}

DefaultEnemysWeapon::DefaultEnemysWeapon()
{

}


DefaultEnemysWeapon::~DefaultEnemysWeapon()
{
}
