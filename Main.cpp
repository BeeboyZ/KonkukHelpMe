#include <iostream>
#include "SystemUI.h"

using namespace std;

int main() {
	SystemUI sysui;

	//콘솔창크기조정
	sysui.initFrame(720,640);
	while (true) {
		//메인화면 제목출력
		sysui.mainTitle();
		//메인화면 메뉴출력 및 선택한것의 index를 menuInput에 저장 
		int menuIntput = sysui.mainTitleMenu();
		//선택한 index에 맞는 화면으로 전환
		sysui.mainMenuAction(menuIntput);
	}
	//system("pause");

	return 0;
}