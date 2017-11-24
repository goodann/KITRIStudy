#pragma once
#ifndef __Managers
#define __Managers



#include"SingletonWindowManager.h"
#define WINMGR SingletonWindowManager::GetInstance()
#include "SingletonGameManager.h"
#define GAMEMGR SingletonGameManager::GetInstance()
#include "SingletonFrameManager.h"
#define FRAMEMGR SingletonFrameManager::GetInstance()
#include "SingletonSpriteManager.h"
#define SPRITEMGR SingletonSpriteManager::GetInstance()
#include "SingletonEnemyManager.h"
#define ENEMYMGR SingletonEnemyManager::GetInstance()


#endif // !__Managers
