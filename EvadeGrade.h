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

	int stage; // 스테이지 
	//int score; // 점수
	int life; // 생명
	int speed; // 학점 스피드 
	int PerPosition; // 유저 위치 변경 변수 

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
	int gradespeed(int speed, int score); // 학점 Speed 컨트롤 
	void Mapline(); // 맵 경계라인 표시 
	void InitMap(); // 맵 초기화 
	void PrintMap(int *P); // 학점 출력 
	void RowDownMap();
	void randline(); // line 당 학점 출력 개수 정하기 

					 // User Method
	int CollisionDetection(int score, int *P, int life); // 생명, 점수 계산 
	void keycontrol(); // user 키보드 컨트롤 

	void play(); // 게임 PLAY
	void showEvadeGradeView(int width, int height);
	//int getScore(); // 메인에 결과 점수 return 


};
