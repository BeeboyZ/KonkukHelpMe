#include "EvadeGrade.h"
int map[MapY][MapX];
int Person[MapX] = { 0, };

void EvadeGrade::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//speed 컨트롤
int EvadeGrade::gradespeed(int speed, int score)
{
	if (this->score > 50) this->speed = 80;
	if (this->score > 100) this->speed = 50;
	if (this->score > 150) this->speed = 30;
	if (this->score > 200) this->speed = 10;
	if (this->score > 250) this->speed = 1;
	return this->speed;
}


//맵경계표시
void EvadeGrade::Mapline()
{
	for (int i = 0; i < MapY + 1; i++)
	{
		this->gotoxy(MapX, i); printf("■\n");
	}
	this->gotoxy(0, MapY);
	for (int i = 0; i < MapX / 2; i++) printf("■");
}

//맵 초기화
void EvadeGrade::InitMap()
{
	for (int i = 0; i < MapY; i++)
	{
		for (int j = 0; j < MapX; j++)
		{
			map[i][j] = 0;
		}
	}
}

//학점 찍기
void EvadeGrade::PrintMap(int *P)
{
	for (int i = 0; i < MapY - 1; i++)
	{
		for (int j = 0; j < MapX; j++)
		{
			switch (map[i][j])
			{
			case 0:  printf(" "); break;
			case 1:  printf("A"); break;
			case 2:  printf("B"); break;
			case 3:  printf("C"); break;
			case 4:  printf("D"); break;
			case 5:  printf("F"); break;
			}
		}
		printf("\n");
	}

	for (int j = 0; j < MapX; j++)
	{
		if (P[j] == 0) printf(" ");
		else if (P[j] == 1) printf("♀");
	}

}

void EvadeGrade::RowDownMap()
{
	for (int i = MapY - 1; i > 0; i--)
	{
		for (int j = 0; j < MapX; j++)
		{
			map[i][j] = map[i - 1][j];
		}
	}
	for (int j = 0; j < MapX; j++)
	{
		map[0][j] = 0;
	}
}

//목숨, 점수 계산 함수
int EvadeGrade::CollisionDetection(int score, int *P, int life)
{
	for (int i = 0; i < MapX; i++)
	{
		if (map[MapY - 1][i] && P[i]) {
			switch (map[MapY - 1][i])
			{
				this->gotoxy(MapX + 2, 3);
			case 1:
				printf(" A학점 취득!! 생명 회복(+2)! ");
				this->life += 2;
				break;
			case 2:
				printf(" B학점 취득!! 생명 감소(-1)! ");
				this->life -= 1;
				break;
			case 3:
				printf(" C학점 취득!! 생명 감소(-1)! ");
				this->life -= 2;
				break;
			case 4:
				printf(" D학점 취득!! 생명 감소(-1)! ");
				this->life -= 3;
				break;
			case 5:
				system("color f0");
				this->life -= 1000;
				break;
			}

			this->gotoxy(MapX + 2, 0);
			printf("LIFE:                                         ");
			this->gotoxy(MapX + 2, 0);
			printf("LIFE:");

			for (unsigned int i = 0; i < this->life; i++)
			{
				printf("♥");
				if (this->life < 0) {
					break;
				}
			}
		}

		else if (P[i] != 1) {
			switch (map[MapY - 1][i])
			{
			case 2:
				this->score += 1;
				break;//B가 닿을때
			case 3:
				this->score += 1;
				break;//C가 닿을때
			case 4:
				this->score += 2;
				break;//D가 닿을때
			case 5:
				this->score += 2;
				break;//F가 닿을때
			}
		}
	}
	if (this->life < 0) {
		return 1;
	}
	return 0;
}

void EvadeGrade::randline()
{
	int Position;
	for (int i = 0; i < rand() % 4; i++)// 라인당 학점 0~3개 나오도록
	{
		int num = rand() % 6;
		Position = rand() % MapX;
		map[0][Position] = num;
	}
}

void EvadeGrade::keycontrol() {
	int ch;
	if (_kbhit())
	{
		ch = _getch();
		ch = _getch();
		if (ch == 75 && PerPosition > 0)
		{
			Person[PerPosition] = 0;
			this->PerPosition--;
			Person[PerPosition] = 1;
		}
		else if (ch == 77 && PerPosition < MapX - 1)
		{
			Person[PerPosition] = 0;
			this->PerPosition++;
			Person[PerPosition] = 1;
		}
	}
}
void EvadeGrade::play()
{

	EvadeGrade ev;

	ev.InitMap();
	ev.Mapline();

	ev.gotoxy(MapX + 2, 0);
	printf("LIFE:♥♥♥♥♥");

	srand((unsigned)time(NULL));
	Person[PerPosition] = 1;

	for (;;)
	{
		ev.RowDownMap();
		ev.randline();
		ev.keycontrol();
		ev.gotoxy(0, 0);
		ev.PrintMap(Person);

		if (ev.life < 2)
			system("color f4");//빨강
		if (ev.life >= 2 && ev.life < 5)
			system("color f6");//노랑
		if (ev.life >= 5)
			system("color f1");//파랑

		if (ev.CollisionDetection(ev.score, Person, ev.life)) break;
		ev.gradespeed(ev.speed, ev.score);
		Sleep(ev.speed);
		//목숨,스테이지,점수 출력
		ev.gotoxy(MapX + 2, 1);
		printf("STAGE:%d", (ev.score / 50) + 1);
		ev.gotoxy(MapX + 2, 2);
		printf("score:%d", ev.score);
	}

	system("cls"); //최종 점수 출력
	//ev.gotoxy(MapX / 3, MapY / 4);
	system("color 07");//원래대로


	for (int i = 0; i < 5; i++) { cout << "                                                                 " << endl; }
	cout << " " << "###################################################################################" << endl;
	cout << " " << "                                    Game Over!!                                   " << endl;
	cout << " " << "                           邕 당신의 점수는 " << ev.score << " 점 입니다 邕                      " << endl;
	cout << " " << "                                                                                 " << endl;
	cout << " " << "###################################################################################" << endl;

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


void EvadeGrade::showEvadeGradeView(int width, int height)
{
	system("cls");
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
	play();
}



