#include <iostream>
#include "SystemUI.h"

using namespace std;

int main() {
	SystemUI sysui;

	//�ܼ�âũ������
	sysui.initFrame(720,640);
	while (true) {
		//����ȭ�� �������
		sysui.mainTitle();
		//����ȭ�� �޴���� �� �����Ѱ��� index�� menuInput�� ���� 
		int menuIntput = sysui.mainTitleMenu();
		//������ index�� �´� ȭ������ ��ȯ
		sysui.mainMenuAction(menuIntput);
	}
	//system("pause");

	return 0;
}