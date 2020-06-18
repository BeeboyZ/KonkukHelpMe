#pragma once
#include <iostream>
#include "conio.h"
#include "windows.h"
#include "Game.h"
using namespace std;

const int screenWidth = 60, screenHeight = 35;
struct Position {
	int x;
	int y;
};

class Setting {
public:
	void SetConsoleSize(int width, int height);
	void gotoxy(int x, int y);
};
class Player {
private:
	Position originalPivotPos; 
	Position pivotPos;
	int direction;
public:
	Position bodyPos[3][3];
	inline void CalcBodyPos();
	Player(int posX, int posY);
	void Reset();
	void Move();
	inline int getPivotPosX();
	inline int getPivotPosY();
	inline int getDirection();
	inline void setDirection(int dir);
};
class Obstacle {
private:
	int score;
	int speed; 
	char bodyChar;
	Position originalPivotPos; 
	Position pivotPos;
	int direction;
public:
	Position bodyPos[3][3];
	inline void CalcBodyPos();
	Obstacle(int posX, int posY, int dir, int spd, char ch);
	void Move();
	inline int getPivotPosX();
	inline int getPivotPosY();
	inline char getBodyChar();
	inline int getDirection();
};
class GameManager {
private:
	int score;
	char grade;
	int width; 
	int height;
	bool quit; 
	bool restart;
	bool gameOver;
	Player *player;
	Obstacle *obs[10];
	Setting *set;
public:
	GameManager(int h, int w);
	~GameManager();
	void CheckInput();
	void scoreUp();
	void Logic();
	void Draw();
	void Run();
	void GameOver();
	int sendScore();
};

class Ilgamlake : public Game {
private:
	//int score;
public:	
	int playIlgam();
	//int getScore();
};