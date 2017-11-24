#pragma once
class SingletonEnemyManager
{
	SINGLETON_FUNC(SingletonEnemyManager);
	std::list<GameObject*>		m_listEnemys;
	int			m_EnemyMax;

	int m_CurrEnemyCnt;

public:
	inline int getCurrEnemyCnt() { return m_CurrEnemyCnt; }
	void Init(void);
	void Update(void);
	void CreateEnemy(void);
	//void newCreateEnemy(EnemyInfo& _enemyInfo);
	int GetEnemyCount(void) { return (int)m_listEnemys.size(); }

	void CreateEnemy(GameObject* _enemy)
	{
		m_listEnemys.push_back(_enemy);
	}

	//void CreateEnemy2(baseImageObject* _enemy);
	//void CreateEnemy2(GameObject* _enemy, HUDBar* _hudBar = nullptr);


	void DeleteEnemy(GameObject* _enemy);
};

