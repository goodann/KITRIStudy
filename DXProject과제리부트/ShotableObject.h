#pragma once
class ShotableObject :
	public baseObject,public Shotable
{
public:
	//virtual void Init(OBJECTINFO _info)=0;
	//virtual void Update(float dTime)=0;
	//virtual void Render(void)=0;
	//virtual void Release(void)=0;
	//virtual void OnCollisionHit(baseObject* pCollObj, float dTime, bool isForward = true) = 0;
	virtual bool PickingCheck(ShotableObject* Target, D3DXVECTOR3* pickPos, MouseRay ray);
	virtual bool PickingMeshCheck(ShotableObject * Target, D3DXVECTOR3 * pickPos, MouseRay ray);
	ShotableObject();
	virtual ~ShotableObject();
};

