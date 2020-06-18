#include "card.h"

Card::Card()
{
	this->resultX1 = 5;
	this->resultX2 = 5;
	this->resultY1 = 6;
	this->resultY2 = 6;
	this->playCount = 0;
	this->openCount = 0;
	this->score = 20;
	this->hint = 2;
}
Card::~Card() {

}
/*
int Card::getScore() {
	return this->score;
}
*/
int Card::getOC() {
	return this->openCount;
}
int Card::getPC() {
	return this->playCount;
}
int Card::getHint() {
	return this->hint;
}

void Card::cardShuffle() {
	srand(time(NULL));

	int row1, row2, col1, col2;	// 카드 섞을 변수

	for (int i = 0; i < 1000; i++) {

		row1 = rand() % 4;

		row2 = rand() % 4;

		col1 = rand() % 4;

		col2 = rand() % 4;

		swap(back[row1][col1], back[row2][col2]);

		swap(result[row1][col1], result[row2][col2]);
	}
}

void Card::Display0() {
	system("cls");
	cout << endl;
	cout << "                카드 뒤집기 게임" << endl;
	cout << " 맞춘 카드 개수 : " << getOC()<<"                "<<"Hint 남은 횟수 : "<< getHint()<< endl;
	cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	for (int i = 0; i < 4; i++) {
		cout <<"              "<< "  ┌──────────┐ ┌──────────┐ ┌──────────┐ ┌──────────┐ " << endl;
		cout <<"              "<< "  │          │" << " │          │" << " │          │" << " │          │" << endl;
		cout <<"              "<< "  │ " << back[i][0] << " │" << " │ " << back[i][1] << " │" << " │ " << back[i][2] << " │ " << "│ " << back[i][3] << " │ " << endl;
		cout <<"              "<< "  │          │" << " │          │" << " │          │" << " │          │" << endl;
		cout <<"              "<< "  │          │" << " │          │" << " │          │" << " │          │" << endl;
		cout <<"              "<< "  └──────────┘ └──────────┘ └──────────┘ └──────────┘ " << endl;
	}
	cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
}

void Card::Display1() {
	system("cls");
	cout << endl;
	cout << "                카드 뒤집기 게임" << endl;
	cout << " 맞춘 카드 개수 : " << getOC() << "                " << "Hint 남은 횟수 : " << getHint() << endl;
	cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;

	for (int i = 0; i < 4; i++) {
		cout << "              "<< "  ┌──────────┐ ┌──────────┐ ┌──────────┐ ┌──────────┐ " << endl;

		if ((resultX1 == i && resultY1 == 0) || (resultX2 == i && resultY2 == 0) || openCard[i][0] == 1)
		{
			cout << "              " << "  │ " << back[i][0] << " │" << " │          │" << " │          │" << " │          │" << endl;
		}
		else { cout << "              " << "  │    " << front[i][0] << "    │" << " │          │" << " │          │" << " │          │" << endl; }

		if ((resultX1 == i && resultY1 == 1) || (resultX2 == i && resultY2 == 1) || openCard[i][1] == 1)
		{
			cout << "              " << "  │          │" << " │ " << back[i][1] << " │ " << "│          │" << " │          │" << endl;
		}
		else { cout << "              " << "  │          │" << " │    " << front[i][1] << "    │" << " │          │" << " │          │" << endl; }

		if ((resultX1 == i && resultY1 == 2) || (resultX2 == i && resultY2 == 2) || openCard[i][2] == 1)
		{
			cout << "              " << "  │          │" << " │          │" << " │ " << back[i][2] << " │ " << "│          │" << endl;
		}
		else { cout << "              " << "  │          │" << " │          │" << " │    " << front[i][2] << "    │" << " │          │" << endl; }

		if ((resultX1 == i && resultY1 == 3) || (resultX2 == i && resultY2 == 3) || openCard[i][3] == 1)
		{
			cout << "              " << "  │          │" << " │          │" << " │          │ " << "│ " << back[i][3] << " │ " << endl;
		}
		else { cout << "              " << "  │          │" << " │          │" << " │          │" << " │    " << front[i][3] << "    │ " << endl; }

		cout << "              " << "  └──────────┘ └──────────┘ └──────────┘ └──────────┘ " << endl;
	}
	cout << " ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
}

void Card::Hint() {
	if (hint <3 && hint >0) {
		system("cls");
		Display0();
		hint--;
		Sleep(500);
		Display1();
		selectPlay1();
	}
	else {
		system("cls");
		for (int i = 0; i < 5; i++) { cout << "                                                                 " << endl; }
		cout << " " << "###################################################################################" << endl;
		cout << " " << "#                                                                                 #" << endl;
		cout << " " << "#                                힌트를 다 썼습니다                               #" << endl;
		cout << " " << "#                                                                                 #" << endl;
		cout << " " << "###################################################################################" << endl;
		Sleep(500);
		Display1();
		selectPlay1();
	}
}
void Card::selectPlay1() {
	playCount++;

	int x, y;	// 0행 0열이 아닌 1행 1열로 시작하게 하기 위한 변수
	cout << "Hint!!를 보고싶으시다면 H를 눌러주세요! : " << endl;
	cout << " 첫번째 뒤집을 카드를 선택하세요 ( ex) 1 1 ~ 4 4 ) : ";

	char key = _getch();
	if (key == 'h') {
		Hint();
	}
	else {
		x = key - 48;
		cout << x;
		cin >> y;

		resultX1 = x - 1;

		resultY1 = y - 1;

		// 4행 4열 안에 값인지 확인해서 아니면 다시 입력

		while (resultX1 > 3 || resultX1 < 0 || resultY1 > 3 || resultY1 < 0 || openCard[resultX1][resultY1] == 1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
				break;

			cout << " 잘못입력하셨거나 이미 오픈된 카드입니다." << endl;

			cout << " 두번째 뒤집을 카드를 재선택하세요 ( ex) 1 1 ~ 4 4 ) : ";

			cin >> x >> y;

			resultX1 = x - 1;

			resultY1 = y - 1;
		}
	}
}

void Card::selectPlay2() {
		playCount++;	// 입력할때마다 증가

		int x, y;		// 0행 0열이 아닌 1행 1열로 시작하게 하기 위한 변수

		cout << " 2번째 뒤집을 카드를 선택하세요 ( ex) 1 1 ~ 4 4 ) : ";

		cin >> x >> y;
		
		resultX2 = x - 1;

		resultY2 = y - 1;
		// 4행 4열 안에 값인지 확인해서 아니면 다시 입력


		while (resultX2 > 3 || resultX2 < 0 || resultY2 > 3 || resultY2 < 0 || openCard[resultX2][resultY2] == 1 || (resultX1 == resultX2 && resultY1 == resultY2)
) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
				break;
			cout << " 잘못입력하셨거나 이미 오픈된 카드입니다." << endl;
			cout << " 2번째 뒤집을 카드를 재선택하세요 ( ex) 1 1 ~ 4 4 ) : ";
			cin >> x >> y;

			resultX2 = x - 1;

			resultY2 = y - 1;
		}
	}

void Card::Display2() {

	Display1();
    Sleep(500);

	// 초기화

	resultX1 = 5;
	resultY1 = 6;
	resultX2 = 5;
	resultY2 = 6;
}

void Card::SetConsoleSize(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}

void Card::grade(int score) {
	if (score >= 90) {	cout << " " << "#                                A 입니다.                                        #" << endl;}
	else if (score >= 70) { cout << " " << "#                                B 입니다.                                        #" << endl; }
	else if (score >= 50) { cout << " " << "#                                C 입니다.                                        #" << endl; }
	else if (score >= 30) { cout << " " << "#                                D 입니다.                                        #" << endl; }
	else { cout << " " << "#                                F 입니다.                                        #" << endl; }
}

void Card::GameOver(){
	system("cls");

	for (int i = 0; i < 5; i++) { cout << "                                                                 " << endl; }
	cout << " " << "###################################################################################" << endl;
	cout << " " << "#                                                                                 #" << endl;
	cout << " " << "#                                " << openCount << " 개 짝을 맞추셨습니다                           #" << endl;
	grade(score);
	cout << " " << "#                                                                                 #" << endl;
	cout << " " "###################################################################################" << endl;

	for (int i = 0; i < 3; i++) { cout << "                                                                 " << endl; }
	cout << " " << ".d8888b.                                        .d88888b." << endl;
	cout << " " << "d88P  Y88b                                     d88P' 'Y88b" << endl;
	cout << " " << "888    888                                     888     888" << endl;
	cout << " " << "888         8888b.  88888b.d88b.   .d88b.      888     888 888  888  .d88b.  888d888" << endl;
	cout << " " << "888  88888     '88b 888 '888 '88b d8P  Y8b     888     888 888  888 d8P  Y8b 888P'" << endl;
	cout << " " << "888    888 .d888888 888  888  888 88888888     888     888 Y88  88P 88888888 888" << endl;
	cout << " " << "Y88b  d88P 888  888 888  888  888 Y8b.         Y88b. .d88P  Y8bd8P  Y8b.     888" << endl;
	cout << " " << "'Y8888P88  'Y888888 888  888  888  'Y8888       'Y88888P'    Y88P    'Y8888  888" << endl;
}

void Card::play() {
	Card c;
	c.SetConsoleSize(720, 640);
	c.cardShuffle();
	c.Display0();
	Sleep(3000);

	while (1)

	{
		c.Display1();
		c.selectPlay1();
		c.Display1();
		c.selectPlay2();
		
		// 카드를 맞추었다면 
		// 카드를 맞추었는데 만약 학식이다. --> 바로 game out
		if (c.result[c.resultX1][c.resultY1] == 3 && c.result[c.resultX2][c.resultY2] == 3) {
			break;
		}
		else if (c.result[c.resultX1][c.resultY1] == c.result[c.resultX2][c.resultY2]) {

			c.openCard[c.resultX1][c.resultY1] = 1;

			c.openCard[c.resultX2][c.resultY2] = 1;

			c.openCount += 2;
			c.score += 10;
		}
		c.Display2();

		if (c.getPC() == 14) break;//?쇨낢吏???李얠쑝硫??덉텧 //OR ?숈떇??怨좊Ⅴ硫? game over.//playcount瑜??쒗븳???ъ꽌 game over?좉퉴 怨좊?以?

	}
	c.GameOver();
}


