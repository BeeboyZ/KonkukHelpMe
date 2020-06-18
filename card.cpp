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

	int row1, row2, col1, col2;	// ī�� ���� ����

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
	cout << "                ī�� ������ ����" << endl;
	cout << " ���� ī�� ���� : " << getOC()<<"                "<<"Hint ���� Ƚ�� : "<< getHint()<< endl;
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	for (int i = 0; i < 4; i++) {
		cout <<"              "<< "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;
		cout <<"              "<< "  ��          ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		cout <<"              "<< "  �� " << back[i][0] << " ��" << " �� " << back[i][1] << " ��" << " �� " << back[i][2] << " �� " << "�� " << back[i][3] << " �� " << endl;
		cout <<"              "<< "  ��          ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		cout <<"              "<< "  ��          ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		cout <<"              "<< "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;
	}
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
}

void Card::Display1() {
	system("cls");
	cout << endl;
	cout << "                ī�� ������ ����" << endl;
	cout << " ���� ī�� ���� : " << getOC() << "                " << "Hint ���� Ƚ�� : " << getHint() << endl;
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;

	for (int i = 0; i < 4; i++) {
		cout << "              "<< "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;

		if ((resultX1 == i && resultY1 == 0) || (resultX2 == i && resultY2 == 0) || openCard[i][0] == 1)
		{
			cout << "              " << "  �� " << back[i][0] << " ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl;
		}
		else { cout << "              " << "  ��    " << front[i][0] << "    ��" << " ��          ��" << " ��          ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 1) || (resultX2 == i && resultY2 == 1) || openCard[i][1] == 1)
		{
			cout << "              " << "  ��          ��" << " �� " << back[i][1] << " �� " << "��          ��" << " ��          ��" << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��    " << front[i][1] << "    ��" << " ��          ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 2) || (resultX2 == i && resultY2 == 2) || openCard[i][2] == 1)
		{
			cout << "              " << "  ��          ��" << " ��          ��" << " �� " << back[i][2] << " �� " << "��          ��" << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��          ��" << " ��    " << front[i][2] << "    ��" << " ��          ��" << endl; }

		if ((resultX1 == i && resultY1 == 3) || (resultX2 == i && resultY2 == 3) || openCard[i][3] == 1)
		{
			cout << "              " << "  ��          ��" << " ��          ��" << " ��          �� " << "�� " << back[i][3] << " �� " << endl;
		}
		else { cout << "              " << "  ��          ��" << " ��          ��" << " ��          ��" << " ��    " << front[i][3] << "    �� " << endl; }

		cout << "              " << "  ������������������������ ������������������������ ������������������������ ������������������������ " << endl;
	}
	cout << " �ѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
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
		cout << " " << "#                                ��Ʈ�� �� ����ϴ�                               #" << endl;
		cout << " " << "#                                                                                 #" << endl;
		cout << " " << "###################################################################################" << endl;
		Sleep(500);
		Display1();
		selectPlay1();
	}
}
void Card::selectPlay1() {
	playCount++;

	int x, y;	// 0�� 0���� �ƴ� 1�� 1���� �����ϰ� �ϱ� ���� ����
	cout << "Hint!!�� ��������ôٸ� H�� �����ּ���! : " << endl;
	cout << " ù��° ������ ī�带 �����ϼ��� ( ex) 1 1 ~ 4 4 ) : ";

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

		// 4�� 4�� �ȿ� ������ Ȯ���ؼ� �ƴϸ� �ٽ� �Է�

		while (resultX1 > 3 || resultX1 < 0 || resultY1 > 3 || resultY1 < 0 || openCard[resultX1][resultY1] == 1) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
				break;

			cout << " �߸��Է��ϼ̰ų� �̹� ���µ� ī���Դϴ�." << endl;

			cout << " �ι�° ������ ī�带 �缱���ϼ��� ( ex) 1 1 ~ 4 4 ) : ";

			cin >> x >> y;

			resultX1 = x - 1;

			resultY1 = y - 1;
		}
	}
}

void Card::selectPlay2() {
		playCount++;	// �Է��Ҷ����� ����

		int x, y;		// 0�� 0���� �ƴ� 1�� 1���� �����ϰ� �ϱ� ���� ����

		cout << " 2��° ������ ī�带 �����ϼ��� ( ex) 1 1 ~ 4 4 ) : ";

		cin >> x >> y;
		
		resultX2 = x - 1;

		resultY2 = y - 1;
		// 4�� 4�� �ȿ� ������ Ȯ���ؼ� �ƴϸ� �ٽ� �Է�


		while (resultX2 > 3 || resultX2 < 0 || resultY2 > 3 || resultY2 < 0 || openCard[resultX2][resultY2] == 1 || (resultX1 == resultX2 && resultY1 == resultY2)
) {
			if (cin.fail()) {
				cin.clear();
				cin.ignore(100, '\n');
			}
			else
				break;
			cout << " �߸��Է��ϼ̰ų� �̹� ���µ� ī���Դϴ�." << endl;
			cout << " 2��° ������ ī�带 �缱���ϼ��� ( ex) 1 1 ~ 4 4 ) : ";
			cin >> x >> y;

			resultX2 = x - 1;

			resultY2 = y - 1;
		}
	}

void Card::Display2() {

	Display1();
    Sleep(500);

	// �ʱ�ȭ

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
	if (score >= 90) {	cout << " " << "#                                A �Դϴ�.                                        #" << endl;}
	else if (score >= 70) { cout << " " << "#                                B �Դϴ�.                                        #" << endl; }
	else if (score >= 50) { cout << " " << "#                                C �Դϴ�.                                        #" << endl; }
	else if (score >= 30) { cout << " " << "#                                D �Դϴ�.                                        #" << endl; }
	else { cout << " " << "#                                F �Դϴ�.                                        #" << endl; }
}

void Card::GameOver(){
	system("cls");

	for (int i = 0; i < 5; i++) { cout << "                                                                 " << endl; }
	cout << " " << "###################################################################################" << endl;
	cout << " " << "#                                                                                 #" << endl;
	cout << " " << "#                                " << openCount << " �� ¦�� ���߼̽��ϴ�                           #" << endl;
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
		
		// ī�带 ���߾��ٸ� 
		// ī�带 ���߾��µ� ���� �н��̴�. --> �ٷ� game out
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

		if (c.getPC() == 14) break;//?�곱�???찾으�??�출 //OR ?�식??고르�? game over.//playcount�??�한???�서 game over?�까 고�?�?

	}
	c.GameOver();
}


