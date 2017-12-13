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
		if ((GetKeyState(i) & 0x8000)) // Ű�� ����������
		{
			if ((m_KeyboardState[i] & 0x80) == 0x00) // ó�� �������ٸ�
				m_KeyboardState[i] = 0x80;

			// ���������� ���ȴٸ�
			else
			{
				m_KeyboardState[i] = 0x81;
			}
		}

		// Ű�� ������ �ʾҴٸ�
		else
		{
			// ������ ������ �־����� üũ
			if (m_KeyboardState[i] & 0x80)
				m_KeyboardState[i] = 0x01;

			// Ű���� ���°� 0x01 or 0x00�϶� 
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
