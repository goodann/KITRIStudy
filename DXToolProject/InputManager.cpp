#include "GameCommon.h"

SINGLETON_INIT(InputManager)


void InputManager::SetUp(void)
{
	memset(m_KeyboardState, 0, KEYBOARDMAX);
}

void InputManager::Update(void)
{
	for (int i = 0; i < KEYBOARDMAX; ++i)
	{
		if ((GetKeyState(i) & 0x8000)) // 키가 눌러졌는지
		{
			if ((m_KeyboardState[i] & 0x80) == 0x00) // 처음 눌러졌다면
				m_KeyboardState[i] = 0x80;

			// 지속적으로 눌렸다면
			else
			{
				m_KeyboardState[i] = 0x81;
			}
		}

		// 키가 눌리지 않았다면
		else
		{
			// 이전에 눌러져 있었는지 체크
			if (m_KeyboardState[i] & 0x80)
				m_KeyboardState[i] = 0x01;

			// 키보드 상태가 0x01 or 0x00일때 
			else
			{
				m_KeyboardState[i] = 0x00;
			}
		}
	}
}

bool InputManager::GetKeyDown(BYTE key)
{
	if (m_KeyboardState[key] == 0x80)
		return true;

	return false;
}

bool InputManager::GetKeyUp(BYTE key)
{
	if (m_KeyboardState[key] == 0x01)
		return true;

	return false;
}

bool InputManager::GetKey(BYTE key)
{
	if (m_KeyboardState[key] & 0x80)
		return true;

	return false;
}

InputManager::InputManager()
{
	
}

InputManager::~InputManager()
{

}
