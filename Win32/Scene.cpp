#include"IncludeAPI.h"



void Scene::CreateObject(GameObject * _Obj)
{
	m_listObjects.push_back(_Obj);
}

Scene::Scene()
{
}


Scene::~Scene()
{
}
