#include"IncludeAPI.h"


SINGLETON_INIT(SingletonPyhisicsManager)
bool SingletonPyhisicsManager::isCollision(Position& a, Position& b)
{
	if (a.left() > b.right())
		return false;
	if (a.right() < b.left())
		return false;
	if (b.top() > a.bottom())
		return false;
	if (b.bottom() < a.top())
		return false;

	return true;
}

void SingletonPyhisicsManager::Update()
{
	for (auto& itor : m_ListColliders) {
		for (auto& itor2 : m_ListColliders) {
			if (itor == itor2)
				continue;
			if (isCollision(itor->Target()->Position(), itor2->Target()->Position())) {
				itor->Target()->OnCollisionHit(itor2->Target());
				itor2->Target()->OnCollisionHit(itor->Target());
			}
		}
	}
}

void SingletonPyhisicsManager::AddCollider(GameObject * _Obj)
{
	Collider* newCol = new Collider(_Obj);
	m_ListColliders.push_front(newCol);
	size++;
}

void SingletonPyhisicsManager::DeleteCollider(GameObject * _pObj)
{
	for (auto iter = m_ListColliders.before_begin(); iter != m_ListColliders.end(); ) {
		auto before = iter;
		iter++;
		if (iter == m_ListColliders.end())
			return;
		if ((*iter)->Target() == _pObj) {
			size--;
			delete *iter;
			iter = m_ListColliders.erase_after(before);
		}
	}
}

bool SingletonPyhisicsManager::RePosCheck(GameObject * _pObj)
{
	for (auto& itor : m_ListColliders) {
		if (itor->Target() == _pObj)continue;
		if (isCollision(itor->Target()->Position(), _pObj->Position()))
		{
			return true;
		}
	}
	return false;

}

SingletonPyhisicsManager::SingletonPyhisicsManager()
{
	size = 0;
}


SingletonPyhisicsManager::~SingletonPyhisicsManager()
{
}
