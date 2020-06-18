#include <stdio.h>
#include <windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <iostream>
#define MapX 20
#define MapY 20
using namespace std;
int map[MapY][MapX];
int Person[MapX] = { 0, };
int PerPosition = (int)(MapX / 2.0);

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int gradespeed(int *speed, int *score)
{//speed 컨트롤
	if (*score > 50) *speed = 200;
	if (*score > 150) *speed = 150;
	if (*score > 200) *speed = 100;
	if (*score > 250) *speed = 50;
	if (*score > 300) *speed = 25;
	return *speed;
}

void Mapline()
{//맵경계표시
	for (int i = 0; i < MapY + 1; i++)
	{
		gotoxy(MapX, i); printf("■\n");
	}
	gotoxy(0, MapY);
	for (int i = 0; i < MapX / 2; i++) printf("■");
}

void InitMap()
{
	for (int i = 0; i < MapY; i++)
	{
		for (int j = 0; j < MapX; j++)
		{
			map[i][j] = 0;
		}
	}
}

void PrintMap(int * P)
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

void RowDownMap()
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

int CollisionDetection(int *score, int * P, int *life)
{                                //목숨, 점수 계산 함수
	for (int i = 0; i < MapX; i++)
	{
		if (map[MapY - 1][i] && P[i]) {
			switch (map[MapY - 1][i])
			{
				gotoxy(MapX + 2, 3);
			case 1: 
				system("color f4");
				printf(" A학점 취득!! 생명 회복(+2)! ");
				*life += 2;
				break;
			case 2:
				system("color f1");
				printf(" B학점 취득!! 생명 감소(-1)! ");
				*life -= 1;
				break;
			case 3:
				system("color f6");
				printf(" C학점 취득!! 생명 감소(-1)! ");
				*life -= 2;
				break;
			case 4:
				system("color f2");
				printf(" D학점 취득!! 생명 감소(-1)! ");
				*life -= 3;
				break;
			case 5:
				system("color f0");
				*life -= 1000;
				break;
			}	

			gotoxy(MapX + 2, 0);
			printf("LIFE:                                         ");
			gotoxy(MapX + 2, 0);
			printf("LIFE:");

			for (unsigned int i = 0; i < *life; i++)
			{
				printf("♥");
				if (*life < 0) {
					break;
				}
			}
		}

		else if (P[i] != 1) {
			switch (map[MapY - 1][i])
			{
			case 2:
				*score += 1;
				break;//B가 닿을때
			case 3: 
				*score += 2;
				break;//C가 닿을때
			case 4: 
				*score += 3;
				break;//D가 닿을때
			case 5: 
				*score += 4; 
				break;//F가 닿을때
			}	
		}
	}
	if (*life < 0) {
		return 1;
	}
	return 0;
}

void randline() {
	int Position;
	for (int i = 0; i < rand() % 4; i++)// 라인당 학점 0~3개 나오도록
	{
		int num = rand() % 6;
		Position = rand() % MapX;
		map[0][Position] = num;
	}
}

void keycontrol() {
	int ch;
	if (_kbhit())
	{
		ch = _getch();
		ch = _getch();
		if (ch == 75 && PerPosition > 0)
		{
			Person[PerPosition] = 0;
			PerPosition--;
			Person[PerPosition] = 1;
		}
		else if (ch == 77 && PerPosition < MapX - 1)
		{
			Person[PerPosition] = 0;
			PerPosition++;
			Person[PerPosition] = 1;
		}
	}
}
/*
int main()
{
	int stage = 1;
	int score = 0;
	int life = 5;
	int speed = 300;

	InitMap();
	Mapline();
	
	system("color f4");
	gotoxy(MapX + 2, 0);
	printf("LIFE:♥♥♥♥♥");

	srand((unsigned)time(NULL));
	Person[PerPosition] = 1;

	for (;;)
	{
		RowDownMap();
		randline();
		keycontrol();
		gotoxy(0, 0);
		PrintMap(Person);

		if (CollisionDetection(&score, Person, &life)) break;
		gradespeed(&speed, &score);
		Sleep(speed);
		//목숨,스테이지,점수 출력
		gotoxy(MapX + 2, 1);
		printf("STAGE:%d", (score / 50) + 1);
		gotoxy(MapX + 2, 2);
		printf("score:%d", score);
	}

	system("cls");       //최종 점수 출력
	gotoxy(MapX / 3, MapY / 4);
	printf("Game Over!!\n");
	printf("\t邕당신의 점수는 %d점입니다邕\n\n", score);//\t tap
}*/