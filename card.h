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
	int resultX1, resultY1, resultX2, resultY2;		// ù��° ī����ġ ���� resultX1, resultY1 / �ι�° ī����ġ ���� resultX2, resultY2
	int playCount;		// ī�带 ������ Ƚ��
	int openCount;		// ���� ī���
	//int score;
	int hint;

public:
	Card();
	~Card();
	string front[4][4] = { { "  ","  ","  ","  " },

	{ "  ","  ","  ","  " },

	{ "  ","  ","  ","  " },

	{ "  ","  ","  ","  " } };

	string back[4][4] = { { "�� �� ��","��    ��","�� �� ��","��    ��" },

	{ "�� �� ��","���ڵ���","���� 420","��    ��" },

	{ "�� �� ��","��    ��","�� �� ��","��    ��" },

	{ "�� �� ��","���ڵ���","���� 420","��    ��" } };

	int result[4][4] = { { 0, 1, 2, 3 },

	{ 4, 5, 6, 7 },

	{ 0, 1, 2, 3 },

	{ 4, 5, 6, 7 } };

	int openCard[4][4] = { { 0, }, };		// ���µ� ī�� 0 �̸� �޸�, 1 �̸� �ո��� �����Ե� �迭

	void cardShuffle();		// ī�� ����
	void Display0();        // �ϱ��϶�� �����ִ� ȭ��
	void Display1();		// �ո� Ȥ�� ���� ī�� Ȯ�� ȭ�� 
	void Display2();	    // ������ ȭ�� 
	void GameOver();
	void selectPlay1();		// ù��° ����ī�� �Է� ó�� �� ī�� �������� Ȯ��
	void selectPlay2();		// �ι�° ����ī�� �Է� ó�� �� ī�� �������� Ȯ��
	void grade(int score);
	void SetConsoleSize(int width, int heigh);
	//int getScore();
	int getOC();//opencount
	int getPC();//playcount
	int getHint();//hint count
	void play();
	void Hint();


};