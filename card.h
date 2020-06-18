#pragma once
#include<iostream>
#include<time.h>
#include<conio.h>
#include<string>
#include<Windows.h>
#include<stdlib.h>
#include"Game.h"

using namespace std;

class Card : public Game{
private:
	int resultX1, resultY1, resultX2, resultY2;		// 첫번째 카드위치 변수 resultX1, resultY1 / 두번째 카드위치 변수 resultX2, resultY2
	int playCount;		// 카드를 뒤집은 횟수
	int openCount;		// 맞춘 카드수
	//int score;
	int hint;

public:
	Card();
	~Card();
	string front[4][4] = { { "  ","  ","  ","  " },

	{ "  ","  ","  ","  " },

	{ "  ","  ","  ","  " },

	{ "  ","  ","  ","  " } };

	string back[4][4] = { { "가 츠 시","알    촌","부 리 또","학    식" },

	{ "개 미 집","코코도리","도쿄 420","건    불" },

	{ "가 츠 시","알    촌","부 리 또","학    식" },

	{ "개 미 집","코코도리","도쿄 420","건    불" } };

	int result[4][4] = { { 0, 1, 2, 3 },

	{ 4, 5, 6, 7 },

	{ 0, 1, 2, 3 },

	{ 4, 5, 6, 7 } };

	int openCard[4][4] = { { 0, }, };		// 오픈될 카드 0 이면 뒷면, 1 이면 앞면이 나오게될 배열

	void cardShuffle();		// 카드 셔플
	void Display0();        // 암기하라고 보여주는 화면
	void Display1();		// 앞면 혹은 맞춘 카드 확인 화면 
	void Display2();	    // 뒤집은 화면 
	void GameOver();
	void selectPlay1();		// 첫번째 오픈카드 입력 처리 및 카드 진위여부 확인
	void selectPlay2();		// 두번째 오픈카드 입력 처리 및 카드 진위여부 확인
	void grade(int score);
	void SetConsoleSize(int width, int heigh);
	//int getScore();
	int getOC();//opencount
	int getPC();//playcount
	int getHint();//hint count
	void play();
	void Hint();


};