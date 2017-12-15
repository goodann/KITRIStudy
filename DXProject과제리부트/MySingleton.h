#pragma once
#include <assert.h>

template <typename T>
class MySingleton
{
	static T*			m_pInstance;

public:
	static T* GetInstance(void);
	void Release(void);

	MySingleton(void) { assert(!m_pInstance); }
	virtual ~MySingleton(void) {};
};

template <typename T>
T* MySingleton<T>::m_pInstance = NULL;


template <typename T>
T* MySingleton<T>::GetInstance(void)
{
	if (m_pInstance == NULL)
		m_pInstance = new T;

	return m_pInstance;
}

template <typename T>
void MySingleton<T>::Release(void)
{
	SAFE_DELETE(m_pInstance);
}