#include"GameCommon.h"



Boss::Boss()
{
	m_Speed = 3;
	m_TPos = D3DXVECTOR3(10, 0.5, 10);
	

}

void Boss::Update(float dTime)
{
	Enemy::Update(dTime);
	D3DXVECTOR3 plyPos = GAMEMGR->m_pTriPlayer->GetTransform()->GetvPos();
	D3DXVECTOR3 diffV = plyPos- m_Transform->GetvPos();
	
	float diff = D3DXVec3LengthSq(&(diffV));
	D3DXVec3Normalize(&diffV, &diffV);
	if (diff < 100) {
		m_pTarget = GAMEMGR->m_pTriPlayer;
	}
	else if(m_pTarget!=nullptr){
		m_pTarget = nullptr;
	}
	if (m_pTarget) {
		diffV = m_pTarget->GetTransform()->GetvPos() - m_Transform->GetvPos();
		diffV.y = 0;
		D3DXVec3Normalize(&diffV, &diffV);
		D3DXVECTOR3 dir = m_Transform->GetvDir();
		D3DXVec3Cross(&diffV, &dir, &diffV);
		if (D3DXVec3LengthSq(&diffV)>0.01)
			m_Transform->Rotate(diffV*dTime*m_Speed);


		m_Transform->MoveForward(m_Speed*dTime);
	}
	else {
		diffV = m_TPos - m_Transform->GetvPos();
		diff= D3DXVec3LengthSq(&(diffV));
		diffV.y = 0;
		D3DXVec3Normalize(&diffV, &diffV);
		D3DXVECTOR3 dir = m_Transform->GetvDir();
		D3DXVECTOR3 diffV2;
		D3DXVec3Cross(&diffV2, &dir, &diffV);

		if(D3DXVec3LengthSq(&diffV2)*1000>0.00001)
			m_Transform->Rotate(diffV2*dTime*m_Speed);
		else {
			if(diffV!=diffV2)
				m_Transform->Rotate(VEC3UP*dTime);
		}
		if (diff < 1) {
			float x=rand() % 50;
			float z= rand() % 50;
			x -= 25;
			z -= 25;
			m_TPos = D3DXVECTOR3(x, 0.5, z);
		}
		m_Transform->MoveForward(m_Speed*dTime);
	}
}


Boss::~Boss()
{
}
