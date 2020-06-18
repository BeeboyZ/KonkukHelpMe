#pragma once
#include<windows.h>
#include<iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include "Game.h"
#define MapX 30
#define MapY 30
using namespace std;

class EvadeGrade : public Game
{

public:

	int stage; // �������� 
	//int score; // ����
	int life; // ����
	int speed; // ���� ���ǵ� 
	int PerPosition; // ���� ��ġ ���� ���� 

					 // Constructor 
	EvadeGrade()
	{
		PerPosition = (int)(MapX / 2.0);
		stage = 1;
		score = 0;
		life = 5;
		speed = 100;
	};

	~EvadeGrade()
	{
	};

	// MAP Method
	void gotoxy(int x, int y);
	int gradespeed(int speed, int score); // ���� Speed ��Ʈ�� 
	void Mapline(); // �� ������ ǥ�� 
	void InitMap(); // �� �ʱ�ȭ 
	void PrintMap(int *P); // ���� ��� 
	void RowDownMap();
	void randline(); // line �� ���� ��� ���� ���ϱ� 

					 // User Method
	int CollisionDetection(int score, int *P, int life); // ����, ���� ��� 
	void keycontrol(); // user Ű���� ��Ʈ�� 

	void play(); // ���� PLAY
	void showEvadeGradeView(int width, int height);
	//int getScore(); // ���ο� ��� ���� return 


};
