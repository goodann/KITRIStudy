#include "GameCommon.h"


void CollisionManager::CreateCollisionSphere(OBJECTINFO _info)
{
	CollisonSphere* pColl = new CollisonSphere;

	_info.m_collInfo.pTarget->SetpColl(pColl);

	pColl->Init(_info);

	m_listColls.push_back(pColl);
}

void CollisionManager::IsCollisionSphere(CollisonSphere * pColl, float dTime, bool isForward)
{
	for each(auto p in m_listColls)
	{
		if (p == pColl) continue; // 자신 컬리션 오브젝트는 하지 않음

		D3DXVECTOR3 vDis = p->GetTransform()->GetvPos()
			- pColl->GetTransform()->GetvPos();

		float len = D3DXVec3Length(&vDis);

		if (len < p->GetcollInfo().fRadius +
			pColl->GetcollInfo().fRadius)
		{
			baseObject* pSrc = pColl->GetcollInfo().pTarget;
			baseObject* pDest = p->GetcollInfo().pTarget;

			pSrc->OnCollisionHit(pDest, dTime, isForward);
			pDest->OnCollisionHit(pSrc, dTime, isForward);

			break;
		}
	}
}

baseObject* CollisionManager::IsCheckColl(CollisonSphere * pColl)
{
	for each(auto p in m_listColls)
	{
		if (p == pColl) continue; // 자신 컬리션 오브젝트는 하지 않음

		D3DXVECTOR3 vDis = p->GetTransform()->GetvPos()
			- pColl->GetTransform()->GetvPos();

		float len = D3DXVec3Length(&vDis);

		if (len < p->GetcollInfo().fRadius +
			pColl->GetcollInfo().fRadius)
		{
			return p->GetcollInfo().pTarget;
		}
	}

	return NULL;
}

void CollisionManager::Update(float dTime)
{
	if (INPUTMGR->GetKeyDown('P'))
		m_bDraw = !m_bDraw;

	for each(auto p in m_listColls)
		p->Update(dTime);
}

void CollisionManager::Render(void)
{
	if (m_bDraw == false) return;

	for each(auto p in m_listColls)
		p->Render();
}

void CollisionManager::DeleteCollison(CollisonSphere * pColl)
{
	for (list<CollisonSphere*>::iterator itor = m_listColls.begin();
		itor != m_listColls.end(); )
	{
		CollisonSphere* _pColl = (*itor);

		if (_pColl == pColl)
		{
			SAFE_DELETE(_pColl);
			itor = m_listColls.erase(itor);
		}
		else
			++itor;
	}
}

CollisionManager::CollisionManager()
{
	m_bDraw = false;
}


CollisionManager::~CollisionManager()
{
}
