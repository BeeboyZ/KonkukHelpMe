#include "SystemEvent.h"

SystemEvent::SystemEvent()
{
}


SystemEvent::~SystemEvent()
{
}

//Ű���� �̺�Ʈ�� �޾ƿ�
int SystemEvent::keyboardEvent()
{
	char key = _getch();

	if (key == 'w' || key == 'W') {
		return UP;
	}
	else if (key == 'a' || key == 'A') {
		return LEFT;
	}
	else if (key == 's' || key == 'S') {
		return DOWN;
	}
	else if (key == 'd' || key == 'D') {
		return RIGHT;
	}
	
	else if (13 == (int)key) {
		return SUBMIT;
	}
}

void SystemEvent::cursorMoveXY(int x, int y)
{
	//�ܼ��� �ڵ� ��������
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandle, pos);
}
